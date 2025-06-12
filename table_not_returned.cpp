#include "table_not_returned.h"
#include "ui_table_not_returned.h"
#include "user.h"
#include "ubook.h"
#include "QMessageBox"
#include "database.h"
table_not_returned::table_not_returned(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::table_not_returned)
{
    ui->setupUi(this);
    user::users.clear();
    book::books.clear();

     Database::loadStudents();
    Database::loadAdmins();
     Database::load_books();
    Database::load_magazines();
     Database::load_newspaper();
    book::sort();

    //lets try something that might work
    QString usrnm=user::current_user->get_username();
    int pos_current_user=user::search_user(usrnm);
    user *Actual_current_user=user::users[pos_current_user];

    //the thing stops here

    user::sort_users();
     ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    student* s = dynamic_cast<student*>(Actual_current_user);

    if (!s) {
        QMessageBox::warning(this, "Error", "Only students have borrowed books.");
        return;
    }

    int count = s->borrowed_books_list.size();
    ui->tableWidget->setRowCount(count);

    for (int i = 0; i < count; ++i) {
        QString title = s->borrowed_books_list[i];
        QString borrowDate = s->borrow_dates[i].toString("yyyy-MM-dd");
        QString returnDate = s->return_dates[i].toString("yyyy-MM-dd");
        bool isOverdue = QDate::currentDate() > s->return_dates[i];
        QString status = isOverdue ? "Overdue" : "On time";

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(title));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(borrowDate));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(returnDate));

        QTableWidgetItem* statusItem = new QTableWidgetItem(status);
        if (isOverdue) {
            statusItem->setBackground(QColor(255, 102, 102)); // Red background
            statusItem->setForeground(QColor(255, 255, 255)); // White text for readability
        }
        ui->tableWidget->setItem(i, 3, statusItem);

        QColor rowColor = (i % 2 == 0) ? QColor(141, 169, 196) : QColor(238, 244, 237);
        for (int col = 0; col < 3; ++col) { // Apply row color to first 3 columns only
            QTableWidgetItem* item = ui->tableWidget->item(i, col);
            if (item) item->setBackground(rowColor);
        }
    }
}

table_not_returned::~table_not_returned()
{
    delete ui;
}
