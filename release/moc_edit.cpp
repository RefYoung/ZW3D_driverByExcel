/****************************************************************************
** Meta object code from reading C++ file 'edit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../edit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'edit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_edit_t {
    QByteArrayData data[15];
    char stringdata0[316];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_edit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_edit_t qt_meta_stringdata_edit = {
    {
QT_MOC_LITERAL(0, 0, 4), // "edit"
QT_MOC_LITERAL(1, 5, 25), // "on_btnCheckInEdit_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 26), // "on_btnCheckOutEdit_clicked"
QT_MOC_LITERAL(4, 59, 24), // "on_btnUpdateEdit_clicked"
QT_MOC_LITERAL(5, 84, 22), // "on_btnSaveEdit_clicked"
QT_MOC_LITERAL(6, 107, 20), // "on_btnGenDwg_clicked"
QT_MOC_LITERAL(7, 128, 22), // "onGetModelTreeFinished"
QT_MOC_LITERAL(8, 151, 25), // "onGetModelTreeFinishedCap"
QT_MOC_LITERAL(9, 177, 40), // "on_combGitChoiceEdit_currentI..."
QT_MOC_LITERAL(10, 218, 5), // "index"
QT_MOC_LITERAL(11, 224, 21), // "onPostCheckInFinished"
QT_MOC_LITERAL(12, 246, 22), // "onPostCheckOutFinished"
QT_MOC_LITERAL(13, 269, 20), // "onPutFtpFileFinished"
QT_MOC_LITERAL(14, 290, 25) // "onPostUpload2DPicFinished"

    },
    "edit\0on_btnCheckInEdit_clicked\0\0"
    "on_btnCheckOutEdit_clicked\0"
    "on_btnUpdateEdit_clicked\0"
    "on_btnSaveEdit_clicked\0on_btnGenDwg_clicked\0"
    "onGetModelTreeFinished\0onGetModelTreeFinishedCap\0"
    "on_combGitChoiceEdit_currentIndexChanged\0"
    "index\0onPostCheckInFinished\0"
    "onPostCheckOutFinished\0onPutFtpFileFinished\0"
    "onPostUpload2DPicFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_edit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    1,   81,    2, 0x08 /* Private */,
      11,    0,   84,    2, 0x08 /* Private */,
      12,    0,   85,    2, 0x08 /* Private */,
      13,    0,   86,    2, 0x08 /* Private */,
      14,    0,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void edit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        edit *_t = static_cast<edit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnCheckInEdit_clicked(); break;
        case 1: _t->on_btnCheckOutEdit_clicked(); break;
        case 2: _t->on_btnUpdateEdit_clicked(); break;
        case 3: _t->on_btnSaveEdit_clicked(); break;
        case 4: _t->on_btnGenDwg_clicked(); break;
        case 5: _t->onGetModelTreeFinished(); break;
        case 6: _t->onGetModelTreeFinishedCap(); break;
        case 7: _t->on_combGitChoiceEdit_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->onPostCheckInFinished(); break;
        case 9: _t->onPostCheckOutFinished(); break;
        case 10: _t->onPutFtpFileFinished(); break;
        case 11: _t->onPostUpload2DPicFinished(); break;
        default: ;
        }
    }
}

const QMetaObject edit::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_edit.data,
      qt_meta_data_edit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *edit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *edit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_edit.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int edit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
