#include "widget.h"
#include "./ui_widget.h"
#include "sp_widget.h"
//#include <thread>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QMenuBar* pMenuBar = new QMenuBar(this);

    QAction* pAction = new QAction("串口设置",this);
    QAction* pAction1 = new QAction("回放",this);
    QAction* pAction2 = new QAction("保存",this);
    QAction* pAction3 = new QAction("关闭",this);

    pMenuBar->addAction(pAction);
    pMenuBar->addAction(pAction1);
    pMenuBar->addAction(pAction2);
    pMenuBar->addAction(pAction3);

    QGridLayout *vbox = new QGridLayout(ui->chart_area);
    vbox->addWidget(&cv[0]);
    vbox->addWidget(&cv[1]);
    vbox->addWidget(&cv[2]);
    //vbox->addStretch(1);
    ui->chart_area->setLayout(vbox);

    SP_Widget *spw = new SP_Widget(nullptr, cv);
    connect(pAction, &QAction::triggered,
        [=](){
            spw->show();
        });

//    for(int i = 1;i < 3;i++){
//        m_list[i] = new Worker(&cv[i]);
//        m_list[i]->moveToThread(&workerThread[i]);
//        connect(this, SIGNAL(operate(const int)), m_list[i], SLOT(start(int)));
//        workerThread[i].start();
//    }

    cv[0].getline()->setName("cmH2O");
    cv[0].getline()->setColor(Qt::green);
    cv[1].getline()->setName("ml");
    cv[1].getline()->setColor(Qt::red);
    cv[2].getline()->setName("LPM");
    cv[2].getline()->setColor(Qt::blue);

    emit operate(500);
}

Widget::~Widget()
{
    delete ui;
    for(int i = 0;i<3;i++){
        workerThread[i].quit();
        workerThread[i].wait();
    }
}

//void Widget::timerEvent(QTimerEvent *){
//    ui->widget->add(QRandomGenerator::global()->bounded(5) - 2.5);
//    std::thread a([&](){
//        ui->widget_2->add(QRandomGenerator::global()->bounded(10) - 5);
//        qDebug() << "\tCurrent thread ID: " << QThread::currentThreadId();
//    });
//    a.detach();
//    std::thread b([&](){
//        ui->widget_3->add(QRandomGenerator::global()->bounded(10) - 5);
//        qDebug() << "\tCurrent thread ID: " << QThread::currentThreadId();
//    });
//    b.detach();
    //ui->widget_2->add(QRandomGenerator::global()->bounded(10) - 5);
    //ui->widget_3->add(QRandomGenerator::global()->bounded(5) - 2.5);
//}

