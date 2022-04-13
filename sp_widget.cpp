#include "sp_widget.h"
#include "ui_sp_widget.h"

SP_Widget::SP_Widget(QWidget *parent, ChartView *cv) :
    QWidget(parent),
    ui(new Ui::SP_Widget),
    m_cv{cv}
{
    ui->setupUi(this);
    this->setWindowTitle("serial");

    //搜索所有可用串口
    int index = 0;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        QString name = info.portName();
        qDebug() << name;
        serialWin[index++] = nullptr;
        ui->serialBox->addItem(name);

        qDebug() << "Name : " << name;
        qDebug() << "Description : " << info.description();
        qDebug() << "Manufacturer: " << info.manufacturer();
        qDebug() << "Serial Number: " << info.serialNumber();
        qDebug() << "System Location: " << info.systemLocation();
        qDebug() << "";
    }
    ui->winBox->setCurrentIndex(3);
}

SP_Widget::~SP_Widget()
{
    delete ui;
}

void SP_Widget::on_openButton_clicked()
{
    int index = ui->serialBox->currentIndex();  //串口号
    QString name = ui->serialBox->currentText();

    if(!serialPort.contains(index)){
        serialPort[index] = new QSerialPort(name);
        //连接串口读事件
        QObject::connect(serialPort[index], &QSerialPort::readyRead, [&, index](){
            QByteArray buf = serialPort[index]->readAll();
            if(!buf.isEmpty())
            {
                ui->reception->clear();
                ui->reception->setText(buf);
            }

            if(serialWin[index])
                workerList[index]->sendRead(buf.toDouble());
                //emit m_cv[serialWin[index]].add(buf.toDouble());
            //m_cv[serialWin[index]].add(buf.toDouble());
            else
                QMessageBox::critical(this, "提示", "请配置串口！");
            qDebug() << buf.toDouble();
            buf.clear();
        });
    }

    if(serialPort[index]->isOpen())//如果串口已经打开了 先给他关闭了
    {
        qDebug() << "串口已打开";
        serialPort[index]->clear();
        serialPort[index]->close();
    }
    qDebug() << index;

    /* 打开串口提示框 */
    if (serialPort[index]->open(QIODevice::ReadWrite))
    {
        QMessageBox::information(this, "提示", "串口打开成功");
    }
    else
    {
        QMessageBox::critical(this, "提示", "串口打开失败");
    }

    //串口设置
    serialPort[index]->setBaudRate(ui->baudrateBox->currentText().toInt());
    serialPort[index]->setDataBits(QSerialPort::Data8);
    serialPort[index]->setStopBits(QSerialPort::OneStop);
    serialPort[index]->setParity(QSerialPort::NoParity);
}



void SP_Widget::on_closeButton_clicked()
{
    int index = ui->serialBox->currentIndex();
    if(serialPort.contains(index) && serialPort[index]->isOpen())
        serialPort[index]->close();
    else
        QMessageBox::critical(this, "提示", "串口未打开");
}

void SP_Widget::on_bind_clicked()
{
    int index = ui->serialBox->currentIndex();
    serialWin[index] = &m_cv[ui->winBox->currentIndex()];

    if(serialWin[index]){
        if(!winThread.contains(index)){

            winThread[index] = new QThread;             //注册多线程
            workerList[index] = new Worker(serialWin[index], 0);

            workerList[index]->moveToThread(winThread[index]);
            connect(workerList[index], &Worker::sendRead, workerList[index], &Worker::read);
            winThread[index]->start();
        }
    }
    else
        QMessageBox::critical(this, "提示", "请选择要绑定的窗口");

    //锁死box
}

void SP_Widget::on_unbind_clicked()
{
    serialWin[ui->serialBox->currentIndex()] = nullptr;
    ui->winBox->setCurrentIndex(ui->winBox->count() - 1);
    //解锁box
}


void SP_Widget::on_serialBox_currentIndexChanged(int)
{
    if(serialWin[ui->serialBox->currentIndex()])
        ui->winBox->setCurrentText(serialWin[ui->serialBox->currentIndex()]->getline()->name());
    //锁死box
}

