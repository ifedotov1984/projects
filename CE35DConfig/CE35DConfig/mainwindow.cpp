#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "portselect.h"
#include "sr_control.h"
#include "csrs485_config.h"
#include "csrs485_calib.h"
#include "vcrs485_config.h"
#include "vcrs485_calib.h"
#include "asc35d_config.h"
#include "asc35d_calib.h"
#include "sva35d_config.h"
#include "sva35d_calib.h"
#include "spc35d_config.h"
#include "about.h"
#include <QtMath>
#include <QTextCodec>
#include <QStyleFactory>
#include <QApplication>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->menu_openPort, SIGNAL(triggered()), this, SLOT(onMenu_PortOpen()));
    connect(ui->menu_closePort, SIGNAL(triggered()), this, SLOT(onMenu_PortClose()));
    connect(ui->menuAbout, SIGNAL(triggered()), this, SLOT(onMenu_About()));
    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(onTabWidget_Changed(int)));

    ui->tabWidget->setCurrentIndex(0);

/*#ifndef Q_OS_WIN
    int h = this->height()-15;
    this->setMinimumHeight(h);
    this->setMaximumHeight(h);
    this->setFixedHeight(h);
#endif*/
    //SK-35D region
    {
        //SK-35D Type CheckBoxes
        for(int i=0;i<16;i++)
        {
            QCheckBox *sk35d_Type = new QCheckBox(ui->sk35d_Params);
            sk35d_Type->setObjectName(QString::fromUtf8("sk35d_Type")+QString::number(i));
            sk35d_Type->setGeometry(QRect(33+20*i, 280, 15, 15));
            sk35d_TypeList.append(sk35d_Type);

            QLabel *sk35d_TypeLabel = new QLabel(ui->sk35d_Params);
            sk35d_TypeLabel->setObjectName(QString::fromUtf8("sk35d_TypeLabel")+QString::number(i));
            sk35d_TypeLabel->setGeometry(QRect(32+20*i, 265, 15, 15));
            QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
            sizePolicy.setHorizontalStretch(0);
            sizePolicy.setVerticalStretch(0);
            sizePolicy.setHeightForWidth(sk35d_TypeLabel->sizePolicy().hasHeightForWidth());
            sk35d_TypeLabel->setSizePolicy(sizePolicy);
            sk35d_TypeLabel->setLayoutDirection(Qt::RightToLeft);
            sk35d_TypeLabel->setAlignment(Qt::AlignCenter);
            sk35d_TypeLabel->setText(QString::number(i+1));
        }
        //SK-35D Status CheckBoxes
        for(int i=0;i<16;i++)
        {
            QCheckBox *sk35d_Status = new QCheckBox(ui->sk35dTab);
            sk35d_Status->setObjectName(QString::fromUtf8("sk35d_Status")+QString::number(i));
            sk35d_Status->setGeometry(QRect(41+20*i, 410, 15, 15));
            sk35d_Status->setCheckable(false);
            checkboxStatusColorSet(sk35d_Status, Qt::gray);

            sk35d_StatusList.append(sk35d_Status);

            QLabel *sk35d_StatusLabel = new QLabel(ui->sk35dTab);
            sk35d_StatusLabel->setObjectName(QString::fromUtf8("sk35d_StatusLabel")+QString::number(i));
            sk35d_StatusLabel->setGeometry(QRect(40+20*i, 395, 15, 15));
            QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
            sizePolicy.setHorizontalStretch(0);
            sizePolicy.setVerticalStretch(0);
            sizePolicy.setHeightForWidth(sk35d_StatusLabel->sizePolicy().hasHeightForWidth());
            sk35d_StatusLabel->setSizePolicy(sizePolicy);
            sk35d_StatusLabel->setLayoutDirection(Qt::RightToLeft);
            sk35d_StatusLabel->setAlignment(Qt::AlignCenter);
            sk35d_StatusLabel->setText(QString::number(i+1));
        }
        ui->sk35d_Params->setEnabled(false);
        connect(ui->sk35d_Write, SIGNAL(clicked()), this, SLOT(onWriteButton_Click()));
        connect(ui->sk35dModuleN, SIGNAL(valueChanged(int)), this, SLOT(onModuleN_Changed(int)));
        sk35d_DisconnectedDataSet();
    }
    //SVC-35D region
    {
        //SVC-35D Type CheckBoxes
        for(int i=0;i<16;i++)
        {
            QCheckBox *svc35d_Type = new QCheckBox(ui->svc35d_Params);
            svc35d_Type->setObjectName(QString::fromUtf8("svc35d_Type")+QString::number(i));
            svc35d_Type->setGeometry(QRect(33+20*i, 280, 15, 15));
            svc35d_TypeList.append(svc35d_Type);

            QLabel *svc35d_TypeLabel = new QLabel(ui->svc35d_Params);
            svc35d_TypeLabel->setObjectName(QString::fromUtf8("svc35d_TypeLabel")+QString::number(i));
            svc35d_TypeLabel->setGeometry(QRect(32+20*i, 265, 15, 15));
            QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
            sizePolicy.setHorizontalStretch(0);
            sizePolicy.setVerticalStretch(0);
            sizePolicy.setHeightForWidth(svc35d_TypeLabel->sizePolicy().hasHeightForWidth());
            svc35d_TypeLabel->setSizePolicy(sizePolicy);
            svc35d_TypeLabel->setLayoutDirection(Qt::RightToLeft);
            svc35d_TypeLabel->setAlignment(Qt::AlignCenter);
            svc35d_TypeLabel->setText(QString::number(i+1));
        }
        //SVC-35D Status CheckBoxes
        for(int i=0;i<16;i++)
        {
            QCheckBox *svc35d_Status = new QCheckBox(ui->svc35dTab);
            svc35d_Status->setObjectName(QString::fromUtf8("svc35d_Status")+QString::number(i));
            svc35d_Status->setGeometry(QRect(41+20*i, 410, 15, 15));
            svc35d_Status->setCheckable(false);
            checkboxStatusColorSet(svc35d_Status, Qt::gray);

            svc35d_StatusList.append(svc35d_Status);

            QLabel *svc35d_StatusLabel = new QLabel(ui->svc35dTab);
            svc35d_StatusLabel->setObjectName(QString::fromUtf8("svc35d_StatusLabel")+QString::number(i));
            svc35d_StatusLabel->setGeometry(QRect(40+20*i, 395, 15, 15));
            QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
            sizePolicy.setHorizontalStretch(0);
            sizePolicy.setVerticalStretch(0);
            sizePolicy.setHeightForWidth(svc35d_StatusLabel->sizePolicy().hasHeightForWidth());
            svc35d_StatusLabel->setSizePolicy(sizePolicy);
            svc35d_StatusLabel->setLayoutDirection(Qt::RightToLeft);
            svc35d_StatusLabel->setAlignment(Qt::AlignCenter);
            svc35d_StatusLabel->setText(QString::number(i+1));
        }
        ui->svc35d_Params->setEnabled(false); 
        connect(ui->svc35d_Write, SIGNAL(clicked()), this, SLOT(onWriteButton_Click()));
        connect(ui->svc35dModuleN, SIGNAL(valueChanged(int)), this, SLOT(onModuleN_Changed(int)));
        svc35d_DisconnectedDataSet();
    }
    //SR-35D region
    {
        //SR-35D Relays
        sr35d_RelayList.append(ui->sr35d_Relay1);
        sr35d_RelayList.append(ui->sr35d_Relay2);
        sr35d_RelayList.append(ui->sr35d_Relay3);
        sr35d_RelayList.append(ui->sr35d_Relay4);
        sr35d_RelayList.append(ui->sr35d_Relay5);
        sr35d_RelayList.append(ui->sr35d_Relay6);
        sr35d_RelaySaveList.append(ui->sr35d_Relay1Save);
        sr35d_RelaySaveList.append(ui->sr35d_Relay2Save);
        sr35d_RelaySaveList.append(ui->sr35d_Relay3Save);
        sr35d_RelaySaveList.append(ui->sr35d_Relay4Save);
        sr35d_RelaySaveList.append(ui->sr35d_Relay5Save);
        sr35d_RelaySaveList.append(ui->sr35d_Relay6Save);
        //SR-35D DIN Type CheckBoxes
        for(int i=0;i<8;i++)
        {
            QCheckBox *sr35d_Type = new QCheckBox(ui->sr35d_DinParams);
            sr35d_Type->setObjectName(QString::fromUtf8("sr35d_Type")+QString::number(i));
            sr35d_Type->setGeometry(QRect(16+45*i, 90, 15, 15));
            sr35d_TypeList.append(sr35d_Type);
        }
        //SR-35D DINStatus CheckBoxes
        for(int i=0;i<8;i++)
        {
            QCheckBox *sr35d_Status = new QCheckBox(ui->sr35dTab);
            sr35d_Status->setObjectName(QString::fromUtf8("sr35d_Status")+QString::number(i));
            sr35d_Status->setGeometry(QRect(31+45*i, 410, 15, 15));
            sr35d_Status->setCheckable(false);
            checkboxStatusColorSet(sr35d_Status, Qt::gray);

            sr35d_StatusList.append(sr35d_Status);

            QLabel *sr35d_StatusLabel = new QLabel(ui->sr35dTab);
            sr35d_StatusLabel->setObjectName(QString::fromUtf8("sr35d_StatusLabel")+QString::number(i));
            sr35d_StatusLabel->setGeometry(QRect(30+45*i, 395, 15, 15));
            QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
            sizePolicy.setHorizontalStretch(0);
            sizePolicy.setVerticalStretch(0);
            sizePolicy.setHeightForWidth(sr35d_StatusLabel->sizePolicy().hasHeightForWidth());
            sr35d_StatusLabel->setSizePolicy(sizePolicy);
            sr35d_StatusLabel->setLayoutDirection(Qt::RightToLeft);
            sr35d_StatusLabel->setAlignment(Qt::AlignCenter);
            sr35d_StatusLabel->setText(QString::number(i+1));

            QSpinBox *sr35d_Timer = new QSpinBox(ui->sr35d_DinParams);
            sr35d_Timer->setObjectName(QString::fromUtf8("sr35d_Timer")+QString::number(i));
            sr35d_Timer->setGeometry(QRect(5+45*i, 41, 40, 22));
            sr35d_Timer->setMaximum(99);
            sr35d_Timer->setAlignment(Qt::AlignmentFlag::AlignRight);
            sr35d_TimerList.append(sr35d_Timer);

            QLabel *sr35d_TimerLabel = new QLabel(ui->sr35d_DinParams);
            sr35d_TimerLabel->setObjectName(QString::fromUtf8("sr35d_TimerLabel")+QString::number(i));
            sr35d_TimerLabel->setGeometry(QRect(16+45*i, 28, 15, 15));
            QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
            sizePolicy1.setHorizontalStretch(0);
            sizePolicy1.setVerticalStretch(0);
            sizePolicy1.setHeightForWidth(sr35d_TimerLabel->sizePolicy().hasHeightForWidth());
            sr35d_TimerLabel->setSizePolicy(sizePolicy1);
            sr35d_TimerLabel->setLayoutDirection(Qt::RightToLeft);
            sr35d_TimerLabel->setAlignment(Qt::AlignCenter);
            sr35d_TimerLabel->setText(QString::number(i+1));
        }

        ui->sr35d_Params->setEnabled(false);
        connect(ui->sr35d_Write, SIGNAL(clicked()), this, SLOT(onWriteButton_Click()));
        connect(ui->sr35dModuleN, SIGNAL(valueChanged(int)), this, SLOT(onModuleN_Changed(int)));
        sr35d_DisconnectedDataSet();
    }
    //US-RS485 region
    {
        ui->usrs485_Params->setEnabled(false);
        connect(ui->usrs485_Write, SIGNAL(clicked()), this, SLOT(onWriteButton_Click()));
        connect(ui->usrs485ModuleN, SIGNAL(valueChanged(int)), this, SLOT(onModuleN_Changed(int)));
        firstReq_usrs485 = true;
        voltReq_usrs485 = false;
        usrs485_DisconnectedDataSet();
    }
    //STR-35D region
    {
        //STR-35D
        str35d_TempList.append(ui->__rs485_Temp_1);
        str35d_TempList.append(ui->__rs485_Temp_2);
        str35d_TempList.append(ui->__rs485_Temp_3);
        str35d_TempList.append(ui->__rs485_Temp_4);
        str35d_TempList.append(ui->__rs485_Temp_5);
        str35d_TempList.append(ui->__rs485_Temp_6);
        str35d_TempList.append(ui->__rs485_Temp_7);
        str35d_TempList.append(ui->__rs485_Temp_8);

        str35d_HumList.append(ui->__rs485_Hum_1);
        str35d_HumList.append(ui->__rs485_Hum_2);
        str35d_HumList.append(ui->__rs485_Hum_3);
        str35d_HumList.append(ui->__rs485_Hum_4);
        str35d_HumList.append(ui->__rs485_Hum_5);
        str35d_HumList.append(ui->__rs485_Hum_6);
        str35d_HumList.append(ui->__rs485_Hum_7);
        str35d_HumList.append(ui->__rs485_Hum_8);

        str35d_DewList.append(ui->__rs485_Dew_1);
        str35d_DewList.append(ui->__rs485_Dew_2);
        str35d_DewList.append(ui->__rs485_Dew_3);
        str35d_DewList.append(ui->__rs485_Dew_4);
        str35d_DewList.append(ui->__rs485_Dew_5);
        str35d_DewList.append(ui->__rs485_Dew_6);
        str35d_DewList.append(ui->__rs485_Dew_7);
        str35d_DewList.append(ui->__rs485_Dew_8);

        str35d_PressList.append(ui->__rs485_Press_1);
        str35d_PressList.append(ui->__rs485_Press_2);
        str35d_PressList.append(ui->__rs485_Press_3);
        str35d_PressList.append(ui->__rs485_Press_4);
        str35d_PressList.append(ui->__rs485_Press_5);
        str35d_PressList.append(ui->__rs485_Press_6);
        str35d_PressList.append(ui->__rs485_Press_7);
        str35d_PressList.append(ui->__rs485_Press_8);

        str35d_CO2List.append(ui->__rs485_CO2_1);
        str35d_CO2List.append(ui->__rs485_CO2_2);
        str35d_CO2List.append(ui->__rs485_CO2_3);
        str35d_CO2List.append(ui->__rs485_CO2_4);
        str35d_CO2List.append(ui->__rs485_CO2_5);
        str35d_CO2List.append(ui->__rs485_CO2_6);
        str35d_CO2List.append(ui->__rs485_CO2_7);
        str35d_CO2List.append(ui->__rs485_CO2_8);
        for (int ts = 0; ts < 8; ts++)
        {
            str35dtempstatus[ts] = 0;
            str35dhumstatus[ts] = 0;
            str35dpressurestatus[ts] = 0;
            str35dco2status[ts] = 0;
        }
        ui->str35d_Params->setEnabled(false);
        connect(ui->str35d_Write, SIGNAL(clicked()), this, SLOT(onWriteButton_Click()));
        connect(ui->str35dModuleN, SIGNAL(valueChanged(int)), this, SLOT(onModuleN_Changed(int)));
        firstReq_str35d = true;
        secondReq_str35d = false;
        str35d_DisconnectedDataSet();
    }
    //CS-RS485 region
    {
        ui->csrs485_Params->setEnabled(false);
        connect(ui->csrs485_Write, SIGNAL(clicked()), this, SLOT(onWriteButton_Click()));
        connect(ui->csrs485ModuleN, SIGNAL(valueChanged(int)), this, SLOT(onModuleN_Changed(int)));
        csrs485_DisconnectedDataSet();
    }
    //VC-RS485 region
    {
        ui->vcrs485_Params->setEnabled(false);
        connect(ui->vcrs485_Write, SIGNAL(clicked()), this, SLOT(onWriteButton_Click()));
        connect(ui->vcrs485ModuleN, SIGNAL(valueChanged(int)), this, SLOT(onModuleN_Changed(int)));
        vcrs485_DisconnectedDataSet();
    }
    //ASC-35D region
    {
        for (int cl = 0; cl < 4; cl++)
        {
            asc35d_status_cloop[cl] = 0x0;
            asc35d_template_cloop[cl] = 0x0;
        }
        for (int cl = 0; cl < 2; cl++)
        {
            asc35d_template_an[cl] = 0x0;
        }
        ui->asc35d_Params->setEnabled(false);
        connect(ui->asc35d_Write, SIGNAL(clicked()), this, SLOT(onWriteButton_Click()));
        connect(ui->asc35dModuleN, SIGNAL(valueChanged(int)), this, SLOT(onModuleN_Changed(int)));
        asc35d_DisconnectedDataSet();
    }
    //SVA-35D region
    {
        ui->sva35dData->setColumnWidth(0, 200);
        ui->sva35dData->setColumnWidth(1, 55);
        ui->sva35dData->setColumnWidth(2, 115);
        ui->sva35dData->setSelectionMode(QAbstractItemView::SelectionMode::NoSelection);
        for(int n=0;n<ui->sva35dData->rowCount();n++)
        {
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setText("");
            item->setTextAlignment(Qt::AlignRight);
            ui->sva35dData->setItem(n, 2, item);
        }
        QFont f = ui->sva35dData->font();
        f.setPixelSize(f.pixelSize()*0.95);
        ui->sva35dData->setFont(f);
        ui->sva35d_Params->setEnabled(false);
        connect(ui->sva35d_Write, SIGNAL(clicked()), this, SLOT(onWriteButton_Click()));
        connect(ui->sva35dModuleN, SIGNAL(valueChanged(int)), this, SLOT(onModuleN_Changed(int)));
        sva35d_DisconnectedDataSet();
    }
    //SPC-35D region
    {
        ui->spc35dData->setColumnWidth(0, 200);
        ui->spc35dData->setColumnWidth(1, 65);
        ui->spc35dData->setColumnWidth(2, 105);
        ui->spc35dData->setSelectionMode(QAbstractItemView::SelectionMode::NoSelection);
        for(int n=0;n<ui->spc35dData->rowCount();n++)
        {
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setText("");
            item->setTextAlignment(Qt::AlignRight);
            ui->spc35dData->setItem(n, 2, item);
        }
        QFont f = ui->spc35dData->font();
        f.setPixelSize(f.pixelSize()*0.95);
        ui->spc35dData->setFont(f);
        ui->spc35d_Params->setEnabled(false);
        connect(ui->spc35d_Write, SIGNAL(clicked()), this, SLOT(onWriteButton_Click()));
        connect(ui->spc35dModuleN, SIGNAL(valueChanged(int)), this, SLOT(onModuleN_Changed(int)));
        firstReq_spc35d = true;
        spc35d_DisconnectedDataSet();
    }
    ui->moduleConnectStatus->setText(ConstStings::disconnected);
    QPalette palette = ui->moduleConnectStatus->palette();
    palette.setColor(QPalette::WindowText, Qt::red);
    ui->moduleConnectStatus->setPalette(palette);

    ModuleConnected = false;
    ui->moduleSN->setText(ConstStings::noSN);

    ModuleType = ui->tabWidget->currentIndex();
    ModuleAddress = 0;
    passConnErr = 0;
    tabWasChanged = false;
    //Set poll timer
    {
        pollTimer = new QTimer(this);
        connect(pollTimer, SIGNAL(timeout()), this, SLOT(pollTimerTimeout()));
        pollTimer->start(350);
        pollRequestFlag = false;
    }
}

MainWindow::~MainWindow()
{
    comP.PortCloseRequest(false);
    QThread::sleep(1);
    delete ui;
}


void MainWindow::checkboxStatusColorSet(QCheckBox *cb, QColor color)
{
    QPalette p = cb->palette( );
    p.setColor( QPalette::All, QPalette::Base, color );
    p.setColor( QPalette::All, QPalette::Button, color );
    cb->setPalette( p );
}



void MainWindow::pollTimerTimeout()
{
    bool connect=false;

    if(pollRequestFlag == true)
        return;

    //check new frame
    portFrame frame = comP.queue.DequeueRxFrame();
    if(frame.TransmitStatus == TrmtStatus_EventSuccess && tabWasChanged == false)
    {
        if(frame.Function == Function_Read)
        {
           if(ModuleAddress == frame.ComAddress)
           {
                switch(ModuleType)
                {
                    case ModuleTypes_SK35D:
                    {
                        int i = 0;
                        while (i < frame.length)
                        {
                            switch ((uint8_t)frame.data.at(i))
                            {
                                case 0x40: //Текущее состояние входов
                                {
                                    i++;
                                    if ((i + 1) < frame.length)
                                    {
                                        for(int k=0;k<sk35d_StatusList.length();k++)
                                        {
                                            if(((uint8_t)frame.data.at(i+((sk35d_StatusList.length()-1-k)/8)))&(1<<(k%8)))
                                            {
                                                checkboxStatusColorSet(sk35d_StatusList.at(k), Qt::red);
                                            }
                                            else
                                            {
                                                checkboxStatusColorSet(sk35d_StatusList.at(k), Qt::green);
                                            }
                                        }
                                        connect = true;
                                    }
                                    else connect = false;
                                    i+=2;
                                    break;
                                }
                                case 0x80: //Настройка типа таймера
                                {
                                    i++;
                                    if ((i + 1) < frame.length)
                                    {
                                        if (ui->sk35d_ParamsEnable->isChecked() == false)
                                        {
                                            for(int k=0;k<sk35d_TypeList.length();k++)
                                            {
                                                if(((uint8_t)frame.data.at(i+(sk35d_TypeList.length()-1-k)/8))&(1<<(k%8)))
                                                {
                                                    sk35d_TypeList.at(k)->setChecked(true);
                                                }
                                                else
                                                {
                                                    sk35d_TypeList.at(k)->setChecked(false);
                                                }
                                            }
                                        }
                                        connect = true;
                                    }
                                    else connect = false;
                                    i+=2;
                                    break;
                                }
                                case 0x81:	//Таймер
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if (ui->sk35d_ParamsEnable->isChecked() == false)
                                        {
                                            ui->sk35d_Timer->setValue((uint8_t)frame.data.at(i));
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0xA0: //Адрес
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if (ui->sk35d_ParamsEnable->isChecked() == false)
                                        {
                                            ui->sk35d_AddrDEC->setValue((uint8_t)frame.data.at(i));
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA1:	//Скорость
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if (ui->sk35d_ParamsEnable->isChecked() == false)
                                        {
                                            ui->sk35d_BaudRate->setCurrentIndex((int)frame.data.at(i));
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA2:	//Протокол
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if  (ui->sk35d_ParamsEnable->isChecked() == false)
                                        {
                                            if ((uint8_t)frame.data.at(i) == 0xf0)
                                                ui->sk35d_ModbusEn->setChecked(true);
                                            else
                                                ui->sk35d_ModbusEn->setChecked(false);
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA3:	//Бит четности
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if  (ui->sk35d_ParamsEnable->isChecked() == false)
                                        {
                                            if((uint8_t)frame.data.at(i) == 0xf0)
                                                ui->sk35d_Parity->setCurrentIndex(2);
                                            else if ((uint8_t)frame.data.at(i) == 0x0f)
                                                ui->sk35d_Parity->setCurrentIndex(1);
                                            else
                                                ui->sk35d_Parity->setCurrentIndex(0);
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA8:
                                {
                                    i++;
                                    int k=i;
                                    while (k<frame.length && (uint8_t)frame.data.at(k) != 0x0)
                                        k++;
                                    if (k < frame.length)
                                    {
                                        QByteArray sn;
                                        for (int n=0;n<k-i;n++)
                                        {
                                            sn.append(frame.data.at(i+n));
                                        }
                                        ui->moduleSN->setText(sn);
                                        i =k+1;
                                        while (i<frame.length && (uint8_t)frame.data.at(i) == 0x0)
                                            i++;
                                        connect = true;
                                    }
                                    else { ui->moduleSN->setText(ConstStings::noSN); connect = false; }
                                    break;
                                }
                                case 0x88:
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if  (ui->sk35d_ParamsEnable->isChecked() == false)
                                        {
                                            if ((uint8_t)frame.data.at(i) == 0xf0)
                                                ui->sk35d_Relay1->setCurrentIndex(1);
                                            else
                                                ui->sk35d_Relay1->setCurrentIndex(0);
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0x89:
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if  (ui->sk35d_ParamsEnable->isChecked() == false)
                                        {
                                            if ((uint8_t)frame.data.at(i) == 0xf0)
                                                ui->sk35d_Relay1Save->setChecked(true);
                                            else
                                                ui->sk35d_Relay1Save->setChecked(false);
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0x8A:
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if  (ui->sk35d_ParamsEnable->isChecked() == false)
                                        {
                                            if ((uint8_t)frame.data.at(i) == 0xf0)
                                                ui->sk35d_Relay2->setCurrentIndex(1);
                                            else
                                                ui->sk35d_Relay2->setCurrentIndex(0);
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0x8B:
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if  (ui->sk35d_ParamsEnable->isChecked() == false)
                                        {
                                            if ((uint8_t)frame.data.at(i) == 0xf0)
                                                ui->sk35d_Relay2Save->setChecked(true);
                                            else
                                                ui->sk35d_Relay2Save->setChecked(false);
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                default:
                                {
                                    i++; connect = false; break;
                                }
                            }
                            if(connect == false)
                                break;
                        }
                        break;
                    }
                    case ModuleTypes_SVC35D:
                    {
                        int i = 0;
                        while (i < frame.length)
                        {
                            switch ((uint8_t)frame.data.at(i))
                            {
                                case 0x40: //Текущее состояние входов
                                {
                                    i++;
                                    if ((i + 1) < frame.length)
                                    {
                                        for(int k=0;k<svc35d_StatusList.length();k++)
                                        {
                                            if(((uint8_t)frame.data.at(i+(svc35d_StatusList.length()-1-k)/8))&(1<<(k%8)))
                                            {
                                                checkboxStatusColorSet(svc35d_StatusList.at(k), Qt::blue);
                                            }
                                            else
                                            {
                                                checkboxStatusColorSet(svc35d_StatusList.at(k), Qt::yellow);
                                            }
                                        }
                                        connect = true;
                                    }
                                    else connect = false;
                                    i+=2;
                                    break;
                                }
                                case 0x80: //Настройка типа таймера
                                {
                                    i++;
                                    if ((i + 1) < frame.length)
                                    {
                                        if (ui->svc35d_ParamsEnable->isChecked() == false)
                                        {
                                            for(int k=0;k<svc35d_TypeList.length();k++)
                                            {
                                                if(((uint8_t)frame.data.at(i+((svc35d_TypeList.length()-1-k)/8)))&(1<<(k%8)))
                                                {
                                                    svc35d_TypeList.at(k)->setChecked(true);
                                                }
                                                else
                                                {
                                                    svc35d_TypeList.at(k)->setChecked(false);
                                                }
                                            }
                                        }
                                        connect = true;
                                    }
                                    else connect = false;
                                    i+=2;
                                    break;
                                }
                                case 0x81:	//Таймер
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if (ui->svc35d_ParamsEnable->isChecked() == false)
                                        {
                                            ui->svc35d_Timer->setValue((uint8_t)frame.data.at(i));
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0xA0: //Адрес
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if (ui->svc35d_ParamsEnable->isChecked() == false)
                                        {
                                            ui->svc35d_AddrDEC->setValue((uint8_t)frame.data.at(i));
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA1:	//Скорость
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if (ui->svc35d_ParamsEnable->isChecked() == false)
                                        {
                                            ui->svc35d_BaudRate->setCurrentIndex((int)frame.data.at(i));
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA2:	//Протокол
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if  (ui->svc35d_ParamsEnable->isChecked() == false)
                                        {
                                            if ((uint8_t)frame.data.at(i) == 0xf0)
                                                ui->svc35d_ModbusEn->setChecked(true);
                                            else
                                                ui->svc35d_ModbusEn->setChecked(false);
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA3:	//Бит четности
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if  (ui->svc35d_ParamsEnable->isChecked() == false)
                                        {
                                            if((uint8_t)frame.data.at(i) == 0xf0)
                                                ui->svc35d_Parity->setCurrentIndex(2);
                                            else if ((uint8_t)frame.data.at(i) == 0x0f)
                                                ui->svc35d_Parity->setCurrentIndex(1);
                                            else
                                                ui->svc35d_Parity->setCurrentIndex(0);
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA8:
                                {
                                    i++;
                                    int k=i;
                                    while (k<frame.length && (uint8_t)frame.data.at(k) != 0x0)
                                        k++;
                                    if (k < frame.length)
                                    {
                                        QByteArray sn;
                                        for (int n=0;n<k-i;n++)
                                        {
                                            sn.append(frame.data.at(i+n));
                                        }
                                        ui->moduleSN->setText(sn);
                                        i =k+1;
                                        while (i<frame.length && (uint8_t)frame.data.at(i) == 0x0)
                                            i++;
                                        connect = true;
                                    }
                                    else { ui->moduleSN->setText(ConstStings::noSN); connect = false; }
                                    break;
                                }
                                case 0x88:
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if  (ui->svc35d_ParamsEnable->isChecked() == false)
                                        {
                                            if ((uint8_t)frame.data.at(i) == 0xf0)
                                                ui->svc35d_Relay1->setCurrentIndex(1);
                                            else
                                                ui->svc35d_Relay1->setCurrentIndex(0);
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0x89:
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if  (ui->svc35d_ParamsEnable->isChecked() == false)
                                        {
                                            if ((uint8_t)frame.data.at(i) == 0xf0)
                                                ui->svc35d_Relay1Save->setChecked(true);
                                            else
                                                ui->svc35d_Relay1Save->setChecked(false);
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                default:
                                {
                                    i++; connect = false; break;
                                }
                            }
                            if(connect == false)
                                break;
                        }
                        break;
                    }
                    case ModuleTypes_SR35D:
                    {
                        int i = 0;
                        while (i < frame.length)
                        {
                            switch ((uint8_t)frame.data.at(i))
                            {
                                case 0x40: //Текущее состояние входов
                                    i+=2;
                                    if ((i + 1) < frame.length)
                                    {
                                        for(int k=0;k<sr35d_StatusList.length();k++)
                                        {
                                            if(((uint8_t)frame.data.at(i))&(1<<k))
                                            {
                                                checkboxStatusColorSet(sr35d_StatusList.at(k), Qt::red);
                                            }
                                            else
                                            {
                                                checkboxStatusColorSet(sr35d_StatusList.at(k), Qt::green);
                                            }
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;

                                case 0x80: //Настройка тип а выходов
                                    i+=2;
                                    if ((i + 1) < frame.length)
                                    {
                                        if  (ui->sr35d_ParamsEnable->isChecked() == false)
                                        {
                                            for(int k=0;k<sr35d_TypeList.length();k++)
                                            {
                                                if(((uint8_t)frame.data.at(i)&(1<<k)))
                                                {
                                                    sr35d_TypeList.at(k)->setChecked(true);
                                                }
                                                else
                                                {
                                                    sr35d_TypeList.at(k)->setChecked(false);
                                                }
                                            }
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;

                                case 0x81:	//Таймеры
                                case 0x82:
                                case 0x83:
                                case 0x84:
                                case 0x85:
                                case 0x86:
                                case 0x87:
                                case 0x88:
                                {
                                    uint8_t raddr = frame.data.at(i)-0x81;
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if (ui->sr35d_ParamsEnable->isChecked() == false)
                                        {
                                            sr35d_TimerList.at(raddr)->setValue((uint8_t)frame.data.at(i));
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA0: //Адрес
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if (ui->sr35d_ParamsEnable->isChecked() == false)
                                        {
                                            ui->sr35d_AddrDEC->setValue((uint8_t)frame.data.at(i));
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;

                                case 0xA1:	//Скорость
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if (ui->sr35d_ParamsEnable->isChecked() == false)
                                        {
                                            ui->sr35d_BaudRate->setCurrentIndex((int)frame.data.at(i));
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA2:	//Протокол
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if  (ui->sr35d_ParamsEnable->isChecked() == false)
                                        {
                                            if ((uint8_t)frame.data.at(i) == 0xf0)
                                                ui->sr35d_ModbusEn->setChecked(true);
                                            else
                                                ui->sr35d_ModbusEn->setChecked(false);
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA3:	//Бит четности
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if  (ui->sr35d_ParamsEnable->isChecked() == false)
                                        {
                                            if((uint8_t)frame.data.at(i) == 0xf0)
                                                ui->sr35d_Parity->setCurrentIndex(2);
                                            else if ((uint8_t)frame.data.at(i) == 0x0f)
                                                ui->sr35d_Parity->setCurrentIndex(1);
                                            else
                                                ui->sr35d_Parity->setCurrentIndex(0);
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA8:
                                {
                                    i++;
                                    int k=i;
                                    while (k<frame.length && (uint8_t)frame.data.at(k) != 0x0)
                                        k++;
                                    if (k < frame.length)
                                    {
                                        QByteArray sn;
                                        for (int n=0;n<k-i;n++)
                                        {
                                            sn.append(frame.data.at(i+n));
                                        }
                                        ui->moduleSN->setText(sn);
                                        i =k+1;
                                        while (i<frame.length && (uint8_t)frame.data.at(i) == 0x0)
                                            i++;
                                        connect = true;
                                    }
                                    else { ui->moduleSN->setText(ConstStings::noSN); connect = false; }
                                    break;
                                }

                                case 0x89:
                                case 0x8C:
                                case 0x8F:
                                case 0x92:
                                case 0x95:
                                case 0x98:
                                    {
                                        uint8_t raddr = ((uint8_t)frame.data.at(i)-0x89)/3;
                                        i += 2;
                                        if (i < frame.length)
                                        {
                                            if(ui->sr35d_ParamsEnable->isChecked() == false)
                                            {
                                                if ((uint8_t)frame.data.at(i) == 0xf0)
                                                    sr35d_RelayList.at(raddr)->setCurrentIndex(1);
                                                else
                                                    sr35d_RelayList.at(raddr)->setCurrentIndex(0);
                                                break;
                                            }
                                            i++;
                                            connect = true;
                                        }
                                        else connect = false;
                                        break;
                                    }
                                case 0x8A:
                                case 0x8D:
                                case 0x90:
                                case 0x93:
                                case 0x96:
                                case 0x99:
                                    {
                                        uint8_t raddr = ((uint8_t)frame.data.at(i)-0x8A)/3;
                                        i += 2;
                                        if (i < frame.length)
                                        {
                                            if(ui->sr35d_ParamsEnable->isChecked() == false)
                                            {
                                                if ((uint8_t)frame.data.at(i) == 0xf0)
                                                    sr35d_RelaySaveList.at(raddr)->setCheckState(Qt::CheckState::Checked);
                                                else
                                                    sr35d_RelaySaveList.at(raddr)->setCheckState(Qt::CheckState::Unchecked);
                                                break;
                                            }
                                            i++;
                                            connect = true;
                                        }
                                        else connect = false;
                                        break;
                                    }
                                default: i++; break;
                            }
                            if(connect == false)
                                break;
                        }
                        break;
                    }
                    case ModuleTypes_USRS485:
                    {
                        bool btempstatus = false;
                        bool bhumstatus = false;
                        bool bpressurestatus = false;
                        char tempStatus = 0;
                        char humStatus = 0;
                        char pressureStatus = 0;


                        int i = 0;
                        while (i < frame.length)
                        {
                            switch ((uint8_t)frame.data.at(i))
                            {
                                case 0x40:
                                    btempstatus = true;
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        tempStatus = frame.data.at(i);
                                        i++;
                                        connect = true;
                                    }
                                    else
                                        connect = false;
                                    break;

                                case 0x41:
                                    i++;
                                    if ((i + 1) < frame.length)
                                    {
                                        int itemp;
                                        itemp = (int)((int16_t)((uint16_t)((uint8_t)frame.data.at(i))*256+(uint8_t)frame.data.at(i+1)));
                                        QString temp;
                                        temp= QString::number(itemp);
                                        if (temp.length() < 2 && temp.at(0) != '-')
                                            temp = temp.insert(0, "0,");
                                        else if (temp.length() < 3 && temp[0] == '-')
                                            temp = temp.insert(1, "0,");
                                        else temp = temp.insert(temp.length() - 1, ",");
                                        ui->usrs485_Temp->setText(temp);
                                        i += 2;
                                        connect = true;
                                    }
                                    else
                                        connect = false;
                                    break;

                                case 0x42:
                                    bhumstatus = true;
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        humStatus = frame.data.at(i);
                                        i++;
                                        connect = true;
                                    }
                                    else
                                        connect = false;
                                    break;

                                case 0x43:
                                    i++;
                                    if ((i + 1) < frame.length)
                                    {
                                        int itemp;
                                        itemp = (int)((int16_t)((uint16_t)((uint8_t)frame.data.at(i))*256+(uint8_t)frame.data.at(i+1)));
                                        QString temp;
                                        temp= QString::number(itemp);
                                        if (temp.length() < 2 && temp.at(0) != '-')
                                            temp = temp.insert(0, "0,");
                                        else if (temp.length() < 3 && temp[0] == '-')
                                            temp = temp.insert(1, "0,");
                                        else temp = temp.insert(temp.length() - 1, ",");
                                        ui->usrs485_Hum->setText(temp);
                                        i += 2;
                                        connect = true;
                                    }
                                    else
                                        connect = false;
                                    break;

                                case 0x44:
                                    i++;
                                    if ((i + 1) < frame.length)
                                    {
                                        int itemp;
                                        itemp = (int)((int16_t)((uint16_t)((uint8_t)frame.data.at(i))*256+(uint8_t)frame.data.at(i+1)));
                                        QString temp;
                                        temp= QString::number(itemp);
                                        if (temp.length() < 2 && temp.at(0) != '-')
                                            temp = temp.insert(0, "0,");
                                        else if (temp.length() < 3 && temp[0] == '-')
                                            temp = temp.insert(1, "0,");
                                        else temp = temp.insert(temp.length() - 1, ",");
                                        ui->usrs485_Dew->setText(temp);
                                        i += 2;
                                        connect = true;
                                    }
                                    else
                                        connect = false;
                                    break;

                                case 0x45:
                                    bpressurestatus = true;
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        pressureStatus = frame.data.at(i);
                                        i++;
                                        connect = true;
                                    }
                                    else
                                        connect = false;
                                    break;

                                case 0x46:
                                    i++;
                                    if ((i + 1) < frame.length)
                                    {
                                        int itemp;
                                        itemp = (int)((int16_t)((uint16_t)((uint8_t)frame.data.at(i))*256+(uint8_t)frame.data.at(i+1)));
                                        QString temp;
                                        temp= QString::number(itemp);
                                        if (temp.length() < 2 && temp.at(0) != '-')
                                            temp = temp.insert(0, "0,");
                                        else if (temp.length() < 3 && temp[0] == '-')
                                            temp = temp.insert(1, "0,");
                                        else temp = temp.insert(temp.length() - 1, ",");
                                        ui->usrs485_Press->setText(temp);
                                        i += 2;
                                        connect = true;
                                    }
                                    else
                                        connect = false;
                                    break;

                                case 0xA0: //Адрес
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if (ui->usrs485_ParamsEnable->isChecked() == false)
                                        {
                                            ui->usrs485_AddrDEC->setValue((uint8_t)frame.data.at(i));
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA1:	//Скорость
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if (ui->usrs485_ParamsEnable->isChecked() == false)
                                        {
                                            ui->usrs485_BaudRate->setCurrentIndex((int)frame.data.at(i));
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA2:	//Протокол
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if  (ui->usrs485_ParamsEnable->isChecked() == false)
                                        {
                                            if ((uint8_t)frame.data.at(i) == 0xf0)
                                                ui->usrs485_ModbusEn->setChecked(true);
                                            else
                                                ui->usrs485_ModbusEn->setChecked(false);
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA3:	//Бит четности
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if  (ui->usrs485_ParamsEnable->isChecked() == false)
                                        {
                                            if((uint8_t)frame.data.at(i) == 0xf0)
                                                ui->usrs485_Parity->setCurrentIndex(2);
                                            else if ((uint8_t)frame.data.at(i) == 0x0f)
                                                ui->usrs485_Parity->setCurrentIndex(1);
                                            else
                                                ui->usrs485_Parity->setCurrentIndex(0);
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0xA8:
                                {
                                    i++;
                                    int k=i;
                                    while (k<frame.length && (uint8_t)frame.data.at(k) != 0x0)
                                        k++;
                                    if (k < frame.length)
                                    {
                                        QByteArray sn;
                                        for (int n=0;n<k-i;n++)
                                        {
                                            sn.append(frame.data.at(i+n));
                                        }
                                        ui->moduleSN->setText(sn);
                                        i =k+1;
                                        while (i<frame.length && (uint8_t)frame.data.at(i) == 0x0)
                                            i++;
                                        connect = true;
                                    }
                                    else { ui->moduleSN->setText(ConstStings::noSN); connect = false; }
                                    break;
                                }
                                case 0x4f:
                                    i++;
                                    if ((i + 1) < frame.length)
                                    {
                                        int itemp;
                                        itemp = (int)((int16_t)((uint16_t)((uint8_t)frame.data.at(i))*256+(uint8_t)frame.data.at(i+1)));
                                        QString temp;
                                        temp= QString::number(itemp);
                                        ui->usrs485_Volt->setText(temp);
                                        i += 2;
                                    }
                                    connect = true;
                                    break;
                                default:
                                {
                                    i++; connect = false; break;
                                }
                            }
                            if(connect == false)
                                break;
                        }
                        if (tempStatus == 0 && btempstatus == true)
                        {
                            ui->usrs485_Temp->setText("");
                        }
                        if (humStatus == 0 && bhumstatus == true)
                        {
                            ui->usrs485_Hum->setText("");
                            ui->usrs485_Dew->setText("");
                        }
                        if (pressureStatus == 0 && bpressurestatus == true)
                        {
                            ui->usrs485_Press->setText("");
                        }
                        break;
                    }
                    case ModuleTypes_CSRS485:
                    {
                        bool bco2status = false;
                        char co2Status = 0;

                        int i = 0;
                        while (i < frame.length)
                        {
                            switch ((uint8_t)frame.data.at(i))
                            {
                                case 0x50:
                                    bco2status = true;
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        co2Status = frame.data.at(i);
                                        i++;
                                        connect = true;
                                    }
                                    else
                                        connect = false;
                                    break;

                                case 0x51:
                                    i++;
                                    if ((i + 1) < frame.length)
                                    {
                                        int itemp;
                                        itemp = (int)((int16_t)((uint16_t)((uint8_t)frame.data.at(i))*256+(uint8_t)frame.data.at(i+1)));
                                        QString temp;
                                        temp= QString::number(itemp);
                                        ui->csrs485_CO2->setText(temp);
                                        i += 2;
                                        connect = true;
                                    }
                                    else
                                        connect = false;
                                    break;

                                case 0xA0: //Адрес
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if (ui->csrs485_ParamsEnable->isChecked() == false)
                                        {
                                            ui->csrs485_AddrDEC->setValue((uint8_t)frame.data.at(i));
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA1:	//Скорость
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if (ui->csrs485_ParamsEnable->isChecked() == false)
                                        {
                                            ui->csrs485_BaudRate->setCurrentIndex((int)frame.data.at(i));
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA2:	//Протокол
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if  (ui->csrs485_ParamsEnable->isChecked() == false)
                                        {
                                            if ((uint8_t)frame.data.at(i) == 0xf0)
                                                ui->csrs485_ModbusEn->setChecked(true);
                                            else
                                                ui->csrs485_ModbusEn->setChecked(false);
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA3:	//Бит четности
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if  (ui->csrs485_ParamsEnable->isChecked() == false)
                                        {
                                            if((uint8_t)frame.data.at(i) == 0xf0)
                                                ui->csrs485_Parity->setCurrentIndex(2);
                                            else if ((uint8_t)frame.data.at(i) == 0x0f)
                                                ui->csrs485_Parity->setCurrentIndex(1);
                                            else
                                                ui->csrs485_Parity->setCurrentIndex(0);
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0xA8:
                                {
                                    i++;
                                    int k=i;
                                    while (k<frame.length && (uint8_t)frame.data.at(k) != 0x0)
                                        k++;
                                    if (k < frame.length)
                                    {
                                        QByteArray sn;
                                        for (int n=0;n<k-i;n++)
                                        {
                                            sn.append(frame.data.at(i+n));
                                        }
                                        ui->moduleSN->setText(sn);
                                        i =k+1;
                                        while (i<frame.length && (uint8_t)frame.data.at(i) == 0x0)
                                            i++;
                                        connect = true;
                                    }
                                    else { ui->moduleSN->setText(ConstStings::noSN); connect = false; }
                                    break;
                                }
                                default:
                                {
                                    i++; connect = false; break;
                                }
                            }
                            if(connect == false)
                                break;
                        }
                        if(bco2status == true)
                        {
                            if (co2Status != 1 && co2Status != 2)
                            {
                                ui->csrs485_CO2->setText("");
                                ui->csrs485_Heat->setVisible(false);
                            }
                            else if (co2Status == 2)
                            {
                                ui->csrs485_Heat->setVisible(true);
                                QFont f=ui->csrs485_Heat->font();
                                f.setWeight(QFont::Bold);
                                ui->csrs485_Heat->setFont(f);
                                break;
                            }
                            else
                            {
                                ui->csrs485_Heat->setVisible(false);
                            }

                        }
                        break;
                    }
                    case ModuleTypes_STR35D:
                    {
                        for (int ts = 0; ts < 8; ts++)
                        {
                            str35dtempstatus[ts] = 0;
                            str35dhumstatus[ts] = 0;
                            str35dpressurestatus[ts] = 0;
                            str35dco2status[ts] = 0;
                        }
                        int i = 0;
                        while (i < frame.length)
                        {
                            switch ((uint8_t)frame.data.at(i))
                            {
                                case 0x40:
                                case 0x47:
                                case 0x4E:
                                case 0x55:
                                case 0x5C:
                                case 0x63:
                                case 0x6A:
                                case 0x71:
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        str35dtempstatus[((uint8_t)frame.data.at(i - 2) - 0x40) / 7] = frame.data.at(i);
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;

                                case 0x41:
                                case 0x48:
                                case 0x4F:
                                case 0x56:
                                case 0x5D:
                                case 0x64:
                                case 0x6B:
                                case 0x72:
                                {
                                    int raddr = ((uint8_t)frame.data.at(i) - 0x41) / 7;
                                    i++;
                                    if ((i + 1) < frame.length)
                                    {
                                        int itemp;
                                        itemp = (int)((int16_t)((uint16_t)((uint8_t)frame.data.at(i))*256+(uint8_t)frame.data.at(i+1)));
                                        QString temp;
                                        temp= QString::number(itemp);
                                        if (temp.length() < 2 && temp.at(0) != '-')
                                            temp = temp.insert(0, "0,");
                                        else if (temp.length() < 3 && temp[0] == '-')
                                            temp = temp.insert(1, "0,");
                                        else temp = temp.insert(temp.length() - 1, ",");
                                        str35d_TempList.at(raddr)->setText(temp);
                                        i += 2;
                                        connect = true;
                                    }
                                    else
                                        connect = false;
                                    break;
                                }
                                case 0x42:
                                case 0x49:
                                case 0x50:
                                case 0x57:
                                case 0x5E:
                                case 0x65:
                                case 0x6C:
                                case 0x73:
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        str35dhumstatus[((uint8_t)frame.data.at(i - 2) - 0x42) / 7] = frame.data.at(i);
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;

                                case 0x43:
                                case 0x4A:
                                case 0x51:
                                case 0x58:
                                case 0x5F:
                                case 0x66:
                                case 0x6D:
                                case 0x74:
                                {
                                    int raddr = ((uint8_t)frame.data.at(i) - 0x43) / 7;
                                    i++;
                                    if ((i + 1) < frame.length)
                                    {
                                        int itemp;
                                        itemp = (int)((int16_t)((uint16_t)((uint8_t)frame.data.at(i))*256+(uint8_t)frame.data.at(i+1)));
                                        QString temp;
                                        temp= QString::number(itemp);
                                        if (temp.length() < 2 && temp.at(0) != '-')
                                            temp = temp.insert(0, "0,");
                                        else if (temp.length() < 3 && temp[0] == '-')
                                            temp = temp.insert(1, "0,");
                                        else temp = temp.insert(temp.length() - 1, ",");
                                        str35d_HumList.at(raddr)->setText(temp);
                                        i += 2;
                                        connect = true;
                                    }
                                    else
                                        connect = false;
                                    break;
                                }
                                case 0x44:
                                case 0x4B:
                                case 0x52:
                                case 0x59:
                                case 0x60:
                                case 0x67:
                                case 0x6E:
                                case 0x75:
                                {
                                    int raddr = ((uint8_t)frame.data.at(i) - 0x44) / 7;
                                    i++;
                                    if ((i + 1) < frame.length)
                                    {
                                        int itemp;
                                        itemp = (int)((int16_t)((uint16_t)((uint8_t)frame.data.at(i))*256+(uint8_t)frame.data.at(i+1)));
                                        QString temp;
                                        temp= QString::number(itemp);
                                        if (temp.length() < 2 && temp.at(0) != '-')
                                            temp = temp.insert(0, "0,");
                                        else if (temp.length() < 3 && temp[0] == '-')
                                            temp = temp.insert(1, "0,");
                                        else temp = temp.insert(temp.length() - 1, ",");
                                        str35d_DewList.at(raddr)->setText(temp);
                                        i += 2;
                                        connect = true;
                                    }
                                    else
                                        connect = false;
                                    break;
                                }

                                case 0x45:
                                case 0x4C:
                                case 0x53:
                                case 0x5A:
                                case 0x61:
                                case 0x68:
                                case 0x6F:
                                case 0x76:
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        str35dpressurestatus[((uint8_t)frame.data.at(i - 2) - 0x45) / 7] = frame.data.at(i);
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;

                                case 0x46:
                                case 0x4D:
                                case 0x54:
                                case 0x5B:
                                case 0x62:
                                case 0x69:
                                case 0x70:
                                case 0x77:
                                {
                                    int raddr = ((uint8_t)frame.data.at(i) - 0x46) / 7;
                                    i++;
                                    if ((i + 1) < frame.length)
                                    {
                                        int itemp;
                                        itemp = (int)((int16_t)((uint16_t)((uint8_t)frame.data.at(i))*256+(uint8_t)frame.data.at(i+1)));
                                        QString temp;
                                        temp= QString::number(itemp);
                                        if (temp.length() < 2 && temp.at(0) != '-')
                                            temp = temp.insert(0, "0,");
                                        else if (temp.length() < 3 && temp[0] == '-')
                                            temp = temp.insert(1, "0,");
                                        else temp = temp.insert(temp.length() - 1, ",");
                                        str35d_PressList.at(raddr)->setText(temp);
                                        i += 2;
                                        connect = true;
                                    }
                                    else
                                        connect = false;
                                    break;
                                }


                                case 0x78:
                                case 0x7A:
                                case 0x7C:
                                case 0x7E:
                                case 0x80:
                                case 0x82:
                                case 0x84:
                                case 0x86:
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        str35dco2status[((uint8_t)frame.data.at(i - 2) - 0x78) / 2] = frame.data.at(i);
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                case 0x79:
                                case 0x7B:
                                case 0x7D:
                                case 0x7F:
                                case 0x81:
                                case 0x83:
                                case 0x85:
                                case 0x87:
                                {
                                    int raddr = ((uint8_t)frame.data.at(i) - 0x79) / 2;
                                    i++;
                                    if ((i + 1) < frame.length)
                                    {
                                        int itemp;
                                        itemp = (int)((int16_t)((uint16_t)((uint8_t)frame.data.at(i))*256+(uint8_t)frame.data.at(i+1)));
                                        QString temp;
                                        temp= QString::number(itemp);
                                        str35d_CO2List.at(raddr)->setText(temp);
                                        i += 2;
                                        connect = true;
                                    }
                                    else
                                        connect = false;
                                    break;
                                }



                                case 0xA0: //Адрес
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if (ui->str35d_ParamsEnable->isChecked() == false)
                                        {
                                            ui->str35d_AddrDEC->setValue((uint8_t)frame.data.at(i));
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA1:	//Скорость
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if (ui->str35d_ParamsEnable->isChecked() == false)
                                        {
                                            ui->str35d_BaudRate->setCurrentIndex((int)frame.data.at(i));
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA2:	//Протокол
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if  (ui->str35d_ParamsEnable->isChecked() == false)
                                        {
                                            if ((uint8_t)frame.data.at(i) == 0xf0)
                                                ui->str35d_ModbusEn->setChecked(true);
                                            else
                                                ui->str35d_ModbusEn->setChecked(false);
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA3:	//Бит четности
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if  (ui->str35d_ParamsEnable->isChecked() == false)
                                        {
                                            if((uint8_t)frame.data.at(i) == 0xf0)
                                                ui->str35d_Parity->setCurrentIndex(2);
                                            else if ((uint8_t)frame.data.at(i) == 0x0f)
                                                ui->str35d_Parity->setCurrentIndex(1);
                                            else
                                                ui->str35d_Parity->setCurrentIndex(0);
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0xA8:
                                {
                                    i++;
                                    int k=i;
                                    while (k<frame.length && (uint8_t)frame.data.at(k) != 0x0)
                                        k++;
                                    if (k < frame.length)
                                    {
                                        QByteArray sn;
                                        for (int n=0;n<k-i;n++)
                                        {
                                            sn.append(frame.data.at(i+n));
                                        }
                                        ui->moduleSN->setText(sn);
                                        i =k+1;
                                        while (i<frame.length && (uint8_t)frame.data.at(i) == 0x0)
                                            i++;
                                        connect = true;
                                    }
                                    else { ui->moduleSN->setText(ConstStings::noSN); connect = false; }
                                    break;
                                }
                                default: i++; break;
                            }
                            if (connect == false)
                                break;
                        }
                        if(connect == true)
                        {
                            if(secondReq_str35d == false)
                            {
                                for (int ts = 0; ts < str35d_TempList.length(); ts++)
                                {
                                    if(str35dtempstatus[ts] == 0)
                                        str35d_TempList.at(ts)->setText("");
                                }
                                for (int ts = 0; ts < str35d_HumList.length(); ts++)
                                {
                                    if(str35dhumstatus[ts] == 0)
                                    {
                                        str35d_HumList.at(ts)->setText("");
                                        str35d_DewList.at(ts)->setText("");
                                    }
                                }
                                for (int ts = 0; ts < str35d_PressList.length(); ts++)
                                {
                                    if(str35dpressurestatus[ts] == 0)
                                        str35d_PressList.at(ts)->setText("");
                                }
                            }
                            else
                            {
                                for (int ts = 0; ts < str35d_CO2List.length(); ts++)
                                {
                                    if(str35dco2status[ts] == 0)
                                        str35d_CO2List.at(ts)->setText("");
                                }
                            }
                        }
                        break;

                    }
                    case ModuleTypes_VCRS485:
                    {
                        int i = 0;
                        while (i < frame.length)
                        {
                            switch ((uint8_t)frame.data.at(i))
                            {
                                case 0x40:
                                case 0x41:
                                {
                                    QString str = "";
                                    uint8_t cn = (uint8_t)frame.data.at(i);
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        switch ((uint8_t)frame.data.at(i))
                                        {
                                            default:
                                            case 0:
                                                str = ""; break;
                                            case 0x0f:
                                                str = "макс."; break;
                                            case 0xf0:
                                                str = "мин."; break;
                                        }
                                        if (cn == 0x40)
                                            ui->vcrs485_Dia->setText(tr("%1").arg(str));
                                        else
                                            ui->vcrs485_Dia_2->setText(tr("%1").arg(str));
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0x42:
                                case 0x43:
                                {
                                    uint8_t cn = (uint8_t)frame.data.at(i);
                                    i++;
                                    if ((i + 1) < frame.length)
                                    {
                                        double valt = (double)((int16_t)((uint16_t)((uint8_t)frame.data.at(i))*256+(uint8_t)frame.data.at(i+1)));
                                        valt = valt / 100;
                                        switch (cn)
                                        {
                                            case 0x42: ui->vcrs485_Volt->setText(QString::number(valt, 'f', 2)); break;
                                            case 0x43: ui->vcrs485_Volt_2->setText(QString::number(valt, 'f', 2)); break;
                                        }
                                        i += 2;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0x44:
                                case 0x45:
                                {
                                    uint8_t cn = (uint8_t)frame.data.at(i);
                                    i++;
                                    if ((i + 1) < frame.length)
                                    {
                                        bool vs = false;
                                        if ((uint8_t)frame.data.at(i) == 0x0 && (uint8_t)frame.data.at(i+1) == 0x0)
                                        {
                                            connect = true;
                                        }
                                        else if ((uint8_t)frame.data.at(i) == 0 && (uint8_t)frame.data.at(i+1) == 0x0f)
                                        {
                                            connect = true;
                                            vs = true;
                                        }
                                        switch (cn)
                                        {
                                            case 0x44:
                                            {
                                                ui->vcrs485_Over->setVisible(vs);
                                                QFont f=ui->vcrs485_Over->font();
                                                f.setWeight(QFont::Bold);
                                                ui->vcrs485_Over->setFont(f);
                                                break;
                                            }
                                            case 0x45:
                                            {
                                                ui->vcrs485_Over_2->setVisible(vs);
                                                QFont f=ui->vcrs485_Over_2->font();
                                                f.setWeight(QFont::Bold);
                                                ui->vcrs485_Over_2->setFont(f);
                                                break;
                                            }
                                        }
                                        i += 2;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0x60:
                                case 0x61:
                                {
                                    uint8_t cn = (uint8_t)frame.data.at(i);
                                    uint8_t indx = (uint8_t)(cn - 0x60);
                                    i++;
                                    if ((i + 3) < frame.length)
                                    {
                                        double valt = (double)((int32_t)((uint32_t)(uint8_t)frame.data.at(i)*256*256*256+(uint32_t)(uint8_t)frame.data.at(i+1)*256*256+(uint32_t)(uint8_t)frame.data.at(i+2)*256+(uint8_t)(uint8_t)frame.data.at(i+3)));
                                        double n = qPow(10, vcrs485_template_an[indx]);
                                        valt = valt / n;
                                        switch (cn)
                                        {
                                            case 0x60: ui->vcrs485_AnK->setText(QString::number(valt, 'f', vcrs485_template_an[indx])); break;
                                            case 0x61: ui->vcrs485_AnK_2->setText(QString::number(valt, 'f', vcrs485_template_an[indx])); break;
                                        }
                                        i += 4;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0x10:
                                case 0x11:
                                {
                                    uint8_t cn = (uint8_t)frame.data.at(i);
                                    uint8_t indx = (uint8_t)(cn - 0x10);
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        vcrs485_template_an[indx] = (uint8_t)frame.data.at(i);
                                        if (vcrs485_template_an[indx] > 3) vcrs485_template_an[indx] = 3;
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0x30:
                                {
                                    i++;
                                    int j = 0;
                                    while ((uint8_t)frame.data.at(i + j) != 0x0) j++;
                                    if (j > 11)
                                    {
                                        connect = false;
                                        break;
                                    }
                                    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
                                    ui->vcrs485_Dim->setText(codec->toUnicode(frame.data.mid(i,j)));
                                    i = i + j + 1;
                                    connect = true;
                                    break;
                                }
                                case 0x31:
                                {
                                    i++;
                                    int j = 0;
                                    while ((uint8_t)frame.data.at(i + j) != 0x0) j++;
                                    if (j > 11)
                                    {
                                        connect = false;
                                        break;
                                    }
                                    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
                                    ui->vcrs485_Dim_2->setText(codec->toUnicode(frame.data.mid(i,j)));
                                    i = i + j + 1;
                                    connect = true;
                                    break;
                                }
                                case 0xA0: //Адрес
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if (ui->vcrs485_ParamsEnable->isChecked() == false)
                                        {
                                            ui->vcrs485_AddrDEC->setValue((uint8_t)frame.data.at(i));
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA1:	//Скорость
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if (ui->vcrs485_ParamsEnable->isChecked() == false)
                                        {
                                            ui->vcrs485_BaudRate->setCurrentIndex((int)frame.data.at(i));
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA2:	//Протокол
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if  (ui->vcrs485_ParamsEnable->isChecked() == false)
                                        {
                                            if ((uint8_t)frame.data.at(i) == 0xf0)
                                                ui->vcrs485_ModbusEn->setChecked(true);
                                            else
                                                ui->vcrs485_ModbusEn->setChecked(false);
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA3:	//Бит четности
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if  (ui->vcrs485_ParamsEnable->isChecked() == false)
                                        {
                                            if((uint8_t)frame.data.at(i) == 0xf0)
                                                ui->vcrs485_Parity->setCurrentIndex(2);
                                            else if ((uint8_t)frame.data.at(i) == 0x0f)
                                                ui->vcrs485_Parity->setCurrentIndex(1);
                                            else
                                                ui->vcrs485_Parity->setCurrentIndex(0);
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0xA8:
                                {
                                    i++;
                                    int k=i;
                                    while (k<frame.length && (uint8_t)frame.data.at(k) != 0x0)
                                        k++;
                                    if (k < frame.length)
                                    {
                                        QByteArray sn;
                                        for (int n=0;n<k-i;n++)
                                        {
                                            sn.append(frame.data.at(i+n));
                                        }
                                        ui->moduleSN->setText(sn);
                                        i =k+1;
                                        while (i<frame.length && (uint8_t)frame.data.at(i) == 0x0)
                                            i++;
                                        connect = true;
                                    }
                                    else { ui->moduleSN->setText(ConstStings::noSN); connect = false; }
                                    break;
                                }
                                default:
                                {
                                    i++; connect = false; break;
                                }
                            }
                            if(connect == false)
                                break;
                        }
                        break;
                    }

                    case ModuleTypes_ASC35D:
                    {
                        for (int cl = 0; cl < 4; cl++)
                        {
                            asc35d_status_cloop[cl] = 0x0;
                            asc35d_template_cloop[cl] = 0x0;
                        }
                        for (int cl = 0; cl < 2; cl++)
                        {
                            asc35d_template_an[cl] = 0x0;
                        }
                        int i = 0;
                        while (i < frame.length)
                        {
                            switch ((uint8_t)frame.data.at(i))
                            {
                                case 0x40:
                                case 0x41:
                                {
                                    QString str = "";
                                    uint8_t cn = (uint8_t)frame.data.at(i);
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        switch ((uint8_t)frame.data.at(i))
                                        {
                                            default:
                                            case 0:
                                                str = ""; break;
                                            case 0x0f:
                                                str = "макс."; break;
                                            case 0xf0:
                                                str = "мин."; break;
                                        }
                                        if (cn == 0x40)
                                            ui->asc35d_Dia_1->setText(tr("%1").arg(str));
                                        else
                                            ui->asc35d_Dia_2->setText(tr("%1").arg(str));
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0x42:
                                case 0x43:
                                case 0x44:
                                case 0x45:
                                {
                                    uint8_t cn = (uint8_t)frame.data.at(i);
                                    i++;
                                    if ((i + 1) < frame.length)
                                    {
                                        double valt = (double)((int16_t)((uint16_t)((uint8_t)frame.data.at(i))*256+(uint8_t)frame.data.at(i+1)));
                                        valt = valt / 100;
                                        switch (cn)
                                        {
                                            case 0x42: ui->asc35d_Volt_1->setText(QString::number(valt, 'f', 2)); break;
                                            case 0x43: ui->asc35d_Volt_2->setText(QString::number(valt, 'f', 2)); break;
                                            case 0x44: ui->asc35d_Curr_1->setText(QString::number(valt, 'f', 2)); break;
                                            case 0x45: ui->asc35d_Curr_2->setText(QString::number(valt, 'f', 2)); break;
                                        }
                                        i += 2;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0x46:
                                case 0x47:
                                case 0x48:
                                case 0x49:
                                {
                                    uint8_t cn = (uint8_t)frame.data.at(i);
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        asc35d_status_cloop[(cn - 0x46)] = (uint8_t)frame.data.at(i);
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0x60:
                                case 0x61:
                                {
                                    uint8_t cn = (uint8_t)frame.data.at(i);
                                    uint8_t indx = (uint8_t)(cn - 0x60);
                                    i++;
                                    if ((i + 3) < frame.length)
                                    {
                                        double valt = (double)((int32_t)((uint32_t)(uint8_t)frame.data.at(i)*256*256*256+(uint32_t)(uint8_t)frame.data.at(i+1)*256*256+(uint32_t)(uint8_t)frame.data.at(i+2)*256+(uint8_t)(uint8_t)frame.data.at(i+3)));
                                        double n = qPow(10, asc35d_template_an[indx]);
                                        valt = valt / n;
                                        switch (cn)
                                        {
                                            case 0x60: ui->asc35d_AnK_1->setText(QString::number(valt, 'f', asc35d_template_an[indx])); break;
                                            case 0x61: ui->asc35d_AnK_2->setText(QString::number(valt, 'f', asc35d_template_an[indx])); break;
                                        }
                                        i += 4;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0x62:
                                case 0x63:
                                case 0x64:
                                case 0x65:
                                {
                                    uint8_t cn = (uint8_t)frame.data.at(i);
                                    uint8_t indx = (uint8_t)(cn - 0x62);
                                    i++;
                                    if ((i + 3) < frame.length)
                                    {
                                        double valt = (double)((int32_t)((uint32_t)(uint8_t)frame.data.at(i)*256*256*256+(uint32_t)(uint8_t)frame.data.at(i+1)*256*256+(uint32_t)(uint8_t)frame.data.at(i+2)*256+(uint8_t)(uint8_t)frame.data.at(i+3)));
                                        double n = qPow(10, asc35d_template_cloop[indx]);
                                        valt = valt / n;
                                        switch (cn)
                                        {
                                            case 0x62: ui->asc35d_420_1->setText(QString::number(valt, 'f', asc35d_template_cloop[indx])); break;
                                            case 0x63: ui->asc35d_420_2->setText(QString::number(valt, 'f', asc35d_template_cloop[indx])); break;
                                            case 0x64: ui->asc35d_420_3->setText(QString::number(valt, 'f', asc35d_template_cloop[indx])); break;
                                            case 0x65: ui->asc35d_420_4->setText(QString::number(valt, 'f', asc35d_template_cloop[indx])); break;
                                        }
                                        i += 4;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0x10:
                                case 0x11:
                                {
                                    uint8_t cn = (uint8_t)frame.data.at(i);
                                    uint8_t indx = (uint8_t)(cn - 0x10);
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        asc35d_template_an[indx] = (uint8_t)frame.data.at(i);
                                        if (asc35d_template_an[indx] > 3)asc35d_template_an[indx] = 3;
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0x14:
                                case 0x17:
                                case 0x1A:
                                case 0x1D:
                                {
                                    uint8_t cn = (uint8_t)frame.data.at(i);
                                    uint8_t indx = (uint8_t)((uint8_t)(cn - 0x14))/3;
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        asc35d_template_cloop[indx] = (uint8_t)frame.data.at(i);
                                        if (asc35d_template_cloop[indx] > 3)asc35d_template_cloop[indx] = 3;
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0x30:
                                {
                                    i++;
                                    int j = 0;
                                    while ((uint8_t)frame.data.at(i + j) != 0x0) j++;
                                    if (j > 11)
                                    {
                                        connect = false;
                                        break;
                                    }
                                    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
                                    ui->asc35d_Dim_1->setText(codec->toUnicode(frame.data.mid(i,j)));
                                    i = i + j + 1;
                                    connect = true;
                                    break;
                                }
                                case 0x31:
                                {
                                    i++;
                                    int j = 0;
                                    while ((uint8_t)frame.data.at(i + j) != 0x0) j++;
                                    if (j > 11)
                                    {
                                        connect = false;
                                        break;
                                    }
                                    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
                                    ui->asc35d_Dim_2->setText(codec->toUnicode(frame.data.mid(i,j)));
                                    i = i + j + 1;
                                    connect = true;
                                    break;
                                }
                                case 0x32:
                                {
                                    i++;
                                    int j = 0;
                                    while ((uint8_t)frame.data.at(i + j) != 0x0) j++;
                                    if (j > 11)
                                    {
                                        connect = false;
                                        break;
                                    }
                                    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
                                    ui->asc35d_420Dim_1->setText(codec->toUnicode(frame.data.mid(i,j)));
                                    i = i + j + 1;
                                    connect = true;
                                    break;
                                }
                                case 0x33:
                                {
                                    i++;
                                    int j = 0;
                                    while ((uint8_t)frame.data.at(i + j) != 0x0) j++;
                                    if (j > 11)
                                    {
                                        connect = false;
                                        break;
                                    }
                                    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
                                    ui->asc35d_420Dim_2->setText(codec->toUnicode(frame.data.mid(i,j)));
                                    i = i + j + 1;
                                    connect = true;
                                    break;
                                }
                                case 0x34:
                                {
                                    i++;
                                    int j = 0;
                                    while ((uint8_t)frame.data.at(i + j) != 0x0) j++;
                                    if (j > 11)
                                    {
                                        connect = false;
                                        break;
                                    }
                                    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
                                    ui->asc35d_420Dim_3->setText(codec->toUnicode(frame.data.mid(i,j)));
                                    i = i + j + 1;
                                    connect = true;
                                    break;
                                }
                                case 0x35:
                                {
                                    i++;
                                    int j = 0;
                                    while ((uint8_t)frame.data.at(i + j) != 0x0) j++;
                                    if (j > 11)
                                    {
                                        connect = false;
                                        break;
                                    }
                                    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
                                    ui->asc35d_420Dim_4->setText(codec->toUnicode(frame.data.mid(i,j)));
                                    i = i + j + 1;
                                    connect = true;
                                    break;
                                }
                                case 0xA0: //Адрес
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if (ui->asc35d_ParamsEnable->isChecked() == false)
                                        {
                                            ui->asc35d_AddrDEC->setValue((uint8_t)frame.data.at(i));
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA1:	//Скорость
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if (ui->asc35d_ParamsEnable->isChecked() == false)
                                        {
                                            ui->asc35d_BaudRate->setCurrentIndex((int)frame.data.at(i));
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA2:	//Протокол
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if  (ui->asc35d_ParamsEnable->isChecked() == false)
                                        {
                                            if ((uint8_t)frame.data.at(i) == 0xf0)
                                                ui->asc35d_ModbusEn->setChecked(true);
                                            else
                                                ui->asc35d_ModbusEn->setChecked(false);
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA3:	//Бит четности
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if  (ui->asc35d_ParamsEnable->isChecked() == false)
                                        {
                                            if((uint8_t)frame.data.at(i) == 0xf0)
                                                ui->asc35d_Parity->setCurrentIndex(2);
                                            else if ((uint8_t)frame.data.at(i) == 0x0f)
                                                ui->asc35d_Parity->setCurrentIndex(1);
                                            else
                                                ui->asc35d_Parity->setCurrentIndex(0);
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0xA8:
                                {
                                    i++;
                                    int k=i;
                                    while (k<frame.length && (uint8_t)frame.data.at(k) != 0x0)
                                        k++;
                                    if (k < frame.length)
                                    {
                                        QByteArray sn;
                                        for (int n=0;n<k-i;n++)
                                        {
                                            sn.append(frame.data.at(i+n));
                                        }
                                        ui->moduleSN->setText(sn);
                                        i =k+1;
                                        while (i<frame.length && (uint8_t)frame.data.at(i) == 0x0)
                                            i++;
                                        connect = true;
                                    }
                                    else { ui->moduleSN->setText(ConstStings::noSN); connect = false; }
                                    break;
                                }
                                default:
                                {
                                    i++; connect = false; break;
                                }
                            }
                            if(connect == false)
                                break;
                        }
                        if (asc35d_status_cloop[0] == 0)
                        {
                            ui->asc35d_420_1->setText(tr("отключен"));
                            ui->asc35d_420Dim_1->setText("");
                        }
                        if (asc35d_status_cloop[1] == 0)
                        {
                            ui->asc35d_420_2->setText(tr("отключен"));
                            ui->asc35d_420Dim_2->setText("");
                        }
                        if (asc35d_status_cloop[2] == 0)
                        {
                            ui->asc35d_420_3->setText(tr("отключен"));
                            ui->asc35d_420Dim_3->setText("");
                        }
                        if (asc35d_status_cloop[3] == 0)
                        {
                            ui->asc35d_420_4->setText(tr("отключен"));
                            ui->asc35d_420Dim_4->setText("");
                        }
                        break;
                    }
                    case ModuleTypes_SVA35D:
                    {
                        int i = 0;
                        while (i < frame.length)
                        {
                            switch ((uint8_t)frame.data.at(i))
                            {
                                case 0x40:
                                {
                                    i++;
                                    if ((i + 1) < frame.length)
                                    {
                                        double valt = (double)((int16_t)((uint16_t)((uint8_t)frame.data.at(i))*256+(uint8_t)frame.data.at(i+1)));
                                        valt = valt / 100;
                                        ui->sva35dData->item(22,2)->setText(QString::number(valt, 'f', 2));
                                        i += 2;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0x41:
                                case 0x42:
                                case 0x43:
                                {
                                    uint8_t cn = (uint8_t)frame.data.at(i);
                                    i++;
                                    if ((i + 1) < frame.length)
                                    {
                                        double valt = (double)((int16_t)((uint16_t)((uint8_t)frame.data.at(i))*256+(uint8_t)frame.data.at(i+1)));
                                        valt = valt / 100;
                                        ui->sva35dData->item(cn-0x41+19,2)->setText(QString::number(valt, 'f', 2));
                                        i += 2;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0x44:
                                case 0x45:
                                case 0x46:
                                {
                                    uint8_t cn = (uint8_t)frame.data.at(i);
                                    i++;
                                    if ((i + 1) < frame.length)
                                    {
                                        double valt = (double)((int16_t)((uint16_t)((uint8_t)frame.data.at(i))*256+(uint8_t)frame.data.at(i+1)));
                                        valt = valt / 100;
                                        ui->sva35dData->item(cn-0x44+24,2)->setText(QString::number(valt, 'f', 2));
                                        i += 2;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0x47:
                                {
                                    uint8_t cn = (uint8_t)frame.data.at(i);
                                    i++;
                                    if ((i + 1) < frame.length)
                                    {
                                        double valt = (double)((int16_t)((uint16_t)((uint8_t)frame.data.at(i))*256+(uint8_t)frame.data.at(i+1)));
                                        valt = valt / 10;
                                        sva35dCalibData[3] = QString::number(valt, 'f', 1);
                                        ui->sva35dData->item(cn-0x47+23,2)->setText(sva35dCalibData[3]);
                                        i += 2;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0x60:
                                case 0x61:
                                case 0x62:
                                {
                                    uint8_t cn = (uint8_t)frame.data.at(i);
                                    i++;
                                    if ((i + 3) < frame.length)
                                    {
                                        double valt = (double)((int32_t)((uint32_t)(uint8_t)frame.data.at(i)*256*256*256+(uint32_t)(uint8_t)frame.data.at(i+1)*256*256+(uint32_t)(uint8_t)frame.data.at(i+2)*256+(uint8_t)(uint8_t)frame.data.at(i+3)));
                                        valt = valt / 100;
                                        ui->sva35dData->item(cn-0x60+12,2)->setText(QString::number(valt, 'f', 2));
                                        i += 4;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0x63:
                                case 0x64:
                                case 0x65:
                                case 0x66:
                                {
                                    uint8_t cn = (uint8_t)frame.data.at(i);
                                    i++;
                                    if ((i + 3) < frame.length)
                                    {
                                        double valt = (double)((int32_t)((uint32_t)(uint8_t)frame.data.at(i)*256*256*256+(uint32_t)(uint8_t)frame.data.at(i+1)*256*256+(uint32_t)(uint8_t)frame.data.at(i+2)*256+(uint8_t)(uint8_t)frame.data.at(i+3)));
                                        valt = valt / 100;
                                        ui->sva35dData->item(cn-0x63+15,2)->setText(QString::number(valt, 'f', 2));
                                        i += 4;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0x67:
                                case 0x68:
                                case 0x69:
                                case 0x6A:
                                case 0x6B:
                                case 0x6C:
                                case 0x6D:
                                case 0x6E:
                                case 0x6F:
                                case 0x70:
                                case 0x71:
                                case 0x72:
                                {
                                    uint8_t cn = (uint8_t)frame.data.at(i);
                                    i++;
                                    if ((i + 3) < frame.length)
                                    {
                                        double valt = (double)((int32_t)((uint32_t)(uint8_t)frame.data.at(i)*256*256*256+(uint32_t)(uint8_t)frame.data.at(i+1)*256*256+(uint32_t)(uint8_t)frame.data.at(i+2)*256+(uint8_t)(uint8_t)frame.data.at(i+3)));
                                        valt = valt / 1000;
                                        if(cn == 0x70 || cn == 0x71 || cn == 0x72)
                                        {
                                            sva35dCalibData[cn-0x70] = QString::number(valt, 'f', 3);
                                        }
                                        ui->sva35dData->item(cn-0x67+0,2)->setText(QString::number(valt, 'f', 3));
                                        i += 4;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0xA0: //Адрес
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if (ui->sva35d_ParamsEnable->isChecked() == false)
                                        {
                                            ui->sva35d_AddrDEC->setValue((uint8_t)frame.data.at(i));
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA1:	//Скорость
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if (ui->sva35d_ParamsEnable->isChecked() == false)
                                        {
                                            ui->sva35d_BaudRate->setCurrentIndex((int)frame.data.at(i));
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA2:	//Протокол
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if  (ui->sva35d_ParamsEnable->isChecked() == false)
                                        {
                                            if ((uint8_t)frame.data.at(i) == 0xf0)
                                                ui->sva35d_ModbusEn->setChecked(true);
                                            else
                                                ui->sva35d_ModbusEn->setChecked(false);
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA3:	//Бит четности
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if  (ui->sva35d_ParamsEnable->isChecked() == false)
                                        {
                                            if((uint8_t)frame.data.at(i) == 0xf0)
                                                ui->sva35d_Parity->setCurrentIndex(2);
                                            else if ((uint8_t)frame.data.at(i) == 0x0f)
                                                ui->sva35d_Parity->setCurrentIndex(1);
                                            else
                                                ui->sva35d_Parity->setCurrentIndex(0);
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0xA8:
                                {
                                    i++;
                                    int k=i;
                                    while (k<frame.length && (uint8_t)frame.data.at(k) != 0x0)
                                        k++;
                                    if (k < frame.length)
                                    {
                                        QByteArray sn;
                                        for (int n=0;n<k-i;n++)
                                        {
                                            sn.append(frame.data.at(i+n));
                                        }
                                        ui->moduleSN->setText(sn);
                                        i =k+1;
                                        while (i<frame.length && (uint8_t)frame.data.at(i) == 0x0)
                                            i++;
                                        connect = true;
                                    }
                                    else { ui->moduleSN->setText(ConstStings::noSN); connect = false; }
                                    break;
                                }
                                default:
                                {
                                    i++; connect = false; break;
                                }
                            }
                            if(connect == false)
                                break;
                        }
                        break;
                    }
                    case ModuleTypes_SPC35D:
                    {
                        int i = 0;
                        while (i < frame.length)
                        {
                            switch ((uint8_t)frame.data.at(i))
                            {
                                case 0x40:
                                {
                                    i++;
                                    if ((i + 1) < frame.length)
                                    {
                                        uint16_t valt = ((uint16_t)((uint16_t)((uint8_t)frame.data.at(i))*256+(uint8_t)frame.data.at(i+1)));
                                        ui->spc35dData->item(0,2)->setText(QString::number(valt));
                                        i += 2;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0x41:
                                {
                                    i++;
                                    if ((i + 1) < frame.length)
                                    {
                                        double valt = (double)((int16_t)((uint16_t)((uint8_t)frame.data.at(i))*256+(uint8_t)frame.data.at(i+1)));
                                        valt = valt / 100;
                                        ui->spc35dData->item(19,2)->setText(QString::number(valt, 'f', 2));
                                        i += 2;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0x42:
                                case 0x43:
                                case 0x44:
                                {
                                    uint8_t cn = (uint8_t)frame.data.at(i);
                                    i++;
                                    if ((i + 1) < frame.length)
                                    {
                                        double valt = (double)((int16_t)((uint16_t)((uint8_t)frame.data.at(i))*256+(uint8_t)frame.data.at(i+1)));
                                        valt = valt / 10;
                                        ui->spc35dData->item(cn-0x42+44,2)->setText(QString::number(valt, 'f', 1));
                                        i += 2;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0x60:
                                case 0x61:
                                case 0x62:
                                case 0x63:
                                case 0x64:
                                case 0x65:
                                case 0x66:
                                case 0x67:
                                case 0x68:
                                case 0x69:
                                case 0x6A:
                                case 0x6B:
                                case 0x6C:
                                case 0x6D:
                                case 0x6E:
                                case 0x6F:
                                case 0x70:
                                case 0x71:
                                case 0x72:
                                case 0x73:
                                case 0x74:
                                case 0x75:
                                case 0x76:
                                case 0x77:
                                {
                                    uint8_t cn = (uint8_t)frame.data.at(i);
                                    i++;
                                    if ((i + 3) < frame.length)
                                    {
                                        double valt = (double)((int32_t)((uint32_t)(uint8_t)frame.data.at(i)*256*256*256+(uint32_t)(uint8_t)frame.data.at(i+1)*256*256+(uint32_t)(uint8_t)frame.data.at(i+2)*256+(uint8_t)(uint8_t)frame.data.at(i+3)));
                                        valt = valt / 1000;
                                        ui->spc35dData->item(cn-0x60+3,2)->setText(QString::number(valt, 'f', 3));
                                        i += 4;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0x78:
                                case 0x79:
                                case 0x7A:
                                case 0x7B:
                                case 0x7C:
                                case 0x7D:
                                {
                                    uint8_t cn = (uint8_t)frame.data.at(i);
                                    i++;
                                    if ((i + 3) < frame.length)
                                    {
                                        double valt = (double)((int32_t)((uint32_t)(uint8_t)frame.data.at(i)*256*256*256+(uint32_t)(uint8_t)frame.data.at(i+1)*256*256+(uint32_t)(uint8_t)frame.data.at(i+2)*256+(uint8_t)(uint8_t)frame.data.at(i+3)));
                                        ui->spc35dData->item(cn-0x78+28,2)->setText(QString::number(valt, 'f', 3));
                                        i += 4;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0x7E:
                                case 0x7F:
                                case 0x80:
                                case 0x81:
                                case 0x82:
                                case 0x83:
                                {
                                    uint8_t cn = (uint8_t)frame.data.at(i);
                                    i++;
                                    if ((i + 3) < frame.length)
                                    {
                                        double valt = (double)((int32_t)((uint32_t)(uint8_t)frame.data.at(i)*256*256*256+(uint32_t)(uint8_t)frame.data.at(i+1)*256*256+(uint32_t)(uint8_t)frame.data.at(i+2)*256+(uint8_t)(uint8_t)frame.data.at(i+3)));
                                        valt = valt / 1000;
                                        ui->spc35dData->item(cn-0x7E + 34,2)->setText(QString::number(valt, 'f', 3));
                                        i += 4;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0x84:
                                case 0x85:
                                case 0x86:
                                case 0x87:
                                {
                                    uint8_t cn = (uint8_t)frame.data.at(i);
                                    i++;
                                    if ((i + 3) < frame.length)
                                    {
                                        double valt = (double)((int32_t)((uint32_t)(uint8_t)frame.data.at(i)*256*256*256+(uint32_t)(uint8_t)frame.data.at(i+1)*256*256+(uint32_t)(uint8_t)frame.data.at(i+2)*256+(uint8_t)(uint8_t)frame.data.at(i+3)));
                                        valt = valt / 1000;
                                        ui->spc35dData->item(cn-0x84 + 40,2)->setText(QString::number(valt, 'f', 3));
                                        i += 4;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }


                                case 0xA0: //Адрес
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if (ui->spc35d_ParamsEnable->isChecked() == false)
                                        {
                                            ui->spc35d_AddrDEC->setValue((uint8_t)frame.data.at(i));
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA1:	//Скорость
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if (ui->spc35d_ParamsEnable->isChecked() == false)
                                        {
                                            ui->spc35d_BaudRate->setCurrentIndex((int)frame.data.at(i));
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA2:	//Протокол
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if  (ui->spc35d_ParamsEnable->isChecked() == false)
                                        {
                                            if ((uint8_t)frame.data.at(i) == 0xf0)
                                                ui->spc35d_ModbusEn->setChecked(true);
                                            else
                                                ui->spc35d_ModbusEn->setChecked(false);
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }

                                case 0xA3:	//Бит четности
                                {
                                    i += 2;
                                    if (i < frame.length)
                                    {
                                        if  (ui->spc35d_ParamsEnable->isChecked() == false)
                                        {
                                            if((uint8_t)frame.data.at(i) == 0xf0)
                                                ui->spc35d_Parity->setCurrentIndex(2);
                                            else if ((uint8_t)frame.data.at(i) == 0x0f)
                                                ui->spc35d_Parity->setCurrentIndex(1);
                                            else
                                                ui->spc35d_Parity->setCurrentIndex(0);
                                        }
                                        i++;
                                        connect = true;
                                    }
                                    else connect = false;
                                    break;
                                }
                                case 0xA8:
                                {
                                    i++;
                                    int k=i;
                                    while (k<frame.length && (uint8_t)frame.data.at(k) != 0x0)
                                        k++;
                                    if (k < frame.length)
                                    {
                                        QByteArray sn;
                                        for (int n=0;n<k-i;n++)
                                        {
                                            sn.append(frame.data.at(i+n));
                                        }
                                        ui->moduleSN->setText(sn);
                                        i =k+1;
                                        while (i<frame.length && (uint8_t)frame.data.at(i) == 0x0)
                                            i++;
                                        connect = true;
                                    }
                                    else { ui->moduleSN->setText(ConstStings::noSN); connect = false; }
                                    break;
                                }
                                case 0xA9:
                                case 0xAA:
                                {
                                    uint8_t cn = (uint8_t)frame.data.at(i);
                                    i++;
                                    int j = 0;
                                    while ((uint8_t)frame.data.at(i + j) != 0x0) j++;
                                    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
                                    ui->spc35dData->item(cn - 0xA9 + 1,2)->setText(codec->toUnicode(frame.data.mid(i,j)));
                                    i = i + j + 1;
                                    break;
                                }
                                case 0xAB:
                                {
                                    i++;
                                    int j = 0;
                                    while ((uint8_t)frame.data.at(i + j) != 0x0) j++;
                                    if (j > 20)
                                    {
                                        connect = false;
                                        break;
                                    }
                                    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
                                    ui->spc35dData->item(47,2)->setText(codec->toUnicode(frame.data.mid(i,j)));
                                    i = i + j + 1;
                                    connect = true;
                                    break;
                                }
                                case 0xAC:
                                {
                                    i++;
                                    int j = 0;
                                    while ((uint8_t)frame.data.at(i + j) != 0x0) j++;
                                    if (j > 20)
                                    {
                                        connect = false;
                                        break;
                                    }
                                    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
                                     ui->spc35dData->item(48,2)->setText(codec->toUnicode(frame.data.mid(i,j)));
                                    i = i + j + 1;
                                    connect = true;
                                    break;
                                }
                                default:
                                {
                                    i++; connect = false; break;
                                }
                            }
                            if(connect == false)
                                break;
                        }
                        break;
                    }
                    default:
                        break;
                }
            }
            else
               passConnErr=4;
        }
        else if ((frame.Function & 0x7f) == Function_Read)
        {
            if (voltReq_usrs485 == true && ModuleType == ModuleTypes_USRS485)
            {
                voltReq_usrs485 = false;
                if (ModuleConnected == true)
                    connect = true;
            }
            else if (secondReq_str35d == true && ModuleType == ModuleTypes_STR35D)
            {
                secondReq_str35d = false;
                if (ModuleConnected == true)
                    connect = true;
            }
        }
    }
    else if((frame.TransmitStatus != TrmtStatus_Unknown) || tabWasChanged == true)
    {
        passConnErr=4;
        tabWasChanged = false;
    }

    //Connect status
    if (connect == false)
    {
        passConnErr++;
    }

    if (passConnErr > 3 || connect == true)
    {
        passConnErr = 0;

        voltReq_usrs485 = false;
        secondReq_str35d = false;

        if (connect == true)
        {
            ui->moduleConnectStatus->setText(ConstStings::connected);
            QPalette palette = ui->moduleConnectStatus->palette();
            palette.setColor(QPalette::WindowText, Qt::darkGreen);
            ui->moduleConnectStatus->setPalette(palette);
            ModuleConnected = true;
        }
        else
        {
            ui->moduleConnectStatus->setText(ConstStings::disconnected);
            QPalette palette = ui->moduleConnectStatus->palette();
            palette.setColor(QPalette::WindowText, Qt::red);
            ui->moduleConnectStatus->setPalette(palette);
            ModuleConnected = false;

            firstReq_usrs485 = true;
            firstReq_str35d = true;
            firstReq_spc35d = true;

            ui->moduleSN->setText(ConstStings::noSN);
            switch (ModuleType)
            {
                case ModuleTypes_SK35D:
                    sk35d_DisconnectedDataSet();
                    break;
                case ModuleTypes_SVC35D:
                    svc35d_DisconnectedDataSet();
                    break;
                case ModuleTypes_SR35D:
                    sr35d_DisconnectedDataSet();
                    break;
                case ModuleTypes_USRS485:
                    usrs485_DisconnectedDataSet();
                    break;
                case ModuleTypes_CSRS485:
                    csrs485_DisconnectedDataSet();
                    break;
                case ModuleTypes_STR35D:
                    str35d_DisconnectedDataSet();
                    break;
                case ModuleTypes_VCRS485:
                    vcrs485_DisconnectedDataSet();
                    break;
                case ModuleTypes_ASC35D:
                    asc35d_DisconnectedDataSet();
                    break;
                case ModuleTypes_SVA35D:
                    sva35d_DisconnectedDataSet();
                    break;
                case ModuleTypes_SPC35D:
                    spc35d_DisconnectedDataSet();
                    break;
             }
       }
    }


    //Send request
    frame.data.clear();
    frame.Function = Function_Read;
    switch(ModuleType)
    {
        case ModuleTypes_SK35D:
        {
            const uint8_t req[]={ 0x40, 0x80, 0x81, 0x88, 0x89, 0x8A, 0x8B, 0xA0, 0xA1, 0xA2, 0xA3, 0xA8 };
            frame.data.append((char*)req, sizeof(req));
            frame.length = frame.data.length();
            ModuleAddress = (uint8_t)ui->sk35dModuleN->value()+(ModuleBaseAddress_SK35D-1);
            frame.ComAddress = ModuleAddress;
            break;
        }
        case ModuleTypes_SVC35D:
        {
            const uint8_t req[]={ 0x40, 0x80, 0x81, 0x88, 0x89, 0xA0, 0xA1, 0xA2, 0xA3, 0xA8 };
            frame.data.append((char*)req, sizeof(req));
            frame.length = frame.data.length();

            ModuleAddress = (uint8_t)ui->svc35dModuleN->value()+(ModuleBaseAddress_SVC35D-1);
            frame.ComAddress = ModuleAddress;
            break;
        }
        case ModuleTypes_SR35D:
        {
            const uint8_t req[]={0x40, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8C, 0x8D, 0x8F, 0x90, 0x92, 0x93, 0x95, 0x96, 0x98, 0x99, 0xA0, 0xA1, 0xA2, 0xA3, 0xA8 };
            frame.data.append((char*)req, sizeof(req));
            frame.length = frame.data.length();

            ModuleAddress = (uint8_t)ui->sr35dModuleN->value()+(ModuleBaseAddress_SR35D-1);
            frame.ComAddress = ModuleAddress;
            break;
        }
        case ModuleTypes_USRS485:
        {
            if (firstReq_usrs485 == true)
            {
                const uint8_t req[]={ 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0xA0, 0xA1, 0xA2, 0xA3, 0xA8 };
                frame.data.append((char*)req, sizeof(req));
                firstReq_usrs485 = false;
            }
            else
            {
                const uint8_t req[]={ 0x4f };
                frame.data.append((char*)req, sizeof(req));
                firstReq_usrs485 = true;
                voltReq_usrs485 = true;
            }

            frame.length = frame.data.length();
            ModuleAddress = (uint8_t)ui->usrs485ModuleN->value()+(ModuleBaseAddress_USRS485-1);
            frame.ComAddress = ModuleAddress;
            break;
        }
        case ModuleTypes_CSRS485:
        {
            const uint8_t req[]={ 0x50, 0x51, 0xA0, 0xA1, 0xA2, 0xA3, 0xA8 };
            frame.data.append((char*)req, sizeof(req));
            frame.length = frame.data.length();
            ModuleAddress = (uint8_t)ui->csrs485ModuleN->value()+(ModuleBaseAddress_CSRS485-1);
            frame.ComAddress = ModuleAddress;
            break;
        }
        case ModuleTypes_STR35D:
        {
            if (firstReq_str35d == true)
            {
                const uint8_t req[]={ 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0xA0, 0xA1, 0xA2, 0xA3, 0xA8 };
                frame.data.append((char*)req, sizeof(req));
                firstReq_str35d = false;
            }
            else
            {
                const uint8_t req[]={0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87 };
                frame.data.append((char*)req, sizeof(req));
                firstReq_str35d = true;
                secondReq_str35d = true;
            }
            frame.length = frame.data.length();
            ModuleAddress = (uint8_t)ui->str35dModuleN->value()+(ModuleBaseAddress_STR35D-1);
            frame.ComAddress = ModuleAddress;
            break;
        }
        case ModuleTypes_VCRS485:
        {
            const uint8_t req[]={ 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x10, 0x60, 0x11, 0x61, 0x30, 0x31, 0xA0, 0xA1, 0xA2, 0xA3, 0xA8 };
            frame.data.append((char*)req, sizeof(req));
            frame.length = frame.data.length();
            ModuleAddress = (uint8_t)ui->vcrs485ModuleN->value()+(ModuleBaseAddress_VCRS485-1);
            frame.ComAddress = ModuleAddress;
            break;
        }
        case ModuleTypes_ASC35D:
        {
            const uint8_t req[]= { 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x10, 0x60, 0x11, 0x61, 0x14, 0x62, 0x17, 0x63, 0x1A, 0x64, 0x1D, 0x65, 0xA0, 0xA1, 0xA2, 0xA3, 0xA8, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35 };
            frame.data.append((char*)req, sizeof(req));
            frame.length = frame.data.length();
            ModuleAddress = (uint8_t)ui->asc35dModuleN->value()+(ModuleBaseAddress_ASC35D-1);
            frame.ComAddress = ModuleAddress;
            break;
        }
        case ModuleTypes_SVA35D:
        {
            const uint8_t req[]= { 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x72, 0xA0, 0xA1, 0xA2, 0xA3, 0xA8 };
            frame.data.append((char*)req, sizeof(req));
            frame.length = frame.data.length();
            ModuleAddress = (uint8_t)ui->sva35dModuleN->value()+(ModuleBaseAddress_SVA35D-1);
            frame.ComAddress = ModuleAddress;
            break;
        }
        case ModuleTypes_SPC35D:
        {
            if (firstReq_spc35d == true)
            {
                const uint8_t req[]= { 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC };
                frame.data.append((char*)req, sizeof(req));
                firstReq_spc35d = false;
            }
            else
            {
                const uint8_t req[]= { 0x40, 0x41, 0x42, 0x43, 0x44, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0xA0, 0xA1, 0xA2, 0xA3 };
                frame.data.append((char*)req, sizeof(req));
                firstReq_spc35d = true;
            }
            frame.length = frame.data.length();
            ModuleAddress = (uint8_t)ui->spc35dModuleN->value()+(ModuleBaseAddress_SPC35D-1);
            frame.ComAddress = ModuleAddress;
            break;
        }

    }
    frame.TransmitStatus = TrmtStatus_Send;
    comP.queue.EnqueueTxFrame(frame);
}

void MainWindow::onWriteButton_Click()
{
    if(ModuleConnected == false)
    {
        QMessageBox::information(NULL, tr("Внимание"),
                               tr("Отсутствует соединение с модулем"));
        return;
    }

    wrframe.TransmitStatus = TrmtStatus_SendWithRxTimeout;
    wrframe.rx_timeout = 700;
    wrframe.ComAddress = ModuleAddress;
    wrframe.Function = Function_Write;
    wrframe.length = 0;
    wrframe.data.clear();
    switch(ModuleType)
    {
        case ModuleTypes_SK35D:
        {
            if  (ui->sk35d_ParamsEnable->isChecked() == false)
            {
                QMessageBox::information(NULL, tr("Внимание"),
                                       tr("Включите режим редактирования"));
                return;
            }
            wrframe.data.append((char)0x80);
            uint8_t ch[2]={0,0};
            for(int k=0;k<sk35d_TypeList.length();k++)
            {
                if(sk35d_TypeList.at(k)->checkState() == Qt::Checked)
                {
                    ch[k/8] |= 1<<(k%8);
                }
            }
            wrframe.data.append((char)ch[1]);
            wrframe.data.append((char)ch[0]);

            wrframe.data.append((char)0x81);
            wrframe.data.append((char)0x0);
            wrframe.data.append((char)((uint8_t)ui->sk35d_Timer->value()));

            wrframe.data.append((char)0xA0);
            wrframe.data.append((char)0x0);
            wrframe.data.append((char)((uint8_t)ui->sk35d_AddrDEC->value()));

            wrframe.data.append((char)0xA1);
            wrframe.data.append((char)0x0);
            wrframe.data.append(ui->sk35d_BaudRate->currentIndex());

            wrframe.data.append((char)0xA2);
            wrframe.data.append((char)0x0);
            if(ui->sk35d_ModbusEn->checkState() == Qt::Checked)
            {
                wrframe.data.append((char)0xf0);
            }
            else
            {
                wrframe.data.append((char)0x0f);
            }

            wrframe.data.append((char)0xA3);
            wrframe.data.append((char)0x0);
            switch(ui->sk35d_Parity->currentIndex())
            {
                default:
                case 0:
                  wrframe.data.append((char)0x0);break;
                case 1:
                  wrframe.data.append((char)0x0f);break;
                case 2:
                  wrframe.data.append((char)0xf0);break;
            }

            wrframe.data.append((char)0x88);
            wrframe.data.append((char)0x0);
            switch(ui->sk35d_Relay1->currentIndex())
            {
                default:
                case 0:
                  wrframe.data.append((char)0x0f);break;
                case 1:
                  wrframe.data.append((char)0xf0);break;
            }

            wrframe.data.append((char)0x89);
            wrframe.data.append((char)0x0);
            if(ui->sk35d_Relay1Save->checkState() == Qt::Checked)
            {
                wrframe.data.append((char)0xf0);
            }
            else
            {
                wrframe.data.append((char)0x0f);
            }

            wrframe.data.append((char)0x8A);
            wrframe.data.append((char)0x0);
            switch(ui->sk35d_Relay2->currentIndex())
            {
                default:
                case 0:
                  wrframe.data.append((char)0x0f);break;
                case 1:
                  wrframe.data.append((char)0xf0);break;
            }

            wrframe.data.append((char)0x8B);
            wrframe.data.append((char)0x0);
            if(ui->sk35d_Relay2Save->checkState() == Qt::Checked)
            {
                wrframe.data.append((char)0xf0);
            }
            else
            {
                wrframe.data.append((char)0x0f);
            }

            wrframe.length = wrframe.data.length();
            break;
        }
        case ModuleTypes_SVC35D:
        {
            if  (ui->svc35d_ParamsEnable->isChecked() == false)
            {
                QMessageBox::information(NULL, tr("Внимание"),
                                       tr("Включите режим редактирования"));
                return;
            }
            wrframe.data.append((char)0x80);
            uint8_t ch[2]={0,0};
            for(int k=0;k<svc35d_TypeList.length();k++)
            {
                if(svc35d_TypeList.at(k)->checkState() == Qt::Checked)
                {
                    ch[k/8] |= 1<<(k%8);
                }
            }
            wrframe.data.append((char)ch[1]);
            wrframe.data.append((char)ch[0]);

            wrframe.data.append((char)0x81);
            wrframe.data.append((char)0x0);
            wrframe.data.append((char)((uint8_t)ui->svc35d_Timer->value()));

            wrframe.data.append((char)0xA0);
            wrframe.data.append((char)0x0);
            wrframe.data.append((char)((uint8_t)ui->svc35d_AddrDEC->value()));

            wrframe.data.append((char)0xA1);
            wrframe.data.append((char)0x0);
            wrframe.data.append(ui->svc35d_BaudRate->currentIndex());

            wrframe.data.append((char)0xA2);
            wrframe.data.append((char)0x0);
            if(ui->svc35d_ModbusEn->checkState() == Qt::Checked)
            {
                wrframe.data.append((char)0xf0);
            }
            else
            {
                wrframe.data.append((char)0x0f);
            }

            wrframe.data.append((char)0xA3);
            wrframe.data.append((char)0x0);
            switch(ui->svc35d_Parity->currentIndex())
            {
                default:
                case 0:
                  wrframe.data.append((char)0x0);break;
                case 1:
                  wrframe.data.append((char)0x0f);break;
                case 2:
                  wrframe.data.append((char)0xf0);break;
            }

            wrframe.data.append((char)0x88);
            wrframe.data.append((char)0x0);
            switch(ui->svc35d_Relay1->currentIndex())
            {
                default:
                case 0:
                  wrframe.data.append((char)0x0f);break;
                case 1:
                  wrframe.data.append((char)0xf0);break;
            }

            wrframe.data.append((char)0x89);
            wrframe.data.append((char)0x0);
            if(ui->svc35d_Relay1Save->checkState() == Qt::Checked)
            {
                wrframe.data.append((char)0xf0);
            }
            else
            {
                wrframe.data.append((char)0x0f);
            }

            wrframe.length = wrframe.data.length();
            break;
        }
        case ModuleTypes_SR35D:
        {
            if  (ui->sr35d_ParamsEnable->isChecked() == false)
            {
                QMessageBox::information(NULL, tr("Внимание"),
                                       tr("Включите режим редактирования"));
                return;
            }
            wrframe.data.append((char)0x80);
            uint8_t ch[2]={0,0};
            for(int k=0;k<sr35d_TypeList.length();k++)
            {
                if(sr35d_TypeList.at(k)->checkState() == Qt::Checked)
                {
                    ch[k/8] |= 1<<(k%8);
                }
            }
            wrframe.data.append((char)ch[1]);
            wrframe.data.append((char)ch[0]);

            for(int k=0;k<sr35d_TimerList.length();k++)
            {
                wrframe.data.append((char)(0x81+k));
                wrframe.data.append((char)0x0);
                wrframe.data.append((char)((uint8_t)sr35d_TimerList.at(k)->value()));
            }

            for(int k=0;k<sr35d_RelayList.length();k++)
            {
                wrframe.data.append((char)(0x89+3*k));
                wrframe.data.append((char)0x0);
                switch(sr35d_RelayList.at(k)->currentIndex())
                {
                    default:
                    case 0:
                      wrframe.data.append((char)0x0f);break;
                    case 1:
                      wrframe.data.append((char)0xf0);break;
                }
            }
            for(int k=0;k<sr35d_RelaySaveList.length();k++)
            {
                wrframe.data.append((char)(0x8A+3*k));
                wrframe.data.append((char)0x0);
                if(sr35d_RelaySaveList.at(k)->checkState() == Qt::Checked)
                {
                    wrframe.data.append((char)0xf0);
                }
                else
                {
                    wrframe.data.append((char)0x0f);
                }
            }

            wrframe.data.append((char)0xA0);
            wrframe.data.append((char)0x0);
            wrframe.data.append((char)((uint8_t)ui->sr35d_AddrDEC->value()));

            wrframe.data.append((char)0xA1);
            wrframe.data.append((char)0x0);
            wrframe.data.append(ui->sr35d_BaudRate->currentIndex());

            wrframe.data.append((char)0xA2);
            wrframe.data.append((char)0x0);
            if(ui->sr35d_ModbusEn->checkState() == Qt::Checked)
            {
                wrframe.data.append((char)0xf0);
            }
            else
            {
                wrframe.data.append((char)0x0f);
            }

            wrframe.data.append((char)0xA3);
            wrframe.data.append((char)0x0);
            switch(ui->sr35d_Parity->currentIndex())
            {
                default:
                case 0:
                  wrframe.data.append((char)0x0);break;
                case 1:
                  wrframe.data.append((char)0x0f);break;
                case 2:
                  wrframe.data.append((char)0xf0);break;
            }
            wrframe.length = wrframe.data.length();
            break;
        }
        case ModuleTypes_USRS485:
        {
            if  (ui->usrs485_ParamsEnable->isChecked() == false)
            {
                QMessageBox::information(NULL, tr("Внимание"),
                                       tr("Включите режим редактирования"));
                return;
            }
            wrframe.data.append((char)0xA0);
            wrframe.data.append((char)0x0);
            wrframe.data.append((char)((uint8_t)ui->usrs485_AddrDEC->value()));

            wrframe.data.append((char)0xA1);
            wrframe.data.append((char)0x0);
            wrframe.data.append(ui->usrs485_BaudRate->currentIndex());

            wrframe.data.append((char)0xA2);
            wrframe.data.append((char)0x0);
            if(ui->usrs485_ModbusEn->checkState() == Qt::Checked)
            {
                wrframe.data.append((char)0xf0);
            }
            else
            {
                wrframe.data.append((char)0x0f);
            }

            wrframe.data.append((char)0xA3);
            wrframe.data.append((char)0x0);
            switch(ui->usrs485_Parity->currentIndex())
            {
                default:
                case 0:
                  wrframe.data.append((char)0x0);break;
                case 1:
                  wrframe.data.append((char)0x0f);break;
                case 2:
                  wrframe.data.append((char)0xf0);break;
            }

            wrframe.length = wrframe.data.length();
            break;
        }
        case ModuleTypes_STR35D:
    {
        if  (ui->str35d_ParamsEnable->isChecked() == false)
        {
            QMessageBox::information(NULL, tr("Внимание"),
                                   tr("Включите режим редактирования"));
            return;
        }
        wrframe.data.append((char)0xA0);
        wrframe.data.append((char)0x0);
        wrframe.data.append((char)((uint8_t)ui->str35d_AddrDEC->value()));

        wrframe.data.append((char)0xA1);
        wrframe.data.append((char)0x0);
        wrframe.data.append(ui->str35d_BaudRate->currentIndex());

        wrframe.data.append((char)0xA2);
        wrframe.data.append((char)0x0);
        if(ui->str35d_ModbusEn->checkState() == Qt::Checked)
        {
            wrframe.data.append((char)0xf0);
        }
        else
        {
            wrframe.data.append((char)0x0f);
        }

        wrframe.data.append((char)0xA3);
        wrframe.data.append((char)0x0);
        switch(ui->str35d_Parity->currentIndex())
        {
            default:
            case 0:
              wrframe.data.append((char)0x0);break;
            case 1:
              wrframe.data.append((char)0x0f);break;
            case 2:
              wrframe.data.append((char)0xf0);break;
        }

        wrframe.length = wrframe.data.length();
        break;
    }
        case ModuleTypes_CSRS485:
        {
            if  (ui->csrs485_ParamsEnable->isChecked() == false)
            {
                QMessageBox::information(NULL, tr("Внимание"),
                                       tr("Включите режим редактирования"));
                return;
            }
            wrframe.data.append((char)0xA0);
            wrframe.data.append((char)0x0);
            wrframe.data.append((char)((uint8_t)ui->csrs485_AddrDEC->value()));

            wrframe.data.append((char)0xA1);
            wrframe.data.append((char)0x0);
            wrframe.data.append(ui->csrs485_BaudRate->currentIndex());

            wrframe.data.append((char)0xA2);
            wrframe.data.append((char)0x0);
            if(ui->csrs485_ModbusEn->checkState() == Qt::Checked)
            {
                wrframe.data.append((char)0xf0);
            }
            else
            {
                wrframe.data.append((char)0x0f);
            }

            wrframe.data.append((char)0xA3);
            wrframe.data.append((char)0x0);
            switch(ui->csrs485_Parity->currentIndex())
            {
                default:
                case 0:
                  wrframe.data.append((char)0x0);break;
                case 1:
                  wrframe.data.append((char)0x0f);break;
                case 2:
                  wrframe.data.append((char)0xf0);break;
            }

            wrframe.length = wrframe.data.length();
            break;
        }
        case ModuleTypes_VCRS485:
        {
            if  (ui->vcrs485_ParamsEnable->isChecked() == false)
            {
                QMessageBox::information(NULL, tr("Внимание"),
                                       tr("Включите режим редактирования"));
                return;
            }
            wrframe.data.append((char)0xA0);
            wrframe.data.append((char)0x0);
            wrframe.data.append((char)((uint8_t)ui->vcrs485_AddrDEC->value()));

            wrframe.data.append((char)0xA1);
            wrframe.data.append((char)0x0);
            wrframe.data.append(ui->vcrs485_BaudRate->currentIndex());

            wrframe.data.append((char)0xA2);
            wrframe.data.append((char)0x0);
            if(ui->vcrs485_ModbusEn->checkState() == Qt::Checked)
            {
                wrframe.data.append((char)0xf0);
            }
            else
            {
                wrframe.data.append((char)0x0f);
            }

            wrframe.data.append((char)0xA3);
            wrframe.data.append((char)0x0);
            switch(ui->vcrs485_Parity->currentIndex())
            {
                default:
                case 0:
                  wrframe.data.append((char)0x0);break;
                case 1:
                  wrframe.data.append((char)0x0f);break;
                case 2:
                  wrframe.data.append((char)0xf0);break;
            }

            wrframe.length = wrframe.data.length();
            break;
        }
        case ModuleTypes_ASC35D:
        {
            if  (ui->asc35d_ParamsEnable->isChecked() == false)
            {
                QMessageBox::information(NULL, tr("Внимание"),
                                       tr("Включите режим редактирования"));
                return;
            }
            wrframe.data.append((char)0xA0);
            wrframe.data.append((char)0x0);
            wrframe.data.append((char)((uint8_t)ui->asc35d_AddrDEC->value()));

            wrframe.data.append((char)0xA1);
            wrframe.data.append((char)0x0);
            wrframe.data.append(ui->asc35d_BaudRate->currentIndex());

            wrframe.data.append((char)0xA2);
            wrframe.data.append((char)0x0);
            if(ui->asc35d_ModbusEn->checkState() == Qt::Checked)
            {
                wrframe.data.append((char)0xf0);
            }
            else
            {
                wrframe.data.append((char)0x0f);
            }

            wrframe.data.append((char)0xA3);
            wrframe.data.append((char)0x0);
            switch(ui->asc35d_Parity->currentIndex())
            {
                default:
                case 0:
                  wrframe.data.append((char)0x0);break;
                case 1:
                  wrframe.data.append((char)0x0f);break;
                case 2:
                  wrframe.data.append((char)0xf0);break;
            }

            wrframe.length = wrframe.data.length();
            break;
        }
        case ModuleTypes_SVA35D:
        {
            if  (ui->sva35d_ParamsEnable->isChecked() == false)
            {
                QMessageBox::information(NULL, tr("Внимание"),
                                       tr("Включите режим редактирования"));
                return;
            }
            wrframe.data.append((char)0xA0);
            wrframe.data.append((char)0x0);
            wrframe.data.append((char)((uint8_t)ui->sva35d_AddrDEC->value()));

            wrframe.data.append((char)0xA1);
            wrframe.data.append((char)0x0);
            wrframe.data.append(ui->sva35d_BaudRate->currentIndex());

            wrframe.data.append((char)0xA2);
            wrframe.data.append((char)0x0);
            if(ui->sva35d_ModbusEn->checkState() == Qt::Checked)
            {
                wrframe.data.append((char)0xf0);
            }
            else
            {
                wrframe.data.append((char)0x0f);
            }

            wrframe.data.append((char)0xA3);
            wrframe.data.append((char)0x0);
            switch(ui->sva35d_Parity->currentIndex())
            {
                default:
                case 0:
                  wrframe.data.append((char)0x0);break;
                case 1:
                  wrframe.data.append((char)0x0f);break;
                case 2:
                  wrframe.data.append((char)0xf0);break;
            }

            wrframe.length = wrframe.data.length();
            break;
        }
        case ModuleTypes_SPC35D:
        {
            if  (ui->spc35d_ParamsEnable->isChecked() == false)
            {
                QMessageBox::information(NULL, tr("Внимание"),
                                       tr("Включите режим редактирования"));
                return;
            }
            wrframe.data.append((char)0xA0);
            wrframe.data.append((char)0x0);
            wrframe.data.append((char)((uint8_t)ui->spc35d_AddrDEC->value()));

            wrframe.data.append((char)0xA1);
            wrframe.data.append((char)0x0);
            wrframe.data.append(ui->spc35d_BaudRate->currentIndex());

            wrframe.data.append((char)0xA2);
            wrframe.data.append((char)0x0);
            if(ui->spc35d_ModbusEn->checkState() == Qt::Checked)
            {
                wrframe.data.append((char)0xf0);
            }
            else
            {
                wrframe.data.append((char)0x0f);
            }

            wrframe.data.append((char)0xA3);
            wrframe.data.append((char)0x0);
            switch(ui->spc35d_Parity->currentIndex())
            {
                default:
                case 0:
                  wrframe.data.append((char)0x0);break;
                case 1:
                  wrframe.data.append((char)0x0f);break;
                case 2:
                  wrframe.data.append((char)0xf0);break;
            }

            wrframe.length = wrframe.data.length();
            break;
        }
        default:
            break;
    }
    if (wrframe.length>0)
    {
        pollRequestFlag = true; //запрещаем отправление данных в цикле
        comP.queue.ClerQueueTxFrame();
        comP.queue.EnqueueTxFrame(wrframe);
        {
            writePassConnErr = 0;
            writeTimer = new QTimer(this);
            connect(writeTimer, SIGNAL(timeout()), this, SLOT(writeTimerTimeout()));
            writeTimer->start(300);
        }
    }
}

void MainWindow::writeTimerTimeout()
{
    bool wrError=true;
    if(writePassConnErr++ < 5)
    {
        portFrame frame = comP.queue.DequeueRxFrame();
        if(frame.TransmitStatus == TrmtStatus_EventSuccess)
        {
            if(frame.Function == Function_Read)
            {
                return;
            }
            else if(frame.Function == Function_Write)
            {
                if(frame.data == wrframe.data)
                    wrError = false;
            }
        }
        else if(frame.TransmitStatus == TrmtStatus_Unknown)
        {
            return;
        }
    }
    pollRequestFlag = false;
    if (wrError == false)
    {
        QMessageBox::information(NULL, tr("Внимание"),
                                   tr("Данные успешно записаны"));
    }
    else
    {
            QMessageBox::critical(NULL, tr("Внимание"),
                                   tr("Ошибка записи данных"));
    }

    //delete write timer
    writeTimer->deleteLater();
}

void MainWindow::on_sk35d_ParamsEnable_clicked(bool checked)
{
    if(checked == true)
        ui->sk35d_Params->setEnabled(true);
    else
        ui->sk35d_Params->setEnabled(false);
}

void MainWindow::on_svc35d_ParamsEnable_clicked(bool checked)
{
    if(checked == true)
        ui->svc35d_Params->setEnabled(true);
    else
        ui->svc35d_Params->setEnabled(false);
}
void MainWindow::on_sr35d_ParamsEnable_clicked(bool checked)
{
    if(checked == true)
        ui->sr35d_Params->setEnabled(true);
    else
        ui->sr35d_Params->setEnabled(false);
}

void MainWindow::on_usrs485_ParamsEnable_clicked(bool checked)
{
    if(checked == true)
        ui->usrs485_Params->setEnabled(true);
    else
        ui->usrs485_Params->setEnabled(false);
}

void MainWindow::on_str35d_ParamsEnable_clicked(bool checked)
{
    if(checked == true)
        ui->str35d_Params->setEnabled(true);
    else
        ui->str35d_Params->setEnabled(false);
}

void MainWindow::on_csrs485_ParamsEnable_clicked(bool checked)
{
    if(checked == true)
        ui->csrs485_Params->setEnabled(true);
    else
        ui->csrs485_Params->setEnabled(false);
}

void MainWindow::on_vcrs485_ParamsEnable_clicked(bool checked)
{
    if(checked == true)
        ui->vcrs485_Params->setEnabled(true);
    else
        ui->vcrs485_Params->setEnabled(false);
}

void MainWindow::on_asc35d_ParamsEnable_clicked(bool checked)
{
    if(checked == true)
        ui->asc35d_Params->setEnabled(true);
    else
        ui->asc35d_Params->setEnabled(false);
}

void MainWindow::on_sva35d_ParamsEnable_clicked(bool checked)
{
    if(checked == true)
        ui->sva35d_Params->setEnabled(true);
    else
        ui->sva35d_Params->setEnabled(false);
}

void MainWindow::on_spc35d_ParamsEnable_clicked(bool checked)
{
    if(checked == true)
        ui->spc35d_Params->setEnabled(true);
    else
        ui->spc35d_Params->setEnabled(false);
}


void MainWindow::sk35d_DisconnectedDataSet()
{
    foreach(QCheckBox *status, sk35d_StatusList)
    {
        checkboxStatusColorSet(status, Qt::gray);
    }
    if  (ui->sk35d_ParamsEnable->isChecked() == false)
    {
        foreach(QCheckBox *type, sk35d_TypeList)
        {
            type->setChecked(false);
        }
        ui->sk35d_ModbusEn->setChecked(false);
        ui->sk35d_BaudRate->setCurrentIndex(5);
        ui->sk35d_Parity->setCurrentIndex(2);
        ui->sk35d_AddrDEC->setValue(0);
        ui->sk35d_Timer->setValue(0);
        ui->sk35d_Relay1->setCurrentText("");
        ui->sk35d_Relay1Save->setChecked(false);
        ui->sk35d_Relay2->setCurrentText("");
        ui->sk35d_Relay2Save->setChecked(false);
    }
}

void MainWindow::svc35d_DisconnectedDataSet()
{
    foreach(QCheckBox *status, svc35d_StatusList)
    {
        checkboxStatusColorSet(status, Qt::gray);
    }
    if  (ui->svc35d_ParamsEnable->isChecked() == false)
    {
        foreach(QCheckBox *type, svc35d_TypeList)
        {
            type->setChecked(false);
        }
        ui->svc35d_ModbusEn->setChecked(false);
        ui->svc35d_BaudRate->setCurrentIndex(5);
        ui->svc35d_Parity->setCurrentIndex(2);
        ui->svc35d_AddrDEC->setValue(0);
        ui->svc35d_Timer->setValue(0);
        ui->svc35d_Relay1->setCurrentText("");
        ui->svc35d_Relay1Save->setChecked(false);
    }
}

void MainWindow::sr35d_DisconnectedDataSet()
{
    foreach(QCheckBox *status, sr35d_StatusList)
    {
        checkboxStatusColorSet(status, Qt::gray);
    }
    if  (ui->sr35d_ParamsEnable->isChecked() == false)
    {
        foreach(QCheckBox *type, sr35d_TypeList)
        {
            type->setChecked(false);
        }
        ui->sr35d_ModbusEn->setChecked(false);
        ui->sr35d_BaudRate->setCurrentIndex(5);
        ui->sr35d_Parity->setCurrentIndex(2);
        ui->sr35d_AddrDEC->setValue(0);
        foreach (QSpinBox* tm, sr35d_TimerList)
        {
            tm->setValue(0);
        }
        foreach (QComboBox* rl, sr35d_RelayList)
        {
            rl->setCurrentIndex(0);
        };
        foreach(QCheckBox *rtype, sr35d_RelaySaveList)
        {
            rtype->setChecked(false);
        }
    }
}

void MainWindow::usrs485_DisconnectedDataSet()
{
    ui->usrs485_Temp->setText("");
    ui->usrs485_Hum->setText("");
    ui->usrs485_Dew->setText("");
    ui->usrs485_Press->setText("");
    ui->usrs485_Volt->setText("");
    if  (ui->usrs485_ParamsEnable->isChecked() == false)
    {
        ui->usrs485_ModbusEn->setChecked(false);
        ui->usrs485_BaudRate->setCurrentIndex(5);
        ui->usrs485_Parity->setCurrentIndex(2);
        ui->usrs485_AddrDEC->setValue(0);

    }
}

void MainWindow::str35d_DisconnectedDataSet()
{
    foreach(QLineEdit *val, str35d_TempList)
    {
        val->setText("");
    }
    foreach(QLineEdit *val, str35d_HumList)
    {
        val->setText("");
    }
    foreach(QLineEdit *val, str35d_DewList)
    {
        val->setText("");
    }
    foreach(QLineEdit *val, str35d_PressList)
    {
        val->setText("");
    }
    foreach(QLineEdit *val, str35d_CO2List)
    {
        val->setText("");
    }

    if  (ui->str35d_ParamsEnable->isChecked() == false)
    {
        ui->str35d_ModbusEn->setChecked(false);
        ui->str35d_BaudRate->setCurrentIndex(5);
        ui->str35d_Parity->setCurrentIndex(2);
        ui->str35d_AddrDEC->setValue(0);
    }
}

void MainWindow::csrs485_DisconnectedDataSet()
{
    ui->csrs485_CO2->setText("");
    ui->csrs485_Heat->setVisible(false);
    if  (ui->csrs485_ParamsEnable->isChecked() == false)
    {
        ui->csrs485_ModbusEn->setChecked(false);
        ui->csrs485_BaudRate->setCurrentIndex(5);
        ui->csrs485_Parity->setCurrentIndex(2);
        ui->csrs485_AddrDEC->setValue(0);
    }
}

void MainWindow::vcrs485_DisconnectedDataSet()
{
    ui->vcrs485_Volt->setText("");
    ui->vcrs485_AnK->setText("");
    ui->vcrs485_Dim->setText("");
    ui->vcrs485_Dia->setText("");
    ui->vcrs485_Over->setVisible(false);
    ui->vcrs485_Volt_2->setText("");
    ui->vcrs485_AnK_2->setText("");
    ui->vcrs485_Dim_2->setText("");
    ui->vcrs485_Dia_2->setText("");
    ui->vcrs485_Over_2->setVisible(false);
    if  (ui->vcrs485_ParamsEnable->isChecked() == false)
    {
        ui->vcrs485_ModbusEn->setChecked(false);
        ui->vcrs485_BaudRate->setCurrentIndex(5);
        ui->vcrs485_Parity->setCurrentIndex(2);
        ui->vcrs485_AddrDEC->setValue(0);
    }
}

void MainWindow::asc35d_DisconnectedDataSet()
{
    ui->asc35d_Volt_1->setText("");
    ui->asc35d_Volt_2->setText("");
    ui->asc35d_Dia_1->setText("");
    ui->asc35d_Dia_2->setText("");
    ui->asc35d_AnK_1->setText("");
    ui->asc35d_AnK_2->setText("");
    ui->asc35d_Dim_1->setText("");
    ui->asc35d_Dim_2->setText("");
    ui->asc35d_Curr_1->setText("");
    ui->asc35d_Curr_2->setText("");
    ui->asc35d_420_1->setText("");
    ui->asc35d_420_2->setText("");
    ui->asc35d_420_3->setText("");
    ui->asc35d_420_4->setText("");
    ui->asc35d_420Dim_1->setText("");
    ui->asc35d_420Dim_2->setText("");
    ui->asc35d_420Dim_3->setText("");
    ui->asc35d_420Dim_4->setText("");

    if  (ui->asc35d_ParamsEnable->isChecked() == false)
    {
        ui->asc35d_ModbusEn->setChecked(false);
        ui->asc35d_BaudRate->setCurrentIndex(5);
        ui->asc35d_Parity->setCurrentIndex(2);
        ui->asc35d_AddrDEC->setValue(0);
    }
}

void MainWindow::sva35d_DisconnectedDataSet()
{
    for(int n=0;n<ui->sva35dData->rowCount();n++)
    {
        ui->sva35dData->item(n,2)->setText("");
    }
    for(int n=0;n<4;n++)
    {
        sva35dCalibData[n]="";
    }

    if  (ui->sva35d_ParamsEnable->isChecked() == false)
    {
        ui->sva35d_ModbusEn->setChecked(false);
        ui->sva35d_BaudRate->setCurrentIndex(5);
        ui->sva35d_Parity->setCurrentIndex(2);
        ui->sva35d_AddrDEC->setValue(0);
    }
}

void MainWindow::spc35d_DisconnectedDataSet()
{
    for(int n=0;n<ui->spc35dData->rowCount();n++)
    {
        ui->spc35dData->item(n,2)->setText("");
    }
    if  (ui->spc35d_ParamsEnable->isChecked() == false)
    {
        ui->spc35d_ModbusEn->setChecked(false);
        ui->spc35d_BaudRate->setCurrentIndex(5);
        ui->spc35d_Parity->setCurrentIndex(2);
        ui->spc35d_AddrDEC->setValue(0);
    }
}





void MainWindow::onTabWidget_Changed(int index)
{
    ModuleType = index;
    ui->moduleConnectStatus->setText(ConstStings::disconnected);
    QPalette palette = ui->moduleConnectStatus->palette();
    palette.setColor(QPalette::WindowText, Qt::red);
    ui->moduleConnectStatus->setPalette(palette);
    tabWasChanged=true;
}

void MainWindow::onModuleN_Changed(int value)
{
    tabWasChanged=true;
}


void MainWindow::on_sk35d_AddrDEC_valueChanged(int arg1)
{
    ui->sk35d_AddrHEX->setText("0x"+QString::number(arg1,16));
}

void MainWindow::on_svc35d_AddrDEC_valueChanged(int arg1)
{
    ui->svc35d_AddrHEX->setText("0x"+QString::number(arg1,16));
}

void MainWindow::on_sr35d_AddrDEC_valueChanged(int arg1)
{
    ui->sr35d_AddrHEX->setText("0x"+QString::number(arg1,16));
}

void MainWindow::on_usrs485_AddrDEC_valueChanged(int arg1)
{
    ui->usrs485_AddrHEX->setText("0x"+QString::number(arg1,16));
}

void MainWindow::on_str35d_AddrDEC_valueChanged(int arg1)
{
    ui->str35d_AddrHEX->setText("0x"+QString::number(arg1,16));
}

void MainWindow::on_csrs485_AddrDEC_valueChanged(int arg1)
{
    ui->csrs485_AddrHEX->setText("0x"+QString::number(arg1,16));
}

void MainWindow::on_vcrs485_AddrDEC_valueChanged(int arg1)
{
    ui->vcrs485_AddrHEX->setText("0x"+QString::number(arg1,16));
}

void MainWindow::on_asc35d_AddrDEC_valueChanged(int arg1)
{
    ui->asc35d_AddrHEX->setText("0x"+QString::number(arg1,16));
}

void MainWindow::on_sva35d_AddrDEC_valueChanged(int arg1)
{
    ui->sva35d_AddrHEX->setText("0x"+QString::number(arg1,16));
}

void MainWindow::on_spc35d_AddrDEC_valueChanged(int arg1)
{
    ui->spc35d_AddrHEX->setText("0x"+QString::number(arg1,16));
}


void MainWindow::onMenu_PortOpen()
{
    QString portName;
    PortSelect *ps = new PortSelect(this);
    ps->exec();
    if(ps->apply==true)
    {
        portName = ps->portName;
        comP.PortTransmitOpen(portName);
    }
    ps->deleteLater();
}



void MainWindow::onMenu_PortClose()
{
    comP.PortCloseRequest(true);
}

void MainWindow::on_sr35d_ConfigButton_clicked()
{

 /*   if(ModuleConnected == false)
    {
        QMessageBox::information(NULL, tr("Внимание"),
                               tr("Отсутствует соединение с модулем"));
        return;
    }
*/
    SR_Control *sr = new SR_Control(this);
    sr->SR_DataLoad(&comP, &pollRequestFlag, ModuleAddress);
}

void MainWindow::on_csrs485_Config_clicked()
{
    if(ModuleConnected == false)
    {
        QMessageBox::information(NULL, tr("Внимание"),
                               tr("Отсутствует соединение с датчиком"));
        return;
    }

    CSRS485_Config *cfg = new CSRS485_Config(this);
    cfg->DataLoad(&comP, &pollRequestFlag, ModuleAddress);
}

void MainWindow::on_csrs485_Caibrate_clicked()
{
    if(ModuleConnected == false)
    {
        QMessageBox::information(NULL, tr("Внимание"),
                               tr("Отсутствует соединение с датчиком"));
        return;
    }

    CSRS485_Calib *calib = new CSRS485_Calib(this);
    calib->DataLoad(&comP, &pollRequestFlag, ModuleAddress);
}


void MainWindow::on_vcrs485_Config_clicked()
{
    if(ModuleConnected == false)
    {
        QMessageBox::information(NULL, tr("Внимание"),
                               tr("Отсутствует соединение с датчиком"));
        return;
    }

    VCRS485_Config *cfg = new VCRS485_Config(this);
    cfg->DataLoad(&comP, &pollRequestFlag, ModuleAddress);
}

void MainWindow::on_vcrs485_Caibrate_clicked()
{
    if(ModuleConnected == false)
    {
        QMessageBox::information(NULL, tr("Внимание"),
                               tr("Отсутствует соединение с датчиком"));
        return;
    }

    VCRS485_Calib *calib = new VCRS485_Calib(this);
    calib->DataLoad(&comP, &pollRequestFlag, ModuleAddress);
}


void MainWindow::on_asc35d_Config_clicked()
{
    if(ModuleConnected == false)
    {
        QMessageBox::information(NULL, tr("Внимание"),
                               tr("Отсутствует соединение с модудем"));
        return;
    }

    ASC35D_Config *cfg = new ASC35D_Config(this);
    cfg->DataLoad(&comP, &pollRequestFlag, ModuleAddress);
}

void MainWindow::on_asc35d_Caibrate_clicked()
{
    if(ModuleConnected == false)
    {
        QMessageBox::information(NULL, tr("Внимание"),
                               tr("Отсутствует соединение с модудем"));
        return;
    }

    ASC35D_Calib *cfg = new ASC35D_Calib(this);
    cfg->DataLoad(&comP, &pollRequestFlag, ModuleAddress);
}

void MainWindow::on_sva35d_Config_clicked()
{
    if(ModuleConnected == false)
    {
        QMessageBox::information(NULL, tr("Внимание"),
                               tr("Отсутствует соединение с модудем"));
        return;
    }

    SVA35D_Config *cfg = new SVA35D_Config(this);
    cfg->DataLoad(&comP, &pollRequestFlag, ModuleAddress);
}

void MainWindow::on_sva35d_Caibrate_clicked()
{
  if(ModuleConnected == false)
    {
        QMessageBox::information(NULL, tr("Внимание"),
                               tr("Отсутствует соединение с модудем"));
        return;
    }

    SVA35D_Calib *cfg = new SVA35D_Calib(this);
    for (int n=0;n<4;n++)
    {
        cfg->sva35dCalibData[n] = &sva35dCalibData[n];
    }
    cfg->DataLoad(&comP, &pollRequestFlag, ModuleAddress);
}



void MainWindow::on_spc35d_Caibrate_clicked()
{
    if(ModuleConnected == false)
    {
        QMessageBox::information(NULL, tr("Внимание"),
                               tr("Отсутствует соединение с модудем"));
        return;
    }

    SPC35D_Config *cfg = new SPC35D_Config(this);
    cfg->DataLoad(&comP, &pollRequestFlag, ModuleAddress);
}

void MainWindow::onMenu_About()
{
    about *ab = new about(this);
    ab->open();
}
