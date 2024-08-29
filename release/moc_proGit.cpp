/****************************************************************************
** Meta object code from reading C++ file 'proGit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../proGit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'proGit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_proGit_t {
    QByteArrayData data[12];
    char stringdata0[242];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_proGit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_proGit_t qt_meta_stringdata_proGit = {
    {
QT_MOC_LITERAL(0, 0, 6), // "proGit"
QT_MOC_LITERAL(1, 7, 23), // "on_btnOpenModel_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 20), // "on_btnDetail_clicked"
QT_MOC_LITERAL(4, 53, 22), // "onGetModelTreeFinished"
QT_MOC_LITERAL(5, 76, 36), // "on_treeViewStandardGit_double..."
QT_MOC_LITERAL(6, 113, 5), // "index"
QT_MOC_LITERAL(7, 119, 32), // "onGetQuery3DTPGitMaplistFinished"
QT_MOC_LITERAL(8, 152, 17), // "onGetFileFinished"
QT_MOC_LITERAL(9, 170, 21), // "onGetOpenModelFinshed"
QT_MOC_LITERAL(10, 192, 26), // "onGetOpenModelFileFinished"
QT_MOC_LITERAL(11, 219, 22) // "onPostCheckOutFinished"

    },
    "proGit\0on_btnOpenModel_clicked\0\0"
    "on_btnDetail_clicked\0onGetModelTreeFinished\0"
    "on_treeViewStandardGit_doubleClicked\0"
    "index\0onGetQuery3DTPGitMaplistFinished\0"
    "onGetFileFinished\0onGetOpenModelFinshed\0"
    "onGetOpenModelFileFinished\0"
    "onPostCheckOutFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_proGit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    1,   62,    2, 0x08 /* Private */,
       7,    0,   65,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    0,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void proGit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        proGit *_t = static_cast<proGit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnOpenModel_clicked(); break;
        case 1: _t->on_btnDetail_clicked(); break;
        case 2: _t->onGetModelTreeFinished(); break;
        case 3: _t->on_treeViewStandardGit_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->onGetQuery3DTPGitMaplistFinished(); break;
        case 5: _t->onGetFileFinished(); break;
        case 6: _t->onGetOpenModelFinshed(); break;
        case 7: _t->onGetOpenModelFileFinished(); break;
        case 8: _t->onPostCheckOutFinished(); break;
        default: ;
        }
    }
}

const QMetaObject proGit::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_proGit.data,
      qt_meta_data_proGit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *proGit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *proGit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_proGit.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int proGit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
