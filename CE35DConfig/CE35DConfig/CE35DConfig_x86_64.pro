QT       += core gui
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    asc35d_calib.cpp \
    asc35d_config.cpp \
    comthread.cpp \
    csrs485_calib.cpp \
    csrs485_config.cpp \
    main.cpp \
    mainwindow.cpp \
    portselect.cpp \
    spc35d_config.cpp \
    sr_control.cpp \
    sva35d_calib.cpp \
    sva35d_config.cpp \
    vcrs485_calib.cpp \
    vcrs485_config.cpp

HEADERS += \
    about.h \
    asc35d_calib.h \
    asc35d_config.h \
    comthread.h \
    csrs485_calib.h \
    csrs485_config.h \
    mainwindow.h \
    portselect.h \
    spc35d_config.h \
    sr_control.h \
    sva35d_calib.h \
    sva35d_config.h \
    vcrs485_calib.h \
    vcrs485_config.h

FORMS += \
    about.ui \
    asc35d_calib.ui \
    asc35d_config.ui \
    csrs485_calib.ui \
    csrs485_config.ui \
    mainwindow.ui \
    portselect.ui \
    spc35d_config.ui \
    sr_control.ui \
    sva35d_calib.ui \
    sva35d_config.ui \
    vcrs485_calib.ui \
    vcrs485_config.ui

TRANSLATIONS += \
    CE35DConfig_ru_RU.ts

RESOURCES += \
    res.qrc

TARGET = CE35DConfig
DESTDIR = ../CE35DConfig-bin/usr/bin

