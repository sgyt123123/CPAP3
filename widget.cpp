#include "widget.h"
#include "./ui_widget.h"
//#include <thread>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    startTimer(500);

    QMenuBar* pMenuBar = new QMenuBar(this);

    QMenu* pMenuTest = new QMenu("串口设置",this);
    QMenu* pMenuTest1 = new QMenu("回放",this);
    QMenu* pMenuTest2 = new QMenu("保存",this);
    QMenu* pMenuTest3 = new QMenu("关闭",this);

    pMenuBar->addMenu(pMenuTest);
    pMenuBar->addMenu(pMenuTest1);
    pMenuBar->addMenu(pMenuTest2);
    pMenuBar->addMenu(pMenuTest3);


//    QLineSeries* line = ui->widget->getline();
//    line->setName("cmH2O");
//    line->setColor(QColor(255,0,0));
//    for(int i = 0 ;i <= 20;i++){
//        line->append(i, i/3.0);
//    }
//    QValueAxis* AxX = ui->widget->getAxX();
//    QValueAxis* AxY = ui->widget->getAxY();
//    AxY->setRange(0, 10);
//    AxX->setRange(0, 20);

//    line = ui->widget_2->getline();
//    line->setName("L/min");
//    line->setColor(QColor(0,255,0));
//    for(int i = 0 ;i <= 20;i++){
//        line->append(i, sin(i));
//    }
//    AxX = ui->widget_2->getAxX();
//    AxY = ui->widget_2->getAxY();
//    AxY->setRange(-5, 5);
//    AxX->setRange(0, 20);
//    //AxX->setLinePenColor(Qt::GlobalColor::transparent);

//    line = ui->widget_3->getline();
//    line->setName("ml");
//    line->setColor(QColor(0,0,255));
//    for(int i = 0 ;i <= 20;i++){
//        line->append(i, log(i));
//    }
//    AxX = ui->widget_3->getAxX();
//    AxY = ui->widget_3->getAxY();
//    AxY->setRange(0, 10);
//    AxX->setRange(0, 20);


    //auto m_chart = new QChart();
    //m_chart->setTitle("Dynamic spline chart");
    //m_chart->legend()->hide();
//    ui->widget->setRenderHint(QPainter::Antialiasing);

//    ui->widget->setChart(m_chart);


//    std::thread a([&]{
//        qDebug() << "fuck";
//        while(true){
//            QThread::msleep(500);
//            //qDebug() << "fuck";
//            ui->widget->add(QRandomGenerator::global()->bounded(10) - 5);
//        }
//    });
//    std::thread b([&]{
//        while(true){
//            //QThread::msleep(1000);
//            //qDebug() << "shit";
//            QThread::msleep(500);
//            ui->widget_3->add(QRandomGenerator::global()->bounded(10) - 5);
//        }
//    });
//    a.detach();
//    b.detach();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *){
    ui->widget->add(QRandomGenerator::global()->bounded(5) - 2.5);
    ui->widget_2->add(QRandomGenerator::global()->bounded(10) - 5);
    ui->widget_3->add(QRandomGenerator::global()->bounded(5) - 2.5);
}

