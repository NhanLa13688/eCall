#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QObject>
#include <QSerialPort>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , speed(0)
    , temp(27)
    , tempMC(45)
{
    ui->setupUi(this);

    // create timer
    timer = new QTimer(this);

    ui->distancLabel->setStyleSheet("color: white;");
    ui->fuelLabel->setStyleSheet("color: white;");
    ui->avgspeedLabel->setStyleSheet("color: white;");
    ui->timeLabel->setStyleSheet("color: white;");
    ui->dateLabel->setStyleSheet("color: white;");
    ui->readyLabel->setStyleSheet("color: green;");

    ui->tempLabel->setText(QString::number(temp) + " °C");
    ui->tempLabel->setStyleSheet("color: white; font-size: 18px;");

    ui->tempMCLabel->setText(QString::number(tempMC) + " °C");
    ui->tempMCLabel->setStyleSheet("color: red; font-size: 25px; Bold;");

    ui->sosButton->setStyleSheet("background-color: blue; color: black; font-size: 18px;");

    QTcpSocket socket; // Uesr QTcpSocket serial TCP
    socket.connectToHost("192.168.137.61", 65432); // adrr IP and port server

    connect(timer, &QTimer::timeout, this, &MainWindow::updateSpeed);
    connect(timer, &QTimer::timeout, this, &MainWindow::updatePbattery);
    connect(timer, &QTimer::timeout, this, &MainWindow::updatePdistance);
    connect(timer, &QTimer::timeout, this, &MainWindow::updatePfuel);
    connect(timer, &QTimer::timeout, this, &MainWindow::updatePavgspeed);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateReady);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateABS);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateECO);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateSmart);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateSport);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateDate);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTemperature);

    //connect(ui->sosButton, &QPushButton::clicked, this, &MainWindow::changeButtonColor);
    connect(ui->incLabel, &QPushButton::clicked, this, &MainWindow::updateInc);
    connect(ui->decLabel, &QPushButton::clicked, this, &MainWindow::updateDec);
    connect(ui->sosButton, &QPushButton::clicked, this, &MainWindow::handleSOS);
    
    // start timer
    timer->start(1250);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateSpeed()
{
    speed += 1;
    if (speed > 250)
        speed = 0;

    ui->speedLabel->setText(QString::number(speed));
    ui->speedLabel->setStyleSheet("color: cyan; font-size: 33px;");

    ui->kmhLabel->setStyleSheet("color: cyan;");

    ui->speedLabel->setAlignment(Qt::AlignCenter);
}
void MainWindow::updatePbattery()
{
    battery += 1;
    if (battery > 100)
        battery = 0;

    ui->PbatteryLabel->setText(QString::number(battery)+"%");
    ui->PbatteryLabel->setStyleSheet("color: white; font-size: 33px;");
    ui->batteryLabel->setStyleSheet("color: white; ");
    ui->PbatteryLabel->setAlignment(Qt::AlignCenter);
}
void MainWindow::updatePdistance()
{
    distance += 1;
    if (distance > 10000)
        distance = 0;


    ui->PdistanceLabel->setText(QString::number(distance)+" KM");
    ui->PdistanceLabel->setStyleSheet("color: white; font-size: 10px;");
    ui->PdistanceLabel->setStyleSheet("color: white; ");
    ui->PdistanceLabel->setAlignment(Qt::AlignLeft);

}
void MainWindow::updatePfuel()
{
    fuel += 1;
    if (fuel > 75)
        fuel = 0;

    ui->PfuelLabel->setText(QString::number(fuel)+" mpg");
    ui->PfuelLabel->setStyleSheet("color: white; font-size: 10px;");
    ui->PfuelLabel->setStyleSheet("color: white; ");
    ui->PfuelLabel->setAlignment(Qt::AlignLeft);

}
void MainWindow::updatePavgspeed()
{
    avgspeed += 1;
    if (avgspeed > 90)
        avgspeed = 0;

    ui->PavgspeedLabel->setText(QString::number(avgspeed)+" mph");
    ui->PavgspeedLabel->setStyleSheet("color: white; font-size: 10px;");
    ui->PavgspeedLabel->setStyleSheet("color: white; ");
    ui->PavgspeedLabel->setAlignment(Qt::AlignLeft);
}
void MainWindow::updateReady()
{
     static int currentIndex = 0; // Chỉ số trạng thái hiện tại
     static const QStringList states = {"READY", "P", "R", "N", "D"}; // Các trạng thái
     static const QStringList colors = {"green", "blue", "red", "orange", "green"}; // Màu sắc cho từng trạng thái
     ui->readyLabel->setAlignment(Qt::AlignCenter);
     ui->readyLabel->setText(states[currentIndex]);
     ui->readyLabel->setStyleSheet(QString("color: %1; font-size: 22px;").arg(colors[currentIndex]));

     // switch next status
     currentIndex = (currentIndex + 1) % states.size();

}
void MainWindow::updateTime()
{
    QTime currentTime = QTime::currentTime();
    QString timeString = currentTime.toString("HH:mm:ss");


    ui->timeLabel->setText(timeString);
    ui->timeLabel->setAlignment(Qt::AlignCenter);
    ui->timeLabel->setStyleSheet("color: white; font-size: 18px; ");
}
void MainWindow::updateDate()
{
       QDateTime currentDateTime = QDateTime::currentDateTime();
       QString dateString = currentDateTime.date().toString("dd/MM/yyyy");

       ui->dateLabel->setText(dateString);
       ui->dateLabel->setAlignment(Qt::AlignCenter);
       ui->dateLabel->setStyleSheet("color: white; font-size: 18px;");
}
void MainWindow::updateInc()
{
    temp++;
    if(temp>35)
    (temp = 35);

    ui->tempLabel->setText(QString::number(temp) + " °C");
    ui->tempLabel->setStyleSheet("color: white; font-size: 18px;");
}
void MainWindow::updateDec()
{

    temp--;
    if(temp < 16)
    (temp = 16);

    ui->tempLabel->setText(QString::number(temp) + " °C");
    ui->tempLabel->setStyleSheet("color: white; font-size: 18px;"); // Tùy chỉnh màu sắc nếu cần
}
void MainWindow::delay( int millseconds)
{
    QEventLoop loop;
    QTimer::singleShot(millseconds, &loop, &QEventLoop::quit);
    loop.exec();
}

void MainWindow::handleSOS()
{

        qDebug() << "Button --> SOS";
        ui->sosButton->setStyleSheet("background-color: red; color: red; font-size: 18px;");

       QTcpSocket socket;
       socket.connectToHost("192.168.137.61", 65432);
       if (!socket.waitForConnected(3000))
       {

                qDebug() << "Failed to connect to server.";
                ui->statusLabel->setText("FAILED TO CONNECT!");
                ui->statusLabel->setStyleSheet("color: red; font-size: 16px; bold;");
                return;
       }

       // Send JSON COMMAN to SERVER
       QJsonObject command;
       command["command"] = "ON";
       QJsonDocument doc(command);
       QByteArray data = doc.toJson();

       socket.write(data);
       if (!socket.waitForBytesWritten(3000))
       {
                qDebug() << "Failed to send data to server.";
                ui->statusLabel->setText("SOS SEND FAILED !");
                ui->statusLabel->setStyleSheet("color: red; font-size: 16px; bold;");

       }
       else
       {
                qDebug() << "SOS command sent to server.";
                ui->statusLabel->setText("SOS SEND DONE !");
                ui->statusLabel->setStyleSheet("color: red; font-size: 16px; bold;");

       }

       if (socket.waitForReadyRead(3000))
       {
                QByteArray response = socket.readAll();
                std::string responseStr = response.toStdString(); // Chuyển đổi sang std::string

                qDebug() << "Response from server:" << QString::fromStdString(responseStr);

                ui->statusLabel->setText(QString::fromStdString(responseStr));
                ui->statusLabel->setStyleSheet("color: red; font-size: 16px; bold;");
        }
        else
        {
                   qDebug() << "No response from server.";
                   ui->statusLabel->setText("No response from PSAP !");
                   ui->statusLabel->setStyleSheet("color: red; font-size: 16px; bold;");
        }

        socket.disconnectFromHost();
        delay(1000);
        ui->sosButton->setStyleSheet("background-color: red; color: black; font-size: 18px;");

}
void MainWindow::updateABS()
{
    static int currentIndex = 0; // Chỉ số trạng thái hiện tại
    static const QStringList states = {"(ABS)", "(ABS)"}; // Các trạng thái
    static const QStringList colors = {"black", "orange"}; // Màu sắc cho từng trạng thái

    ui->absLabel->setAlignment(Qt::AlignCenter);
    ui->absLabel->setText(states[currentIndex]);
    ui->absLabel->setStyleSheet(QString("color: %1; font-size: 22px;").arg(colors[currentIndex]));

    currentIndex = (currentIndex + 1) % states.size(); // Quay vòng trạng thái
}
void MainWindow::updateECO()
{
    static int currentIndex = 0; // Chỉ số trạng thái hiện tại
    static const QStringList states = {"ECO", "ECO"}; // Các trạng thái
    static const QStringList colors = {"black", "blue"}; // Màu sắc cho từng trạng thái

    ui->ecoLabel->setAlignment(Qt::AlignCenter);
    ui->ecoLabel->setText(states[currentIndex]);
    ui->ecoLabel->setStyleSheet(QString("color: %1; font-size: 22px;").arg(colors[currentIndex]));

    currentIndex = (currentIndex + 1) % states.size(); // Quay vòng trạng thái
}
void MainWindow::updateSmart()
{
    static int currentIndex = 0; // Chỉ số trạng thái hiện tại
    static const QStringList states = {"SMART", "SMART"}; // Các trạng thái
    static const QStringList colors = {"black", "green"}; // Màu sắc cho từng trạng thái

    ui->smartLabel->setAlignment(Qt::AlignCenter);
    ui->smartLabel->setText(states[currentIndex]);
    ui->smartLabel->setStyleSheet(QString("color: %1; font-size: 22px;").arg(colors[currentIndex]));

    currentIndex = (currentIndex + 1) % states.size(); // Quay vòng trạng thái
}
void MainWindow::updateSport()
{
    static int currentIndex = 0; // Chỉ số trạng thái hiện tại
    static const QStringList states = {"SPORT", "SPORT"}; // Các trạng thái
    static const QStringList colors = {"black", "RED"}; // Màu sắc cho từng trạng thái

    ui->sportLabel->setAlignment(Qt::AlignCenter);
    ui->sportLabel->setText(states[currentIndex]);
    ui->sportLabel->setStyleSheet(QString("color: %1; font-size: 22px;").arg(colors[currentIndex]));

    currentIndex = (currentIndex + 1) % states.size(); // Quay vòng trạng thái
}

void MainWindow::processData(const QByteArray &data)
{
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
                    ui->speedLabel->setText(QString("Speed: %1 km/h").arg(speed));
                } else if (id == 0x02) { // Temperature
                   // int temperature = (static_cast<uint8_t>(payload[0]) << 8) | static_cast<uint8_t>(payload[1]);
                   // temperatureLabel->setText(QString("Temperature: %1 °C").arg(temperature));
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

float MainWindow::getCPUTemperature() {
    std::ifstream file("/sys/class/thermal/thermal_zone0/temp");
    float tempMC = 0.0;
    if (file.is_open()) {
        file >> tempMC;
        tempMC /= 1000;  // Chuyển đổi milliCelsius sang Celsius
    }
    return tempMC;
}

void MainWindow::updateTemperature() {
    int tempMC = static_cast<int>(getCPUTemperature());
    QString tempText = QString("%1 °C").arg(tempMC);
    ui->tempMCLabel->setText(tempText);
}

