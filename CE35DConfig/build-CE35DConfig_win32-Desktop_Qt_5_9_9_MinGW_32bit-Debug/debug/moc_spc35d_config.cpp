/****************************************************************************
** Meta object code from reading C++ file 'spc35d_config.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CE35DConfig/spc35d_config.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spc35d_config.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SPC35D_Config_t {
    QByteArrayData data[8];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SPC35D_Config_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SPC35D_Config_t qt_meta_stringdata_SPC35D_Config = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SPC35D_Config"
QT_MOC_LITERAL(1, 14, 16), // "pollTimerTimeout"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 20), // "on_addrWrite_clicked"
QT_MOC_LITERAL(4, 53, 21), // "on_passwWrite_clicked"
QT_MOC_LITERAL(5, 75, 25), // "on_SPC35D_Config_finished"
QT_MOC_LITERAL(6, 101, 6), // "result"
QT_MOC_LITERAL(7, 108, 17) // "on_Cancel_clicked"

    },
    "SPC35D_Config\0pollTimerTimeout\0\0"
    "on_addrWrite_clicked\0on_passwWrite_clicked\0"
    "on_SPC35D_Config_finished\0result\0"
    "on_Cancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SPC35D_Config[] = {

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
       5,    1,   42,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,

       0        // eod
};

void SPC35D_Config::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SPC35D_Config *_t = static_cast<SPC35D_Config *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pollTimerTimeout(); break;
        case 1: _t->on_addrWrite_clicked(); break;
        case 2: _t->on_passwWrite_clicked(); break;
        case 3: _t->on_SPC35D_Config_finished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_Cancel_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject SPC35D_Config::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SPC35D_Config.data,
      qt_meta_data_SPC35D_Config,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SPC35D_Config::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SPC35D_Config::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SPC35D_Config.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SPC35D_Config::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
