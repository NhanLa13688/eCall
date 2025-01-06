#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), serialConnection(new SerialConnection(this)), isPortOpen(false)
{
    // Thiết lập giao diện
    setFixedSize(400, 250);

    // Tạo QLabel để hiển thị tốc độ
    speedLabel = new QLabel("Speed: 0 km/h", this);
    speedLabel->setGeometry(50, 50, 300, 30);
    speedLabel->setStyleSheet("font-size: 18px; font-weight: bold;");

    // Tạo QLabel để hiển thị nhiệt độ
    temperatureLabel = new QLabel("Temperature: 0 °C", this);
    temperatureLabel->setGeometry(50, 100, 300, 30);
    temperatureLabel->setStyleSheet("font-size: 18px; font-weight: bold;");

    // Tạo QLabel để hiển thị trạng thái kết nối
    statusLabel = new QLabel("Status: Disconnected", this);
    statusLabel->setGeometry(50, 150, 300, 30);
    statusLabel->setStyleSheet("font-size: 16px; color: red;");

    // Kết nối tín hiệu khi trạng thái kết nối thay đổi
    connect(serialConnection, &SerialConnection::statusUpdated, this, &MainWindow::updateStatus);

    // Kết nối tín hiệu nhận dữ liệu
    connect(serialConnection, &SerialConnection::dataReceived, this, &MainWindow::processData);

    // Tự động mở kết nối UART khi ứng dụng khởi chạy
    if (serialConnection->openConnection("/dev/ttyUSB0", 115200)) {
        qDebug() << "Attempting to auto-connect to UART...";
    }
}

MainWindow::~MainWindow()
{
    serialConnection->closeConnection();
}

void MainWindow::updateStatus(bool status)
{
    isPortOpen = status;
    if (status) {
        qDebug() << "Connected to UART successfully!";
        statusLabel->setText("Status: Connected");
        statusLabel->setStyleSheet("font-size: 16px; color: green;");
    } else {
        qDebug() << "UART connection failed.";
        statusLabel->setText("Status: Disconnected");
        statusLabel->setStyleSheet("font-size: 16px; color: red;");
    }
}

void MainWindow::processData(const QByteArray &data)
{
    qDebug() << "Received data:" << data;

    QString receivedData(data);
    QStringList parts = receivedData.trimmed().split(";");

    if (parts.size() == 2) {
        // Xử lý giá trị tốc độ
        if (parts[0].startsWith("SPEED:")) {
            QString speedValue = parts[0].mid(6);
            speedLabel->setText(QString("Speed: %1 km/h").arg(speedValue.trimmed()));
        }

        // Xử lý giá trị nhiệt độ
        if (parts[1].startsWith("TEMP:")) {
            QString tempValue = parts[1].mid(5);
            temperatureLabel->setText(QString("Temperature: %1 °C").arg(tempValue.trimmed()));
        }
    }
}
