#include "waypoint.h"

waypoint::waypoint()
{

}
waypoint::waypoint(int num, double longitude, double latitude, double altitude, double hdg, int time, int type, int numMission) : numW(num) , longitudeW(longitude), latitudeW(latitude), altitudeW(altitude),hdgW(hdg),timeW(time),typeW(type), numMissionW(numMission)
{

}


double waypoint::getAlt(){
    return altitudeW ;
}
double waypoint::getHdg(){
    return hdgW ;
}
qreal waypoint::getLat(){
    return latitudeW ;
}
qreal waypoint::getLong(){
    return longitudeW ;
}

int waypoint::getNum(){
    return numW ;
}
int waypoint::getTime(){
    return timeW;
}
int waypoint::getType(){
    return typeW;
}
int waypoint::getMission(){
    return numMissionW;
}


void waypoint::setAlt(double alt){
    altitudeW = alt ;
}


void waypoint::setHdg(double hd){
    hdgW = hd ;
}


void waypoint::setLat(qreal lat){
    latitudeW = lat ;
}


void waypoint::setLong(qreal lon){
    longitudeW = lon ;
}


void waypoint::setNum(int n){
    numW = n ;
}

void waypoint::setTime(int ti){
    timeW = ti ;
}
void waypoint::setType(int ty){
    typeW = ty ;
}

void waypoint::setMission(int numMission){
    numMissionW = numMission;
}



