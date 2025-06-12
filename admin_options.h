#ifndef ADMIN_OPTIONS_H
#define ADMIN_OPTIONS_H

#include <QDialog>

namespace Ui {
class admin_options;
}

class admin_options : public QDialog
{
    Q_OBJECT

public:
    explicit admin_options(QWidget *parent = nullptr);
    ~admin_options();

private slots:
    void on_books_clicked();

    void on_magazines_clicked();

    void on_newspapers_clicked();

    void on_students_clicked();

    void on_admins_clicked();

    void on_issued_clicked();

    void on_non_returned_clicked();

private:
    Ui::admin_options *ui;
};

#endif // ADMIN_OPTIONS_H
