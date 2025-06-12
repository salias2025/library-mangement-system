#ifndef ADD_NEWSPAPER_H
#define ADD_NEWSPAPER_H

#include <QDialog>

namespace Ui {
class add_newspaper;
}

class add_newspaper : public QDialog
{
    Q_OBJECT

public:
    explicit add_newspaper(QWidget *parent = nullptr);
    ~add_newspaper();
private slots:
    void limitTextSize();

    void on_submit_clicked();


private:
    Ui::add_newspaper *ui;
};

#endif // ADD_NEWSPAPER_H
