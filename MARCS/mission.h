#ifndef MISSION_H
#define MISSION_H
#include <GeoPainter.h>
#include "waypoint.h"
#include <QFileDialog>
#include <QFile>
#include <QXmlStreamReader>

class mission
{
public:
    mission();
    mission(int num);
    ~mission();

    int getNum();

    void setNum(int n);
    void saveMission(QList < waypoint* > wpList , QString fileName);
    void saveMissionKml(QList < waypoint* > wpList , QString fileName);
    void setWaypointList(QList <waypoint* > mission);
    QList <waypoint* > loadMission(QString filename);
    QList <waypoint* > getWaypointList();



public :
    int n_mission ;
     QList <waypoint* > myMission ;

};

#endif // MISSION_H
