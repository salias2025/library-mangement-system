/********************************************************************************
** Form generated from reading UI file 'admin_options.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_OPTIONS_H
#define UI_ADMIN_OPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_admin_options
{
public:
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_4;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QPushButton *books;
    QPushButton *magazines;
    QPushButton *newspapers;
    QPushButton *students;
    QPushButton *admins;
    QPushButton *issued;

    void setupUi(QDialog *admin_options)
    {
        if (admin_options->objectName().isEmpty())
            admin_options->setObjectName("admin_options");
        admin_options->resize(1510, 597);
        horizontalLayout = new QHBoxLayout(admin_options);
        horizontalLayout->setObjectName("horizontalLayout");
        scrollArea = new QScrollArea(admin_options);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName("scrollAreaWidgetContents_4");
        scrollAreaWidgetContents_4->setGeometry(QRect(0, -1649, 1469, 2222));
        horizontalLayout_2 = new QHBoxLayout(scrollAreaWidgetContents_4);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        widget = new QWidget(scrollAreaWidgetContents_4);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 2200));
        books = new QPushButton(widget);
        books->setObjectName("books");
        books->setGeometry(QRect(90, 10, 1251, 351));
        magazines = new QPushButton(widget);
        magazines->setObjectName("magazines");
        magazines->setGeometry(QRect(90, 370, 1251, 351));
        newspapers = new QPushButton(widget);
        newspapers->setObjectName("newspapers");
        newspapers->setGeometry(QRect(90, 730, 1251, 351));
        students = new QPushButton(widget);
        students->setObjectName("students");
        students->setGeometry(QRect(90, 1090, 1251, 351));
        admins = new QPushButton(widget);
        admins->setObjectName("admins");
        admins->setGeometry(QRect(100, 1450, 1241, 351));
        issued = new QPushButton(widget);
        issued->setObjectName("issued");
        issued->setGeometry(QRect(100, 1820, 1241, 351));

        horizontalLayout_2->addWidget(widget);

        scrollArea->setWidget(scrollAreaWidgetContents_4);

        horizontalLayout->addWidget(scrollArea);


        retranslateUi(admin_options);

        QMetaObject::connectSlotsByName(admin_options);
    } // setupUi

    void retranslateUi(QDialog *admin_options)
    {
        admin_options->setWindowTitle(QCoreApplication::translate("admin_options", "Dialog", nullptr));
        books->setText(QString());
        magazines->setText(QString());
        newspapers->setText(QString());
        students->setText(QString());
        admins->setText(QString());
        issued->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class admin_options: public Ui_admin_options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_OPTIONS_H
