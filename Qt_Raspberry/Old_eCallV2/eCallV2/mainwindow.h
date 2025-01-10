#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QDateTime>
#include <json.hpp>
#include <QDebug>
#include <QEventLoop>
#include "fstream"

#include <iostream>
#include <string>
#include <cstring>
#include <arpa/inet.h>  // Cho inet_pton
#include <sys/socket.h> // Cho socket
#include <unistd.h>     // Cho close và read
#include <QTcpSocket>     // Để sử dụng QTcpSocket
#include <QJsonObject>    // Để tạo JSON object
#include <QJsonDocument>  // Để chuyển đổi JSON object thành QByteArray
#include "serialconnection.h"

using json = nlohmann::json;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void updateSpeed();
    void updatePbattery();
    void updatePdistance();
    void updatePfuel();
    void updatePavgspeed();
    void updateReady();
    void updateTime();
    void updateDate();
    void updateInc();
    void updateDec();
    void handleSOS();
    void updateABS();
    void updateECO();
    void updateSmart();
    void updateSport();
    void delay(int millseconds);
    //void changeButtonColor();

    // Serial
    void processData(const QByteArray &data);


private:
    Ui::MainWindow *ui;

    int speed; // Biến để lưu giá trị tốc độ hiện tại
    int battery; // Bien luu gia tri cua battery
    int distance;
    int fuel;
    int avgspeed;
    int temp;
    int tempMC;

    QTimer *timer; // Timer để cập nhật tốc độ

    float getCPUTemperature();
    void updateTemperature();

};

#endif // MAINWINDOW_H
