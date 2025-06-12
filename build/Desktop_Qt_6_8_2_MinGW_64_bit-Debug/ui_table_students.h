/********************************************************************************
** Form generated from reading UI file 'table_students.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_STUDENTS_H
#define UI_TABLE_STUDENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_table_students
{
public:
    QTableWidget *tableWidget;
    QPushButton *remove_student;
    QLineEdit *searchBar;
    QLabel *label;

    void setupUi(QDialog *table_students)
    {
        if (table_students->objectName().isEmpty())
            table_students->setObjectName("table_students");
        table_students->resize(1439, 596);
        tableWidget = new QTableWidget(table_students);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
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
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 70, 1401, 461));
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        remove_student = new QPushButton(table_students);
        remove_student->setObjectName("remove_student");
        remove_student->setGeometry(QRect(852, 548, 281, 41));
        searchBar = new QLineEdit(table_students);
        searchBar->setObjectName("searchBar");
        searchBar->setGeometry(QRect(1100, 20, 151, 31));
        label = new QLabel(table_students);
        label->setObjectName("label");
        label->setGeometry(QRect(1010, 20, 101, 31));

        retranslateUi(table_students);

        QMetaObject::connectSlotsByName(table_students);
    } // setupUi

    void retranslateUi(QDialog *table_students)
    {
        table_students->setWindowTitle(QCoreApplication::translate("table_students", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("table_students", "first name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("table_students", "family name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("table_students", "date_of_birth", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("table_students", "student ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("table_students", "username", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("table_students", "study year ", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("table_students", "borrowed books", nullptr));
        remove_student->setText(QCoreApplication::translate("table_students", "remove student", nullptr));
        label->setText(QCoreApplication::translate("table_students", "search bar:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class table_students: public Ui_table_students {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_STUDENTS_H
