#include "serialwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SerialWidget w;
    w.show();
    return a.exec();
}
