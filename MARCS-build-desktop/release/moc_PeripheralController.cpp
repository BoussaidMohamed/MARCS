/****************************************************************************
** Meta object code from reading C++ file 'PeripheralController.h'
**
** Created: Mon 12. Aug 17:10:35 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MARCS/PeripheralController.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PeripheralController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PeripheralController[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: signature, parameters, type, tag, flags
      41,   22,   21,   21, 0x05,
      74,   21,   21,   21, 0x05,
      96,   21,   21,   21, 0x05,
     109,   21,   21,   21, 0x05,
     130,   21,   21,   21, 0x05,
     150,   21,   21,   21, 0x05,
     168,   21,   21,   21, 0x05,
     188,   21,   21,   21, 0x05,
     210,   21,   21,   21, 0x05,
     244,  234,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
     278,   21,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PeripheralController[] = {
    "PeripheralController\0\0button,waitRelease\0"
    "mouseEvent(Qt::MouseButton,bool)\0"
    "controllerConnected()\0noJoystick()\0"
    "directInputProblem()\0dataFormatProblem()\0"
    "joystickProblem()\0deviceEnumProblem()\0"
    "controllerMouseMode()\0controllerControlMode()\0"
    "x,y,z,yaw\0move(double,double,double,double)\0"
    "useController()\0"
};

const QMetaObject PeripheralController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PeripheralController,
      qt_meta_data_PeripheralController, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PeripheralController::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PeripheralController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PeripheralController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PeripheralController))
        return static_cast<void*>(const_cast< PeripheralController*>(this));
    return QObject::qt_metacast(_clname);
}

int PeripheralController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: mouseEvent((*reinterpret_cast< Qt::MouseButton(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: controllerConnected(); break;
        case 2: noJoystick(); break;
        case 3: directInputProblem(); break;
        case 4: dataFormatProblem(); break;
        case 5: joystickProblem(); break;
        case 6: deviceEnumProblem(); break;
        case 7: controllerMouseMode(); break;
        case 8: controllerControlMode(); break;
        case 9: move((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 10: useController(); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void PeripheralController::mouseEvent(Qt::MouseButton _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PeripheralController::controllerConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void PeripheralController::noJoystick()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void PeripheralController::directInputProblem()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void PeripheralController::dataFormatProblem()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void PeripheralController::joystickProblem()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void PeripheralController::deviceEnumProblem()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void PeripheralController::controllerMouseMode()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void PeripheralController::controllerControlMode()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void PeripheralController::move(double _t1, double _t2, double _t3, double _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
