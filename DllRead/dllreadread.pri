QT       += core gui
QT       += charts


INCLUDEPATH += $$PWD
SOURCES += \
      $$PWD/dllread.cpp

HEADERS +=$$PWD/USBDAQ8API.h \
    $$PWD/dllread.h

FORMS +=$$PWD/dllread.ui

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
