#include "mainwindow.h"

#include <QApplication>
#include <QScreen>
#define default_height 768

int main(int argc, char *argv[])
{
    int fontPixels=12;
#ifdef Q_OS_WIN
    double scale = 1;
    fontPixels=11;
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
    qputenv("QT_SCREEN_SCALE_FACTORS", "1.1");
#endif

    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("fusion"));

    QFont font;
    font.setFamily("Open Sans");
    font.setWeight(QFont::Normal);
    font.setPixelSize(fontPixels);
    a.setFont (font);


    MainWindow w;
    w.show();
    return a.exec();
}
