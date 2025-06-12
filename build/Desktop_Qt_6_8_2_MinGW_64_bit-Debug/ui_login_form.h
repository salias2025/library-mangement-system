/********************************************************************************
** Form generated from reading UI file 'login_form.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_FORM_H
#define UI_LOGIN_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_login_form
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *usrnm;
    QLineEdit *passwd;
    QPushButton *submit;

    void setupUi(QDialog *login_form)
    {
        if (login_form->objectName().isEmpty())
            login_form->setObjectName("login_form");
        login_form->resize(739, 510);
        label = new QLabel(login_form);
        label->setObjectName("label");
        label->setGeometry(QRect(230, 20, 271, 241));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/pictures/login.png);"));
        label_2 = new QLabel(login_form);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 310, 241, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 16pt \"Bernard MT\";\n"
""));
        label_3 = new QLabel(login_form);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 360, 251, 41));
        label_3->setStyleSheet(QString::fromUtf8("font: 16pt \"Bernard MT\";"));
        usrnm = new QLineEdit(login_form);
        usrnm->setObjectName("usrnm");
        usrnm->setGeometry(QRect(330, 300, 241, 41));
        usrnm->setStyleSheet(QString::fromUtf8("font: 15pt \"Segoe UI\";"));
        passwd = new QLineEdit(login_form);
        passwd->setObjectName("passwd");
        passwd->setGeometry(QRect(330, 370, 241, 41));
        passwd->setStyleSheet(QString::fromUtf8("font: 15pt \"Segoe UI\";"));
        passwd->setEchoMode(QLineEdit::EchoMode::Password);
        submit = new QPushButton(login_form);
        submit->setObjectName("submit");
        submit->setGeometry(QRect(550, 430, 151, 41));

        retranslateUi(login_form);

        QMetaObject::connectSlotsByName(login_form);
    } // setupUi

    void retranslateUi(QDialog *login_form)
    {
        login_form->setWindowTitle(QCoreApplication::translate("login_form", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("login_form", "enter your username:", nullptr));
        label_3->setText(QCoreApplication::translate("login_form", "enter your password:", nullptr));
        submit->setText(QCoreApplication::translate("login_form", "submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login_form: public Ui_login_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_FORM_H
