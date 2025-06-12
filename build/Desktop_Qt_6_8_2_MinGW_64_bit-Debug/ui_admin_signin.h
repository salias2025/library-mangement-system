/********************************************************************************
** Form generated from reading UI file 'admin_signin.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_SIGNIN_H
#define UI_ADMIN_SIGNIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_admin_signin
{
public:
    QGroupBox *groupBox;
    QLabel *label_4;
    QLineEdit *fix_part;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *first_name;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *family_name;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDateEdit *dateEdit;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *username;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *choose_passwd;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *conf_passwd;
    QLineEdit *id;
    QLabel *label_8;
    QLineEdit *root_passwd;
    QPushButton *submit;

    void setupUi(QDialog *admin_signin)
    {
        if (admin_signin->objectName().isEmpty())
            admin_signin->setObjectName("admin_signin");
        admin_signin->resize(992, 688);
        groupBox = new QGroupBox(admin_signin);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 60, 951, 561));
        groupBox->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Arial Rounded MT\";\n"
""));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(70, 210, 123, 27));
        fix_part = new QLineEdit(groupBox);
        fix_part->setObjectName("fix_part");
        fix_part->setGeometry(QRect(200, 210, 101, 31));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(60, 60, 421, 35));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        first_name = new QLineEdit(layoutWidget);
        first_name->setObjectName("first_name");

        horizontalLayout->addWidget(first_name);

        layoutWidget_2 = new QWidget(groupBox);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(60, 100, 421, 35));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        family_name = new QLineEdit(layoutWidget_2);
        family_name->setObjectName("family_name");

        horizontalLayout_2->addWidget(family_name);

        layoutWidget_3 = new QWidget(groupBox);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(70, 152, 411, 41));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_3);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        dateEdit = new QDateEdit(layoutWidget_3);
        dateEdit->setObjectName("dateEdit");

        horizontalLayout_3->addWidget(dateEdit);

        layoutWidget_4 = new QWidget(groupBox);
        layoutWidget_4->setObjectName("layoutWidget_4");
        layoutWidget_4->setGeometry(QRect(60, 250, 481, 35));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget_4);
        label_5->setObjectName("label_5");

        horizontalLayout_5->addWidget(label_5);

        username = new QLineEdit(layoutWidget_4);
        username->setObjectName("username");

        horizontalLayout_5->addWidget(username);

        layoutWidget_5 = new QWidget(groupBox);
        layoutWidget_5->setObjectName("layoutWidget_5");
        layoutWidget_5->setGeometry(QRect(50, 300, 491, 35));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget_5);
        label_6->setObjectName("label_6");

        horizontalLayout_6->addWidget(label_6);

        choose_passwd = new QLineEdit(layoutWidget_5);
        choose_passwd->setObjectName("choose_passwd");
        choose_passwd->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_6->addWidget(choose_passwd);

        layoutWidget_6 = new QWidget(groupBox);
        layoutWidget_6->setObjectName("layoutWidget_6");
        layoutWidget_6->setGeometry(QRect(50, 340, 494, 35));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_6);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget_6);
        label_7->setObjectName("label_7");

        horizontalLayout_7->addWidget(label_7);

        conf_passwd = new QLineEdit(layoutWidget_6);
        conf_passwd->setObjectName("conf_passwd");
        conf_passwd->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_7->addWidget(conf_passwd);

        id = new QLineEdit(groupBox);
        id->setObjectName("id");
        id->setGeometry(QRect(310, 210, 231, 33));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(140, 430, 311, 41));
        label_8->setStyleSheet(QString::fromUtf8("font: 900 14pt \"Segoe UI\";\n"
"background-color: rgb(255, 0, 0);"));
        root_passwd = new QLineEdit(groupBox);
        root_passwd->setObjectName("root_passwd");
        root_passwd->setGeometry(QRect(470, 430, 301, 41));
        root_passwd->setEchoMode(QLineEdit::EchoMode::Password);
        submit = new QPushButton(groupBox);
        submit->setObjectName("submit");
        submit->setGeometry(QRect(380, 500, 151, 41));

        retranslateUi(admin_signin);

        QMetaObject::connectSlotsByName(admin_signin);
    } // setupUi

    void retranslateUi(QDialog *admin_signin)
    {
        admin_signin->setWindowTitle(QCoreApplication::translate("admin_signin", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("admin_signin", "admin sign in form :", nullptr));
        label_4->setText(QCoreApplication::translate("admin_signin", "admin_id:", nullptr));
        label->setText(QCoreApplication::translate("admin_signin", "first     name :", nullptr));
        label_2->setText(QCoreApplication::translate("admin_signin", "family name :", nullptr));
        label_3->setText(QCoreApplication::translate("admin_signin", "Birth date:", nullptr));
        label_5->setText(QCoreApplication::translate("admin_signin", "choose a username:", nullptr));
        label_6->setText(QCoreApplication::translate("admin_signin", "choose  a  password:", nullptr));
        label_7->setText(QCoreApplication::translate("admin_signin", "confirm the password:", nullptr));
        label_8->setText(QCoreApplication::translate("admin_signin", "enter the root password:", nullptr));
        submit->setText(QCoreApplication::translate("admin_signin", "submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admin_signin: public Ui_admin_signin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_SIGNIN_H
