#include "gause.h"
#include "ui_gause.h"
#include<QDebug>

Gause::Gause(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gause)
{
    ui->setupUi(this);
    connect(ui->gauge,SIGNAL(customsignal()), this, SLOT(customslot()));

}
void Gause::customslot()
{
   // qDebug()<<"我被执行";
    qDebug()<<ui->gauge->Value();
}
void Gause::valueChanged(int value)
{
     qDebug()<<value;
}
Gause::~Gause()
{
    delete ui;
}

