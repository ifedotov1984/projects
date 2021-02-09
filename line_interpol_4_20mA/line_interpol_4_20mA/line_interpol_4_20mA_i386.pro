QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = line_interpol_4_20ma
TEMPLATE = app


SOURCES += main.cpp\
        line_interpol_4_20ma.cpp

HEADERS  += line_interpol_4_20ma.h

FORMS    += line_interpol_4_20ma.ui

DESTDIR = ../line_interpol_4_20mA-bin-i386/usr/bin

RESOURCES += \
    res.qrc
