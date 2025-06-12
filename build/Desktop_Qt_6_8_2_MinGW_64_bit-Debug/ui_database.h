/********************************************************************************
** Form generated from reading UI file 'database.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASE_H
#define UI_DATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Database
{
public:

    void setupUi(QDialog *Database)
    {
        if (Database->objectName().isEmpty())
            Database->setObjectName("Database");
        Database->resize(400, 300);

        retranslateUi(Database);

        QMetaObject::connectSlotsByName(Database);
    } // setupUi

    void retranslateUi(QDialog *Database)
    {
        Database->setWindowTitle(QCoreApplication::translate("Database", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Database: public Ui_Database {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASE_H
