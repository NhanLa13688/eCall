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
    // In dữ liệu thô nhận được để debug
    qDebug() << "Raw Data Received:" << data.toHex();

    // Kiểm tra nếu frame bắt đầu bằng 0xAA
    if (data.size() >= 5 && static_cast<uint8_t>(data[0]) == 0xAA) {
        uint8_t id = static_cast<uint8_t>(data[1]); // ID
        uint8_t dlc = static_cast<uint8_t>(data[2]); // DLC

        if (data.size() >= 3 + dlc + 1) { // Đảm bảo frame có đủ dữ liệu
            QByteArray payload = data.mid(3, dlc); // Lấy payload
            uint8_t crc = static_cast<uint8_t>(data[3 + dlc]); // Lấy CRC

            // Kiểm tra CRC
            uint8_t calculated_crc = 0;
            for (int i = 0; i < 3 + dlc; i++) {
                calculated_crc ^= static_cast<uint8_t>(data[i]);
            }

            if (calculated_crc == crc) {
                // Phân tích payload dựa trên ID
                if (id == 0x01) { // Speed
                    int speed = (static_cast<uint8_t>(payload[0]) << 8) | static_cast<uint8_t>(payload[1]);
                    speedLabel->setText(QString("Speed: %1 km/h").arg(speed));
                } else if (id == 0x02) { // Temperature
                    int temperature = (static_cast<uint8_t>(payload[0]) << 8) | static_cast<uint8_t>(payload[1]);
                    temperatureLabel->setText(QString("Temperature: %1 °C").arg(temperature));
                }
            } else {
                qDebug() << "CRC mismatch!";
            }
        } else {
            qDebug() << "Incomplete frame!";
        }
    } else {
        qDebug() << "Invalid frame!";
    }
}

