/****************************************************************************
** Meta object code from reading C++ file 'CommunicationControl.h'
**
** Created: Mon 9. Sep 12:19:13 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MARCS/CommunicationControl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CommunicationControl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CommunicationControl[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      24,       // signalCount

 // signals: signature, parameters, type, tag, flags
      32,   22,   21,   21, 0x05,
      74,   22,   21,   21, 0x05,
     112,   21,   21,   21, 0x05,
     123,   21,   21,   21, 0x05,
     136,   21,   21,   21, 0x05,
     147,   21,   21,   21, 0x05,
     158,   21,   21,   21, 0x05,
     170,   21,   21,   21, 0x05,
     194,  183,   21,   21, 0x05,
     247,  215,   21,   21, 0x05,
     319,  279,   21,   21, 0x05,
     366,  353,   21,   21, 0x05,
     397,  388,   21,   21, 0x05,
     418,  388,   21,   21, 0x05,
     447,  438,   21,   21, 0x05,
     471,  462,   21,   21, 0x05,
     493,  462,   21,   21, 0x05,
     519,  514,   21,   21, 0x05,
     573,  537,   21,   21, 0x05,
     666,  614,   21,   21, 0x05,
     724,  715,   21,   21, 0x05,
     750,  741,   21,   21, 0x05,
     770,   21,   21,   21, 0x05,
     789,   21,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
     825,  807,   21,   21, 0x0a,
     875,  863,   21,   21, 0x0a,
     904,   21,   21,   21, 0x0a,
     915,   21,   21,   21, 0x0a,
     932,   21,   21,   21, 0x0a,
     959,   21,   21,   21, 0x0a,
     978,   21,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CommunicationControl[] = {
    "CommunicationControl\0\0x,y,z,yaw\0"
    "sendWaypoint(double,double,double,double)\0"
    "sendMove(double,double,double,double)\0"
    "sendGoTo()\0sendLaunch()\0sendLand()\0"
    "sendHome()\0sendMotOn()\0sendMotOff()\0"
    "dataToPoll\0poll(unsigned short)\0"
    "dist,validLatLong,validAltitude\0"
    "validWaypoint(double,bool,bool)\0"
    "p_cWaypointNumber,p_nDistance,p_cStatus\0"
    "waypointNAVInfo(char,short,short)\0"
    "p_iSatellite\0updateGPSQuality(int)\0"
    "p_dValue\0batteryLevel(double)\0"
    "updateStatus(short)\0p_cValue\0"
    "inFlight(char)\0p_pValue\0updateHeading(double)\0"
    "updateHeight(double)\0data\0displayAck(char*)\0"
    "latitude,longitude,altitude,heading\0"
    "geolocation(double,double,double,double)\0"
    "yaw,pitch,roll,thrust,serial,GPSHeightControl,valid\0"
    "rcData(short,short,short,short,short,short,char)\0"
    "p_bValue\0XBeeStatus(bool)\0p_dSpeed\0"
    "updateSpeed(double)\0XBeeDisconnected()\0"
    "XBeeReconnected()\0xDest,yDest,zDest\0"
    "controlWaypoint(double,double,double)\0"
    "data,length\0computePolledData(char*,int)\0"
    "pollData()\0autonomousMode()\0"
    "computerAidedControlMode()\0"
    "pollDataTimedOut()\0retryConnection()\0"
};

const QMetaObject CommunicationControl::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CommunicationControl,
      qt_meta_data_CommunicationControl, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CommunicationControl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CommunicationControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CommunicationControl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CommunicationControl))
        return static_cast<void*>(const_cast< CommunicationControl*>(this));
    return QObject::qt_metacast(_clname);
}

int CommunicationControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendWaypoint((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 1: sendMove((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 2: sendGoTo(); break;
        case 3: sendLaunch(); break;
        case 4: sendLand(); break;
        case 5: sendHome(); break;
        case 6: sendMotOn(); break;
        case 7: sendMotOff(); break;
        case 8: poll((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 9: validWaypoint((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 10: waypointNAVInfo((*reinterpret_cast< char(*)>(_a[1])),(*reinterpret_cast< short(*)>(_a[2])),(*reinterpret_cast< short(*)>(_a[3]))); break;
        case 11: updateGPSQuality((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: batteryLevel((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: updateStatus((*reinterpret_cast< short(*)>(_a[1]))); break;
        case 14: inFlight((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 15: updateHeading((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: updateHeight((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: displayAck((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 18: geolocation((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 19: rcData((*reinterpret_cast< short(*)>(_a[1])),(*reinterpret_cast< short(*)>(_a[2])),(*reinterpret_cast< short(*)>(_a[3])),(*reinterpret_cast< short(*)>(_a[4])),(*reinterpret_cast< short(*)>(_a[5])),(*reinterpret_cast< short(*)>(_a[6])),(*reinterpret_cast< char(*)>(_a[7]))); break;
        case 20: XBeeStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: updateSpeed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 22: XBeeDisconnected(); break;
        case 23: XBeeReconnected(); break;
        case 24: controlWaypoint((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 25: computePolledData((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 26: pollData(); break;
        case 27: autonomousMode(); break;
        case 28: computerAidedControlMode(); break;
        case 29: pollDataTimedOut(); break;
        case 30: retryConnection(); break;
        default: ;
        }
        _id -= 31;
    }
    return _id;
}

// SIGNAL 0
void CommunicationControl::sendWaypoint(double _t1, double _t2, double _t3, double _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CommunicationControl::sendMove(double _t1, double _t2, double _t3, double _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CommunicationControl::sendGoTo()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void CommunicationControl::sendLaunch()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void CommunicationControl::sendLand()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void CommunicationControl::sendHome()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void CommunicationControl::sendMotOn()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void CommunicationControl::sendMotOff()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void CommunicationControl::poll(unsigned short _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void CommunicationControl::validWaypoint(double _t1, bool _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void CommunicationControl::waypointNAVInfo(char _t1, short _t2, short _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void CommunicationControl::updateGPSQuality(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void CommunicationControl::batteryLevel(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void CommunicationControl::updateStatus(short _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void CommunicationControl::inFlight(char _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void CommunicationControl::updateHeading(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void CommunicationControl::updateHeight(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void CommunicationControl::displayAck(char * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void CommunicationControl::geolocation(double _t1, double _t2, double _t3, double _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void CommunicationControl::rcData(short _t1, short _t2, short _t3, short _t4, short _t5, short _t6, char _t7)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void CommunicationControl::XBeeStatus(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void CommunicationControl::updateSpeed(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void CommunicationControl::XBeeDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 22, 0);
}

// SIGNAL 23
void CommunicationControl::XBeeReconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 23, 0);
}
QT_END_MOC_NAMESPACE
