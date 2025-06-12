/********************************************************************************
** Form generated from reading UI file 'student_options.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENT_OPTIONS_H
#define UI_STUDENT_OPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_student_options
{
public:
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame;
    QPushButton *books;
    QPushButton *magazines;
    QPushButton *newspapers;
    QPushButton *non_returned;

    void setupUi(QDialog *student_options)
    {
        if (student_options->objectName().isEmpty())
            student_options->setObjectName("student_options");
        student_options->resize(1147, 546);
        horizontalLayout = new QHBoxLayout(student_options);
        horizontalLayout->setObjectName("horizontalLayout");
        scrollArea = new QScrollArea(student_options);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, -1000, 1106, 1522));
        horizontalLayout_2 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        frame = new QFrame(scrollAreaWidgetContents);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(0, 1500));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        books = new QPushButton(frame);
        books->setObjectName("books");
        books->setGeometry(QRect(0, 10, 1071, 351));
        magazines = new QPushButton(frame);
        magazines->setObjectName("magazines");
        magazines->setGeometry(QRect(0, 370, 1071, 351));
        newspapers = new QPushButton(frame);
        newspapers->setObjectName("newspapers");
        newspapers->setGeometry(QRect(0, 730, 1071, 351));
        non_returned = new QPushButton(frame);
        non_returned->setObjectName("non_returned");
        non_returned->setGeometry(QRect(0, 1090, 1071, 351));

        horizontalLayout_2->addWidget(frame);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);


        retranslateUi(student_options);

        QMetaObject::connectSlotsByName(student_options);
    } // setupUi

    void retranslateUi(QDialog *student_options)
    {
        student_options->setWindowTitle(QCoreApplication::translate("student_options", "Dialog", nullptr));
        books->setText(QString());
        magazines->setText(QString());
        newspapers->setText(QString());
        non_returned->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class student_options: public Ui_student_options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENT_OPTIONS_H
