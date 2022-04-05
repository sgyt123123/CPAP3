#ifndef CHARTVIEW_H
#define CHARTVIEW_H

#include <QtCharts>
#include <QChartView>

QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QValueAxis;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class ChartView : public QChartView
{
     Q_OBJECT
public:
    ChartView(QWidget *parent = nullptr, QChart *chart = new QChart);

    virtual ~ChartView();

    void add(qreal);

    QLineSeries* getline();

    //void timerEvent(QTimerEvent *);

private:
    QChart* m_chart;
    QSplineSeries *m_series;
    QValueAxis *m_axisX;
    QValueAxis *m_axisY;
    qreal m_x;
    qreal m_y;

//public slots:
//    void start(int);
};

#endif /* CHARTVIEW_H */
