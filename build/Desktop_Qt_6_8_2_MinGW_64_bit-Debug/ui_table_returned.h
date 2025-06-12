/********************************************************************************
** Form generated from reading UI file 'table_returned.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_RETURNED_H
#define UI_TABLE_RETURNED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_table_returned
{
public:

    void setupUi(QDialog *table_returned)
    {
        if (table_returned->objectName().isEmpty())
            table_returned->setObjectName("table_returned");
        table_returned->resize(400, 300);

        retranslateUi(table_returned);

        QMetaObject::connectSlotsByName(table_returned);
    } // setupUi

    void retranslateUi(QDialog *table_returned)
    {
        table_returned->setWindowTitle(QCoreApplication::translate("table_returned", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class table_returned: public Ui_table_returned {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_RETURNED_H
