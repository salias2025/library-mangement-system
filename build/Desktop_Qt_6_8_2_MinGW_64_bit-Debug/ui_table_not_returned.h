/********************************************************************************
** Form generated from reading UI file 'table_not_returned.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_NOT_RETURNED_H
#define UI_TABLE_NOT_RETURNED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_table_not_returned
{
public:
    QTableWidget *tableWidget;

    void setupUi(QDialog *table_not_returned)
    {
        if (table_not_returned->objectName().isEmpty())
            table_not_returned->setObjectName("table_not_returned");
        table_not_returned->resize(822, 487);
        tableWidget = new QTableWidget(table_not_returned);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(110, 40, 571, 371));
        tableWidget->horizontalHeader()->setStretchLastSection(true);

        retranslateUi(table_not_returned);

        QMetaObject::connectSlotsByName(table_not_returned);
    } // setupUi

    void retranslateUi(QDialog *table_not_returned)
    {
        table_not_returned->setWindowTitle(QCoreApplication::translate("table_not_returned", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("table_not_returned", "borrowed titles", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("table_not_returned", "borrow_dates", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("table_not_returned", "return_dates", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("table_not_returned", "deadline_passed", nullptr));
    } // retranslateUi

};

namespace Ui {
    class table_not_returned: public Ui_table_not_returned {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_NOT_RETURNED_H
