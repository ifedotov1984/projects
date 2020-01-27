#include "mainwindow.h"

#include <QApplication>
#include <QStyleFactory>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setFont (QFont ("Open Sans", 9, QFont::Normal));

    a.setStyle(QStyleFactory::create("fusion"));
/*   QFile File("stylesheet.qss");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());
    File.close();*/
    a.setStyleSheet("QTabBar::scroller {width: 60px;}"
                    "QGroupBox {"
                        "border: 1px solid gray;"
                        "border-radius: 3px;"
                        "margin-top: 10px;}"
                    "QGroupBox::title {"
                        "subcontrol-origin: margin;"
                        "subcontrol-position: top left;}");

    MainWindow w;
    w.show();
    return a.exec();
}
