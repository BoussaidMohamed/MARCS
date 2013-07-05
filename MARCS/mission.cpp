#include "mission.h"
#include "waypoint.h"
#include <qdom.h>
#include <QFile>
#include <QtXml>
#include <ctime>
#include <qxmlstream.h>
#include <iostream>
#include <QFileDialog>
#include <MarbleWidget.h>
#include <GeoPainter.h>
#include <GeoDataLineString.h>
#include <GeoDataCoordinates.h>

using namespace std ;
using namespace Marble ;



mission::mission()
{

}
mission::mission(int num): n_mission(num)
{


}
mission::~mission()
{

}

int mission::getNum(){
    return n_mission ;
}

void mission::setNum(int n){
    n_mission = n ;
}

void mission::saveMission(QList < waypoint* > wpList , QString filename){

    time_t now1 = time (0);
    struct tm * now2 = localtime( & now1);
    string temp ;
    char* time_mission = new char[32];
    QString qs ;

    sprintf(time_mission,"%d_%d_%d_%d_%d",(now2->tm_year + 1900 ) ,(now2->tm_mon+1), (now2->tm_mday),(now2->tm_hour),  (now2->tm_min));
    temp = string(time_mission);
     string time_mission_temp = "" + temp ;
    qs =  QString::fromStdString(time_mission_temp);

       QFile file(filename);
       file.open(QIODevice::WriteOnly);

       QXmlStreamWriter xmlWriter(&file);
       xmlWriter.setAutoFormatting(true);
       xmlWriter.writeStartDocument();

       xmlWriter.writeStartElement("Mission");
       xmlWriter.writeTextElement("Number",qs);

       for ( int i = 0 ; i < wpList.size(); i++ ) {

      xmlWriter.writeStartElement("Waypoint");
      xmlWriter.writeTextElement("Number",QString::number(wpList[i]->getNum()));
      xmlWriter.writeTextElement("Longitude",QString::number(wpList[i]->getLong(),'g',6));
      xmlWriter.writeTextElement("Latitude",QString::number(wpList[i]->getLat(),'g',6));
      xmlWriter.writeTextElement("Altitude",QString::number(wpList[i]->getAlt()));
      xmlWriter.writeTextElement("Heading",QString::number(wpList[i]->getHdg()));
      xmlWriter.writeTextElement("Time",QString::number(wpList[i]->getTime()));
      xmlWriter.writeTextElement("Type",QString::number(wpList[i]->getType()));
      xmlWriter.writeEndElement();

       }

       xmlWriter.writeEndElement();
       xmlWriter.writeEndDocument();

       file.close();

}

void mission::customPaint(QList < waypoint* > wpList) {


}
