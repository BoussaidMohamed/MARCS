#include "mission.h"
#include <QFile>
#include <QXmlStreamWriter>
#include <QString>

mission::mission()
{
}
mission::mission(int num): n_mission(num)
{

}

int mission::getNum(){
    return n_mission ;
}

void mission::setNum(int n){
    n_mission = n ;
}

void mission::saveMission(waypoint wp , QFile file ){

 //   QString miss = QString("Mission %1").arg(getNum());
   // QString waypoint  = QString("Waypoint %1").arg(wp.getNum());

    //QXmlStreamWriter xmlWriter(&file);
    //xmlWriter.setAutoFormatting(true);
    //xmlWriter.writeStartDocument(miss);
    //xmlWriter.writeStartElement(waypoint);

    //xmlWriter.writeTextElement("num",wp.getNum());
    //xmlWriter.writeTextElement("Longitude",wp.getLong());
    //xmlWriter.writeTextElement("Latitude",wp.getLat());
   // xmlWriter.writeTextElement("Altitude",wp.getAlt());
   // xmlWriter.writeTextElement("Heading",wp.getHdg());
    //xmlWriter.writeTextElement("Time",wp.getTime());
  //  xmlWriter.writeTextElement("Type",wp.getType());
   // xmlWriter.writeTextElement("num",wp.getNum());

//    xmlWriter.writeEndElement();
  //  xmlWriter.writeEndDocument();

    //file.close();



}
