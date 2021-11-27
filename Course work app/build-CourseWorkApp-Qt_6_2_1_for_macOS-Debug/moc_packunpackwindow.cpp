/****************************************************************************
** Meta object code from reading C++ file 'packunpackwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../CourseWorkApp/packunpackwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'packunpackwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PackUnpackWindow_t {
    const uint offsetsAndSize[12];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_PackUnpackWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_PackUnpackWindow_t qt_meta_stringdata_PackUnpackWindow = {
    {
QT_MOC_LITERAL(0, 16), // "PackUnpackWindow"
QT_MOC_LITERAL(17, 38), // "on_PackUnpackWindow_windowTit..."
QT_MOC_LITERAL(56, 0), // ""
QT_MOC_LITERAL(57, 5), // "title"
QT_MOC_LITERAL(63, 20), // "on_btnAction_clicked"
QT_MOC_LITERAL(84, 24) // "on_btnChoosePath_clicked"

    },
    "PackUnpackWindow\0"
    "on_PackUnpackWindow_windowTitleChanged\0"
    "\0title\0on_btnAction_clicked\0"
    "on_btnChoosePath_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PackUnpackWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x08,    1 /* Private */,
       4,    0,   35,    2, 0x08,    3 /* Private */,
       5,    0,   36,    2, 0x08,    4 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PackUnpackWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PackUnpackWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_PackUnpackWindow_windowTitleChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_btnAction_clicked(); break;
        case 2: _t->on_btnChoosePath_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject PackUnpackWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_PackUnpackWindow.offsetsAndSize,
    qt_meta_data_PackUnpackWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_PackUnpackWindow_t
, QtPrivate::TypeAndForceComplete<PackUnpackWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *PackUnpackWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PackUnpackWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PackUnpackWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PackUnpackWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
