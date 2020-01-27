#ifndef ASC35D_CONFIG_H
#define ASC35D_CONFIG_H

#include <QTimer>
#include <QMessageBox>
#include <QDialog>
#include "comthread.h"

namespace Ui {
class ASC35D_Config;
}

class ASC35D_Config : public QDialog
{
    Q_OBJECT

public:
    explicit ASC35D_Config(QWidget *parent = nullptr);
    ~ASC35D_Config();
    void DataLoad(ComPortTransmit *comPort, bool *RequesrFlag, uint8_t maddress);



private slots:
    void pollTimerTimeout();


    void on_ASC35D_Config_finished(int result);

    void on_Cancel_clicked();

    void on_i_Write_1_clicked();

    void on_i_Write_2_clicked();

    void on_i_Write_3_clicked();

    void on_i_Write_4_clicked();

    void on_dWrite_1_clicked();

    void on_dWrite_2_clicked();

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

    Ui::ASC35D_Config *ui;
};

#endif // ASC35D_CONFIG_H
