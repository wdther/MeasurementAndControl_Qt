#ifndef SPEEDPANEL_H
#define SPEEDPANEL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SpeedPanel; }
QT_END_NAMESPACE

class SpeedPanel : public QMainWindow
{
    Q_OBJECT

public:
    SpeedPanel(QWidget *parent = nullptr);
    ~SpeedPanel();

private:
    Ui::SpeedPanel *ui;
};
#endif // SPEEDPANEL_H
