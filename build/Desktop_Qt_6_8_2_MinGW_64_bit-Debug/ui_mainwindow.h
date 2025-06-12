/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *welcome;
    QLabel *pics;
    QPushButton *log_in;
    QPushButton *sign_admin;
    QPushButton *sign_in;
    QPushButton *log_admin;
    QLabel *label;
    QPushButton *read;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1539, 799);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        welcome = new QLabel(centralwidget);
        welcome->setObjectName("welcome");
        welcome->setGeometry(QRect(440, -10, 881, 121));
        welcome->setStyleSheet(QString::fromUtf8("font: 55pt \"Algerian\";\n"
"color:brown;"));
        pics = new QLabel(centralwidget);
        pics->setObjectName("pics");
        pics->setGeometry(QRect(520, 100, 511, 441));
        pics->setStyleSheet(QString::fromUtf8(" text-align: center;"));
        pics->setPixmap(QPixmap(QString::fromUtf8(":/pictures/intro.png")));
        log_in = new QPushButton(centralwidget);
        log_in->setObjectName("log_in");
        log_in->setGeometry(QRect(270, 350, 151, 51));
        sign_admin = new QPushButton(centralwidget);
        sign_admin->setObjectName("sign_admin");
        sign_admin->setGeometry(QRect(1110, 280, 151, 51));
        sign_in = new QPushButton(centralwidget);
        sign_in->setObjectName("sign_in");
        sign_in->setGeometry(QRect(270, 280, 151, 51));
        log_admin = new QPushButton(centralwidget);
        log_admin->setObjectName("log_admin");
        log_admin->setGeometry(QRect(1110, 350, 151, 51));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(390, 490, 741, 251));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/pictures/read.png);"));
        read = new QPushButton(centralwidget);
        read->setObjectName("read");
        read->setGeometry(QRect(690, 600, 171, 31));
        read->setStyleSheet(QString::fromUtf8("font: 14pt \"Sitka\";\n"
"font: 700 9pt \"Bahnschrift\";\n"
"color: rgb(255, 255, 0);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1539, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        welcome->setText(QCoreApplication::translate("MainWindow", "WELCOME TO LIBRO", nullptr));
        pics->setText(QString());
        log_in->setText(QCoreApplication::translate("MainWindow", "log In", nullptr));
        sign_admin->setText(QCoreApplication::translate("MainWindow", "sign as admin", nullptr));
        sign_in->setText(QCoreApplication::translate("MainWindow", "sign In", nullptr));
        log_admin->setText(QCoreApplication::translate("MainWindow", "log as admin", nullptr));
        label->setText(QString());
        read->setText(QCoreApplication::translate("MainWindow", "READ CAPTION", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
