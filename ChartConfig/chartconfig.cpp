#include "chartconfig.h"
#include "ui_chartconfig.h"

#include    "qwdialogpen.h"

// 若MSVC 编译版本错误，修改 msvc-version.conf 文件
// 解决MSVC编译时，界面汉字乱码的问题
#if _MSC_VER >= 1600     //MSVC2015>1899,    MSVC_VER= 14.0
#pragma execution_character_set("utf-8")
#endif


void ChartConfig::createChart()
{//创建图表的各个部件
    QChart *chart = pchart;
    chart->setTitle(tr("简单函数曲线"));
//    chart->setAcceptHoverEvents(true);
//    ui->chartView->setChart(pchart);
//    ui->chartView->setRenderHint(QPainter::Antialiasing);
    //为了整洁，删去了

    QLineSeries *series0 = new QLineSeries();
    QLineSeries *series1 = new QLineSeries();
    series0->setName("实际速度");
    series1->setName("期望速度");

    curSeries=series0; //当前序列

    QPen    pen;
    pen.setStyle(Qt::DotLine);//Qt::SolidLine, Qt::DashLine, Qt::DotLine, Qt::DashDotLine
    pen.setWidth(2);
    pen.setColor(Qt::red);
    series0->setPen(pen); //折线序列的线条设置

    pen.setStyle(Qt::SolidLine);//Qt::SolidLine, Qt::DashLine, Qt::DotLine, Qt::DashDotLine
    pen.setColor(Qt::blue);
    series1->setPen(pen);//折线序列的线条设置

    chart->addSeries(series0);
    chart->addSeries(series1);

    QValueAxis *axisX = new QValueAxis;
    curAxis=axisX; //当前坐标轴
    axisX->setRange(0, 10); //设置坐标轴范围
    axisX->setLabelFormat("%.1f"); //标签格式
    axisX->setTickCount(11); //主分隔个数
    axisX->setMinorTickCount(4);
    axisX->setTitleText("time(secs)"); //标题
//    axisX->setGridLineVisible(false);

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(-2, 2);
    axisY->setTitleText("value");
    axisY->setTickCount(5);
    axisY->setLabelFormat("%.2f"); //标签格式
//    axisY->setGridLineVisible(false);
    axisY->setMinorTickCount(4);

//  下面4行语句在Qt5.12.1里编译时提示过时（deprecated）了，应使用另外一种方法添加坐标轴
//    chart->setAxisX(axisX, series0); //添加X坐标轴
//    chart->setAxisX(axisX, series1); //添加X坐标轴
//    chart->setAxisY(axisY, series0); //添加Y坐标轴
//    chart->setAxisY(axisY, series1); //添加Y坐标轴

//另一种实现设置坐标轴的方法,在Qt 5.12.1里编译时不会提示过时
    chart->addAxis(axisX,Qt::AlignBottom); //坐标轴添加到图表，并指定方向
    chart->addAxis(axisY,Qt::AlignLeft);

    series0->attachAxis(axisX); //序列 series0 附加坐标轴
    series0->attachAxis(axisY);

    series1->attachAxis(axisX);//序列 series1 附加坐标轴
    series1->attachAxis(axisY);

    foreach (QLegendMarker* marker, chart->legend()->markers()) {
        QObject::disconnect(marker, SIGNAL(clicked()), this, SLOT(on_LegendMarkerClicked()));
        QObject::connect(marker, SIGNAL(clicked()), this, SLOT(on_LegendMarkerClicked()));
    }
}

void ChartConfig::prepareData()
{//为序列生成数据
    QLineSeries *series0=(QLineSeries *)pchart->series().at(0);
    QLineSeries *series1=(QLineSeries *)pchart->series().at(1);

    series0->clear(); //清除数据
    series1->clear();

    qsrand(QTime::currentTime().second());//随机数初始化
    qreal   t=0,y1,y2,intv=0.1;
    qreal   rd;
    int cnt=100;
    for(int i=0;i<cnt;i++)
    {
        rd=(qrand() % 10)-5; //随机数,-5~+5
        y1=qSin(t)+rd/50;
        *series0<<QPointF(t,y1);  //序列添加数据点
//        series0->append(t,y1);  //序列添加数据点

        rd=(qrand() % 10)-5; //随机数,-5~+5
        y2=qCos(t)+rd/50;
//        series1->append(t,y2); //序列添加数据点
        *series1<<QPointF(t,y2); //序列添加数据点

        t+=intv;
    }
}

void ChartConfig::updateFromChart()
{ //从图表上获取数据更新界面显示
    QChart  *aChart;
    aChart=pchart;  //获取chart

    ui->editTitle->setText(aChart->title()); //图表标题

    QMargins    mg=aChart->margins(); //边距
    ui->spinMarginLeft->setValue(mg.left());
    ui->spinMarginRight->setValue(mg.right());
    ui->spinMarginTop->setValue(mg.top());
    ui->spinMarginBottom->setValue(mg.bottom());
}

ChartConfig::ChartConfig(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChartConfig)
{
    ui->setupUi(this);
     /**设置数据的方法**/
    //pchart ->set....
    pchart=new QChart ;
    createChart();//创建图表
    prepareData();//生成数据
    updateFromChart(); //从图表获得属性值，刷新界面显示
}

ChartConfig::~ChartConfig()
{
    delete ui;
}

void ChartConfig::on_LegendMarkerClicked()
{
    QLegendMarker* marker = qobject_cast<QLegendMarker*> (sender());

    switch (marker->type())
    {
        case QLegendMarker::LegendMarkerTypeXY:
        {
            marker->series()->setVisible(!marker->series()->isVisible());
            marker->setVisible(true);
            qreal alpha = 1.0;
            if (!marker->series()->isVisible())
                alpha = 0.5;

            QColor color;
            QBrush brush = marker->labelBrush();
            color = brush.color();
            color.setAlphaF(alpha);
            brush.setColor(color);
            marker->setLabelBrush(brush);

            brush = marker->brush();
            color = brush.color();
            color.setAlphaF(alpha);
            brush.setColor(color);
            marker->setBrush(brush);

            QPen pen = marker->pen();
            color = pen.color();
            color.setAlphaF(alpha);
            pen.setColor(color);
            marker->setPen(pen);
            break;
        }
        default:
            break;
    }


}

void ChartConfig::on_actDraw_triggered()
{ //重新生成数据
    prepareData();//重新生成数据
}

void ChartConfig::on_btnSetTitle_clicked()
{ //设置图标标题文字
    QString str=ui->editTitle->text();
    pchart->setTitle(str);
}

void ChartConfig::on_btnSetTitleFont_clicked()
{ //设置图标标题文字的字体
    QFont font=pchart->titleFont();
    bool  ok=false;
    font=QFontDialog::getFont(&ok,font);
    if (ok)
        pchart->setTitleFont(font);
}

void ChartConfig::on_btnSetMargin_clicked()
{//设置图标的4个边距
    QMargins    mgs;
    mgs.setLeft(ui->spinMarginLeft->value());
    mgs.setRight(ui->spinMarginRight->value());
    mgs.setTop(ui->spinMarginTop->value());
    mgs.setBottom(ui->spinMarginBottom->value());
    pchart->setMargins(mgs);
}

void ChartConfig::on_chkPointVisible_clicked(bool checked)
{//序列的数据点是否可见
    curSeries->setPointsVisible(checked);
}

void ChartConfig::on_chkPointLabelVisible_clicked(bool checked)
{ //序列的数据点标签是否可见
    curSeries->setPointLabelsVisible(checked);
}

void ChartConfig::on_btnSeriesName_clicked()
{ //设置序列名称
    curSeries->setName(ui->editSeriesName->text());
    if (ui->radioSeries0->isChecked())
        ui->radioSeries0->setText(ui->editSeriesName->text());
    else
        ui->radioSeries1->setText(ui->editSeriesName->text());
}

void ChartConfig::on_btnSeriesColor_clicked()
{ //序列的曲线颜色
    QColor  color=curSeries->color();

    color=QColorDialog::getColor(color);
    if (color.isValid())
      curSeries->setColor(color);
}

void ChartConfig::on_chkLegendVisible_clicked(bool checked)
{//图例是否可见
    pchart->legend()->setVisible(checked);
}

void ChartConfig::on_btnSetAxisRange_clicked()
{ //设置坐标轴的坐标范围
    curAxis->setRange(ui->spinAxisMin->value(),ui->spinAxisMax->value());

}

void ChartConfig::on_spinTickCount_valueChanged(int arg1)
{
    curAxis->setTickCount(arg1);
}

void ChartConfig::on_spinMinorTickCount_valueChanged(int arg1)
{
    curAxis->setMinorTickCount(arg1);
}

void ChartConfig::on_radioX_clicked()
{ //获取当前坐标轴
// 在Qt 5.12.1中编译时提示 QChart::axisX()和QChart::axisY()函数过时，应使用 QChart::axes()函数
//    if (ui->radioX->isChecked())
//        curAxis=(QValueAxis*)pchart->axisX();
//    else
//        curAxis=(QValueAxis*)pchart->axisY();

//  下面是针对Qt 5.12.1修改的代码
    QList<QAbstractAxis*> axes;
    if (ui->radioX->isChecked())
        axes=pchart->axes(Qt::Horizontal);
    else
        axes=pchart->axes(Qt::Vertical);
    curAxis=(QValueAxis*)axes[0];


//获取坐标轴的各种属性，显示到界面上
    ui->spinAxisMin->setValue(curAxis->min());
    ui->spinAxisMax->setValue(curAxis->max());

    ui->editAxisTitle->setText(curAxis->titleText());
    ui->chkBoxAxisTitle->setChecked(curAxis->isTitleVisible());

    ui->editAxisLabelFormat->setText(curAxis->labelFormat());
    ui->chkBoxLabelsVisible->setChecked(curAxis->labelsVisible());

    ui->chkGridLineVisible->setChecked(curAxis->isGridLineVisible());
    ui->chkAxisLineVisible->setChecked(curAxis->isLineVisible());

    ui->spinTickCount->setValue(curAxis->tickCount());
    ui->chkAxisLineVisible->setChecked(curAxis->isLineVisible());

    ui->spinMinorTickCount->setValue(curAxis->minorTickCount());
    ui->chkMinorTickVisible->setChecked(curAxis->isMinorGridLineVisible());
}

void ChartConfig::on_radioY_clicked()
{
    on_radioX_clicked();
}

void ChartConfig::on_chkGridLineVisible_clicked(bool checked)
{ //轴的网格线是否可见
    curAxis->setGridLineVisible(checked);
}

void ChartConfig::on_chkMinorTickVisible_clicked(bool checked)
{ //次级刻度是否可见
    curAxis->setMinorGridLineVisible(checked);
}


void ChartConfig::on_chkBoxLegendBackground_clicked(bool checked)
{//图例的背景是否可见
    pchart->legend()->setBackgroundVisible(checked);
}

void ChartConfig::on_radioButton_clicked()
{//图例的位置
    pchart->legend()->setAlignment(Qt::AlignTop);
}

void ChartConfig::on_radioButton_2_clicked()
{//图例的位置
    pchart->legend()->setAlignment(Qt::AlignBottom);
}

void ChartConfig::on_radioButton_3_clicked()
{//图例的位置
    pchart->legend()->setAlignment(Qt::AlignLeft);
}

void ChartConfig::on_radioButton_4_clicked()
{//图例的位置
    pchart->legend()->setAlignment(Qt::AlignRight);
}

void ChartConfig::on_btnLegendFont_clicked()
{ //图例的字体设置
    QFont font=pchart->legend()->font();
    bool  ok=false;
    font=QFontDialog::getFont(&ok,font);
    if (ok)
        pchart->legend()->setFont(font);
}

void ChartConfig::on_btnLegendlabelColor_clicked()
{//图例的文字颜色设置
    QColor  color=pchart->legend()->labelColor();
    color=QColorDialog::getColor(color);
    if (color.isValid())
        pchart->legend()->setLabelColor(color);
}

void ChartConfig::on_chkBoxVisible_clicked(bool checked)
{ //坐标轴是否可见
    curAxis->setVisible(checked);
}


void ChartConfig::on_btnAxisSetTitle_clicked()
{ //设置坐标轴的标题
    curAxis->setTitleText(ui->editAxisTitle->text());
}

void ChartConfig::on_btnAxisSetTitleFont_clicked()
{ //设置坐标轴的标题的字体
    QFont   font=curAxis->titleFont();

    bool    ok=false;
    font=QFontDialog::getFont(&ok,font);
    if (ok)
       curAxis->setTitleFont(font);
}

void ChartConfig::on_chkBoxAxisTitle_clicked(bool checked)
{ //轴标题是否可见
    curAxis->setTitleVisible(checked);
}

void ChartConfig::on_pushButton_clicked()
{//设置坐标轴刻度标签的文字格式
    curAxis->setLabelFormat(ui->editAxisLabelFormat->text());
}

void ChartConfig::on_btnAxisLabelColor_clicked()
{//设置坐标轴刻度标签的文字颜色
    QColor   color=curAxis->labelsColor();

    color=QColorDialog::getColor(color);
    if (color.isValid())
       curAxis->setLabelsColor(color);
}

void ChartConfig::on_btnAxisLabelFont_clicked()
{//设置坐标轴刻度标签的文字字体
    QFont   font=curAxis->labelsFont();

    bool    ok=false;
    font=QFontDialog::getFont(&ok,font);
    if (ok)
       curAxis->setLabelsFont(font);
}

void ChartConfig::on_chkBoxLabelsVisible_clicked(bool checked)
{//轴的刻度标签是否可见
   curAxis->setLabelsVisible(checked);
}

void ChartConfig::on_btnGridLineColor_clicked()
{ //网格线的颜色设置
    QColor   color=curAxis->gridLineColor();

    color=QColorDialog::getColor(color);
    if (color.isValid())
       curAxis->setGridLineColor(color);
}

void ChartConfig::on_pushButton_10_clicked()
{ //网格线的Pen设置
    QPen    pen;
    pen=curAxis->gridLinePen();

    bool    ok=false;
    pen=QWDialogPen::getPen(pen,ok);

    if (ok)
      curAxis->setGridLinePen(pen);
}

void ChartConfig::on_chkAxisLineVisible_clicked(bool checked)
{//刻度是否可见
    curAxis->setLineVisible(checked);
}

void ChartConfig::on_btnAxisLinePen_clicked()
{
    QPen    pen;
    pen=curAxis->linePen();

    bool    ok=false;
    pen=QWDialogPen::getPen(pen,ok);

    if (ok)
      curAxis->setLinePen(pen);
}


void ChartConfig::on_btnAxisLinePenColor_clicked()
{
    QColor   color=curAxis->linePenColor();

    color=QColorDialog::getColor(color);
    if (color.isValid())
       curAxis->setLinePenColor(color);
}

void ChartConfig::on_btnMinorColor_clicked()
{//次级刻度网格线颜色
    QColor   color=curAxis->minorGridLineColor();

    color=QColorDialog::getColor(color);
    if (color.isValid())
       curAxis->setMinorGridLineColor(color);
}

void ChartConfig::on_btnMinorPen_clicked()
{//次级刻度线Pen设置
    QPen    pen;
    pen=curAxis->minorGridLinePen();

    bool    ok=false;
    pen=QWDialogPen::getPen(pen,ok);

    if (ok)
      curAxis->setMinorGridLinePen(pen);
}

void ChartConfig::on_radioSeries0_clicked()
{//获取当前数据序列
    if (ui->radioSeries0->isChecked())
        curSeries=(QLineSeries *)pchart->series().at(0);
    else
        curSeries=(QLineSeries *)pchart->series().at(1);
//获取序列的属性值，并显示到界面上
    ui->editSeriesName->setText(curSeries->name());
    ui->chkSeriesVisible->setChecked(curSeries->isVisible());
    ui->chkPointVisible->setChecked(curSeries->pointsVisible());
    ui->sliderSeriesOpacity->setValue(curSeries->opacity()*10);
    ui->chkPointLabelVisible->setChecked(curSeries->pointLabelsVisible());
}

void ChartConfig::on_radioSeries1_clicked()
{
    on_radioSeries0_clicked();
}


void ChartConfig::on_chkSeriesVisible_clicked(bool checked)
{//序列是否可见
    this->curSeries->setVisible(checked);
}

void ChartConfig::on_btnSeriesPen_clicked()
{//序列线条的Pen设置
    bool    ok=false;
    QPen    pen;
    pen=curSeries->pen();

    pen=QWDialogPen::getPen(pen,ok);

    if (ok)
      curSeries->setPen(pen);
}

void ChartConfig::on_sliderSeriesOpacity_valueChanged(int value)
{//序列的透明度
    curSeries->setOpacity(value/10.0);
}

void ChartConfig::on_btnSeriesLabColor_clicked()
{//序列数据点标签颜色
    QColor  color=curSeries->pointLabelsColor();

    color=QColorDialog::getColor(color);
    if (color.isValid())
      curSeries->setPointLabelsColor(color);

}

void ChartConfig::on_btnSeriesLabFont_clicked()
{//序列数据点标签字体
    QFont   font;
    font=curSeries->pointLabelsFont();
    bool    ok=false;
    font=QFontDialog::getFont(&ok,font);
    if (ok)
        curSeries->setPointLabelsFont(font);
}

void ChartConfig::on_radioSeriesLabFormat0_clicked()
{ //序列数据点标签的显示格式
    curSeries->setPointLabelsFormat("@yPoint");
}

void ChartConfig::on_radioSeriesLabFormat1_clicked()
{//序列数据点标签的显示格式
    curSeries->setPointLabelsFormat("(@xPoint,@yPoint)");
}

void ChartConfig::on_cBoxAnimation_currentIndexChanged(int index)
{//动画效果
    pchart->setAnimationOptions(QChart::AnimationOptions(index));
//    pchart->setAnimationOptions(QChart::SeriesAnimations);
//    pchart->setAnimationOptions(QChart::AllAnimations);
}


void ChartConfig::on_cBoxTheme_currentIndexChanged(int index)
{ //图标的主题
    pchart->setTheme(QChart::ChartTheme(index));
}

void ChartConfig::on_actZoomIn_triggered()
{//放大
    pchart->zoom(1.2);//zoomIn();
}

void ChartConfig::on_actZoomOut_triggered()
{//缩小
    pchart->zoom(0.8);//zoomOut();
}

void ChartConfig::on_actZoomReset_triggered()
{//复位
    pchart->zoomReset();
}

void ChartConfig::on_toolBox_currentChanged(int index)
{
    if(index==1)
        on_radioSeries0_clicked();
    if(index==2)
        on_radioX_clicked();
}
