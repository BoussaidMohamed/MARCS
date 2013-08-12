/****************************************************************************
** Meta object code from reading C++ file 'FlightData.h'
**
** Created: Wed 7. Aug 12:01:47 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MARCS/FlightData.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FlightData.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FlightData[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      60,   12,   11,   11, 0x0a,
     110,  101,   11,   11, 0x0a,
     138,  127,   11,   11, 0x0a,
     167,  157,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FlightData[] = {
    "FlightData\0\0p_dLatitude,p_dLongitude,p_dAltitude,p_dHeading\0"
    "setPosition(double,double,double,double)\0"
    "p_dSpeed\0setSpeed(double)\0p_dHeading\0"
    "setHeading(double)\0p_dHeight\0"
    "setHeight(double)\0"
};

const QMetaObject FlightData::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_FlightData,
      qt_meta_data_FlightData, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FlightData::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FlightData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FlightData::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FlightData))
        return static_cast<void*>(const_cast< FlightData*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int FlightData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setPosition((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 1: setSpeed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: setHeading((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: setHeight((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
