/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../eCallV2/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[259];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 11), // "updateSpeed"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 14), // "updatePbattery"
QT_MOC_LITERAL(4, 39, 15), // "updatePdistance"
QT_MOC_LITERAL(5, 55, 11), // "updatePfuel"
QT_MOC_LITERAL(6, 67, 15), // "updatePavgspeed"
QT_MOC_LITERAL(7, 83, 11), // "updateReady"
QT_MOC_LITERAL(8, 95, 10), // "updateTime"
QT_MOC_LITERAL(9, 106, 10), // "updateDate"
QT_MOC_LITERAL(10, 117, 9), // "updateInc"
QT_MOC_LITERAL(11, 127, 9), // "updateDec"
QT_MOC_LITERAL(12, 137, 9), // "handleSOS"
QT_MOC_LITERAL(13, 147, 9), // "updateABS"
QT_MOC_LITERAL(14, 157, 9), // "updateECO"
QT_MOC_LITERAL(15, 167, 11), // "updateSmart"
QT_MOC_LITERAL(16, 179, 11), // "updateSport"
QT_MOC_LITERAL(17, 191, 11), // "resizeEvent"
QT_MOC_LITERAL(18, 203, 13), // "QResizeEvent*"
QT_MOC_LITERAL(19, 217, 5), // "event"
QT_MOC_LITERAL(20, 223, 5), // "delay"
QT_MOC_LITERAL(21, 229, 11), // "millseconds"
QT_MOC_LITERAL(22, 241, 17) // "changeButtonColor"

    },
    "MainWindow\0updateSpeed\0\0updatePbattery\0"
    "updatePdistance\0updatePfuel\0updatePavgspeed\0"
    "updateReady\0updateTime\0updateDate\0"
    "updateInc\0updateDec\0handleSOS\0updateABS\0"
    "updateECO\0updateSmart\0updateSport\0"
    "resizeEvent\0QResizeEvent*\0event\0delay\0"
    "millseconds\0changeButtonColor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x08 /* Private */,
       3,    0,  105,    2, 0x08 /* Private */,
       4,    0,  106,    2, 0x08 /* Private */,
       5,    0,  107,    2, 0x08 /* Private */,
       6,    0,  108,    2, 0x08 /* Private */,
       7,    0,  109,    2, 0x08 /* Private */,
       8,    0,  110,    2, 0x08 /* Private */,
       9,    0,  111,    2, 0x08 /* Private */,
      10,    0,  112,    2, 0x08 /* Private */,
      11,    0,  113,    2, 0x08 /* Private */,
      12,    0,  114,    2, 0x08 /* Private */,
      13,    0,  115,    2, 0x08 /* Private */,
      14,    0,  116,    2, 0x08 /* Private */,
      15,    0,  117,    2, 0x08 /* Private */,
      16,    0,  118,    2, 0x08 /* Private */,
      17,    1,  119,    2, 0x08 /* Private */,
      20,    1,  122,    2, 0x08 /* Private */,
      22,    0,  125,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateSpeed(); break;
        case 1: _t->updatePbattery(); break;
        case 2: _t->updatePdistance(); break;
        case 3: _t->updatePfuel(); break;
        case 4: _t->updatePavgspeed(); break;
        case 5: _t->updateReady(); break;
        case 6: _t->updateTime(); break;
        case 7: _t->updateDate(); break;
        case 8: _t->updateInc(); break;
        case 9: _t->updateDec(); break;
        case 10: _t->handleSOS(); break;
        case 11: _t->updateABS(); break;
        case 12: _t->updateECO(); break;
        case 13: _t->updateSmart(); break;
        case 14: _t->updateSport(); break;
        case 15: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 16: _t->delay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->changeButtonColor(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


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
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
