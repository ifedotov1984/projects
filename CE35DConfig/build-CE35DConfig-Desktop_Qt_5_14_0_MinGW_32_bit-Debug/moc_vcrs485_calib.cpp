/****************************************************************************
** Meta object code from reading C++ file 'vcrs485_calib.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../CE35DConfig/vcrs485_calib.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vcrs485_calib.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VCRS485_Calib_t {
    QByteArrayData data[13];
    char stringdata0[220];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VCRS485_Calib_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VCRS485_Calib_t qt_meta_stringdata_VCRS485_Calib = {
    {
QT_MOC_LITERAL(0, 0, 13), // "VCRS485_Calib"
QT_MOC_LITERAL(1, 14, 25), // "on_VCRS485_Calib_finished"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 6), // "result"
QT_MOC_LITERAL(4, 48, 16), // "pollTimerTimeout"
QT_MOC_LITERAL(5, 65, 17), // "on_Cancel_clicked"
QT_MOC_LITERAL(6, 83, 16), // "UpdateVoltChecks"
QT_MOC_LITERAL(7, 100, 19), // "on_diaWrite_clicked"
QT_MOC_LITERAL(8, 120, 18), // "on_upWrite_clicked"
QT_MOC_LITERAL(9, 139, 19), // "on_dwnWrite_clicked"
QT_MOC_LITERAL(10, 159, 20), // "on_Calibrate_clicked"
QT_MOC_LITERAL(11, 180, 19), // "on_avgWrite_clicked"
QT_MOC_LITERAL(12, 200, 19) // "on_pswWrite_clicked"

    },
    "VCRS485_Calib\0on_VCRS485_Calib_finished\0"
    "\0result\0pollTimerTimeout\0on_Cancel_clicked\0"
    "UpdateVoltChecks\0on_diaWrite_clicked\0"
    "on_upWrite_clicked\0on_dwnWrite_clicked\0"
    "on_Calibrate_clicked\0on_avgWrite_clicked\0"
    "on_pswWrite_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VCRS485_Calib[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x08 /* Private */,
       4,    0,   67,    2, 0x08 /* Private */,
       5,    0,   68,    2, 0x08 /* Private */,
       6,    1,   69,    2, 0x08 /* Private */,
       7,    0,   72,    2, 0x08 /* Private */,
       8,    0,   73,    2, 0x08 /* Private */,
       9,    0,   74,    2, 0x08 /* Private */,
      10,    0,   75,    2, 0x08 /* Private */,
      11,    0,   76,    2, 0x08 /* Private */,
      12,    0,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VCRS485_Calib::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VCRS485_Calib *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_VCRS485_Calib_finished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->pollTimerTimeout(); break;
        case 2: _t->on_Cancel_clicked(); break;
        case 3: _t->UpdateVoltChecks((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_diaWrite_clicked(); break;
        case 5: _t->on_upWrite_clicked(); break;
        case 6: _t->on_dwnWrite_clicked(); break;
        case 7: _t->on_Calibrate_clicked(); break;
        case 8: _t->on_avgWrite_clicked(); break;
        case 9: _t->on_pswWrite_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VCRS485_Calib::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_VCRS485_Calib.data,
    qt_meta_data_VCRS485_Calib,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VCRS485_Calib::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VCRS485_Calib::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VCRS485_Calib.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int VCRS485_Calib::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
