#include "chartview.h"
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QRandomGenerator>
#include <QtCore/QDebug>

ChartView::ChartView(QWidget *parent, QChart *chart):
    QChartView(chart, parent),
    m_chart(chart),
    m_series(0),
    m_axisX(new QValueAxis()),
    m_axisY(new QValueAxis()),
    m_x(5),
    m_y(0)
{
//    QObject::connect(&m_timer, &QTimer::timeout, this, &Chart::handleTimeout);
//    m_timer.setInterval(500);

    m_series = new QSplineSeries(this);
    QPen green;
    green.setWidth(2);
    m_series->setPen(green);
    m_series->append(m_x, m_y);
    //m_series->setPointsVisible(true);

    m_chart->addSeries(m_series);
    m_axisX->setLabelFormat("%.1f");
    //m_axisY->setLabelFormat("%d");
    m_chart->addAxis(m_axisX,Qt::AlignBottom);
    m_chart->addAxis(m_axisY,Qt::AlignLeft);
    m_series->attachAxis(m_axisX);
    m_series->attachAxis(m_axisY);
    m_axisX->setTickCount(m_x * 2 + 1);
    m_axisX->setRange(0, m_x);
    m_axisY->setRange(-5, 10);

    m_chart->setAnimationOptions(QChart::SeriesAnimations);
    setRenderHint(QPainter::Antialiasing);  //抗锯齿

    m_chart->layout()->setContentsMargins(0, 0, 0, 0);
    //设置内边界全部为0
    m_chart->setMargins(QMargins(0, 0, 0, 0));
    //设置背景区域无圆角
    m_chart->setBackgroundRoundness(0);

    QLegend *mlegend = m_chart->legend();
    mlegend->detachFromChart();
    mlegend->setGeometry(QRectF(30,0,100,100));

    //m_series->setName("cmH2O");


}

ChartView::~ChartView()
{

}

void ChartView::add(qreal y)
{
    qreal x = m_chart->plotArea().width() / (m_axisX->tickCount() - 1);
    m_x += 2;
    m_series->append(m_x, y);
    m_chart->scroll(x, 0);
}

QLineSeries* ChartView::getline(){
    return m_series;
}

//void ChartView::timerEvent(QTimerEvent *){
//    add(QRandomGenerator::global()->bounded(10) - 5);
//}

//void ChartView::start(int interval){
//    startTimer(interval);
//    qDebug()<<"     current thread ID:"<<QThread::currentThreadId()<<'\n';
//}
