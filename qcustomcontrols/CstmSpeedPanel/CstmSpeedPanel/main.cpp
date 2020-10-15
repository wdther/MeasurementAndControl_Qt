#include "speedpanel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SpeedPanel w;
    w.show();
    return a.exec();
}
