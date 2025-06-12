#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_sign_in_clicked();

    void on_log_in_clicked();

    void on_sign_admin_clicked();

    void on_log_admin_clicked();

    void on_read_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
