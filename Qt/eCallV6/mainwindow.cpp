#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), serialConnection(new SerialConnection(this)), isPortOpen(false)
{
    // Tạo giao diện
    toggleButton = new QPushButton("Open Port", this);
    statusLabel = new QLabel("Status: Disconnected", this);

    toggleButton->setGeometry(50, 50, 150, 50);
    statusLabel->setGeometry(50, 120, 200, 50);

    // Kết nối tín hiệu và slot
    connect(toggleButton, &QPushButton::clicked, this, &MainWindow::toggleConnection);
    connect(serialConnection, &SerialConnection::statusUpdated, this, &MainWindow::updateStatus);
}

MainWindow::~MainWindow()
{
}

void MainWindow::toggleConnection()
{
    if (isPortOpen) {
        serialConnection->closeConnection();
    } else {
        // Mở cổng với tên và tốc độ mặc định
        serialConnection->openConnection("/dev/ttyUSB0", 115200); 
    }
}

void MainWindow::updateStatus(bool status)
{
    isPortOpen = status;
    if (status) {
        statusLabel->setText("Status: Connected");
        toggleButton->setText("Close Port");
    } else {
        statusLabel->setText("Status: Disconnected");
        toggleButton->setText("Open Port");
    }
}
