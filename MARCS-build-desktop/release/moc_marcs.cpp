/****************************************************************************
** Meta object code from reading C++ file 'marcs.h'
**
** Created: Wed 11. Sep 10:53:16 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MARCS/marcs.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'marcs.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MARCS[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      53,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,
      17,    6,    6,    6, 0x05,
      28,    6,    6,    6, 0x05,
      38,    6,    6,    6, 0x05,
      64,   48,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      98,    6,    6,    6, 0x0a,
     118,    6,    6,    6, 0x0a,
     138,    6,    6,    6, 0x0a,
     159,    6,    6,    6, 0x0a,
     172,    6,    6,    6, 0x0a,
     186,    6,    6,    6, 0x0a,
     197,    6,    6,    6, 0x0a,
     211,    6,    6,    6, 0x0a,
     234,  225,    6,    6, 0x0a,
     281,    6,    6,    6, 0x0a,
     296,    6,    6,    6, 0x0a,
     311,    6,    6,    6, 0x0a,
     322,    6,    6,    6, 0x0a,
     337,    6,    6,    6, 0x0a,
     359,  354,    6,    6, 0x0a,
     382,    6,    6,    6, 0x0a,
     402,    6,    6,    6, 0x0a,
     419,  413,    6,    6, 0x0a,
     444,    6,    6,    6, 0x0a,
     467,  458,    6,    6, 0x0a,
     488,    6,    6,    6, 0x0a,
     511,  501,    6,    6, 0x0a,
     561,  548,    6,    6, 0x0a,
     628,  622,    6,    6, 0x0a,
     659,  225,    6,    6, 0x0a,
     714,  622,    6,    6, 0x0a,
     748,  225,    6,    6, 0x0a,
     812,  802,    6,    6, 0x0a,
     830,    6,    6,    6, 0x0a,
     836,    6,    6,    6, 0x0a,
     853,    6,    6,    6, 0x0a,
     867,    6,    6,    6, 0x0a,
     885,  877,    6,    6, 0x0a,
     908,  899,    6,    6, 0x0a,
     927,    6,    6,    6, 0x0a,
     934,    6,    6,    6, 0x0a,
     948,    6,    6,    6, 0x0a,
     958,    6,    6,    6, 0x0a,
     966,    6,    6,    6, 0x08,
     992,    6,    6,    6, 0x08,
    1028,    6,    6,    6, 0x08,
    1071, 1065,    6,    6, 0x08,
    1121,    6,    6,    6, 0x08,
    1153, 1148,    6,    6, 0x08,
    1192,    6,    6,    6, 0x08,
    1219,    6,    6,    6, 0x08,
    1247,    6,    6,    6, 0x08,
    1280,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MARCS[] = {
    "MARCS\0\0clickOn()\0clickOff()\0takeOff()\0"
    "landRPA()\0lon,lat,alt,num\0"
    "next(double,double,double,double)\0"
    "openNewWindowMain()\0openNewWindowData()\0"
    "openNewWindowVideo()\0openNewMap()\0"
    "switchToMap()\0showList()\0openMission()\0"
    "saveMission()\0lon,lat,\0"
    "addPoint(qreal,qreal,GeoDataCoordinates::Unit)\0"
    "clearMission()\0editWaypoint()\0loadData()\0"
    "saveEditData()\0finishEditData()\0show\0"
    "showEditWaypoint(bool)\0showConnectDialog()\0"
    "validCom()\0event\0closeEvent(QCloseEvent*)\0"
    "startMotors()\0p_pValue\0batteryLevel(double)\0"
    "stopMotors()\0style,hdg\0"
    "createStyleRPA(GeoDataStyle*,double)\0"
    "hdg,lon,lat,\0"
    "createRpaMark(double,double,double,GeoDataCoordinates::Unit)\0"
    "style\0createStyleHome(GeoDataStyle*)\0"
    "createHomeMark(double,double,GeoDataCoordinates::Unit)\0"
    "createStyleAddMark(GeoDataStyle*)\0"
    "createAddMark(double,double,GeoDataCoordinates::Unit)\0"
    "p_dHeight\0setHeight(double)\0fly()\0"
    "XbeeDisconnect()\0XbeeConnect()\0stopFly()\0"
    "p_value\0GPSLevel(int)\0p_cValue\0"
    "updateMotors(char)\0goTo()\0setTableRPA()\0"
    "showLog()\0close()\0on_start_button_clicked()\0"
    "on_lineEdit_HDG_textEdited(QString)\0"
    "on_lineEdit_Alt_textChanged(QString)\0"
    "index\0on_comboBox_ListWaypoint_currentIndexChanged(int)\0"
    "on_Delete_button_clicked()\0date\0"
    "on_timeEdit_Mission_timeChanged(QTime)\0"
    "on_excute_button_clicked()\0"
    "on_addMark_button_clicked()\0"
    "on_AddToMission_button_clicked()\0"
    "on_NextWaypoint_button_clicked()\0"
};

const QMetaObject MARCS::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MARCS,
      qt_meta_data_MARCS, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MARCS::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MARCS::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MARCS::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MARCS))
        return static_cast<void*>(const_cast< MARCS*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MARCS::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: clickOn(); break;
        case 1: clickOff(); break;
        case 2: takeOff(); break;
        case 3: landRPA(); break;
        case 4: next((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 5: openNewWindowMain(); break;
        case 6: openNewWindowData(); break;
        case 7: openNewWindowVideo(); break;
        case 8: openNewMap(); break;
        case 9: switchToMap(); break;
        case 10: showList(); break;
        case 11: openMission(); break;
        case 12: saveMission(); break;
        case 13: addPoint((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< GeoDataCoordinates::Unit(*)>(_a[3]))); break;
        case 14: clearMission(); break;
        case 15: editWaypoint(); break;
        case 16: loadData(); break;
        case 17: saveEditData(); break;
        case 18: finishEditData(); break;
        case 19: showEditWaypoint((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: showConnectDialog(); break;
        case 21: validCom(); break;
        case 22: closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 23: startMotors(); break;
        case 24: batteryLevel((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 25: stopMotors(); break;
        case 26: createStyleRPA((*reinterpret_cast< GeoDataStyle*(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 27: createRpaMark((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< GeoDataCoordinates::Unit(*)>(_a[4]))); break;
        case 28: createStyleHome((*reinterpret_cast< GeoDataStyle*(*)>(_a[1]))); break;
        case 29: createHomeMark((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< GeoDataCoordinates::Unit(*)>(_a[3]))); break;
        case 30: createStyleAddMark((*reinterpret_cast< GeoDataStyle*(*)>(_a[1]))); break;
        case 31: createAddMark((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< GeoDataCoordinates::Unit(*)>(_a[3]))); break;
        case 32: setHeight((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 33: fly(); break;
        case 34: XbeeDisconnect(); break;
        case 35: XbeeConnect(); break;
        case 36: stopFly(); break;
        case 37: GPSLevel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: updateMotors((*reinterpret_cast< char(*)>(_a[1]))); break;
        case 39: goTo(); break;
        case 40: setTableRPA(); break;
        case 41: showLog(); break;
        case 42: close(); break;
        case 43: on_start_button_clicked(); break;
        case 44: on_lineEdit_HDG_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 45: on_lineEdit_Alt_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 46: on_comboBox_ListWaypoint_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 47: on_Delete_button_clicked(); break;
        case 48: on_timeEdit_Mission_timeChanged((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 49: on_excute_button_clicked(); break;
        case 50: on_addMark_button_clicked(); break;
        case 51: on_AddToMission_button_clicked(); break;
        case 52: on_NextWaypoint_button_clicked(); break;
        default: ;
        }
        _id -= 53;
    }
    return _id;
}

// SIGNAL 0
void MARCS::clickOn()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MARCS::clickOff()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MARCS::takeOff()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MARCS::landRPA()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void MARCS::next(double _t1, double _t2, double _t3, double _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
