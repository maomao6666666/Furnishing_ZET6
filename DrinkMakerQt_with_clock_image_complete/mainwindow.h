#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QSerialPort *serial;  // 串口对象

private slots:
    void on_btnMilkTea_clicked();
    void on_btnCoffee_clicked();
    void on_btnJuice_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
