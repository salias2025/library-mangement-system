#ifndef TABLE_NOT_RETURNED_H
#define TABLE_NOT_RETURNED_H

#include <QDialog>

namespace Ui {
class table_not_returned;
}

class table_not_returned : public QDialog
{
    Q_OBJECT

public:
    explicit table_not_returned(QWidget *parent = nullptr);
    ~table_not_returned();

private:
    Ui::table_not_returned *ui;
};

#endif // TABLE_NOT_RETURNED_H
