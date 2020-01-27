#include "portselect.h"
#include "ui_portselect.h"

PortSelect::PortSelect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PortSelect)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint);

    portName = "";

    QList<QSerialPortInfo> spiList = QSerialPortInfo::availablePorts();
    foreach(QSerialPortInfo spi, spiList)
    {
        ui->comboBox->addItem(spi.portName());
    }
    apply = false;

}

PortSelect::~PortSelect()
{
    delete ui;
}

void PortSelect::on_Cancel_clicked()
{
    this->close();
}

void PortSelect::on_Submit_clicked()
{
    portName = ui->comboBox->itemText(ui->comboBox->currentIndex());
    this->close();
    apply = true;
}

