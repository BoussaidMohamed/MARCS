#-------------------------------------------------
#
# Project created by QtCreator 2013-06-18T10:48:11
#
#-------------------------------------------------

QT       += core gui


TARGET = MARCS
TEMPLATE = app

SOURCES += main.cpp\
    ComThread.cpp \
    CommunicationControl.cpp \
    UAVLogger.cpp \
    waypoint.cpp \
    mission.cpp \
    MissionControl.cpp \
    PeripheralController.cpp \
    JoystickGrabber.cpp \
    UAV.cpp \
    LogReplayControl.cpp \
    LatLongCoord.cpp \
    marcs.cpp
QT       += xml

CONFIG += console
CONFIG += serialport


HEADERS  += \
    ComThread.h \
    CommunicationControl.h \
    UAVLogger.h \
    waypoint.h \
    mission.h \
    MissionControl.h \
    PeripheralController.h \
    JoystickGrabber.h \
    UAV.h \
    LogReplayControl.h \
    LatLongCoord.h \
    marcs.h

FORMS    += \
    marcs.ui


win32 {
    INCLUDEPATH += $$quote(C:\Program Files (x86)\marble\include\marble)
    INCLUDEPATH += $$quote(C:\Users\mboussai\Desktop\Mohamed\Qt Projects\Lib\libxbee3_v3.0.9)
    INCLUDEPATH += $$quote(C:\Users\mboussai\Desktop\Last\qtserialport\build\include)
    LIBS += $$quote(C:\Program Files (x86)\marble\libmarblewidget.dll)
    LIBS += $$quote(C:\Users\mboussai\Desktop\Mohamed\Qt Projects\Lib\libxbee3_v3.0.9\lib\libxbee3.dll)
}

include(C:/Users/mboussai/Desktop/Mohamed/Qt Projects/Lib/qextserialport-1.2beta1/src/qextserialport.pri)


RESOURCES += \
    ressource.qrc
