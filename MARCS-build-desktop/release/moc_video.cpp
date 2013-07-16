/****************************************************************************
** Meta object code from reading C++ file 'video.h'
**
** Created: Mon 15. Jul 17:36:05 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MARCS/video.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'video.h' doesn't include <QObject>."
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
      17,   14, // methods
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
     230,    6,    6,    6, 0x0a,
     245,    6,    6,    6, 0x0a,
     256,    6,    6,    6, 0x0a,
     271,    6,    6,    6, 0x0a,
     288,    6,    6,    6, 0x0a,
     302,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_video[] = {
    "video\0\0openNewWindowMain()\0"
    "openNewWindowData()\0openNewWindowVideo()\0"
    "openNewMap()\0switchToMap()\0afficheList()\0"
    "openMission()\0saveMission()\0lon,lat,\0"
    "addPoint(qreal,qreal,GeoDataCoordinates::Unit)\0"
    "clearMission()\0activateAddingPoint()\0"
    "editWaypoint()\0loadData()\0saveEditData()\0"
    "finishEditData()\0drawMission()\0close()\0"
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
        case 10: activateAddingPoint(); break;
        case 11: editWaypoint(); break;
        case 12: loadData(); break;
        case 13: saveEditData(); break;
        case 14: finishEditData(); break;
        case 15: drawMission(); break;
        case 16: close(); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
