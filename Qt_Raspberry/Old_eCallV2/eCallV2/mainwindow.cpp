#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , speed(0) // Khởi tạo tốc độ ban đầu là 0
    , temp(27) // Khoi tao nhiet do ban dau la 27
{
    ui->setupUi(this);

    // Tạo QTimer để cập nhật tốc độ
    timer = new QTimer(this);

    ui->distancLabel->setStyleSheet("color: white;");
    ui->fuelLabel->setStyleSheet("color: white;");
    ui->avgspeedLabel->setStyleSheet("color: white;");
    ui->timeLabel->setStyleSheet("color: white;");
    ui->dateLabel->setStyleSheet("color: white;");
    ui->readyLabel->setStyleSheet("color: green;");
    ui->tempLabel->setText(QString::number(temp) + " °C");
    ui->tempLabel->setStyleSheet("color: white; font-size: 18px;");
    ui->sosButton->setStyleSheet("background-color: red; color: black; font-size: 18px;");

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


    //connect(ui->sosButton, &QPushButton::clicked, this, &MainWindow::changeButtonColor);
    connect(ui->incLabel, &QPushButton::clicked, this, &MainWindow::updateInc);
    connect(ui->decLabel, &QPushButton::clicked, this, &MainWindow::updateDec);
    connect(ui->sosButton, &QPushButton::clicked, this, &MainWindow::handleSOS);

    // Bắt đầu timer, cập nhật mỗi 100ms
    timer->start(1550);
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

    // Hiển thị tốc độ lên QLabel
    ui->speedLabel->setText(QString::number(speed));

    // Dat mau chu la do
    ui->speedLabel->setStyleSheet("color: cyan; font-size: 33px;");
    ui->kmhLabel->setStyleSheet("color: cyan;");
    // Can phai noi dung
    ui->speedLabel->setAlignment(Qt::AlignCenter);
}
void MainWindow::updatePbattery()
{
    //
    battery += 1;
    if (battery > 100)
        battery = 0;

    // Hiển thị tốc độ lên QLabel
    ui->PbatteryLabel->setText(QString::number(battery)+"%");

    // Dat mau chu la do
    ui->PbatteryLabel->setStyleSheet("color: white; font-size: 33px;");
    ui->batteryLabel->setStyleSheet("color: white; ");
    // Can phai noi dung
    ui->PbatteryLabel->setAlignment(Qt::AlignCenter);
}
void MainWindow::updatePdistance()
{
    distance += 1;
    if (distance > 10000)
        distance = 0;

    // Hiển thị tốc độ lên QLabel
    ui->PdistanceLabel->setText(QString::number(distance)+" KM");

    // Dat mau chu la do
    ui->PdistanceLabel->setStyleSheet("color: white; font-size: 10px;");
    ui->PdistanceLabel->setStyleSheet("color: white; ");
    // Can phai noi dung
    ui->PdistanceLabel->setAlignment(Qt::AlignLeft);

}
void MainWindow::updatePfuel()
{
    fuel += 1;
    if (fuel > 75)
        fuel = 0;

    // Hiển thị tốc độ lên QLabel
    ui->PfuelLabel->setText(QString::number(fuel)+" mpg");

    // Dat mau chu la do
    ui->PfuelLabel->setStyleSheet("color: white; font-size: 10px;");
    ui->PfuelLabel->setStyleSheet("color: white; ");
    // Can phai noi dung
    ui->PfuelLabel->setAlignment(Qt::AlignLeft);

}
void MainWindow::updatePavgspeed()
{
    avgspeed += 1;
    if (avgspeed > 90)
        avgspeed = 0;

    // Hiển thị tốc độ lên QLabel
    ui->PavgspeedLabel->setText(QString::number(avgspeed)+" mph");

    // Dat mau chu la do
    ui->PavgspeedLabel->setStyleSheet("color: white; font-size: 10px;");
    ui->PavgspeedLabel->setStyleSheet("color: white; ");
    // Can phai noi dung
    ui->PavgspeedLabel->setAlignment(Qt::AlignLeft);
}
void MainWindow::updateReady()
{
     static int currentIndex = 0; // Chỉ số trạng thái hiện tại
     static const QStringList states = {"READY", "P", "R", "N", "D"}; // Các trạng thái
     static const QStringList colors = {"green", "blue", "red", "orange", "green"}; // Màu sắc cho từng trạng thái
     ui->readyLabel->setAlignment(Qt::AlignCenter);
     // Cập nhật chữ và màu sắc
     ui->readyLabel->setText(states[currentIndex]);
     ui->readyLabel->setStyleSheet(QString("color: %1; font-size: 22px;").arg(colors[currentIndex]));

     // Chuyển sang trạng thái tiếp theo
     currentIndex = (currentIndex + 1) % states.size(); // Quay vòng trạng thái

}
void MainWindow::updateTime()
{
    // Lấy thời gian hiện tại từ hệ thống
    QTime currentTime = QTime::currentTime();

    // Chuyển đổi thời gian thành chuỗi định dạng "HH:mm:ss"
    QString timeString = currentTime.toString("HH:mm:ss");

    // Cập nhật QLabel hiển thị thời gian
    ui->timeLabel->setText(timeString);

    // Đảm bảo căn giữa văn bản
    ui->timeLabel->setAlignment(Qt::AlignCenter);

    // Thay đổi màu sắc và kiểu chữ nếu cần
    ui->timeLabel->setStyleSheet("color: white; font-size: 18px;");
}
void MainWindow::updateDate()
{
    // Lấy thời gian và ngày hiện tại
       QDateTime currentDateTime = QDateTime::currentDateTime();

       // Chuyển đổi thời gian và ngày thành chuỗi
       QString dateString = currentDateTime.date().toString("dd/MM/yyyy");

       // Cập nhật QLabel hiển thị thời gian và ngày
       ui->dateLabel->setText(dateString);

       // Đảm bảo căn giữa văn bản
       ui->dateLabel->setAlignment(Qt::AlignCenter);
       ui->dateLabel->setStyleSheet("color: white; font-size: 18px;");
}
void MainWindow::updateInc()
{
    // Tang nhiet do
    temp++;
    if(temp>35)
    (temp = 35);
    ui->tempLabel->setText(QString::number(temp) + " °C");
    ui->tempLabel->setStyleSheet("color: white; font-size: 18px;"); // Tùy chỉnh màu sắc nếu cần
}
void MainWindow::updateDec()
{
    // Giảm nhiệt độ
    temp--;
    if(temp < 16)
    (temp = 16);
    // Cập nhật giao diện
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


//    void updateECO();
   // static bool isSOSActive = false; // Biến để lưu trạng thái hiện tại

//    if (isSOSActive) {
        // Trạng thái tắt: Đổi màu nút trở lại mặc định
  //      ui->sosButton->setStyleSheet("background-color: gray; color: black; font-size: 18px;");
  //  } else {
        // Trạng thái bật: Đổi màu nút sang đỏ
  //osButton->setStyleSheet("background-color: red; color: white; font-size: 18px;");
  //  }
        qDebug() << "Da Nhan SOS";
        ui->sosButton->setStyleSheet("background-color: red; color: red; font-size: 18px;");

        QTcpSocket socket; // Sử dụng QTcpSocket cho giao tiếp TCP
            socket.connectToHost("192.168.137.22", 65432); // Địa chỉ IP và cổng của server

            if (!socket.waitForConnected(3000)) {
                qDebug() << "Failed to connect to server.";
                return;
            }

            // Tạo JSON command để gửi tới server
            QJsonObject command;
            command["command"] = "ON"; // Gửi lệnh SOS
            QJsonDocument doc(command);
            QByteArray data = doc.toJson();

            // Gửi dữ liệu tới server
            socket.write(data);
            if (!socket.waitForBytesWritten(3000)) {
                qDebug() << "Failed to send data to server.";
            } else {
                qDebug() << "SOS command sent to server.";
            }

            // Đọc phản hồi từ server (nếu có)
            if (socket.waitForReadyRead(3000)) {
                QByteArray response = socket.readAll();
                QJsonDocument responseDoc = QJsonDocument::fromJson(response);
                QJsonObject responseObj = responseDoc.object();

                qDebug() << "Response from server:" << responseObj;
            } else {
                qDebug() << "No response from server.";
            }

            socket.disconnectFromHost();
            delay(1000);
            ui->sosButton->setStyleSheet("background-color: red; color: black; font-size: 18px;");

}
void MainWindow::updateABS()
{
#include <sys/socket.h> // Cho socket
    static int currentIndex = 0; // Chỉ số trạng thái hiện tại
    static const QStringList states = {"(ABS)", "(ABS)"}; // Các trạng thái
    static const QStringList colors = {"black", "orange"}; // Màu sắc cho từng trạng thái
    ui->absLabel->setAlignment(Qt::AlignCenter);
    // Cập nhật chữ và màu sắc
    ui->absLabel->setText(states[currentIndex]);
    ui->absLabel->setStyleSheet(QString("color: %1; font-size: 22px;").arg(colors[currentIndex]));

    // Chuyển sang trạng thái tiếp theo
    currentIndex = (currentIndex + 1) % states.size(); // Quay vòng trạng thái
}
void MainWindow::updateECO()
{
    static int currentIndex = 0; // Chỉ số trạng thái hiện tại
    static const QStringList states = {"ECO", "ECO"}; // Các trạng thái
    static const QStringList colors = {"black", "blue"}; // Màu sắc cho từng trạng thái
    ui->ecoLabel->setAlignment(Qt::AlignCenter);
    // Cập nhật chữ và màu sắc
    ui->ecoLabel->setText(states[currentIndex]);
    ui->ecoLabel->setStyleSheet(QString("color: %1; font-size: 22px;").arg(colors[currentIndex]));

    // Chuyển sang trạng thái tiếp theo
    currentIndex = (currentIndex + 1) % states.size(); // Quay vòng trạng thái
}
void MainWindow::updateSmart()
{
    static int currentIndex = 0; // Chỉ số trạng thái hiện tại
    static const QStringList states = {"SMART", "SMART"}; // Các trạng thái
    static const QStringList colors = {"black", "green"}; // Màu sắc cho từng trạng thái
    ui->smartLabel->setAlignment(Qt::AlignCenter);
    // Cập nhật chữ và màu sắc
    ui->smartLabel->setText(states[currentIndex]);
    ui->smartLabel->setStyleSheet(QString("color: %1; font-size: 22px;").arg(colors[currentIndex]));

    // Chuyển sang trạng thái tiếp theo
    currentIndex = (currentIndex + 1) % states.size(); // Quay vòng trạng thái
}
void MainWindow::updateSport()
{
    static int currentIndex = 0; // Chỉ số trạng thái hiện tại
    static const QStringList states = {"SPORT", "SPORT"}; // Các trạng thái
    static const QStringList colors = {"black", "RED"}; // Màu sắc cho từng trạng thái
    ui->sportLabel->setAlignment(Qt::AlignCenter);
    // Cập nhật chữ và màu sắc
    ui->sportLabel->setText(states[currentIndex]);
    ui->sportLabel->setStyleSheet(QString("color: %1; font-size: 22px;").arg(colors[currentIndex]));

    // Chuyển sang trạng thái tiếp theo
    currentIndex = (currentIndex + 1) % states.size(); // Quay vòng trạng thái
}
//void MainWindow::changeButtonColor() {
//    static bool isRed = false; // Trạng thái hiện tại của màu nút

//    if (isRed) {
//        ui->sosButton->setStyleSheet("background-color: gray; color: black; font-size: 18px;");
//    } else {
//        ui->sosButton->setStyleSheet("background-color: red; color: white; font-size: 18px;");
//    }

//    isRed = !isRed; // Đổi trạng thái
//}
