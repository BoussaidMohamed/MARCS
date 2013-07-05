#ifndef MISSION_H
#define MISSION_H
#include "waypoint.h"
#include <QFileDialog>
#include <QFile>

class mission
{
public:
    mission();
    mission(int num);
    ~mission();

    int getNum();

    void setNum(int n);
    void saveMission(QList < waypoint* > wpList , QString fileName);
    void customPaint(QList < waypoint* > wpList);



public :
    int n_mission ;
};

#endif // MISSION_H
