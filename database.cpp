#include "database.h"
#include "user.h"
#include "ubook.h"
//1-constructor
Database::Database()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mylibrary.db");

    if (!openConnection()) {
        qDebug() << "Failed to open database!";
    }
}


// 2-Destructor: Close the database connection
Database::~Database()
{
    closeConnection();
}
// 3-Open connection to the SQLite database
bool Database::openConnection()
{
    if (!db.open()) {
        qDebug() << "Error: Connection to database failed";
        return false;
    }
    return true;
}

// 4-Close the connection to the database
void Database::closeConnection()
{
    db.close();
}
//5-create students table
void Database::createStudentsTable()
{
    QSqlQuery query;

    // Create students table
    QString createStudentsTable = R"(
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            first_name TEXT,
            family_name TEXT,
            birthdate TEXT,
             student_id TEXT,
            username TEXT ,
            password TEXT,
            study_year INTEGER,
            borrowed_books_list TEXT, -- New column
             borrow_dates_list TEXT ,-- New column
             return_dates_list TEXT -- New column
        )
    )";

    if (!query.exec(createStudentsTable)) {
        qDebug() << "Error creating students table:" << query.lastError().text();
    }
}



//6-create admins table
void Database::createAdminsTable() {
    QSqlQuery query;

    // Create admins table
    QString createAdminsTable = R"(
        CREATE TABLE IF NOT EXISTS admins (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            first_name TEXT,
            family_name TEXT,
            birthdate TEXT,
            student_id TEXT,
            username TEXT,
            password TEXT

        )
    )";

    if (!query.exec(createAdminsTable)) {
        qDebug() << "Error creating Admins table:" << query.lastError().text();
    } else {
        qDebug() << "Admins table created or already exists.";
    }
}
//7-create books table

void Database::createBooksTable()
{
    QSqlQuery query;

    // Create books table
    QString createBooksTable = R"(
        CREATE TABLE IF NOT EXISTS books (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            title TEXT,
            author TEXT,
            genre TEXT,
            description TEXT,
            number_of_pages INTEGER,
            number_of_available_copies_in_library INTEGER,
            number_of_issued_copies INTEGER,
            number_of_returned_copies INTEGER,
            number_of_non_returned_copies INTEGER,
            rating REAL,
             borrowers TEXT -- Storing the list of borrowers as a semicolon-separated string
        )
    )";

    if (!query.exec(createBooksTable)) {
        qDebug() << "Error creating books table:" << query.lastError().text();
    } else {
        qDebug() << "Books table created or already exists.";
    }
}

//8-magazines table
void Database::createMagazinesTable()
{
    QSqlQuery query;

    // Create magazines table
    QString createMagazinesTable = R"(
        CREATE TABLE IF NOT EXISTS magazines (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            title TEXT,
            author TEXT,
            genre TEXT,
            description TEXT,
            number_of_pages INTEGER,
            number_of_available_copies_in_library INTEGER,
            number_of_issued_copies INTEGER,
            number_of_returned_copies INTEGER,
            number_of_non_returned_copies INTEGER,
            rating REAL,
            borrowers TEXT, -- List of borrowers as semicolon-separated string
            price REAL -- Additional field for magazine price
        )
    )";

    if (!query.exec(createMagazinesTable)) {
        qDebug() << "Error creating magazines table:" << query.lastError().text();
    } else {
        qDebug() << "Magazines table created or already exists.";
    }
}
//9-newsaper table
void Database::createNewspaperTable()
{
    QSqlQuery query;

    // Create newspapers table
    QString createNewspapersTable = R"(
        CREATE TABLE IF NOT EXISTS newspapers (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            title TEXT,
            author TEXT,
            genre TEXT,
            description TEXT,
            number_of_pages INTEGER,
            number_of_available_copies_in_library INTEGER,
            number_of_issued_copies INTEGER,
            number_of_returned_copies INTEGER,
            number_of_non_returned_copies INTEGER,
            rating REAL,
            borrowers TEXT, -- Storing the list of borrowers as a semicolon-separated string
            editor TEXT -- Additional field for newspaper editor
        )
    )";

    if (!query.exec(createNewspapersTable)) {
        qDebug() << "Error creating newspapers table:" << query.lastError().text();
    } else {
        qDebug() << "Newspapers table created or already exists.";
    }
}
//10-add student to database


bool Database::addStudent(const QString &first_name, const QString &family_name, const QDate &birthdate,
                          const QString &student_id, const QString &username, const QString &password, int study_year)
{
    QSqlQuery query;

    // Start a transaction
    if (!query.exec("BEGIN TRANSACTION")) {
        qDebug() << "Failed to start transaction:" << query.lastError().text();
        return false;
    }

    // Prepare the INSERT statement with positional placeholders
    query.prepare(R"(
        INSERT INTO users (
            first_name, family_name, birthdate, student_id, username, password, study_year
        ) VALUES (?, ?, ?, ?, ?, ?, ?)
    )");

    // Bind values in the same order as placeholders
    query.addBindValue(first_name);
    query.addBindValue(family_name);
    query.addBindValue(birthdate.toString("yyyy-MM-dd"));  // Convert QDate to string for SQLite
    query.addBindValue(student_id);
    query.addBindValue(username);
    query.addBindValue(password);
    query.addBindValue(study_year);

    // Execute the insert query
    if (!query.exec()) {
        qDebug() << "Error inserting new student:" << query.lastError().text();
        query.exec("ROLLBACK");
        return false;
    }

    // Commit the transaction
    if (!query.exec("COMMIT")) {
        qDebug() << "Failed to commit transaction:" << query.lastError().text();
        return false;
    }

    return true;
}
//11-add admin to databse
bool Database::addAdmin(const QString &first_name, const QString &family_name, const QDate &birthdate,
                        const QString &student_id, const QString &username,
                        const QString &password)
{
    QSqlQuery query;

    if (!query.exec("BEGIN TRANSACTION")) {
        qDebug() << "Failed to start transaction:" << query.lastError().text();
        return false;
    }

    query.prepare(R"(
        INSERT INTO admins (
            first_name, family_name, birthdate, student_id, username, password
        ) VALUES (?, ?, ?, ?, ?, ?)
    )");

    query.addBindValue(first_name);
    query.addBindValue(family_name);
    query.addBindValue(birthdate.toString("yyyy-MM-dd"));
    query.addBindValue(student_id);
    query.addBindValue(username);
    query.addBindValue(password);

    if (!query.exec()) {
        qDebug() << "Error inserting new admin:" << query.lastError().text();
        query.exec("ROLLBACK");
        return false;
    }

    if (!query.exec("COMMIT")) {
        qDebug() << "Failed to commit transaction:" << query.lastError().text();
        return false;
    }

    return true;
}


//12-add book to database

bool Database::add_book(const QString &title, const QString &author, const QString &genre, const QString &description,
                        const int &num_of_pages, const int &copies)
{
    QSqlQuery query;

    query.prepare(R"(
        INSERT INTO books (
            title,
            author,
            genre,
            description,
            number_of_pages,
            number_of_available_copies_in_library,
            number_of_issued_copies,
            number_of_returned_copies,
            number_of_non_returned_copies,
            rating,
            borrowers
        ) VALUES (
            :title,
            :author,
            :genre,
            :description,
            :number_of_pages,
            :available,
            0, 0, 0, 0.0, ''
        )
    )");

    query.bindValue(":title", title);
    query.bindValue(":author", author);
    query.bindValue(":genre", genre);
    query.bindValue(":description", description);
    query.bindValue(":number_of_pages", num_of_pages);
    query.bindValue(":available", copies);

    if (!query.exec()) {
        qDebug() << "Error inserting book:" << query.lastError().text();
        return false;
    } else {
        qDebug() << "Book added successfully.";
        return true;
    }
}
//13-add magazine to database
bool Database::add_magazine(const QString &title ,const QString &author,const QString &genre ,const QString &description,
                            const int &num_of_pages , const int & copies,const double &price)
{
    QSqlQuery query;

    query.prepare(R"(
        INSERT INTO magazines (
            title,
            author,
            genre,
            description,
            number_of_pages,
            number_of_available_copies_in_library,
            number_of_issued_copies,
            number_of_returned_copies,
            number_of_non_returned_copies,
            rating,
            borrowers,
            price
        ) VALUES (
            :title,
            :author,
            :genre,
            :description,
            :number_of_pages,
            :available,
            0, 0, 0, 0.0, '', :price
        )
    )");

    query.bindValue(":title", title);
    query.bindValue(":author", author);
    query.bindValue(":genre", genre);
    query.bindValue(":description", description);
    query.bindValue(":number_of_pages", num_of_pages);
    query.bindValue(":available", copies);
    query.bindValue(":price", price);

    if (!query.exec()) {
        qDebug() << "Error inserting magazine:" << query.lastError().text();
        return false;
    } else {
        qDebug() << "Magazine added successfully.";
        return true;
    }
}
//14-add newspaper to database
bool Database::add_newspaper(const QString &title ,const QString &author,const QString &genre ,const QString &description,
                             const int &num_of_pages , const int & copies,const QString &editor)
{
    QSqlQuery query;

    query.prepare(R"(
        INSERT INTO newspapers (
            title,
            author,
            genre,
            description,
            number_of_pages,
            number_of_available_copies_in_library,
            number_of_issued_copies,
            number_of_returned_copies,
            number_of_non_returned_copies,
            rating,
            borrowers,
            editor
        ) VALUES (
            :title,
            :author,
            :genre,
            :description,
            :number_of_pages,
            :available,
            0, 0, 0, 0.0, '', :editor
        )
    )");

    query.bindValue(":title", title);
    query.bindValue(":author", author);
    query.bindValue(":genre", genre);
    query.bindValue(":description", description);
    query.bindValue(":number_of_pages", num_of_pages);
    query.bindValue(":available", copies);
    query.bindValue(":editor", editor);

    if (!query.exec()) {
        qDebug() << "Error inserting newspaper:" << query.lastError().text();
        return false;
    } else {
        qDebug() << "Newspaper added successfully.";
        return true;
    }
}


//15-load students

void Database::loadStudents()
{
    qDebug() << "Start loading students...";

    // Reset counters and clear previous users to avoid duplication

    user::users_counter = 0;
     student::students_counter = 0;
    QSqlQuery query;
    if (!query.exec("SELECT * FROM users")) {
        qDebug() << "Error executing query to load students: " << query.lastError().text();
        return;
    }

    while (query.next()) {
        QString first_name = query.value("first_name").toString();
        QString family_name = query.value("family_name").toString();
        QString birthdateStr = query.value("birthdate").toString();
        QDate birthdate = QDate::fromString(birthdateStr, "yyyy-MM-dd");
        QString user_id = query.value("student_id").toString();
        QString username = query.value("username").toString();
        QString password = query.value("password").toString();
        int study_year = query.value("study_year").toInt();

        QString borrowed_books_str = query.value("borrowed_books_list").toString();
        QString borrow_dates_str = query.value("borrow_dates_list").toString();
        QString return_dates_str = query.value("return_dates_list").toString();

        student* newStudent = new student(first_name, family_name, birthdate, user_id, username, password, study_year);

        // Parse borrowed books list
        QStringList borrowedBooksList = borrowed_books_str.split(";", Qt::SkipEmptyParts);
        for (const QString& book : borrowedBooksList) {
            newStudent->borrowed_books_list.push_back(book);
        }

        // Parse borrow dates
        QStringList borrowDatesList = borrow_dates_str.split(";", Qt::SkipEmptyParts);
        for (const QString& dateStr : borrowDatesList) {
            QDate d = QDate::fromString(dateStr, Qt::ISODate);
            newStudent->borrow_dates.push_back(d.isValid() ? d : QDate());
        }

        // Parse return dates
        QStringList returnDatesList = return_dates_str.split(";", Qt::SkipEmptyParts);
        for (const QString& dateStr : returnDatesList) {
            QDate d = QDate::fromString(dateStr, Qt::ISODate);
            newStudent->return_dates.push_back(d.isValid() ? d : QDate());
        }

        user::users.push_back(newStudent);
        user::users_counter++;
        student::students_counter++;

        qDebug() << "Loaded student:" << username;
    }

    qDebug() << "Total students loaded: " << student::students_counter;
}


//16-load admins
void Database::loadAdmins()
{
    qDebug() << "Start loading admins...";

    admin::admins_counter = 0;

    QSqlQuery query;
    if (!query.exec("SELECT * FROM admins")) {
        qDebug() << "Error executing query to load admins: " << query.lastError().text();
        return;
    }

    while (query.next()) {
        QString first_name = query.value("first_name").toString();
        QString family_name = query.value("family_name").toString();
        QString birthdateStr = query.value("birthdate").toString();
        QDate birthdate = QDate::fromString(birthdateStr, "yyyy-MM-dd");
        QString user_id = query.value("student_id").toString();  // or "admin_id" if correct
        QString username = query.value("username").toString();
        QString password = query.value("password").toString();

        admin* newAdmin = new admin(first_name, family_name, birthdate, user_id, username, password);

        user::users.push_back(newAdmin);
        admin::admins_counter++;
        user::users_counter++;

        qDebug() << "Loaded admin:" << username;
    }

    qDebug() << "Total admins loaded: " << admin::admins_counter;
}


//17-load books
void Database::load_books()
{
    qDebug() << "Start loading books...";

    QSqlQuery query;
    if (!query.exec("SELECT * FROM books")) {
        qDebug() << "Error executing query to load books: " << query.lastError().text();
        return;
    }

    book::books_counter = 0;

    while (query.next()) {
        QString title = query.value("title").toString();
        QString author = query.value("author").toString();
        QString genre = query.value("genre").toString();
        QString description = query.value("description").toString();
        int pages = query.value("number_of_pages").toInt();
        int available = query.value("number_of_available_copies_in_library").toInt();
        int issued = query.value("number_of_issued_copies").toInt();
        int returned = query.value("number_of_returned_copies").toInt();
        int not_returned = query.value("number_of_non_returned_copies").toInt();
        double rating = query.value("rating").toDouble();

        QString borrowersStr = query.value("borrowers").toString();
        QStringList borrowersList = borrowersStr.split(";", Qt::SkipEmptyParts);
        std::vector<QString> borrowers;
        for (const QString& b : borrowersList) {
            borrowers.push_back(b);
        }

        book* newBook = new book(title, author, genre, description, pages, available);
        newBook->set_number_of_issued(issued);
        newBook->set_number_of_returned(returned);
        newBook->set_number_of_non_returned( not_returned);
        newBook->set_rating(rating);
        newBook->borrowers=borrowers;

        book::books.push_back(newBook);
        book::books_counter++;

        qDebug() << "Loaded book:" << title;
    }

    qDebug() << "Total books loaded:" << book::books_counter;
}


// 18 - Load Magazines (Storing as Book for Polymorphism)
void Database::load_magazines()
{
    qDebug() << "Start loading magazines...";

    QSqlQuery query;
    if (!query.exec("SELECT * FROM magazines")) { // Adjust table name if needed
        qDebug() << "Error executing query to load magazines: " << query.lastError().text();
        return;
    }

    magazine::magazine_counter = 0;

    while (query.next()) {
        QString title = query.value("title").toString();
        QString author = query.value("author").toString();
        QString genre = query.value("genre").toString();
        QString description = query.value("description").toString();
        int pages = query.value("number_of_pages").toInt();
        int available = query.value("number_of_available_copies_in_library").toInt();
        int issued = query.value("number_of_issued_copies").toInt();
        int returned = query.value("number_of_returned_copies").toInt();
        int not_returned = query.value("number_of_non_returned_copies").toInt();
        double rating = query.value("rating").toDouble();
        double price = query.value("price").toDouble(); // Magazine-specific field

        QString borrowersStr = query.value("borrowers").toString();
        QStringList borrowersList = borrowersStr.split(";", Qt::SkipEmptyParts);
        std::vector<QString> borrowers;
        for (const QString& b : borrowersList) {
            borrowers.push_back(b);
        }

        // Create a Magazine object (polymorphically a Book)
        magazine* newMagazine = new magazine(title, author, genre, description, pages, available, price);
        newMagazine->set_number_of_issued(issued);
        newMagazine->set_number_of_returned(returned);
        newMagazine->set_number_of_non_returned(not_returned);
        newMagazine->set_rating(rating);

        // Magazines have a unique set of data (borrowers are already handled)
        newMagazine->borrowers = borrowers;  // Directly setting the borrowers vector

        // Store in the 'books' vector as a Book, but it will be a Magazine object
        book::books.push_back(newMagazine);  // Polymorphism in action here

        magazine::magazine_counter++;
        book::books_counter++;  // Incrementing the books counter as well

        qDebug() << "Loaded magazine:" << title;
    }

    qDebug() << "Total magazines loaded:" << magazine::magazine_counter;
}
//19-loading nespaper from database
// 19 - Load Newspapers (Storing as Book for Polymorphism)
void Database::load_newspaper()
{
    qDebug() << "Start loading newspapers...";

    QSqlQuery query;
    if (!query.exec("SELECT * FROM newspapers")) { // Adjust table name if needed
        qDebug() << "Error executing query to load newspapers: " << query.lastError().text();
        return;
    }

    newspaper::newspaper_counter = 0;

    while (query.next()) {
        QString title = query.value("title").toString();
        QString author = query.value("author").toString();
        QString genre = query.value("genre").toString();
        QString description = query.value("description").toString();
        int pages = query.value("number_of_pages").toInt();
        int available = query.value("number_of_available_copies_in_library").toInt();
        int issued = query.value("number_of_issued_copies").toInt();
        int returned = query.value("number_of_returned_copies").toInt();
        int not_returned = query.value("number_of_non_returned_copies").toInt();
        double rating = query.value("rating").toDouble();
        QString editor = query.value("editor").toString(); // Newspaper-specific field

        QString borrowersStr = query.value("borrowers").toString();
        QStringList borrowersList = borrowersStr.split(";", Qt::SkipEmptyParts);
        std::vector<QString> borrowers;
        for (const QString& b : borrowersList) {
            borrowers.push_back(b);
        }

        // Create a Newspaper object (polymorphically a Book)
        newspaper* newNewspaper = new newspaper(title, author, genre, description, pages, available, editor);
        newNewspaper->set_number_of_issued(issued);
        newNewspaper->set_number_of_returned(returned);
        newNewspaper->set_number_of_non_returned(not_returned);
        newNewspaper->set_rating(rating);

        // Newspapers have a unique set of data (borrowers are already handled)
        newNewspaper->borrowers = borrowers;  // Directly setting the borrowers vector

        // Store in the 'books' vector as a Book, but it will be a Newspaper object
        book::books.push_back(newNewspaper);  // Polymorphism in action here

        newspaper::newspaper_counter++;
        book::books_counter++;  // Incrementing the books counter as well

        qDebug() << "Loaded newspaper:" << title;
    }

    qDebug() << "Total newspapers loaded:" << newspaper::newspaper_counter;
}
//20-remove user
bool Database::removeStudent(const QString &username){
    QSqlQuery query;
    query.prepare(R"(
        DELETE FROM users
        WHERE username = :username AND student_id IS NOT NULL AND study_year IS NOT NULL
    )");
    query.bindValue(":username", username);

    if (!query.exec()) {
        qDebug() << "Database error while deleting student:" << query.lastError().text();
        return false;
    }

    if (query.numRowsAffected() == 0) {
        qDebug() << "No student with username" << username << "found.";
        return false;
    }

    qDebug() << "Student with username" << username << "successfully deleted.";
    return true;
}
//21-remove admin
bool Database::removeAdmin(const QString &username) {
    QSqlQuery query;
    query.prepare("DELETE FROM admins WHERE username = :username");
    query.bindValue(":username", username);

    if (!query.exec()) {
        qDebug() << "Database error while deleting admin:" << query.lastError().text();
        return false;
    }

    if (query.numRowsAffected() == 0) {
        qDebug() << "No admin with username" << username << "found.";
        return false;
    }

    qDebug() << "Admin with username" << username << "successfully deleted.";
    return true;
}
//22-remove book from database
bool Database::remove_book(const QString &title) {
    QSqlQuery query;
    query.prepare("DELETE FROM books WHERE title = :title");
    query.bindValue(":title", title);

    if (!query.exec()) {
        qDebug() << "Database error while deleting book:" << query.lastError().text();
        return false;
    }

    if (query.numRowsAffected() == 0) {
        qDebug() << "No book with title" << title << "found.";
        return false;
    }

    qDebug() << "Book with title" << title << "successfully deleted.";
    return true;
}
//23-remove magazine
bool Database::remove_magazine(const QString &title) {
    QSqlQuery query;
    query.prepare("DELETE FROM magazines WHERE title = :title");
    query.bindValue(":title", title);

    if (!query.exec()) {
        qDebug() << "Database error while deleting magazine:" << query.lastError().text();
        return false;
    }

    if (query.numRowsAffected() == 0) {
        qDebug() << "No magazine with title" << title << "found.";
        return false;
    }

    qDebug() << "Magazine with title" << title << "successfully deleted.";
    return true;
}
//34-remove newspaper
bool Database::remove_newspaper(const QString &title) {
    QSqlQuery query;
    query.prepare("DELETE FROM newspapers WHERE title = :title");
    query.bindValue(":title", title);

    if (!query.exec()) {
        qDebug() << "Database error while deleting newspaper:" << query.lastError().text();
        return false;
    }

    if (query.numRowsAffected() == 0) {
        qDebug() << "No newspaper with title" << title << "found.";
        return false;
    }

    qDebug() << "Newspaper with title" << title << "successfully deleted.";
    return true;
}



//23-borrow book
bool Database::borrowBook(const QString &title, const QString &borrowDate, const QString &returnDate, const QString &username)
{
    QSqlQuery query;

    // === 1. Update USERS table ===
    query.prepare("SELECT borrowed_books_list, borrow_dates_list, return_dates_list FROM users WHERE username = ?");
    query.addBindValue(username);

    if (!query.exec() || !query.next()) {
        qDebug() << "Failed to retrieve user data:" << query.lastError().text();
        return false;
    }

    QString booksList = query.value(0).toString();
    QString borrowDatesList = query.value(1).toString();
    QString returnDatesList = query.value(2).toString();

    if (!booksList.isEmpty()) booksList += ";";
    booksList += title;

    if (!borrowDatesList.isEmpty()) borrowDatesList += ";";
    borrowDatesList += borrowDate;

    if (!returnDatesList.isEmpty()) returnDatesList += ";";
    returnDatesList += returnDate;

    query.prepare(R"(
        UPDATE users SET
            borrowed_books_list = ?,
            borrow_dates_list = ?,
            return_dates_list = ?
        WHERE username = ?
    )");
    query.addBindValue(booksList);
    query.addBindValue(borrowDatesList);
    query.addBindValue(returnDatesList);
    query.addBindValue(username);

    if (!query.exec()) {
        qDebug() << "Failed to update user data:" << query.lastError().text();
        return false;
    }

    // === 2. Update BOOKS table ===
    query.prepare("SELECT borrowers, number_of_issued_copies, number_of_non_returned_copies FROM books WHERE title = ?");
    query.addBindValue(title);

    if (!query.exec() || !query.next()) {
        qDebug() << "Failed to retrieve book data:" << query.lastError().text();
        return false;
    }

    QString borrowers = query.value(0).toString();
    int issued = query.value(1).toInt();
    int nonReturned = query.value(2).toInt();

    if (!borrowers.isEmpty()) borrowers += ";";
    borrowers += username;

    issued++;
    nonReturned++;
    int returned = issued - nonReturned;

    query.prepare(R"(
        UPDATE books SET
            borrowers = ?,
            number_of_issued_copies = ?,
            number_of_non_returned_copies = ?,
            number_of_returned_copies = ?
        WHERE title = ?
    )");
    query.addBindValue(borrowers);
    query.addBindValue(issued);
    query.addBindValue(nonReturned);
    query.addBindValue(returned);
    query.addBindValue(title);

    if (!query.exec()) {
        qDebug() << "Failed to update book data:" << query.lastError().text();
        return false;
    }

    return true;
}
//24-borrow magazine
bool Database::borrowMagazine(const QString &title, const QString &borrowDate, const QString &returnDate, const QString &username)
{
    QSqlQuery query;

    // === 1. Update USERS table ===
    query.prepare("SELECT borrowed_books_list, borrow_dates_list, return_dates_list FROM users WHERE username = ?");
    query.addBindValue(username);

    if (!query.exec() || !query.next()) {
        qDebug() << "Failed to retrieve user data:" << query.lastError().text();
        return false;
    }

    QString booksList = query.value(0).toString();
    QString borrowDatesList = query.value(1).toString();
    QString returnDatesList = query.value(2).toString();

    if (!booksList.isEmpty()) booksList += ";";
    booksList += title;

    if (!borrowDatesList.isEmpty()) borrowDatesList += ";";
    borrowDatesList += borrowDate;

    if (!returnDatesList.isEmpty()) returnDatesList += ";";
    returnDatesList += returnDate;

    query.prepare(R"(
        UPDATE users SET
            borrowed_books_list = ?,
            borrow_dates_list = ?,
            return_dates_list = ?
        WHERE username = ?
    )");
    query.addBindValue(booksList);
    query.addBindValue(borrowDatesList);
    query.addBindValue(returnDatesList);
    query.addBindValue(username);

    if (!query.exec()) {
        qDebug() << "Failed to update user data for magazine:" << query.lastError().text();
        return false;
    }

    // === 2. Update MAGAZINES table ===
    query.prepare("SELECT borrowers, number_of_issued_copies, number_of_non_returned_copies FROM magazines WHERE title = ?");
    query.addBindValue(title);

    if (!query.exec() || !query.next()) {
        qDebug() << "Failed to retrieve magazine data:" << query.lastError().text();
        return false;
    }

    QString borrowers = query.value(0).toString();
    int issued = query.value(1).toInt();
    int nonReturned = query.value(2).toInt();

    if (!borrowers.isEmpty()) borrowers += ";";
    borrowers += username;

    issued++;
    nonReturned++;
    int returned = issued - nonReturned;

    query.prepare(R"(
        UPDATE magazines SET
            borrowers = ?,
            number_of_issued_copies = ?,
            number_of_non_returned_copies = ?,
            number_of_returned_copies = ?
        WHERE title = ?
    )");
    query.addBindValue(borrowers);
    query.addBindValue(issued);
    query.addBindValue(nonReturned);
    query.addBindValue(returned);
    query.addBindValue(title);

    if (!query.exec()) {
        qDebug() << "Failed to update magazine data:" << query.lastError().text();
        return false;
    }

    return true;
}
//25-borrow newspaper
bool Database::borrowNewspaper(const QString &title, const QString &borrowDate, const QString &returnDate, const QString &username)
{
    QSqlQuery query;

    // === 1. Update USERS table ===
    query.prepare("SELECT borrowed_books_list, borrow_dates_list, return_dates_list FROM users WHERE username = ?");
    query.addBindValue(username);

    if (!query.exec() || !query.next()) {
        qDebug() << "Failed to retrieve user data:" << query.lastError().text();
        return false;
    }

    QString booksList = query.value(0).toString();
    QString borrowDatesList = query.value(1).toString();
    QString returnDatesList = query.value(2).toString();

    if (!booksList.isEmpty()) booksList += ";";
    booksList += title;

    if (!borrowDatesList.isEmpty()) borrowDatesList += ";";
    borrowDatesList += borrowDate;

    if (!returnDatesList.isEmpty()) returnDatesList += ";";
    returnDatesList += returnDate;

    query.prepare(R"(
        UPDATE users SET
            borrowed_books_list = ?,
            borrow_dates_list = ?,
            return_dates_list = ?
        WHERE username = ?
    )");
    query.addBindValue(booksList);
    query.addBindValue(borrowDatesList);
    query.addBindValue(returnDatesList);
    query.addBindValue(username);

    if (!query.exec()) {
        qDebug() << "Failed to update user data for newspaper:" << query.lastError().text();
        return false;
    }

    // === 2. Update NEWSPAPERS table ===
    query.prepare("SELECT borrowers, number_of_issued_copies, number_of_non_returned_copies FROM newspapers WHERE title = ?");
    query.addBindValue(title);

    if (!query.exec() || !query.next()) {
        qDebug() << "Failed to retrieve newspaper data:" << query.lastError().text();
        return false;
    }

    QString borrowers = query.value(0).toString();
    int issued = query.value(1).toInt();
    int nonReturned = query.value(2).toInt();

    if (!borrowers.isEmpty()) borrowers += ";";
    borrowers += username;

    issued++;
    nonReturned++;
    int returned = issued - nonReturned;

    query.prepare(R"(
        UPDATE newspapers SET
            borrowers = ?,
            number_of_issued_copies = ?,
            number_of_non_returned_copies = ?,
            number_of_returned_copies = ?
        WHERE title = ?
    )");
    query.addBindValue(borrowers);
    query.addBindValue(issued);
    query.addBindValue(nonReturned);
    query.addBindValue(returned);
    query.addBindValue(title);

    if (!query.exec()) {
        qDebug() << "Failed to update newspaper data:" << query.lastError().text();
        return false;
    }

    return true;
}
//26-return book
bool Database::returnBook(const QString &title, const QString &rating, const QString &username) {
    QSqlQuery query;

    // === 1. Retrieve user data ===
    query.prepare("SELECT borrowed_books_list, borrow_dates_list, return_dates_list FROM users WHERE username = ?");
    query.addBindValue(username);

    if (!query.exec() || !query.next()) {
        qDebug() << "Failed to retrieve user data:" << query.lastError().text();
        return false;
    }

    QString booksList = query.value(0).toString();
    QString borrowDatesList = query.value(1).toString();
    QString returnDatesList = query.value(2).toString();

    qDebug() << "User's borrowed books: " << booksList;

    // Remove the book from the user's borrowed books
    QStringList books = booksList.split(";", Qt::SkipEmptyParts);
    QStringList borrowDates = borrowDatesList.split(";", Qt::SkipEmptyParts);
    QStringList returnDates = returnDatesList.split(";", Qt::SkipEmptyParts);

    qDebug() << "Books list after split: " << books;

    int bookIndex = books.indexOf(title);
    if (bookIndex == -1) {
        qDebug() << "Book not found in borrowed list!";
        return false;
    }

    // Remove the book and its corresponding dates
    books.removeAt(bookIndex);
    borrowDates.removeAt(bookIndex);
    returnDates.removeAt(bookIndex);

    // Update user's borrowed books list
    booksList = books.join(";");
    borrowDatesList = borrowDates.join(";");
    returnDatesList = returnDates.join(";");

    query.prepare(R"(
        UPDATE users SET
            borrowed_books_list = ?,
            borrow_dates_list = ?,
            return_dates_list = ?
        WHERE username = ?
    )");
    query.addBindValue(booksList);
    query.addBindValue(borrowDatesList);
    query.addBindValue(returnDatesList);
    query.addBindValue(username);

    if (!query.exec()) {
        qDebug() << "Failed to update user data:" << query.lastError().text();
        return false;
    }

    // === 2. Retrieve book data ===
    query.prepare("SELECT borrowers, number_of_issued_copies, number_of_non_returned_copies, rating FROM books WHERE title = ?");
    query.addBindValue(title);

    if (!query.exec() || !query.next()) {
        qDebug() << "Failed to retrieve book data:" << query.lastError().text();
        return false;
    }

    QString borrowers = query.value(0).toString();
    int issued = query.value(1).toInt();
    int nonReturned = query.value(2).toInt();
    double currentRating = query.value(3).toDouble();

    qDebug() << "Book borrowers: " << borrowers;

    // Remove the user from the book's borrowers list
    QStringList borrowerList = borrowers.split(";", Qt::SkipEmptyParts);
    borrowerList.removeAll(username);
    borrowers = borrowerList.join(";");

    // Update book stats
    issued--;
    nonReturned--;
    int returned = issued - nonReturned;

    // Update the book rating
    double newRating = rating.toDouble();
    if (currentRating == 0) {
        currentRating = newRating;
    } else {
        currentRating = (currentRating + newRating) / 2.0;
    }

    // Update the book record in the database
    query.prepare(R"(
        UPDATE books SET
            borrowers = ?,
            number_of_issued_copies = ?,
            number_of_non_returned_copies = ?,
            number_of_returned_copies = ?,
            rating = ?
        WHERE title = ?
    )");
    query.addBindValue(borrowers);
    query.addBindValue(issued);
    query.addBindValue(nonReturned);
    query.addBindValue(returned);
    query.addBindValue(currentRating);
    query.addBindValue(title);

    if (!query.exec()) {
        qDebug() << "Failed to update book data:" << query.lastError().text();
        return false;
    }

    return true;
}

bool Database::returnMagazine(const QString &title, const QString &rating, const QString &username) {
    QSqlQuery query;

    // === 1. Retrieve user data ===
    query.prepare("SELECT borrowed_books_list, borrow_dates_list, return_dates_list FROM users WHERE username = ?");
    query.addBindValue(username);

    if (!query.exec() || !query.next()) {
        qDebug() << "Failed to retrieve user data:" << query.lastError().text();
        return false;
    }

    QString booksList = query.value(0).toString();
    QString borrowDatesList = query.value(1).toString();
    QString returnDatesList = query.value(2).toString();

    QStringList books = booksList.split(";", Qt::SkipEmptyParts);
    QStringList borrowDates = borrowDatesList.split(";", Qt::SkipEmptyParts);
    QStringList returnDates = returnDatesList.split(";", Qt::SkipEmptyParts);

    int bookIndex = books.indexOf(title);
    if (bookIndex == -1) {
        qDebug() << "Magazine not found in user's borrowed list.";
        return false;
    }

    books.removeAt(bookIndex);
    borrowDates.removeAt(bookIndex);
    returnDates.removeAt(bookIndex);

    booksList = books.join(";");
    borrowDatesList = borrowDates.join(";");
    returnDatesList = returnDates.join(";");

    query.prepare(R"(
        UPDATE users SET
            borrowed_books_list = ?,
            borrow_dates_list = ?,
            return_dates_list = ?
        WHERE username = ?
    )");
    query.addBindValue(booksList);
    query.addBindValue(borrowDatesList);
    query.addBindValue(returnDatesList);
    query.addBindValue(username);

    if (!query.exec()) {
        qDebug() << "Failed to update user data for magazine return:" << query.lastError().text();
        return false;
    }

    // === 2. Retrieve magazine data ===
    query.prepare("SELECT borrowers, number_of_issued_copies, number_of_non_returned_copies, rating FROM magazines WHERE title = ?");
    query.addBindValue(title);

    if (!query.exec() || !query.next()) {
        qDebug() << "Failed to retrieve magazine data:" << query.lastError().text();
        return false;
    }

    QString borrowers = query.value(0).toString();
    int issued = query.value(1).toInt();
    int nonReturned = query.value(2).toInt();
    double currentRating = query.value(3).toDouble();

    QStringList borrowerList = borrowers.split(";", Qt::SkipEmptyParts);
    borrowerList.removeAll(username);
    borrowers = borrowerList.join(";");

    issued--;
    nonReturned--;
    int returned = issued - nonReturned;

    double newRating = rating.toDouble();
    if (currentRating == 0) {
        currentRating = newRating;
    } else {
        currentRating = (currentRating + newRating) / 2.0;
    }

    query.prepare(R"(
        UPDATE magazines SET
            borrowers = ?,
            number_of_issued_copies = ?,
            number_of_non_returned_copies = ?,
            number_of_returned_copies = ?,
            rating = ?
        WHERE title = ?
    )");
    query.addBindValue(borrowers);
    query.addBindValue(issued);
    query.addBindValue(nonReturned);
    query.addBindValue(returned);
    query.addBindValue(currentRating);
    query.addBindValue(title);

    if (!query.exec()) {
        qDebug() << "Failed to update magazine data:" << query.lastError().text();
        return false;
    }

    return true;
}

bool Database::returnNewspaper(const QString &title, const QString &rating, const QString &username) {
    QSqlQuery query;

    query.prepare("SELECT borrowed_books_list, borrow_dates_list, return_dates_list FROM users WHERE username = ?");
    query.addBindValue(username);

    if (!query.exec() || !query.next()) {
        qDebug() << "Failed to retrieve user data:" << query.lastError().text();
        return false;
    }

    QString booksList = query.value(0).toString();
    QString borrowDatesList = query.value(1).toString();
    QString returnDatesList = query.value(2).toString();

    QStringList books = booksList.split(";", Qt::SkipEmptyParts);
    QStringList borrowDates = borrowDatesList.split(";", Qt::SkipEmptyParts);
    QStringList returnDates = returnDatesList.split(";", Qt::SkipEmptyParts);

    int bookIndex = books.indexOf(title);
    if (bookIndex == -1) {
        qDebug() << "Newspaper not found in user's borrowed list.";
        return false;
    }

    books.removeAt(bookIndex);
    borrowDates.removeAt(bookIndex);
    returnDates.removeAt(bookIndex);

    booksList = books.join(";");
    borrowDatesList = borrowDates.join(";");
    returnDatesList = returnDates.join(";");

    query.prepare(R"(
        UPDATE users SET
            borrowed_books_list = ?,
            borrow_dates_list = ?,
            return_dates_list = ?
        WHERE username = ?
    )");
    query.addBindValue(booksList);
    query.addBindValue(borrowDatesList);
    query.addBindValue(returnDatesList);
    query.addBindValue(username);

    if (!query.exec()) {
        qDebug() << "Failed to update user data for newspaper return:" << query.lastError().text();
        return false;
    }

    query.prepare("SELECT borrowers, number_of_issued_copies, number_of_non_returned_copies, rating FROM newspapers WHERE title = ?");
    query.addBindValue(title);

    if (!query.exec() || !query.next()) {
        qDebug() << "Failed to retrieve newspaper data:" << query.lastError().text();
        return false;
    }

    QString borrowers = query.value(0).toString();
    int issued = query.value(1).toInt();
    int nonReturned = query.value(2).toInt();
    double currentRating = query.value(3).toDouble();

    QStringList borrowerList = borrowers.split(";", Qt::SkipEmptyParts);
    borrowerList.removeAll(username);
    borrowers = borrowerList.join(";");

    issued--;
    nonReturned--;
    int returned = issued - nonReturned;

    double newRating = rating.toDouble();
    if (currentRating == 0) {
        currentRating = newRating;
    } else {
        currentRating = (currentRating + newRating) / 2.0;
    }

    query.prepare(R"(
        UPDATE newspapers SET
            borrowers = ?,
            number_of_issued_copies = ?,
            number_of_non_returned_copies = ?,
            number_of_returned_copies = ?,
            rating = ?
        WHERE title = ?
    )");
    query.addBindValue(borrowers);
    query.addBindValue(issued);
    query.addBindValue(nonReturned);
    query.addBindValue(returned);
    query.addBindValue(currentRating);
    query.addBindValue(title);

    if (!query.exec()) {
        qDebug() << "Failed to update newspaper data:" << query.lastError().text();
        return false;
    }

    return true;
}
