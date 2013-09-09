/****************************************************************************
** Meta object code from reading C++ file 'MissionControl.h'
**
** Created: Thu 5. Sep 15:46:18 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MARCS/MissionControl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MissionControl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MissionControl[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      41,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      17,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   16,   15,   15, 0x05,
      46,   16,   15,   15, 0x05,
      60,   16,   15,   15, 0x05,
      79,   16,   15,   15, 0x05,
     100,   16,   15,   15, 0x05,
     129,   15,   15,   15, 0x05,
     146,   15,   15,   15, 0x05,
     166,   15,   15,   15, 0x05,
     188,   15,   15,   15, 0x05,
     229,  216,   15,   15, 0x05,
     277,  267,   15,   15, 0x05,
     311,   15,   15,   15, 0x05,
     324,   15,   15,   15, 0x05,
     340,   15,   15,   15, 0x05,
     358,   15,   15,   15, 0x05,
     374,   15,   15,   15, 0x05,
     455,  395,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
     501,   16,   15,   15, 0x0a,
     523,   16,   15,   15, 0x0a,
     538,   15,   15,   15, 0x0a,
     557,   16,   15,   15, 0x0a,
     574,   16,   15,   15, 0x0a,
     600,   15,   15,   15, 0x0a,
     620,   15,  615,   15, 0x0a,
     675,  635,   15,   15, 0x0a,
     710,  703,   15,   15, 0x0a,
     729,   15,   15,   15, 0x0a,
     748,   15,   15,   15, 0x0a,
     765,   15,   15,   15, 0x0a,
     826,  783,   15,   15, 0x0a,
     933,  860,   15,   15, 0x0a,
     991,  982,   15,   15, 0x0a,
    1006,   15,   15,   15, 0x0a,
    1020,   15,   15,   15, 0x0a,
    1035,   15,   15,   15, 0x0a,
    1046,   15,   15,   15, 0x0a,
    1058,   15,   15,   15, 0x0a,
    1069,   15,   15,   15, 0x0a,
    1081,   15,   15,   15, 0x0a,
    1086,   15,   15,   15, 0x0a,
    1093,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MissionControl[] = {
    "MissionControl\0\0p_pValue\0batteryLevel(double)\0"
    "GPSLevel(int)\0digression(double)\0"
    "XBeeConnection(bool)\0radiocommandConnection(bool)\0"
    "directXProblem()\0controllerProblem()\0"
    "controllerConnected()\0resetWaypointNotification()\0"
    "x,y,z,number\0waypoint(double,double,double,double)\0"
    "x,y,z,yaw\0move(double,double,double,double)\0"
    "sendLaunch()\0endFlightPlan()\0"
    "waypointReached()\0RCDataChanged()\0"
    "flightPlanLaunched()\0"
    "p_bBattery,p_bGPS,p_bXBee,p_bStatus,p_bFlightPlan,p_bEngine\0"
    "cannotLaunchFP(bool,bool,bool,bool,bool,bool)\0"
    "updateBattery(double)\0updateGPS(int)\0"
    "updateDigression()\0updateXBee(bool)\0"
    "updateRadiocommand(short)\0sendWaypoint()\0"
    "bool\0nextWaypoint()\0"
    "p_cWaypointNumber,p_nDistance,p_cStatus\0"
    "updateNAV(char,short,short)\0m_pAck\0"
    "acknowledge(char*)\0launchFlightPlan()\0"
    "stopFlightPlan()\0pauseFlightPlan()\0"
    "p_cWaypointNumber,p_nDistance,p_nNavStatus\0"
    "updateWayStatus(char,short,short)\0"
    "p_nYaw,p_nPitch,p_nRoll,p_nThrust,p_nSerial,p_nGPSHeightControl,p_cVal"
    "id\0"
    "rcData(short,short,short,short,short,short,char)\0"
    "p_cValue\0inFlight(char)\0moveForward()\0"
    "moveBackward()\0moveLeft()\0moveRight()\0"
    "turnLeft()\0turnRight()\0up()\0down()\0"
    "addMark()\0"
};

const QMetaObject MissionControl::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MissionControl,
      qt_meta_data_MissionControl, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MissionControl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MissionControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MissionControl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MissionControl))
        return static_cast<void*>(const_cast< MissionControl*>(this));
    return QObject::qt_metacast(_clname);
}

int MissionControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: batteryLevel((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: GPSLevel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: digression((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: XBeeConnection((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: radiocommandConnection((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: directXProblem(); break;
        case 6: controllerProblem(); break;
        case 7: controllerConnected(); break;
        case 8: resetWaypointNotification(); break;
        case 9: waypoint((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 10: move((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 11: sendLaunch(); break;
        case 12: endFlightPlan(); break;
        case 13: waypointReached(); break;
        case 14: RCDataChanged(); break;
        case 15: flightPlanLaunched(); break;
        case 16: cannotLaunchFP((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6]))); break;
        case 17: updateBattery((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: updateGPS((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: updateDigression(); break;
        case 20: updateXBee((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: updateRadiocommand((*reinterpret_cast< short(*)>(_a[1]))); break;
        case 22: sendWaypoint(); break;
        case 23: { bool _r = nextWaypoint();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 24: updateNAV((*reinterpret_cast< char(*)>(_a[1])),(*reinterpret_cast< short(*)>(_a[2])),(*reinterpret_cast< short(*)>(_a[3]))); break;
        case 25: acknowledge((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 26: launchFlightPlan(); break;
        case 27: stopFlightPlan(); break;
        case 28: pauseFlightPlan(); break;
        case 29: updateWayStatus((*reinterpret_cast< char(*)>(_a[1])),(*reinterpret_cast< short(*)>(_a[2])),(*reinterpret_cast< short(*)>(_a[3]))); break;
        case 30: rcData((*reinterpret_cast< short(*)>(_a[1])),(*reinterpret_cast< short(*)>(_a[2])),(*reinterpret_cast< short(*)>(_a[3])),(*reinterpret_cast< short(*)>(_a[4])),(*reinterpret_cast< short(*)>(_a[5])),(*reinterpret_cast< short(*)>(_a[6])),(*reinterpret_cast< char(*)>(_a[7]))); break;
        case 31: inFlight((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 32: moveForward(); break;
        case 33: moveBackward(); break;
        case 34: moveLeft(); break;
        case 35: moveRight(); break;
        case 36: turnLeft(); break;
        case 37: turnRight(); break;
        case 38: up(); break;
        case 39: down(); break;
        case 40: addMark(); break;
        default: ;
        }
        _id -= 41;
    }
    return _id;
}

// SIGNAL 0
void MissionControl::batteryLevel(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MissionControl::GPSLevel(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MissionControl::digression(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MissionControl::XBeeConnection(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MissionControl::radiocommandConnection(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MissionControl::directXProblem()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void MissionControl::controllerProblem()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void MissionControl::controllerConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void MissionControl::resetWaypointNotification()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void MissionControl::waypoint(double _t1, double _t2, double _t3, double _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void MissionControl::move(double _t1, double _t2, double _t3, double _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void MissionControl::sendLaunch()
{
    QMetaObject::activate(this, &staticMetaObject, 11, 0);
}

// SIGNAL 12
void MissionControl::endFlightPlan()
{
    QMetaObject::activate(this, &staticMetaObject, 12, 0);
}

// SIGNAL 13
void MissionControl::waypointReached()
{
    QMetaObject::activate(this, &staticMetaObject, 13, 0);
}

// SIGNAL 14
void MissionControl::RCDataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 14, 0);
}

// SIGNAL 15
void MissionControl::flightPlanLaunched()
{
    QMetaObject::activate(this, &staticMetaObject, 15, 0);
}

// SIGNAL 16
void MissionControl::cannotLaunchFP(bool _t1, bool _t2, bool _t3, bool _t4, bool _t5, bool _t6)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}
QT_END_MOC_NAMESPACE
