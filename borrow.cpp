#include "borrow.h"
#include "ui_borrow.h"
#include "user.h"
#include "QMessageBox"
#include "database.h"
#include "table_books.h"
#include "table_magazines.h"
#include "table_newspaper.h"
borrow::borrow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::borrow)
{
    ui->setupUi(this);

    ui->borrow_date->setDate(QDate::currentDate());
    ui->borrow_date->setReadOnly(true);
    ui->return_date->setDate(QDate::currentDate());
    ui->return_date->setMaximumDate(QDate::currentDate().addMonths(2));
   ui->return_date->setMinimumDate(QDate::currentDate().addDays(1));
}

borrow::~borrow()
{
    delete ui;
}
void borrow::setTitle(const QString& title)
{
    ui->title->setReadOnly(true);
    ui->title->setText(title);
}
void borrow::setAuthor(const QString& author)
{
    ui->title->setReadOnly(true);
    ui->author->setText(author);
}
void borrow::on_pushButton_clicked()
{
    QString usr = user::current_user->get_username();
    QString title = ui->title->text();
    QString borrow_date = ui->borrow_date->date().toString("yyyy-MM-dd");
    QString return_date = ui->return_date->date().toString("yyyy-MM-dd");

    student s;
    int pos = book::search_book(title);
    book *b = book::books[pos];

    // Check if it's a magazine
    if (dynamic_cast<magazine*>(b)) {
        if (s.borrow_magazine(title, borrow_date, return_date, usr)) {
            QMessageBox::information(this, "Success", "Magazine borrowed successfully.");
        } else {
            QMessageBox::warning(this, "Failure", "Failed to borrow the magazine.");
            return;
        }

        // Refresh data and show updated magazine table
        book::books.clear();
        user::users.clear();
        Database::load_books();
        Database::load_magazines();
        Database::load_newspaper();
        Database::loadStudents();
        Database::loadAdmins();
        user::sort_users();
        book::sort();

        table_magazines m;
        m.setModal(true);
        this->close();
        m.exec();
        return;
    }

    // Check if it's a newspaper
    if (dynamic_cast<newspaper*>(b)) {
        if (s.borrow_newspaper(title, borrow_date, return_date, usr)) {
            QMessageBox::information(this, "Success", "Newspaper borrowed successfully.");
        } else {
            QMessageBox::warning(this, "Failure", "Failed to borrow the newspaper.");
            return;
        }

        // Refresh data and show updated newspaper table
        book::books.clear();
        user::users.clear();
        Database::load_books();
        Database::load_magazines();
        Database::load_newspaper();
        Database::loadStudents();
        Database::loadAdmins();
        book::sort();
        table_newspaper n;
        n.setModal(true);
        this->close();
        n.exec();
        return;
    }

    // Otherwise, treat it as a regular book
    if (s.borrow_book(title, borrow_date, return_date, usr)) {
        QMessageBox::information(this, "Success", "Book borrowed successfully.");
    } else {
        QMessageBox::warning(this, "Failure", "Failed to borrow the book.");
        return;
    }

    // Refresh data and show updated book table
    book::books.clear();
    user::users.clear();
    Database::load_books();
    Database::load_magazines();
    Database::load_newspaper();
    Database::loadStudents();
    Database::loadAdmins();
    book::sort();
    table_books tb;
    tb.setModal(true);
    this->close();
    tb.exec();
}
