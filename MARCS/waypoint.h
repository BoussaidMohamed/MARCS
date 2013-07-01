#ifndef WAYPOINT_H
#define WAYPOINT_H
#include <QtGlobal>

class waypoint
{
public:
    waypoint();
    waypoint (int num , qreal longitude,qreal latitude,double altitude, double  hdg, int time,int type, int numMission);
  // ~waypoint();

    void setNum ( int n);
    void setLong ( qreal lon);
    void setLat ( qreal lat);
    void setAlt ( double alt);
    void setHdg (double hd);
    void setTime ( int ti);
    void setType ( int ty);
    void setMission (int numMission);

    int getNum ()  ;
    int getMission()  ;
    qreal getLong() ;
    qreal getLat() ;
    double getAlt()  ;
    double getHdg() ;
    int getTime()  ;
    int getType()  ;



public:
    int numW ;
    qreal longitudeW, latitudeW ;
    double  altitudeW, hdgW ;
    int timeW, typeW , numMissionW ;



};

#endif // WAYPOINT_H
