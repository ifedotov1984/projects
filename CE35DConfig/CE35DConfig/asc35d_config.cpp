#include "asc35d_config.h"
#include "ui_asc35d_config.h"
#include <QTextCodec>

ASC35D_Config::ASC35D_Config(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ASC35D_Config)
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

ASC35D_Config::~ASC35D_Config()
{
    delete ui;
}


bool ASC35D_Config::busyWaitMessage()
{
    if (pollTimer->isActive() == true)
    {
       QMessageBox::warning(NULL, tr("Внимание"),
                              tr("Дождитесь завершения операции"));
       return true;
    }
    return false;
}

void ASC35D_Config::DataLoad(ComPortTransmit *comPort, bool *RequestFlag, uint8_t maddress)
{
    comP = comPort;
    pollRequestFlag = RequestFlag;
    ModuleAddress = maddress;
    DataRequest();
}


void ASC35D_Config::DataRequest()
{
    *pollRequestFlag = true;
    comP->queue.ClerQueueTxFrame();

    portFrame frame;

    frame.data.clear();
    frame.Function = Function_Read;
    const uint8_t req[]={ 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35 };
    frame.data.append((char*)req, sizeof(req));
    frame.length = frame.data.length();
    frame.ComAddress = ModuleAddress;
    frame.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frame);
    pollTimerQuant = 0;
    pollTimer->start(300);
}


void ASC35D_Config::pollTimerTimeout()
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
                        case 0x12:
                        case 0x13:
                        case 0x14:
                        case 0x15:
                        case 0x16:
                        case 0x17:
                        case 0x18:
                        case 0x19:
                        case 0x1A:
                        case 0x1B:
                        case 0x1C:
                        case 0x1D:
                        {
                            uint8_t cn = (uint8_t)answer.data.at(i);
                            i++;
                            if ((i + 1) < answer.length)
                            {
                                uint8_t val=(uint16_t)(uint8_t)answer.data.at(i)*256+(uint16_t)(uint8_t)answer.data.at(i+1);
                                switch (cn)
                                {
                                    case 0x10: ui->dec_1->setValue(val); break;
                                    case 0x11: ui->dec_2->setValue(val); break;
                                    case 0x12: ui->i_low_1->setValue(val); break;
                                    case 0x13: ui->i_high_1->setValue(val); break;
                                    case 0x14: ui->i_dec_1->setValue(val); break;
                                    case 0x15: ui->i_low_2->setValue(val); break;
                                    case 0x16: ui->i_high_2->setValue(val); break;
                                    case 0x17: ui->i_dec_2->setValue(val); break;
                                    case 0x18: ui->i_low_3->setValue(val); break;
                                    case 0x19: ui->i_high_3->setValue(val); break;
                                    case 0x1A: ui->i_dec_3->setValue(val); break;
                                    case 0x1B: ui->i_low_4->setValue(val); break;
                                    case 0x1C: ui->i_high_4->setValue(val); break;
                                    case 0x1D: ui->i_dec_4->setValue(val); break;
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
                        case 0x24:
                        case 0x25:
                        case 0x26:
                        case 0x27:
                        case 0x28:
                        case 0x29:
                        case 0x2A:
                        case 0x2B:
                        {
                            uint8_t cn = (uint8_t)answer.data.at(i);
                            i++;
                            if ((i + 3) < answer.length)
                            {
                                int32_t val = ((int32_t)((uint32_t)(uint8_t)answer.data.at(i)*256*256*256+(uint32_t)(uint8_t)answer.data.at(i+1)*256*256+(uint32_t)(uint8_t)answer.data.at(i+2)*256+(uint8_t)answer.data.at(i+3)));
                                switch (cn)
                                {
                                    case 0x20: ui->koeff_K_1->setValue(val); break;
                                    case 0x21: ui->koeff_Z_1->setValue(val); break;
                                    case 0x22: ui->koeff_K_2->setValue(val); break;
                                    case 0x23: ui->koeff_Z_2->setValue(val); break;
                                    case 0x24: ui->p_low_1->setValue(val); break;
                                    case 0x25: ui->p_high_1->setValue(val); break;
                                    case 0x26: ui->p_low_2->setValue(val); break;
                                    case 0x27: ui->p_high_2->setValue(val); break;
                                    case 0x28: ui->p_low_3->setValue(val); break;
                                    case 0x29: ui->p_high_3->setValue(val); break;
                                    case 0x2A: ui->p_low_4->setValue(val); break;
                                    case 0x2B: ui->p_high_4->setValue(val); break;
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
                            ui->dim_1->setText(codec->toUnicode(answer.data.mid(i,j)));
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
                        case 0x32:
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
                            ui->i_dim_1->setText(codec->toUnicode(answer.data.mid(i,j)));
                            i = i + j + 1;
                            connect = true;
                            break;
                        }
                        case 0x33:
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
                            ui->i_dim_2->setText(codec->toUnicode(answer.data.mid(i,j)));
                            i = i + j + 1;
                            connect = true;
                            break;
                        }
                        case 0x34:
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
                            ui->i_dim_3->setText(codec->toUnicode(answer.data.mid(i,j)));
                            i = i + j + 1;
                            connect = true;
                            break;
                        }
                        case 0x35:
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
                            ui->i_dim_4->setText(codec->toUnicode(answer.data.mid(i,j)));
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


void ASC35D_Config::on_ASC35D_Config_finished(int result)
{
    pollTimer->deleteLater();
    this->deleteLater();
}

void ASC35D_Config::on_Cancel_clicked()
{
    if (busyWaitMessage() == true)
    {
       return;
    }
    *pollRequestFlag = false;
    isOpened = false;
    this->close();
}

void ASC35D_Config::on_i_Write_1_clicked()
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
    frwr.data.append((char)0x12);
    uint16_t val=(uint16_t)ui->i_low_1->value();
    frwr.data.append((char)(uint8_t)(val/(256)));
    frwr.data.append((char)(uint8_t)(val/(1)));

    frwr.data.append((char)0x13);
    val=(uint16_t)ui->i_high_1->value();
    frwr.data.append((char)(uint8_t)(val/(256)));
    frwr.data.append((char)(uint8_t)(val/(1)));

    frwr.data.append((char)0x24);
    uint32_t val32=(uint32_t)ui->p_low_1->value();
    frwr.data.append((char)(uint8_t)(val32/(256*256*256)));
    frwr.data.append((char)(uint8_t)(val32/(256*256)));
    frwr.data.append((char)(uint8_t)(val32/(256)));
    frwr.data.append((char)(uint8_t)(val32/(1)));

    frwr.data.append((char)0x25);
    val32=(uint32_t)ui->p_high_1->value();
    frwr.data.append((char)(uint8_t)(val32/(256*256*256)));
    frwr.data.append((char)(uint8_t)(val32/(256*256)));
    frwr.data.append((char)(uint8_t)(val32/(256)));
    frwr.data.append((char)(uint8_t)(val32/(1)));

    frwr.data.append((char)0x14);
    frwr.data.append((char)0x0);
    frwr.data.append((char)ui->i_dec_1->value());

    frwr.data.append((char)0x32);
    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
    frwr.data.append(codec->fromUnicode(ui->i_dim_1->text()));
    frwr.data.append((char)0x0);

    frwr.length = frwr.data.length();
    frwr.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(300);
}

void ASC35D_Config::on_i_Write_2_clicked()
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
    frwr.data.append((char)0x15);
    uint16_t val=(uint16_t)ui->i_low_2->value();
    frwr.data.append((char)(uint8_t)(val/(256)));
    frwr.data.append((char)(uint8_t)(val/(1)));

    frwr.data.append((char)0x16);
    val=(uint16_t)ui->i_high_2->value();
    frwr.data.append((char)(uint8_t)(val/(256)));
    frwr.data.append((char)(uint8_t)(val/(1)));

    frwr.data.append((char)0x26);
    uint32_t val32=(uint32_t)ui->p_low_2->value();
    frwr.data.append((char)(uint8_t)(val32/(256*256*256)));
    frwr.data.append((char)(uint8_t)(val32/(256*256)));
    frwr.data.append((char)(uint8_t)(val32/(256)));
    frwr.data.append((char)(uint8_t)(val32/(1)));

    frwr.data.append((char)0x27);
    val32=(uint32_t)ui->p_high_2->value();
    frwr.data.append((char)(uint8_t)(val32/(256*256*256)));
    frwr.data.append((char)(uint8_t)(val32/(256*256)));
    frwr.data.append((char)(uint8_t)(val32/(256)));
    frwr.data.append((char)(uint8_t)(val32/(1)));

    frwr.data.append((char)0x17);
    frwr.data.append((char)0x0);
    frwr.data.append((char)ui->i_dec_2->value());

    frwr.data.append((char)0x33);
    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
    frwr.data.append(codec->fromUnicode(ui->i_dim_2->text()));
    frwr.data.append((char)0x0);

    frwr.length = frwr.data.length();
    frwr.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(300);
}

void ASC35D_Config::on_i_Write_3_clicked()
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
    frwr.data.append((char)0x18);
    uint16_t val=(uint16_t)ui->i_low_3->value();
    frwr.data.append((char)(uint8_t)(val/(256)));
    frwr.data.append((char)(uint8_t)(val/(1)));

    frwr.data.append((char)0x19);
    val=(uint16_t)ui->i_high_3->value();
    frwr.data.append((char)(uint8_t)(val/(256)));
    frwr.data.append((char)(uint8_t)(val/(1)));

    frwr.data.append((char)0x28);
    uint32_t val32=(uint32_t)ui->p_low_3->value();
    frwr.data.append((char)(uint8_t)(val32/(256*256*256)));
    frwr.data.append((char)(uint8_t)(val32/(256*256)));
    frwr.data.append((char)(uint8_t)(val32/(256)));
    frwr.data.append((char)(uint8_t)(val32/(1)));

    frwr.data.append((char)0x29);
    val32=(uint32_t)ui->p_high_3->value();
    frwr.data.append((char)(uint8_t)(val32/(256*256*256)));
    frwr.data.append((char)(uint8_t)(val32/(256*256)));
    frwr.data.append((char)(uint8_t)(val32/(256)));
    frwr.data.append((char)(uint8_t)(val32/(1)));

    frwr.data.append((char)0x1A);
    frwr.data.append((char)0x0);
    frwr.data.append((char)ui->i_dec_3->value());

    frwr.data.append((char)0x34);
    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
    frwr.data.append(codec->fromUnicode(ui->i_dim_3->text()));
    frwr.data.append((char)0x0);

    frwr.length = frwr.data.length();
    frwr.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(300);
}

void ASC35D_Config::on_i_Write_4_clicked()
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
    frwr.data.append((char)0x1B);
    uint16_t val=(uint16_t)ui->i_low_4->value();
    frwr.data.append((char)(uint8_t)(val/(256)));
    frwr.data.append((char)(uint8_t)(val/(1)));

    frwr.data.append((char)0x1C);
    val=(uint16_t)ui->i_high_4->value();
    frwr.data.append((char)(uint8_t)(val/(256)));
    frwr.data.append((char)(uint8_t)(val/(1)));

    frwr.data.append((char)0x2A);
    uint32_t val32=(uint32_t)ui->p_low_4->value();
    frwr.data.append((char)(uint8_t)(val32/(256*256*256)));
    frwr.data.append((char)(uint8_t)(val32/(256*256)));
    frwr.data.append((char)(uint8_t)(val32/(256)));
    frwr.data.append((char)(uint8_t)(val32/(1)));

    frwr.data.append((char)0x2B);
    val32=(uint32_t)ui->p_high_4->value();
    frwr.data.append((char)(uint8_t)(val32/(256*256*256)));
    frwr.data.append((char)(uint8_t)(val32/(256*256)));
    frwr.data.append((char)(uint8_t)(val32/(256)));
    frwr.data.append((char)(uint8_t)(val32/(1)));

    frwr.data.append((char)0x1D);
    frwr.data.append((char)0x0);
    frwr.data.append((char)ui->i_dec_4->value());

    frwr.data.append((char)0x35);
    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
    frwr.data.append(codec->fromUnicode(ui->i_dim_4->text()));
    frwr.data.append((char)0x0);

    frwr.length = frwr.data.length();
    frwr.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(300);
}

void ASC35D_Config::on_dWrite_1_clicked()
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
    uint32_t val=(uint32_t)ui->koeff_K_1->value();
    frwr.data.append((char)(uint8_t)(val/(256*256*256)));
    frwr.data.append((char)(uint8_t)(val/(256*256)));
    frwr.data.append((char)(uint8_t)(val/(256)));
    frwr.data.append((char)(uint8_t)(val/(1)));

    frwr.data.append((char)0x21);
    val=(uint32_t)ui->koeff_Z_1->value();
    frwr.data.append((char)(uint8_t)(val/(256*256*256)));
    frwr.data.append((char)(uint8_t)(val/(256*256)));
    frwr.data.append((char)(uint8_t)(val/(256)));
    frwr.data.append((char)(uint8_t)(val/(1)));

    frwr.data.append((char)0x10);
    frwr.data.append((char)0x0);
    frwr.data.append((char)ui->dec_1->value());

    frwr.data.append((char)0x30);
    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
    frwr.data.append(codec->fromUnicode(ui->dim_1->text()));
    frwr.data.append((char)0x0);

    frwr.length = frwr.data.length();
    frwr.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(300);
}

void ASC35D_Config::on_dWrite_2_clicked()
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
