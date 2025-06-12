#include "admin_form.h"
#include "ui_admin_form.h"
#include "QMessageBox"
#include "user.h"
#include "admin_options.h"
#include "database.h"
admin_form::admin_form(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::admin_form)
{
    ui->setupUi(this);
     this->setStyleSheet("background-color: #ADD8E6;");
    ui->submit->setStyleSheet(
        "QPushButton { background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #8B4513, stop:1 #A0522D); color: white; border: none; padding: 10px 20px; font-size: 16px; font-weight: bold; border-radius: 8px; }"
        "QPushButton:hover { background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #A0522D, stop:1 #8B4513); }"
        "QPushButton:pressed { background: #6A2E0F; }"
        );
}

admin_form::~admin_form()
{
    delete ui;
}

void admin_form::on_submit_clicked()
{
    QString utilisateur=ui->usrnm->text();
    QString mot_de_passe=ui->passwd->text();
    QString root=ui->root_passwd->text();
    admin ad;


    if (root != ad.get_root_password()){
         QMessageBox::warning(this,"input error","the provided root password in incorrect");
        return;
    }

    if(user::authenticate(utilisateur,mot_de_passe)){
        QMessageBox::information(this, "welcome", "welcome "+utilisateur);
        int pos=user::search_user(utilisateur);
        user::current_user=user::users[pos];

        admin_options options;
        options.setModal(true);
        this->close();
        options.exec();

    }else{
        QMessageBox::warning(this,"input error","user not found check your log in infos");
    }
}

