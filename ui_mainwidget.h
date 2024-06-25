/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWidget
{
public:
    QLabel *label_x;
    QLabel *label_y;
    QSpinBox *spinBox_x;
    QSpinBox *spinBox_y;
    QPushButton *btn_black;
    QPushButton *btn_white;
    QPushButton *btn_restart;
    QPushButton *btn_start;
    QCheckBox *btn_whitefirst;
    QPushButton *btn_conn;

    void setupUi(QWidget *mainWidget)
    {
        if (mainWidget->objectName().isEmpty())
            mainWidget->setObjectName(QString::fromUtf8("mainWidget"));
        mainWidget->resize(791, 771);
        label_x = new QLabel(mainWidget);
        label_x->setObjectName(QString::fromUtf8("label_x"));
        label_x->setGeometry(QRect(630, 530, 99, 22));
        label_y = new QLabel(mainWidget);
        label_y->setObjectName(QString::fromUtf8("label_y"));
        label_y->setGeometry(QRect(630, 570, 99, 22));
        spinBox_x = new QSpinBox(mainWidget);
        spinBox_x->setObjectName(QString::fromUtf8("spinBox_x"));
        spinBox_x->setGeometry(QRect(670, 530, 55, 29));
        spinBox_x->setMinimum(1);
        spinBox_x->setMaximum(14);
        spinBox_y = new QSpinBox(mainWidget);
        spinBox_y->setObjectName(QString::fromUtf8("spinBox_y"));
        spinBox_y->setGeometry(QRect(670, 570, 55, 29));
        spinBox_y->setMinimum(1);
        spinBox_y->setMaximum(15);
        btn_black = new QPushButton(mainWidget);
        btn_black->setObjectName(QString::fromUtf8("btn_black"));
        btn_black->setGeometry(QRect(610, 610, 135, 41));
        btn_white = new QPushButton(mainWidget);
        btn_white->setObjectName(QString::fromUtf8("btn_white"));
        btn_white->setGeometry(QRect(610, 670, 135, 41));
        btn_restart = new QPushButton(mainWidget);
        btn_restart->setObjectName(QString::fromUtf8("btn_restart"));
        btn_restart->setGeometry(QRect(610, 730, 135, 41));
        btn_start = new QPushButton(mainWidget);
        btn_start->setObjectName(QString::fromUtf8("btn_start"));
        btn_start->setGeometry(QRect(610, 470, 135, 41));
        btn_whitefirst = new QCheckBox(mainWidget);
        btn_whitefirst->setObjectName(QString::fromUtf8("btn_whitefirst"));
        btn_whitefirst->setGeometry(QRect(620, 430, 122, 26));
        btn_conn = new QPushButton(mainWidget);
        btn_conn->setObjectName(QString::fromUtf8("btn_conn"));
        btn_conn->setGeometry(QRect(630, 380, 91, 41));

        retranslateUi(mainWidget);

        QMetaObject::connectSlotsByName(mainWidget);
    } // setupUi

    void retranslateUi(QWidget *mainWidget)
    {
        mainWidget->setWindowTitle(QApplication::translate("mainWidget", "mainWidget", nullptr));
        label_x->setText(QApplication::translate("mainWidget", "X", nullptr));
        label_y->setText(QApplication::translate("mainWidget", "Y", nullptr));
        btn_black->setText(QApplication::translate("mainWidget", "\351\273\221\346\243\213", nullptr));
        btn_white->setText(QApplication::translate("mainWidget", "\347\231\275\346\243\213", nullptr));
        btn_restart->setText(QApplication::translate("mainWidget", "\351\207\215\346\226\260\345\274\200\345\247\213", nullptr));
        btn_start->setText(QApplication::translate("mainWidget", "\345\274\200\345\247\213", nullptr));
        btn_whitefirst->setText(QApplication::translate("mainWidget", "\347\231\275\346\243\213\344\274\230\345\205\210", nullptr));
        btn_conn->setText(QApplication::translate("mainWidget", "\346\237\245\346\211\276\347\216\251\345\256\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainWidget: public Ui_mainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
