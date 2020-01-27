#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QString>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QLineEdit>
#include <QTimer>
#include <QBitArray>
#include <QMessageBox>
#include "comthread.h"

namespace ConstStings
{
    const QString disconnected = QT_TR_NOOP("Модуль отключен");
    const QString connected = QT_TR_NOOP("Модуль подключен");
    const QString noSN = "-- -- ----";
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}
QT_END_NAMESPACE

enum ModuleTypes //должно соответствовать порядку следования табов на форме
{
    ModuleTypes_SK35D       =    (0),
    ModuleTypes_SVC35D      =    (1),
    ModuleTypes_SR35D       =    (2),
    ModuleTypes_USRS485     =    (3),
    ModuleTypes_CSRS485     =    (4),
    ModuleTypes_STR35D      =    (5),
    ModuleTypes_VCRS485     =    (6),
    ModuleTypes_ASC35D      =    (7),
    ModuleTypes_SVA35D      =    (8),
    ModuleTypes_SPC35D      =    (9),
};

enum ModuleBaseAddress
{
    ModuleBaseAddress_SK35D    =    (0x10),
    ModuleBaseAddress_SVC35D   =    (0x20),
    ModuleBaseAddress_SR35D    =    (0x90),
    ModuleBaseAddress_USRS485  =    (0x80),
    ModuleBaseAddress_STR35D   =    (0x40),
    ModuleBaseAddress_CSRS485  =    (0x88),
    ModuleBaseAddress_VCRS485  =    (0xB0),
    ModuleBaseAddress_ASC35D   =    (0xA0),
    ModuleBaseAddress_SVA35D   =    (0x60),
    ModuleBaseAddress_SPC35D   =    (0x50),
};




class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool pollBusyFlag;
    bool pollRequestFlag;

private slots:
    void on_sk35d_ParamsEnable_clicked(bool);
    void pollTimerTimeout();
    void writeTimerTimeout();
    void onTabWidget_Changed(int index);
    void onModuleN_Changed(int);
    void on_sk35d_AddrDEC_valueChanged(int arg1);
    void on_svc35d_ParamsEnable_clicked(bool checked);
    void on_svc35d_AddrDEC_valueChanged(int arg1);

    void on_sr35d_ParamsEnable_clicked(bool checked);
    void on_sr35d_ConfigButton_clicked();
    void on_sr35d_AddrDEC_valueChanged(int arg1);
    void on_usrs485_AddrDEC_valueChanged(int arg1);
    void on_usrs485_ParamsEnable_clicked(bool checked);
    void on_str35d_ParamsEnable_clicked(bool checked);


    void on_str35d_AddrDEC_valueChanged(int arg1);

    void on_csrs485_AddrDEC_valueChanged(int arg1);

    void on_csrs485_ParamsEnable_clicked(bool checked);

    void on_csrs485_Config_clicked();

    void on_csrs485_Caibrate_clicked();

    void on_vcrs485_ParamsEnable_clicked(bool checked);

    void on_vcrs485_AddrDEC_valueChanged(int arg1);

    void on_vcrs485_Config_clicked();

    void on_vcrs485_Caibrate_clicked();

    void onWriteButton_Click();


    void on_asc35d_ParamsEnable_clicked(bool checked);

    void on_asc35d_AddrDEC_valueChanged(int arg1);

    void on_asc35d_Config_clicked();

    void on_asc35d_Caibrate_clicked();

    void on_sva35d_ParamsEnable_clicked(bool checked);

    void on_sva35d_AddrDEC_valueChanged(int arg1);

    void on_sva35d_Config_clicked();

    void on_sva35d_Caibrate_clicked();

    void on_spc35d_AddrDEC_valueChanged(int arg1);

    void on_spc35d_ParamsEnable_clicked(bool checked);

    void on_spc35d_Caibrate_clicked();

    void onMenu_PortOpen();
    void onMenu_PortClose();
    void onMenu_About();

private:
    void checkboxStatusColorSet(QCheckBox *cb, QColor color);
    void sk35d_DisconnectedDataSet();
    void svc35d_DisconnectedDataSet();
    void sr35d_DisconnectedDataSet();
    void usrs485_DisconnectedDataSet();
    void str35d_DisconnectedDataSet();
    void csrs485_DisconnectedDataSet();
    void vcrs485_DisconnectedDataSet();
    void asc35d_DisconnectedDataSet();
    void sva35d_DisconnectedDataSet();
    void spc35d_DisconnectedDataSet();

    QLabel *SNlabel;
    ComPortTransmit comP;
    //SK-35D
    QList<QCheckBox *> sk35d_TypeList;
    QList<QCheckBox *> sk35d_StatusList;
    //SVC-35D
    QList<QCheckBox *> svc35d_TypeList;
    QList<QCheckBox *> svc35d_StatusList;
    //SR-35D
    QList<QComboBox *> sr35d_RelayList;
    QList<QCheckBox *> sr35d_RelaySaveList;
    QList<QCheckBox *> sr35d_TypeList;
    QList<QCheckBox *> sr35d_StatusList;
    QList<QSpinBox *> sr35d_TimerList;
    //USRS485
    bool firstReq_usrs485;
    bool voltReq_usrs485;
    //STR-35D
    QList<QLineEdit *> str35d_TempList;
    QList<QLineEdit *> str35d_HumList;
    QList<QLineEdit *> str35d_DewList;
    QList<QLineEdit *> str35d_PressList;
    QList<QLineEdit *> str35d_CO2List;
    bool firstReq_str35d;
    bool secondReq_str35d;
    char str35dtempstatus[8];
    char str35dhumstatus[8];
    char str35dpressurestatus[8];
    char str35dco2status[8];
    //VC-RS485
    uint8_t vcrs485_template_an[2];
    //ASC-35D
    uint8_t asc35d_status_cloop[4];
    uint8_t asc35d_template_cloop[4];
    uint8_t asc35d_template_an[2];
    //SVA-35D
    QString sva35dCalibData[4];
    //SPC-35D
    bool firstReq_spc35d;




    QTimer *pollTimer;
    QTimer *writeTimer;
    int ModuleType;
    uint8_t ModuleAddress;
    bool ModuleConnected;
    bool tabWasChanged;
    int passConnErr;
    int writePassConnErr;
    portFrame wrframe;

    Ui::MainWindow *ui;


};









#endif // MAINWINDOW_H
