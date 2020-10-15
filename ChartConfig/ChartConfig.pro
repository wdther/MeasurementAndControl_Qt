#-------------------------------------------------
#
# Project created by QtCreator 2016-12-23T00:04:20
#
#-------------------------------------------------

QT       += core gui

QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chartconfig
TEMPLATE = app


SOURCES += main.cpp\
        chartconfig.cpp \
    qwdialogpen.cpp

HEADERS  += chartconfig.h \
    qwdialogpen.h

FORMS    += chartconfig.ui \
    qwdialogpen.ui

RESOURCES += \
    res.qrc
