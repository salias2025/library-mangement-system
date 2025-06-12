#ifndef BORROW_H
#define BORROW_H

#include <QDialog>

namespace Ui {
class borrow;
}

class borrow : public QDialog
{
    Q_OBJECT

public:
    explicit borrow(QWidget *parent = nullptr);
    ~borrow();
    void setTitle(const QString& title);

    void setAuthor(const QString& author);


private slots:
    void on_pushButton_clicked();

private:
    Ui::borrow *ui;
};

#endif // BORROW_H
