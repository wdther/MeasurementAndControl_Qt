#include "dllread.h"

#include <QApplication>
#include"USBDAQ8API.h"
#include<QDebug>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    DllRead w;
    w.show();


    return a.exec();
}
