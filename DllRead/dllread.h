#ifndef DLLREAD_H
#define DLLREAD_H

#include <QMainWindow>
#include    <QtCharts>
#include <QtCharts/QChart>
#include<vector>
#include "wave.h"                      // Model's header file
#include "rtwtypes.h"
#include<QList>
#include<QVector>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class DllRead; }

QT_END_NAMESPACE

/*重写方法，没必要加入类的成员方法*/
int USBDAQ8_INIT();  //原方法 USB8CHDAQ_INIT
int USBDAQ8_DAQ(int handle,int channel,int fre,int len);
void USBDAQ8_QUIT(int handle);
QVector<double> USBDAQ8_ReadData_Continue(int handle,int len,int channel);
/*---自定义函数----*/
double *generateRandomArray(int n, int rangeL, int rangeR);

class DllRead : public QMainWindow
{
    Q_OBJECT

public:
    DllRead(QWidget *parent = nullptr);
    ~DllRead();
    void on_PlotChart_clicked(QVector<double> ,int anum);
public:
    QChart *chart ;
    QChart *speedchart;
    QLineSeries *series0;
    QSplineSeries  *series1;
    waveModelClass wave_Obj;
    void wavert_OneStep(void);//用于波形的步进

private slots:
    void on_TestButton_clicked();

    void on_StartAcquire_clicked();
    void on_timer_timeout();

    void on_StopAcquire_clicked();

    void on_timetest_clicked();
    void on_waveconfig_triggered();

    void on_speedconfig_triggered();

    void on_lower_editingFinished();

    void on_upper_editingFinished();
    void setfreqValue();
    void setampValue();

    void on_freq_editingFinished();

    void on_freqn_editingFinished();

    void on_cardset_clicked();

    void on_cardquit_clicked();

    void on_convert_clicked();

private:
    Ui::DllRead *ui;
    void ChartInit();
    void ActionInit();
    void SpeedpanelInit();
    bool LogInit();
private:
    QTimer *SignalTimer;  //创建定时器;  //定时器
    int handle;// int 型的句柄值
    int fn;  //采样数和采样频率
    int freq;
    float dt ; //dt=1/freq
    qreal timeperiod; //周期fn*dt
    int virtualamp;
    int virtualfreq;
    QValueAxis *axisX;
    QValueAxis *axisX1;
    qreal rsum; //总转了多少圈
    QVector<double> data;
    bool PhysicsIsGood;
    bool cardflag; //表示采集卡状态
public:
    float actualspped;
private: //dll 的类型转换
    typedef void *HANDLE;
signals:
    void SpeedUpdate(float);

};
#endif // DLLREAD_H
