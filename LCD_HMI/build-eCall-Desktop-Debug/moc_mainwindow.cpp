/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../eCall/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[214];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "updatePdistance"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "updatePfuel"
QT_MOC_LITERAL(4, 40, 15), // "updatePavgspeed"
QT_MOC_LITERAL(5, 56, 11), // "updateReady"
QT_MOC_LITERAL(6, 68, 10), // "updateTime"
QT_MOC_LITERAL(7, 79, 10), // "updateDate"
QT_MOC_LITERAL(8, 90, 9), // "updateInc"
QT_MOC_LITERAL(9, 100, 9), // "updateDec"
QT_MOC_LITERAL(10, 110, 9), // "handleSOS"
QT_MOC_LITERAL(11, 120, 9), // "updateABS"
QT_MOC_LITERAL(12, 130, 9), // "updateECO"
QT_MOC_LITERAL(13, 140, 11), // "updateSmart"
QT_MOC_LITERAL(14, 152, 11), // "updateSport"
QT_MOC_LITERAL(15, 164, 5), // "delay"
QT_MOC_LITERAL(16, 170, 11), // "millseconds"
QT_MOC_LITERAL(17, 182, 11), // "processData"
QT_MOC_LITERAL(18, 194, 4), // "data"
QT_MOC_LITERAL(19, 199, 14) // "onDataReceived"

    },
    "MainWindow\0updatePdistance\0\0updatePfuel\0"
    "updatePavgspeed\0updateReady\0updateTime\0"
    "updateDate\0updateInc\0updateDec\0handleSOS\0"
    "updateABS\0updateECO\0updateSmart\0"
    "updateSport\0delay\0millseconds\0processData\0"
    "data\0onDataReceived"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    0,   99,    2, 0x08 /* Private */,
       8,    0,  100,    2, 0x08 /* Private */,
       9,    0,  101,    2, 0x08 /* Private */,
      10,    0,  102,    2, 0x08 /* Private */,
      11,    0,  103,    2, 0x08 /* Private */,
      12,    0,  104,    2, 0x08 /* Private */,
      13,    0,  105,    2, 0x08 /* Private */,
      14,    0,  106,    2, 0x08 /* Private */,
      15,    1,  107,    2, 0x08 /* Private */,
      17,    1,  110,    2, 0x08 /* Private */,
      19,    1,  113,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::QByteArray,   18,
    QMetaType::Void, QMetaType::QByteArray,   18,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updatePdistance(); break;
        case 1: _t->updatePfuel(); break;
        case 2: _t->updatePavgspeed(); break;
        case 3: _t->updateReady(); break;
        case 4: _t->updateTime(); break;
        case 5: _t->updateDate(); break;
        case 6: _t->updateInc(); break;
        case 7: _t->updateDec(); break;
        case 8: _t->handleSOS(); break;
        case 9: _t->updateABS(); break;
        case 10: _t->updateECO(); break;
        case 11: _t->updateSmart(); break;
        case 12: _t->updateSport(); break;
        case 13: _t->delay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->processData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 15: _t->onDataReceived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
