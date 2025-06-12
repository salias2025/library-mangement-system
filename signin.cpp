#include "signin.h"
#include "ui_signin.h"
#include "user.h"
#include <QMessageBox>
#include "database.h"
#include "student_options.h"

signin::signin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signin)
{
    ui->setupUi(this);
    QPixmap bgPixmap(":/pictures/signin.png");

    // Scale the pixmap to the widget size
    QPixmap scaledPixmap = bgPixmap.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(scaledPixmap));

    this->setAutoFillBackground(true);
    this->setPalette(palette);
    ui->submit->setStyleSheet(
        "QPushButton { background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #8B4513, stop:1 #A0522D); color: white; border: none; padding: 10px 20px; font-size: 16px; font-weight: bold; border-radius: 8px; }"
        "QPushButton:hover { background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #A0522D, stop:1 #8B4513); }"
        "QPushButton:pressed { background: #6A2E0F; }"
        );
    ui->dateEdit->setMinimumDate(QDate(2003, 1, 1));
    ui->dateEdit->setMaximumDate(QDate(2007, 12, 31));
    ui->fix_part->setText("2424");
    ui->fix_part->setReadOnly(true);
}

signin::~signin()
{
    delete ui;
}

void signin::on_submit_clicked()
{
    QString prenom=ui->first_name->text();
    QString nom=ui->family_name->text();
    QDate date_de_naissance=ui->dateEdit->date();
    QString identite_scolaire=ui->id->text();

    QString nom_utilisateur=ui->username->text();
    QString mot_de_passe=ui->choose_passwd->text();
    QString confirmation=ui->conf_passwd->text();
    int annee = 0;


    if (ui->radioButton->isChecked()) {
        annee = 1;
    } else if (ui->radioButton_2->isChecked()) {
        annee = 2;
    } else if (ui->radioButton_3->isChecked()) {
        annee = 3;
    } else if (ui->radioButton_4->isChecked()) {
        annee = 4;
    } else {
        QMessageBox::warning(this, "Input Error", "Please select a study year.");
        return;  // or handle no selection
    }

    if (prenom.isEmpty() || nom.isEmpty() || identite_scolaire.isEmpty() || mot_de_passe.isEmpty() || confirmation.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all the required fields.");
        return;  // stop further processing
    }

    if (mot_de_passe!=confirmation){
        QMessageBox::warning(this, "Input Error", "check your password confirmation.");
        return;  // stop further processing
    }
    if(  ! user::isStrongPassword(mot_de_passe)){
        return;
    };
     if (! user::check_infos_validity(prenom,nom,identite_scolaire )){
        return ;
    }
         ;
     if (!user::check_username_unicity(nom_utilisateur)) {
         return;
     }

     student *s = new student(prenom, nom, date_de_naissance, identite_scolaire, nom_utilisateur, mot_de_passe, annee);

     if (student::add_student(s)) {

         QMessageBox::information(this, "Success", "User added successfully.");

         user::users.clear();
         Database::loadStudents();
         Database::loadAdmins();
         user::sort_users();

         int pos = user::search_user(nom_utilisateur);
         user::current_user = user::users[pos];

         student_options options;
         options.setModal(true);
         this->close();
         options.exec();
     }else{
          QMessageBox::warning(this, "warning", "failed to add the user.");
     }


}

