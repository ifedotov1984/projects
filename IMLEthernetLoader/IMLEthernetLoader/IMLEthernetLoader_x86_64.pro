#-------------------------------------------------
#
# Project created by QtCreator 2020-01-10T09:32:18
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IMLEthernetLoader
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    tftp.h

FORMS    += mainwindow.ui

DESTDIR = ../IMLEthernetLoader-bin-x64/usr/bin
