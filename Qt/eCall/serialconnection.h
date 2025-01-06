#ifndef SERIALCONNECTION_H
#define SERIALCONNECTION_H

#include <QObject>
#include <QSerialPort>

class SerialConnection : public QObject
{
    Q_OBJECT

public:
    explicit SerialConnection(QObject *parent = nullptr);
    ~SerialConnection();

    bool openConnection(const QString &portName, int baudRate); // Mở cổng UART
    void closeConnection();                                     // Đóng cổng UART
    bool isConnected() const;                                   // Kiểm tra trạng thái kết nối

signals:
    void statusUpdated(bool isConnected);                      // Phát tín hiệu khi trạng thái thay đổi
    void dataReceived(const QByteArray &data);                 // Phát tín hiệu khi nhận dữ liệu

private slots:
    void readData();                                            // Xử lý dữ liệu nhận từ UART

private:
    QSerialPort *serialPort;
    bool connected;
};

#endif // SERIALCONNECTION_H
