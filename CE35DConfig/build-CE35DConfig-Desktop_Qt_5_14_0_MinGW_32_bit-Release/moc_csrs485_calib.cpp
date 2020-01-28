/****************************************************************************
** Meta object code from reading C++ file 'csrs485_calib.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../CE35DConfig/csrs485_calib.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'csrs485_calib.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CSRS485_Calib_t {
    QByteArrayData data[9];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CSRS485_Calib_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CSRS485_Calib_t qt_meta_stringdata_CSRS485_Calib = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CSRS485_Calib"
QT_MOC_LITERAL(1, 14, 16), // "pollTimerTimeout"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 17), // "on_Cancel_clicked"
QT_MOC_LITERAL(4, 50, 25), // "on_CSRS485_Calib_finished"
QT_MOC_LITERAL(5, 76, 6), // "result"
QT_MOC_LITERAL(6, 83, 17), // "on_CalibZ_clicked"
QT_MOC_LITERAL(7, 101, 17), // "on_CalibV_clicked"
QT_MOC_LITERAL(8, 119, 16) // "on_Write_clicked"

    },
    "CSRS485_Calib\0pollTimerTimeout\0\0"
    "on_Cancel_clicked\0on_CSRS485_Calib_finished\0"
    "result\0on_CalibZ_clicked\0on_CalibV_clicked\0"
    "on_Write_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CSRS485_Calib[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    1,   46,    2, 0x08 /* Private */,
       6,    0,   49,    2, 0x08 /* Private */,
       7,    0,   50,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CSRS485_Calib::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CSRS485_Calib *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pollTimerTimeout(); break;
        case 1: _t->on_Cancel_clicked(); break;
        case 2: _t->on_CSRS485_Calib_finished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_CalibZ_clicked(); break;
        case 4: _t->on_CalibV_clicked(); break;
        case 5: _t->on_Write_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CSRS485_Calib::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CSRS485_Calib.data,
    qt_meta_data_CSRS485_Calib,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CSRS485_Calib::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSRS485_Calib::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CSRS485_Calib.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CSRS485_Calib::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
