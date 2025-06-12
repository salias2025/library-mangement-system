#ifndef TABLE_ISSUED_H
#define TABLE_ISSUED_H

#include <QDialog>

namespace Ui {
class table_issued;
}

class table_issued : public QDialog
{
    Q_OBJECT

public:
    explicit table_issued(QWidget *parent = nullptr);
    ~table_issued();

private:
    Ui::table_issued *ui;
};

#endif // TABLE_ISSUED_H
