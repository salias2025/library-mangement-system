/********************************************************************************
** Form generated from reading UI file 'borrow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BORROW_H
#define UI_BORROW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_borrow
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QDateEdit *borrow_date;
    QDateEdit *return_date;
    QLineEdit *title;
    QLineEdit *author;

    void setupUi(QDialog *borrow)
    {
        if (borrow->objectName().isEmpty())
            borrow->setObjectName("borrow");
        borrow->resize(820, 566);
        pushButton = new QPushButton(borrow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(530, 470, 151, 51));
        label = new QLabel(borrow);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 80, 141, 51));
        label->setStyleSheet(QString::fromUtf8("\n"
"font: 700 15pt \"Urdu Typesetting\";"));
        label_2 = new QLabel(borrow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 140, 141, 51));
        label_2->setStyleSheet(QString::fromUtf8("\n"
"font: 700 15pt \"Urdu Typesetting\";"));
        label_3 = new QLabel(borrow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 190, 141, 51));
        label_3->setStyleSheet(QString::fromUtf8("\n"
"font: 700 15pt \"Urdu Typesetting\";"));
        label_4 = new QLabel(borrow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(80, 250, 141, 51));
        label_4->setStyleSheet(QString::fromUtf8("\n"
"font: 700 15pt \"Urdu Typesetting\";"));
        borrow_date = new QDateEdit(borrow);
        borrow_date->setObjectName("borrow_date");
        borrow_date->setGeometry(QRect(240, 200, 181, 41));
        return_date = new QDateEdit(borrow);
        return_date->setObjectName("return_date");
        return_date->setGeometry(QRect(240, 260, 181, 41));
        title = new QLineEdit(borrow);
        title->setObjectName("title");
        title->setGeometry(QRect(240, 90, 181, 41));
        author = new QLineEdit(borrow);
        author->setObjectName("author");
        author->setGeometry(QRect(240, 150, 181, 41));

        retranslateUi(borrow);

        QMetaObject::connectSlotsByName(borrow);
    } // setupUi

    void retranslateUi(QDialog *borrow)
    {
        borrow->setWindowTitle(QCoreApplication::translate("borrow", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("borrow", "confirm", nullptr));
        label->setText(QCoreApplication::translate("borrow", "Title:", nullptr));
        label_2->setText(QCoreApplication::translate("borrow", "author:", nullptr));
        label_3->setText(QCoreApplication::translate("borrow", "borrow date:", nullptr));
        label_4->setText(QCoreApplication::translate("borrow", "return date:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class borrow: public Ui_borrow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORROW_H
