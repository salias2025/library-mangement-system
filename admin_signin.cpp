#include "admin_signin.h"
#include "ui_admin_signin.h"
#include <QMessageBox>
#include "user.h"
#include "database.h"
#include "admin_options.h"
admin_signin::admin_signin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::admin_signin)
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
    ui->dateEdit->setMinimumDate(QDate(1900, 1, 1));
    ui->dateEdit->setMaximumDate(QDate(2007, 12, 31));
    ui->fix_part->setText("2424");
    ui->fix_part->setReadOnly(true);

}

admin_signin::~admin_signin()
{
    delete ui;
}

void admin_signin::on_submit_clicked()
{
    QString prenom = ui->first_name->text();
    QString nom = ui->family_name->text();
    QDate date_de_naissance = ui->dateEdit->date();
    QString identite_scolaire = ui->id->text();

    QString nom_utilisateur = ui->username->text();
    QString mot_de_passe = ui->choose_passwd->text();
    QString confirmation = ui->conf_passwd->text();
    QString root = ui->root_passwd->text();

    admin ad;
    if (root != ad.get_root_password()) {
        QMessageBox::warning(this, "Input Error", "The root password is incorrect.");
        return;
    }

    if (prenom.isEmpty() || nom.isEmpty() || identite_scolaire.isEmpty() ||
        mot_de_passe.isEmpty() || confirmation.isEmpty() || root.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all the required fields.");
        return;
    }

    if (mot_de_passe != confirmation) {
        QMessageBox::warning(this, "Input Error", "Check your password confirmation.");
        return;
    }

    if (!user::isStrongPassword(mot_de_passe)) return;
    if (!user::check_infos_validity(prenom, nom, identite_scolaire)) return;
    if (!user::check_username_unicity(nom_utilisateur)) return;

    Database::addAdmin(prenom, nom, date_de_naissance, identite_scolaire, nom_utilisateur, mot_de_passe);

    user::users.clear();  // Optional
    Database::loadStudents();
    Database::loadAdmins();
    user::sort_users();

    int pos = user::search_user(nom_utilisateur);
    user::current_user = user::users[pos];

    QMessageBox::information(this, "Congrats", "Admin added successfully.");
    admin_options* options = new admin_options();
    options->setModal(true);
    this->hide();  // Keep window in memory
    options->show();
}
