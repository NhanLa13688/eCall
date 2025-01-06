#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "serialconnection.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateStatus(bool status);               // Cập nhật trạng thái kết nối
    void processData(const QByteArray &data);     // Xử lý dữ liệu nhận được

private:
    SerialConnection *serialConnection;           // Đối tượng kết nối UART
    bool isPortOpen;                              // Trạng thái mở cổng

    QLabel *speedLabel;                           // Hiển thị giá trị tốc độ
    QLabel *temperatureLabel;                    // Hiển thị giá trị nhiệt độ
    QLabel *statusLabel;
}
