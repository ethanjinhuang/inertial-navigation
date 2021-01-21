/****************************************************************************
** Meta object code from reading C++ file 'QRibbon.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Inertial_Navigation_with_QT/QRibbon/QRibbon.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QRibbon.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QRibbon_t {
    QByteArrayData data[11];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QRibbon_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QRibbon_t qt_meta_stringdata_QRibbon = {
    {
QT_MOC_LITERAL(0, 0, 7), // "QRibbon"
QT_MOC_LITERAL(1, 8, 14), // "setWindowTitle"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5), // "title"
QT_MOC_LITERAL(4, 30, 15), // "toggleMaximized"
QT_MOC_LITERAL(5, 46, 9), // "expandTab"
QT_MOC_LITERAL(6, 56, 7), // "hideTab"
QT_MOC_LITERAL(7, 64, 17), // "onHideTabFinished"
QT_MOC_LITERAL(8, 82, 12), // "onTabChanged"
QT_MOC_LITERAL(9, 95, 11), // "onLostFocus"
QT_MOC_LITERAL(10, 107, 8) // "clickTab"

    },
    "QRibbon\0setWindowTitle\0\0title\0"
    "toggleMaximized\0expandTab\0hideTab\0"
    "onHideTabFinished\0onTabChanged\0"
    "onLostFocus\0clickTab"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QRibbon[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       4,    0,   57,    2, 0x0a /* Public */,
       5,    0,   58,    2, 0x08 /* Private */,
       6,    0,   59,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QRibbon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QRibbon *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setWindowTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->toggleMaximized(); break;
        case 2: _t->expandTab(); break;
        case 3: _t->hideTab(); break;
        case 4: _t->onHideTabFinished(); break;
        case 5: _t->onTabChanged(); break;
        case 6: _t->onLostFocus(); break;
        case 7: _t->clickTab(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QRibbon::staticMetaObject = { {
    QMetaObject::SuperData::link<QMenuBar::staticMetaObject>(),
    qt_meta_stringdata_QRibbon.data,
    qt_meta_data_QRibbon,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QRibbon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QRibbon::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QRibbon.stringdata0))
        return static_cast<void*>(this);
    return QMenuBar::qt_metacast(_clname);
}

int QRibbon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenuBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
