//pid.cpp:
#include <iostream>
#include "pid.h"
 
using namespace std;
 
void  Pid_control::PID_init()
{
pid.SetSpeed = 0;
pid.ActualSpeed = 0;
pid.err = 0;
pid.err1 = 0;
pid.err2 = 0;
pid.u=0;
pid.u1 = 0;
pid.integral = 0;
pid.err_last = 0;
pid.err_next = 0;

}
void  Pid_control::setpid(double kp,double ki,double kd)
{
    pid.Kp = kp;
    pid.Ki = ki;
    pid.Kd = kd;
}
 
double Pid_control::PID_realize(double actualspeed,double setspeed,float timeperiod){
    //假如 p=1 i=0 d=0 会怎么样
    pid.SetSpeed =setspeed;
    pid.ActualSpeed = actualspeed;
    pid.err = pid.SetSpeed - pid.ActualSpeed; //误差
   // double incrementSpeed = pid.Kp*(pid.err - pid.err1) + pid.Ki*pid.err + pid.Kd*(pid.err - 2 * pid.err1 + pid.err2);

    //double incrementSpeed = pid.Kp*(pid.err - pid.err_next) + pid.Ki*pid.err + pid.Kd*(pid.err - 2 * pid.err_next + pid.err_last);
    double incrementSpeed = pid.Kp*(pid.err - pid.err_next) + pid.Ki*pid.err + pid.Kd*(pid.err - 2 * pid.err_next + pid.err_last);
    pid.u=pid.u+incrementSpeed ;
//    pid.err2 = pid.err1;
//    pid.err1 = pid.err;
    pid.err_last = pid.err_next;
    pid.err_next = pid.err;

   // return pid.u;
    return pid.u;

}
double Pid_control:: PidIncrement(double actualspeed,double setspeed,float timeperiod)//增量式PID
{
    timeperiod=1;
    pid.SetSpeed =setspeed; //100
    pid.ActualSpeed = actualspeed; //0
    pid.err = pid.SetSpeed - pid.ActualSpeed; //误差  100
    double increment = pid.Kp*(pid.err - pid.err1) + pid.Ki*pid.err*timeperiod + pid.Kd*1/timeperiod*(pid.err - 2 * pid.err1 + pid.err2);
    //控制增量Δu(k)的确定仅与最近3次的采样值有关。 因为 pid参数不能0 ，否则采集不到三次误差
    pid.u += increment; //100
    pid.err2 = pid.err1; //err1=0
    pid.err1 = pid.err; //err=100 err1=100
    return pid.u;
}

double Pid_control:: PidPosition(double actualspeed,double setspeed,float timeperiod)//位置式pid
{
    pid.SetSpeed =setspeed;
    pid.ActualSpeed = actualspeed;
    pid.err =pid.SetSpeed - pid.ActualSpeed; //误差
    //u(k)=Kp*e+Ki*pid.integral+Kd*(e-e1)
    pid.u = pid.Kp*pid.err + pid.Ki*timeperiod*pid.integral + pid.Kd*1/timeperiod*(pid.err - pid.err1);
    pid.integral += pid.err;
    pid.err1 = pid.err;
    pid.u1 = pid.u;
    return pid.u;
}


double Pid_control::ReturnErr()
{
return pid.err;

}
double Pid_control:: Transfer()
{
    return 0.5*pid.u1/(1-0.5*pid.u1);
}
