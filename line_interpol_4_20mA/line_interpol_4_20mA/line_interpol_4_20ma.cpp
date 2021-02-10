#include "line_interpol_4_20mA.h"
#include "ui_line_interpol_4_20mA.h"

line_interpol_4_20mA::line_interpol_4_20mA(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::line_interpol_4_20mA)
{
    ui->setupUi(this);
    connect(ui->Y0Edit, SIGNAL(cursorPositionChanged(int, int)), this, SLOT(onData_Changed()));
    connect(ui->Y0Box_X, SIGNAL(valueChanged(int)), this, SLOT(onData_Changed()));
    connect(ui->Y1Edit, SIGNAL(cursorPositionChanged(int, int)), this, SLOT(onData_Changed()));
    connect(ui->Y1Box_X, SIGNAL(valueChanged(int)), this, SLOT(onData_Changed()));
    connect(ui->X0Edit, SIGNAL(cursorPositionChanged(int, int)), this, SLOT(onData_Changed()));
    connect(ui->X0Box_X, SIGNAL(valueChanged(int)), this, SLOT(onData_Changed()));
    connect(ui->X1Edit, SIGNAL(cursorPositionChanged(int, int)), this, SLOT(onData_Changed()));
    connect(ui->X1Box_X, SIGNAL(valueChanged(int)), this, SLOT(onData_Changed()));
    connect(ui->I0Box, SIGNAL(valueChanged(int)), this, SLOT(onData_Changed()));
    connect(ui->I1Box, SIGNAL(valueChanged(int)), this, SLOT(onData_Changed()));
    connect(ui->ZBox_X, SIGNAL(valueChanged(int)), this, SLOT(onData_Changed()));
}

line_interpol_4_20mA::~line_interpol_4_20mA()
{
    delete ui;
}

void line_interpol_4_20mA::onData_Changed(void)
{
    double y0 = ui->Y0Edit->text().toDouble();
    double y0x = ui->Y0Box_X->text().toDouble();
    double y1 = ui->Y1Edit->text().toDouble();
    double y1x = ui->Y1Box_X->text().toDouble();

    double x0 = ui->X0Edit->text().toDouble();
    double x0x = ui->X0Box_X->text().toDouble();
    double x1 = ui->X1Edit->text().toDouble();
    double x1x = ui->X1Box_X->text().toDouble();

    double i0 = ui->I0Box->text().toDouble();
    double i1 = ui->I1Box->text().toDouble();

    double zx = ui->ZBox_X->text().toDouble();

    y0 *= y0x;
    y1 *= y1x;
    x0 *= x0x;
    x1 *= x1x;

    double z0=0;
    if((x1-x0) != 0)
    {
        z0=i0*((y1-y0)/(x1-x0))-x0*((y1-y0)/(x1-x0))+y0;
        ui->Z0Edit->setText(QString::number(z0*zx, 'f', 3));
    }
    else
    {
        ui->Z0Edit->setText(QString("NaN"));
    }
    double z1=0;
    if((x1-x0) != 0)
    {
        z1=i1*((y1-y0)/(x1-x0))-x0*((y1-y0)/(x1-x0))+y0;
        ui->Z1Edit->setText(QString::number(z1*zx, 'f', 3));
    }
    else
    {
        ui->Z1Edit->setText(QString("NaN"));
    }

}
