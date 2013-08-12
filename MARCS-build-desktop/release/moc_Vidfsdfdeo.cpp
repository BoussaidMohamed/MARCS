/****************************************************************************
** Meta object code from reading C++ file 'Vidfsdfdeo.h'
**
** Created: Mon 5. Aug 17:41:17 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MARCS/Vidfsdfdeo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Vidfsdfdeo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_video[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x0a,
      27,    6,    6,    6, 0x0a,
      47,    6,    6,    6, 0x0a,
      68,    6,    6,    6, 0x0a,
      81,    6,    6,    6, 0x0a,
      95,    6,    6,    6, 0x0a,
     109,    6,    6,    6, 0x0a,
     123,    6,    6,    6, 0x0a,
     146,  137,    6,    6, 0x0a,
     193,    6,    6,    6, 0x0a,
     208,    6,    6,    6, 0x0a,
     223,    6,    6,    6, 0x0a,
     234,    6,    6,    6, 0x0a,
     249,    6,    6,    6, 0x0a,
     274,  266,    6,    6, 0x0a,
     304,  299,    6,    6, 0x0a,
     327,    6,    6,    6, 0x0a,
     347,    6,    6,    6, 0x0a,
     364,  358,    6,    6, 0x0a,
     389,    6,    6,    6, 0x0a,
     397,    6,    6,    6, 0x08,
     423,    6,    6,    6, 0x08,
     459,    6,    6,    6, 0x08,
     502,  496,    6,    6, 0x08,
     552,    6,    6,    6, 0x08,
     584,  579,    6,    6, 0x08,
     623,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_video[] = {
    "video\0\0openNewWindowMain()\0"
    "openNewWindowData()\0openNewWindowVideo()\0"
    "openNewMap()\0switchToMap()\0afficheList()\0"
    "openMission()\0saveMission()\0lon,lat,\0"
    "addPoint(qreal,qreal,GeoDataCoordinates::Unit)\0"
    "clearMission()\0editWaypoint()\0loadData()\0"
    "saveEditData()\0finishEditData()\0painter\0"
    "drawMission(GeoPainter*)\0show\0"
    "showEditWaypoint(bool)\0showConnectDialog()\0"
    "validCom()\0event\0closeEvent(QCloseEvent*)\0"
    "close()\0on_start_button_clicked()\0"
    "on_lineEdit_HDG_textEdited(QString)\0"
    "on_lineEdit_Alt_textChanged(QString)\0"
    "index\0on_comboBox_ListWaypoint_currentIndexChanged(int)\0"
    "on_Delete_button_clicked()\0date\0"
    "on_timeEdit_Mission_timeChanged(QTime)\0"
    "on_stop_button_clicked()\0"
};

const QMetaObject video::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_video,
      qt_meta_data_video, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &video::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *video::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *video::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_video))
        return static_cast<void*>(const_cast< video*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int video::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: openNewWindowMain(); break;
        case 1: openNewWindowData(); break;
        case 2: openNewWindowVideo(); break;
        case 3: openNewMap(); break;
        case 4: switchToMap(); break;
        case 5: afficheList(); break;
        case 6: openMission(); break;
        case 7: saveMission(); break;
        case 8: addPoint((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< GeoDataCoordinates::Unit(*)>(_a[3]))); break;
        case 9: clearMission(); break;
        case 10: editWaypoint(); break;
        case 11: loadData(); break;
        case 12: saveEditData(); break;
        case 13: finishEditData(); break;
        case 14: drawMission((*reinterpret_cast< GeoPainter*(*)>(_a[1]))); break;
        case 15: showEditWaypoint((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: showConnectDialog(); break;
        case 17: validCom(); break;
        case 18: closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 19: close(); break;
        case 20: on_start_button_clicked(); break;
        case 21: on_lineEdit_HDG_textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: on_lineEdit_Alt_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: on_comboBox_ListWaypoint_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: on_Delete_button_clicked(); break;
        case 25: on_timeEdit_Mission_timeChanged((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 26: on_stop_button_clicked(); break;
        default: ;
        }
        _id -= 27;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
