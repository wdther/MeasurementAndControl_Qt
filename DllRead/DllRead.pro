QT       += core gui


QT += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


DEFINES += QT_DEPRECATED_WARNINGS



SOURCES += main.cpp \
    dllread.cpp

HEADERS += USBDAQ8API.h\
    dllread.h\

FORMS += dllread.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



unix|win32: LIBS += -L$$PWD/./ -lUSBDAQ8

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

include(../qcustomcontrols/progressbar/QtRoundProgressBar.pri)
include(../simulinkwave/simulinkwave.pri)
include(../ChartConfig/ChartConfig.pri)
include(../qcustomcontrols/gauge/gauge.pri)
