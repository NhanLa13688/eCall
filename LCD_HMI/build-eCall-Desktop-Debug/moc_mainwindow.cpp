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
    QByteArrayData data[21];
    char stringdata0[229];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "updatePbattery"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "updatePdistance"
QT_MOC_LITERAL(4, 43, 11), // "updatePfuel"
QT_MOC_LITERAL(5, 55, 15), // "updatePavgspeed"
QT_MOC_LITERAL(6, 71, 11), // "updateReady"
QT_MOC_LITERAL(7, 83, 10), // "updateTime"
QT_MOC_LITERAL(8, 94, 10), // "updateDate"
QT_MOC_LITERAL(9, 105, 9), // "updateInc"
QT_MOC_LITERAL(10, 115, 9), // "updateDec"
QT_MOC_LITERAL(11, 125, 9), // "handleSOS"
QT_MOC_LITERAL(12, 135, 9), // "updateABS"
QT_MOC_LITERAL(13, 145, 9), // "updateECO"
QT_MOC_LITERAL(14, 155, 11), // "updateSmart"
QT_MOC_LITERAL(15, 167, 11), // "updateSport"
QT_MOC_LITERAL(16, 179, 5), // "delay"
QT_MOC_LITERAL(17, 185, 11), // "millseconds"
QT_MOC_LITERAL(18, 197, 11), // "processData"
QT_MOC_LITERAL(19, 209, 4), // "data"
QT_MOC_LITERAL(20, 214, 14) // "onDataReceived"

    },
    "MainWindow\0updatePbattery\0\0updatePdistance\0"
    "updatePfuel\0updatePavgspeed\0updateReady\0"
    "updateTime\0updateDate\0updateInc\0"
    "updateDec\0handleSOS\0updateABS\0updateECO\0"
    "updateSmart\0updateSport\0delay\0millseconds\0"
    "processData\0data\0onDataReceived"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    0,  108,    2, 0x08 /* Private */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    0,  111,    2, 0x08 /* Private */,
      15,    0,  112,    2, 0x08 /* Private */,
      16,    1,  113,    2, 0x08 /* Private */,
      18,    1,  116,    2, 0x08 /* Private */,
      20,    1,  119,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::QByteArray,   19,
    QMetaType::Void, QMetaType::QByteArray,   19,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updatePbattery(); break;
        case 1: _t->updatePdistance(); break;
        case 2: _t->updatePfuel(); break;
        case 3: _t->updatePavgspeed(); break;
        case 4: _t->updateReady(); break;
        case 5: _t->updateTime(); break;
        case 6: _t->updateDate(); break;
        case 7: _t->updateInc(); break;
        case 8: _t->updateDec(); break;
        case 9: _t->handleSOS(); break;
        case 10: _t->updateABS(); break;
        case 11: _t->updateECO(); break;
        case 12: _t->updateSmart(); break;
        case 13: _t->updateSport(); break;
        case 14: _t->delay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->processData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 16: _t->onDataReceived((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
