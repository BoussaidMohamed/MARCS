/****************************************************************************
** Meta object code from reading C++ file 'JoystickGrabber.h'
**
** Created: Fri 9. Aug 16:11:55 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MARCS/JoystickGrabber.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'JoystickGrabber.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_JoystickGrabber[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      30,   16,   16,   16, 0x05,
      51,   16,   16,   16, 0x05,
      71,   16,   16,   16, 0x05,
      89,   16,   16,   16, 0x05,
     109,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
     124,   16,   16,   16, 0x0a,
     131,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_JoystickGrabber[] = {
    "JoystickGrabber\0\0noJoystick()\0"
    "directInputProblem()\0dataFormatProblem()\0"
    "joystickProblem()\0deviceEnumProblem()\0"
    "dataComputed()\0grab()\0sendAcknowledge()\0"
};

const QMetaObject JoystickGrabber::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_JoystickGrabber,
      qt_meta_data_JoystickGrabber, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &JoystickGrabber::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *JoystickGrabber::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *JoystickGrabber::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JoystickGrabber))
        return static_cast<void*>(const_cast< JoystickGrabber*>(this));
    return QObject::qt_metacast(_clname);
}

int JoystickGrabber::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: noJoystick(); break;
        case 1: directInputProblem(); break;
        case 2: dataFormatProblem(); break;
        case 3: joystickProblem(); break;
        case 4: deviceEnumProblem(); break;
        case 5: dataComputed(); break;
        case 6: grab(); break;
        case 7: sendAcknowledge(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void JoystickGrabber::noJoystick()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void JoystickGrabber::directInputProblem()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void JoystickGrabber::dataFormatProblem()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void JoystickGrabber::joystickProblem()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void JoystickGrabber::deviceEnumProblem()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void JoystickGrabber::dataComputed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
