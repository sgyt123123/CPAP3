#include "m_widget.h"
#include "ui_m_widget.h"

M_Widget::M_Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::M_Widget)
{
    ui->setupUi(this);

//    ui->widget->setAlternatingRowColors(true);
//    ui->widget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->widget->horizontalHeader()->setStretchLastSection(true);

    //setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    //ui->widget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    layout()->setMargin(0);
    layout()->setContentsMargins(0, 0, 0, 0);

//    setWindowFlags(Qt::SubWindow);
//    showFullScreen();
//    ui->widget->setWindowFlags(Qt::SubWindow);
//    ui->widget->showFullScreen();
//    adjustSize();
//    ui->widget->adjustSize();

    QChart* chart = new QChart();

    AxY = new QValueAxis();
    AxX = new QValueAxis();
    line = new QLineSeries();


    // 将系列添加到图表
    chart->addSeries(line);
    chart->setTheme(QtCharts::QChart::ChartThemeBrownSand);

    //mAxX->setTitleText(QString(tr("ImageNumber")));
    //mAxY->setTitleText(QString(tr("ReadRate(%)")));
    chart->addAxis(AxY, Qt::AlignLeft);
    chart->addAxis(AxX, Qt::AlignBottom);

    line->attachAxis(AxY);
    line->attachAxis(AxX);

    //突出曲线上的点
    line->setPointsVisible(true);

    //图例
    QLegend *mlegend = chart->legend();
    mlegend->detachFromChart();
    mlegend->setGeometry(QRectF(25,0,100,100));
    //mlegend->setAlignment(Qt::AlignTop);
    //chart->legend()->setBackgroundVisible(true);
    //mlegend->setAlignment();
    //mlegend->setVisible(false);

    // 将图表绑定到视图 weiget 为 QChartView

    //隐藏背景
    //chart->setBackgroundVisible(false);
    //设置外边界全部为0
    chart->layout()->setContentsMargins(0, 0, 0, 0);
    //设置内边界全部为0
    chart->setMargins(QMargins(0, 0, 0, 0));
    //设置背景区域无圆角
    chart->setBackgroundRoundness(0);
    ui->widget->setChart(chart);
}

M_Widget::~M_Widget()
{
    delete ui;
}

void M_Widget::timerEvent(QTimerEvent *)
{

}

QLineSeries* M_Widget::getline(){
    return line;
}

QValueAxis* M_Widget::getAxY(){
    return AxY;
}

QValueAxis* M_Widget::getAxX(){
    return AxX;
}
