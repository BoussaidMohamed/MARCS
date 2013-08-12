/****************************************************************************
** Meta object code from reading C++ file 'RPA.h'
**
** Created: Mon 12. Aug 17:10:39 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MARCS/RPA.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RPA.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RPA[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       5,    4,    4,    4, 0x05,

 // slots: signature, parameters, type, tag, flags
      71,   23,    4,    4, 0x0a,
     121,  112,    4,    4, 0x0a,
     143,  112,    4,    4, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_RPA[] = {
    "RPA\0\0positionChanged()\0"
    "p_fLatitude,p_fLongitude,p_fAltitude,p_fHeading\0"
    "geolocation(double,double,double,double)\0"
    "p_pValue\0updateHeading(double)\0"
    "updateHeight(double)\0"
};

const QMetaObject RPA::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RPA,
      qt_meta_data_RPA, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RPA::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RPA::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RPA::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RPA))
        return static_cast<void*>(const_cast< RPA*>(this));
    return QObject::qt_metacast(_clname);
}

int RPA::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: positionChanged(); break;
        case 1: geolocation((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 2: updateHeading((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: updateHeight((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void RPA::positionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
