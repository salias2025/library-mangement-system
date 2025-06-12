/********************************************************************************
** Form generated from reading UI file 'table_issued.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_ISSUED_H
#define UI_TABLE_ISSUED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_table_issued
{
public:
    QTableWidget *tableWidget;

    void setupUi(QDialog *table_issued)
    {
        if (table_issued->objectName().isEmpty())
            table_issued->setObjectName("table_issued");
        table_issued->resize(1069, 600);
        tableWidget = new QTableWidget(table_issued);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
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
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(150, 30, 741, 531));
        tableWidget->horizontalHeader()->setStretchLastSection(true);

        retranslateUi(table_issued);

        QMetaObject::connectSlotsByName(table_issued);
    } // setupUi

    void retranslateUi(QDialog *table_issued)
    {
        table_issued->setWindowTitle(QCoreApplication::translate("table_issued", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("table_issued", "student", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("table_issued", "borrowed titles", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("table_issued", "borrow_date", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("table_issued", "return_date", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("table_issued", "deadline passed ?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class table_issued: public Ui_table_issued {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_ISSUED_H
