#include "comthread.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include <QElapsedTimer>

void QueueThread::ClerQueueTxFrame()
{
    mutex.lock();
    QueueTx.clear();
    mutex.unlock();
}

void QueueThread::ClerQueueRxFrame()
{
    mutex.lock();
    QueueRx.clear();
    mutex.unlock();
}

void QueueThread::ClerQueueCfgFrame()
{
    mutex.lock();
    QueueCfg.clear();
    mutex.unlock();
}

void QueueThread::EnqueueTxFrame(portFrame frame)
{
    mutex.lock();
    QueueTx.clear();
    QueueTx.enqueue(frame);
    mutex.unlock();

    semDataTx.release();
}

portFrame QueueThread::DequeueTxFrame()
{
    portFrame frame;
    frame.TransmitStatus = TrmtStatus_Unknown;
    mutex.lock();
    if(QueueTx.length()>0)
        frame = QueueTx.dequeue();
    mutex.unlock();

    return frame;
}

void QueueThread::EnqueueRxFrame(portFrame frame)
{
    mutex.lock();
    QueueRx.clear();
    QueueRx.enqueue(frame);
    mutex.unlock();
}

portFrame QueueThread::DequeueRxFrame()
{
    portFrame frame;
    frame.TransmitStatus = TrmtStatus_Unknown;
    mutex.lock();
    if(QueueRx.length()>0)
        frame = QueueRx.dequeue();
    mutex.unlock();

    return frame;
}

void QueueThread::EnqueueCfgFrame(portFrame frame)
{
    mutex.lock();
    QueueCfg.enqueue(frame);
    mutex.unlock();

    semDataTx.release();
}

portFrame QueueThread::DequeueCfgFrame()
{
    portFrame frame;
    frame.TransmitStatus = TrmtStatus_Unknown;
    mutex.lock();
    if(QueueCfg.length()>0)
        frame = QueueCfg.dequeue();
    mutex.unlock();

    return frame;
}

ComPortTransmit::ComPortTransmit()
{
    thread = NULL;
}

ComPortTransmit::~ComPortTransmit()
{

}

ComPortWorker::ComPortWorker(QString port,  QueueThread *pqueue)
{
    ComPortName = port;
    RxTimeoutValue = 300;
    queue = pqueue;
}

ComPortWorker::~ComPortWorker()
{
    if (sp!=NULL)
    {
        if(sp->isOpen()==true)
        {
            sp->close();
        }
        sp->deleteLater();
        sp=NULL;
    }
    queue->ClerQueueCfgFrame();
    queue->ClerQueueTxFrame();
    queue->ClerQueueRxFrame();
    emit threadDel();
}

void ComPortTransmit::PortChangeRxTimeoutRequest(int tm)
{
    portFrame frame;
    frame.TransmitStatus = TrmtStatus_SetRxTimeout;
    frame.rx_timeout = tm;
    queue.EnqueueCfgFrame(frame);
}

void ComPortTransmit::PortCloseRequest(bool no_silent)
{
    portFrame frame;
    frame.TransmitStatus = no_silent==true?TrmtStatus_Exit : TrmtStatus_ExitSilent;
    queue.EnqueueCfgFrame(frame);
}


void ComPortTransmit::PortOpen(QString port)
{
    this->queue.ClerQueueTxFrame();
    this->queue.ClerQueueRxFrame();
    this->queue.ClerQueueCfgFrame();
    //Берем настройки порта
    ComPortWorker* worker = new ComPortWorker(port, &this->queue);
    thread = new QThread;
    worker->moveToThread(thread);
    connect(thread, SIGNAL(started()), worker, SLOT(process()));
    connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
    connect(worker, SIGNAL(threadDel()), thread, SLOT(quit()));
    connect(worker, SIGNAL(threadDel()), this, SLOT(deleteThread()));


    connect(worker, SIGNAL(status(int)), this, SLOT(on_ComPortStatusChanged(int)));
    thread->start();
}

void ComPortTransmit::PortTransmitOpen(QString port)
{
     if(thread != NULL)
     {
         PortCloseRequest(false);
         int i=300;
         do
         {
             if(thread==NULL)
                 break;
             QThread::msleep(100);
             QApplication::processEvents();
         }while(i--);
         if(thread!=NULL)
             return;
     }
     PortOpen(port);
}

void ComPortTransmit::deleteThread()
{
    thread->deleteLater();
    thread = NULL;
    ComPortIsOpened = false;
}

void ComPortTransmit::on_ComPortStatusChanged(int status)
{
    if(status == ComStatus_Opened)
    {    QMessageBox::information(NULL, tr("Внимание"),
                               tr("Com-порт открыт"));
        ComPortIsOpened = true;
    }
    else if(status == ComStatus_Closed)
    {
        QMessageBox::information(NULL, tr("Внимание"),
                               tr("Com-порт закрыт"));
    }
    else
    {
        QMessageBox::critical(NULL, tr("Внимание"),
                               tr("Ошибка открытия Com-порта"));
    }
}

void ComPortWorker::process()
{
    sp = new QSerialPort(NULL);
    sp->setPortName(ComPortName);
    sp->open(QIODevice::ReadWrite);
    sp->setParity(QSerialPort::Parity::EvenParity);
    sp->setBaudRate(COMPORT_BAUDRATE);
    sp->setDataBits(QSerialPort::DataBits::Data8);
    sp->setStopBits(QSerialPort::StopBits::OneStop);
    sp->setFlowControl(QSerialPort::FlowControl::NoFlowControl);


    if(sp->isOpen() == false)
    {
        emit status(ComStatus_Error);
        emit finished();
        return;
    }

    emit status(ComStatus_Opened);
    while(1)
    {
        QApplication::processEvents();
        if(queue==NULL)
            break;
        queue->semDataTx.acquire();
        portFrame frame = queue->DequeueCfgFrame();
        switch(frame.TransmitStatus)
        {
            case  TrmtStatus_Exit:
            {
                emit status(ComStatus_Closed);
                emit finished();
                return;
            }
            case  TrmtStatus_ExitSilent:
            {
                emit finished();
                return;
            }
            case TrmtStatus_SetRxTimeout:
            {
                if(frame.rx_timeout>50 && frame.rx_timeout<10000)
                    RxTimeoutValue = frame.rx_timeout;
                continue;
            }
            default:
                break;
        }

        frame = queue->DequeueTxFrame();
        switch(frame.TransmitStatus)
        {
            case TrmtStatus_SendWithRxTimeout:
            {
                _preRxTimeoutValue = RxTimeoutValue;
                if(frame.rx_timeout>50 && frame.rx_timeout<10000)
                {
                    RxTimeoutValue = frame.rx_timeout;
                }
                //no break;
            }
            case TrmtStatus_Send:
            {
                int TrmtStatus = frame.TransmitStatus;
                QByteArray sdata;
                sdata.append(frame.ComAddress);
                sdata.append(frame.Function);
                sdata.append(frame.length);
                sdata.append(frame.data);
                sdata.append(CRC8Count(sdata, sdata.length()));
                //send data
                sp->readAll(); //read all remaining data from serial port
                sp->write(sdata);
                sp->waitForBytesWritten(2000);

                //wait for answer
                QByteArray answer;
                int _rcvd = -1;
                int _times=0;
                do{
                    sp->waitForReadyRead(RxTimeoutValue/10);
                    answer.append(sp->readAll());
                    if(answer.length()>=3)
                    {
                        if(answer.length()==((uint8_t)answer.at(2)+4))
                        {
                            _rcvd = 1;
                            break;
                        }
                        else if(answer.length()>((uint16_t)answer.at(2)+4))
                        {
                            break;
                        }
                    }
                }while(_times++ < 8);
                if(_rcvd == -1) //не приняли данные или приняли но не полностью
                {
                    frame.TransmitStatus = TrmtStatus_EventRxTimeout;
                }
                else if(_rcvd == 1) //получены данные
                {
                    if((uint8_t)answer.at(answer.length()-1) == CRC8Count(answer, answer.length()-1))
                    {
                        //
                        frame.TransmitStatus = TrmtStatus_EventSuccess;
                        frame.ComAddress = answer.at(0);
                        frame.Function = answer.at(1);
                        frame.length = answer.at(2);
                        answer = answer.remove(0,3); //remove first 3 bytes
                        answer = answer.remove(answer.length()-1,1); //remove crc
                        if(answer.length() != frame.length)
                        {
                            frame.TransmitStatus = TrmtStatus_EventAnswerError;
                        }
                        else
                        {
                            frame.data.clear();
                            frame.data.append(answer);
                            queue->EnqueueRxFrame(frame);
                        }
                    }
                    else
                    {
                        frame.TransmitStatus = TrmtStatus_EventAnswerError;
                    }
                }
                else
                {
                    frame.TransmitStatus = TrmtStatus_EventAnswerError;
                }

                if(TrmtStatus == TrmtStatus_SendWithRxTimeout)
                    RxTimeoutValue = _preRxTimeoutValue;
                break;
            }
            default:
                break;
        }

    }
    emit status(ComStatus_Closed);
    emit finished();

}

uint8_t CRC8TBL[]={0x00, 0x5E, 0xBC, 0xE2, 0x61, 0x3F, 0xDD, 0x83, 0xC2, 0x9C, 0x7E, 0x20, 0xA3, 0xFD, 0x1F, 0x41,
0x9D, 0xC3, 0x21, 0x7F, 0xFC, 0xA2, 0x40, 0x1E, 0x5F, 0x01, 0xE3, 0xBD, 0x3E, 0x60, 0x82, 0xDC,
0x23, 0x7D, 0x9F, 0xC1, 0x42, 0x1C, 0xFE, 0xA0, 0xE1, 0xBF, 0x5D, 0x03, 0x80, 0xDE, 0x3C, 0x62,
0xBE, 0xE0, 0x02, 0x5C, 0xDF, 0x81, 0x63, 0x3D, 0x7C, 0x22, 0xC0, 0x9E, 0x1D, 0x43, 0xA1, 0xFF,
0x46, 0x18, 0xFA, 0xA4, 0x27, 0x79, 0x9B, 0xC5, 0x84, 0xDA, 0x38, 0x66, 0xE5, 0xBB, 0x59, 0x07,
0xDB, 0x85, 0x67, 0x39, 0xBA, 0xE4, 0x06, 0x58, 0x19, 0x47, 0xA5, 0xFB, 0x78, 0x26, 0xC4, 0x9A,
0x65, 0x3B, 0xD9, 0x87, 0x04, 0x5A, 0xB8, 0xE6, 0xA7, 0xF9, 0x1B, 0x45, 0xC6, 0x98, 0x7A, 0x24,
0xF8, 0xA6, 0x44, 0x1A, 0x99, 0xC7, 0x25, 0x7B, 0x3A, 0x64, 0x86, 0xD8, 0x5B, 0x05, 0xE7, 0xB9,
0x8C, 0xD2, 0x30, 0x6E, 0xED, 0xB3, 0x51, 0x0F, 0x4E, 0x10, 0xF2, 0xAC, 0x2F, 0x71, 0x93, 0xCD,
0x11, 0x4F, 0xAD, 0xF3, 0x70, 0x2E, 0xCC, 0x92, 0xD3, 0x8D, 0x6F, 0x31, 0xB2, 0xEC, 0x0E, 0x50,
0xAF, 0xF1, 0x13, 0x4D, 0xCE, 0x90, 0x72, 0x2C, 0x6D, 0x33, 0xD1, 0x8F, 0x0C, 0x52, 0xB0, 0xEE,
0x32, 0x6C, 0x8E, 0xD0, 0x53, 0x0D, 0xEF, 0xB1, 0xF0, 0xAE, 0x4C, 0x12, 0x91, 0xCF, 0x2D, 0x73,
0xCA, 0x94, 0x76, 0x28, 0xAB, 0xF5, 0x17, 0x49, 0x08, 0x56, 0xB4, 0xEA, 0x69, 0x37, 0xD5, 0x8B,
0x57, 0x09, 0xEB, 0xB5, 0x36, 0x68, 0x8A, 0xD4, 0x95, 0xCB, 0x29, 0x77, 0xF4, 0xAA, 0x48, 0x16,
0xE9, 0xB7, 0x55, 0x0B, 0x88, 0xD6, 0x34, 0x6A, 0x2B, 0x75, 0x97, 0xC9, 0x4A, 0x14, 0xF6, 0xA8,
0x74, 0x2A, 0xC8, 0x96, 0x15, 0x4B, 0xA9, 0xF7, 0xB6, 0xE8, 0x0A, 0x54, 0xD7, 0x89, 0x6B, 0x35};

uint8_t ComPortWorker::CRC8Count(QByteArray sdata, int length)
{
    int cnt;
    uint8_t CRC=0;
    if(length>sdata.length())
        return CRC;
    for(cnt=0;cnt<length;cnt++)
    {
        CRC=CRC8TBL[CRC^((uint8_t)sdata.at(cnt))];
    }
    return CRC;
}
