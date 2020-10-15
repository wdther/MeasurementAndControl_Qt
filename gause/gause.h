#ifndef GAUSE_H
#define GAUSE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Gause; }
QT_END_NAMESPACE

class Gause : public QMainWindow
{
    Q_OBJECT

public:
    Gause(QWidget *parent = nullptr);
    ~Gause();

private:
    Ui::Gause *ui;
private slots:
    void customslot();
    void valueChanged(int );
};
#endif // GAUSE_H
