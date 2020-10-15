void on_demarcatechart_clicked();
void on_kbsetspeed_clicked();
void on_StartDemarcate_clicked();
void on_empty_clicked();
void on_InnerPid_clicked();
void on_displayspeed_clicked();
#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include<QMainWindow>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTime>
#include    <QtCharts>
#include <QtCharts/QChart>
#include"pid.h"
/**导出的pid控制器*/
#include "pidmodel.h"                  // Model's header file
#include "rtwtypes.h"
namespace Ui {
class SerialWidget;
}

class SerialWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit SerialWidget(QMainWindow *parent = 0);
    ~SerialWidget();
    void on_PlotChart_clicked(float y);
    void on_PidControllSerial(int y);
    void UpdataPhysicsSpeed(float );
    QVector<double> ployfit(QVector<double> x ,QVector<double> y ,int anum);
private:
    void ChartInit();
    void ToByte(QByteArray );
private slots:
    void Read_Date();       //读取串口数据
    void find_port();       //查找可用串口
    void sleep(int msec);      //延时函数

    void on_send_button_clicked();
    void on_open_port_clicked();
    void on_close_port_clicked();
    void on_clear_button_1_clicked();
    void on_clear_button2_clicked();


    void on_rehex_clicked(bool checked);

    void on_reascii_clicked(bool checked);

    void on_seascii_clicked(bool checked);

    void on_sehex_clicked(bool checked);

    void on_version_clicked();

    void on_stop_clicked();

    void on_setspeed_clicked();

    void on_pushButton_clicked();

    void on_start_clicked();

    void on_stoppid_clicked();
    void on_timer_timeout();//定时器



    void on_timeperiod_editingFinished();

    void on_pid_p_editingFinished();

    void on_pid_i_editingFinished();

    void on_pid_d_editingFinished();
    void on_config_triggered();

    void on_clearseries_clicked();

    void on_pwmchart_clicked(bool checked);

    void on_speedchart_clicked(bool checked);
    void on_displayspeed_clicked();
    void StringToHex(QString , QByteArray &);
    char ConvertHexChar(char ch);

    void on_bytesingle_clicked(bool checked);

    void on_bytestream_clicked(bool checked);

    void on_bytetime_editingFinished();

    void on_encoder_clicked(bool checked);
    void on_pin_triggered(bool checked);
    void on_InnerPid_clicked();
    void on_WritePidPara_clicked();

    void on_OuterPid_clicked();

    void on_stm32_clicked(bool checked);

    void on_stm32_released();
    void on_empty_clicked();

    void on_ClearDemarcate_clicked();
    void on_StartDemarcate_clicked();
    void on_kbsetspeed_clicked();

    void on_demarcatechart_clicked(bool checked);

private:
    Ui::SerialWidget *ui;
    QSerialPort *serialport;
    bool textstate_receive;
    bool textstate_send;
    bool serialflag; //判断串口是否打开
    double timeperiod; //定时周期
    Pid_control Pid;
    QChart *chart;
    QChart *pwmchart;
    QChart *demarcatechart;
    QSplineSeries *series0;
    QSplineSeries *series1;
    QSplineSeries *series2;
    QScatterSeries *series3; //表示标定的散点
    QLineSeries *series4 ;  //表示标定的数学曲线
    qreal k,b; //正转曲线的斜率和截距
    qreal k2,b2; //反转曲线


    float incrementSpeed ;
    double pid_d,pid_p,pid_i;
    qreal t; //用于坐标轴
    qreal scrollnum;
    bool Byteflag;
    int  bytetime;
    float encoderspeed; //编码器速度
    int Pidnum; //计算pid调节次数。
    bool Pidflag;




public:
    QTimer *PidTimer;
    QValueAxis *axisX;
    QValueAxis *pwmaxisX;
    double actualspeed; //实际速度
    pidmodelModelClass pidmodel_Obj;
    void Pidrt_OneStep(float timeperiod);
    /*pid模块专用步进**/
    void PhysicsSpeedSet();
    float PhysicsSpeed;
    void Delay_MSec(unsigned int msec);



};

#endif // WIDGET_H
