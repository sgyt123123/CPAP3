#ifndef SP_WIDGET_H
#define SP_WIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>
#include <QThread>
#include "chartview.h"
#include "worker.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SP_Widget; }
QT_END_NAMESPACE

class SP_Widget : public QWidget
{
    Q_OBJECT

public:
    SP_Widget(QWidget *parent = nullptr, ChartView *m_cv = nullptr);
    ~SP_Widget();

private slots:
    void on_openButton_clicked();

    void on_closeButton_clicked();

    //void on_baudrateBox_currentTextChanged(const QString &arg1);

    //void serial_Read();//串口数据读取显示

    void on_bind_clicked();

    void on_unbind_clicked();

    void on_serialBox_currentIndexChanged(int);

private:
    Ui::SP_Widget *ui;
    ChartView *m_cv;
    QMap<int, QSerialPort*> serialPort;  //串口号 串口
    QMap<int, ChartView*> serialWin;      //串口号 窗口号
    QMap<int, QThread*> winThread;         //窗口号 线程
    QMap<int, Worker*> workerList;

    QMap<int, QVector<QPointF>> serialbuf;  //串口号 缓冲区
};
#endif // SP_WIDGET_H
