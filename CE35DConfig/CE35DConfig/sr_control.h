#ifndef SR_CONTROL_H
#define SR_CONTROL_H

#include <QDialog>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QGroupBox>
#include <QTimer>
#include <QMessageBox>
#include "comthread.h"

namespace Ui {
class SR_Control;
}

class SR_Control : public QDialog
{
    Q_OBJECT

public:
    explicit SR_Control(QWidget *parent = nullptr);
    ~SR_Control();
    void SR_DataLoad(ComPortTransmit *comPort, bool *RequesrFlag, uint8_t maddress);
    void DataRequest();

private:
    QList<QComboBox *> RelaysList;
    QList<QCheckBox *> TypeList;
    ComPortTransmit *comP;
    bool *pollRequestFlag;
    uint8_t ModuleAddress;
    QTimer *pollTimer;
    int pollTimerQuant;
    portFrame wrframe;
    bool isOpened;
    bool busyWaitMessage();


    Ui::SR_Control *ui;

private slots:
    void pollTimerTimeout();
    void on_SR_Control_finished(int result);
    void on_Cancel_clicked();
    void on_Write_clicked();
};

#endif // SR_CONTROL_H
