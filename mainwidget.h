#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QMouseEvent>
//#include <QKeyEvent>
#include <QMouseEvent>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>

#include <QTcpSocket>  //客户端
#include <QHostAddress>
#define BLACK 1
#define WHITE 2
#define NONE 0
enum Chesscolor {
    none,
    black,
    white,
};

namespace Ui {
class mainWidget;
}

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit mainWidget(QWidget *parent = nullptr);
    ~mainWidget();
    void initData(); //自己的初始化函数
    void judge(int x,int y);//判断
    void writeInfo(int x,int y, int type);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
private slots:
    void on_btn_black_clicked();

    void on_btn_white_clicked();

    void on_btn_restart_clicked();

    void on_btn_start_clicked();

    void on_btn_whitefirst_stateChanged(int arg1);

    void on_btn_conn_clicked();

    void connected();  //连接成功
    void readInfo(); //读取数据

private:
    bool isBlack = true;
    Ui::mainWidget *ui;
    unsigned char dat[15][15];  //225*4   字符：225*1——内存占用
    //要考虑范围 unsigned 127 char:255
//    0：无 1：黑 2：白↔
    bool isStart;
    bool startGame = false;
    QTcpSocket *tcpSocket;
};

#endif // MAINWIDGET_H
