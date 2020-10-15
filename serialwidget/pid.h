
//pid.h : 增量式PID
#ifndef _PID_H_
#define _PID_H_
 
typedef struct _pid{
double SetSpeed; //目标转速
double ActualSpeed; //实际转速
double err; ///e 误差
double err1;      //e1前一个误差
double err2; //e2 前前一个误差
double Kp, Ki, Kd; //pid参数
double u;  //u(t）
double u1; 	//u(t)的前一时刻
double integral; ////积分值

double err_last ;
double err_next ;
}Pid;
 
 
class Pid_control
{
public:
 
void PID_init();
double PID_realize(double speed,double setspeed,float timeperiod);
double PidIncrement(double actualspeed,double setspeed,float timeperiod);//增量式PID
double PidPosition(double actualspeed,double setspeed,float timeperiod);//位置式pid
double ReturnErr();
void  setpid(double kp,double ki,double kd);
double Transfer(); //取消时沿误差
 
public:
int index;
Pid pid;

};
#endif
