/****************************************************************************
** Meta object code from reading C++ file 'marcs.h'
**
** Created: Mon 12. Aug 17:10:37 2013
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
      34,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,
      17,    6,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      28,    6,    6,    6, 0x0a,
      48,    6,    6,    6, 0x0a,
      68,    6,    6,    6, 0x0a,
      89,    6,    6,    6, 0x0a,
     102,    6,    6,    6, 0x0a,
     116,    6,    6,    6, 0x0a,
     130,    6,    6,    6, 0x0a,
     144,    6,    6,    6, 0x0a,
     167,  158,    6,    6, 0x0a,
     214,    6,    6,    6, 0x0a,
     229,    6,    6,    6, 0x0a,
     244,    6,    6,    6, 0x0a,
     255,    6,    6,    6, 0x0a,
     270,    6,    6,    6, 0x0a,
     295,  287,    6,    6, 0x0a,
     325,  320,    6,    6, 0x0a,
     348,    6,    6,    6, 0x0a,
     368,    6,    6,    6, 0x0a,
     385,  379,    6,    6, 0x0a,
     410,    6,    6,    6, 0x0a,
     433,  424,    6,    6, 0x0a,
     454,    6,    6,    6, 0x0a,
     477,  467,    6,    6, 0x0a,
     527,  514,    6,    6, 0x0a,
     598,  588,    6,    6, 0x0a,
     616,    6,    6,    6, 0x0a,
     624,    6,    6,    6, 0x08,
     650,    6,    6,    6, 0x08,
     686,    6,    6,    6, 0x08,
     729,  723,    6,    6, 0x08,
     779,    6,    6,    6, 0x08,
     811,  806,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MARCS[] = {
    "MARCS\0\0clickOn()\0clickOff()\0"
    "openNewWindowMain()\0openNewWindowData()\0"
    "openNewWindowVideo()\0openNewMap()\0"
    "switchToMap()\0afficheList()\0openMission()\0"
    "saveMission()\0lon,lat,\0"
    "addPoint(qreal,qreal,GeoDataCoordinates::Unit)\0"
    "clearMission()\0editWaypoint()\0loadData()\0"
    "saveEditData()\0finishEditData()\0painter\0"
    "drawMission(GeoPainter*)\0show\0"
    "showEditWaypoint(bool)\0showConnectDialog()\0"
    "validCom()\0event\0closeEvent(QCloseEvent*)\0"
    "startMotors()\0p_pValue\0batteryLevel(double)\0"
    "stopMotors()\0style,hdg\0"
    "createStyleRPA(GeoDataStyle*,double)\0"
    "hdg,lon,lat,\0"
    "createRpaMark(double,double,double,GeoDataCoordinates::Unit)\0"
    "p_dHeight\0setHeight(double)\0close()\0"
    "on_start_button_clicked()\0"
    "on_lineEdit_HDG_textEdited(QString)\0"
    "on_lineEdit_Alt_textChanged(QString)\0"
    "index\0on_comboBox_ListWaypoint_currentIndexChanged(int)\0"
    "on_Delete_button_clicked()\0date\0"
    "on_timeEdit_Mission_timeChanged(QTime)\0"
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
        case 2: openNewWindowMain(); break;
        case 3: openNewWindowData(); break;
        case 4: openNewWindowVideo(); break;
        case 5: openNewMap(); break;
        case 6: switchToMap(); break;
        case 7: afficheList(); break;
        case 8: openMission(); break;
        case 9: saveMission(); break;
        case 10: addPoint((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< GeoDataCoordinates::Unit(*)>(_a[3]))); break;
        case 11: clearMission(); break;
        case 12: editWaypoint(); break;
        case 13: loadData(); break;
        case 14: saveEditData(); break;
        case 15: finishEditData(); break;
        case 16: drawMission((*reinterpret_cast< GeoPainter*(*)>(_a[1]))); break;
        case 17: showEditWaypoint((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: showConnectDialog(); break;
        case 19: validCom(); break;
        case 20: closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 21: startMotors(); break;
        case 22: batteryLevel((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 23: stopMotors(); break;
        case 24: createStyleRPA((*reinterpret_cast< GeoDataStyle*(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 25: createRpaMark((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< GeoDataCoordinates::Unit(*)>(_a[4]))); break;
        case 26: setHeight((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 27: close(); break;
        case 28: on_start_button_clicked(); break;
        case 29: on_lineEdit_HDG_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 30: on_lineEdit_Alt_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 31: on_comboBox_ListWaypoint_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: on_Delete_button_clicked(); break;
        case 33: on_timeEdit_Mission_timeChanged((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 34;
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
QT_END_MOC_NAMESPACE
