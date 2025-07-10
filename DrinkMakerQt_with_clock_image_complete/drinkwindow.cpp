#include "drinkwindow.h"
#include "ui_drinkwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QSerialPort>

DrinkWindow::DrinkWindow(QString drinkType, QSerialPort *serial, QWidget *parent)
    : QWidget(parent), ui(new Ui::DrinkWindow),
      serial(serial),
      m_drinkType(drinkType), m_timer(new QTimer(this)), m_progressValue(0) {
    ui->setupUi(this);
    setWindowTitle(drinkType + " 选择");

    connect(m_timer, &QTimer::timeout, this, &DrinkWindow::updateProgress);
    connect(serial, &QSerialPort::readyRead, this, &DrinkWindow::onSerialDataReceived);

    QString imagePath;
    if (drinkType == "奶茶") imagePath = ":/images/milk_tea.png";
    else if (drinkType == "咖啡") imagePath = ":/images/coffee.png";
    else imagePath = ":/images/juice.png";
    ui->labelImage->setPixmap(QPixmap(imagePath));
    ui->labelImage->setScaledContents(true);

    QTimer *clockTimer = new QTimer(this);
    connect(clockTimer, &QTimer::timeout, [=]() {
        QDateTime now = QDateTime::currentDateTime();
        ui->labelClock->setText("当前时间：" + now.toString("hh:mm:ss"));
    });
    clockTimer->start(1000);
}

DrinkWindow::~DrinkWindow() {
    delete ui;
}

void DrinkWindow::on_btnConfirm_clicked() {
    QString iceCode, sugarCode;

    // 冰量编码：7 = 正常冰，5 = 少冰，0 = 去冰
    if (ui->radioNormal->isChecked()) iceCode = "7";
    else if (ui->radioLess->isChecked()) iceCode = "5";
    else if (ui->radioNo->isChecked()) iceCode = "0";

    // 糖度编码：7 = 全糖，5 = 半糖，0 = 无糖
    if (ui->radioFull->isChecked()) sugarCode = "7";
    else if (ui->radioHalf->isChecked()) sugarCode = "5";
    else if (ui->radioNone->isChecked()) sugarCode = "0";

    // 饮品编码：A=奶茶 B=咖啡 C=果汁
    QString drinkCode;
    if (m_drinkType == "奶茶") drinkCode = "A";
    else if (m_drinkType == "咖啡") drinkCode = "B";
    else if (m_drinkType == "果汁") drinkCode = "C";

    // 拼接简洁指令
    QString command = drinkCode + iceCode + sugarCode + "\n";

    // 发送串口数据
    if (serial && serial->isOpen()) {
        serial->write(command.toUtf8());
    }

    // UI 显示中文提示
    QString iceStr = (iceCode == "7") ? "正常冰" : (iceCode == "5") ? "少冰" : "去冰";
    QString sugarStr = (sugarCode == "7") ? "全糖" : (sugarCode == "5") ? "半糖" : "无糖";
    ui->textHistory->append(QString("你选择了：%1 | %2 | %3").arg(m_drinkType).arg(iceStr).arg(sugarStr));

    // 启动进度条
    m_progressValue = 0;
    ui->progressBar->setValue(0);
    ui->labelTime->setText("预计制作时间：3 秒");

   // m_timer->start(30);
}

void DrinkWindow::onSerialDataReceived() {
    QByteArray data = serial->readAll();
       static QByteArray buffer;

       buffer += data;

    if (!buffer.contains('\n'))
           return;

       QList<QByteArray> lines = buffer.split('\n');
       for (int i = 0; i < lines.size() - 1; ++i) {
           QString line = QString::fromUtf8(lines[i]).trimmed();
           ui->textHistory->append("下位机：" + line);

           if (line == "STEP_ICE") {
               m_progressValue = 25;
               ui->progressBar->setValue(m_progressValue);
               ui->labelTime->setText("已完成：添加冰块");

           } else if (line == "STEP_SOLID") {
               m_progressValue = 50;
               ui->progressBar->setValue(m_progressValue);
               ui->labelTime->setText("已完成：添加固体冲剂");

           } else if (line == "STEP_LIQUID") {
               m_progressValue = 75;
               ui->progressBar->setValue(m_progressValue);
               ui->labelTime->setText("已完成：注入液体冲剂");

           } else if (line == "STEP_STIR") {
              m_progressValue = 100;
               ui->progressBar->setValue(m_progressValue);
               ui->labelTime->setText("已完成：搅拌完成");

               QMessageBox::information(this, "提示", "饮品制作完成！");
          }
       }

      buffer = lines.last(); // 保留最后未完整的一部分
}



void DrinkWindow::updateProgress() {
    /*m_progressValue += 2;
    ui->progressBar->setValue(m_progressValue);
    ui->labelTime->setText(QString("预计制作时间：%1 秒").arg((100 - m_progressValue) / 33 + 1));
    if (m_progressValue >= 100) {
        m_timer->stop();
        QMessageBox::information(this, "提示", "制作完成！");
    }*/
}

void DrinkWindow::on_btnBack_clicked() {
    emit backToMain();
    this->close();
}

