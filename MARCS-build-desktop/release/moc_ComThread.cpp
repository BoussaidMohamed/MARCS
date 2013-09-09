/****************************************************************************
** Meta object code from reading C++ file 'ComThread.h'
**
** Created: Thu 5. Sep 15:46:15 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MARCS/ComThread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ComThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ComThread[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   11,   10,   10, 0x05,
      49,   10,   10,   10, 0x05,
      68,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      99,   86,   10,   10, 0x0a,
     151,  141,   10,   10, 0x0a,
     189,   10,   10,   10, 0x0a,
     200,   10,   10,   10, 0x0a,
     213,   10,   10,   10, 0x0a,
     224,   10,   10,   10, 0x0a,
     235,   10,   10,   10, 0x0a,
     247,   10,   10,   10, 0x0a,
     272,  260,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ComThread[] = {
    "ComThread\0\0buffer,length\0"
    "dataReceived(char*,int)\0XBeeDisconnected()\0"
    "XBeeReconnected()\0x,y,z,number\0"
    "sendWaypoint(double,double,double,double)\0"
    "x,y,z,yaw\0sendMove(double,double,double,double)\0"
    "sendGoTo()\0sendLaunch()\0sendLand()\0"
    "sendHome()\0sendMotOn()\0sendMotOff()\0"
    "pDataToPoll\0poll(unsigned short)\0"
};

const QMetaObject ComThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ComThread,
      qt_meta_data_ComThread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ComThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ComThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ComThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ComThread))
        return static_cast<void*>(const_cast< ComThread*>(this));
    return QThread::qt_metacast(_clname);
}

int ComThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: dataReceived((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: XBeeDisconnected(); break;
        case 2: XBeeReconnected(); break;
        case 3: sendWaypoint((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 4: sendMove((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 5: sendGoTo(); break;
        case 6: sendLaunch(); break;
        case 7: sendLand(); break;
        case 8: sendHome(); break;
        case 9: sendMotOn(); break;
        case 10: sendMotOff(); break;
        case 11: poll((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void ComThread::dataReceived(char * _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ComThread::XBeeDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ComThread::XBeeReconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
