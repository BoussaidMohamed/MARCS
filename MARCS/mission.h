#ifndef MISSION_H
#define MISSION_H
#include "waypoint.h"
#include <QFile>

class mission
{
public:
    mission();
    mission(int num);
    ~mission();

    int getNum();

    void setNum(int n);
    void saveMission(waypoint wp , QFile file);



public :
    int n_mission ;
};

#endif // MISSION_H
