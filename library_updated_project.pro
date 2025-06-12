QT       += core gui
    QT +=sql
    DISTFILES +=mylibrary.db
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_book.cpp \
    add_magazine.cpp \
    add_newspaper.cpp \
    admin_form.cpp \
    admin_options.cpp \
    admin_signin.cpp \
    borrow.cpp \
    database.cpp \
    login_form.cpp \
    main.cpp \
    mainwindow.cpp \
    readme.cpp \
    return_book.cpp \
    signin.cpp \
    student_options.cpp \
    table_admins.cpp \
    table_books.cpp \
    table_issued.cpp \
    table_magazines.cpp \
    table_newspaper.cpp \
    table_not_returned.cpp \
    table_students.cpp \
    ubook.cpp \
    user.cpp

HEADERS += \
    add_book.h \
    add_magazine.h \
    add_newspaper.h \
    admin_form.h \
    admin_options.h \
    admin_signin.h \
    borrow.h \
    database.h \
    login_form.h \
    mainwindow.h \
    readme.h \
    return_book.h \
    signin.h \
    student_options.h \
    table_admins.h \
    table_books.h \
    table_issued.h \
    table_magazines.h \
    table_newspaper.h \
    table_not_returned.h \
    table_students.h \
    ubook.h \
    user.h

FORMS += \
    add_book.ui \
    add_magazine.ui \
    add_newspaper.ui \
    admin_form.ui \
    admin_options.ui \
    admin_signin.ui \
    borrow.ui \
    login_form.ui \
    mainwindow.ui \
    readme.ui \
    return_book.ui \
    signin.ui \
    student_options.ui \
    table_admins.ui \
    table_books.ui \
    table_issued.ui \
    table_magazines.ui \
    table_newspaper.ui \
    table_not_returned.ui \
    table_students.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources.qrc

DISTFILES += \
    pictures/sidebooks.jpg
