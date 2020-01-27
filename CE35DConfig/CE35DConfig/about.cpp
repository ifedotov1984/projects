#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

about::~about()
{
    delete ui;
}

void about::on_pushButton_clicked()
{
    this->close();
}

void about::on_about_finished(int result)
{
    this->deleteLater();
}
