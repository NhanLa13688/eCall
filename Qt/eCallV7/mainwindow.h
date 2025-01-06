#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include "serialconnection.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void toggleConnection();      // Xử lý mở/đóng cổng
    void updateStatus(bool status); // Cập nhật trạng thái kết nối

private:
    QPushButton *toggleButton;
    QLabel *statusLabel;

    SerialConnection *serialConnection;
    bool isPortOpen;
};

#endif // MAINWINDOW_H
