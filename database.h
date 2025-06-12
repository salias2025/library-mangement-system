#ifndef DATABASE_H
#define DATABASE_H
#include "user.h"
#include "ubook.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

class Database
{
public:
    Database();  // Constructor
    ~Database(); // Destructor

    bool openConnection();  // Open connection to the database
    void closeConnection(); // Close the connection

    static void createStudentsTable();
    static void createAdminsTable();
    static void createBooksTable();
    static void createMagazinesTable();
    static void createNewspaperTable();

    static bool addStudent(const QString &first_name, const QString &family_name, const QDate &birthdate,
                           const QString &student_id,const QString &username, const QString &password,int study_year);
    static bool addAdmin(const QString &first_name, const QString &family_name, const QDate &birthdate,
                           const QString &student_id,const QString &username, const QString &password);
    static bool add_book(const QString &title, const QString &author, const QString &genre, const QString &description,
                        const int &num_of_pages, const int &copies);
    static bool add_magazine(const QString &title ,const QString &author,const QString &genre ,const QString &description,
                         const int &num_of_pages , const int & copies,const double &price);
    static bool add_newspaper(const QString &title ,const QString &author,const QString &genre ,const QString &description,
                         const int &num_of_pages , const int & copies,const QString &editor);

    static bool removeStudent(const QString &username);
   static bool removeAdmin(const QString &username);
   static bool remove_book(const QString &title);
   static bool remove_magazine(const QString &title);
   static bool remove_newspaper(const QString &title);
    static void loadStudents();
    static  void loadAdmins();
    static void load_books();
    static void load_magazines();
    static void load_newspaper();
   static bool borrowBook(const QString &title, const QString &borrowDate, const QString &returnDate, const QString &username);
    static bool borrowMagazine(const QString &title, const QString &borrowDate, const QString &returnDate, const QString &username);
   static bool borrowNewspaper(const QString &title, const QString &borrowDate, const QString &returnDate, const QString &username);
    static bool returnBook(const QString &title, const QString &rating, const QString &username);
   static bool returnMagazine(const QString &title, const QString &rating, const QString &username);
   static bool returnNewspaper(const QString &title, const QString &rating, const QString &username);
private:
    QSqlDatabase db;
};

#endif // DATABASE_H
