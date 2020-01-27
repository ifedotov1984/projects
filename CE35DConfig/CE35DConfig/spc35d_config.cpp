#include "spc35d_config.h"
#include "ui_spc35d_config.h"
#include <QTextCodec>

SPC35D_Config::SPC35D_Config(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SPC35D_Config)
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

SPC35D_Config::~SPC35D_Config()
{
    delete ui;
}

bool SPC35D_Config::busyWaitMessage()
{
    if (pollTimer->isActive() == true)
    {
       QMessageBox::warning(NULL, tr("Внимание"),
                              tr("Дождитесь завершения операции"));
       return true;
    }
    return false;
}

void SPC35D_Config::DataLoad(ComPortTransmit *comPort, bool *RequestFlag, uint8_t maddress)
{
    comP = comPort;
    pollRequestFlag = RequestFlag;
    ModuleAddress = maddress;
    DataRequest();
}


void SPC35D_Config::DataRequest()
{
    *pollRequestFlag = true;
    comP->queue.ClerQueueTxFrame();

    portFrame frame;

    frame.data.clear();
    frame.Function = Function_Read;
    const uint8_t req[]={ 0xAB, 0xAC };
    frame.data.append((char*)req, sizeof(req));
    frame.length = frame.data.length();
    frame.ComAddress = ModuleAddress;
    frame.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frame);
    pollTimerQuant = 0;
    pollTimer->start(300);
}

void SPC35D_Config::pollTimerTimeout()
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
                        case 0xAB:
                        {
                            i++;
                            int j = 0;
                            while ((uint8_t)answer.data.at(i + j) != 0x0) j++;
                            if (j > 20)
                            {
                                connect = false;
                                break;
                            }
                            QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
                            ui->addr->setText(codec->toUnicode(answer.data.mid(i,j)));
                            i = i + j + 1;
                            connect = true;
                            break;
                        }
                        case 0xAC:
                        {
                            i++;
                            int j = 0;
                            while ((uint8_t)answer.data.at(i + j) != 0x0) j++;
                            if (j > 20)
                            {
                                connect = false;
                                break;
                            }
                            QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
                            ui->passw->setText(codec->toUnicode(answer.data.mid(i,j)));
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


void SPC35D_Config::on_addrWrite_clicked()
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
    frwr.data.append((char)0xAB);
    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
    frwr.data.append(codec->fromUnicode(ui->addr->text()));
    frwr.data.append((char)0x0);

    frwr.length = frwr.data.length();
    frwr.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(300);
}

void SPC35D_Config::on_passwWrite_clicked()
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
    frwr.data.append((char)0xAC);
    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
    frwr.data.append(codec->fromUnicode(ui->passw->text()));
    frwr.data.append((char)0x0);

    frwr.length = frwr.data.length();
    frwr.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(300);
}

void SPC35D_Config::on_SPC35D_Config_finished(int result)
{
    pollTimer->deleteLater();
    this->deleteLater();
}

void SPC35D_Config::on_Cancel_clicked()
{
    if (busyWaitMessage() == true)
    {
       return;
    }
    *pollRequestFlag = false;
    isOpened = false;
    this->close();
}
