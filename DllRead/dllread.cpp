#include "dllread.h"
#include "ui_dllread.h"
#include"USBDAQ8API.h"
#include"chartconfig.h"
#include"QtRoundProgressBar.h"
#include <vector>
#include <QtCharts/QAbstractAxis>
using namespace std;

/**/
void Own_Convert(UCHAR *pOrg,double *rData,INT Len,INT ChannelCount)
{
    int rindex[8] = {0,0,0,0,0,0,0,0};
      for (int index = 0; index < ChannelCount * Len; ++index) {
        unsigned char low = pOrg[2*index]; //高位
        unsigned char high = pOrg[2*index + 1]; //低位
        unsigned short ADCDATA=(high << 8) + low; //高位移8加上低位，完全位

        switch(7-(high>>4)) {
        case 0:  //0*5+
          rData[0*Len + rindex[0]++] = 5000.00 - (ADCDATA & 0xFFF) * 10000.00 / 4096.00;
          break;
        case 1: //1*5+
          rData[1*Len + rindex[1]++] = 5000.00 - (ADCDATA & 0xFFF) * 10000.00 / 4096.00;
          break;
        case 2:
          rData[2*Len + rindex[2]++] = 5000.00 - (ADCDATA & 0xFFF) * 10000.00 / 4096.00;
          break;
        case 3:
          rData[3*Len + rindex[3]++] = 5000.00 - (ADCDATA & 0xFFF) * 10000.00 / 4096.00;
          break;
        case 4:
          rData[4*Len + rindex[4]++] = 5000.00 - (ADCDATA & 0xFFF) * 10000.00 / 4096.00;
          break;
        case 5:
          rData[5*Len + rindex[5]++] = 5000.00 - (ADCDATA & 0xFFF) * 10000.00 / 4096.00;
          break;
        case 6:
          rData[6*Len + rindex[6]++] = 5000.00 - (ADCDATA & 0xFFF) * 10000.00 / 4096.00;
          break;
        case 7:
          rData[7*Len + rindex[7]++] = 5000.00 - (ADCDATA & 0xFFF) * 10000.00 / 4096.00;
          break;
        default:
          break;
        }
      }
 }

/*----重写方法------*/
int USBDAQ8_INIT()
{
    int iRtv;
    iRtv =(int) USB8CHDAQ_INIT();
   return iRtv;
}
int USBDAQ8_DAQ(int handle,int channel,int fre,int len)
{
//调用方法 USBDAQ8_DAQ(handle, 8,10000,1000)

    int mex_handle,mex_channel,mex_fre,mex_len,iRtv;
    int returnvalue; //右边的变量
    mex_handle = handle;
    mex_channel = channel;
    mex_fre = fre;
    mex_len = len;
    mex_channel = mex_channel & 0xFF;
    mex_channel = 1 << (8 - mex_channel);//移位操作
    // mex_channel = 1 << (8 - mex_channel);//移位操作
    //8-5=3, 1的二进制 0000 0001  左移3位 0000 1000 十进制的8，通道5

    if(mex_fre > 400000)
       {
           iRtv = -3;
           goto R;
       }
       iRtv = USB8CHDAQ_DAQ((HANDLE)mex_handle,mex_channel,mex_fre,mex_len);
       R:
       returnvalue=iRtv;

       return returnvalue;

}
QVector<double> USBDAQ8_ReadData_Continue(int handle,int len,int channel)
{// 调用格式 USBDAQ8_ReadData_Continue(handle,1000,5)

    int mex_handle,mex_len,mex_channel,iRtv;
    mex_handle = handle;
    mex_len = len;
    mex_channel = channel;
    UCHAR* pData = new UCHAR[2*mex_len];
    double * dData=new double [8*mex_len];
   for(int i=0;i<8*mex_len;i++)
   {
      dData[i]=0; //为了避免出现极大值和极小值进行初始化
   }

    mex_channel = mex_channel & 0xFF;

     mex_channel = 1 << (8 - mex_channel);//移位操作

     //8-5=3, 1的二进制 0000 0001  左移3位 0000 0100 十进制的8，通道5

    iRtv = USB8CHDAQ_ReadData_Continue((HANDLE)mex_handle,2*mex_len,pData);
    //虽然返回值是iRtv，只是一个判断值，而非数组值，是通过pData获取数组值
    if(!iRtv)
        for(int i = 0; i < 8*mex_len;++i)
            dData[i] = 0; //为了避免完全没有数据，令它为20
    else
     {  USB8CHDAQ_Convert(pData,dData,mex_len,1);
        }


    //pData是函数中的数据，dData是 返回数据的指针,通过dData 修改
    for(int i=0;i<20;i++)
    {
        qDebug()<<"pData"<<pData[i]<<" | ";
    }

    QVector<double >array;

    for(int i=mex_len*(channel-1);i<mex_len*channel;i++) //channel=5
    {
        array.append(dData[i]-500);

    }
    qDebug()<<"数据大小"<<array.count();
//    for(int i=0;i<20;i++)
//    {
//        qDebug()<<"array"<<array[i]<<" | ";
//    }
    //直接输出8000个点看看吧
//    for(int i=0;i<8*mex_len;i++)
//    {
//       qDebug()<<i<<dData[i]; //为了避免出现极大值和极小值进行初始化
//    }


    delete []pData;
    delete []dData;
    return array;

}
void USBDAQ8_QUIT(int handle)
{
    int mex_handle=handle;
    USB8CHDAQ_QUIT((HANDLE)mex_handle);

}
/*-----重写方法----*/
/*自定义函数*/
// 生成有n个元素的随机数组,每个元素的随机范围为[rangeL, rangeR] 闭区间
double *generateRandomArray(int n, int rangeL, int rangeR) {
    assert(rangeL <= rangeR);

    double *arr = new double[n]; // 创建一个 n个元素的数组

    srand(time(NULL)); // 随机种子
    for (int i = 0; i < n; i++)
        arr[i] = rand() % (rangeR - rangeL + 1) + rangeL,qDebug()<<arr[i];

    return arr;
}
/*自定义函数*/
DllRead::DllRead(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DllRead)
{
    ui->setupUi(this);
    /****/
    data<<0<<0<<0<<0<<0<<0; //
    data.clear();
    qDebug()<<data.count();
    /***/
    PhysicsIsGood=0;
    /**----定时器初始化----*/
    SignalTimer=new QTimer(this);
    SignalTimer->stop();
    rsum=0;
    //SignalTimer->setInterval(1000);
    connect(SignalTimer,SIGNAL(timeout()),this,SLOT(on_timer_timeout())); //关联定时器的信号与槽
    /**---采样频率与采样数的初始化----**/
    fn=ui->freqn->value();
    freq=ui->freq->value();
    dt=1.0/freq;  //1是整数 1/1000 得到的是0
    timeperiod=dt*fn;
    ChartInit();
    ActionInit();
    /**速度仪表盘的初始化---**/
    SpeedpanelInit();

    /*幅值频率调整*/
    ui->ampslide->setShowValue(1);
    ui->freqslide->setShowValue(1);
    ui->ampslide->setShowPointer(1);
    ui->freqslide->setShowPointer(1);
    ui->freqslide->setPointerStyle(ui->freqslide->Triangle);
    ui->ampslide->setPointerStyle(ui->ampslide->Triangle);
    ui->ampslide->setRange(0,100);
    ui->freqslide->setRange(0,1000);
     connect(ui->freqslide, SIGNAL(customsignal()), this, SLOT(setfreqValue()));
    connect(ui->ampslide, SIGNAL(customsignal()), this, SLOT(setampValue()));
     ui->freqslide->setValue(10);
     ui->ampslide->setValue(20);
    virtualfreq=10;
     virtualamp=20;
    /*波形发生器的初始化**/
     qDebug()<<"采样数"<<fn<<"采样频率"<<freq<<"采样率"<<dt;
     qDebug()<<"幅值"<<virtualamp<<"频率"<<virtualfreq<<"采样时间"<<dt;
    wave_Obj.initialize(virtualamp,virtualfreq,dt);//幅值，频率，采样时间

    //采集卡状态
     cardflag=false;
    handle=0;
    //通过日志来记录错误


}
void DllRead::SpeedpanelInit()
{
    QPalette p1;
    p1.setBrush(QPalette::AlternateBase, Qt::black);
    p1.setColor(QPalette::Text, Qt::white);
//    ui->speedpanel->setBarStyle(QtRoundProgressBar::StyleLine);
    ui->speedpanel->setPalette(p1);
    ui->speedpanel->setOutlinePenWidth(1);
    QGradientStops gradientPoints;
    gradientPoints << QGradientStop(0, Qt::green) << QGradientStop(0.5, Qt::yellow) << QGradientStop(1, Qt::red);
    ui->speedpanel->setDataColors(gradientPoints);
    ui->speedpanel->setFormat("%v");
    ui->speedpanel->setValue(0);
    ui->speedpanel->setRange(ui->lower->value(),ui->upper->value()); //初始化
}
void DllRead::setfreqValue()
{
    virtualfreq= ui->freqslide->Value();
     wave_Obj.terminate();
     wave_Obj.initialize( virtualamp,virtualfreq,dt);
     //qDebug()<<"虚拟频率"<<virtualfreq;
}
void DllRead::setampValue()
{
    virtualamp= ui->ampslide->Value();
    wave_Obj.terminate();
    wave_Obj.initialize(virtualamp,virtualfreq,dt);
    //  qDebug()<<"虚拟频幅值"<<virtualamp;
    //qDebug()<<"虚拟频率"<<virtualfreq;
}
void DllRead::ChartInit()
{
    /*图表*/
    /*抗锯齿----*/
    ui->WavechartView->setRenderHint(QPainter::Antialiasing);
    ui->SpeedchartView->setRenderHint(QPainter::Antialiasing);
    chart=new QChart();
    ui->WavechartView->setChart(chart);
    series0 = new QLineSeries();
    series0->setName("随机波形曲线");

    chart->addSeries(series0); //序列添加到图表
    chart->setTheme(QChart::ChartThemeBlueCerulean);//设置系统主题
    chart->setTitle("随机曲线");//设置标题
    chart->setTitleFont(QFont("微软雅黑",10));
    chart->createDefaultAxes();
    axisX = new QValueAxis; //X 轴
   QValueAxis *axisY = new QValueAxis; //Y 轴
   axisX->setRange(0, 0.25); //设置坐标轴范围
    axisX->setTitleText("time(secs)"); //标题
   axisY->setRange(-1000, 5000);
   axisY->setTitleText("value");
   axisX->setGridLineVisible(1);
   chart->setAxisX(axisX, series0); //为序列设置坐标轴
   chart->setAxisY(axisY, series0); //
   /**-------***/
   speedchart= new QChart();
   ui->SpeedchartView->setChart(speedchart);
   series1 = new QSplineSeries();
   series1->setName("速度平均值曲线");
   speedchart->addSeries(series1); //序列添加到图表
  speedchart->setTheme(QChart::ChartThemeDark);//设置系统主题
   speedchart->setTitle("速度平均值曲线");//设置标题
   speedchart->setTitleFont(QFont("微软雅黑",10));
   QValueAxis *axisY1 = new QValueAxis; //Y 轴
   axisX1 = new QValueAxis; //Y 轴
   axisX1->setRange(0, 10); //设置坐标轴范围
    axisX1->setTitleText("time(secs)"); //标题
   axisY1->setRange(0, 3000);
   axisY1->setTitleText("value");
   axisX1->setGridLineVisible(1);
   speedchart->setAxisX(axisX1, series1); //为序列设置坐标轴
   speedchart->setAxisY(axisY1, series1); //
   //加速
 // series0->setUseOpenGL(true);// 会导致菜单栏黑化



}
void DllRead::ActionInit()
{
    ui->WavechartView->addAction(ui->waveconfig);
    ui->SpeedchartView->addAction(ui->speedconfig);
}
void DllRead::on_waveconfig_triggered()
{
    static int waveNum = 1;
    QString cur = tr("波形图设置%1").arg(waveNum++);
    ChartConfig * chartconfig=new ChartConfig;
    chartconfig->setAttribute(Qt::WA_DeleteOnClose);
    chartconfig->setWindowTitle(cur);
    chartconfig->show();
    chartconfig->pchart=ui->WavechartView->chart();
    qDebug()<<"wave设置界面打开";
}
void DllRead::on_speedconfig_triggered()
{
    static int sppedNum = 1;
    QString cur = tr("速度图设置%1").arg(sppedNum++);
    ChartConfig * chartconfig=new ChartConfig;
    chartconfig->setAttribute(Qt::WA_DeleteOnClose);
    chartconfig->setWindowTitle(cur);
    chartconfig->show();
    chartconfig->pchart=ui->SpeedchartView->chart();
    qDebug()<<"speed设置界面打开";
}
DllRead::~DllRead()
{
    delete ui;
}
void DllRead::on_timer_timeout()
{
 static int timenum=0;
 timenum+=1;
 QString str="当前已经运行："+QString::number(timenum*ui->timeperiod->value())+"s";
 //qDebug()<<str;
 ui->tips->setText(str);
 //qDebug()<<"虚拟频幅值"<<virtualamp;
 //qDebug()<<"虚拟频率"<<virtualfreq;

 //data用于存放数据，那么每次都要初始化
 data.clear();
 if(ui->physics->isChecked()&&PhysicsIsGood) //(ui->physics->isChecked()&&PhysicsIsGood)
 {

    qDebug()<<"ReadData读取数据的句柄为："<<handle;
    if(handle) //更进一步的保护
        data=USBDAQ8_ReadData_Continue(handle,fn,ui->channel->value()); //读取缓冲区通道5数据


 }
 else if(ui->square->isChecked())
 {    qDebug()<<"square";
     for (int i=0;i<fn;i++)
       {
           wavert_OneStep();
           data.append(wave_Obj.wave_Y.SquareWaveOut);

      }
 }
 else if(ui->sin->isChecked()) //正弦波
 {      qDebug()<<"sin";
     for (int i=0;i<fn;i++)
       {
           wavert_OneStep();
           data.append(wave_Obj.wave_Y.SinWaveOut);

      }
 }
 else if(ui->saw->isChecked())
 {   qDebug()<<"saw";
     for (int i=0;i<fn;i++)
       {
           wavert_OneStep();
           data.append(wave_Obj.wave_Y.SawWaveOut);

      }
 }

on_PlotChart_clicked(data,data.count());
qDebug()<<"数据个数"<<data.count();
 /***测试用虚拟数据***/

}
void DllRead::on_PlotChart_clicked(QVector<double> array,int anum)
{ //绘制图形
//对于指针指向的数组，无法判断数组大小

    series0->clear();
    //series1->clear();
    qreal t=0; //不滚动
    static qreal spt=0; //滚动
    int count=0;

    qreal   y1;
    QList<QPointF>Points;
    //QPointF Points2;
    qreal sum;
    for(int i=0;i<anum-1;i++)
    {
        if(array[i]*array[i+1]<0)
        {
          count++;
        }
        y1=array[i];
        Points.append(QPointF(t,y1));
        sum=sum+y1;
        t+=dt;
       // qDebug()<<array[i];
    }
    //series0->replace(Points);
    series0->append(Points);

    /****************速度****************/

    /**---速度显示-----*/

    rsum=rsum+count;
    //由于首段不符合过零，所以加1补偿一下，假如速度为0就是个错误。
    if(ui->noTrans->isChecked())
    {
        if(count%2) //为奇数
        {
           actualspped=3+(count)/2/timeperiod; //转化为分钟
        }
        else{
           actualspped=2+(count)/2/timeperiod; //转化为分钟
        }

    }
    else
    {
        actualspped=(count)/2/timeperiod/(ui->ratio->value())*60; //转化为分钟
    }

    ui->speedpanel->setValue(actualspped); //速度显示会调用updata(),重绘
    series1->append(QPointF(spt,actualspped));
    /*----发出信号---*/
    emit SpeedUpdate(actualspped );
     spt+=timeperiod;
    //qDebug()<<"时刻"<<spt<<"坐标点"<<count;
    /*----一些测试*/
    static int plotnum=0;
    plotnum+=1;
    //qDebug()<<"当前已经绘制过："<<plotnum<<"幅图"<<"速度"<<count;
    /*--滚动轴----*/
    qreal range=axisX1->max()-axisX1->min();
    //一个数据点的宽度
     qreal area=timeperiod/range*speedchart->plotArea().width();
       qDebug()<<"时间宽度"<<timeperiod<<"区域宽度"<<area;
      if(plotnum>(range/timeperiod -0))  //range/timeperiod -1  如果时间步太短，则看不出，可适当增加
        {  //此处的滚动策略为，预留一个数据，看到末端
          //此处的时间指的定时器刷新时间
          speedchart->scroll(area, 0); //timeperiod/range *wodth

       }
     /******/

}


void DllRead::on_TestButton_clicked()
{
    /* void *是一种无类型指针，任何类型指针都可以转为void\*，它无条件接受各种类型。*/
    QString str;

    //handle 为0x 0
    if(!cardflag) //采集卡关闭状态才能初始化
        {
         handle=USBDAQ8_INIT();

        QString s2 = QString("原始句柄:%1").arg(handle);
        ui->tips->setText(s2);
         qDebug()<<"句柄值为"<<handle;

        str.setNum(handle);
        str="句柄值为："+str;
        ui->state->setText(str);
       }

    if(handle) //如果句柄不为0，则表示采集卡打开
      {  cardflag=true;

        }

    else
       { cardflag=false;

        }
   // handle=(long long)(handle);
}

void DllRead::on_StartAcquire_clicked()
{

    /***测试用虚拟数据***///实际上应该加入{}内，此处测试用
       SignalTimer->start((ui->timeperiod->value())*1000) ; //单位为ms
       qDebug()<<"开始采集";
    /***测试用虚拟数据***/


}

void DllRead::on_StopAcquire_clicked()
{


     SignalTimer->stop() ;
}

void DllRead::on_timetest_clicked()
{
//    double* array=generateRandomArray(10, 0, 5);
//    on_PlotChart_clicked(array,10);
}


void DllRead::on_lower_editingFinished()
{
     ui->speedpanel->setRange(ui->lower->value(),ui->upper->value()); //初始化
}

void DllRead::on_upper_editingFinished()
{
    ui->speedpanel->setRange(ui->lower->value(),ui->upper->value()); //初始化 //初始化
}
void DllRead::wavert_OneStep(void)
{
      static boolean_T OverrunFlag = false;

      // Disable interrupts here

      // Check for overrun
      if (OverrunFlag) {
        rtmSetErrorStatus(wave_Obj.getRTM(), "Overrun");
        return;
      }

      OverrunFlag = true;

      // Save FPU context here (if necessary)
      // Re-enable timer or interrupt here
      // Set model inputs here

      // Step the model for base rate
      wave_Obj.step();

      // Get model outputs here

      // Indicate task complete
      OverrunFlag = false;

      // Disable interrupts here
      // Restore FPU context here (if necessary)
      // Enable interrupts here
}

void DllRead::on_freq_editingFinished()
{

   freq=ui->freq->value();
   dt=1.0/freq;

   wave_Obj.initialize( virtualamp,virtualfreq,dt);
   timeperiod=dt*fn;
}

void DllRead::on_freqn_editingFinished()
{
     fn=ui->freqn->value();
     timeperiod=dt*fn;
}

void DllRead::on_cardset_clicked()
{

if (handle)
{
    int revalue=USBDAQ8_DAQ(handle, 5,freq,fn); //返回值如果是正整数1，说明设置成功，
    qDebug()<<"USBDAQ8_DAQ设置的返回值为："<<revalue;
    QString str;
    str.setNum(revalue);
    str="设置的返回值为："+str;
    ui->cardsettips->setText(str);
    if (revalue==1)  //设置的条件判断，正常模式  1
    {
        PhysicsIsGood=1;
    ui->state->setText("设置成功");
    ui->cardquittips->setText("采集卡设置成功");

    }
    else
    {
        ui->cardsettips->setText("参数设置失败");
        PhysicsIsGood=0;
    }
}
else{

    ui->cardsettips->setText("句柄值为0，请检查");
}

}

void DllRead::on_cardquit_clicked()
{
    if(handle)
    {

        USBDAQ8_QUIT(handle);
        ui->cardquittips->setText("采集卡已经退出");
        cardflag=false;
        //退出之后，句柄值应该重置为0，防止退出两次
        handle=0;

    }
    else{

         ui->cardquittips->setText("句柄值为0，请检查");

    }

}

void DllRead::on_convert_clicked()
{
    int mex_len=10;

    UCHAR* pData = new UCHAR[2*mex_len];
    double * dData=new double [8*mex_len] ;


//   for(int i=0;i<2*mex_len;i++)
//   {
//      pData[i]=77;
//   }
    UCHAR  ta[]={128,52,215,5,72,101,237,4,0,0,0,0,7,2,0,0,48,54,239,4};
       for(int i=0;i<20;i++)
       {
          pData[i]=ta[i];
       }

   for(int i=0;i<8*mex_len;i++)
   {
      dData[i]=0;
   }
    USB8CHDAQ_Convert(pData,dData,mex_len,1);

    QVector<double >array;

    for(int i=mex_len*5;i<mex_len*(5+1);i++)
    {
        array.append(dData[i]);
        //按照预期则输出i=10*5 到10*6
        //实际上是70-80
     // mex_channel = 1 << (8 - mex_channel);//移位操作
     //8-5=3, 1的二进制 0000 0001  左移3位 0000 0100 十进制的4，通道6

    }
    qDebug()<<"数据大小"<<array.count();
    for(int i=0;i<10;i++)
    {
        qDebug()<<"array"<<array[i]<<" | ";
    }

    for(int i=0;i<8*mex_len;i++)
    {
       qDebug()<<"dData"<<i<<dData[i]<<" | ";
    }


}
