#ifndef WAYPOINT_H
#define WAYPOINT_H
#include <QtGlobal>

class waypoint
{
public:
    waypoint();
    waypoint (int num , double longitude,double latitude,double altitude, double  hdg, int time,int type);
    ~waypoint();

    void setNum ( int num);
    void setLong ( double longitude);
    void setLat ( double lat);
    void setAlt ( double alt);
    void setHdg (double hdg);
    void setTime ( int t);
    void setType ( int type);

    int getnum () const ;
    double getLong() const;
    double getLat() const;
    double getAlt() const ;
    double getHdg() const;
    double getTime() const ;
    double getType() const ;

public:
    int num ,time, type ;
    double longitude, latitude, altitude, hdg ;


};

#endif // WAYPOINT_H
