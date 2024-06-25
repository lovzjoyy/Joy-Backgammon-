#include "chessdemo.h"
#include "ui_chessdemo.h"

ChessDemo::ChessDemo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChessDemo)
{
    ui->setupUi(this);
}

ChessDemo::~ChessDemo()
{
    delete ui;
}



//绘制--各种画笔的获取
//中间的河的线
void ChessDemo::paintEvent(QPaintEvent *event)
{
    //1.定义画笔，画刷
    QPainter painter(this); //绘制对象
    QPen pen;
    QBrush brush;
    pen.setWidth(5);
    pen.setColor(Qt::black);
    brush.setColor(Qt::black);
    painter.setPen(pen);
    painter.setBrush(brush);
    QPixmap pixmap;
    pixmap.load("D:/QT/QTcODE/DrawDemo/drawDemo/xiangqi/qipan.png");  //资源文件
    painter.drawPixmap(90,40,800,900,pixmap);
    painter.drawLine(90,440,890,440);
    painter.drawLine(90,540,890,540);
    //2绘制上下的格子-5*8的格子

    pen.setWidth(2);
    pen.setColor(Qt::black);
    brush.setColor(Qt::black);
    painter.setPen(pen);
    painter.setBrush(brush);
    for(int i = 0; i < 4;i++){
        painter.drawLine(90,40+i*100,890,40+100*i);
    }
    for(int i = 0; i < 4;i++){
        painter.drawLine(90,540+i*100,890,540+100*i);
    }
    // 绘制竖线
    for(int i = 0; i < 8;i++){
        painter.drawLine(90+i*100,40,90+i*100,440);
    }
    for(int i = 0; i < 8;i++){
        painter.drawLine(90+i*100,540,90+i*100,940);
    //绘制斜线
        painter.drawLine(90+3*100,40,90+5*100,240);
        painter.drawLine(90+5*100,40,90+3*100,240);

        painter.drawLine(90+3*100,940,90+5*100,740);
        painter.drawLine(90+5*100,940,90+3*100,740);

    }
    //绘制汉字
    QFont font;
    font.setBold(true);
    painter.setFont(font);
    font.setPixelSize(50);
    painter.drawText((470-170),490,"楚河");
    painter.drawText((470+170),490,"汉界");

    //绘制棋子
    //绘制图片 ./image/qipan.png
//    QPixmap pixmap1;
//    pixmap1.load("F:/QtExpClass/3222/drawDemo/drawDemo/xiangqi/hei_ma.png");
//    painter.drawPixmap(90,140,100,100,pixmap1);
    QPixmap pixmap1;
        if (!pixmap1.load("D:/QT/QTcODE/DrawDemo/drawDemo/xiangqi/hei_ma.png")) {
            qDebug() << "Failed to load hei_ma.png";
            return;
        }
        painter.drawPixmap(90 + 1 * 100 - 22, 40 + 0 * 100 - 22, 55, 55, pixmap1); // 示例：绘制在棋盘上的(0,1)位置
//        painter.drawPixmap(90 + 1 * 100 - 22, 40 + 0 * 100 - 22, 55, 55, {xiangqi:url(:/image/un-radiobutton-o.png)});
        painter.drawPixmap(90 + 7 * 100 - 22, 40 + 0 * 100 - 22, 55, 55, pixmap1);
    QPixmap pixmap2;
        if (!pixmap1.load("D:/QT/QTcODE/DrawDemo/drawDemo/xiangqi/hei_che.png")) {
            qDebug() << "Failed to load hei_ma.png";
            return;
        }
        painter.drawPixmap(90 + 0 * 100 - 22, 40 + 0 * 100 - 22, 55, 55, pixmap1);
        painter.drawPixmap(90 + 8 * 100 - 22, 40 + 0 * 100 - 22, 55, 55, pixmap1);
        QPixmap pixmap3;
            if (!pixmap1.load("D:/QT/QTcODE/DrawDemo/drawDemo/xiangqi/hei_xiang.png")) {
                qDebug() << "Failed to load hei_ma.png";
                return;
            }
            painter.drawPixmap(90 + 2 * 100 - 22, 40 + 0 * 100 - 22, 55, 55, pixmap1);
            painter.drawPixmap(90 + 6 * 100 - 22, 40 + 0 * 100 - 22, 55, 55, pixmap1);
            //shi
            if (!pixmap1.load("D:/QT/QTcODE/DrawDemo/drawDemo/xiangqi/hei_si.png")) {
                qDebug() << "Failed to load hei_ma.png";
                return;
            }
            painter.drawPixmap(90 + 3 * 100 - 22, 40 + 0 * 100 - 22, 55, 55, pixmap1);
            painter.drawPixmap(90 + 5 * 100 - 22, 40 + 0 * 100 - 22, 55, 55, pixmap1);
            if (!pixmap1.load("D:/QT/QTcODE/DrawDemo/drawDemo/xiangqi/hei_jiang.png")) {
                qDebug() << "Failed to load hei_ma.png";
                return;
            }
            painter.drawPixmap(90 + 4 * 100 - 22, 40 + 0 * 100 - 22, 55, 55, pixmap1);
            if (!pixmap1.load("D:/QT/QTcODE/DrawDemo/drawDemo/xiangqi/hei_pao.png")) {
                qDebug() << "Failed to load hei_ma.png";
                return;
            }
            painter.drawPixmap(90 + 1 * 100 - 22, 40 + 2 * 100 - 22, 55, 55, pixmap1);
            painter.drawPixmap(90 + 7 * 100 - 22, 40 + 2 * 100 - 22, 55, 55, pixmap1);

            if (!pixmap1.load("D:/QT/QTcODE/DrawDemo/drawDemo/xiangqi/hei_zu.png")) {
                qDebug() << "Failed to load hei_ma.png";
                return;
            }
            painter.drawPixmap(90 + 0 * 100 - 22, 40 + 3 * 100 - 22, 55, 55, pixmap1);
            painter.drawPixmap(90 + 2 * 100 - 22, 40 + 3 * 100 - 22, 55, 55, pixmap1);
            painter.drawPixmap(90 + 4 * 100 - 22, 40 + 3 * 100 - 22, 55, 55, pixmap1);
            painter.drawPixmap(90 + 6 * 100 - 22, 40 + 3 * 100 - 22, 55, 55, pixmap1);
            painter.drawPixmap(90 + 8 * 100 - 22, 40 + 3 * 100 - 22, 55, 55, pixmap1);


            //红色棋子

            if (!pixmap2.load("D:/QT/QTcODE/DrawDemo/drawDemo/xiangqi/hong_ma.png")) {
                    qDebug() << "Failed to load hong_ma.png";
                    return;
                }
                painter.drawPixmap(90 + 1 * 100 - 22, 40 + 9 * 100 - 22, 55, 55, pixmap2);
                painter.drawPixmap(90 + 7 * 100 - 22, 40 + 9 * 100 - 22, 55, 55, pixmap2);

                if (!pixmap2.load("D:/QT/QTcODE/DrawDemo/drawDemo/xiangqi/hong_che.png")) {
                    qDebug() << "Failed to load hong_che.png";
                    return;
                }
                painter.drawPixmap(90 + 0 * 100 - 22, 40 + 9 * 100 - 22, 55, 55, pixmap2);
                painter.drawPixmap(90 + 8 * 100 - 22, 40 + 9 * 100 - 22, 55, 55, pixmap2);

                if (!pixmap2.load("D:/QT/QTcODE/DrawDemo/drawDemo/xiangqi/hong_xiang.png")) {
                    qDebug() << "Failed to load hong_xiang.png";
                    return;
                }
                painter.drawPixmap(90 + 2 * 100 - 22, 40 + 9 * 100 - 22, 55, 55, pixmap2);
                painter.drawPixmap(90 + 6 * 100 - 22, 40 + 9 * 100 - 22, 55, 55, pixmap2);

                if (!pixmap2.load("D:/QT/QTcODE/DrawDemo/drawDemo/xiangqi/hong_si.png")) {
                    qDebug() << "Failed to load hong_si.png";
                    return;
                }
                painter.drawPixmap(90 + 3 * 100 - 22, 40 + 9 * 100 - 22, 55, 55, pixmap2);
                painter.drawPixmap(90 + 5 * 100 - 22, 40 + 9 * 100 - 22, 55, 55, pixmap2);

                if (!pixmap2.load("D:/QT/QTcODE/DrawDemo/drawDemo/xiangqi/hong_jiang.png")) {
                    qDebug() << "Failed to load hong_jiang.png";
                    return;
                }
                painter.drawPixmap(90 + 4 * 100 - 22, 40 + 9 * 100 - 22, 55, 55, pixmap2);

                if (!pixmap2.load("D:/QT/QTcODE/DrawDemo/drawDemo/xiangqi/hong_pao.png")) {
                    qDebug() << "Failed to load hong_pao.png";
                    return;
                }
                painter.drawPixmap(90 + 1 * 100 - 22, 40 + 7 * 100 - 22, 55, 55, pixmap2);
                painter.drawPixmap(90 + 7 * 100 - 22, 40 + 7 * 100 - 22, 55, 55, pixmap2);

                if (!pixmap2.load("D:/QT/QTcODE/DrawDemo/drawDemo/xiangqi/hong_zu.png")) {
                    qDebug() << "Failed to load hong_zu.png";
                    return;
                }
                painter.drawPixmap(90 + 0 * 100 - 22, 40 + 6 * 100 - 22, 55, 55, pixmap2);
                painter.drawPixmap(90 + 2 * 100 - 22, 40 + 6 * 100 - 22, 55, 55, pixmap2);
                painter.drawPixmap(90 + 4 * 100 - 22, 40 + 6 * 100 - 22, 55, 55, pixmap2);
                painter.drawPixmap(90 + 6 * 100 - 22, 40 + 6 * 100 - 22, 55, 55, pixmap2);
                painter.drawPixmap(90 + 8 * 100 - 22, 40 + 6 * 100 - 22, 55, 55, pixmap2);

}
