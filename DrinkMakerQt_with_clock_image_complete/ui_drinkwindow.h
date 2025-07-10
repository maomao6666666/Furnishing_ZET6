/********************************************************************************
** Form generated from reading UI file 'drinkwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRINKWINDOW_H
#define UI_DRINKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DrinkWindow
{
public:
    QLabel *labelImage;
    QGroupBox *groupBoxTemp;
    QRadioButton *radioNormal;
    QRadioButton *radioLess;
    QRadioButton *radioNo;
    QGroupBox *groupBoxSugar;
    QRadioButton *radioFull;
    QRadioButton *radioHalf;
    QRadioButton *radioNone;
    QPushButton *btnConfirm;
    QPushButton *btnBack;
    QProgressBar *progressBar;
    QLabel *labelTime;
    QLabel *labelClock;
    QTextEdit *textHistory;

    void setupUi(QWidget *DrinkWindow)
    {
        if (DrinkWindow->objectName().isEmpty())
            DrinkWindow->setObjectName(QString::fromUtf8("DrinkWindow"));
        DrinkWindow->resize(935, 400);
        labelImage = new QLabel(DrinkWindow);
        labelImage->setObjectName(QString::fromUtf8("labelImage"));
        labelImage->setGeometry(QRect(10, 10, 100, 100));
        groupBoxTemp = new QGroupBox(DrinkWindow);
        groupBoxTemp->setObjectName(QString::fromUtf8("groupBoxTemp"));
        groupBoxTemp->setGeometry(QRect(110, 20, 141, 141));
        radioNormal = new QRadioButton(groupBoxTemp);
        radioNormal->setObjectName(QString::fromUtf8("radioNormal"));
        radioNormal->setGeometry(QRect(10, 30, 70, 29));
        radioLess = new QRadioButton(groupBoxTemp);
        radioLess->setObjectName(QString::fromUtf8("radioLess"));
        radioLess->setGeometry(QRect(10, 90, 55, 29));
        radioNo = new QRadioButton(groupBoxTemp);
        radioNo->setObjectName(QString::fromUtf8("radioNo"));
        radioNo->setGeometry(QRect(10, 60, 55, 29));
        groupBoxSugar = new QGroupBox(DrinkWindow);
        groupBoxSugar->setObjectName(QString::fromUtf8("groupBoxSugar"));
        groupBoxSugar->setGeometry(QRect(380, 20, 151, 141));
        radioFull = new QRadioButton(groupBoxSugar);
        radioFull->setObjectName(QString::fromUtf8("radioFull"));
        radioFull->setGeometry(QRect(10, 30, 55, 29));
        radioHalf = new QRadioButton(groupBoxSugar);
        radioHalf->setObjectName(QString::fromUtf8("radioHalf"));
        radioHalf->setGeometry(QRect(10, 60, 55, 29));
        radioNone = new QRadioButton(groupBoxSugar);
        radioNone->setObjectName(QString::fromUtf8("radioNone"));
        radioNone->setGeometry(QRect(10, 90, 55, 29));
        btnConfirm = new QPushButton(DrinkWindow);
        btnConfirm->setObjectName(QString::fromUtf8("btnConfirm"));
        btnConfirm->setGeometry(QRect(640, 40, 211, 30));
        btnBack = new QPushButton(DrinkWindow);
        btnBack->setObjectName(QString::fromUtf8("btnBack"));
        btnBack->setGeometry(QRect(639, 100, 211, 30));
        progressBar = new QProgressBar(DrinkWindow);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(10, 180, 841, 30));
        labelTime = new QLabel(DrinkWindow);
        labelTime->setObjectName(QString::fromUtf8("labelTime"));
        labelTime->setGeometry(QRect(10, 220, 460, 30));
        labelClock = new QLabel(DrinkWindow);
        labelClock->setObjectName(QString::fromUtf8("labelClock"));
        labelClock->setGeometry(QRect(340, 360, 180, 30));
        textHistory = new QTextEdit(DrinkWindow);
        textHistory->setObjectName(QString::fromUtf8("textHistory"));
        textHistory->setGeometry(QRect(10, 259, 841, 91));

        retranslateUi(DrinkWindow);

        QMetaObject::connectSlotsByName(DrinkWindow);
    } // setupUi

    void retranslateUi(QWidget *DrinkWindow)
    {
        DrinkWindow->setWindowTitle(QCoreApplication::translate("DrinkWindow", "\351\200\211\346\213\251\351\245\256\345\223\201", nullptr));
        groupBoxTemp->setTitle(QCoreApplication::translate("DrinkWindow", "\346\270\251\345\272\246", nullptr));
        radioNormal->setText(QCoreApplication::translate("DrinkWindow", "\346\255\243\345\270\270\345\206\260", nullptr));
        radioLess->setText(QCoreApplication::translate("DrinkWindow", "\345\260\221\345\206\260", nullptr));
        radioNo->setText(QCoreApplication::translate("DrinkWindow", "\345\216\273\345\206\260", nullptr));
        groupBoxSugar->setTitle(QCoreApplication::translate("DrinkWindow", "\347\224\234\345\272\246", nullptr));
        radioFull->setText(QCoreApplication::translate("DrinkWindow", "\345\205\250\347\263\226", nullptr));
        radioHalf->setText(QCoreApplication::translate("DrinkWindow", "\345\215\212\347\263\226", nullptr));
        radioNone->setText(QCoreApplication::translate("DrinkWindow", "\346\227\240\347\263\226", nullptr));
        btnConfirm->setText(QCoreApplication::translate("DrinkWindow", "\345\274\200\345\247\213\345\210\266\344\275\234", nullptr));
        btnBack->setText(QCoreApplication::translate("DrinkWindow", "\350\277\224\345\233\236", nullptr));
        labelTime->setText(QCoreApplication::translate("DrinkWindow", "\351\242\204\350\256\241\345\210\266\344\275\234\346\227\266\351\227\264\357\274\232", nullptr));
        labelClock->setText(QCoreApplication::translate("DrinkWindow", "\345\275\223\345\211\215\346\227\266\351\227\264\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DrinkWindow: public Ui_DrinkWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRINKWINDOW_H
