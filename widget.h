#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include "chartview.h"
#include "worker.h"
QT_CHARTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void timerEvent(QTimerEvent *);

private:
    Ui::Widget *ui;
    Worker *m_list[3];
    ChartView cv[3];
    QThread workerThread[3];
signals:
    void operate(const int);  // 发送信号，触发线程
};
#endif // WIDGET_H
