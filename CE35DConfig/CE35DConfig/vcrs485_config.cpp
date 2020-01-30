#include "vcrs485_config.h"
#include "ui_vcrs485_config.h"
#include <QTextCodec>

VCRS485_Config::VCRS485_Config(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VCRS485_Config)
{
    ui->setupUi(this);

    comP = NULL;
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

    isOpened = false;

    ui->dec->setValue(2);
    ui->koeff_K->setValue(100);
    ui->koeff_Z->setValue(0);
    ui->dec_2->setValue(2);
    ui->koeff_K_2->setValue(100);
    ui->koeff_Z_2->setValue(0);

    //Set poll timer
    {
        wrframe.data.clear();
        pollTimer = new QTimer(this);
        connect(pollTimer, SIGNAL(timeout()), this, SLOT(pollTimerTimeout()));
    }
}

VCRS485_Config::~VCRS485_Config()
{
    delete ui;
}

bool VCRS485_Config::busyWaitMessage()
{
    if (pollTimer->isActive() == true)
    {
       QMessageBox::warning(NULL, tr("Внимание"),
                              tr("Дождитесь завершения операции"));
       return true;
    }
    return false;
}

void VCRS485_Config::DataLoad(ComPortTransmit *comPort, bool *RequestFlag, uint8_t maddress)
{
    comP = comPort;
    pollRequestFlag = RequestFlag;
    ModuleAddress = maddress;
    DataRequest();
}


void VCRS485_Config::DataRequest()
{
    *pollRequestFlag = true;
    comP->queue.ClerQueueTxFrame();

    portFrame frame;

    frame.data.clear();
    frame.Function = Function_Read;
    const uint8_t req[]={ 0x10, 0x11, 0x20, 0x21, 0x22, 0x23, 0x30, 0x31 };
    frame.data.append((char*)req, sizeof(req));
    frame.length = frame.data.length();
    frame.ComAddress = ModuleAddress;
    frame.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frame);
    pollTimerQuant = 0;
    pollTimer->start(300);
}

void VCRS485_Config::pollTimerTimeout()
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
                        case 0x10:
                        case 0x11:
                        {
                            uint8_t cn = (uint8_t)answer.data.at(i);
                            i++;
                            if ((i + 1) < answer.length)
                            {
                                uint8_t val=(uint16_t)(uint8_t)answer.data.at(i)*256+(uint16_t)(uint8_t)answer.data.at(i+1);
                                switch (cn)
                                {
                                    case 0x10: ui->dec->setValue(val); break;
                                    case 0x11: ui->dec_2->setValue(val); break;
                                }
                                connect = true;
                                i+=2;
                            }
                            else connect = false;
                            break;
                        }
                        case 0x20:
                        case 0x21:
                        case 0x22:
                        case 0x23:
                        {
                            uint8_t cn = (uint8_t)answer.data.at(i);
                            i++;
                            if ((i + 3) < answer.length)
                            {
                                int32_t val = ((int32_t)((uint32_t)(uint8_t)answer.data.at(i)*256*256*256+(uint32_t)(uint8_t)answer.data.at(i+1)*256*256+(uint32_t)(uint8_t)answer.data.at(i+2)*256+(uint8_t)answer.data.at(i+3)));
                                switch (cn)
                                {
                                    case 0x20: ui->koeff_K->setValue(val); break;
                                    case 0x21: ui->koeff_Z->setValue(val); break;
                                    case 0x22: ui->koeff_K_2->setValue(val); break;
                                    case 0x23: ui->koeff_Z_2->setValue(val); break;
                                }
                                connect = true;
                                i += 4;
                            }
                            else connect = false;
                            break;
                        }
                        case 0x30:
                        {
                            i++;
                            int j = 0;
                            while ((uint8_t)answer.data.at(i + j) != 0x0) j++;
                            if (j > 10)
                            {
                                connect = false;
                                break;
                            }
                            QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
                            ui->dim->setText(codec->toUnicode(answer.data.mid(i,j)));
                            i = i + j + 1;
                            connect = true;
                            break;
                        }
                        case 0x31:
                        {
                            i++;
                            int j = 0;
                            while ((uint8_t)answer.data.at(i + j) != 0x0) j++;
                            if (j > 10)
                            {
                                connect = false;
                                break;
                            }
                            QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
                            ui->dim_2->setText(codec->toUnicode(answer.data.mid(i,j)));
                            i = i + j + 1;
                            connect = true;
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



void VCRS485_Config::on_dWrite_clicked()
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
    frwr.data.append((char)0x20);
    uint32_t val=(uint32_t)ui->koeff_K->value();
    frwr.data.append((char)(uint8_t)(val/(256*256*256)));
    frwr.data.append((char)(uint8_t)(val/(256*256)));
    frwr.data.append((char)(uint8_t)(val/(256)));
    frwr.data.append((char)(uint8_t)(val/(1)));

    frwr.data.append((char)0x21);
    val=(uint32_t)ui->koeff_Z->value();
    frwr.data.append((char)(uint8_t)(val/(256*256*256)));
    frwr.data.append((char)(uint8_t)(val/(256*256)));
    frwr.data.append((char)(uint8_t)(val/(256)));
    frwr.data.append((char)(uint8_t)(val/(1)));

    frwr.data.append((char)0x10);
    frwr.data.append((char)0x0);
    frwr.data.append((char)ui->dec->value());

    frwr.data.append((char)0x30);
    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
    frwr.data.append(codec->fromUnicode(ui->dim->text()));
    frwr.data.append((char)0x0);

    frwr.length = frwr.data.length();
    frwr.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(300);
}

void VCRS485_Config::on_dWrite_2_clicked()
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
    frwr.data.append((char)0x22);
    uint32_t val=(uint32_t)ui->koeff_K_2->value();
    frwr.data.append((char)(uint8_t)(val/(256*256*256)));
    frwr.data.append((char)(uint8_t)(val/(256*256)));
    frwr.data.append((char)(uint8_t)(val/(256)));
    frwr.data.append((char)(uint8_t)(val/(1)));

    frwr.data.append((char)0x23);
    val=(uint32_t)ui->koeff_Z_2->value();
    frwr.data.append((char)(uint8_t)(val/(256*256*256)));
    frwr.data.append((char)(uint8_t)(val/(256*256)));
    frwr.data.append((char)(uint8_t)(val/(256)));
    frwr.data.append((char)(uint8_t)(val/(1)));

    frwr.data.append((char)0x11);
    frwr.data.append((char)0x0);
    frwr.data.append((char)ui->dec_2->value());

    frwr.data.append((char)0x31);
    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
    frwr.data.append(codec->fromUnicode(ui->dim_2->text()));
    frwr.data.append((char)0x0);

    frwr.length = frwr.data.length();
    frwr.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(300);
}

void VCRS485_Config::on_Cancel_clicked()
{
    if (busyWaitMessage() == true)
    {
       return;
    }
    *pollRequestFlag = false;
    isOpened = false;
    this->close();
}

void VCRS485_Config::on_VCRS485_Config_finished(int result)
{
    pollTimer->deleteLater();
    this->deleteLater();
}

