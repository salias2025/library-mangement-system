/********************************************************************************
** Form generated from reading UI file 'return_book.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RETURN_BOOK_H
#define UI_RETURN_BOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_return_book
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *rate;
    QLineEdit *lineEdit_2;
    QLineEdit *title;
    QLineEdit *username;
    QPushButton *confirm;

    void setupUi(QDialog *return_book)
    {
        if (return_book->objectName().isEmpty())
            return_book->setObjectName("return_book");
        return_book->resize(593, 402);
        label = new QLabel(return_book);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 80, 61, 41));
        label->setStyleSheet(QString::fromUtf8("font: 11pt \"Sitka\";"));
        label_2 = new QLabel(return_book);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(150, 30, 281, 41));
        label_2->setStyleSheet(QString::fromUtf8("font: 11pt \"Sitka\";"));
        label_3 = new QLabel(return_book);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 130, 101, 41));
        label_3->setStyleSheet(QString::fromUtf8("font: 11pt \"Sitka\";"));
        label_4 = new QLabel(return_book);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 180, 181, 20));
        label_4->setStyleSheet(QString::fromUtf8("font: 11pt \"Sitka\";"));
        rate = new QLineEdit(return_book);
        rate->setObjectName("rate");
        rate->setGeometry(QRect(170, 180, 31, 26));
        lineEdit_2 = new QLineEdit(return_book);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(200, 180, 31, 26));
        title = new QLineEdit(return_book);
        title->setObjectName("title");
        title->setGeometry(QRect(170, 90, 141, 26));
        username = new QLineEdit(return_book);
        username->setObjectName("username");
        username->setGeometry(QRect(170, 140, 141, 26));
        confirm = new QPushButton(return_book);
        confirm->setObjectName("confirm");
        confirm->setGeometry(QRect(380, 270, 161, 51));

        retranslateUi(return_book);

        QMetaObject::connectSlotsByName(return_book);
    } // setupUi

    void retranslateUi(QDialog *return_book)
    {
        return_book->setWindowTitle(QCoreApplication::translate("return_book", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("return_book", "title :", nullptr));
        label_2->setText(QCoreApplication::translate("return_book", "may you confirm  this is you :", nullptr));
        label_3->setText(QCoreApplication::translate("return_book", "username:", nullptr));
        label_4->setText(QCoreApplication::translate("return_book", "your rate :", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("return_book", "/10", nullptr));
        confirm->setText(QCoreApplication::translate("return_book", "confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class return_book: public Ui_return_book {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RETURN_BOOK_H
