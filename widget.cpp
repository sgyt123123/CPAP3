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

    //QRadioButton* radio = new QRadioButton;
//    cv[0].setParent(ui->chart_area);
//    cv[1].setParent(ui->chart_area);
//    cv[2].setParent(ui->chart_area);

    QGridLayout *vbox = new QGridLayout(ui->chart_area);
    vbox->addWidget(&cv[0]);
    vbox->addWidget(&cv[1]);
    vbox->addWidget(&cv[2]);
    //vbox->addStretch(1);
    ui->chart_area->setLayout(vbox);


    //auto chart_array = ui->chart_area->children();

    for(int i = 0;i < 3;i++){
        m_list[i] = new Worker(&cv[i]);
        m_list[i]->moveToThread(&workerThread[i]);
        connect(this, SIGNAL(operate(const int)), m_list[i], SLOT(start(int)));
        workerThread[i].start();
    }

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

void Widget::timerEvent(QTimerEvent *){
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
}

