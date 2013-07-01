#-------------------------------------------------
#
# Project created by QtCreator 2013-06-18T10:48:11
#
#-------------------------------------------------

QT       += core gui
QT       += xml

TARGET = MARCS
TEMPLATE = app


SOURCES += main.cpp\
    video.cpp \
    waypoint.cpp \
    mission.cpp

HEADERS  += \
    video.h \
    waypoint.h \
    mission.h

FORMS    += \
    video.ui


win32 {
    INCLUDEPATH += $$quote(C:\Program Files (x86)\marble\include\marble)
    LIBS += $$quote(C:\Program Files (x86)\marble\libmarblewidget.dll)
}

RESOURCES += \
    ressources.qrc \
    ressource.qrc
