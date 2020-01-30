#include "sr_control.h"
#include "ui_sr_control.h"

SR_Control::SR_Control(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SR_Control)
{
    ui->setupUi(this);
    comP = NULL;
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    isOpened = false;

    for (int i=0;i<6;i++)
    {
        QGroupBox *groupbox = new QGroupBox(this);
        groupbox->setObjectName(QString::fromUtf8("sk35d_Params"));
        groupbox->setGeometry(QRect(10, 5+i*78, 770, 75));
        QString title = "Релейный выход "+QString::number(i+1);
        groupbox->setTitle(QCoreApplication::translate("MainWindow", title.toUtf8(), nullptr));

        QComboBox *sr35d_relay = new QComboBox(groupbox);
        sr35d_relay->addItem(QString());
        sr35d_relay->addItem(QString());
        sr35d_relay->addItem(QString());
        sr35d_relay->addItem(QString());
        sr35d_relay->setObjectName(QString::fromUtf8("sr35d_relay"));
        sr35d_relay->setGeometry(QRect(160, 15, 600, 25));
        title = "Отключено";
        sr35d_relay->setItemText(0, QCoreApplication::translate("SR_Control", title.toUtf8(), nullptr));
        title = "Смена состояния выхода при аварии дискретного входа";
        sr35d_relay->setItemText(1, QCoreApplication::translate("SR_Control", title.toUtf8(), nullptr));
        title = "Включение выхода при аварии дискр. входа/ Выключение - при отмене аварии";
        sr35d_relay->setItemText(2, QCoreApplication::translate("SR_Control", title.toUtf8(), nullptr));
        title = "Смена состояния выхода при смене состояния  дискретного входа";
        sr35d_relay->setItemText(3, QCoreApplication::translate("SR_Control", title.toUtf8(), nullptr));
        RelaysList.append(sr35d_relay);

        QLabel *label_relay = new QLabel(groupbox);
        label_relay->setObjectName(QString::fromUtf8("label_relay")+QString::number(i));
        label_relay->setGeometry(QRect(10, 17, 150, 20));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_relay->sizePolicy().hasHeightForWidth());
        label_relay->setSizePolicy(sizePolicy);
        label_relay->setLayoutDirection(Qt::RightToLeft);
        label_relay->setAlignment(Qt::AlignLeft);
        title = "Способ управления";
        label_relay->setText(QCoreApplication::translate("SR_Control", title.toUtf8(), nullptr));

        QLabel *label_din = new QLabel(groupbox);
        label_din->setObjectName(QString::fromUtf8("label_relay")+QString::number(i));
        label_din->setGeometry(QRect(10, 47, 210, 20));
        QSizePolicy sizePolicy_din(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy_din.setHorizontalStretch(0);
        sizePolicy_din.setVerticalStretch(0);
        sizePolicy_din.setHeightForWidth(label_relay->sizePolicy().hasHeightForWidth());
        label_din->setSizePolicy(sizePolicy_din);
        label_din->setLayoutDirection(Qt::RightToLeft);
        label_din->setAlignment(Qt::AlignLeft);
        title = "Активные дискретные входы:";
        label_din->setText(QCoreApplication::translate("SR_Control", title.toUtf8(), nullptr));
        for (int j=0 ; j<8; j++)
        {
            QCheckBox *sr35d_dType = new QCheckBox(groupbox);
            sr35d_dType->setObjectName(QString::fromUtf8("dType")+QString::number(j)+QString::number(i));
            sr35d_dType->setGeometry(QRect(235+70*j, 47, 16, 20));
            TypeList.append(sr35d_dType);

            QLabel *sr35d_dTypeLabel = new QLabel(groupbox);
            sr35d_dTypeLabel->setObjectName(QString::fromUtf8("dTypeLabel")+QString::number(j)+QString::number(i));
            sr35d_dTypeLabel->setGeometry(QRect(220+70*j, 46, 16, 20));
            QSizePolicy sizePolicydType(QSizePolicy::Preferred, QSizePolicy::Preferred);
            sizePolicydType.setHorizontalStretch(0);
            sizePolicydType.setVerticalStretch(0);
            sizePolicydType.setHeightForWidth(sr35d_dTypeLabel->sizePolicy().hasHeightForWidth());
            sr35d_dTypeLabel->setSizePolicy(sizePolicydType);
            sr35d_dTypeLabel->setLayoutDirection(Qt::RightToLeft);
            sr35d_dTypeLabel->setAlignment(Qt::AlignCenter);
            sr35d_dTypeLabel->setText(QString::number(j+1));
        }

    }

    //Set poll timer
    {
        wrframe.data.clear();
        pollTimer = new QTimer(this);
        connect(pollTimer, SIGNAL(timeout()), this, SLOT(pollTimerTimeout()));
    }
}


SR_Control::~SR_Control()
{
    delete ui;
}

bool SR_Control::busyWaitMessage()
{
    if (pollTimer->isActive() == true)
    {
       QMessageBox::warning(NULL, tr("Внимание"),
                              tr("Дождитесь завершения операции"));
       return true;
    }
    return false;
}


void SR_Control::SR_DataLoad(ComPortTransmit *comPort, bool *RequestFlag, uint8_t maddress)
{
    comP = comPort;
    pollRequestFlag = RequestFlag;
    ModuleAddress = maddress;
    DataRequest();
}


void SR_Control::DataRequest()
{
    *pollRequestFlag = true;
    comP->queue.ClerQueueTxFrame();

    portFrame frame;

    frame.data.clear();
    frame.Function = Function_Read;
    const uint8_t req[]={ 0x8B, 0x8E, 0x91, 0x94, 0x97, 0x9A };
    frame.data.append((char*)req, sizeof(req));
    frame.length = frame.data.length();
    frame.ComAddress = ModuleAddress;
    frame.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frame);
    pollTimerQuant = 0;
    pollTimer->start(300);
}


void SR_Control::pollTimerTimeout()
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
                        case 0x8B: //Текущее состояние входов
                        case 0x8E:
                        case 0x91:
                        case 0x94:
                        case 0x97:
                        case 0x9A:
                        {
                            uint8_t raddr = ((uint8_t)answer.data.at(i)-0x8B)/3;
                            i++;
                            if (i < answer.length)
                            {
                                switch ((uint8_t)answer.data.at(i))
                                {
                                    default:
                                    case 0x00:
                                        RelaysList.at(raddr)->setCurrentIndex(0);
                                        break;
                                    case 0x0f:
                                        RelaysList.at(raddr)->setCurrentIndex(1);
                                        break;
                                    case 0xf0:
                                        RelaysList.at(raddr)->setCurrentIndex(2);
                                        break;
                                    case 0xff:
                                        RelaysList.at(raddr)->setCurrentIndex(3);
                                        break;
                                }
                                connect = true;
                            }
                            i++;
                            if (i < answer.length)
                            {
                                for (int j = 0; j < 8; j++)
                                {
                                    uint8_t dinst = (uint8_t)answer.data.at(i);
                                    if ((dinst & (1 << j)) > 0)
                                        TypeList.at(raddr*8+j)->setCheckState(Qt::CheckState::Checked);
                                    else
                                        TypeList.at(raddr*8+j)->setCheckState(Qt::CheckState::Unchecked);
                                }
                                connect = true;
                            }
                            i++;
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
                               tr("Модуль не отвечает на запрос"));
        if(isOpened == false)
            this->deleteLater();
    }
}


void SR_Control::on_SR_Control_finished(int result)
{
    pollTimer->deleteLater();
    this->deleteLater();
}

void SR_Control::on_Cancel_clicked()
{
    if (busyWaitMessage() == true)
    {
       return;
    }
    *pollRequestFlag = false;
    isOpened = false;
    this->close();
}

void SR_Control::on_Write_clicked()
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
    for (int i = 0; i < 6; i++)
    {
        frwr.data.append((char)(0x8B+i*3));
        switch(RelaysList.at(i)->currentIndex())
        {
            default:
            case 0:
                frwr.data.append((char)0x0);
                break;
            case 1:
                frwr.data.append((char)0x0f);
                break;
            case 2:
                frwr.data.append((char)0xf0);
                break;
            case 3:
                frwr.data.append((char)0xff);
                break;
        }
        uint8_t val=0;
        for(int j=0;j<8;j++)
        {
            if(TypeList.at(i*8+j)->checkState()==Qt::CheckState::Checked)
            {
                val |= 1<<j;
            }
        }
        frwr.data.append(val);
    }
    frwr.length = frwr.data.length();
    frwr.TransmitStatus = TrmtStatus_Send;
    comP->queue.EnqueueTxFrame(frwr);
    wrframe = frwr;
    pollTimerQuant = 0;
    pollTimer->start(300);
 }

