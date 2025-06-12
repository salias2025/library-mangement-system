#ifndef TABLE_NEWSPAPER_H
#define TABLE_NEWSPAPER_H

#include <QDialog>

namespace Ui {
class table_newspaper;
}

class table_newspaper : public QDialog
{
    Q_OBJECT

public:
    explicit table_newspaper(QWidget *parent = nullptr);
    ~table_newspaper();

private slots:
    void on_add_clicked();

    void on_remove_clicked();

    void on_returm_clicked();

    void on_borrow_clicked();

    void on_searchBar_textChanged(const QString &searchText);

private:
    Ui::table_newspaper *ui;
};

#endif // TABLE_NEWSPAPER_H
