#include "table_books.h"
#include "ui_table_books.h"
#include "ubook.h"
#include "user.h"
#include "add_book.h"
#include <QMessageBox>
#include "borrow.h"
#include "return_book.h"
#include "database.h"
table_books::table_books(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::table_books)
{


    ui->setupUi(this);

     ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(ui->search_bar, &QLineEdit::textChanged, this, &table_books::on_searchBar_textChanged);
      ui->search_bar->setPlaceholderText("Search books by title...");
    book::books.clear();
     Database::load_books();
     Database::load_magazines();
     Database::load_newspaper();
     book::sort();
    if (dynamic_cast<student*>(user::current_user)) {
        // current_user is a student
        ui->add->hide();
        ui->remove->hide();
    }
    else if (dynamic_cast<admin*>(user::current_user)) {
        // current_user is an admin
        ui->borrow->hide();
        ui->returm->hide();}
        ui->tableWidget->setRowCount(book::books_counter);


    for (int i = 0; i < book::books_counter; i++) {
        book *ptr = book::books[i];

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(ptr->get_title()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(ptr->get_author()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(ptr->get_genre()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(ptr->get_desciption()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(ptr->get_number_of_pages())));

        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(ptr->get_number_of_available_copies())));

        ui->tableWidget->setItem(i, 6, new QTableWidgetItem(QString::number(ptr->get_number_of_issued_copies())));

        ui->tableWidget->setItem(i, 7, new QTableWidgetItem(QString::number(ptr->get_number_of_returned_copies())));
        ui->tableWidget->setItem(i, 8, new QTableWidgetItem(QString::number(ptr->get_number_of_non_returned_copies())));  // Changed to "returned" copies

        ui->tableWidget->setItem(i, 9, new QTableWidgetItem(QString::number(ptr->calculate_rating())));

        QStringList borrowerList;
        for (const QString &borrower : ptr->borrowers) {
            borrowerList << borrower;
        }
        QString joinedBorrowers = borrowerList.join(", ");
        ui->tableWidget->setItem(i, 10, new QTableWidgetItem(joinedBorrowers));
        // Row coloring
        QColor rowcolor = (i % 2 == 0) ? QColor(173, 232, 244) : QColor(144, 224, 239);
        for (int col = 0; col <= 11; ++col) {
            QTableWidgetItem* item = ui->tableWidget->item(i, col);
            if (item) item->setBackground(rowcolor);
        }
    }
}

table_books::~table_books()
{
    delete ui;
}

void table_books::on_add_clicked()
{

    add_book b;
    b.setModal(true);
    this->close();
    b.exec();


}

void table_books::on_remove_clicked()
{
    int row = ui->tableWidget->currentRow();
    if (row >= 0) {
        // Check if column 10 (borrower column) is not empty
        QTableWidgetItem* borrowerItem = ui->tableWidget->item(row, 10);
        if (borrowerItem && !borrowerItem->text().isEmpty()) {
            QMessageBox::warning(this, "Cannot Delete",
                                 "This book cannot be deleted because it has active borrowers.");
            return;
        }

        QString title = ui->tableWidget->item(row, 0)->text(); // Assuming column 0 contains the book title

        admin a;
        if (a.remove_book(title)) {
            QMessageBox::information(this, "Info", "Book deleted successfully.");
            book::books_counter--;
            ui->tableWidget->removeRow(row);
        } else {
            QMessageBox::warning(this, "Error", "Failed to delete book from database.");
        }
    } else {
        QMessageBox::warning(this, "Warning", "Please select a row to delete.");
    }
}



void table_books::on_borrow_clicked()
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


void table_books::on_returm_clicked()
{
    int row = ui->tableWidget->currentRow();

    if (row < 0) {
        QMessageBox::warning(this, "Error", "Please select a book to return.");
        return;
    }

    QString title = ui->tableWidget->item(row, 0)->text();
    student *s = dynamic_cast<student*>(user::current_user);

    if (!s) {
        QMessageBox::warning(this, "Error", "Only students can return books.");
        return;
    }

    bool found = false;
    int pos=book::search_book(title);
    book *b=book::books[pos];
    for (const QString &borrower : b->borrowers) {

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

void table_books::on_searchBar_textChanged(const QString &searchText)
{
    for(int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        QTableWidgetItem *titleItem = ui->tableWidget->item(row, 0); // First column has titles
        bool match = titleItem->text().contains(searchText, Qt::CaseInsensitive);
        ui->tableWidget->setRowHidden(row, !match);
    }
}
