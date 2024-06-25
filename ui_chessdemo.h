/********************************************************************************
** Form generated from reading UI file 'chessdemo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESSDEMO_H
#define UI_CHESSDEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_ChessDemo
{
public:

    void setupUi(QDialog *ChessDemo)
    {
        if (ChessDemo->objectName().isEmpty())
            ChessDemo->setObjectName(QString::fromUtf8("ChessDemo"));
        ChessDemo->resize(1100, 1000);

        retranslateUi(ChessDemo);

        QMetaObject::connectSlotsByName(ChessDemo);
    } // setupUi

    void retranslateUi(QDialog *ChessDemo)
    {
        ChessDemo->setWindowTitle(QApplication::translate("ChessDemo", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChessDemo: public Ui_ChessDemo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESSDEMO_H
