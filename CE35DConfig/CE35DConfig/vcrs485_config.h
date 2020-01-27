#ifndef VCRS485_CONFIG_H
#define VCRS485_CONFIG_H

#include <QTimer>
#include <QMessageBox>
#include <QDialog>
#include "comthread.h"

namespace Ui {
class VCRS485_Config;
}

class VCRS485_Config : public QDialog
{
    Q_OBJECT

public:
    explicit VCRS485_Config(QWidget *parent = nullptr);
    ~VCRS485_Config();

    void DataLoad(ComPortTransmit *comPort, bool *RequesrFlag, uint8_t maddress);


private slots:
    void pollTimerTimeout();


    void on_dWrite_clicked();

    void on_dWrite_2_clicked();

    void on_Cancel_clicked();


    void on_VCRS485_Config_finished(int result);

private:
    ComPortTransmit *comP;
    bool *pollRequestFlag;
    uint8_t ModuleAddress;
    QTimer *pollTimer;
    int pollTimerQuant;
    portFrame wrframe;
    bool isOpened;
    bool busyWaitMessage();
    void DataRequest();

    Ui::VCRS485_Config *ui;
};

#endif // VCRS485_CONFIG_H
