/****************************************************************************
** Meta object code from reading C++ file 'sr_control.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CE35DConfig/sr_control.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sr_control.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SR_Control_t {
    QByteArrayData data[7];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SR_Control_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SR_Control_t qt_meta_stringdata_SR_Control = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SR_Control"
QT_MOC_LITERAL(1, 11, 16), // "pollTimerTimeout"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 22), // "on_SR_Control_finished"
QT_MOC_LITERAL(4, 52, 6), // "result"
QT_MOC_LITERAL(5, 59, 17), // "on_Cancel_clicked"
QT_MOC_LITERAL(6, 77, 16) // "on_Write_clicked"

    },
    "SR_Control\0pollTimerTimeout\0\0"
    "on_SR_Control_finished\0result\0"
    "on_Cancel_clicked\0on_Write_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SR_Control[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    1,   35,    2, 0x08 /* Private */,
       5,    0,   38,    2, 0x08 /* Private */,
       6,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SR_Control::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SR_Control *_t = static_cast<SR_Control *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pollTimerTimeout(); break;
        case 1: _t->on_SR_Control_finished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_Cancel_clicked(); break;
        case 3: _t->on_Write_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject SR_Control::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SR_Control.data,
      qt_meta_data_SR_Control,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SR_Control::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SR_Control::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SR_Control.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SR_Control::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
