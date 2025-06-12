#ifndef ADMIN_FORM_H
#define ADMIN_FORM_H

#include <QDialog>

namespace Ui {
class admin_form;
}

class admin_form : public QDialog
{
    Q_OBJECT

public:
    explicit admin_form(QWidget *parent = nullptr);
    ~admin_form();

private slots:
    void on_submit_clicked();

private:
    Ui::admin_form *ui;
};

#endif // ADMIN_FORM_H
