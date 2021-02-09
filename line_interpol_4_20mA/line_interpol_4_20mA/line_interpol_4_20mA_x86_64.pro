QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = line_interpol_4_20mA
TEMPLATE = app


SOURCES += main.cpp \
    line_interpol_4_20mA.cpp

HEADERS  += \
    line_interpol_4_20mA.h

FORMS    += \
    line_interpol_4_20mA.ui

RESOURCES += \
    res.qrc

DESTDIR = ../line_interpol_4_20mA-bin-x64/usr/bin


