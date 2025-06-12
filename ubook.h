#ifndef UBOOK_H
#define UBOOK_H
#include <QString>
class book {
protected:
    QString title;
    QString author;
    QString genre;
    QString description;
    int number_of_pages;
    int number_of_available_copies_in_library;
    int number_of_issued_copies;
    int number_of_returned_copies;
    int number_of_non_returned_copies;
    double rating;
    public:
    std::vector <QString>borrowers;
    //static data members
    public:
    static int books_counter;
    static std::vector<book*> books;
public:
        book (QString t="",QString au="",QString g="",QString d="",int nbp=0,int availbalbe=0);
        virtual ~book();
        //setters
        void set_title(QString t);
        void set_author(QString au);
        void set_genre (QString g);
        void set_description(QString d);
        void set_number_of_pages(int nbp);
        void set_number_of_available_copies(int available);
        void set_number_of_issued(int n);
        void set_number_of_returned(int n);
        void set_number_of_non_returned(int n);
        void set_rating(double r);
        QString get_title();
        QString get_author();
        QString get_genre();
        QString get_desciption();
        int get_number_of_pages();
        int get_number_of_available_copies();
        int get_number_of_issued_copies();
        int get_number_of_returned_copies();
        int get_number_of_non_returned_copies();
         double calculate_rating();
        static void sort();
         static int search_book(QString tit);



         //friend classes since admin can add and remove books,student can borrow and return books
        friend class admin;
         friend class student;


};

class magazine:public book{
private:
    double price;
public:
    static int magazine_counter;
public:
    magazine(QString t="",QString au="",QString g="",QString d="",int nbp=0,int availbalbe=0,double p=0);
    ~magazine();
    void set_price(double p);
    double get_price();

    //friend classes
    friend class admin;
    friend class student;


};
class newspaper :public book{

    QString editor;
public:
    static int newspaper_counter;
    newspaper(QString t="",QString au="",QString g="",QString d="",int nbp=0,int availbalbe=0,QString edit="");
    ~newspaper();
    void set_editor(QString edit);
    QString get_editor();


    //friend classes
    friend class admin;
    friend class student;
};

#endif // UBOOK_H
