#ifndef LINE_INTERPOL_4_20MA_H
#define LINE_INTERPOL_4_20MA_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class line_interpol_4_20mA; }
QT_END_NAMESPACE

class line_interpol_4_20mA : public QMainWindow
{
    Q_OBJECT

public:
    line_interpol_4_20mA(QWidget *parent = 0);
    ~line_interpol_4_20mA();

private:
    Ui::line_interpol_4_20mA *ui;

private slots:
    void onData_Changed();
};
#endif // LINE_INTERPOL_4_20MA_H
