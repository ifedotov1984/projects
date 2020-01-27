/****************************************************************************
** Meta object code from reading C++ file 'asc35d_calib.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../CE35DConfig/asc35d_calib.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asc35d_calib.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ASC35D_Calib_t {
    QByteArrayData data[19];
    char stringdata0[354];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ASC35D_Calib_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ASC35D_Calib_t qt_meta_stringdata_ASC35D_Calib = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ASC35D_Calib"
QT_MOC_LITERAL(1, 13, 16), // "pollTimerTimeout"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 17), // "on_Cancel_clicked"
QT_MOC_LITERAL(4, 49, 16), // "UpdateVoltChecks"
QT_MOC_LITERAL(5, 66, 24), // "on_ASC35D_Calib_finished"
QT_MOC_LITERAL(6, 91, 6), // "result"
QT_MOC_LITERAL(7, 98, 21), // "on_v_diaWrite_clicked"
QT_MOC_LITERAL(8, 120, 20), // "on_v_upWrite_clicked"
QT_MOC_LITERAL(9, 141, 21), // "on_v_dwnWrite_clicked"
QT_MOC_LITERAL(10, 163, 22), // "on_v_Calibrate_clicked"
QT_MOC_LITERAL(11, 186, 19), // "on_avgWrite_clicked"
QT_MOC_LITERAL(12, 206, 19), // "on_pswWrite_clicked"
QT_MOC_LITERAL(13, 226, 19), // "on_i_zWrite_clicked"
QT_MOC_LITERAL(14, 246, 18), // "on_i_Write_clicked"
QT_MOC_LITERAL(15, 265, 22), // "on_i_Calibrate_clicked"
QT_MOC_LITERAL(16, 288, 21), // "on_c_dwnWrite_clicked"
QT_MOC_LITERAL(17, 310, 22), // "on_c_Calibrate_clicked"
QT_MOC_LITERAL(18, 333, 20) // "on_c_upWrite_clicked"

    },
    "ASC35D_Calib\0pollTimerTimeout\0\0"
    "on_Cancel_clicked\0UpdateVoltChecks\0"
    "on_ASC35D_Calib_finished\0result\0"
    "on_v_diaWrite_clicked\0on_v_upWrite_clicked\0"
    "on_v_dwnWrite_clicked\0on_v_Calibrate_clicked\0"
    "on_avgWrite_clicked\0on_pswWrite_clicked\0"
    "on_i_zWrite_clicked\0on_i_Write_clicked\0"
    "on_i_Calibrate_clicked\0on_c_dwnWrite_clicked\0"
    "on_c_Calibrate_clicked\0on_c_upWrite_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ASC35D_Calib[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    1,   96,    2, 0x08 /* Private */,
       5,    1,   99,    2, 0x08 /* Private */,
       7,    0,  102,    2, 0x08 /* Private */,
       8,    0,  103,    2, 0x08 /* Private */,
       9,    0,  104,    2, 0x08 /* Private */,
      10,    0,  105,    2, 0x08 /* Private */,
      11,    0,  106,    2, 0x08 /* Private */,
      12,    0,  107,    2, 0x08 /* Private */,
      13,    0,  108,    2, 0x08 /* Private */,
      14,    0,  109,    2, 0x08 /* Private */,
      15,    0,  110,    2, 0x08 /* Private */,
      16,    0,  111,    2, 0x08 /* Private */,
      17,    0,  112,    2, 0x08 /* Private */,
      18,    0,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ASC35D_Calib::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ASC35D_Calib *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pollTimerTimeout(); break;
        case 1: _t->on_Cancel_clicked(); break;
        case 2: _t->UpdateVoltChecks((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_ASC35D_Calib_finished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_v_diaWrite_clicked(); break;
        case 5: _t->on_v_upWrite_clicked(); break;
        case 6: _t->on_v_dwnWrite_clicked(); break;
        case 7: _t->on_v_Calibrate_clicked(); break;
        case 8: _t->on_avgWrite_clicked(); break;
        case 9: _t->on_pswWrite_clicked(); break;
        case 10: _t->on_i_zWrite_clicked(); break;
        case 11: _t->on_i_Write_clicked(); break;
        case 12: _t->on_i_Calibrate_clicked(); break;
        case 13: _t->on_c_dwnWrite_clicked(); break;
        case 14: _t->on_c_Calibrate_clicked(); break;
        case 15: _t->on_c_upWrite_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ASC35D_Calib::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ASC35D_Calib.data,
    qt_meta_data_ASC35D_Calib,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ASC35D_Calib::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ASC35D_Calib::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ASC35D_Calib.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ASC35D_Calib::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
