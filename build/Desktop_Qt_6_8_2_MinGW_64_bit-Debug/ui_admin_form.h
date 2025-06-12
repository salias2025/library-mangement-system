/********************************************************************************
** Form generated from reading UI file 'admin_form.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_FORM_H
#define UI_ADMIN_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_admin_form
{
public:
    QLineEdit *usrnm;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *passwd;
    QLabel *label_3;
    QLineEdit *root_passwd;
    QLabel *label_4;
    QPushButton *submit;

    void setupUi(QDialog *admin_form)
    {
        if (admin_form->objectName().isEmpty())
            admin_form->setObjectName("admin_form");
        admin_form->resize(831, 556);
        usrnm = new QLineEdit(admin_form);
        usrnm->setObjectName("usrnm");
        usrnm->setGeometry(QRect(350, 300, 291, 41));
        usrnm->setStyleSheet(QString::fromUtf8("font: 15pt \"Segoe UI\";"));
        label_2 = new QLabel(admin_form);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(110, 310, 231, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 16pt \"Bernard MT\";\n"
""));
        label = new QLabel(admin_form);
        label->setObjectName("label");
        label->setGeometry(QRect(240, 50, 311, 201));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/pictures/login.png);"));
        passwd = new QLineEdit(admin_form);
        passwd->setObjectName("passwd");
        passwd->setGeometry(QRect(350, 360, 291, 41));
        passwd->setStyleSheet(QString::fromUtf8("font: 15pt \"Segoe UI\";"));
        passwd->setEchoMode(QLineEdit::EchoMode::Password);
        label_3 = new QLabel(admin_form);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(100, 360, 251, 41));
        label_3->setStyleSheet(QString::fromUtf8("font: 16pt \"Bernard MT\";"));
        root_passwd = new QLineEdit(admin_form);
        root_passwd->setObjectName("root_passwd");
        root_passwd->setGeometry(QRect(360, 420, 281, 41));
        root_passwd->setStyleSheet(QString::fromUtf8("font: 15pt \"Segoe UI\";"));
        root_passwd->setEchoMode(QLineEdit::EchoMode::Password);
        label_4 = new QLabel(admin_form);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(80, 420, 261, 41));
        label_4->setStyleSheet(QString::fromUtf8("font: 16pt \"Bernard MT\";\n"
"background-color: rgb(255, 3, 3);"));
        submit = new QPushButton(admin_form);
        submit->setObjectName("submit");
        submit->setGeometry(QRect(640, 490, 151, 41));

        retranslateUi(admin_form);

        QMetaObject::connectSlotsByName(admin_form);
    } // setupUi

    void retranslateUi(QDialog *admin_form)
    {
        admin_form->setWindowTitle(QCoreApplication::translate("admin_form", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("admin_form", "enter your username:", nullptr));
        label->setText(QString());
        label_3->setText(QCoreApplication::translate("admin_form", "enter your password:", nullptr));
        root_passwd->setText(QString());
        label_4->setText(QCoreApplication::translate("admin_form", "enter the root password:", nullptr));
        submit->setText(QCoreApplication::translate("admin_form", "submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admin_form: public Ui_admin_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_FORM_H
