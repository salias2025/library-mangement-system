#ifndef TABLE_ADMINS_H
#define TABLE_ADMINS_H

#include <QDialog>

namespace Ui {
class table_admins;
}

class table_admins : public QDialog
{
    Q_OBJECT

public:
    explicit table_admins(QWidget *parent = nullptr);
    ~table_admins();

private slots:
    void on_pushButton_clicked();

private:
    Ui::table_admins *ui;
};

#endif // TABLE_ADMINS_H
