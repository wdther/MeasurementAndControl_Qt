#-------------------------------------------------
#
# Project created by QtCreator 2018-04-26T19:07:06
#
#-------------------------------------------------

QT       += core gui
QT       += serialport
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SerialPort

INCLUDEPATH += $$PWD

SOURCES +=main.cpp\
         serialwidget.cpp\
        pid.cpp
        


HEADERS  +=$$PWD/serialwidget.h\
            pid.h
    
FORMS    +=$$PWD/serialwidget.ui
include(../simulinkmotor/motor.pri)
include(../simulinkpid_nofliter/simulinkpid_nofliter.pri)
include(../ChartConfig/ChartConfig.pri)

RESOURCES += \
    serial_qc.qrc

