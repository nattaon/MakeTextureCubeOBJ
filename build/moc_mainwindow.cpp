/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[418];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 28), // "ButtonOpenSourceImagePressed"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 28), // "ButtonOpenTargetImagePressed"
QT_MOC_LITERAL(4, 70, 19), // "ButtonRotCCWPressed"
QT_MOC_LITERAL(5, 90, 18), // "ButtonRotCWPressed"
QT_MOC_LITERAL(6, 109, 25), // "ButtonFlipVerticalPressed"
QT_MOC_LITERAL(7, 135, 27), // "ButtonFlipHorizontalPressed"
QT_MOC_LITERAL(8, 163, 24), // "ButtonRemovePointPressed"
QT_MOC_LITERAL(9, 188, 26), // "ButtonClearallPointPressed"
QT_MOC_LITERAL(10, 215, 21), // "ButtonNewImagePressed"
QT_MOC_LITERAL(11, 237, 22), // "ButtonSaveImagePressed"
QT_MOC_LITERAL(12, 260, 33), // "ButtonPerspectiveTransformPre..."
QT_MOC_LITERAL(13, 294, 22), // "TreeSourcePointClicked"
QT_MOC_LITERAL(14, 317, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(15, 334, 19), // "current_select_item"
QT_MOC_LITERAL(16, 354, 24), // "PressedCombineTexturePNG"
QT_MOC_LITERAL(17, 379, 20), // "PressedCreateOBJ_MTL"
QT_MOC_LITERAL(18, 400, 17) // "PressedShowObject"

    },
    "MainWindow\0ButtonOpenSourceImagePressed\0"
    "\0ButtonOpenTargetImagePressed\0"
    "ButtonRotCCWPressed\0ButtonRotCWPressed\0"
    "ButtonFlipVerticalPressed\0"
    "ButtonFlipHorizontalPressed\0"
    "ButtonRemovePointPressed\0"
    "ButtonClearallPointPressed\0"
    "ButtonNewImagePressed\0ButtonSaveImagePressed\0"
    "ButtonPerspectiveTransformPressed\0"
    "TreeSourcePointClicked\0QTreeWidgetItem*\0"
    "current_select_item\0PressedCombineTexturePNG\0"
    "PressedCreateOBJ_MTL\0PressedShowObject"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    0,   99,    2, 0x08 /* Private */,
      13,    1,  100,    2, 0x08 /* Private */,
      16,    0,  103,    2, 0x08 /* Private */,
      17,    0,  104,    2, 0x08 /* Private */,
      18,    0,  105,    2, 0x08 /* Private */,

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
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ButtonOpenSourceImagePressed(); break;
        case 1: _t->ButtonOpenTargetImagePressed(); break;
        case 2: _t->ButtonRotCCWPressed(); break;
        case 3: _t->ButtonRotCWPressed(); break;
        case 4: _t->ButtonFlipVerticalPressed(); break;
        case 5: _t->ButtonFlipHorizontalPressed(); break;
        case 6: _t->ButtonRemovePointPressed(); break;
        case 7: _t->ButtonClearallPointPressed(); break;
        case 8: _t->ButtonNewImagePressed(); break;
        case 9: _t->ButtonSaveImagePressed(); break;
        case 10: _t->ButtonPerspectiveTransformPressed(); break;
        case 11: _t->TreeSourcePointClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 12: _t->PressedCombineTexturePNG(); break;
        case 13: _t->PressedCreateOBJ_MTL(); break;
        case 14: _t->PressedShowObject(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
