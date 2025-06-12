#include "table_admins.h"
#include "QMessagebox.h"
#include "ui_table_admins.h"
#include "user.h"
#include "database.h"
table_admins::table_admins(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::table_admins)
{
    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //lets fill the table
    ui->tableWidget->setRowCount(admin::admins_counter);
    ui->tableWidget->setColumnCount(5); // Ensure this matches your layout

    int row = 0;
    for (int i = 0; i < user::users_counter; i++) {
        user* ptr = user::users[i];
        admin* ad = dynamic_cast<admin*>(ptr);
        if (ad != nullptr) {
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(ad->get_first_name()));
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(ad->get_family_name()));
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(ad->get_birth_date().toString()));
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(ad->get_id()));
            ui->tableWidget->setItem(row, 4, new QTableWidgetItem(ad->get_username()));

            QColor rowcolor = (row % 2 == 0) ? QColor(253, 255, 182) : QColor(255, 214, 165);
            for (int col = 0; col < 5; ++col) {
                QTableWidgetItem* item = ui->tableWidget->item(row, col);
                if (item) item->setBackground(rowcolor);
            }

            row++;
        }
    }

}

table_admins::~table_admins()
{
    delete ui;
}

void table_admins::on_pushButton_clicked()
{
    int row = ui->tableWidget->currentRow();
    if (row >= 0) {
        QString username = ui->tableWidget->item(row, 4)->text(); // Assuming column 0 is the username

        admin a;
        if (a.remove_admin(username)) {
            QMessageBox::information(this, "Info", "Admin deleted successfully.");
            user::users.clear();
            Database::loadStudents();
            Database::loadAdmins();
            user::sort_users();

            ui->tableWidget->removeRow(row);
        } else {
            QMessageBox::warning(this, "Error", "Failed to delete admin from database.");
        }
    } else {
        QMessageBox::warning(this, "Warning", "Please select a row to delete.");
    }
}

