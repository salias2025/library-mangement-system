#include "table_issued.h"
#include "ui_table_issued.h"
#include "ubook.h"
#include "user.h"

table_issued::table_issued(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::table_issued)
{
    ui->setupUi(this);
     ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    int issuedCount = 0;


    for (book* b : book::books) {
        issuedCount += b->get_number_of_issued_copies();
    }


    ui->tableWidget->setRowCount(issuedCount);

    int row = 0;

    for (user* u : user::users) {

        student* s = dynamic_cast<student*>(u);
        if (!s) continue;  // Skip if not a student

        std::vector<QString> borrowedBooks = s->borrowed_books_list;
        std::vector<QDate> borrowDates = s->borrow_dates;
        std::vector<QDate> returnDates = s->return_dates;

        for (int i = 0; i < borrowedBooks.size(); ++i) {
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(i == 0 ? s->get_username() : ""));
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(borrowedBooks[i]));
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(borrowDates[i].toString("yyyy-MM-dd")));
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(
                                                 returnDates[i].isValid() ? returnDates[i].toString("yyyy-MM-dd") : "Not Returned"
                                                 ));

            bool isDeadlinePassed = returnDates[i].isValid() && QDate::currentDate() > returnDates[i];
            QTableWidgetItem* deadlineItem = new QTableWidgetItem(isDeadlinePassed ? "Yes" : "No");

            if (isDeadlinePassed) {
                deadlineItem->setBackground(QColor(255, 102, 102));
                deadlineItem->setForeground(QColor(255, 255, 255));
            }

            ui->tableWidget->setItem(row, 4, deadlineItem);

            QColor rowcolor = (row % 2 == 0) ? QColor(253, 252, 220) : QColor(255, 243, 176);
            for (int col = 0; col < 4; ++col) { // Color only columns 0–3
                QTableWidgetItem* item = ui->tableWidget->item(row, col);
                if (item) item->setBackground(rowcolor);
            }

            row++;
        }
    }

    ui->tableWidget->resizeColumnsToContents();
}

table_issued::~table_issued()
{
    delete ui;
}
