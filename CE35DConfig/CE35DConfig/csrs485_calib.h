#ifndef CSRS485_CALIB_H
#define CSRS485_CALIB_H

#include <QTimer>
#include <QMessageBox>
#include <QDialog>
#include "comthread.h"



namespace Ui {
class CSRS485_Calib;
}

class CSRS485_Calib : public QDialog
{
    Q_OBJECT

public:
    explicit CSRS485_Calib(QWidget *parent = nullptr);
    ~CSRS485_Calib();

    void DataLoad(ComPortTransmit *comPort, bool *RequesrFlag, uint8_t maddress);

private slots:
    void pollTimerTimeout();
    void on_Cancel_clicked();
    void on_CSRS485_Calib_finished(int result);
    void on_CalibZ_clicked();
    void on_CalibV_clicked();
    void on_Write_clicked();

private:
    ComPortTransmit *comP;
    bool *pollRequestFlag;
    uint8_t ModuleAddress;
    QTimer *pollTimer;
    int pollTimerQuant;
    portFrame wrframe;
    bool busyWaitMessage();


    Ui::CSRS485_Calib *ui;
};

#endif // CSRS485_CALIB_H
