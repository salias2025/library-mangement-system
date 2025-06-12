#ifndef TABLE_STUDENTS_H
#define TABLE_STUDENTS_H

#include <QDialog>

namespace Ui {
class table_students;
}

class table_students : public QDialog
{
    Q_OBJECT

public:
    explicit table_students(QWidget *parent = nullptr);
    ~table_students();

private slots:
    void on_remove_student_clicked();
     void on_searchBar_textChanged(const QString &searchText);

private:
    Ui::table_students *ui;
};

#endif // TABLE_STUDENTS_H
