#ifndef DRINKWINDOW_H
#define DRINKWINDOW_H

#include <QWidget>
#include <QTimer>
#include <QDateTime>
#include <QSerialPort>

namespace Ui {
class DrinkWindow;
}

class DrinkWindow : public QWidget {
    Q_OBJECT

public:
    explicit DrinkWindow(QString drinkType, QSerialPort *serial, QWidget *parent = nullptr);
    ~DrinkWindow();

signals:
    void backToMain();

private slots:
    void on_btnConfirm_clicked();
    void on_btnBack_clicked();
    void updateProgress();
    void onSerialDataReceived();  // 串口接收槽函数

private:
    Ui::DrinkWindow *ui;
    QSerialPort *serial;
    QString m_drinkType;
    QTimer *m_timer;
    int m_progressValue;

};

#endif // DRINKWINDOW_H
