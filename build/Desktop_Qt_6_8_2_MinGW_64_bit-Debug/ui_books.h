/********************************************************************************
** Form generated from reading UI file 'books.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKS_H
#define UI_BOOKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_books
{
public:

    void setupUi(QDialog *books)
    {
        if (books->objectName().isEmpty())
            books->setObjectName("books");
        books->resize(400, 300);

        retranslateUi(books);

        QMetaObject::connectSlotsByName(books);
    } // setupUi

    void retranslateUi(QDialog *books)
    {
        books->setWindowTitle(QCoreApplication::translate("books", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class books: public Ui_books {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKS_H
