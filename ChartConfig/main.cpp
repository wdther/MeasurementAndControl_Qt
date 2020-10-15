#include "chartconfig.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChartConfig w;
    w.show();

    return a.exec();
}
