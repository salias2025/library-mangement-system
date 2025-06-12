#ifndef RETURN_BOOK_H
#define RETURN_BOOK_H

#include <QDialog>

namespace Ui {
class return_book;
}

class return_book : public QDialog
{
    Q_OBJECT

public:
    explicit return_book(QWidget *parent = nullptr);
    ~return_book();
    void setTitle(const QString& title);


    void setUser(const QString& author);


private slots:
    void on_confirm_clicked();

private:
    Ui::return_book *ui;
};

#endif // RETURN_BOOK_H
