#include "serialconnection.h"
#include <QDebug>

SerialConnection::SerialConnection(QObject *parent)
    : QObject(parent), serialPort(new QSerialPort(this)), connected(false)
{
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
        qDebug() << "Port opened successfully!";
        return true;
    } else {
        qDebug() << "Failed to open port:" << serialPort->errorString();
        return false;
    }
}

void SerialConnection::closeConnection()
{
    if (serialPort->isOpen()) {
        serialPort->close();
        connected = false;
        emit statusUpdated(false);
        qDebug() << "Port closed successfully!";
    }
}

bool SerialConnection::isConnected() const
{
    return connected;
}
