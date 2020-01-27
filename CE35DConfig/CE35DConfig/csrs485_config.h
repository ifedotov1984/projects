#ifndef CSRS485_CONFIG_H
#define CSRS485_CONFIG_H

#include <QTimer>
#include <QMessageBox>
#include <QDialog>
#include "comthread.h"



namespace Ui {
class CSRS485_Config;
}

class CSRS485_Config : public QDialog
{
    Q_OBJECT

public:
    explicit CSRS485_Config(QWidget *parent = nullptr);
    ~CSRS485_Config();

    void DataLoad(ComPortTransmit *comPort, bool *RequesrFlag, uint8_t maddress);
    void DataRequest();

private slots:
    void pollTimerTimeout();


    void on_dWrite_clicked();

    void on_dWrite_2_clicked();

    void on_Cancel_clicked();

    void on_CSRS485_Config_finished(int result);

private:
    ComPortTransmit *comP;
    bool *pollRequestFlag;
    uint8_t ModuleAddress;
    QTimer *pollTimer;
    int pollTimerQuant;
    portFrame wrframe;
    bool isOpened;
    bool busyWaitMessage();


    Ui::CSRS485_Config *ui;
};

#endif // CSRS485_CONFIG_H
