#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "drinkwindow.h"
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    serial = new QSerialPort(this);
       serial->setPortName("/dev/ttyS9"); // 根据实际设备修改，Windows是 "COM3"
       serial->setBaudRate(QSerialPort::Baud115200);  // 设置为115200波特率
       serial->setDataBits(QSerialPort::Data8);
       serial->setParity(QSerialPort::NoParity);
       serial->setStopBits(QSerialPort::OneStop);
       serial->setFlowControl(QSerialPort::NoFlowControl);

       if (serial->open(QIODevice::ReadWrite)) {
           qDebug() << "串口打开成功";
       } else {
           qDebug() << "串口打开失败：" << serial->errorString();
       }

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_btnMilkTea_clicked() {
    this->hide();
    auto *win = new DrinkWindow("奶茶", serial);
    connect(win, &DrinkWindow::backToMain, this, &MainWindow::show);
    win->show();
}

void MainWindow::on_btnCoffee_clicked() {
    this->hide();
    auto *win = new DrinkWindow("咖啡", serial);
    connect(win, &DrinkWindow::backToMain, this, &MainWindow::show);
    win->show();
}

void MainWindow::on_btnJuice_clicked() {
    this->hide();
    auto *win = new DrinkWindow("果汁",serial);
    connect(win, &DrinkWindow::backToMain, this, &MainWindow::show);
    win->show();
}
