/****************************************************************************
** Meta object code from reading C++ file 'admin_options.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../admin_options.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'admin_options.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN13admin_optionsE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN13admin_optionsE = QtMocHelpers::stringData(
    "admin_options",
    "on_books_clicked",
    "",
    "on_magazines_clicked",
    "on_newspapers_clicked",
    "on_students_clicked",
    "on_admins_clicked",
    "on_issued_clicked",
    "on_non_returned_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN13admin_optionsE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    0,   62,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject admin_options::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ZN13admin_optionsE.offsetsAndSizes,
    qt_meta_data_ZN13admin_optionsE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN13admin_optionsE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<admin_options, std::true_type>,
        // method 'on_books_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_magazines_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_newspapers_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_students_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_admins_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_issued_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_non_returned_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void admin_options::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<admin_options *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_books_clicked(); break;
        case 1: _t->on_magazines_clicked(); break;
        case 2: _t->on_newspapers_clicked(); break;
        case 3: _t->on_students_clicked(); break;
        case 4: _t->on_admins_clicked(); break;
        case 5: _t->on_issued_clicked(); break;
        case 6: _t->on_non_returned_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *admin_options::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *admin_options::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN13admin_optionsE.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int admin_options::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
