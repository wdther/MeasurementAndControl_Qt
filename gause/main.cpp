#include "gause.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Gause w;
    w.show();
    return a.exec();
}
