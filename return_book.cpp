#include "return_book.h"
#include "ui_return_book.h"
#include "QMessageBox"
#include "user.h"
#include "database.h"
#include "table_books.h"
#include "table_magazines.h"
#include "table_newspaper.h"
return_book::return_book(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::return_book)
{
    ui->setupUi(this);
}

return_book::~return_book()
{
    delete ui;
}
void return_book::setTitle(const QString& title)
{
    ui->title->setReadOnly(true);
    ui->title->setText(title);
}
void return_book::setUser(const QString& author)
{
    ui->username->setReadOnly(true);
    ui->username->setText(author);
}

void return_book::on_confirm_clicked()
{
    QString usrnm = user::current_user->get_username();
    QString title = ui->title->text();

    bool ok;
    int num_rate = ui->rate->text().toInt(&ok);

    if (!ok || num_rate < 0 || num_rate > 10) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid integer between 0 and 10.");
        return;
    }


    // Find the book by title from the static books vector
    book* targetBook = nullptr;
    for (book* b : book::books) {
       if (b->get_title() == title) {
            targetBook = b;
            break;
        }
    }

    if (!targetBook) {
        QMessageBox::warning(this, "Error", "Book not found.");
        return;
    }

    bool success = false;

    // Check type via dynamic cast
    if (dynamic_cast<magazine*>(targetBook)) {
        qDebug()<<"casting 1";
        success = Database::returnMagazine(title, QString::number(num_rate), usrnm);
    } else if (dynamic_cast<newspaper*>(targetBook)) {
        qDebug()<<"casting 2";
        success = Database::returnNewspaper(title, QString::number(num_rate), usrnm);
    } else {
        qDebug()<<"before the return";
        qDebug()<<title<<QString::number(num_rate)<<usrnm;
        success = Database::returnBook(title, QString::number(num_rate), usrnm);
        qDebug()<<"after  the return";

    }


    if (success) {
        QMessageBox::information(this, "Congrats", "Item returned successfully.");
        book::books.clear();
        user::users.clear();
        Database::load_books();
        Database::load_magazines();
        Database::load_newspaper();
        Database::loadStudents();
        Database::loadAdmins();
        user::sort_users();
        book::sort();
        table_books b;
        b.setModal(true);
        this->close();
        b.exec();



    } else {
        QMessageBox::warning(this, "Error", "Failed to return item.");
    }
}
