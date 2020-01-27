#include "sva35d_calib.h"
#include "ui_sva35d_calib.h"
#include <QTextCodec>

SVA35D_Calib::SVA35D_Calib(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SVA35D_Calib)
{
    ui->setupUi(this);

    comP = NULL;
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

    for (int n=0;n<4;n++)
    {
        sva35dCalibData[n] = NULL;
    }

    //Set poll timer
    {
        wrframe.data.clear();
        pollTimer = new QTimer(this);
        connect(pollTimer, SIGNAL(timeout()), this, SLOT(pollTimerTimeout()));
    }
    {
        updateTimer = new QTimer(this);
        connect(updateTimer, SIGNAL(timeout()), this, SLOT(updateTimerTimeout()));
        updateTimer->start(500);
    }
}

SVA35D_Calib::~SVA35D_Calib()
{
    delete ui;
}

bool SVA35D_Calib::busyWaitMessage()
{
    if (pollTimer->isActive() == true)
    {
       QMessageBox::warning(NULL, tr("Внимание"),
                              tr("Дождитесь завершения операции"));
       return true;
    }
    return false;
}


void SVA35D_Calib::DataLoad(ComPortTransmit *comPort, bool *RequestFlag, uint8_t maddress)
{
    comP = comPort;
    pollRequestFlag = RequestFlag;
    ModuleAddress = maddress;

    this->open();
}

void SVA35D_Calib::updateTimerTimeout()
{
    if(sva35dCalibData[0] != NULL)
    {
        ui->kvar_1->setText(*sva35dCalibData[0]);
    }
    if(sva35dCalibData[1] != NULL)
    {
        ui->kvar_2->setText(*sva35dCalibData[1]);
    }
    if(sva35dCalibData[2] != NULL)
    {
        ui->kvar_3->setText(*sva35dCalibData[2]);
    }
    if(sva35dCalibData[3] != NULL)
    {
        ui->dTemp->setText(*sva35dCalibData[3]);
    }
}

void SVA35D_Calib::pollTimerTimeout()
{
    bool connect = false;
    portFrame answer = comP->queue.DequeueRxFrame();
    if(answer.TransmitStatus == TrmtStatus_EventSuccess)
    {
        if(answer.Function == Function_Read)
        {
            if(ModuleAddress == answer.ComAddress)
            {
                if ((uint8_t)answer.data.at(0) == 0xC7)
                {
                    if ((uint8_t)answer.data.at(1) == 0x0)
                    {
                        if ((uint8_t)answer.data.at(2) == 0xff)
                            QMessageBox::information(NULL, tr("Внимание"),
                                                       tr("Калибровка завершена"));
                        else if ((uint8_t)answer.data.at(2) == 0x0f)
                            QMessageBox::information(NULL, tr("Внимание"),
                                                       tr("Калибровка в процессе"));
                        else if ((uint8_t)answer.data.at(2) == 0xf0)
                            QMessageBox::critical(NULL, tr("Внимание"),
                                                       tr("Калибровка провалена"));
                        connect = true;
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
        *pollRequestFlag = false;
    }
    else if(pollTimerQuant++ >= 5)
    {
        *pollRequestFlag = false;
        pollTimer->stop();
        QMessageBox::critical(NULL, tr("Внимание"),
                               tr("Датчик не отвечает на запрос"));
    }
}

void SVA35D_Calib::on_TempWrite_clicked()
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
    uint32_t val = (uint32_t)ui->Temp->value();
    frwr.data.append((char)0xC2);
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

void SVA35D_Calib::on_offsetWrite_clicked()
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
    frwr.data.append((char)0xC6);
    frwr.data.append((char)0x0);
    uint8_t bt=0;
    if(ui->phase_1->checkState() == Qt::CheckState::Checked)
    {
        bt |= 1;
    }
    if(ui->phase_2->checkState() == Qt::CheckState::Checked)
    {
        bt |= 2;
    }
    if(ui->phase_3->checkState() == Qt::CheckState::Checked)
    {
        bt |= 4;
    }
    frwr.data.append((char)bt);

    frwr.length = frwr.data.length();
    frwr.TransmitStatus = TrmtStatus_SendWithRxTimeout;
    frwr.rx_timeout = 1500;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(500);
}

void SVA35D_Calib::on_vWrite_clicked()
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
    uint32_t val = (uint32_t)ui->volt->value();
    frwr.data.append((char)0xC0);
    uint8_t bt = ((uint8_t)(val/(256*256*256)))&0x0f;
    if(ui->phase_1->checkState() == Qt::CheckState::Checked)
    {
        bt |= 0x10;
    }
    if(ui->phase_2->checkState() == Qt::CheckState::Checked)
    {
        bt |= 0x20;
    }
    if(ui->phase_3->checkState() == Qt::CheckState::Checked)
    {
        bt |= 0x40;
    }
    frwr.data.append((char)bt);

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
void SVA35D_Calib::on_cWrite_clicked()
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
    uint32_t val = (uint32_t)(ui->curr->value()*ui->mult->value());
    frwr.data.append((char)0xC0);
    uint8_t bt = ((uint8_t)(val/(256*256*256)))&0x0f;
    if(ui->phase_1->checkState() == Qt::CheckState::Checked)
    {
        bt |= 0x10;
    }
    if(ui->phase_2->checkState() == Qt::CheckState::Checked)
    {
        bt |= 0x20;
    }
    if(ui->phase_3->checkState() == Qt::CheckState::Checked)
    {
        bt |= 0x40;
    }
    frwr.data.append((char)bt);

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

void SVA35D_Calib::on_checkWrite_clicked()
{
    *pollRequestFlag = true;
    comP->queue.ClerQueueTxFrame();

    portFrame frame;

    frame.data.clear();
    frame.Function = Function_Read;
    const uint8_t req[]={ 0xC7 };
    frame.data.append((char*)req, sizeof(req));
    frame.length = frame.data.length();
    frame.ComAddress = ModuleAddress;
    frame.TransmitStatus = TrmtStatus_SendWithRxTimeout;
    frame.rx_timeout = 1500;
    comP->queue.EnqueueTxFrame(frame);
    pollTimerQuant = 0;
    pollTimer->start(500);
}

void SVA35D_Calib::on_aWrite_1_clicked()
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
    uint32_t val = (uint32_t)ui->angle_1->value();
    frwr.data.append((char)0xC3);
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

void SVA35D_Calib::on_aWrite_2_clicked()
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
    uint32_t val = (uint32_t)ui->angle_2->value();
    frwr.data.append((char)0xC4);
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

void SVA35D_Calib::on_aWrite_3_clicked()
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
    uint32_t val = (uint32_t)ui->angle_3->value();
    frwr.data.append((char)0xC5);
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


void SVA35D_Calib::on_Save_clicked()
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
    frwr.data.append((char)0xC8);
    frwr.data.append((char)0x0);
    frwr.data.append((char)0xf0);

    frwr.length = frwr.data.length();
    frwr.TransmitStatus = TrmtStatus_SendWithRxTimeout;
    frwr.rx_timeout = 2000;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(700);
}

void SVA35D_Calib::on_Write_clicked()
{
    *pollRequestFlag = true;
    comP->queue.ClerQueueTxFrame();

    portFrame frwr;
    frwr.Function = Function_Write;
    frwr.ComAddress = ModuleAddress;
    frwr.data.clear();
    frwr.data.append((char)0xCF);
    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
    frwr.data.append(codec->fromUnicode(ui->passw->text()));
    frwr.data.append((char)0x0);
    frwr.length = frwr.data.length();
    frwr.TransmitStatus = TrmtStatus_SendWithRxTimeout;
    frwr.rx_timeout = 1500;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(500);
}

void SVA35D_Calib::on_SVA35D_Calib_finished(int result)
{
    pollTimer->deleteLater();
    updateTimer->deleteLater();
    this->deleteLater();
}

void SVA35D_Calib::on_Cancel_clicked()
{
    if (busyWaitMessage() == true)
    {
       return;
    }
    *pollRequestFlag = false;
    this->close();
}
