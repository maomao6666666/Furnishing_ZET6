/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnMilkTea;
    QPushButton *btnCoffee;
    QPushButton *btnJuice;
    QLabel *labelMilkTeaImg;
    QLabel *labelCoffeeImg;
    QLabel *labelJuiceImg;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(925, 404);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btnMilkTea = new QPushButton(centralwidget);
        btnMilkTea->setObjectName(QString::fromUtf8("btnMilkTea"));
        btnMilkTea->setGeometry(QRect(80, 290, 231, 40));
        btnCoffee = new QPushButton(centralwidget);
        btnCoffee->setObjectName(QString::fromUtf8("btnCoffee"));
        btnCoffee->setGeometry(QRect(359, 290, 231, 40));
        btnJuice = new QPushButton(centralwidget);
        btnJuice->setObjectName(QString::fromUtf8("btnJuice"));
        btnJuice->setGeometry(QRect(629, 290, 221, 40));
        labelMilkTeaImg = new QLabel(centralwidget);
        labelMilkTeaImg->setObjectName(QString::fromUtf8("labelMilkTeaImg"));
        labelMilkTeaImg->setGeometry(QRect(80, 30, 231, 221));
        labelMilkTeaImg->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/milk_tea.png);"));
        labelMilkTeaImg->setScaledContents(true);
        labelCoffeeImg = new QLabel(centralwidget);
        labelCoffeeImg->setObjectName(QString::fromUtf8("labelCoffeeImg"));
        labelCoffeeImg->setGeometry(QRect(360, 30, 221, 221));
        labelCoffeeImg->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/coffee.png);"));
        labelCoffeeImg->setScaledContents(true);
        labelJuiceImg = new QLabel(centralwidget);
        labelJuiceImg->setObjectName(QString::fromUtf8("labelJuiceImg"));
        labelJuiceImg->setGeometry(QRect(630, 30, 221, 221));
        labelJuiceImg->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/juice.png);"));
        labelJuiceImg->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\351\245\256\345\223\201\351\200\211\346\213\251", nullptr));
        btnMilkTea->setText(QCoreApplication::translate("MainWindow", "\345\245\266\350\214\266", nullptr));
        btnCoffee->setText(QCoreApplication::translate("MainWindow", "\345\222\226\345\225\241", nullptr));
        btnJuice->setText(QCoreApplication::translate("MainWindow", "\346\236\234\346\261\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
