#include "csrs485_config.h"
#include "ui_csrs485_config.h"

CSRS485_Config::CSRS485_Config(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CSRS485_Config)
{
    ui->setupUi(this);
    comP = NULL;
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

    isOpened = false;

    //Set poll timer
    {
        wrframe.data.clear();
        pollTimer = new QTimer(this);
        connect(pollTimer, SIGNAL(timeout()), this, SLOT(pollTimerTimeout()));
    }
}

CSRS485_Config::~CSRS485_Config()
{
    delete ui;
}


bool CSRS485_Config::busyWaitMessage()
{
    if (pollTimer->isActive() == true)
    {
       QMessageBox::warning(NULL, tr("Внимание"),
                              tr("Дождитесь завершения операции"));
       return true;
    }
    return false;
}

void CSRS485_Config::DataLoad(ComPortTransmit *comPort, bool *RequestFlag, uint8_t maddress)
{
    comP = comPort;
    pollRequestFlag = RequestFlag;
    ModuleAddress = maddress;
    DataRequest();
}


void CSRS485_Config::DataRequest()
{
    *pollRequestFlag = true;
    comP->queue.ClerQueueTxFrame();

    portFrame frame;

    frame.data.clear();
    frame.Function = Function_Read;
    const uint8_t req[]={ 0xA4, 0xA5 };
    frame.data.append((char*)req, sizeof(req));
    frame.length = frame.data.length();
    frame.ComAddress = ModuleAddress;
    frame.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frame);
    pollTimerQuant = 0;
    pollTimer->start(300);
}


void CSRS485_Config::pollTimerTimeout()
{
    bool connect = false;
    portFrame answer = comP->queue.DequeueRxFrame();
    if(answer.TransmitStatus == TrmtStatus_EventSuccess)
    {
        if(answer.Function == Function_Read)
        {
            if(ModuleAddress == answer.ComAddress)
            {
                int i = 0;
                while (i < answer.length)
                {
                    switch ((uint8_t)answer.data.at(i))
                    {
                        case 0xA4:
                        {
                            i++;
                            if ((i+1) < answer.length)
                            {
                                if((uint8_t)answer.data.at(i) == 0x0 && (uint8_t)answer.data.at(i+1)==0xf0)
                                {
                                    ui->diap->setCurrentIndex(1);
                                }
                                else
                                {
                                    ui->diap->setCurrentIndex(0);
                                }
                                connect = true;
                            }
                            else
                                connect = false;
                            i+=2;
                            break;
                        }
                        case 0xA5:
                        {
                            i++;
                            if ((i+1) < answer.length)
                            {
                                if((uint8_t)answer.data.at(i) == 0x0 && (uint8_t)answer.data.at(i+1)==0xf0)
                                {
                                    ui->correct->setCheckState(Qt::CheckState::Checked);
                                }
                                else
                                {
                                    ui->correct->setCheckState(Qt::CheckState::Unchecked);
                                }
                                connect = true;
                            }
                            else
                                connect = false;
                            i+=2;
                            break;
                        }
                        default:
                            connect = false;
                            break;
                    }
                    if(connect==false)
                        break;
                }
                if(connect==true) //считаны правильные данные, отображаем окно
                {
                    if(isOpened == false)
                    {
                        isOpened = true;
                        this->open();
                    }
                }
            }
        }
        else if(answer.Function == Function_Write)
        {
            if(ModuleAddress == answer.ComAddress)
            {
                connect = true;
                if(answer.data == wrframe.data)
                {
                    QMessageBox::information(NULL, tr("Внимание"),
                                               tr("Данные успешно записаны"));
                }
                else
                {
                    QMessageBox::critical(NULL, tr("Внимание"),
                                               tr("Ошибка записи данных"));
                }
            }
        }
    }
    if(connect == true)
    {
        pollTimer->stop();
        if(answer.Function == Function_Write)
            DataRequest();
        else
            *pollRequestFlag = false;
    }
    else if(pollTimerQuant++ >= 5)
    {
        *pollRequestFlag = false;
        pollTimer->stop();
        QMessageBox::critical(NULL, tr("Внимание"),
                               tr("Датчик не отвечает на запрос"));
        if(isOpened == false)
            this->deleteLater();
    }
}



void CSRS485_Config::on_dWrite_clicked()
{
    if (busyWaitMessage() == true)
    {
       return;
    }
    *pollRequestFlag = true;
    comP->queue.ClerQueueTxFrame();

    portFrame frwr;
    frwr.Function = Function_Write;
    frwr.ComAddress = ModuleAddress;
    frwr.data.clear();
    frwr.data.append((char)0xA4);
    frwr.data.append((char)0x0);
    switch(ui->diap->currentIndex())
    {
        default:
        case 0:
            frwr.data.append((char)0x0f);
            break;
        case 1:
            frwr.data.append((char)0xf0);
            break;
    }
    frwr.length = frwr.data.length();
    frwr.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(300);
}

void CSRS485_Config::on_dWrite_2_clicked()
{
    if (busyWaitMessage() == true)
    {
       return;
    }
    *pollRequestFlag = true;
    comP->queue.ClerQueueTxFrame();

    portFrame frwr;
    frwr.Function = Function_Write;
    frwr.ComAddress = ModuleAddress;
    frwr.data.clear();
    frwr.data.append((char)0xA5);
    frwr.data.append((char)0x0);
    if(ui->correct->checkState()==Qt::CheckState::Checked)
        frwr.data.append((char)0xf0);
    else
        frwr.data.append((char)0x0f);
    frwr.length = frwr.data.length();
    frwr.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(300);
}

void CSRS485_Config::on_Cancel_clicked()
{
    if (busyWaitMessage() == true)
    {
       return;
    }
    *pollRequestFlag = false;
    isOpened = false;
    this->close();
}

void CSRS485_Config::on_CSRS485_Config_finished(int result)
{
    pollTimer->deleteLater();
    this->deleteLater();
}
