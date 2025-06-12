#ifndef TABLE_MAGAZINES_H
#define TABLE_MAGAZINES_H

#include <QDialog>

namespace Ui {
class table_magazines;
}

class table_magazines : public QDialog
{
    Q_OBJECT

public:
    explicit table_magazines(QWidget *parent = nullptr);
    ~table_magazines();

private slots:
    void on_add_clicked();

    void on_remove_clicked();

    void on_borrow_clicked();

    void on_returm_clicked();

     void on_searchBar_textChanged(const QString &searchText);

private:
    Ui::table_magazines *ui;
};

#endif // TABLE_MAGAZINES_H
