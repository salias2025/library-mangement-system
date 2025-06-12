#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signin.h"
#include "login_form.h"
#include "admin_signin.h"
#include "admin_form.h"
#include "readme.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->read->setStyleSheet(
        "QPushButton {"
        " background-color: transparent;"
        " color: yellow;"
        " font-size: 22px;"
        " font-weight: bold;"
        "}"
        "QPushButton:hover {"
        " background-color: rgba(255, 255, 0, 180);"
        "}"
        );
    setStyleSheet("background-color: white;");
    // Set button styles
    ui->log_in->setStyleSheet(
        "QPushButton { background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #8B4513, stop:1 #A0522D); color: white; border: none; padding: 10px 20px; font-size: 16px; font-weight: bold; border-radius: 8px; }"
        "QPushButton:hover { background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #A0522D, stop:1 #8B4513); }"
        "QPushButton:pressed { background: #6A2E0F; }"
        );
    // Set button styles
    ui->sign_in->setStyleSheet(
        "QPushButton { background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #8B4513, stop:1 #A0522D); color: white; border: none; padding: 10px 20px; font-size: 16px; font-weight: bold; border-radius: 8px; }"
        "QPushButton:hover { background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #A0522D, stop:1 #8B4513); }"
        "QPushButton:pressed { background: #6A2E0F; }"
        );
    // Set button styles
    ui->log_admin->setStyleSheet(
        "QPushButton { background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #8B4513, stop:1 #A0522D); color: white; border: none; padding: 10px 20px; font-size: 16px; font-weight: bold; border-radius: 8px; }"
        "QPushButton:hover { background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #A0522D, stop:1 #8B4513); }"
        "QPushButton:pressed { background: #6A2E0F; }"
        );
    // Set button styles
    ui->sign_admin->setStyleSheet(
        "QPushButton { background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #8B4513, stop:1 #A0522D); color: white; border: none; padding: 10px 20px; font-size: 16px; font-weight: bold; border-radius: 8px; }"
        "QPushButton:hover { background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #A0522D, stop:1 #8B4513); }"
        "QPushButton:pressed { background: #6A2E0F; }"
        );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sign_in_clicked()
{
    signin s;
    s.setModal(true);
    s.exec();
}


void MainWindow::on_log_in_clicked()
{
    login_form l;
    l.setModal(true);
    l.exec();
}


void MainWindow::on_sign_admin_clicked()
{
    admin_signin s;
    s.setModal(true);
    s.exec();
}


void MainWindow::on_log_admin_clicked()
{
    admin_form f;
    f.setModal(true);
    f.exec();
}


void MainWindow::on_read_clicked()
{
    readme r;
    r.setModal(true);
    r.exec();
}

