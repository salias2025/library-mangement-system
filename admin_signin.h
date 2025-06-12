#ifndef ADMIN_SIGNIN_H
#define ADMIN_SIGNIN_H

#include <QDialog>

namespace Ui {
class admin_signin;
}

class admin_signin : public QDialog
{
    Q_OBJECT

public:
    explicit admin_signin(QWidget *parent = nullptr);
    ~admin_signin();

private slots:
    void on_submit_clicked();

private:
    Ui::admin_signin *ui;
};

#endif // ADMIN_SIGNIN_H
