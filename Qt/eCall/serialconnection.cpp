#include "serialconnection.h"
#include <QDebug>

SerialConnection::SerialConnection(QObject *parent)
    : QObject(parent), serialPort(new QSerialPort(this)), connected(false)
{
    // Kết nối tín hiệu khi dữ liệu UART sẵn sàng để đọc
    connect(serialPort, &QSerialPort::readyRead, this, &SerialConnection::readData);
}

SerialConnection::~SerialConnection()
{
    closeConnection();
}

bool SerialConnection::openConnection(const QString &portName, int baudRate)
{
    if (serialPort->isOpen()) {
        qDebug() << "Port is already open!";
        return false;
    }

    serialPort->setPortName(portName);
    serialPort->setBaudRate(baudRate);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (serialPort->open(QIODevice::ReadWrite)) {
        connected = true;
        emit statusUpdated(true);
        qDebug() << "UART port opened successfully!";
        return true;
    } else {
        qDebug() << "Failed to open UART port:" << serialPort->errorString();
        return false;
    }
}

void SerialConnection::closeConnection()
{
    if (serialPort->isOpen()) {
        serialPort->close();
        connected = false;
        emit statusUpdated(false);
        qDebug() << "UART port closed.";
    }
}

bool SerialConnection::isConnected() const
{
    return connected;
}

void SerialConnection::readData()
{
    QByteArray data = serialPort->readAll(); // Đọc tất cả dữ liệu từ UART
    emit dataReceived(data);                // Phát tín hiệu với dữ liệu nhận được
}
