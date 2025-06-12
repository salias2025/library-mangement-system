#ifndef ADD_MAGAZINE_H
#define ADD_MAGAZINE_H

#include <QDialog>

namespace Ui {
class add_magazine;
}

class add_magazine : public QDialog
{
    Q_OBJECT

public:
    explicit add_magazine(QWidget *parent = nullptr);
    ~add_magazine();
private slots:
    void limitTextSize();
    void on_submit_clicked();

private:
    Ui::add_magazine *ui;
};

#endif // ADD_MAGAZINE_H
