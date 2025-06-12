#include "mainwindow.h"
#include "database.h"
#include <QApplication>
#include "add_book.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Open the database connection before showing the main window
    Database db;
    if (!db.openConnection()) {
        qDebug() << "Database connection failed!";
        return -1;  // Exit if the database connection fails
    }else{
        qDebug() << "Database connection succeeded!";
    }
    Database::createStudentsTable();
    Database::createAdminsTable();
    Database::createBooksTable();
    Database::createMagazinesTable();
    Database::createNewspaperTable();
    Database::loadStudents();
    Database::loadAdmins();
    Database::load_books();
    Database::load_magazines();
    Database::load_newspaper();
    user::sort_users();
    book::sort();



    MainWindow w;
    w.show();
    return a.exec();
}
