/********************************************************************************
** Form generated from reading UI file 'table_admins.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_ADMINS_H
#define UI_TABLE_ADMINS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_table_admins
{
public:
    QTableWidget *tableWidget;
    QPushButton *pushButton;

    void setupUi(QDialog *table_admins)
    {
        if (table_admins->objectName().isEmpty())
            table_admins->setObjectName("table_admins");
        table_admins->resize(1163, 735);
        tableWidget = new QTableWidget(table_admins);
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
        tableWidget->setGeometry(QRect(140, 30, 841, 471));
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        pushButton = new QPushButton(table_admins);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(810, 540, 211, 51));

        retranslateUi(table_admins);

        QMetaObject::connectSlotsByName(table_admins);
    } // setupUi

    void retranslateUi(QDialog *table_admins)
    {
        table_admins->setWindowTitle(QCoreApplication::translate("table_admins", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("table_admins", "first name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("table_admins", "family name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("table_admins", "date_of_birth", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("table_admins", "admin ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("table_admins", "username", nullptr));
        pushButton->setText(QCoreApplication::translate("table_admins", "remove admin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class table_admins: public Ui_table_admins {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_ADMINS_H
