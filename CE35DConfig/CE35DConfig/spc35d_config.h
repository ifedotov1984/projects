#ifndef SPC35D_CONFIG_H
#define SPC35D_CONFIG_H


#include <QTimer>
#include <QMessageBox>
#include <QDialog>
#include "comthread.h"

namespace Ui {
class SPC35D_Config;
}

class SPC35D_Config : public QDialog
{
    Q_OBJECT

public:
    explicit SPC35D_Config(QWidget *parent = nullptr);
    ~SPC35D_Config();

    void DataLoad(ComPortTransmit *comPort, bool *RequesrFlag, uint8_t maddress);


private slots:
    void pollTimerTimeout();


    void on_addrWrite_clicked();

    void on_passwWrite_clicked();

    void on_SPC35D_Config_finished(int result);

    void on_Cancel_clicked();

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

    Ui::SPC35D_Config *ui;
};

#endif // SPC35D_CONFIG_H
