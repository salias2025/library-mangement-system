/********************************************************************************
** Form generated from reading UI file 'table_books.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_BOOKS_H
#define UI_TABLE_BOOKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_table_books
{
public:
    QTableWidget *tableWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *returm;
    QPushButton *remove;
    QPushButton *borrow;
    QPushButton *add;
    QLineEdit *search_bar;
    QLabel *label;

    void setupUi(QDialog *table_books)
    {
        if (table_books->objectName().isEmpty())
            table_books->setObjectName("table_books");
        table_books->resize(1525, 719);
        tableWidget = new QTableWidget(table_books);
        if (tableWidget->columnCount() < 11)
            tableWidget->setColumnCount(11);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 60, 1511, 581));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(234, 252, 255);"));
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        layoutWidget = new QWidget(table_books);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 650, 1491, 71));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        returm = new QPushButton(layoutWidget);
        returm->setObjectName("returm");

        horizontalLayout->addWidget(returm);

        remove = new QPushButton(layoutWidget);
        remove->setObjectName("remove");

        horizontalLayout->addWidget(remove);

        borrow = new QPushButton(layoutWidget);
        borrow->setObjectName("borrow");

        horizontalLayout->addWidget(borrow);

        add = new QPushButton(layoutWidget);
        add->setObjectName("add");

        horizontalLayout->addWidget(add);

        search_bar = new QLineEdit(table_books);
        search_bar->setObjectName("search_bar");
        search_bar->setGeometry(QRect(1090, 15, 191, 31));
        label = new QLabel(table_books);
        label->setObjectName("label");
        label->setGeometry(QRect(990, 19, 91, 21));

        retranslateUi(table_books);

        QMetaObject::connectSlotsByName(table_books);
    } // setupUi

    void retranslateUi(QDialog *table_books)
    {
        table_books->setWindowTitle(QCoreApplication::translate("table_books", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("table_books", "title", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("table_books", "author", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("table_books", "genre", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("table_books", "description", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("table_books", "number of pages", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("table_books", "available copies", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("table_books", "issued", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("table_books", "returned", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("table_books", "non_returned", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("table_books", "rating", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("table_books", "borrowers", nullptr));
        returm->setText(QCoreApplication::translate("table_books", "return book", nullptr));
        remove->setText(QCoreApplication::translate("table_books", "remove book", nullptr));
        borrow->setText(QCoreApplication::translate("table_books", "borrow book", nullptr));
        add->setText(QCoreApplication::translate("table_books", "add book ", nullptr));
        label->setText(QCoreApplication::translate("table_books", "search bar:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class table_books: public Ui_table_books {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_BOOKS_H
