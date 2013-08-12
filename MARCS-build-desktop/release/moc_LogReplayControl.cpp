/****************************************************************************
** Meta object code from reading C++ file 'LogReplayControl.h'
**
** Created: Fri 9. Aug 16:11:57 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MARCS/LogReplayControl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LogReplayControl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LogReplayControl[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      27,   18,   17,   17, 0x05,
      85,   49,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
     126,   17,   17,   17, 0x0a,
     134,   17,   17,   17, 0x0a,
     142,   17,   17,   17, 0x0a,
     149,   17,   17,   17, 0x0a,
     160,   17,   17,   17, 0x0a,
     170,   17,   17,   17, 0x0a,
     179,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LogReplayControl[] = {
    "LogReplayControl\0\0p_pValue\0"
    "updateHeading(double)\0"
    "latitude,longitude,altitude,heading\0"
    "geolocation(double,double,double,double)\0"
    "start()\0pause()\0stop()\0backward()\0"
    "forward()\0replay()\0openLog()\0"
};

const QMetaObject LogReplayControl::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LogReplayControl,
      qt_meta_data_LogReplayControl, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LogReplayControl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LogReplayControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LogReplayControl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LogReplayControl))
        return static_cast<void*>(const_cast< LogReplayControl*>(this));
    return QObject::qt_metacast(_clname);
}

int LogReplayControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateHeading((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: geolocation((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 2: start(); break;
        case 3: pause(); break;
        case 4: stop(); break;
        case 5: backward(); break;
        case 6: forward(); break;
        case 7: replay(); break;
        case 8: openLog(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void LogReplayControl::updateHeading(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LogReplayControl::geolocation(double _t1, double _t2, double _t3, double _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
