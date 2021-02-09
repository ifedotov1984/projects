/****************************************************************************
** Meta object code from reading C++ file 'asc35d_config.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../CE35DConfig/asc35d_config.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'asc35d_config.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ASC35D_Config_t {
    QByteArrayData data[12];
    char stringdata0[207];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ASC35D_Config_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ASC35D_Config_t qt_meta_stringdata_ASC35D_Config = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ASC35D_Config"
QT_MOC_LITERAL(1, 14, 16), // "pollTimerTimeout"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 25), // "on_ASC35D_Config_finished"
QT_MOC_LITERAL(4, 58, 6), // "result"
QT_MOC_LITERAL(5, 65, 17), // "on_Cancel_clicked"
QT_MOC_LITERAL(6, 83, 20), // "on_i_Write_1_clicked"
QT_MOC_LITERAL(7, 104, 20), // "on_i_Write_2_clicked"
QT_MOC_LITERAL(8, 125, 20), // "on_i_Write_3_clicked"
QT_MOC_LITERAL(9, 146, 20), // "on_i_Write_4_clicked"
QT_MOC_LITERAL(10, 167, 19), // "on_dWrite_1_clicked"
QT_MOC_LITERAL(11, 187, 19) // "on_dWrite_2_clicked"

    },
    "ASC35D_Config\0pollTimerTimeout\0\0"
    "on_ASC35D_Config_finished\0result\0"
    "on_Cancel_clicked\0on_i_Write_1_clicked\0"
    "on_i_Write_2_clicked\0on_i_Write_3_clicked\0"
    "on_i_Write_4_clicked\0on_dWrite_1_clicked\0"
    "on_dWrite_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ASC35D_Config[] = {

 // content:
       8,       // revision
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
       3,    1,   60,    2, 0x08 /* Private */,
       5,    0,   63,    2, 0x08 /* Private */,
       6,    0,   64,    2, 0x08 /* Private */,
       7,    0,   65,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x08 /* Private */,
      11,    0,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ASC35D_Config::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ASC35D_Config *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pollTimerTimeout(); break;
        case 1: _t->on_ASC35D_Config_finished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_Cancel_clicked(); break;
        case 3: _t->on_i_Write_1_clicked(); break;
        case 4: _t->on_i_Write_2_clicked(); break;
        case 5: _t->on_i_Write_3_clicked(); break;
        case 6: _t->on_i_Write_4_clicked(); break;
        case 7: _t->on_dWrite_1_clicked(); break;
        case 8: _t->on_dWrite_2_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ASC35D_Config::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ASC35D_Config.data,
    qt_meta_data_ASC35D_Config,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ASC35D_Config::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ASC35D_Config::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ASC35D_Config.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ASC35D_Config::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
