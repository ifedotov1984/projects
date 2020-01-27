#ifndef PORTSELECT_H
#define PORTSELECT_H

#include <QDialog>
#include <QString>
#include <QSerialPortInfo>

namespace Ui {
class PortSelect;
}

class PortSelect : public QDialog
{
    Q_OBJECT

public:
    explicit PortSelect(QWidget *parent = nullptr);
    ~PortSelect();
    QString portName;
    bool apply;

private slots:
    void on_Cancel_clicked();

    void on_Submit_clicked();

private:
    Ui::PortSelect *ui;
};

#endif // PORTSELECT_H
