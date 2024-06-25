#ifndef CHESSDEMO_H
#define CHESSDEMO_H

#include <QDialog>
#include <QMouseEvent>
//#include <QKeyEvent>
#include <QMouseEvent>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>

namespace Ui {
class ChessDemo;
}

class ChessDemo : public QDialog
{
    Q_OBJECT

public:
    explicit ChessDemo(QWidget *parent = nullptr);
    ~ChessDemo();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::ChessDemo *ui;
};

#endif // CHESSDEMO_H
