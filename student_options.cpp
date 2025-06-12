#include "student_options.h"
#include "ui_student_options.h"
#include "ubook.h"
#include "table_books.h"
#include "table_magazines.h"
#include "table_newspaper.h"
#include "table_not_returned.h"
student_options::student_options(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::student_options)
{
    ui->setupUi(this);

    // BOOKS BUTTON
    ui->books->setStyleSheet(
        "QPushButton { "
        "background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #6db3f2, stop:1 #1e69de);"
        "color: white; border: none; padding: 15px 20px; font-size: 16px; font-weight: bold; "
        "font-family: 'Georgia'; border-radius: 10px; }"
        "QPushButton:hover { "
        "background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #8ec4ff, stop:1 #2a7aff); }"
        "QPushButton:pressed { background: #0f3f9e; }"
        );
    ui->books->setText("CHECK IN ALL THE AVAILABLE BOOKS IN THE LIBRARY" );

    // MAGAZINES BUTTON
    ui->magazines->setStyleSheet(
        "QPushButton { "
        "background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #ff5c5c, stop:1 #d41414);"
        "color: white; border: none; padding: 15px 20px; font-size: 16px; font-weight: bold; "
        "font-family: 'Georgia'; border-radius: 10px; }"
        "QPushButton:hover { "
        "background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #ff7b7b, stop:1 #e63434); }"
        "QPushButton:pressed { background: #a00000; }"
        );
    ui->magazines->setText("CHECK IN ALL THE AVAILABLE MAGAZINES IN THE LIBRARY" );

    // NEWSPAPERS BUTTON
    ui->newspapers->setStyleSheet(
        "QPushButton { "
        "background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #6ef27a, stop:1 #1daa2f);"
        "color: white; border: none; padding: 15px 20px; font-size: 16px; font-weight: bold; "
        "font-family: 'Georgia'; border-radius: 10px; }"
        "QPushButton:hover { "
        "background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #8ff297, stop:1 #3ae750); }"
        "QPushButton:pressed { background: #138000; }"
        );
    ui->newspapers->setText("CHECK IN ALL THE AVAILABLE NEWSPAPERS IN TH LIBRARY" );

    // NON-RETURNED BUTTON
    ui->non_returned->setStyleSheet(
        "QPushButton { "
        "background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #ff66b3, stop:1 #cc0077);"
        "color: white; border: none; padding: 15px 20px; font-weight: bold; "
        "font-family: 'Georgia'; border-radius: 10px; }"
        "QPushButton:hover { background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #ff80c2, stop:1 #e60099); }"
        "QPushButton:pressed { background: #99004d; }"
        );

    ui->non_returned->setText("CHECK IN ALL THE BOOKS YOU BORROWED ");


}

student_options::~student_options()
{
    delete ui;
}

void student_options::on_books_clicked()
{
    table_books b;
    b.setModal(true);
    b.exec();
}


void student_options::on_magazines_clicked()
{
    table_magazines m;
    m.setModal(true);
    m.exec();
}


void student_options::on_newspapers_clicked()
{
    table_newspaper n;
    n.setModal(true);
    n.exec();

}


void student_options::on_non_returned_clicked()
{
    table_not_returned r;
    r.setModal(true);
    r.exec();
}

