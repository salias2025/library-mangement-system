/********************************************************************************
** Form generated from reading UI file 'signin.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNIN_H
#define UI_SIGNIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signin
{
public:
    QGroupBox *groupBox;
    QLabel *label_4;
    QLabel *label_8;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QLineEdit *fix_part;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *first_name;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *family_name;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDateEdit *dateEdit;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *username;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *choose_passwd;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *conf_passwd;
    QLineEdit *id;
    QPushButton *submit;

    void setupUi(QDialog *signin)
    {
        if (signin->objectName().isEmpty())
            signin->setObjectName("signin");
        signin->resize(1049, 662);
        groupBox = new QGroupBox(signin);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(30, 70, 951, 561));
        groupBox->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Arial Rounded MT\";\n"
""));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(70, 210, 123, 27));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(50, 390, 381, 21));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(70, 430, 181, 24));
        radioButton->setStyleSheet(QString::fromUtf8("font: 11pt \"Sitka\";\n"
""));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(70, 460, 181, 24));
        radioButton_2->setStyleSheet(QString::fromUtf8("font: 11pt \"Sitka\";\n"
""));
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setGeometry(QRect(70, 520, 181, 24));
        radioButton_3->setStyleSheet(QString::fromUtf8("font: 11pt \"Sitka\";\n"
""));
        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName("radioButton_4");
        radioButton_4->setGeometry(QRect(70, 490, 181, 24));
        radioButton_4->setStyleSheet(QString::fromUtf8("font: 11pt \"Sitka\";\n"
""));
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

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(60, 100, 421, 35));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        family_name = new QLineEdit(layoutWidget1);
        family_name->setObjectName("family_name");

        horizontalLayout_2->addWidget(family_name);

        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(70, 152, 411, 41));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        dateEdit = new QDateEdit(layoutWidget2);
        dateEdit->setObjectName("dateEdit");

        horizontalLayout_3->addWidget(dateEdit);

        layoutWidget3 = new QWidget(groupBox);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(60, 250, 481, 35));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget3);
        label_5->setObjectName("label_5");

        horizontalLayout_5->addWidget(label_5);

        username = new QLineEdit(layoutWidget3);
        username->setObjectName("username");

        horizontalLayout_5->addWidget(username);

        layoutWidget4 = new QWidget(groupBox);
        layoutWidget4->setObjectName("layoutWidget4");
        layoutWidget4->setGeometry(QRect(50, 300, 491, 35));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget4);
        label_6->setObjectName("label_6");

        horizontalLayout_6->addWidget(label_6);

        choose_passwd = new QLineEdit(layoutWidget4);
        choose_passwd->setObjectName("choose_passwd");
        choose_passwd->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_6->addWidget(choose_passwd);

        layoutWidget5 = new QWidget(groupBox);
        layoutWidget5->setObjectName("layoutWidget5");
        layoutWidget5->setGeometry(QRect(50, 340, 494, 35));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget5);
        label_7->setObjectName("label_7");

        horizontalLayout_7->addWidget(label_7);

        conf_passwd = new QLineEdit(layoutWidget5);
        conf_passwd->setObjectName("conf_passwd");
        conf_passwd->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_7->addWidget(conf_passwd);

        id = new QLineEdit(groupBox);
        id->setObjectName("id");
        id->setGeometry(QRect(310, 210, 231, 33));
        submit = new QPushButton(groupBox);
        submit->setObjectName("submit");
        submit->setGeometry(QRect(340, 500, 151, 41));

        retranslateUi(signin);

        QMetaObject::connectSlotsByName(signin);
    } // setupUi

    void retranslateUi(QDialog *signin)
    {
        signin->setWindowTitle(QCoreApplication::translate("signin", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("signin", "student inscription form :", nullptr));
        label_4->setText(QCoreApplication::translate("signin", "student_id:", nullptr));
        label_8->setText(QCoreApplication::translate("signin", "select your study year:", nullptr));
        radioButton->setText(QCoreApplication::translate("signin", "first year", nullptr));
        radioButton_2->setText(QCoreApplication::translate("signin", "second year", nullptr));
        radioButton_3->setText(QCoreApplication::translate("signin", "fourth year", nullptr));
        radioButton_4->setText(QCoreApplication::translate("signin", "third year", nullptr));
        label->setText(QCoreApplication::translate("signin", "first     name :", nullptr));
        label_2->setText(QCoreApplication::translate("signin", "family name :", nullptr));
        label_3->setText(QCoreApplication::translate("signin", "Birth date:", nullptr));
        label_5->setText(QCoreApplication::translate("signin", "choose a username:", nullptr));
        label_6->setText(QCoreApplication::translate("signin", "choose  a  password:", nullptr));
        label_7->setText(QCoreApplication::translate("signin", "confirm the password:", nullptr));
        submit->setText(QCoreApplication::translate("signin", "submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signin: public Ui_signin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNIN_H
