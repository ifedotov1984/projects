/****************************************************************************
** Meta object code from reading C++ file 'sva35d_calib.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../CE35DConfig/sva35d_calib.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sva35d_calib.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SVA35D_Calib_t {
    QByteArrayData data[17];
    char stringdata0[295];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SVA35D_Calib_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SVA35D_Calib_t qt_meta_stringdata_SVA35D_Calib = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SVA35D_Calib"
QT_MOC_LITERAL(1, 13, 16), // "pollTimerTimeout"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 18), // "updateTimerTimeout"
QT_MOC_LITERAL(4, 50, 20), // "on_TempWrite_clicked"
QT_MOC_LITERAL(5, 71, 22), // "on_offsetWrite_clicked"
QT_MOC_LITERAL(6, 94, 17), // "on_vWrite_clicked"
QT_MOC_LITERAL(7, 112, 17), // "on_cWrite_clicked"
QT_MOC_LITERAL(8, 130, 21), // "on_checkWrite_clicked"
QT_MOC_LITERAL(9, 152, 19), // "on_aWrite_1_clicked"
QT_MOC_LITERAL(10, 172, 19), // "on_aWrite_2_clicked"
QT_MOC_LITERAL(11, 192, 19), // "on_aWrite_3_clicked"
QT_MOC_LITERAL(12, 212, 15), // "on_Save_clicked"
QT_MOC_LITERAL(13, 228, 16), // "on_Write_clicked"
QT_MOC_LITERAL(14, 245, 24), // "on_SVA35D_Calib_finished"
QT_MOC_LITERAL(15, 270, 6), // "result"
QT_MOC_LITERAL(16, 277, 17) // "on_Cancel_clicked"

    },
    "SVA35D_Calib\0pollTimerTimeout\0\0"
    "updateTimerTimeout\0on_TempWrite_clicked\0"
    "on_offsetWrite_clicked\0on_vWrite_clicked\0"
    "on_cWrite_clicked\0on_checkWrite_clicked\0"
    "on_aWrite_1_clicked\0on_aWrite_2_clicked\0"
    "on_aWrite_3_clicked\0on_Save_clicked\0"
    "on_Write_clicked\0on_SVA35D_Calib_finished\0"
    "result\0on_Cancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SVA35D_Calib[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    1,   96,    2, 0x08 /* Private */,
      16,    0,   99,    2, 0x08 /* Private */,

 // slots: parameters
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
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,

       0        // eod
};

void SVA35D_Calib::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SVA35D_Calib *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pollTimerTimeout(); break;
        case 1: _t->updateTimerTimeout(); break;
        case 2: _t->on_TempWrite_clicked(); break;
        case 3: _t->on_offsetWrite_clicked(); break;
        case 4: _t->on_vWrite_clicked(); break;
        case 5: _t->on_cWrite_clicked(); break;
        case 6: _t->on_checkWrite_clicked(); break;
        case 7: _t->on_aWrite_1_clicked(); break;
        case 8: _t->on_aWrite_2_clicked(); break;
        case 9: _t->on_aWrite_3_clicked(); break;
        case 10: _t->on_Save_clicked(); break;
        case 11: _t->on_Write_clicked(); break;
        case 12: _t->on_SVA35D_Calib_finished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_Cancel_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SVA35D_Calib::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_SVA35D_Calib.data,
    qt_meta_data_SVA35D_Calib,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SVA35D_Calib::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SVA35D_Calib::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SVA35D_Calib.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SVA35D_Calib::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
