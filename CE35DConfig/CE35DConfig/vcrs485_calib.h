#ifndef VCRS485_CALIB_H
#define VCRS485_CALIB_H

#include <QTimer>
#include <QMessageBox>
#include <QDialog>
#include "comthread.h"

namespace Ui {
class VCRS485_Calib;
}

class VCRS485_Calib : public QDialog
{
    Q_OBJECT

public:
    explicit VCRS485_Calib(QWidget *parent = nullptr);
    ~VCRS485_Calib();
    void DataLoad(ComPortTransmit *comPort, bool *RequesrFlag, uint8_t maddress);
    void DataRequest();

private slots:
    void on_VCRS485_Calib_finished(int result);
    void pollTimerTimeout();
    void on_Cancel_clicked();
    void UpdateVoltChecks(int);

    void on_diaWrite_clicked();

    void on_upWrite_clicked();

    void on_dwnWrite_clicked();

    void on_Calibrate_clicked();

    void on_avgWrite_clicked();

    void on_pswWrite_clicked();

private:
    ComPortTransmit *comP;
    bool *pollRequestFlag;
    uint8_t ModuleAddress;
    QTimer *pollTimer;
    int pollTimerQuant;
    portFrame wrframe;
    uint8_t scaleVcoeff[2];
    bool isOpened;
    bool busyWaitMessage();


    Ui::VCRS485_Calib *ui;
};

#endif // VCRS485_CALIB_H
