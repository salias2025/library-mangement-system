/********************************************************************************
** Form generated from reading UI file 'readme.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_README_H
#define UI_README_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_readme
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;

    void setupUi(QDialog *readme)
    {
        if (readme->objectName().isEmpty())
            readme->setObjectName("readme");
        readme->resize(1203, 692);
        readme->setStyleSheet(QString::fromUtf8("font: 700 9pt \"Source Code Pro\";"));
        label = new QLabel(readme);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 40, 991, 61));
        label->setStyleSheet(QString::fromUtf8("font: 12pt ;"));
        label_2 = new QLabel(readme);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(100, 110, 531, 20));
        label_3 = new QLabel(readme);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(100, 150, 751, 20));
        label_4 = new QLabel(readme);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(100, 190, 1031, 20));
        label_5 = new QLabel(readme);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(100, 230, 751, 20));
        label_6 = new QLabel(readme);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(100, 280, 641, 20));
        label_6->setStyleSheet(QString::fromUtf8(""));
        label_7 = new QLabel(readme);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(100, 320, 621, 20));
        label_8 = new QLabel(readme);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(100, 360, 621, 20));
        label_9 = new QLabel(readme);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(100, 400, 811, 20));
        label_10 = new QLabel(readme);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(100, 440, 591, 20));
        label_11 = new QLabel(readme);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(100, 480, 1101, 20));
        label_12 = new QLabel(readme);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(100, 520, 1101, 20));
        label_13 = new QLabel(readme);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(100, 560, 1051, 20));
        label_14 = new QLabel(readme);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(100, 590, 771, 20));
        label_15 = new QLabel(readme);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(90, 630, 1121, 20));

        retranslateUi(readme);

        QMetaObject::connectSlotsByName(readme);
    } // setupUi

    void retranslateUi(QDialog *readme)
    {
        readme->setWindowTitle(QCoreApplication::translate("readme", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("readme", "here is a list of rules to follow during the use of the library mangement systems:", nullptr));
        label_2->setText(QCoreApplication::translate("readme", "1/-two types of users are allowed admins and students .", nullptr));
        label_3->setText(QCoreApplication::translate("readme", "2/-admins are responsible for adding deleting books ,and removing students.", nullptr));
        label_4->setText(QCoreApplication::translate("readme", "3/-admins have access to the list of available books ,magazines and newspapers ,students list and admins list .", nullptr));
        label_5->setText(QCoreApplication::translate("readme", "4/-to sign in or log in as admin you need to enter the root password .", nullptr));
        label_6->setText(QCoreApplication::translate("readme", "5/-it is not permitted to add two books with the same title.", nullptr));
        label_7->setText(QCoreApplication::translate("readme", "6/-books and students are sorted in the alphabetical order.", nullptr));
        label_8->setText(QCoreApplication::translate("readme", "7/-books and students can be found using seach bar option.", nullptr));
        label_9->setText(QCoreApplication::translate("readme", "8/-books are manipulated by their title while users are manipulated by their usernames.", nullptr));
        label_10->setText(QCoreApplication::translate("readme", "9/-usernames are unique attributes choosen by users.", nullptr));
        label_11->setText(QCoreApplication::translate("readme", "10/-the password choosen by a user must countain at least 8 characters,a capital letter ,a digit ,and a special character.", nullptr));
        label_12->setText(QCoreApplication::translate("readme", "11/-users have access to the availables books magazines and newspapers ,they can perform borrow and return book operations", nullptr));
        label_13->setText(QCoreApplication::translate("readme", "12/-when borroing a book a user must specify a return date that does not go beyond 2 months of the borrow date.", nullptr));
        label_14->setText(QCoreApplication::translate("readme", "13/-when returning a books the student can assign a rate to the book between 0-10.", nullptr));
        label_15->setText(QCoreApplication::translate("readme", "14/-the borrow and return dates can be accessed both my admins and users in the issued_books and non_returned books sections.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class readme: public Ui_readme {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_README_H
