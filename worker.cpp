#include "worker.h"

Worker::Worker(ChartView *cv, QObject *parent)
    : QObject{parent},
      m_cv{cv}
{

}

void Worker::start(int interval)
{
    qDebug() << "receive the execute signal" ;
    qDebug() << "\tCurrent thread ID: " << QThread::currentThreadId();

    while(true){
        m_cv->add(QRandomGenerator::global()->bounded(10) - 5);
        QThread::msleep(interval);
    }

    //m_cv->startTimer(interval);

    //emit resultReady(parameter);
}

//void Worker::start(int interval)
//{
//    qDebug() << "receive the execute signal" ;
//    qDebug() << "\tCurrent thread ID: " << QThread::currentThreadId();

//    startTimer(interval);
//}

//void Worker::timerEvent(QTimerEvent *){
//    m_cv->add(QRandomGenerator::global()->bounded(10) - 5);
//    qDebug() << "\tCurrent thread ID: " << QThread::currentThreadId();
//}
