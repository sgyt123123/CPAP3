#include "worker.h"

Worker::Worker(ChartView *cv, QObject *parent)
    : QObject{parent}, m_cv{cv}
{

}

void Worker::read(qreal y)
{
    m_cv->add(y);
}

