#ifndef TABLE_BOOKS_H
#define TABLE_BOOKS_H

#include <QDialog>

namespace Ui {
class table_books;
}

class table_books : public QDialog
{
    Q_OBJECT

public:
    explicit table_books(QWidget *parent = nullptr);
    ~table_books();

private slots:
    void on_add_clicked();

    void on_remove_clicked();

    void on_borrow_clicked();

    void on_returm_clicked();


    void on_searchBar_textChanged(const QString &searchText);

private:
    Ui::table_books *ui;
};

#endif // TABLE_BOOKS_H
