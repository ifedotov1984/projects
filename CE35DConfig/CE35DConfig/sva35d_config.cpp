#include "sva35d_config.h"
#include "ui_sva35d_config.h"

SVA35D_Config::SVA35D_Config(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SVA35D_Config)
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

SVA35D_Config::~SVA35D_Config()
{
    delete ui;
}


bool SVA35D_Config::busyWaitMessage()
{
    if (pollTimer->isActive() == true)
    {
       QMessageBox::warning(NULL, tr("Внимание"),
                              tr("Дождитесь завершения операции"));
       return true;
    }
    return false;
}

void SVA35D_Config::DataLoad(ComPortTransmit *comPort, bool *RequestFlag, uint8_t maddress)
{
    comP = comPort;
    pollRequestFlag = RequestFlag;
    ModuleAddress = maddress;
    DataRequest();
}


void SVA35D_Config::DataRequest()
{
    *pollRequestFlag = true;
    comP->queue.ClerQueueTxFrame();

    portFrame frame;

    frame.data.clear();
    frame.Function = Function_Read;
    const uint8_t req[]={ 0xB0, 0xB1 };
    frame.data.append((char*)req, sizeof(req));
    frame.length = frame.data.length();
    frame.ComAddress = ModuleAddress;
    frame.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frame);
    pollTimerQuant = 0;
    pollTimer->start(300);
}


void SVA35D_Config::pollTimerTimeout()
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
                        case 0xB0:
                        {
                            i++;
                            if ((i + 3) <= answer.length)
                            {
                                int32_t val = ((int32_t)((uint32_t)(uint8_t)answer.data.at(i)*256*256*256+(uint32_t)(uint8_t)answer.data.at(i+1)*256*256+(uint32_t)(uint8_t)answer.data.at(i+2)*256+(uint8_t)answer.data.at(i+3)));
                                ui->v_coeff->setValue(val);
                                connect = true;
                                i += 4;
                            }
                            else connect = false;
                            break;
                        }
                        case 0xB1:
                        {
                            i++;
                            if ((i + 3) <= answer.length)
                            {
                                int32_t val = ((int32_t)((uint32_t)(uint8_t)answer.data.at(i)*256*256*256+(uint32_t)(uint8_t)answer.data.at(i+1)*256*256+(uint32_t)(uint8_t)answer.data.at(i+2)*256+(uint8_t)answer.data.at(i+3)));
                                ui->i_coeff->setValue(val);
                                connect = true;
                                i += 4;
                            }
                            else connect = false;
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


void SVA35D_Config::on_vWrite_clicked()
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
    frwr.data.append((char)0xB0);
    uint32_t val=(uint32_t)ui->v_coeff->value();
    frwr.data.append((char)(uint8_t)(val/(256*256*256)));
    frwr.data.append((char)(uint8_t)(val/(256*256)));
    frwr.data.append((char)(uint8_t)(val/(256)));
    frwr.data.append((char)(uint8_t)(val/(1)));
    frwr.length = frwr.data.length();
    frwr.TransmitStatus = TrmtStatus_SendWithRxTimeout;
    frwr.rx_timeout = 1500;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(500);
}

void SVA35D_Config::on_iWrite_clicked()
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
    frwr.data.append((char)0xB1);
    uint32_t val=(uint32_t)ui->i_coeff->value();
    frwr.data.append((char)(uint8_t)(val/(256*256*256)));
    frwr.data.append((char)(uint8_t)(val/(256*256)));
    frwr.data.append((char)(uint8_t)(val/(256)));
    frwr.data.append((char)(uint8_t)(val/(1)));
    frwr.length = frwr.data.length();
    frwr.TransmitStatus = TrmtStatus_SendWithRxTimeout;
    frwr.rx_timeout = 1500;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(500);
}

void SVA35D_Config::on_Cancel_clicked()
{
    if (busyWaitMessage() == true)
    {
       return;
    }
    *pollRequestFlag = false;
    isOpened = false;
    this->close();
}

void SVA35D_Config::on_SVA35D_Config_finished(int result)
{
    pollTimer->deleteLater();
    this->deleteLater();
}
