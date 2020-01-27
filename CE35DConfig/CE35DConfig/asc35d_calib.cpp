#include "asc35d_calib.h"
#include "ui_asc35d_calib.h"
#include <QTextCodec>


ASC35D_Calib::ASC35D_Calib(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ASC35D_Calib)
{
    ui->setupUi(this);
    comP = NULL;
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    isOpened = false;
    connect(ui->Volt_1, SIGNAL(stateChanged(int)), this, SLOT(UpdateVoltChecks(int)));
    connect(ui->Volt_2, SIGNAL(stateChanged(int)), this, SLOT(UpdateVoltChecks(int)));

    //Set poll timer
    {
        wrframe.data.clear();
        pollTimer = new QTimer(this);
        connect(pollTimer, SIGNAL(timeout()), this, SLOT(pollTimerTimeout()));
    }
}

ASC35D_Calib::~ASC35D_Calib()
{
    delete ui;
}

bool ASC35D_Calib::busyWaitMessage()
{
    if (pollTimer->isActive() == true)
    {
       QMessageBox::warning(NULL, tr("Внимание"),
                              tr("Дождитесь завершения операции"));
       return true;
    }
    return false;
}

void ASC35D_Calib::DataLoad(ComPortTransmit *comPort, bool *RequestFlag, uint8_t maddress)
{
    comP = comPort;
    pollRequestFlag = RequestFlag;
    ModuleAddress = maddress;
    DataRequest();
}


void ASC35D_Calib::DataRequest()
{
    *pollRequestFlag = true;
    comP->queue.ClerQueueTxFrame();

    portFrame frame;

    frame.data.clear();
    frame.Function = Function_Read;
    const uint8_t req[]={ 0xC0, 0xC1, 0xCE };
    frame.data.append((char*)req, sizeof(req));
    frame.length = frame.data.length();
    frame.ComAddress = ModuleAddress;
    frame.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frame);
    pollTimerQuant = 0;
    pollTimer->start(300);
}


void ASC35D_Calib::pollTimerTimeout()
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
                        case 0xCE:
                            i++;
                            if ((i + 1) <= answer.length)
                            {
                                double val = (double)((int16_t)((uint16_t)(uint8_t)answer.data.at(i)*256+(uint16_t)(uint8_t)answer.data.at(i+1)));
                                ui->avg->setValue(val/10);
                                connect = true;
                                i += 2;
                            }
                            else connect = false;
                            break;

                        case 0xC0:
                        case 0xC1:
                        {
                            uint8_t code = (uint8_t)answer.data.at(i);
                            i+=2;
                            if (i <= answer.length)
                            {
                                switch (code)
                                {
                                    case 0xC0: scaleVcoeff[0]= (uint8_t)answer.data.at(i); break;
                                    case 0xC1: scaleVcoeff[1] = (uint8_t)answer.data.at(i); break;
                                }
                                UpdateVoltChecks(0);
                                connect = true;
                                i++;
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

void ASC35D_Calib::UpdateVoltChecks(int state)
{
    int indx = 0;
    if (ui->Volt_1->checkState() == Qt::CheckState::Unchecked && ui->Volt_2->checkState() == Qt::CheckState::Checked)
    {
        indx = 1;
        ui->v_dia_label->setText(tr("№2"));
    }
    else if (ui->Volt_1->checkState() == Qt::CheckState::Checked && ui->Volt_2->checkState() == Qt::CheckState::Checked)
    {
        ui->v_dia_label->setText(tr("№1,№2"));
    }
    else
    {
         ui->v_dia_label->setText(tr("№1"));
    }
    switch (scaleVcoeff[indx])
    {
        default:
        case 0x00:
            ui->Dia->setCurrentIndex(0);
            break;
        case 0x0f:
            ui->Dia->setCurrentIndex(1);
            break;
        case 0xf0:
            ui->Dia->setCurrentIndex(2);
            break;
    }
}

void ASC35D_Calib::on_Cancel_clicked()
{
    if (busyWaitMessage() == true)
    {
       return;
    }
    *pollRequestFlag = false;
    isOpened = false;
    this->close();
}

void ASC35D_Calib::on_ASC35D_Calib_finished(int result)
{
    pollTimer->deleteLater();
    this->deleteLater();
}

void ASC35D_Calib::on_v_diaWrite_clicked()
{
    if (busyWaitMessage() == true)
    {
       return;
    }
    if (ui->Volt_1->checkState() == Qt::CheckState::Unchecked && ui->Volt_2->checkState() == Qt::CheckState::Unchecked)
    {
        QMessageBox::warning(NULL, tr("Внимание"),tr("Не выбрано ни одного датчика"));
        return;
    }

    *pollRequestFlag = true;
    comP->queue.ClerQueueTxFrame();

    portFrame frwr;
    frwr.Function = Function_Write;
    frwr.ComAddress = ModuleAddress;
    frwr.data.clear();

    if (ui->Volt_1->checkState() == Qt::CheckState::Checked)
    {
        frwr.data.append((char)0xC0);
        frwr.data.append((char)0x0);
        switch(ui->Dia->currentIndex())
        {
            default:
            case 0: frwr.data.append((char)0x0);break;
            case 1: frwr.data.append((char)0x0f);break;
            case 2: frwr.data.append((char)0xf0);break;
        }
    }
    if (ui->Volt_2->checkState() == Qt::CheckState::Checked)
    {
        frwr.data.append((char)0xC1);
        frwr.data.append((char)0x0);
        switch(ui->Dia->currentIndex())
        {
            default:
            case 0: frwr.data.append((char)0x0);break;
            case 1: frwr.data.append((char)0x0f);break;
            case 2: frwr.data.append((char)0xf0);break;
        }
    }
    frwr.length = frwr.data.length();
    frwr.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(300);
}

void ASC35D_Calib::on_v_upWrite_clicked()
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
    uint32_t val = (uint32_t)ui->v_up->value();
    frwr.data.append((char)0xC4);
    frwr.data.append((char)(uint8_t)(val/(256*256*256)));
    frwr.data.append((char)(uint8_t)(val/(256*256)));
    frwr.data.append((char)(uint8_t)(val/(256)));
    frwr.data.append((char)(uint8_t)(val/(1)));

    frwr.length = frwr.data.length();
    frwr.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(300);
}

void ASC35D_Calib::on_v_dwnWrite_clicked()
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
    uint32_t val = (uint32_t)ui->v_dwn->value();
    frwr.data.append((char)0xC3);
    frwr.data.append((char)(uint8_t)(val/(256*256*256)));
    frwr.data.append((char)(uint8_t)(val/(256*256)));
    frwr.data.append((char)(uint8_t)(val/(256)));
    frwr.data.append((char)(uint8_t)(val/(1)));

    frwr.length = frwr.data.length();
    frwr.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(300);
}

void ASC35D_Calib::on_v_Calibrate_clicked()
{
    if (busyWaitMessage() == true)
    {
       return;
    }
    if (ui->Volt_1->checkState() == Qt::CheckState::Unchecked && ui->Volt_2->checkState() == Qt::CheckState::Unchecked)
    {
        QMessageBox::warning(NULL, tr("Внимание"),tr("Не выбрано ни одного датчика"));
        return;
    }
    *pollRequestFlag = true;
    comP->queue.ClerQueueTxFrame();

    portFrame frwr;
    frwr.Function = Function_Write;
    frwr.ComAddress = ModuleAddress;
    frwr.data.clear();
    frwr.data.append((char)0xC2);
    frwr.data.append((char)0x0);
    uint8_t data=0x0;
    if(ui->Volt_1->checkState() == Qt::CheckState::Checked)
    {
        data |=0x0f;
    }
    if(ui->Volt_2->checkState() == Qt::CheckState::Checked)
    {
        data |=0xf0;
    }
    frwr.length = frwr.data.length();
    frwr.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(300);
}

void ASC35D_Calib::on_i_zWrite_clicked()
{
    if (busyWaitMessage() == true)
    {
       return;
    }
    if (ui->Curr_1->checkState() == Qt::CheckState::Unchecked && ui->Curr_2->checkState() == Qt::CheckState::Unchecked)
    {
        QMessageBox::warning(NULL, tr("Внимание"),tr("Не выбрано ни одного датчика"));
        return;
    }
    *pollRequestFlag = true;
    comP->queue.ClerQueueTxFrame();

    portFrame frwr;
    frwr.Function = Function_Write;
    frwr.ComAddress = ModuleAddress;
    frwr.data.clear();
    frwr.data.append((char)0xC5);
    frwr.data.append((char)0x0);
    uint8_t data=0x0;
    if(ui->Curr_1->checkState() == Qt::CheckState::Checked)
    {
        data |=0x0f;
    }
    if(ui->Curr_2->checkState() == Qt::CheckState::Checked)
    {
        data |=0xf0;
    }
    frwr.length = frwr.data.length();
    frwr.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(300);
}

void ASC35D_Calib::on_i_Write_clicked()
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
    uint32_t val = (uint32_t)ui->i_val->value();
    frwr.data.append((char)0xC7);
    frwr.data.append((char)(uint8_t)(val/(256*256*256)));
    frwr.data.append((char)(uint8_t)(val/(256*256)));
    frwr.data.append((char)(uint8_t)(val/(256)));
    frwr.data.append((char)(uint8_t)(val/(1)));

    frwr.length = frwr.data.length();
    frwr.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(300);
}

void ASC35D_Calib::on_i_Calibrate_clicked()
{
    if (busyWaitMessage() == true)
    {
       return;
    }
    if (ui->Curr_1->checkState() == Qt::CheckState::Unchecked && ui->Curr_2->checkState() == Qt::CheckState::Unchecked)
    {
        QMessageBox::warning(NULL, tr("Внимание"),tr("Не выбрано ни одного датчика"));
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
    uint8_t data=0x0;
    if(ui->Curr_1->checkState() == Qt::CheckState::Checked)
    {
        data |=0x0f;
    }
    if(ui->Curr_2->checkState() == Qt::CheckState::Checked)
    {
        data |=0xf0;
    }
    frwr.length = frwr.data.length();
    frwr.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(300);
}

void ASC35D_Calib::on_c_upWrite_clicked()
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
    uint32_t val = (uint32_t)ui->c_up->value();
    frwr.data.append((char)0xCB);
    frwr.data.append((char)(uint8_t)(val/(256*256*256)));
    frwr.data.append((char)(uint8_t)(val/(256*256)));
    frwr.data.append((char)(uint8_t)(val/(256)));
    frwr.data.append((char)(uint8_t)(val/(1)));

    frwr.length = frwr.data.length();
    frwr.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(300);
}

void ASC35D_Calib::on_c_dwnWrite_clicked()
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
    uint32_t val = (uint32_t)ui->c_dwn->value();
    frwr.data.append((char)0xCA);
    frwr.data.append((char)(uint8_t)(val/(256*256*256)));
    frwr.data.append((char)(uint8_t)(val/(256*256)));
    frwr.data.append((char)(uint8_t)(val/(256)));
    frwr.data.append((char)(uint8_t)(val/(1)));

    frwr.length = frwr.data.length();
    frwr.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(300);
}

void ASC35D_Calib::on_c_Calibrate_clicked()
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
    frwr.data.append((char)0xC9);
    uint8_t data=0x0;
    if(ui->Cloop_4->isChecked() == true)
    {
        data |=0xf0;
    }
    else if(ui->Cloop_3->isChecked() == true)
    {
        data |=0x0f;
    }
    frwr.data.append((char)data);
    data=0x0;
    if(ui->Cloop_2->isChecked() == true)
    {
        data |=0xf0;
    }
    else if(ui->Cloop_1->isChecked() == true)
    {
        data |=0x0f;
    }
    frwr.data.append((char)data);
    frwr.length = frwr.data.length();
    frwr.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(300);
}





void ASC35D_Calib::on_avgWrite_clicked()
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
    frwr.data.append((char)0xCE);
    uint16_t val = (uint16_t)(ui->avg->value()*10);
    frwr.data.append((char)(uint8_t)(val/(256)));
    frwr.data.append((char)(uint8_t)(val/(1)));

    frwr.length = frwr.data.length();
    frwr.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(300);
}

void ASC35D_Calib::on_pswWrite_clicked()
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
    frwr.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(300);
}







