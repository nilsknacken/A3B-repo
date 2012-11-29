/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created: Thu Nov 29 15:31:36 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../local/gui/MainWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      39,   11,   11,   11, 0x08,
      69,   11,   11,   11, 0x08,
      95,   11,   11,   11, 0x08,
     125,   11,   11,   11, 0x08,
     155,   11,   11,   11, 0x08,
     187,   11,   11,   11, 0x08,
     218,   11,   11,   11, 0x08,
     249,   11,   11,   11, 0x08,
     280,   11,   11,   11, 0x08,
     313,   11,   11,   11, 0x08,
     346,   11,   11,   11, 0x08,
     378,   11,   11,   11, 0x08,
     410,   11,   11,   11, 0x08,
     442,   11,   11,   11, 0x08,
     472,   11,   11,   11, 0x08,
     504,   11,   11,   11, 0x08,
     536,   11,   11,   11, 0x08,
     566,   11,   11,   11, 0x08,
     598,   11,   11,   11, 0x08,
     632,   11,   11,   11, 0x08,
     662,   11,   11,   11, 0x08,
     692,   11,   11,   11, 0x08,
     722,   11,   11,   11, 0x08,
     771,  760,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_actionAbout_triggered()\0"
    "on_actionSettings_triggered()\0"
    "on_actionQuit_triggered()\0"
    "on_pushButtonP1next_clicked()\0"
    "on_pushButtonP1back_clicked()\0"
    "on_pushButtonP1search_clicked()\0"
    "on_pushButtonP1S_Car_clicked()\0"
    "on_pushButtonP1M_Car_clicked()\0"
    "on_pushButtonP1L_Car_clicked()\0"
    "on_pushButtonP1S_Truck_clicked()\0"
    "on_pushButtonP1L_Truck_clicked()\0"
    "on_pushButtonP2search_clicked()\0"
    "on_pushButtonP2delete_clicked()\0"
    "on_pushButtonP2change_clicked()\0"
    "on_pushButtonP2show_clicked()\0"
    "on_pushButtonP2bok_nr_clicked()\0"
    "on_pushButtonP2reg_nr_clicked()\0"
    "on_pushButtonP2name_clicked()\0"
    "on_pushButtonP2per_nr_clicked()\0"
    "on_pushButtonP2phone_nr_clicked()\0"
    "on_pushButtonP2date_clicked()\0"
    "on_pushButtonP4next_clicked()\0"
    "on_pushButtonP4back_clicked()\0"
    "on_pushButtonSearchP5search_clicked()\0"
    "row,column\0on_tableWidgetP5_cellClicked(int,int)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_actionAbout_triggered(); break;
        case 1: _t->on_actionSettings_triggered(); break;
        case 2: _t->on_actionQuit_triggered(); break;
        case 3: _t->on_pushButtonP1next_clicked(); break;
        case 4: _t->on_pushButtonP1back_clicked(); break;
        case 5: _t->on_pushButtonP1search_clicked(); break;
        case 6: _t->on_pushButtonP1S_Car_clicked(); break;
        case 7: _t->on_pushButtonP1M_Car_clicked(); break;
        case 8: _t->on_pushButtonP1L_Car_clicked(); break;
        case 9: _t->on_pushButtonP1S_Truck_clicked(); break;
        case 10: _t->on_pushButtonP1L_Truck_clicked(); break;
        case 11: _t->on_pushButtonP2search_clicked(); break;
        case 12: _t->on_pushButtonP2delete_clicked(); break;
        case 13: _t->on_pushButtonP2change_clicked(); break;
        case 14: _t->on_pushButtonP2show_clicked(); break;
        case 15: _t->on_pushButtonP2bok_nr_clicked(); break;
        case 16: _t->on_pushButtonP2reg_nr_clicked(); break;
        case 17: _t->on_pushButtonP2name_clicked(); break;
        case 18: _t->on_pushButtonP2per_nr_clicked(); break;
        case 19: _t->on_pushButtonP2phone_nr_clicked(); break;
        case 20: _t->on_pushButtonP2date_clicked(); break;
        case 21: _t->on_pushButtonP4next_clicked(); break;
        case 22: _t->on_pushButtonP4back_clicked(); break;
        case 23: _t->on_pushButtonSearchP5search_clicked(); break;
        case 24: _t->on_tableWidgetP5_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
