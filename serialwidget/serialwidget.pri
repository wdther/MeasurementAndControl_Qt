QT       += core gui

QT       += serialport

INCLUDEPATH += $$PWD\

SOURCES +=$$PWD/serialwidget.cpp\
            $$PWD/pid.cpp
        


HEADERS  +=$$PWD/serialwidget.h\
           $$PWD/pid.h
    
FORMS    +=$$PWD/serialwidget.ui

include(../simulinkmotor/motor.pri)
include(../simulinkpid_nofliter/simulinkpid_nofliter.pri)
#include(../ChartConfig/ChartConfig.pri)
    
