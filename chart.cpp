#include "chart.h"
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QRandomGenerator>
#include <QtCore/QDebug>
#include <QtCharts>

Chart::Chart(QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(QChart::ChartTypeCartesian, parent, wFlags),
    m_series(0),
    m_axisX(new QValueAxis()),
    m_axisY(new QValueAxis()),
    m_step(0),
    m_x(10),
    m_y(0)
{
//    QObject::connect(&m_timer, &QTimer::timeout, this, &Chart::handleTimeout);
//    m_timer.setInterval(500);
    startTimer(500);

    m_series = new QSplineSeries(this);
    QPen green(Qt::green);
    green.setWidth(2);
    m_series->setPen(green);
    m_series->append(m_x, m_y);
    //m_series->setPointsVisible(true);

    addSeries(m_series);

    //m_axisX->setLabelFormat("%d");
    //m_axisY->setLabelFormat("%d");
    addAxis(m_axisX,Qt::AlignBottom);
    addAxis(m_axisY,Qt::AlignLeft);
    m_series->attachAxis(m_axisX);
    m_series->attachAxis(m_axisY);
    m_axisX->setTickCount(m_x + 1);
    m_axisX->setRange(0, m_x);
    m_axisY->setRange(-5, 10);

    setAnimationOptions(QChart::AllAnimations);

    layout()->setContentsMargins(0, 0, 0, 0);
    //设置内边界全部为0
    setMargins(QMargins(0, 0, 0, 0));
    //设置背景区域无圆角
    setBackgroundRoundness(0);

    QLegend *mlegend = legend();
    mlegend->detachFromChart();
    mlegend->setGeometry(QRectF(30,0,100,100));

    m_series->setName("cmH2O");
}

Chart::~Chart()
{

}

void Chart::timerEvent(QTimerEvent *)
{
    qreal x = plotArea().width() / (m_axisX->tickCount() - 1);
    //qreal y = (m_axisX->max() - m_axisX->min()) / m_axisX->tickCount();
    m_x += 2;
    m_y = QRandomGenerator::global()->bounded(5) - 2.5;
    m_series->append(m_x, m_y);
    scroll(x, 0);
}
