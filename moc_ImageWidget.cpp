/****************************************************************************
** Meta object code from reading C++ file 'ImageWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ImageWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImageWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ImageWidget_t {
    QByteArrayData data[22];
    char stringdata[296];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageWidget_t qt_meta_stringdata_ImageWidget = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 17),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 7),
QT_MOC_LITERAL(4, 39, 37),
QT_MOC_LITERAL(5, 77, 16),
QT_MOC_LITERAL(6, 94, 22),
QT_MOC_LITERAL(7, 117, 9),
QT_MOC_LITERAL(8, 127, 4),
QT_MOC_LITERAL(9, 132, 5),
QT_MOC_LITERAL(10, 138, 5),
QT_MOC_LITERAL(11, 144, 12),
QT_MOC_LITERAL(12, 157, 9),
QT_MOC_LITERAL(13, 167, 13),
QT_MOC_LITERAL(14, 181, 15),
QT_MOC_LITERAL(15, 197, 6),
QT_MOC_LITERAL(16, 204, 20),
QT_MOC_LITERAL(17, 225, 11),
QT_MOC_LITERAL(18, 237, 12),
QT_MOC_LITERAL(19, 250, 12),
QT_MOC_LITERAL(20, 263, 16),
QT_MOC_LITERAL(21, 280, 15)
    },
    "ImageWidget\0attributesChanged\0\0devName\0"
    "QHash<QString,Tango::DeviceAttribute>\0"
    "attributeChanged\0Tango::DeviceAttribute\0"
    "attribute\0play\0pause\0close\0ImageWidget*\0"
    "saveImage\0setAttributes\0changeAttribute\0"
    "camera\0showPropertiesDialog\0contextPlay\0"
    "contextPause\0contextClose\0contextSaveImage\0"
    "showContextMenu"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   84,    2, 0x06 /* Public */,
       5,    2,   89,    2, 0x06 /* Public */,
       8,    1,   94,    2, 0x06 /* Public */,
       9,    1,   97,    2, 0x06 /* Public */,
      10,    1,  100,    2, 0x06 /* Public */,
      12,    1,  103,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    2,  106,    2, 0x0a /* Public */,
      14,    2,  111,    2, 0x0a /* Public */,
      16,    0,  116,    2, 0x0a /* Public */,
      17,    0,  117,    2, 0x0a /* Public */,
      18,    0,  118,    2, 0x0a /* Public */,
      19,    0,  119,    2, 0x0a /* Public */,
      20,    0,  120,    2, 0x0a /* Public */,
      21,    1,  121,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 6,    3,    7,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 11,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 6,   15,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,

       0        // eod
};

void ImageWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageWidget *_t = static_cast<ImageWidget *>(_o);
        switch (_id) {
        case 0: _t->attributesChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QHash<QString,Tango::DeviceAttribute>(*)>(_a[2]))); break;
        case 1: _t->attributeChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< Tango::DeviceAttribute(*)>(_a[2]))); break;
        case 2: _t->play((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->pause((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->close((*reinterpret_cast< ImageWidget*(*)>(_a[1]))); break;
        case 5: _t->saveImage((*reinterpret_cast< ImageWidget*(*)>(_a[1]))); break;
        case 6: _t->setAttributes((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QHash<QString,Tango::DeviceAttribute>(*)>(_a[2]))); break;
        case 7: _t->changeAttribute((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< Tango::DeviceAttribute(*)>(_a[2]))); break;
        case 8: _t->showPropertiesDialog(); break;
        case 9: _t->contextPlay(); break;
        case 10: _t->contextPause(); break;
        case 11: _t->contextClose(); break;
        case 12: _t->contextSaveImage(); break;
        case 13: _t->showContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ImageWidget* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ImageWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ImageWidget::*_t)(QString , QHash<QString,Tango::DeviceAttribute> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageWidget::attributesChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (ImageWidget::*_t)(QString , Tango::DeviceAttribute );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageWidget::attributeChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (ImageWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageWidget::play)) {
                *result = 2;
            }
        }
        {
            typedef void (ImageWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageWidget::pause)) {
                *result = 3;
            }
        }
        {
            typedef void (ImageWidget::*_t)(ImageWidget * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageWidget::close)) {
                *result = 4;
            }
        }
        {
            typedef void (ImageWidget::*_t)(ImageWidget * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImageWidget::saveImage)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject ImageWidget::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_ImageWidget.data,
      qt_meta_data_ImageWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *ImageWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImageWidget.stringdata))
        return static_cast<void*>(const_cast< ImageWidget*>(this));
    return QFrame::qt_metacast(_clname);
}

int ImageWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void ImageWidget::attributesChanged(QString _t1, QHash<QString,Tango::DeviceAttribute> _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ImageWidget::attributeChanged(QString _t1, Tango::DeviceAttribute _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ImageWidget::play(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ImageWidget::pause(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ImageWidget::close(ImageWidget * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ImageWidget::saveImage(ImageWidget * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
