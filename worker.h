
#ifndef DEL_WORKER_H
#define DEL_WORKER_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include "chartview.h"

class Worker : public QObject
{
Q_OBJECT

public:
    explicit Worker(ChartView *cv, QObject *parent = nullptr);
    //void timerEvent(QTimerEvent *);
private:
    ChartView *m_cv;

public slots:
    void read(qreal);

signals:
    void sendRead(qreal);
//    void resultReady(const int result);  // 线程完成工作时发送的信号
};

#endif //DEL_WORKER_H
