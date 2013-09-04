#include "mission.h"
#include "waypoint.h"
#include <QFile>
#include <ctime>
#include <string.h>
#include <qxmlstream.h>
#include <iostream>
#include <QFileDialog>
#include <QMessageBox>
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
    myMission.~QList();

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

      sprintf(time_mission,"%d_%d_%d_%d_%d",(now2->tm_year + 1900 ) ,(now2->tm_mon+1), (now2->tm_mday),(now2->tm_hour), (now2->tm_min));
      temp = string(time_mission);
       string time_mission_temp = "" + temp ;
      qs = QString::fromStdString(time_mission_temp);

         QFile file(filename);
         file.open(QIODevice::WriteOnly);

         QXmlStreamWriter xmlWriter(&file);
         xmlWriter.setAutoFormatting(true);
         xmlWriter.writeStartDocument();

         xmlWriter.writeStartElement("Mission");
         xmlWriter.writeTextElement("Mission_Number",qs);

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

         delete[] time_mission;

}


QList <waypoint* > mission::loadMission( QString filename){


        QList < waypoint* > wpList ;
    /* We'll parse the filename */
        QFile* file = new QFile(filename);
        int num  ;
        double lon , lat ,alt , hdg ;
        int time, type ;
        bool ok = false ;


        /* If we can't open it, let's show an error message. */
        if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {

        }
        /* QXmlStreamReader takes any QIODevice. */
        QXmlStreamReader xml(file);
        /* We'll parse the XML until we reach end of it.*/
        while(!xml.atEnd() && !xml.hasError()) {
            /* Read next element.*/
            QXmlStreamReader::TokenType token = xml.readNext();
            /* If token is just StartDocument, we'll go to next.*/
            if(token == QXmlStreamReader::StartDocument) {
                continue;
            }
            /* If token is StartElement, we'll see if we can read it.*/
            if(token == QXmlStreamReader::StartElement) {
                /* If it's named Mission, we'll go to the next.*/
                if(xml.name() == "Mission") {
                    continue;
                }
                if(xml.name() == "Mission_Number") {
                    continue;
                }
                /* If it's named Waypoint, we'll dig the information from there.*/
                if(xml.name() == "Waypoint") {

                    /* Next element... */
                    xml.readNext();
                    /*
                     * We're going to loop over the things because the order might change.
                     * We'll continue the loop until we hit an EndElement named Waypoint.
                     */

                    while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "Waypoint")) {



                        if(xml.tokenType() == QXmlStreamReader::StartElement) {
                            /* We've found Number. */
                            if(xml.name() == "Number") {
                                num = xml.readElementText().toInt(&ok,10);
                            }
                            /* We've found Longitude. */
                            if(xml.name() == "Longitude") {
                                lon = xml.readElementText().toDouble(&ok);

                            }
                            /* We've found Latitude. */
                            if(xml.name() == "Latitude") {
                                lat = xml.readElementText().toDouble(&ok);

                            }
                            /* We've found Altitude. */
                            if(xml.name() == "Altitude") {
                                alt=xml.readElementText().toDouble(&ok);
                            }

                            /* We've found Heading. */
                            if(xml.name() == "Heading") {
                                hdg = xml.readElementText().toDouble(&ok);

                            }
                            /* We've found Time. */
                            if(xml.name() == "Time") {
                                time = xml.readElementText().toInt(&ok,10);

                           }
                            /* We've found Type. */
                            if(xml.name() == "Type") {
                                type=xml.readElementText().toInt(&ok,10);
                            }
                        }
                        /* ...and next... */
                        xml.readNext();
                    }
                    wpList.append(new waypoint(num,lon,lat,alt,hdg,time,type,0));

                }
            }
        }
        /* Error handling. */
        if(xml.hasError()) {

        }
        /* Removes any device() or data from the reader
         * and resets its internal state to the initial state. */
        file->close();
        xml.clear();

       return wpList;
       delete file ;
   }

void mission::saveMissionKml(QList<waypoint *> wpList, QString fileName){

    QFile file(fileName);
    file.open(QIODevice::WriteOnly);

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement("kml");
    xmlWriter.writeAttribute("xmlns","http://earth.google.com/kml/2.2");
    xmlWriter.writeStartElement("Folder");
    xmlWriter.writeTextElement("name","Mission MARCS");

    for ( int i = 0 ; i < wpList.size(); i++ ) {

   xmlWriter.writeStartElement("Placemark");
   xmlWriter.writeTextElement("name",QString::number(wpList[i]->getNum()));
   xmlWriter.writeStartElement("Point");
   xmlWriter.writeTextElement("coordinates",QString::number(wpList[i]->getLong(),'g',6)+","+QString::number(wpList[i]->getLat(),'g',6));
    xmlWriter.writeEndElement();
    xmlWriter.writeEndElement();
    }

    xmlWriter.writeEndElement();
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();

    file.close();


}

QList <waypoint*> mission::getWaypointList(){
    return myMission;
}

void mission::setWaypointList(QList<waypoint *> mission){
    myMission = mission;
}
