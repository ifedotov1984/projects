#ifndef SVA35D_CALIB_H
#define SVA35D_CALIB_H


#include <QTimer>
#include <QString>
#include <QMessageBox>
#include <QDialog>
#include "comthread.h"


namespace Ui {
class SVA35D_Calib;
}

class SVA35D_Calib : public QDialog
{
    Q_OBJECT

public:
    explicit SVA35D_Calib(QWidget *parent = nullptr);
    ~SVA35D_Calib();

    void DataLoad(ComPortTransmit *comPort, bool *RequesrFlag, uint8_t maddress);
    QString *sva35dCalibData[4];

private slots:
    void pollTimerTimeout();
    void updateTimerTimeout();


    void on_TempWrite_clicked();

    void on_offsetWrite_clicked();

    void on_vWrite_clicked();

    void on_cWrite_clicked();

    void on_checkWrite_clicked();

    void on_aWrite_1_clicked();

    void on_aWrite_2_clicked();

    void on_aWrite_3_clicked();

    void on_Save_clicked();

    void on_Write_clicked();

    void on_SVA35D_Calib_finished(int result);

    void on_Cancel_clicked();

private:
    ComPortTransmit *comP;
    bool *pollRequestFlag;
    uint8_t ModuleAddress;
    QTimer *pollTimer;
    QTimer *updateTimer;
    int pollTimerQuant;
    portFrame wrframe;
    bool busyWaitMessage();


    Ui::SVA35D_Calib *ui;
};

#endif // SVA35D_CALIB_H
