#include "mainwindow.h"

#include <QApplication>
#include <QStyleFactory>
#include <QFile>
#include <QScreen>
#include <QtWidgets>
#define default_height 768

int main(int argc, char *argv[])
{
    double scale = 1;
    {
        QApplication a(argc, argv);
        if(QGuiApplication::screens().count())
        {
            QRect rec = QGuiApplication::screens()[0]->geometry();
            scale = (double)((rec.height()<rec.width())?rec.height():rec.width())/default_height;
            if(scale<1) scale = 1;
        }
    }

    qputenv("QT_AUTO_SCREEN_SCALE_FACTOR", "0");
    qputenv("QT_SCREEN_SCALE_FACTORS", QString::number(scale, 'f', 3).toLocal8Bit());



 /*   bool EnableHighDpiScaling = false;

        {
            QApplication a(argc, argv);
            if ( a.screens().at(0)->geometry().width() > 1090) // check somehow. DPI i assume
                EnableHighDpiScaling = true;
        }

        QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling, EnableHighDpiScaling);
*/
    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("fusion"));
    a.setStyleSheet("QTabBar::scroller {width: 60px;}"
                    "QGroupBox {"
                        "border: 1px solid gray;"
                        "border-radius: 3px;"
                        "margin-top: 10px;}"
                    "QGroupBox::title {"
                        "subcontrol-origin: margin;"
                        "subcontrol-position: top left;}");
    QFont font;
    font.setFamily("Open Sans");
    font.setWeight(QFont::Normal);
    font.setPixelSize(11);
    a.setFont (font);

    MainWindow w;
    w.show();

    return a.exec();
}
