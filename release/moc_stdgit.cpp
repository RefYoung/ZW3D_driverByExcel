/****************************************************************************
** Meta object code from reading C++ file 'stdgit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../stdgit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stdgit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_stdGit_t {
    QByteArrayData data[11];
    char stringdata0[221];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_stdGit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_stdGit_t qt_meta_stringdata_stdGit = {
    {
QT_MOC_LITERAL(0, 0, 6), // "stdGit"
QT_MOC_LITERAL(1, 7, 23), // "on_btnOpenModel_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 22), // "onGetModelTreeFinished"
QT_MOC_LITERAL(4, 55, 36), // "on_treeViewStandardGit_double..."
QT_MOC_LITERAL(5, 92, 5), // "index"
QT_MOC_LITERAL(6, 98, 32), // "onGetQuery3DTPGitMaplistFinished"
QT_MOC_LITERAL(7, 131, 17), // "onGetFileFinished"
QT_MOC_LITERAL(8, 149, 21), // "onGetOpenModelFinshed"
QT_MOC_LITERAL(9, 171, 26), // "onGetOpenModelFileFinished"
QT_MOC_LITERAL(10, 198, 22) // "onPostCheckOutFinished"

    },
    "stdGit\0on_btnOpenModel_clicked\0\0"
    "onGetModelTreeFinished\0"
    "on_treeViewStandardGit_doubleClicked\0"
    "index\0onGetQuery3DTPGitMaplistFinished\0"
    "onGetFileFinished\0onGetOpenModelFinshed\0"
    "onGetOpenModelFileFinished\0"
    "onPostCheckOutFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_stdGit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    1,   56,    2, 0x08 /* Private */,
       6,    0,   59,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void stdGit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        stdGit *_t = static_cast<stdGit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnOpenModel_clicked(); break;
        case 1: _t->onGetModelTreeFinished(); break;
        case 2: _t->on_treeViewStandardGit_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->onGetQuery3DTPGitMaplistFinished(); break;
        case 4: _t->onGetFileFinished(); break;
        case 5: _t->onGetOpenModelFinshed(); break;
        case 6: _t->onGetOpenModelFileFinished(); break;
        case 7: _t->onPostCheckOutFinished(); break;
        default: ;
        }
    }
}

const QMetaObject stdGit::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_stdGit.data,
      qt_meta_data_stdGit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *stdGit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *stdGit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_stdGit.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int stdGit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
