#include "mainwindow.h"


#include <QApplication>
#include <QScreen>
#include <QStyleFactory>

#define default_height 768


int main(int argc, char *argv[])
{
    int fontPixels=11;
#ifdef Q_OS_WIN
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
#else
    qputenv("QT_SCREEN_SCALE_FACTORS", "1.2");
#endif
    QApplication a(argc, argv);
    int swidth = 40;
#ifdef Q_OS_WIN
    a.setStyle(QStyleFactory::create("fusion"));
    swidth = 50;
#endif

    a.setStyleSheet("QTabBar::scroller {width: "+QString::number(swidth).toLocal8Bit()+"px;}"
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
    font.setPixelSize(fontPixels);
#ifndef Q_OS_WIN
    font.setStretch(95);
#endif
    a.setFont (font);


    MainWindow w;
    w.show();

    return a.exec();
}
