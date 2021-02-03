/****************************************************************************
** Meta object code from reading C++ file 'vcrs485_config.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CE35DConfig/vcrs485_config.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vcrs485_config.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VCRS485_Config_t {
    QByteArrayData data[8];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VCRS485_Config_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VCRS485_Config_t qt_meta_stringdata_VCRS485_Config = {
    {
QT_MOC_LITERAL(0, 0, 14), // "VCRS485_Config"
QT_MOC_LITERAL(1, 15, 16), // "pollTimerTimeout"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 17), // "on_dWrite_clicked"
QT_MOC_LITERAL(4, 51, 19), // "on_dWrite_2_clicked"
QT_MOC_LITERAL(5, 71, 17), // "on_Cancel_clicked"
QT_MOC_LITERAL(6, 89, 26), // "on_VCRS485_Config_finished"
QT_MOC_LITERAL(7, 116, 6) // "result"

    },
    "VCRS485_Config\0pollTimerTimeout\0\0"
    "on_dWrite_clicked\0on_dWrite_2_clicked\0"
    "on_Cancel_clicked\0on_VCRS485_Config_finished\0"
    "result"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VCRS485_Config[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    1,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void VCRS485_Config::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VCRS485_Config *_t = static_cast<VCRS485_Config *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pollTimerTimeout(); break;
        case 1: _t->on_dWrite_clicked(); break;
        case 2: _t->on_dWrite_2_clicked(); break;
        case 3: _t->on_Cancel_clicked(); break;
        case 4: _t->on_VCRS485_Config_finished((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject VCRS485_Config::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_VCRS485_Config.data,
      qt_meta_data_VCRS485_Config,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *VCRS485_Config::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VCRS485_Config::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VCRS485_Config.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int VCRS485_Config::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
