#ifndef STUDENT_OPTIONS_H
#define STUDENT_OPTIONS_H

#include <QDialog>

namespace Ui {
class student_options;
}

class student_options : public QDialog
{
    Q_OBJECT

public:
    explicit student_options(QWidget *parent = nullptr);
    ~student_options();

private slots:
    void on_books_clicked();

    void on_magazines_clicked();

    void on_newspapers_clicked();

    void on_non_returned_clicked();

private:
    Ui::student_options *ui;
};

#endif // STUDENT_OPTIONS_H
