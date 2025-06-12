#include "table_students.h"
#include "ui_table_students.h"
#include "user.h"
#include <QMessageBox>
#include "database.h"
#include <QColor>
table_students::table_students(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::table_students)
{
    ui->setupUi(this);
     ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(ui->searchBar, &QLineEdit::textChanged, this, &table_students::on_searchBar_textChanged);
        ui->searchBar->setPlaceholderText("Search books by title...");
    //lets fill the table
    user::users.clear();
    Database::loadStudents();
    Database::loadAdmins();
    user::sort_users();

    ui->tableWidget->setRowCount(student::students_counter);
    ui->tableWidget->setColumnCount(7); // Ensure this matches your layout

    int row = 0;
    for (int i = 0; i < user::users_counter; i++) {
        qDebug()<< user::users_counter<<"atnaaaaaam";
        user* ptr = user::users[i];
        student* std = dynamic_cast<student*>(ptr);
        if (std != nullptr) {
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(std->get_first_name()));
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(std->get_family_name()));
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(std->get_birth_date().toString()));
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(std->get_id()));
            ui->tableWidget->setItem(row, 4, new QTableWidgetItem(std->get_username()));
            ui->tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(std->get_study_year())));
            qDebug()<<"step3";
            QString borrowedBooksList;
            for (const QString& book : std->borrowed_books_list) {
                borrowedBooksList += book + ", ";
            }
            if (!borrowedBooksList.isEmpty()) borrowedBooksList.chop(2); // remove last comma

            ui->tableWidget->setItem(row, 6, new QTableWidgetItem(borrowedBooksList));
            qDebug()<<"step 4";
            QColor rowcolor = (row % 2 == 0) ? QColor(224, 170, 255) : QColor(199, 125, 255);
            for (int col = 0; col < 7; ++col) {
                QTableWidgetItem* item = ui->tableWidget->item(row, col);
                if (item) item->setBackground(rowcolor);
            }

            row++;
        }
    }



}

table_students::~table_students()
{
    delete ui;
}

void table_students::on_remove_student_clicked()
{
    int row = ui->tableWidget->currentRow();
    if (row >= 0) {
        // Check if column 6 (borrowed books) is not empty
        QTableWidgetItem* borrowedBooksItem = ui->tableWidget->item(row, 6);
        if (borrowedBooksItem && !borrowedBooksItem->text().isEmpty()) {
            QMessageBox::warning(this, "Cannot Delete Student",
                                 "This student cannot be deleted because they have borrowed books.");
            return;
        }

        QString username = ui->tableWidget->item(row, 4)->text();

        admin a;
        if (a.remove_students(username)) {
            QMessageBox::information(this, "Info", "Student deleted successfully.");
            user::users.clear();
            Database::loadStudents();
            Database::loadAdmins();
            user::sort_users();

            ui->tableWidget->removeRow(row);
        } else {
            QMessageBox::warning(this, "Error", "Failed to delete student from database.");
        }
    } else {
        QMessageBox::warning(this, "Warning", "Please select a row to delete.");
    }
}
void table_students::on_searchBar_textChanged(const QString &searchText)
{
    for(int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        QTableWidgetItem *titleItem = ui->tableWidget->item(row, 4); // First column has titles
        bool match = titleItem->text().contains(searchText, Qt::CaseInsensitive);
        ui->tableWidget->setRowHidden(row, !match);
    }
}
