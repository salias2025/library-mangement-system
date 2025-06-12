#ifndef USER_H
#define USER_H
#include <QString>
#include <QDate>
#include <vector>
#include "ubook.h"
class user{
protected:
    QString first_name;
    QString family_name;
    QDate date_of_birth;
    QString user_id;
    QString username;
    QString password;

public:
    //static data members(i set them public so they will be accessible from other files)
    static user *current_user;
    static int users_counter;
    static std::vector<user*> users;  // Use vector to store users
    //constructor
    user (QString fn="",QString famn="",QDate db = QDate(1990, 1, 1),QString id="",QString usrnm="",QString passwd="");
    virtual ~user();
    //setters
    void set_first_name(QString fn);
    void set_family_name(QString fn);
    void set_date_of_birth( QDate db);
     void set_id(QString id);
    void set_username(QString username);
    void set_password(QString passwd);

    //getters
     QString get_first_name();
    QString get_family_name();
     QDate get_birth_date();
    QString get_id();
    QString get_username();
     QString get_password();
    //additional methods

    static bool isStrongPassword(QString passwd);
      static  bool check_infos_validity(QString fn,QString famn,QString id );
    static bool check_username_unicity(QString usernm);
     static bool authenticate(QString usernm,QString passwd);
    static void sort_users();
    static int search_user(QString username);



};


class student :public user{
public:
    int study_year;
    std::vector<QString> borrowed_books_list;
    std::vector<QDate> borrow_dates;
    std::vector<QDate> return_dates;
    //counter
    static int students_counter;
public:
    void set_study_year(int sy);
    int get_study_year();
    student (QString fn="",QString famn="",QDate db = QDate(1990, 1, 1),QString id="",QString usrnm="",QString passwd="",int sy=1);
    ~student();
    static bool add_student(student *s);
    bool borrow_book (const QString &title, const QString &borrowDate, const QString &returnDate, const QString &username);
    bool return_book(const QString &title, const QString &rating, const QString &username);
    bool borrow_magazine(const QString &title, const QString &borrowDate, const QString &returnDate, const QString &username);
    bool return_magazine();
    bool borrow_newspaper(const QString &title, const QString &borrowDate, const QString &returnDate, const QString &username);
    bool return_newspaper();

};
class admin :public user{
private:
    const QString root_password;
public ://counter
   static  int admins_counter;
public:
    admin(QString fn="",QString famn="",QDate db = QDate(1990, 1, 1),QString id="",QString usrnm="",QString passwd="");
    ~admin();

    QString get_root_password();
    static bool add_admin(admin *ad);
    bool remove_admin(QString username);
    bool remove_students(QString usr);
    bool add_book(book *b);
    bool remove_book(QString title);
    bool add_magazine(magazine *m);
    bool remove_magazine(QString title);
    bool add_newspaper(newspaper *n);
    bool remove_newspaper(QString title);
};

#endif // USER_H
