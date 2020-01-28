#ifndef ASC35D_CALIB_H
#define ASC35D_CALIB_H

#include <QTimer>
#include <QMessageBox>
#include <QDialog>
#include "comthread.h"

namespace Ui {
class ASC35D_Calib;
}

class ASC35D_Calib : public QDialog
{
    Q_OBJECT

public:
    explicit ASC35D_Calib(QWidget *parent = nullptr);
    ~ASC35D_Calib();
    void DataLoad(ComPortTransmit *comPort, bool *RequesrFlag, uint8_t maddress);
    void DataRequest();

private slots:
    void pollTimerTimeout();
    void on_Cancel_clicked();
    void UpdateVoltChecks(int);
    void on_ASC35D_Calib_finished(int result);

    void on_v_diaWrite_clicked();

    void on_v_upWrite_clicked();

    void on_v_dwnWrite_clicked();

    void on_v_Calibrate_clicked();

    void on_avgWrite_clicked();

    void on_pswWrite_clicked();

    void on_i_zWrite_clicked();

    void on_i_Write_clicked();

    void on_i_Calibrate_clicked();

    void on_c_dwnWrite_clicked();

    void on_c_Calibrate_clicked();

    void on_c_upWrite_clicked();

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


    Ui::ASC35D_Calib *ui;
};

#endif // ASC35D_CALIB_H
