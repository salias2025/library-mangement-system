#include "ubook.h"
#include "QDebug"
int book::books_counter = 0;
int magazine::magazine_counter = 0;
int newspaper::newspaper_counter = 0;
std::vector<book*> book::books;

book::book (QString t,QString au,QString g,QString d,int nbp,int available){
    title=t;
    author=au;
    genre=g;
    description=d;
    number_of_pages=nbp;
    number_of_available_copies_in_library=available;
    rating=0;
    number_of_issued_copies=0;
    number_of_returned_copies=0;
    number_of_non_returned_copies=0;



};
book::~book() {}

//setters
void book::set_title(QString t){title=t;};
void book::set_author(QString au){author=au;};
void book::set_genre (QString g){genre=g;};
void book::set_description(QString d){description=d;};
void book::set_number_of_pages(int nbp){number_of_pages=nbp;};
void book::set_number_of_available_copies(int available){number_of_available_copies_in_library=available;};
void book::set_number_of_issued(int n){number_of_issued_copies=n;};
void book::set_number_of_returned(int n){number_of_returned_copies=n;};
void book::set_number_of_non_returned(int n){number_of_non_returned_copies=n;};
void book::set_rating(double r){rating=r;};
QString book::get_title(){return title;};
QString book::get_author(){return author;};
QString book::get_genre(){return genre;};
QString book::get_desciption(){return description;};
int book::get_number_of_pages(){return number_of_pages;};
int book::get_number_of_available_copies(){return number_of_available_copies_in_library;};
int book::get_number_of_issued_copies(){return number_of_issued_copies;};
int book::get_number_of_returned_copies(){return number_of_returned_copies;};
int book::get_number_of_non_returned_copies(){return number_of_non_returned_copies;};
double book::calculate_rating(){return rating;};
void book::sort(){
    std::sort(books.begin(), books.end(), [](book* a, book* b) {
        return a->get_title() < b->get_title();
    });
};
int book::search_book(QString tit){
    for (int i = 0; i < books_counter; ++i) {
        qDebug()<<"books at index "<<i<<"is"<<books[i]->get_title();
       if (books[i]->get_title().trimmed() == tit.trimmed()) {
            return i;  // found, return index
        }
    }
    return -1;  // not found

};

//we implement magazine

magazine::magazine(QString t,QString au,QString g,QString d,int nbp,int available,double p):
    book(t,au,g,d,nbp,available),price(p){

};
magazine::~magazine() {}

void magazine::set_price(double p){price=p;};
double magazine::get_price(){return price;};

newspaper::newspaper(QString t,QString au,QString g,QString d,int nbp,int available,QString edit):
    book(t,au,g,d,nbp,available),editor(edit) {};
newspaper::~newspaper() {}


void newspaper::set_editor(QString edit){editor=edit;};
QString newspaper::get_editor(){return editor;};







