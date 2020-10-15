#include "serialwidget.h"
#include "ui_serialwidget.h"
#include <QMessageBox>
#include<iostream>
#include <QtCharts/QAbstractAxis>
#include <ctype.h>
using namespace  std;
#include"chartconfig.h"
/***/
#include "motor.h"                     // Model's header file
#include "rtwtypes.h"
static To_CdcIntrocompleteModelClass motor_Obj;
void rt_OneStep(void);
void rt_OneStep(void)
{
    static boolean_T OverrunFlag = false;

    // Disable interrupts here

    // Check for overrun
    if (OverrunFlag) {
        rtmSetErrorStatus(motor_Obj.getRTM(), "Overrun");
        return;
    }

    OverrunFlag = true;

    // Save FPU context here (if necessary)
    // Re-enable timer or interrupt here
    // Set model inputs here

    // Step the model
    motor_Obj.step();

    // Get model outputs here

    // Indicate task complete
    OverrunFlag = false;

    // Disable interrupts here
    // Restore FPU context here (if necessary)
    // Enable interrupts here
}
/***/ //数学电机，以供测试

SerialWidget::SerialWidget(QMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::SerialWidget)
{
    /**字节数据格式初始化*/

    /**电机初始化**/

    motor_Obj.initialize();

    /****/
    ui->setupUi(this);
    /*---pid初始化*/

     pid_i=ui->pid_i->value();
     pid_d=ui->pid_d->value();
     pid_p=ui->pid_p->value();
    // Pid.PID_init();
//     Pid.setpid(pid_p,pid_i,pid_d);
//     /**simulink导出的pid*/
//     pidmodel_Obj.initialize();
//     ChartInit();
    on_clearseries_clicked();//包括一些列初始化
    PhysicsSpeed=0; //用于接受物理速度
    encoderspeed=0 ;//用于接收编码器速度
    /**--定时器初始化--*/
    PidTimer=new QTimer(this);
    PidTimer->stop();
   // timeperiod=0.5; //定时周期
    timeperiod=ui->timeperiod->value();
    connect(PidTimer,SIGNAL(timeout()),this,SLOT(on_timer_timeout())); //关联定时器的信号与槽
    /*这里是默认的格式 false为16进制，true为ascii码**/
    if (ui->reascii->isChecked())
        textstate_receive = true;
    else
        textstate_receive = false;
    if (ui->seascii->isChecked())
        textstate_send = true;
    else
        textstate_send = false;

    /***/
    setWindowTitle("个人串口助手");
    serialport = new QSerialPort;
    find_port();                    //查找可用串口
     serialflag=false; //串口默认未打开
    ui->send_button->setEnabled(false);     //设置控件不可用
    ui->close_port->setEnabled(false);
    /***/

    /**动作初始化--*/
    ui->chartView->addAction(ui->config);
    ui->toolBox_2->addAction(ui->pin);
    ui->toolBox->addAction(ui->pin);

    if(ui->bytesingle->isChecked())
        Byteflag=true;
    else
        Byteflag=false;
    bytetime=(ui->bytetime->value())*1000;
    Pidnum=0;
    Pidflag=0;
    //拟合曲线的参数
    k=0;b=0;
    k2=0;b2=0;

}

void SerialWidget::Delay_MSec(unsigned int msec)
{
    QTime _Timer = QTime::currentTime().addMSecs(msec);

    while( QTime::currentTime() < _Timer )

    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void SerialWidget::UpdataPhysicsSpeed(float speed)
{
    PhysicsSpeed=speed;
}
void SerialWidget::on_config_triggered()
{
    static int sppedNum = 1;
    QString cur = tr("速度图设置%1").arg(sppedNum++);
    ChartConfig * chartconfig=new ChartConfig;
    chartconfig->setAttribute(Qt::WA_DeleteOnClose);
    chartconfig->setWindowTitle(cur);
    chartconfig->show();
    chartconfig->pchart=ui->chartView->chart();
    //qDebug()<<"speed设置界面打开";

}
void SerialWidget::on_pin_triggered(bool checked)
{
    if(checked)
       setWindowFlags(Qt::WindowStaysOnTopHint);
    else
        setWindowFlags(windowFlags());
        this->show();


}
void SerialWidget::ChartInit()
{

    ui->chartView->setRenderHint(QPainter::Antialiasing);
    chart=new QChart();
    pwmchart=new QChart();
    demarcatechart=new QChart();
    if(ui->pwmchart->isChecked())
    {
        ui->chartView->setChart(pwmchart);
    }
    else if (ui->speedchart->isChecked()){
       ui->chartView->setChart(chart);
    }
    else if (ui->demarcatechart->isChecked()){

       ui->chartView->setChart(demarcatechart);
    }

    series0 = new QSplineSeries();
    series1 = new QSplineSeries();
    series2=  new QSplineSeries();
    series3 = new QScatterSeries(); //表示标定散点
    series4 = new QLineSeries(); //标定标定数学曲线


    series0->setName("实际速度");
    series1->setName("期望速度");
    series2->setName("PWM波形");
    series3->setName("速度-pwm散点");
    series3->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series3->setMarkerSize(10);
    series4->setName("速度-pwm散拟合");

    chart->addSeries(series0); //序列添加到图表
    chart->addSeries(series1);
    pwmchart->addSeries(series2);
    demarcatechart->addSeries(series3);
    demarcatechart->addSeries(series4);

    chart->setTheme(QChart::ChartThemeBlueCerulean);//设置系统主题
    pwmchart->setTheme(QChart::ChartThemeBlueCerulean);
    demarcatechart->setTheme(QChart::ChartThemeBlueCerulean);
    chart->setTitle("速度-误差曲线");//设置标题
    chart->setTitleFont(QFont("微软雅黑",10));
    pwmchart->setTitle("PWM控制曲线");//设置标题
    pwmchart->setTitleFont(QFont("微软雅黑",10));
    demarcatechart->setTitle("速度-pwm拟合");//设置标题
    demarcatechart->setTitleFont(QFont("微软雅黑",10));

    axisX = new QValueAxis; //X 轴
    pwmaxisX= new QValueAxis;
    QValueAxis *axisY = new QValueAxis; //Y 轴
    QValueAxis *pwmaxisY = new QValueAxis; //Y 轴
    QValueAxis *demarcateaxisX = new QValueAxis; //Y 轴
    QValueAxis *demarcateaxisY = new QValueAxis; //Y 轴

    axisX->setRange(0, 4); //设置坐标轴范围
    axisX->setTitleText("time(secs)"); //标题
    pwmaxisX->setRange(0,4);
    pwmaxisX->setTitleText("time(secs)");
    demarcateaxisX->setRange(800,2200);
    demarcateaxisY->setRange(-3000,3000);
    demarcateaxisX->setTitleText("pwm分频数");
    demarcateaxisY->setTitleText("转速 r/s");


    axisY->setRange(0, 3000);
    pwmaxisY->setRange(0, 2000);
    axisY->setTitleText("value");
    axisX->setGridLineVisible(1);
    chart->setAxisX(axisX, series0); //为序列设置坐标轴
    chart->setAxisY(axisY, series0); //
    chart->setAxisX(axisX, series1); //为序列设置坐标轴
    chart->setAxisY(axisY, series1); //
    pwmchart->setAxisX(pwmaxisX, series2); //为序列设置坐标轴
    pwmchart->setAxisY(pwmaxisY, series2); //
    demarcatechart->setAxisX(demarcateaxisX,series3);
    demarcatechart->setAxisY(demarcateaxisY,series3);
    demarcatechart->setAxisX(demarcateaxisX,series4);
    demarcatechart->setAxisY(demarcateaxisY,series4);




    //控制坐标轴的点和滚动
    t=0 ; scrollnum=0;

}
void SerialWidget::on_timer_timeout()
{
     qDebug()<<"设定速度"<<ui->speed->value()<<"电压增量"<<incrementSpeed <<"实际速度"<<actualspeed;

    /*----电机模型---*/
    //返回的是增量式调整参数 第一个参数是实际速度，到时候用
    //采样的速度代替，第二个参数是设定速度
    if(ui->position->isChecked()) //位置型算法
       { incrementSpeed = Pid.PidPosition(actualspeed,(ui->speed->value()),timeperiod);
        qDebug()<<"positon";
    }
    else if(ui->increment->isChecked()) //增量
       { incrementSpeed =Pid.PidIncrement(actualspeed,(ui->speed->value()),timeperiod);
        qDebug()<<"increment";
    }
    else if(ui->simupositon->isChecked())  //位置型
    {   //误差=设定速度-实际速度
        pidmodel_Obj.pidmodel_U.error=(ui->speed->value())-actualspeed;
       Pidrt_OneStep(timeperiod);
       incrementSpeed=pidmodel_Obj.pidmodel_Y.u;
       qDebug()<<"simupositon";
    }
    else if(ui->stm32->isChecked())
    {
        incrementSpeed=0;
    }
/*---------------------------------------------------------------------------------------------------*/
    if(ui->model->isChecked()) //数学模型
       { motor_Obj.motor_U.Voltage=incrementSpeed;
        rt_OneStep();//模型步进
        Pidnum++;
        actualspeed=motor_Obj.motor_Y.Outspeed; //返回实际速度
    }
    else if(ui->motor->isChecked()) //采集卡
    {
        //应当注意阈值问题，例如电压不能设置为负值或者，特别大。
        //这是通过pwm波，来调速的
        //对数据过滤
        //考虑正反转
        if(incrementSpeed>400)
            incrementSpeed=400;
        if(incrementSpeed<0)
            incrementSpeed=0;

        if(ui->speed->value()>0) //设定速度大于0，pwm在1000-1500之间
            {
            incrementSpeed=1500-incrementSpeed; //当pwm0-500变化时 输出为1500-1100变化
            on_PidControllSerial(incrementSpeed); //写入串口数据
            actualspeed=PhysicsSpeed;  //返回测量
             }
        else if(ui->speed->value()<0) //设定速度小于0
        {
            incrementSpeed=1500+incrementSpeed; //当pwm0-500变化时 输出为1500-1900变化
            on_PidControllSerial(incrementSpeed); //写入串口数据
            actualspeed=-PhysicsSpeed;  //返回测量
        }
    }
    else if(ui->encoder->isChecked()) //编码器
    {
        if(!Pidflag) //！Pidflag表示外部PID
        {
           on_PidControllSerial(incrementSpeed); //写入串口数据
        }

        actualspeed=encoderspeed;
    }

     Pidnum++;
     on_PlotChart_clicked(actualspeed);
    /**---------------------***/


   QString s2 = QString("PID参数为：p:%1 i:%2 d:%3。\r\n设定速度 %4。\r\n实际速度%5。\r\n PID调整次数%6\r\n"
                        "电压增量%7").arg(Pid.pid.Kp
                ).arg(Pid.pid.Ki).arg(Pid.pid.Kd).arg(ui->speed->value()).arg(actualspeed).arg(
              Pidnum ).arg(incrementSpeed);    //"rowCount:

   // qDebug()<<"PID参数为："<<Pid.pid.Kp<<Pid.pid.Ki<<Pid.pid.Kd;

    ui->tips->setPlainText(s2);
}
void SerialWidget::on_PidControllSerial(int y)
{
    if(ui->default_deal->isChecked())
    {
        QByteArray ba,temp;
        ba.resize(2); //55 06 fd  cc dd  aa
        ba[0]=uchar(0x55);
        ba[1]=uchar(0x06);
        ba[2]=uchar(0xfb);
        //判断串口是否打开
        if(serialflag)
        {
            //设定速度本质上是设定pwm
            if(y<256) //用两个字节表示
            {
                ba.append(uchar(0x00));
            }
            temp.setNum(y, 16); //2位小数*100 到stm32 除以100

            ba.append(QByteArray::fromHex(temp));
            ba.append(uchar(0xaa));
            if(Byteflag)
                ToByte(ba);
            else
                serialport->write(ba); //
            on_send_button_clicked();  //似乎有效
        }

    }
    else if(ui->custom_deal->isChecked())
    {
        QByteArray ba,temp;
        ba.resize(2);
        ba[0]='c';
        ba[1]=uchar(0xFB);
        if(serialflag)
        {
            //设定速度本质上是设定pwm
            if(y<256) //用两个字节表示
            {
                ba.append(uchar(0x00));
            }
            temp.setNum(y, 16); //2位小数*100 到stm32 除以100

            ba.append(QByteArray::fromHex(temp));
            ba.append('t');
            if(Byteflag)
                ToByte(ba);
            else
                serialport->write(ba); //
            on_send_button_clicked();  //似乎有效
        }

    }




}
void SerialWidget::on_WritePidPara_clicked()
{
    QByteArray ba,temp;
    ba.resize(5);
    ba[0]='p';
    ba[1]=char(pid_p);
    ba[2]=char(pid_i);
    ba[3]=char(pid_d);
    ba[4]='d';
    if(Byteflag)
        ToByte(ba);
    else
        serialport->write(ba); //
    on_send_button_clicked();  //似乎有效
}
void SerialWidget::on_PlotChart_clicked(float y)
{   //实际上它必须保留参数以便不时只需
    //例如外部信号

    QPointF point=QPointF(t,y);
    QPointF point2=QPointF(t,ui->speed->value());
    QPointF point3=QPointF(t,incrementSpeed);

     series0->append(point);
     series1->append(point2);
     series2->append(point3);
     if(ui->speedchart->isChecked())
     {
         qreal range=axisX->max()-axisX->min();
         qreal area=timeperiod/range*chart->plotArea().width();
         if(scrollnum>(range/timeperiod*0.9))  //range/timeperiod -1
             //如果数据点很多 range/timeperiod较大
         {  //此处的滚动策略为，预留一个数据，看到末端
             chart->scroll(area, 0); //timeperiod/range *wodth

         }
     }
     else if(ui->pwmchart->isChecked())
     {
         qreal range=pwmaxisX->max()-pwmaxisX->min();
         qreal area=timeperiod/range*pwmchart->plotArea().width();
         if(scrollnum>(range/timeperiod*0.9))  //range/timeperiod -1
         {
             pwmchart->scroll(area, 0); //timeperiod/range *wodth

         }
     }
    t+=timeperiod;
    scrollnum+=1;
    qDebug()<<"绘图";

}

SerialWidget::~SerialWidget()
{
    delete ui,serialport;
}

//发送数据
void SerialWidget::on_send_button_clicked()
{

    //serialport->write(ui->send_text_window->toPlainText().toLatin1());



    if(textstate_send == true)  //文本模式
    {
        serialport->write(ui->send_text_window->toPlainText().toLatin1());
    }

    if(textstate_send == false)     //16进制
    {
        QString str = ui->send_text_window->toPlainText();
//        int num = str.toInt();
//        str = str.setNum(num,16);
//        ui->send_text_window->clear();
//        ui->send_text_window->append(str);
//        serialport->write(ui->send_text_window->toPlainText().toLatin1());
//        qDebug()<<ui->send_text_window->toPlainText().toLatin1();
//原来的设计是有问题的，都是以文本模式发送数据serialport->write(ui->send_text_window->toPlainText().toLatin1());
        QByteArray senddata;

       StringToHex(str,senddata);
       serialport->write(senddata);
       //原来Qt5取消了toAscii()函数，全局查找替换，将它替换为toLatin1()后问题就解决了。
    }



}
void SerialWidget:: ToByte(QByteArray ba)
{
    int num=ba.size();
    QByteArray batemp;
    batemp.resize(1);
    for(int i=0;i<num;i++)
    {
        batemp[0]=ba[i];
        Delay_MSec(bytetime);//延时0.5m
        serialport->write(batemp);
       // qDebug()<<"字节";
    }

}

void SerialWidget::StringToHex(QString str, QByteArray &senddata)
{
    int hexdata,lowhexdata;
    int hexdatalen = 0;
    int len = str.length();
    senddata.resize(len/2);
    char lstr,hstr;
    for(int i=0; i<len; )
    {
        //char lstr,
        hstr=str[i].toLatin1();
        if(hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        if(i >= len)
            break;
        lstr = str[i].toLatin1();
        hexdata = ConvertHexChar(hstr);
        lowhexdata = ConvertHexChar(lstr);
        if((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            hexdata = hexdata*16+lowhexdata;
        i++;
        senddata[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }
    senddata.resize(hexdatalen);
}

char SerialWidget::ConvertHexChar(char ch)
{
    if((ch >= '0') && (ch <= '9'))
            return ch-0x30;
        else if((ch >= 'A') && (ch <= 'F'))
            return ch-'A'+10;
        else if((ch >= 'a') && (ch <= 'f'))
            return ch-'a'+10;
        else return (-1);
}

//打开串口
void SerialWidget::on_open_port_clicked()
{
   update();
   sleep(100);      //延时100ms
   find_port();     //重新查找com
    //初始化串口
        serialport->setPortName(ui->com->currentText());        //设置串口名
        if(serialport->open(QIODevice::ReadWrite))              //打开串口成功
        {
            serialflag=true;
            serialport->setBaudRate(ui->baud->currentText().toInt());       //设置波特率
            switch(ui->bit->currentIndex())                   //设置数据位数
            {
                case 8:serialport->setDataBits(QSerialPort::Data8);break;
                default: break;
            }
            switch(ui->jiaoyan->currentIndex())                   //设置奇偶校验
            {
                case 0: serialport->setParity(QSerialPort::NoParity);break;
                default: break;
            }
            switch(ui->stopbit->currentIndex())                     //设置停止位
            {
                case 1: serialport->setStopBits(QSerialPort::OneStop);break;
                case 2: serialport->setStopBits(QSerialPort::TwoStop);break;
                default: break;
            }
            serialport->setFlowControl(QSerialPort::NoFlowControl);     //设置流控制
            //连接槽函数
            QObject::connect(serialport, &QSerialPort::readyRead, this, &SerialWidget::Read_Date);
            // 设置控件可否使用
            ui->send_button->setEnabled(true);
            ui->close_port->setEnabled(true);
            ui->open_port->setEnabled(false);
        }
        else    //打开失败提示
        {
            sleep(100);
            serialflag=false;
            QMessageBox::information(this,tr("Erro"),tr("Open the failure"),QMessageBox::Ok);
        }
}
//关闭串口
void SerialWidget::on_close_port_clicked()
{
    serialport->clear();        //清空缓存区
    serialport->close();        //关闭串口

    ui->send_button->setEnabled(false);
    ui->open_port->setEnabled(true);
    ui->close_port->setEnabled(false);
}
//窗口显示串口传来的数据
void SerialWidget::Read_Date()  ///接收数据时候的槽函数
{
    QByteArray buf,Temp;
   // static int delay=1;

    /*------------------------------------------------------------*/

         sleep(bytetime);


        buf=serialport->readAll();

    if(!buf.isEmpty())          //将数据显示到文本串口
    { 

//        if(buf.size()==7) //如何正确读到数据位，特别是在校正的时候
//        {
//            encoderspeed=buf.toInt();
//            if(encoderspeed>100000)
//                encoderspeed=encoderspeed-100000;
//            qDebug()<<"encoderspeed："<<encoderspeed;
//            QString str2=QString("编码器速度：%1").arg(encoderspeed);
//            ui->hints->setText(str2);
//            delay=8;

//        }
        int x1=buf.indexOf('s');
        int y1=buf.indexOf('p');
//        QString str2=QString("数据帧大小：%1").arg(buf.size());
//        ui->hints->setText(str2);
        //s100008p 数据帧大小是9 因为还有换行符
        if(x1!=-1&&y1!=-1&&(y1-x1)==7)   //索引到sp有一个问题，因为我会返回speed关键字
        {
            for(int i=x1+1;i<y1;i++)
            {
                Temp.append(buf[i]);
            }
            encoderspeed=Temp.toInt();
            if(encoderspeed>100000)
                  encoderspeed=encoderspeed-100000;

               // qDebug()<<"encoderspeed："<<encoderspeed;
                QString str2=QString("编码器速度：%1").arg(encoderspeed);
                ui->hints->setText(str2);
                Temp.clear();
        }




        if(textstate_receive == true)   //文本模式
        {
            QString str = ui->Receive_text_window->toPlainText();
           // qDebug()<<"str"<<str;
            str+=tr(buf);
           // str += " ";//数据加空格
          //  qDebug()<<"str"<<str;
            ui->Receive_text_window->clear();
            ui->Receive_text_window->append(str);
        }
        if(textstate_receive == false)   //hex模式
        {
            QString str = ui->Receive_text_window->toPlainText();
            QByteArray temp = buf.toHex(); // byteArray 转 16进制字符串

            str+=tr(temp);

            str += "  ";
            ui->Receive_text_window->clear();
            ui->Receive_text_window->append(str);
        }


        // qDebug()<<"buf"<<buf;

    }

//    static int interuput=1;
//    QString str1=QString("中断次数：%1buf内容%2").arg(interuput).arg(tr(buf.toHex()));
//    interuput++;
    //ui->hints->setText(str1);

    //buf.clear();    //清空缓存区
    //如果不清空缓冲区会怎么样

}


//查找串口
void SerialWidget::find_port()
{
    //查找可用的串口
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;
        serial.setPort(info);   //设置串口
        if(serial.open(QIODevice::ReadWrite))
        {
            ui->com->addItem(serial.portName());        //显示串口name
            serial.close();
        }
    }
}

//延时函数
void SerialWidget::sleep( int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}


void SerialWidget::on_clear_button_1_clicked()
{
    ui->send_text_window->clear();
}

void SerialWidget::on_clear_button2_clicked()
{
    ui->Receive_text_window->clear();
}





//接收框文本模式转换
void SerialWidget::on_rehex_clicked(bool checked)
{   //以hex码接收
    if (checked)
    {
        textstate_receive = false;
        QString str=ui->Receive_text_window->toPlainText();

    }
}

void SerialWidget::on_reascii_clicked(bool checked)
{  //以ascii码接收
    if (checked)
    {
        textstate_receive = true;
     }

}

void SerialWidget::on_seascii_clicked(bool checked)
{
    if (checked)
       {

        textstate_send = true;
    }
}

void SerialWidget::on_sehex_clicked(bool checked)
{
    if (checked)
    {
        textstate_send = false;

    }
}

void SerialWidget::on_version_clicked()
{

    if(ui->default_deal->isChecked())
    {
        QString str= ui->Receive_text_window->toPlainText();
        QByteArray ba;
        ba.resize(3);
        ba[0]=uchar(0x55);
        ba[1]=uchar(0x06);
        ba[2]=uchar(0xfa);
        //判断串口是否打开
        if(serialflag)
        {
            if(Byteflag)
                ToByte(ba);
            else
                serialport->write(ba); //
            on_send_button_clicked();
        }
        else //弹出错误对话框
        {
            QString dlgTitle="warning 消息框";
            QString strInfo="串口没有正常打开";

            QMessageBox::warning(this, dlgTitle, strInfo);
        }

    }
    else if(ui->custom_deal->isChecked())
    {

        QByteArray ba;
        ba.resize(5); //55 06 fd  cc dd  aa
        ba[0]='c';
        ba[1]=uchar(0xFA);
        ba[2]=uchar(0xDD);
        ba[3]=uchar(0xDD);
        ba[4]='t';
        if(serialflag)
         {
          if(Byteflag)
              ToByte(ba);
           else
              serialport->write(ba); //
           on_send_button_clicked();  //似乎有效
        }
        else //弹出错误对话框
        {
            QString dlgTitle="warning 消息框";
            QString strInfo="串口没有正常打开";

            QMessageBox::warning(this, dlgTitle, strInfo);
        }




    }

}

void SerialWidget::on_stop_clicked()

{
    if(ui->default_deal->isChecked())
    {
        QByteArray ba;
        ba.resize(3);
        ba[0]=uchar(0x55);
        ba[1]=uchar(0x06);
        ba[2]=uchar(0xfc);
        if(serialflag)
        {

            if(Byteflag)
                ToByte(ba);
            else
                serialport->write(ba); //
            on_send_button_clicked();  //似乎有效
        }

    }
    else if(ui->custom_deal->isChecked())
    {
        /*-------------------------------------------------------------------*/
        QByteArray ba;
        ba.resize(5); //
        ba[0]='c';
        ba[1]=uchar(0xFC);
        ba[2]=uchar(0xDD);
        ba[3]=uchar(0xDD);
        ba[4]='t';
        if(serialflag)
        {
            if(Byteflag)
                ToByte(ba);
            else
                serialport->write(ba); //
            on_send_button_clicked();  //似乎有效

        }
        else //弹出错误对话框
        {
            QString dlgTitle="warning 消息框";
            QString strInfo="串口没有正常打开";

            QMessageBox::warning(this, dlgTitle, strInfo);
        }
    }
}

void SerialWidget::on_setspeed_clicked()
{   //55 06 fb 04     b0 aa
    int speed=ui->speed->value();

    if(ui->default_deal->isChecked())
    {
        QByteArray ba,temp;
        ba.resize(3);
        ba[0]=uchar(0x55);
        ba[1]=uchar(0x06);
        ba[2]=uchar(0xfb);

        if(serialflag)
        {
            //设定速度本质上是设定pwm,在设定速度上不乘100，否则范围太小。
            if(speed<256)
            {
                ba.append(uchar(0x00));
            }
            temp.setNum(speed, 16); //2位小数*100 到stm32 除以100
            ba.append(QByteArray::fromHex(temp));
            ba.append(uchar(0xaa));
            if(Byteflag)
                ToByte(ba);
            else
                serialport->write(ba); //
            on_send_button_clicked();  //似乎有效
        }

    }
    else if(ui->custom_deal->isChecked())
    {
        /**--------------------------------------------------------*/
        QByteArray ba,temp;
        ba.resize(2); //
        ba[0]='c';
        ba[1]=uchar(0xFB);
        if(serialflag)
        {
            //设定速度本质上是设定pwm,在设定速度上不乘100，否则范围太小。
            if(speed<256)
            {
                ba.append(uchar(0x00));
            }
            temp.setNum(speed, 16); //2位小数*100 到stm32 除以100
            ba.append(QByteArray::fromHex(temp));
            ba.append('t');
            if(Byteflag)
                ToByte(ba);
            else
                serialport->write(ba); //
            on_send_button_clicked();  //似乎有效
        }
        else //弹出错误对话框
        {
            QString dlgTitle="warning 消息框";
            QString strInfo="串口没有正常打开";

            QMessageBox::warning(this, dlgTitle, strInfo);
        }
    }

}

void SerialWidget::on_pushButton_clicked()
{
    QByteArray ba,ba1,ba2,ba3,ba4,ba5,ba6;
    int n = 63;
    ba.setNum(n);           // ba == "63"
    ba1.setNum(n, 16);       // ba == "3f
    ba2.append(63);
    ba3[0]=0x63;
    ba4[0]=uchar(0x63);
    ba5= QByteArray::fromHex("63");
    ba6=QByteArray::fromHex("3E8");//2位
    qDebug()<<sizeof(ba)<<sizeof(ba1)<<sizeof(ba2)<<sizeof(ba3)<<sizeof(ba4);
    //4 4 4 4 4
    qDebug()<<ba.size()<<ba1.size()<<ba2.size()<<ba3.size()<<ba4.size()<<ba5.size()<<ba6.size();
    //2 2 1 1 1
    qDebug()<<ba<<ba1<<ba2<<ba3<<ba4<<ba5<<ba6[1];
    //"63" "3f" "c" "c" "c" "c""\x03\xE8"
    //16进制的63，对应ascii中的“c”
    int nn=1000;
    ba.setNum(nn, 16);
     qDebug()<<ba;
     QByteArray text = QByteArray::fromHex("03e8");
     qDebug()<<text.data(); //Qt is great!
      qDebug()<<text.data()[0]; //Q
      ba.append(text);
      qDebug()<<ba; //"3e8Qt is great!"
}

void SerialWidget::on_start_clicked()
{
     PidTimer->start(timeperiod*1000); //单位为毫秒
}

void SerialWidget::on_stoppid_clicked()
{
    PidTimer->stop();
}



void SerialWidget::on_timeperiod_editingFinished()
{
    timeperiod=ui->timeperiod->value();
}
void SerialWidget::on_pid_p_editingFinished()
{
    pid_p=ui->pid_p->value();
    Pid.setpid(pid_p,pid_i,pid_d); //
    pidmodel_Obj.parainit(pid_p,pid_i,pid_d); //
}

void SerialWidget::on_pid_i_editingFinished()
{
    pid_i=ui->pid_i->value();
    Pid.setpid(pid_p,pid_i,pid_d);
    pidmodel_Obj.parainit(pid_p,pid_i,pid_d);
}

void SerialWidget::on_pid_d_editingFinished()
{
     pid_d=ui->pid_d->value();
     Pid.setpid(pid_p,pid_i,pid_d);
     pidmodel_Obj.parainit(pid_p,pid_i,pid_d);
}

void SerialWidget::on_clearseries_clicked()
{   //除了清除图形，还要将pid控制相关重置
    //编写的pid模块
    Pid.PID_init();
    Pid.setpid(pid_p,pid_i,pid_d);
   //simulink pid模块
    pidmodel_Obj.terminate();
    pidmodel_Obj.initialize();
    pidmodel_Obj.parainit(pid_p,pid_i,pid_d);
    //Simulink 电机模块
    motor_Obj.terminate();//model terminate function
    motor_Obj.initialize();
    //
    incrementSpeed =0;
    actualspeed=0;
    Pidnum =0;
    //为什么我不调用系统的构造函数，因为那样会导致串口重置
    ChartInit();

    qDebug()<<"设定速度"<<ui->speed->value()<<"电压增量"<<incrementSpeed <<"实际速度"<<actualspeed;




}
void SerialWidget::Pidrt_OneStep(float timeperiod)
{
  static boolean_T OverrunFlag = false;

  // Disable interrupts here

  // Check for overrun
  if (OverrunFlag) {
    rtmSetErrorStatus(pidmodel_Obj.getRTM(), "Overrun");
    return;
  }

  OverrunFlag = true;

  // Save FPU context here (if necessary)
  // Re-enable timer or interrupt here
  // Set model inputs here

  // Step the model
  pidmodel_Obj.step(timeperiod);

  // Get model outputs here

  // Indicate task complete
  OverrunFlag = false;

  // Disable interrupts here
  // Restore FPU context here (if necessary)
  // Enable interrupts here
}

void SerialWidget::on_pwmchart_clicked(bool checked)
{
    if(checked)
    {
        ui->chartView->setChart(pwmchart);
    }
}

void SerialWidget::on_speedchart_clicked(bool checked)
{
    if(checked)
    {

        ui->chartView->setChart(chart);
    }
}

void SerialWidget::on_displayspeed_clicked()
{
    int speed=ui->disspeed->value();

//    if(serialflag)
//    {
//        if(speed*100<256) //一位
//         {
//            ba.append(uchar(0x00));
//        }

//          temp.setNum(speed*100, 16); //有2位小数，需要乘以100
//          ba.append(QByteArray::fromHex(temp));
//          //ba.append(0xaa);
//          if(Byteflag)
//              ToByte(ba);
//          else
//            serialport->write(ba); //
//           on_send_button_clicked();  //似乎有效
//          qDebug()<<ba.toHex();
//         qDebug()<<"手动模式";
//    }
    if(ui->default_deal->isChecked())
    {
        QByteArray ba,temp;
        ba.resize(3); //55 06 fd  cc dd  aa
        ba[0]=uchar(0x55);
        ba[1]=uchar(0x06);
        ba[2]=uchar(0xFD);

        if(serialflag)
        {
            //设定速度本质上是设定pwm,在设定速度上不乘100，否则范围太小。
            if(speed<256)
            {
                ba.append(uchar(0x00));
            }
            temp.setNum(speed, 16); //2位小数*100 到stm32 除以100
            ba.append(QByteArray::fromHex(temp));
            ba.append(uchar(0xaa));
            if(Byteflag)
                ToByte(ba);
            else
                serialport->write(ba); //
            on_send_button_clicked();  //似乎有效
        }

    }
    else if(ui->custom_deal->isChecked())
    {
        /*-------------------------------------------------------*/
        QByteArray ba,temp;
        ba.resize(2); //
        ba[0]='c';
        ba[1]=uchar(0xFD);
        if(serialflag)
        {
            temp.setNum(speed*100, 16); //有2位小数，需要乘以100
            ba.append(QByteArray::fromHex(temp));
            ba.append('t');
            if(Byteflag)
                ToByte(ba);
            else
                serialport->write(ba); //
            on_send_button_clicked();  //似乎有效
        }
        else //弹出错误对话框
        {
            QString dlgTitle="warning 消息框";
            QString strInfo="串口没有正常打开";

            QMessageBox::warning(this, dlgTitle, strInfo);
        }
    }

}

void SerialWidget::on_bytesingle_clicked(bool checked)
{
    if(checked)
    {
        Byteflag=1;
    }
}

void SerialWidget::on_bytestream_clicked(bool checked)
{
    if(checked)
    {
        Byteflag=0;
    }
}

void SerialWidget::on_bytetime_editingFinished()
{
    bytetime=(ui->bytetime->value())*1000;
}

void SerialWidget::on_encoder_clicked(bool checked)
{
    if(!Byteflag&&checked)
       {
        QString dlgTitle="warning 消息框";
        QString strInfo="编码器模式下需打开单字节发送";
        QMessageBox::warning(this, dlgTitle, strInfo);
    }
}

void SerialWidget::on_InnerPid_clicked()
{
    QByteArray ba;
    ba.resize(5); //55 06 fd  cc dd  aa
    ba[0]='c';
    ba[1]=uchar(0xFE);
    ba[2]=uchar(0xDD);
    ba[3]=uchar(0xDD);
    ba[4]='t';
    if(serialflag)
    {
        if(Byteflag)
            ToByte(ba);
        else
            serialport->write(ba); //
        on_send_button_clicked();  //似乎有效

      Pidflag=1;
    }
    else //弹出错误对话框
    {
        QString dlgTitle="warning 消息框";
        QString strInfo="串口没有正常打开";

        QMessageBox::warning(this, dlgTitle, strInfo);
    }


}

void SerialWidget::on_OuterPid_clicked()
{
    QByteArray ba;
    ba.resize(5); //55 06 fd  cc dd  aa
    ba[0]='c';
    ba[1]=uchar(0xFF);
    ba[2]=uchar(0xDD);
    ba[3]=uchar(0xDD);
    ba[4]='t';
    if(serialflag)
    {
        if(Byteflag)
            ToByte(ba);
        else
            serialport->write(ba); //
        on_send_button_clicked();  //似乎有效
      Pidflag=0;
    }
    else //弹出错误对话框
    {
        QString dlgTitle="warning 消息框";
        QString strInfo="串口没有正常打开";

        QMessageBox::warning(this, dlgTitle, strInfo);
    }
}

void SerialWidget::on_stm32_clicked(bool checked)
{
    if(checked)
    ui->encoder->setChecked(1);
    on_InnerPid_clicked();

}

void SerialWidget::on_stm32_released()
{
    if(!ui->stm32->isChecked())
        ui->encoder->setChecked(0);
}

void SerialWidget::on_empty_clicked()
{
    QByteArray ba;
    ba.resize(5); //55 06 fd  cc dd  aa
    ba[0]=uchar(0x30);
    ba[1]=uchar(0x30);
    ba[2]=uchar(0x30);
    ba[3]=uchar(0x30);
    ba[4]=uchar(0x30);
    if(serialflag)
    {
        if(Byteflag)
            ToByte(ba);
        else
            serialport->write(ba); //
        on_send_button_clicked();  //似乎有效
      Pidflag=0;
    }
    else //弹出错误对话框
    {
        QString dlgTitle="warning 消息框";
        QString strInfo="串口没有正常打开";

        QMessageBox::warning(this, dlgTitle, strInfo);
    }
}

void SerialWidget::on_StartDemarcate_clicked() //开始标定
{
   //获取基本参数
    on_demarcatechart_clicked(true);
    int pwm=1450;
    qreal last_speed=0;
    QVector<double> up_x;
    QVector<double> up_y;
    QVector<double> down_x;
     QVector<double> down_y;
    //记录拟合次数
     int count=1;

     //测试 PhysicsSpeed
//    int tempsp=1000;


    //发送控制指令
//   while(pwm>1000) //用于测试坐标轴
//   {

//        on_PidControllSerial(pwm);
//        sleep(200); //延时2s,电机速度变化
//        last_speed=PhysicsSpeed;
//        sleep(100); //延时1s电机速度稳定
//        if(1) //因为小于10表示稳定，但是如果没变呢
//         {
//             QPointF point=QPointF(pwm,tempsp);
//            series3->append(point);


//            up_x.append(pwm);
//            up_y.append(tempsp);
//            pwm=pwm-ui->gap->value();
//            //测试
//            tempsp=tempsp+100;

//            QString str= QString("正转有效散点数%1数据点%2 %3").arg(count).arg(pwm).arg(tempsp);
//            count++;
//           ui->DemarcateTips->setText(str);
//           qDebug()<<"数据点"<<pwm<<tempsp;

//        }



//   }
   while(pwm>1100){

       on_PidControllSerial(pwm);//发送pwm控制
       sleep(ui->accelerateTime->value()); //延时2s,电机速度变化
       last_speed=PhysicsSpeed;
       sleep(ui->steadyTime->value()); //延时1s电机速度稳定
       if((PhysicsSpeed-last_speed)<ui->error->value())
        {

          QPointF point=QPointF(pwm,PhysicsSpeed);
          series3->append(point);
          up_x.append(pwm);
          up_y.append(PhysicsSpeed);
          pwm-=ui->gap->value();
          QString str= QString("正转有效散点数%1数据点%2 %3").arg(count).arg(pwm).arg(PhysicsSpeed);
          count++;
          ui->DemarcateTips->setText(str);

       }


   }

   ui->DemarcateTips->setText("正转拟合完毕");

   pwm=1550;
   on_PidControllSerial(pwm);
   sleep(ui->Up_Down_Delay->value()); //正反转中间延时
   count=1;
   while(pwm<1900) //一个问题是，如何判断它是反转，手动指定反转
   {
       on_PidControllSerial(pwm);
       sleep(ui->accelerateTime->value()); //延时2s,电机速度变化
       last_speed=-PhysicsSpeed; //认为速度为负值
       sleep(ui->steadyTime->value()); //延时1s电机速度稳定
       if((PhysicsSpeed+last_speed)<ui->error->value())
        {

          QPointF point=QPointF(pwm,-PhysicsSpeed);
          series3->append(point);
          down_x.append(pwm);
          down_y.append(-PhysicsSpeed);
          pwm+=ui->gap->value();
          QString str= QString("反转有效散点数%1数据点%2 %3").arg(count).arg(pwm).arg(-PhysicsSpeed);
          count++;
          ui->DemarcateTips->setText(str);

       }
   }
   //拟合完毕，把电机速度降下来
   pwm=1550;
   on_PidControllSerial(pwm);

    ui->DemarcateTips->setText("反转拟合完毕");
    //线性分段，拟合
    QVector<double> k_b;

    k_b=ployfit(up_x ,up_y ,up_x.count());
    k=k_b[0];
    b=k_b[1];

    k_b=ployfit(down_x ,down_y ,down_x.count());
    k2=k_b[0];
    b2=k_b[1];

   // 绘制拟合曲线
   double ux1,uy1,ux2,uy2;
   ux1=800;ux2=1500;
   uy1=k*ux1+b;
   uy2=k*ux2+b;
   series4->append(ux1,uy1);
   series4->append(ux2,uy2);
   double dx1,dy1,dx2,dy2;
   dx1=1500;dx2=2200;
   dy1=k2*dx1+b2;
   dy2=k2*dx2+b2;
   series4->append(dx1,dy1);
   series4->append(dx2,dy2);
    ui->DemarcateTips->setText("拟合曲线绘制完毕");





}
QVector<double>SerialWidget::ployfit(QVector<double> x ,QVector<double> y ,int anum)
{
    qreal x_mean=0,y_mean=0, x_sum=0,y_sum=0;
    double k,b;
    double up_sum=0;//分子
    double down_sum=0;//分母

    for(int i=0;i<anum;i++)
    {

        x_sum=x_sum+x[i];
        y_sum=y_sum+y[i];

    }
    x_mean=x_sum/anum;
    y_mean=y_sum/anum;
   for(int i=0;i<anum;i++)
   {
        up_sum+=(x[i]-x_mean)*(y[i]-y_mean);
        down_sum+=(x[i]-x_mean)*(x[i]-x_mean);
   }
   k=up_sum/down_sum;
   b=y_mean-k*x_mean;

   QVector<double> k_b;
   k_b.append(k);
   k_b.append(b);
   return k_b;



}
void SerialWidget::on_ClearDemarcate_clicked()
{
    //清除图像
    series3->clear();
    series4->clear();
    //清除拟合
}

void SerialWidget::on_kbsetspeed_clicked()
{
    qreal y=ui->kbspeed->value();
    if(k*k2!=0)
    {
        if(ui->kbspeed->value()>0) //选择正转的拟合曲线
        {
             qreal x=(y-b)/k;
             on_PidControllSerial((int)x); //强制int转换

        }
        else{  //选择反转的拟合曲线
            qreal x=(y-b2)/k2;
            on_PidControllSerial((int)x); //强制int转换

        }


    }
    else{

        ui->DemarcateTips->setText("拟合出的参数曲线存在问题,k=0");
    }
}

void SerialWidget::on_demarcatechart_clicked(bool checked)
{
    if(checked)
    {
        ui->chartView->setChart(demarcatechart);
    }
}
