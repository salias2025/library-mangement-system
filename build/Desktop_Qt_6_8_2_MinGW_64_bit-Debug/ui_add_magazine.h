/********************************************************************************
** Form generated from reading UI file 'add_magazine.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_MAGAZINE_H
#define UI_ADD_MAGAZINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_add_magazine
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *title;
    QLineEdit *author;
    QSpinBox *spinBox;
    QLineEdit *paginas;
    QLabel *label_7;
    QPlainTextEdit *MyTextEdit;
    QLabel *label_8;
    QPushButton *submit;
    QLineEdit *price;

    void setupUi(QDialog *add_magazine)
    {
        if (add_magazine->objectName().isEmpty())
            add_magazine->setObjectName("add_magazine");
        add_magazine->resize(829, 633);
        groupBox = new QGroupBox(add_magazine);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 0, 811, 621));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 188, 188);\n"
"font : 15pt \"Showcard Gothic\";\n"
""));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 50, 171, 41));
        label->setStyleSheet(QString::fromUtf8("\n"
"font: 15pt \"Sitka\";\n"
"font-weight: bold;"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 230, 171, 41));
        label_3->setStyleSheet(QString::fromUtf8("\n"
"font: 15pt \"Sitka\";\n"
"font-weight: bold;"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 160, 271, 71));
        label_4->setStyleSheet(QString::fromUtf8("\n"
"font: 15pt \"Sitka\";\n"
"font-weight: bold;"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 110, 171, 51));
        label_5->setStyleSheet(QString::fromUtf8("\n"
"font: 15pt \"Sitka\";\n"
"font-weight: bold;"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 280, 171, 41));
        label_6->setStyleSheet(QString::fromUtf8("\n"
"font: 11pt \"Sitka\";\n"
"font-weight: bold;"));
        title = new QLineEdit(groupBox);
        title->setObjectName("title");
        title->setGeometry(QRect(130, 50, 311, 41));
        title->setStyleSheet(QString::fromUtf8("font: 12pt \"Javanese Text\";\n"
"background-color: rgb(255, 235, 229);"));
        author = new QLineEdit(groupBox);
        author->setObjectName("author");
        author->setGeometry(QRect(130, 110, 311, 41));
        author->setStyleSheet(QString::fromUtf8("font: 12pt \"Javanese Text\";\n"
"\n"
"background-color: rgb(255, 235, 229);"));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(190, 290, 231, 31));
        spinBox->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 235, 229);\n"
"font: 12pt \"Javanese Text\";"));
        paginas = new QLineEdit(groupBox);
        paginas->setObjectName("paginas");
        paginas->setGeometry(QRect(260, 170, 181, 41));
        paginas->setStyleSheet(QString::fromUtf8("font: 12pt \"Javanese Text\";\n"
"\n"
"background-color: rgb(255, 235, 229);"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 390, 171, 41));
        label_7->setStyleSheet(QString::fromUtf8("\n"
"font: 15pt \"Sitka\";\n"
"font-weight: bold;"));
        MyTextEdit = new QPlainTextEdit(groupBox);
        MyTextEdit->setObjectName("MyTextEdit");
        MyTextEdit->setGeometry(QRect(190, 380, 391, 181));
        MyTextEdit->setStyleSheet(QString::fromUtf8("font: 12pt \"Javanese Text\";\n"
"\n"
"background-color: rgb(255, 235, 229);"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 330, 411, 41));
        label_8->setStyleSheet(QString::fromUtf8("\n"
"font: 11pt \"Sitka\";\n"
"font-weight: bold;"));
        submit = new QPushButton(groupBox);
        submit->setObjectName("submit");
        submit->setGeometry(QRect(620, 530, 171, 51));
        submit->setStyleSheet(QString::fromUtf8("\n"
"font: 15pt \"Sitka\";\n"
"font-weight: bold;"));
        price = new QLineEdit(groupBox);
        price->setObjectName("price");
        price->setGeometry(QRect(190, 230, 231, 31));
        price->setStyleSheet(QString::fromUtf8("font: 12pt \"Javanese Text\";\n"
"\n"
"background-color: rgb(255, 235, 229);"));

        retranslateUi(add_magazine);

        QMetaObject::connectSlotsByName(add_magazine);
    } // setupUi

    void retranslateUi(QDialog *add_magazine)
    {
        add_magazine->setWindowTitle(QCoreApplication::translate("add_magazine", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("add_magazine", "adding a book form", nullptr));
        label->setText(QCoreApplication::translate("add_magazine", "Title:", nullptr));
        label_3->setText(QCoreApplication::translate("add_magazine", "unity price :", nullptr));
        label_4->setText(QCoreApplication::translate("add_magazine", "number of pages:", nullptr));
        label_5->setText(QCoreApplication::translate("add_magazine", "author :", nullptr));
        label_6->setText(QCoreApplication::translate("add_magazine", "available copies:", nullptr));
        label_7->setText(QString());
        label_8->setText(QCoreApplication::translate("add_magazine", "provide a small description of the book:", nullptr));
        submit->setText(QCoreApplication::translate("add_magazine", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class add_magazine: public Ui_add_magazine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_MAGAZINE_H
