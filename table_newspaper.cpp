#include "table_newspaper.h"
#include "ui_table_newspaper.h"
#include "ubook.h"
#include "user.h"
#include "add_newspaper.h"
#include <QMessageBox>
#include "database.h"
#include "return_book.h"
#include "borrow.h"
table_newspaper::table_newspaper(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::table_newspaper)
{
    book::books.clear();
    Database::load_books();
    Database::load_magazines();
    Database::load_newspaper();
    book::sort();
    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(ui->search_bar, &QLineEdit::textChanged, this, &table_newspaper::on_searchBar_textChanged);
     ui->search_bar->setPlaceholderText("Search books by title...");
    if (dynamic_cast<student*>(user::current_user)) {
        // current_user is a student
        ui->add->hide();
        ui->remove->hide();
    }
    else if (dynamic_cast<admin*>(user::current_user)) {
        // current_user is an admin
        ui->borrow->hide();
        ui->returm->hide();
        ui->tableWidget->setRowCount(book::books_counter);}

    ui->tableWidget->setRowCount(newspaper::newspaper_counter);

    int row = 0;
    for (int i = 0; i < book::books_counter; i++) {
        book *ptr = book::books[i];
        newspaper *nw = dynamic_cast<newspaper*>(ptr);
        if (nw != nullptr) {
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(nw->get_title()));
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(nw->get_author()));
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(nw->get_editor()));
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(nw->get_desciption()));
            ui->tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(nw->get_number_of_pages())));
            ui->tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(nw->get_number_of_available_copies())));
            ui->tableWidget->setItem(row, 6, new QTableWidgetItem(QString::number(nw->get_number_of_issued_copies())));
            ui->tableWidget->setItem(row, 7, new QTableWidgetItem(QString::number(nw->get_number_of_returned_copies())));
            ui->tableWidget->setItem(row, 8, new QTableWidgetItem(QString::number(nw->get_number_of_non_returned_copies())));
            ui->tableWidget->setItem(row, 9, new QTableWidgetItem(QString::number(nw->calculate_rating())));

            QStringList borrowerList;
            for (const QString &borrower : ptr->borrowers) {
                borrowerList << borrower;
            }
            QString joinedBorrowers = borrowerList.join(", ");
            ui->tableWidget->setItem(row, 10, new QTableWidgetItem(joinedBorrowers));

            QColor rowcolor = (row % 2 == 0) ? QColor(152, 245, 225) : QColor(185, 251, 192);
            for (int col = 0; col <= 11; ++col) {
                QTableWidgetItem* item = ui->tableWidget->item(row, col);
                if (item) item->setBackground(rowcolor);
            }

            row++; // Move to next table row only if it's a newspaper
        }
    }
}

table_newspaper::~table_newspaper()
{
    delete ui;
}

void table_newspaper::on_add_clicked()
{
    add_newspaper n;
    n.setModal(true);
    this->close();
    n.exec();
}


void table_newspaper::on_remove_clicked()
{
    int row = ui->tableWidget->currentRow();
    if (row >= 0) {
        // First check if newspaper is borrowed (assuming column 10 contains borrower info)
        QTableWidgetItem* borrowerItem = ui->tableWidget->item(row, 10);
        if (borrowerItem && !borrowerItem->text().isEmpty()) {
            QMessageBox::warning(this, "Cannot Delete",
                                 "This newspaper cannot be deleted because it has active borrowers.");
            return;
         }

        QTableWidgetItem* titleItem = ui->tableWidget->item(row, 0);
        if (!titleItem) {
            QMessageBox::warning(this, "Error", "Selected row is invalid.");
            return;
        }

        QString title = titleItem->text();

        admin a;
        if (a.remove_newspaper(title)) {
            QMessageBox::information(this, "Info", "Newspaper deleted successfully.");
            if (newspaper::newspaper_counter > 0) {
                newspaper::newspaper_counter--;
            }
            ui->tableWidget->removeRow(row);
        } else {
            QMessageBox::warning(this, "Error", "Failed to delete newspaper from database.");
        }
    } else {
        QMessageBox::warning(this, "Warning", "Please select a row to delete.");
    }
}
void table_newspaper::on_returm_clicked()
{
    int row = ui->tableWidget->currentRow();

    if (row < 0) {
        QMessageBox::warning(this, "Error", "Please select a book to return.");
        return;
    }

    QString title = ui->tableWidget->item(row, 0)->text().trimmed();
    student *s = dynamic_cast<student*>(user::current_user);

    if (!s) {
        QMessageBox::warning(this, "Error", "Only students can return books.");
        return;
    }

    bool found = false;
    int pos=book::search_book(title);
    book *b=book::books[pos];
    for (const QString &borrower : b->borrowers) {
        qDebug()<<"book:"<<borrower;
        if (borrower == s->get_username()) {
            found = true;
            break;
        }
    }


    if (found) {
        QString usr = user::current_user->get_username();
        return_book *b = new return_book;
        b->setTitle(title);
        b->setUser(usr);
        b->setModal(true);
        this->close();
        b->exec();
    } else {
        QMessageBox::warning(this, "Error", "You did not borrow that book.");
    }
}


void table_newspaper::on_borrow_clicked()
{
    // Get the selected row
    int row = ui->tableWidget->currentRow();

    // Make sure a row is selected
    if (row >= 0) {
        int available =ui->tableWidget->item(row,5)->text().toInt();
        int issued=ui->tableWidget->item(row,6)->text().toInt();
        if (issued>=available){
            QMessageBox::warning(this,"warning","the book is not available right now");
            return;
        }


        QString borrowers = ui->tableWidget->item(row, 10)->text(); // Borrowers list
        QString current_username = user::current_user->get_username();

        if (borrowers.contains(current_username)) {
            QMessageBox::warning(this, "Warning", "You have already borrowed this book.");
            return;
        }


        // Get title and author from the selected row
        QString title = ui->tableWidget->item(row, 0)->text();
        QString author = ui->tableWidget->item(row, 1)->text();
        borrow *b=new borrow();
        b->setTitle(title);
        b->setAuthor(author);
        b->setModal(true);
        this->hide();
        b->exec();


    }
}
void table_newspaper::on_searchBar_textChanged(const QString &searchText)
{
    for(int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        QTableWidgetItem *titleItem = ui->tableWidget->item(row, 0); // First column has titles
        bool match = titleItem->text().contains(searchText, Qt::CaseInsensitive);
        ui->tableWidget->setRowHidden(row, !match);
    }
}



