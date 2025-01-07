/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *odo;
    QLabel *speedLabel;
    QLabel *PbatteryLabel;
    QLabel *kmhLabel;
    QLabel *batteryLabel;
    QLabel *PdistanceLabel;
    QLabel *distancLabel;
    QLabel *fuelLabel;
    QLabel *avgspeedLabel;
    QLabel *PfuelLabel;
    QLabel *PavgspeedLabel;
    QLabel *readyLabel;
    QLabel *timeLabel;
    QLabel *dateLabel;
    QLabel *tempLabel;
    QPushButton *incLabel;
    QPushButton *decLabel;
    QPushButton *sosButton;
    QLabel *settempLabel;
    QLabel *absLabel;
    QLabel *ecoLabel;
    QLabel *smartLabel;
    QLabel *sportLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(693, 458);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        odo = new QLabel(centralWidget);
        odo->setObjectName(QStringLiteral("odo"));
        odo->setGeometry(QRect(0, -10, 691, 381));
        odo->setPixmap(QPixmap(QString::fromUtf8("../odo.jpg")));
        odo->setScaledContents(true);
        speedLabel = new QLabel(centralWidget);
        speedLabel->setObjectName(QStringLiteral("speedLabel"));
        speedLabel->setGeometry(QRect(314, 130, 61, 51));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        speedLabel->setFont(font);
        speedLabel->setLayoutDirection(Qt::RightToLeft);
        speedLabel->setAutoFillBackground(false);
        PbatteryLabel = new QLabel(centralWidget);
        PbatteryLabel->setObjectName(QStringLiteral("PbatteryLabel"));
        PbatteryLabel->setGeometry(QRect(140, 147, 81, 51));
        PbatteryLabel->setFont(font);
        PbatteryLabel->setLayoutDirection(Qt::RightToLeft);
        PbatteryLabel->setAutoFillBackground(false);
        kmhLabel = new QLabel(centralWidget);
        kmhLabel->setObjectName(QStringLiteral("kmhLabel"));
        kmhLabel->setGeometry(QRect(325, 170, 41, 22));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        kmhLabel->setFont(font1);
        batteryLabel = new QLabel(centralWidget);
        batteryLabel->setObjectName(QStringLiteral("batteryLabel"));
        batteryLabel->setGeometry(QRect(139, 186, 91, 21));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setWeight(75);
        batteryLabel->setFont(font2);
        PdistanceLabel = new QLabel(centralWidget);
        PdistanceLabel->setObjectName(QStringLiteral("PdistanceLabel"));
        PdistanceLabel->setGeometry(QRect(523, 120, 131, 21));
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(true);
        font3.setWeight(75);
        PdistanceLabel->setFont(font3);
        PdistanceLabel->setLayoutDirection(Qt::RightToLeft);
        PdistanceLabel->setAutoFillBackground(false);
        distancLabel = new QLabel(centralWidget);
        distancLabel->setObjectName(QStringLiteral("distancLabel"));
        distancLabel->setGeometry(QRect(522, 141, 121, 22));
        QFont font4;
        font4.setPointSize(8);
        font4.setBold(true);
        font4.setWeight(75);
        distancLabel->setFont(font4);
        fuelLabel = new QLabel(centralWidget);
        fuelLabel->setObjectName(QStringLiteral("fuelLabel"));
        fuelLabel->setGeometry(QRect(523, 185, 131, 20));
        QFont font5;
        font5.setPointSize(7);
        font5.setBold(true);
        font5.setWeight(75);
        fuelLabel->setFont(font5);
        avgspeedLabel = new QLabel(centralWidget);
        avgspeedLabel->setObjectName(QStringLiteral("avgspeedLabel"));
        avgspeedLabel->setGeometry(QRect(524, 225, 121, 20));
        avgspeedLabel->setFont(font5);
        PfuelLabel = new QLabel(centralWidget);
        PfuelLabel->setObjectName(QStringLiteral("PfuelLabel"));
        PfuelLabel->setGeometry(QRect(526, 163, 121, 31));
        PfuelLabel->setFont(font3);
        PfuelLabel->setLayoutDirection(Qt::RightToLeft);
        PfuelLabel->setAutoFillBackground(false);
        PavgspeedLabel = new QLabel(centralWidget);
        PavgspeedLabel->setObjectName(QStringLiteral("PavgspeedLabel"));
        PavgspeedLabel->setGeometry(QRect(527, 205, 111, 31));
        PavgspeedLabel->setFont(font3);
        PavgspeedLabel->setLayoutDirection(Qt::RightToLeft);
        PavgspeedLabel->setAutoFillBackground(false);
        readyLabel = new QLabel(centralWidget);
        readyLabel->setObjectName(QStringLiteral("readyLabel"));
        readyLabel->setGeometry(QRect(315, 320, 68, 22));
        QFont font6;
        font6.setPointSize(14);
        font6.setBold(true);
        font6.setWeight(75);
        readyLabel->setFont(font6);
        timeLabel = new QLabel(centralWidget);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        timeLabel->setGeometry(QRect(306, 10, 81, 22));
        timeLabel->setFont(font1);
        dateLabel = new QLabel(centralWidget);
        dateLabel->setObjectName(QStringLiteral("dateLabel"));
        dateLabel->setGeometry(QRect(438, 10, 101, 22));
        dateLabel->setFont(font1);
        tempLabel = new QLabel(centralWidget);
        tempLabel->setObjectName(QStringLiteral("tempLabel"));
        tempLabel->setGeometry(QRect(160, 10, 51, 22));
        tempLabel->setFont(font1);
        incLabel = new QPushButton(centralWidget);
        incLabel->setObjectName(QStringLiteral("incLabel"));
        incLabel->setGeometry(QRect(120, 310, 31, 31));
        QFont font7;
        font7.setPointSize(18);
        font7.setBold(true);
        font7.setWeight(75);
        incLabel->setFont(font7);
        decLabel = new QPushButton(centralWidget);
        decLabel->setObjectName(QStringLiteral("decLabel"));
        decLabel->setGeometry(QRect(210, 310, 31, 31));
        decLabel->setFont(font7);
        sosButton = new QPushButton(centralWidget);
        sosButton->setObjectName(QStringLiteral("sosButton"));
        sosButton->setGeometry(QRect(480, 310, 61, 31));
        sosButton->setFont(font7);
        settempLabel = new QLabel(centralWidget);
        settempLabel->setObjectName(QStringLiteral("settempLabel"));
        settempLabel->setGeometry(QRect(155, 315, 51, 22));
        settempLabel->setFont(font6);
        absLabel = new QLabel(centralWidget);
        absLabel->setObjectName(QStringLiteral("absLabel"));
        absLabel->setGeometry(QRect(550, 60, 68, 22));
        absLabel->setFont(font6);
        ecoLabel = new QLabel(centralWidget);
        ecoLabel->setObjectName(QStringLiteral("ecoLabel"));
        ecoLabel->setGeometry(QRect(40, 200, 68, 22));
        ecoLabel->setFont(font6);
        smartLabel = new QLabel(centralWidget);
        smartLabel->setObjectName(QStringLiteral("smartLabel"));
        smartLabel->setGeometry(QRect(27, 120, 71, 22));
        smartLabel->setFont(font6);
        sportLabel = new QLabel(centralWidget);
        sportLabel->setObjectName(QStringLiteral("sportLabel"));
        sportLabel->setGeometry(QRect(20, 160, 68, 22));
        sportLabel->setFont(font6);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 693, 28));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        odo->setText(QString());
        speedLabel->setText(QApplication::translate("MainWindow", "0", nullptr));
        PbatteryLabel->setText(QApplication::translate("MainWindow", "0", nullptr));
        kmhLabel->setText(QApplication::translate("MainWindow", "Km/h", nullptr));
        batteryLabel->setText(QApplication::translate("MainWindow", "Battery charge", nullptr));
        PdistanceLabel->setText(QApplication::translate("MainWindow", "0", nullptr));
        distancLabel->setText(QApplication::translate("MainWindow", "Distance", nullptr));
        fuelLabel->setText(QApplication::translate("MainWindow", "Avg. Fuel Usage", nullptr));
        avgspeedLabel->setText(QApplication::translate("MainWindow", "Avg. Speed", nullptr));
        PfuelLabel->setText(QApplication::translate("MainWindow", "0", nullptr));
        PavgspeedLabel->setText(QApplication::translate("MainWindow", "0", nullptr));
        readyLabel->setText(QApplication::translate("MainWindow", "READY", nullptr));
        timeLabel->setText(QApplication::translate("MainWindow", "hh:mm:ss", nullptr));
        dateLabel->setText(QApplication::translate("MainWindow", "dd:mm:yyyy", nullptr));
        tempLabel->setText(QApplication::translate("MainWindow", "27 \302\260C", nullptr));
        incLabel->setText(QApplication::translate("MainWindow", "+", nullptr));
        decLabel->setText(QApplication::translate("MainWindow", "-", nullptr));
        sosButton->setText(QApplication::translate("MainWindow", "SOS", nullptr));
        settempLabel->setText(QApplication::translate("MainWindow", "TEMP", nullptr));
        absLabel->setText(QString());
        ecoLabel->setText(QString());
        smartLabel->setText(QString());
        sportLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
