#ifndef M_WIDGET_H
#define M_WIDGET_H

#include <QWidget>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
QT_CHARTS_USE_NAMESPACE

namespace Ui {
class M_Widget;
}

class M_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit M_Widget(QWidget *parent = nullptr);
    ~M_Widget();

    void timerEvent(QTimerEvent *);

    QLineSeries* getline();
    QValueAxis* getAxY();
    QValueAxis* getAxX();

private:
    Ui::M_Widget *ui;
    QLineSeries* line;
    QValueAxis *AxY, *AxX;
};

#endif // M_WIDGET_H
