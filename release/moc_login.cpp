/****************************************************************************
** Meta object code from reading C++ file 'login.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../login.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'login.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LogIn_t {
    QByteArrayData data[11];
    char stringdata0[200];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LogIn_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LogIn_t qt_meta_stringdata_LogIn = {
    {
QT_MOC_LITERAL(0, 0, 5), // "LogIn"
QT_MOC_LITERAL(1, 6, 17), // "postLogInFinished"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 21), // "on_editCancel_clicked"
QT_MOC_LITERAL(4, 47, 19), // "on_btnLogIn_clicked"
QT_MOC_LITERAL(5, 67, 23), // "on_editName_textChanged"
QT_MOC_LITERAL(6, 91, 4), // "arg1"
QT_MOC_LITERAL(7, 96, 23), // "on_editPswd_textChanged"
QT_MOC_LITERAL(8, 120, 28), // "on_cheAutoLogin_stateChanged"
QT_MOC_LITERAL(9, 149, 30), // "on_cheRemeberPswd_stateChanged"
QT_MOC_LITERAL(10, 180, 19) // "onPostLogInFinished"

    },
    "LogIn\0postLogInFinished\0\0on_editCancel_clicked\0"
    "on_btnLogIn_clicked\0on_editName_textChanged\0"
    "arg1\0on_editPswd_textChanged\0"
    "on_cheAutoLogin_stateChanged\0"
    "on_cheRemeberPswd_stateChanged\0"
    "onPostLogInFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LogIn[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    1,   57,    2, 0x08 /* Private */,
       7,    1,   60,    2, 0x08 /* Private */,
       8,    1,   63,    2, 0x08 /* Private */,
       9,    1,   66,    2, 0x08 /* Private */,
      10,    0,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,

       0        // eod
};

void LogIn::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LogIn *_t = static_cast<LogIn *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->postLogInFinished(); break;
        case 1: _t->on_editCancel_clicked(); break;
        case 2: _t->on_btnLogIn_clicked(); break;
        case 3: _t->on_editName_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_editPswd_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_cheAutoLogin_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_cheRemeberPswd_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->onPostLogInFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (LogIn::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LogIn::postLogInFinished)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject LogIn::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_LogIn.data,
      qt_meta_data_LogIn,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LogIn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LogIn::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LogIn.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int LogIn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void LogIn::postLogInFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
