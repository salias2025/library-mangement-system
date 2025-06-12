#include "user.h"
#include <QMessageBox>
#include <QString>
#include <QChar>
#include <algorithm>
#include "database.h"
// Definition of static members
user* user::current_user = nullptr;  // Definition and initialization
int user::users_counter = 0;
std::vector<user*> user::users;

int student::students_counter = 0;
int admin::admins_counter = 0;

// user class implementation

user::user(QString fn, QString famn, QDate db, QString id, QString usrnm, QString passwd) {
    first_name = fn;
    family_name = famn;
    date_of_birth = db;
    user_id = id;
    username = usrnm;
    password = passwd;
}

user::~user() {}

// Setters
void user::set_first_name(QString fn) { first_name = fn; }
void user::set_family_name(QString fn) { family_name = fn; }
void user::set_date_of_birth(QDate db) { date_of_birth = db; }
void user::set_id(QString id) { user_id = id; }
void user::set_username(QString usrnm) { username = usrnm; }
void user::set_password(QString passwd) { password = passwd; }

// Getters
QString user::get_first_name() { return first_name; }
QString user::get_family_name() { return family_name; }
QDate user::get_birth_date() { return date_of_birth; }
QString user::get_id() { return user_id; }
QString user::get_username() { return username; }
QString user::get_password() { return password; }

// Additional methods

bool user::isStrongPassword(QString passwd) {
    if (passwd.length() < 8) {
        QMessageBox::warning(nullptr, "Password Error", "Password must be at least 8 characters long.");
        return false;
    }

    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    for (const QChar &ch : passwd) {
        if (ch.isUpper()) {
            hasUpper = true;
        } else if (ch.isLower()) {
            hasLower = true;
        } else if (ch.isDigit()) {
            hasDigit = true;
        } else if (!ch.isLetterOrNumber()) {
            hasSpecial = true;
        }
    }

    if (!hasUpper) {
        QMessageBox::warning(nullptr, "Password Error", "Password must contain at least one uppercase letter.");
        return false;
    }
    if (!hasLower) {
        QMessageBox::warning(nullptr, "Password Error", "Password must contain at least one lowercase letter.");
        return false;
    }
    if (!hasDigit) {
        QMessageBox::warning(nullptr, "Password Error", "Password must contain at least one digit.");
        return false;
    }
    if (!hasSpecial) {
        QMessageBox::warning(nullptr, "Password Error", "Password must contain at least one special character.");
        return false;
    }

    // All conditions met
    return true;
}

bool user::check_infos_validity(QString fn, QString famn, QString id) {
    // Check if fn contains only letters
    for (const QChar &ch : fn) {
        if (!ch.isLetter() && ch!=' ') {
            QMessageBox::warning(nullptr, "Invalid First Name", "First name must contain only letters.");
            return false;
        }
    }

    // Check if famn contains only letters
    for (const QChar &ch : famn) {
        if (!ch.isLetter() && ch!=' ') {
            QMessageBox::warning(nullptr, "Invalid Family Name", "Family name must contain only letters.");
            return false;
        }
    }

    // Check if id length is 8
    if (id.length() != 8) {
        QMessageBox::warning(nullptr, "Invalid ID", "ID must be exactly 8 digits long.");
        return false;
    }

    // Check if id contains only digits
    for (const QChar &ch : id) {
        if (!ch.isDigit()) {
            QMessageBox::warning(nullptr, "Invalid ID", "ID must contain only digits.");
            return false;
        }
    }

    // All checks passed
    return true;
}

bool user::check_username_unicity(QString usernm) {
    for (user* u : user::users) {
        if (u->get_username() == usernm) {
            QMessageBox::warning(nullptr,"warning","user already exists");
            return false;  // username already exists
        }
    }
    return true;  // username is unique
}

bool user::authenticate(QString usernm, QString passwd) {
    for (user* u : user::users) {
        if (u->get_username() == usernm && u->get_password() == passwd) {
            return true;  // user found and password matches
        }
    }
    return false;  // no match found
}

void user::sort_users() {
    std::sort(users.begin(), users.end(), [](user* a, user* b) {
        return a->get_first_name() < b->get_first_name();
    });
}

int user::search_user(QString usernm) {
    for (int i = 0; i < users_counter; ++i) {
        if (users[i]->get_username() == usernm) {
            return i;  // found, return index
        }
    }
    return -1;  // not found
}


// student class implementation

student::student(QString fn, QString famn, QDate db, QString id, QString usrnm, QString passwd, int sy)
    : user(fn, famn, db, id, usrnm, passwd), study_year(sy) {
}

student::~student() {
}

void student::set_study_year(int sy) {
    study_year = sy;
}

int student::get_study_year() {
    return study_year;
}

bool student::add_student(student* s) {
    return Database::addStudent(s->get_first_name(),s->get_family_name(),s->get_birth_date(),s->get_id(),
s->get_username(),s->get_password(),s->get_study_year());

}

bool student::borrow_book(const QString &title, const QString &borrowDate, const QString &returnDate, const QString &username){

    return Database::borrowBook(title, borrowDate, returnDate, username);
}
bool student::return_book(const QString &title, const QString &rating, const QString &username){
    return Database::returnBook(title,rating,username);
};

bool student::borrow_magazine(const QString &title, const QString &borrowDate, const QString &returnDate, const QString &username){
    return Database::borrowMagazine(title,borrowDate,returnDate, username);
};
bool student::return_magazine(){

};
bool student::borrow_newspaper(const QString &title, const QString &borrowDate, const QString &returnDate, const QString &username){
    return Database::borrowNewspaper(title,borrowDate,returnDate, username);
};
bool student::return_newspaper(){

};





// admin class implementation

admin::admin(QString fn, QString famn, QDate db, QString id, QString usrnm, QString passwd)
    : user(fn, famn, db, id, usrnm, passwd), root_password("viva l'algerie") {
}

admin::~admin() {
}

QString admin::get_root_password() {
    return root_password;
}

bool admin::add_admin(admin* ad) {
    Database::addAdmin(ad->get_first_name(),ad->get_family_name(),ad->get_birth_date(),ad->get_id(),
                       ad->get_username(),ad->get_password());
    return true;
}
bool admin::remove_admin(QString username){
    Database::removeAdmin(username);
        return true;
}
bool admin::remove_students(QString usr) {
    Database::removeStudent(usr);
    return true;
}

bool admin::add_book(book* b) {
    Database::add_book(b->get_title(),b->get_author(),b->get_genre(),b->get_desciption()
                       ,b->get_number_of_pages(),b->get_number_of_available_copies());
    book::books.clear();
    Database::load_books();
    Database::load_magazines();
    Database::load_newspaper();

    return true;
}

bool admin::remove_book(QString title) {
    Database::remove_book(title);
    return true; // placeholder
}

bool admin::add_magazine(magazine *m){
    Database::add_magazine(m->get_title(),m->get_author(),m->get_genre(),m->get_desciption()
                           ,m->get_number_of_pages(),m->get_number_of_available_copies(),m->get_price());
    book::books.clear();
    Database::load_books();
    Database::load_magazines();
    Database::load_newspaper();
    return true;
};
bool admin::remove_magazine(QString title){
    Database::remove_magazine(title);
    return true;
};
bool admin::add_newspaper(newspaper *n){
    Database::add_newspaper(n->get_title(),n->get_author(),n->get_genre(),n->get_desciption()
                            ,n->get_number_of_pages(),n->get_number_of_available_copies(),n->get_editor());
    book::books.clear();
    Database::load_books();
    Database::load_magazines();
    Database::load_newspaper();
    return true;
};
bool admin::remove_newspaper(QString title){
    Database::remove_newspaper(title);
    return true;
};
