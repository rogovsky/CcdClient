/****************************************************************************
** Meta object code from reading C++ file 'DataReceiver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "DataReceiver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DataReceiver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DataReceiver_t {
    QByteArrayData data[23];
    char stringdata[283];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataReceiver_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataReceiver_t qt_meta_stringdata_DataReceiver = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 10),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 7),
QT_MOC_LITERAL(4, 33, 37),
QT_MOC_LITERAL(5, 71, 4),
QT_MOC_LITERAL(6, 76, 21),
QT_MOC_LITERAL(7, 98, 10),
QT_MOC_LITERAL(8, 109, 4),
QT_MOC_LITERAL(9, 114, 12),
QT_MOC_LITERAL(10, 127, 17),
QT_MOC_LITERAL(11, 145, 26),
QT_MOC_LITERAL(12, 172, 5),
QT_MOC_LITERAL(13, 178, 6),
QT_MOC_LITERAL(14, 185, 9),
QT_MOC_LITERAL(15, 195, 11),
QT_MOC_LITERAL(16, 207, 4),
QT_MOC_LITERAL(17, 212, 5),
QT_MOC_LITERAL(18, 218, 12),
QT_MOC_LITERAL(19, 231, 22),
QT_MOC_LITERAL(20, 254, 9),
QT_MOC_LITERAL(21, 264, 12),
QT_MOC_LITERAL(22, 277, 5)
    },
    "DataReceiver\0updateData\0\0devName\0"
    "QHash<QString,Tango::DeviceAttribute>\0"
    "data\0addDeviceIsSuccessful\0DeviceType\0"
    "type\0deviceClosed\0getFullImage_done\0"
    "std::vector<unsigned char>\0width\0"
    "height\0addDevice\0closeDevice\0play\0"
    "pause\0setAttribute\0Tango::DeviceAttribute\0"
    "attribute\0getFullImage\0close"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataReceiver[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       6,    2,   74,    2, 0x06 /* Public */,
       9,    1,   79,    2, 0x06 /* Public */,
      10,    4,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    2,   91,    2, 0x0a /* Public */,
      15,    1,   96,    2, 0x0a /* Public */,
      16,    1,   99,    2, 0x0a /* Public */,
      17,    1,  102,    2, 0x0a /* Public */,
      18,    2,  105,    2, 0x0a /* Public */,
      21,    1,  110,    2, 0x0a /* Public */,
      22,    0,  113,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,    3,    8,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 11, QMetaType::Int, QMetaType::Int,    3,    5,   12,   13,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7,    3,    8,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 19,    3,   20,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

       0        // eod
};

void DataReceiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DataReceiver *_t = static_cast<DataReceiver *>(_o);
        switch (_id) {
        case 0: _t->updateData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QHash<QString,Tango::DeviceAttribute>(*)>(_a[2]))); break;
        case 1: _t->addDeviceIsSuccessful((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< DeviceType(*)>(_a[2]))); break;
        case 2: _t->deviceClosed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->getFullImage_done((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< std::vector<unsigned char>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 4: _t->addDevice((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< DeviceType(*)>(_a[2]))); break;
        case 5: _t->closeDevice((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->play((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->pause((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->setAttribute((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< Tango::DeviceAttribute(*)>(_a[2]))); break;
        case 9: _t->getFullImage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->close(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DataReceiver::*_t)(QString , QHash<QString,Tango::DeviceAttribute> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataReceiver::updateData)) {
                *result = 0;
            }
        }
        {
            typedef void (DataReceiver::*_t)(QString , DeviceType );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataReceiver::addDeviceIsSuccessful)) {
                *result = 1;
            }
        }
        {
            typedef void (DataReceiver::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataReceiver::deviceClosed)) {
                *result = 2;
            }
        }
        {
            typedef void (DataReceiver::*_t)(QString , std::vector<unsigned char> , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DataReceiver::getFullImage_done)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject DataReceiver::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_DataReceiver.data,
      qt_meta_data_DataReceiver,  qt_static_metacall, 0, 0}
};


const QMetaObject *DataReceiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataReceiver::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DataReceiver.stringdata))
        return static_cast<void*>(const_cast< DataReceiver*>(this));
    if (!strcmp(_clname, "Tango::CallBack"))
        return static_cast< Tango::CallBack*>(const_cast< DataReceiver*>(this));
    return QThread::qt_metacast(_clname);
}

int DataReceiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void DataReceiver::updateData(QString _t1, QHash<QString,Tango::DeviceAttribute> _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DataReceiver::addDeviceIsSuccessful(QString _t1, DeviceType _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DataReceiver::deviceClosed(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DataReceiver::getFullImage_done(QString _t1, std::vector<unsigned char> _t2, int _t3, int _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
