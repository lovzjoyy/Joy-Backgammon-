#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QMessageBox>

mainWidget::mainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWidget)
{
    ui->setupUi(this);
    initData(); //调用
}

mainWidget::~mainWidget()
{
    delete ui;
}

//自己初始化
void mainWidget::initData()
{
    isBlack = true;
    isStart = false;
    for(int i=0;i<15;i++)
    {
        for( int j = 0;j<15;j++)
        {
//            dat[i][j]=0;
//            dat[i][j]=NONE;
            dat[i][j]=Chesscolor::none;
        }
    }
    update();
//    dat[8][9] = Chesscolor::black;
//    dat[1][3] = Chesscolor::white;
}

void mainWidget::paintEvent(QPaintEvent *event)
{
    //1.定义画笔，画刷
    QPainter painter(this);  //绘图对象
    //可以进行绘制了
//    2.绘制下棋区域
//    QPen pen; //kan还需要确定
//    QColor color(255,255,0);
//    pen.setColor(Qt::blue);
//    pen.setColor(color);
//    pen.setWidth(10); //再绘图前
//    painter.setPen(pen);
//    painter.drawLine(0,0,100,100);
//    QPoint pos1(200,300);
//    QPoint pos2(500,400);
//    painter.drawLine(pos1,pos2);
    QPen pen;
    QBrush brush;
    //用枚举
    pen.setColor(Qt::black);
    brush.setColor(Qt::yellow);
    //还需要设置风格才会填充
    painter.setPen(pen);
     pen.setWidth(2);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.drawRect(100-30,100-30,16*30,16*30);
    //绘制图片--背景图片-资源-美工设计
//    QPixmap pixmap;
//    pixmap.load("D:/QT/QTcODE/DrawDemo/drawDemo/xiangqi/qipan.png");  //资源文件
//    painter.drawPixmap(100,100,45,450,pixmap);



//    3.显示“五子棋游戏”
    QFont font;
    font.setBold(true);
    painter.setFont(font);
    font.setPixelSize(30);
//    pen.setColor(Qt::black);
    painter.drawText(260,60,"五子棋游戏");

    //4绘制棋盘(16*16   间隔:30)
    for(int i = 0;i<15;i++){
           painter.drawLine(100,100+30*i,100+14*30,100+30*i);
           painter.drawLine(100+30*i,100,100+30*i,100+14*30);
    }
    //绘制棋盘的定位点
    painter.drawEllipse(100+3*30-6/2,100+3*30-6/2,6,6);
    painter.drawEllipse(100+11*30-6/2,100+3*30-6/2,6,6);
    painter.drawEllipse(100+3*30-6/2,100+11*30-6/2,6,6);
    painter.drawEllipse(100+11*30-6/2,100+11*30-6/2,6,6);
    painter.drawEllipse(100+7*30-6/2,100+7*30-6/2,6,6);






    //6.绘制坐标 QString("%1").arg()
    font.setBold(false);
    font.setPixelSize(12);
    painter.setFont(font);

    for(int i=0;i<15;i++)
    {
        if(i<9)

        painter.drawText(100+30*i,90,QString::number(i+1));
        else
        painter.drawText(100+30*i-4,90,QString::number(i+1));
        //列坐标
        if(i<9)

        painter.drawText(90,100+30*i,QString::number(i+1));
        else
        painter.drawText(90-3,100+30*i,QString::number(i+1));

    }
//    7.绘制棋子
    //黑棋子
    for(int i=0;i<15;i++)
    {
        for( int j = 0;j<15;j++)
        {
            if(dat[i][j] == Chesscolor::black)
            {
                pen.setColor(Qt::black);
                brush.setColor(Qt::black);
                //还需要设置风格才会填充
                painter.setPen(pen);
                //pen.setWidth(2);
                //brush.setStyle(Qt::SolidPattern);
                painter.setBrush(brush);
                painter.drawEllipse(100+i*30-20/2,100+j*30-20/2,20,20);
//                painter.drawEllipse(100+7*30-20/2,100+7*30-20/2,20,20);
            }
            else if(dat[i][j] == Chesscolor::white)
            {
                //白棋
                pen.setColor(Qt::white);
                brush.setColor(Qt::white);
                painter.setPen(pen);
                painter.setBrush(brush);
                painter.drawEllipse(100+i*30-20/2,100+j*30-20/2,20,20);
                //painter.drawEllipse(100+7*30-20/2,100+7*30-20/2,20,20);
//                painter.drawEllipse(100+11*30-20/2,100+11*30-20/2,20,20);
            }
        }
    }




}





void mainWidget::on_btn_black_clicked()
{
    int x = ui->spinBox_x->value();
    int y = ui->spinBox_y->value();

    if(dat[x-1][y-1]==Chesscolor::none)
    {
        dat[x-1][y-1] = Chesscolor::black;
         update();
    }

}

void mainWidget::on_btn_white_clicked()
{
    int x = ui->spinBox_x->value();
    int y = ui->spinBox_y->value();

    if(dat[x-1][y-1]==Chesscolor::none)
    {
        dat[x-1][y-1] = Chesscolor::white;
      update();
    }
//    update();
}
bool isBlack = true;
void mainWidget::on_btn_restart_clicked()
{
  initData(); //数组情况
  //重新绘制
  update();
  isBlack = true;
  isStart = true;//可以开始下
   if(ui->btn_whitefirst->isChecked())
       isBlack = false;
   else {
       isBlack = true;
   }
}




void mainWidget::mousePressEvent(QMouseEvent *event)
{
    if(!isStart) return;
    if(!startGame) return;//没有链接服务器
    int x = event->pos().x();
    int y = event->pos().y();
    qDebug()<<x<<y;
    x = (x-100)/30.0+0.5;
    y = (y - 100)/30.0+0.5;

    if(isBlack)
    {
        if(dat[x][y]==Chesscolor::none)
        {
            dat[x][y]=Chesscolor::white;
        writeInfo(x,y,isBlack?1:2);
        isBlack = false;

        }
    }
//    else if (!isBlack) {
//        if(dat[x][y]==Chesscolor::none)
//        {
//            dat[x][y]=Chesscolor::white;
//        isBlack = true;
//        writeInfo(x,y,isBlack?1:2);
//        }
//    }
    update();
    judge(x,y);
}
void mainWidget::judge(int x,int y) //判断
{
    int count = 0;
    //横线
    for(int i = x;i<15;i++)
    {
        if(dat[x][y] == dat[i][y])

            count ++;

        if(dat[x][y] != dat[i][y])

            break;

    }
    //朝右边再来一次，copy上面的
    for(int i = x - 1;i>=0;i--)
    {
        if(dat[x][y] == dat[i][y])

            count ++;

        if(dat[x][y] != dat[i][y])

            break;
    }
    //竖线
    //朝下
    if(count < 5)
    {
        count = 0;
        for(int i = y;i<15;i++)
        {
            if(dat[x][y] == dat[x][i])

                count ++;

            if(dat[x][y] != dat[x][i])

                break;

        }
        //朝上面再来一次，copy上面的
        for(int i = y - 1;i>=0;i--)
        {
            if(dat[x][y] == dat[x][i])

                count ++;

            if(dat[x][y] != dat[x][i])

                break;
        }
    }

    //从左上到右下
    if(count < 5)
    {
        count = 0;
        for(int i = x,j=y;i<15,j<15;i++,j++)
        {
            //右上
            if(dat[x][y] == dat[i][j])

                count ++;

            if(dat[x][y] != dat[i][i])

                break;

        }

        for(int i = x - 1,j=y-1;i>=0,j>=0;i++,j--) //从右下往左上 都--
        {
            if(dat[x][y] == dat[i][j])

                count ++;

            if(dat[x][y] != dat[i][j])

                break;
        }
    }

    if(count < 5)
    {
        count = 0;
        for(int i = x,j=y;i<15,j>=0;i++,j--)  //从左下到右上
        {

            if(dat[x][y] == dat[i][j])

                count ++;

            if(dat[x][y] != dat[i][i])

                break;

        }

        for(int i = x - 1,j=y+1;i<=15,j>=0;i--,j++) //右上到左下
        {
            if(dat[x][y] == dat[i][j])

                count ++;

            if(dat[x][y] != dat[i][j])

                break;
        }
    }




    if(count == 5)
    {
        QMessageBox::about(this,
                           "提示",
                           dat[x][y] == Chesscolor::black?"黑方胜!":"白方胜");
        isStart = false;
    }


 }




//点击开始
void mainWidget::on_btn_start_clicked()
{
    isStart = true;
}

void mainWidget::on_btn_whitefirst_stateChanged(int arg1)
{
    isBlack = true;
    if(ui->btn_whitefirst->isChecked())
    isBlack = false;
}


//查找玩家--如果错了，不能玩的   需要一个bool
void mainWidget::on_btn_conn_clicked()
{
//    startGame = true;
    //逻辑就是网络通i性能
    tcpSocket = new QTcpSocket;
    QString url = "127.0.0.1";
    int port = 17522;
    tcpSocket->connectToHost(QHostAddress(url),port);
    connect(tcpSocket,&QTcpSocket::connected,this,&mainWidget::connected);
    connect(tcpSocket,&QTcpSocket::readyRead,this,&mainWidget::readInfo);
}


void mainWidget::connected()  //连接成功
{
    startGame = true;
    ui->btn_conn->setEnabled(false);
}


void mainWidget::readInfo() //读取数据
{
    QByteArray arr = tcpSocket->readAll();  //读取数据
    QString datArr = QString(arr);
    QStringList datList = datArr.split(",");
    qDebug()<<datList.at(0)<<datList.at(1)<<datList.at(2);
    //    else if (!isBlack) {
    //        if(dat[x][y]==Chesscolor::none)
    //        {
    //            dat[x][y]=Chesscolor::white;
    //        isBlack = true;
    //        writeInfo(x,y,isBlack?1:2);
    //        }
    //    }
    QString x = datList.at(0);
    QString y = datList.at(1);
    QString t = datList.at(2);
    dat[x.toInt()][y.toInt()] = Chesscolor::black;
    isBlack = true;
    judge(x.toInt(),y.toInt());
    update();

}
void mainWidget::writeInfo(int x,int y, int type)
{
//    tcpSocket->write(QString("%1,%2,%3").arg(x).arg(y).arg(type));
    QString temp = QString("%1,%2,%3").arg(x).arg(y).arg(type);
    tcpSocket->write(temp.toLocal8Bit());
}
