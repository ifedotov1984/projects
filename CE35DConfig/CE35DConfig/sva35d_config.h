#ifndef SVA35D_CONFIG_H
#define SVA35D_CONFIG_H

#include <QTimer>
#include <QMessageBox>
#include <QDialog>
#include "comthread.h"

namespace Ui {
class SVA35D_Config;
}

class SVA35D_Config : public QDialog
{
    Q_OBJECT

public:
    explicit SVA35D_Config(QWidget *parent = nullptr);
    ~SVA35D_Config();

    void DataLoad(ComPortTransmit *comPort, bool *RequesrFlag, uint8_t maddress);
    void DataRequest();

private slots:
    void pollTimerTimeout();

    void on_vWrite_clicked();

    void on_iWrite_clicked();

    void on_Cancel_clicked();

    void on_SVA35D_Config_finished(int result);

private:
    ComPortTransmit *comP;
    bool *pollRequestFlag;
    uint8_t ModuleAddress;
    QTimer *pollTimer;
    int pollTimerQuant;
    portFrame wrframe;
    bool isOpened;
    bool busyWaitMessage();


    Ui::SVA35D_Config *ui;
};

#endif // SVA35D_CONFIG_H
