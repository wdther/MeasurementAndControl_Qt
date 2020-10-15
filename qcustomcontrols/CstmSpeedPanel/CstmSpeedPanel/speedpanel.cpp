#include "speedpanel.h"
#include "ui_speedpanel.h"
#include"CstmSpeedPanel.h"

SpeedPanel::SpeedPanel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SpeedPanel)
{
    ui->setupUi(this);
    CstmSpeedPanel * sp=new CstmSpeedPanel(this);
            sp->show();
          sp->repaint();

}

SpeedPanel::~SpeedPanel()
{
    delete ui;
}

