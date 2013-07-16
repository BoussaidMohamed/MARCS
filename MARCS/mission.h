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
    QList <waypoint* > loadMission(QList < waypoint* > wpList , QString filename);
    //void customPaint(GeoPainter* painter);



public :
    int n_mission ;
};

#endif // MISSION_H
