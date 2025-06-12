#include "admin_options.h"
#include "ui_admin_options.h"
#include "ubook.h"
#include "user.h"
#include "table_students.h"
#include "table_admins.h"
#include "table_books.h"
#include "table_magazines.h"
#include "table_newspaper.h"
#include "table_issued.h"
#include "table_not_returned.h"

admin_options::admin_options(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::admin_options)
{
    ui->setupUi(this);

    // BOOKS BUTTON
    ui->books->setStyleSheet(
        "QPushButton { "
        "background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #6db3f2, stop:1 #1e69de);"
        "color: white; border: none; padding: 15px 20px; font-weight: bold; "
        "font-family: 'Georgia'; border-radius: 10px; }"
        "QPushButton:hover { background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #8ec4ff, stop:1 #2a7aff); }"
        "QPushButton:pressed { background: #0f3f9e; }"
        );
    ui->books->setText("CHECK AVAILABLE BOOKS" );


    // MAGAZINES BUTTON
    ui->magazines->setStyleSheet(
        "QPushButton { "
        "background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #ff5c5c, stop:1 #d41414);"
        "color: white; border: none; padding: 15px 20px; font-weight: bold; "
        "font-family: 'Georgia'; border-radius: 10px; }"
        "QPushButton:hover { background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #ff7b7b, stop:1 #e63434); }"
        "QPushButton:pressed { background: #a00000; }"
        );
    ui->magazines->setText("CHECK AVAILABLE MAGAZINES  " );

    // NEWSPAPERS BUTTON
    ui->newspapers->setStyleSheet(
        "QPushButton { "
        "background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #6ef27a, stop:1 #1daa2f);"
        "color: white; border: none; padding: 15px 20px; font-weight: bold; "
        "font-family: 'Georgia'; border-radius: 10px; }"
        "QPushButton:hover { background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #8ff297, stop:1 #3ae750); }"
        "QPushButton:pressed { background: #138000; }"
        );
    ui->newspapers->setText("CHECK AVAILABLE NEWSPAPERS" );

    // STUDENTS BUTTON
    ui->students->setStyleSheet(
        "QPushButton { "
        "background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #b366ff, stop:1 #8000ff);"
        "color: white; border: none; padding: 15px 20px; font-weight: bold; "
        "font-family: 'Georgia'; border-radius: 10px; }"
        "QPushButton:hover { background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #d580ff, stop:1 #b347ff); }"
        "QPushButton:pressed { background: #4b0082; }"
        );
    ui->students->setText("CHECK ALL THE USERS SIGNED IN TO OUR SERVICES" );

    // ADMINS BUTTON
    ui->admins->setStyleSheet(
        "QPushButton { "
        "background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #ffb366, stop:1 #ff8000);"
        "color: white; border: none; padding: 15px 20px; font-weight: bold; "
        "font-family: 'Georgia'; border-radius: 10px; }"
        "QPushButton:hover { background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #ffc280, stop:1 #ff9933); }"
        "QPushButton:pressed { background: #cc6600; }"
        );
    ui->admins->setText("CHECK IN ALL OUR ADMINSTRATORS" );

    // ISSUED BUTTON
    ui->issued->setStyleSheet(
        "QPushButton { "
        "background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #66fff2, stop:1 #00b3b3);"
        "color: white; border: none; padding: 15px 20px; font-weight: bold; "
        "font-family: 'Georgia'; border-radius: 10px; }"
        "QPushButton:hover { background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #80fff9, stop:1 #33cccc); }"
        "QPushButton:pressed { background: #007070; }"
        );

    //lets  compute how many issued books
    int issuedCount = 0;

    for ( book* b : book::books) {
        issuedCount+=b-> get_number_of_issued_copies();     }

    ui->issued->setText("TOTAL NUMBER OF ISSUED BOOKS IS:\n" + QString::number(issuedCount));


}

admin_options::~admin_options()
{
    delete ui;
}

void admin_options::on_books_clicked()
{
    table_books b;
    b.setModal(true);

    b.exec();
}


void admin_options::on_magazines_clicked()
{
    table_magazines m;
    m.setModal(true);

    m.exec();
}


void admin_options::on_newspapers_clicked()
{
    table_newspaper n;
    n.setModal(true);

    n.exec();
}


void admin_options::on_students_clicked()
{
    table_students s;
    s.setModal(true);
    s.exec();
}


void admin_options::on_admins_clicked()
{
    table_admins a;
    a.setModal(true);

    a.exec();
}


void admin_options::on_issued_clicked()
{
    table_issued i;
    i.setModal(true);

    i.exec();
}


void admin_options::on_non_returned_clicked()
{
    table_not_returned r;
    r.setModal(true);

    r.exec();
}

