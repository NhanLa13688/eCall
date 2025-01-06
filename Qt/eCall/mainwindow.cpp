#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), serialConnection(new SerialConnection(this)), isPortOpen(false)
{
    // Thiết lập giao diện
    setFixedSize(400, 200);

    // Tạo QLabel để hiển thị tốc độ
    speedLabel = new QLabel("Speed: 0 km/h", this);
    speedLabel->setGeometry(50, 50, 300, 30);
    speedLabel->setStyleSheet("font-size: 18px; font-weight: bold;");

    // Tạo QLabel để hiển thị nhiệt độ
    temperatureLabel = new QLabel("Temperature: 0 °C", this);
    temperatureLabel->setGeometry(50, 100, 300, 30);
    temperatureLabel->setStyleSheet("font-size: 18px; font-weight: bold;");

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
    } else {
        qDebug() << "UART connection failed.";
    }
}

void MainWindow::processData(const QByteArray &data)
{
    // Giả sử dữ liệu nhận được có định dạng: "SPEED:<value>;TEMP:<value>\n"
    qDebug() << "Received data:" << data;

    QString receivedData(data);

    // Tách dữ liệu từ frame
    if (receivedData.contains("SPEED:") && receivedData.contains("TEMP:")) {
        QStringList parts = receivedData.split(";");

        // Xử lý giá trị tốc độ
        if (parts[0].startsWith("SPEED:")) {
            QString speedValue = parts[0].mid(6);  // Lấy giá trị sau "SPEED:"
            speedLabel->setText(QString("Speed: %1 km/h").arg(speedValue.trimmed()));
        }

        // Xử lý giá trị nhiệt độ
        if (parts[1].startsWith("TEMP:")) {
            QString tempValue = parts[1].mid(5);  // Lấy giá trị sau "TEMP:"
            temperatureLabel->setText(QString("Temperature: %1 °C").arg(tempValue.trimmed()));
        }
    }
}
