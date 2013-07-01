#include "video.h"
#include "ui_video.h"
#include <global.h>
#include <AbstractFloatItem.h>
#include <QString>
#include <QtGlobal>
#include <QFileDialog>
#include <QtCore/QFileInfo>
#include <QtGui/QApplication>
#include <QListView>
#include <string>
#include <iostream>
#include <QtGui/QTreeView>
#include <QtCore/QDataStream>
#include <QtCore/QFile>
#include <QtCore/QIODevice>
#include <QListWidget>
#include <QListWidgetItem>
#include <QtGui/QTreeView>
#include <MarbleWidget.h>
#include <MarbleModel.h>
#include <GeoPainter.h>
#include <RouteRequest.h>
#include <RoutingManager.h>
#include <GeoDataDocument.h>
#include <GeoDataPlacemark.h>
#include <GeoDataLineString.h>
#include <GeoDataTreeModel.h>
#include <RoutingWidget.h>
#include <GeoPainter.h>
#include "mission.h"
#include "waypoint.h"
#include <QDateTime>
#include <vector>
#include <cstdio>
#include <sstream>

using namespace std;
using namespace Marble;

QListView *m_listView;
bool affichageList;
GeoDataPlacemark *place ;
GeoDataDocument *document ;
RoutingManager* manager ;
RouteRequest* request;
RoutingManager* manager_smallMap ;
RouteRequest* request_smallMap;
qreal lon0 ;
qreal lat0 ;
bool mission = false ;
bool map = false;
QString lastMission;
QString lastMap;
int num_waypoint = 0;
string textNumWaypoint ;
string temp;
QString qstr ;
char * numWpText = new char[32];




video::video(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::video)
{
    affichageList = false ;//etat d'affichage de la liste du log

    ui->setupUi(this);
    place =  new GeoDataPlacemark( "" );
    document = new GeoDataDocument();

    //config marble
    ui->MarbleWidget_smallView->setShowOverviewMap(false);
    ui->MarbleWidget_plan->setShowOverviewMap(false);
    ui->MarbleWidget_smallView->setShowScaleBar(false);
    ui->MarbleWidget_smallView->setShowCompass(false);
    ui->MarbleWidget_smallView->hide();

    //initialisation de l'intreface
    ui->tableWidget->hide();
    ui->snapShoot_button->hide();
    ui->actionFlight_plan->setEnabled(false);
    ui->actionFlight_data->setEnabled(true);
    ui->actionVideo->setEnabled(true);
    ui->listLog->hide();
    ui->actionClear_mission->setEnabled(false);

    //signal&&slot de l'application
    connect(ui->actionFlight_plan,SIGNAL(triggered()),this,SLOT(openNewWindowMain()));
    connect(ui->actionFlight_data,SIGNAL(triggered()),this,SLOT(openNewWindowData()));
    connect(ui->actionVideo,SIGNAL(triggered()),this,SLOT(openNewWindowVideo()));
    connect(ui->actionLoad_map,SIGNAL(triggered()),this,SLOT(openNewMap()));
    connect(ui->actionLoad_mission,SIGNAL(triggered()),this,SLOT(openMission()));
    connect(ui->actionClose,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->MarbleWidget_smallView,SIGNAL(mouseClickGeoPosition(qreal,qreal,GeoDataCoordinates::Unit)),this,SLOT(switchToMap()));
    connect(ui->status_button,SIGNAL(clicked()),this,SLOT(afficheList()));
    connect(ui->led_button,SIGNAL(clicked()),this,SLOT(afficheList()));
    connect(ui->actionSave_mission,SIGNAL(triggered()),this,SLOT(saveMission()));
    connect(ui->actionClear_mission,SIGNAL(triggered()),this,SLOT(clearMission()));
    connect(ui->actionStart_planning,SIGNAL(triggered()),this,SLOT(activateAddingPoint()));

}

video::~video()
{
    delete ui;
}

void video::clearMission(){

    ui->MarbleWidget_plan->model()->removeGeoData(lastMission);
    ui->actionClear_mission->setEnabled(false);

}
void video::activateAddingPoint(){
    ui->actionSave_mission->setEnabled(true);
    connect(ui->MarbleWidget_plan,SIGNAL(mouseClickGeoPosition(qreal,qreal,GeoDataCoordinates::Unit)),this,SLOT(addPoint(qreal,qreal,GeoDataCoordinates::Unit)));
    ui->actionStart_planning->setEnabled(false);
}

void video::afficheList()
{
    if (affichageList==false){
        ui->listLog->show();
        affichageList = true ;
    }
    else {
        ui->listLog->hide();
        affichageList = false ;
    }

}
//open a mission

void video::openMission(){

     disconnect(ui->MarbleWidget_plan,SIGNAL(mouseClickGeoPosition(qreal,qreal,GeoDataCoordinates::Unit)),this,SLOT(addPoint(qreal,qreal,GeoDataCoordinates::Unit)));

    path = QFileDialog::getOpenFileName(this, "Load a mission", "C:/Users/mboussai/Desktop/Mohamed/Qt Projects/FILES/mission", "KML (*.kml)");
    QFileInfo inputFile(path);

           request->clear();
           request_smallMap->clear();
           ui->MarbleWidget_plan->model()->addGeoDataFile( inputFile.absoluteFilePath() );
           ui->MarbleWidget_plan->repaint();
           ui->MarbleWidget_smallView->model()->addGeoDataFile( inputFile.absoluteFilePath() );
           lastMission = inputFile.absoluteFilePath();
           ui->actionClear_mission->setEnabled(true);
           lastMission = inputFile.absoluteFilePath();
           ui->actionStart_planning->setEnabled(true);




}
//enregister une mission

void video::saveMission(){

    QString const fileName = QFileDialog::getSaveFileName( this,  "Save a mission" , "C:/Users/mboussai/Desktop/Mohamed/Qt Projects/FILES/mission",  "KML files (*.kml)"  );

       if ( !fileName.isEmpty() ) {
           manager->saveRoute(fileName);

       }
}
//add waypoint to the Flight Plan
void video::addPoint(qreal lon, qreal lat, GeoDataCoordinates::Unit){

  sprintf(numWpText,"%d",num_waypoint);
  temp = string(numWpText);
  textNumWaypoint = "# " + temp ;
  qstr = QString::fromStdString(textNumWaypoint);

  // Access the shared route request (start, destination and parameters)
  manager = ui->MarbleWidget_plan->model()->routingManager();
  manager_smallMap = ui->MarbleWidget_smallView->model()->routingManager();
  request = manager->routeRequest();
  request_smallMap = manager_smallMap->routeRequest();

 // add point to map
 request->append( GeoDataCoordinates( lon, lat, 0.0, GeoDataCoordinates::Radian ) );
 request->setName(num_waypoint,qstr);
 request_smallMap->append(GeoDataCoordinates( lon, lat, 0.0, GeoDataCoordinates::Radian ));
 num_waypoint++ ;
}



//affichage de l'intreface Flight Plan
void video::openNewWindowMain()
{
    ui->MarbleWidget_plan->show();
    ui->MarbleWidget_smallView->hide();
    ui->tableWidget->hide();
    ui->snapShoot_button->hide();
    ui->addMark_button->show();
    ui->actionFlight_plan->setEnabled(false);
    ui->actionFlight_data->setEnabled(true);
    ui->actionVideo->setEnabled(true);

}

//affichage de l'interface Flight DATA
void video::openNewWindowData()
{
    ui->MarbleWidget_plan->hide();
    ui->MarbleWidget_smallView->hide();
    ui->tableWidget->show();
    ui->snapShoot_button->hide();
    ui->addMark_button->hide();
    ui->actionFlight_plan->setEnabled(true);
    ui->actionFlight_data->setEnabled(false);
    ui->actionVideo->setEnabled(true);

}



//affichage de l'intreface VIDEO
void video::openNewWindowVideo()
{
    ui->MarbleWidget_plan->hide();
    ui->MarbleWidget_smallView->show();
    ui->tableWidget->hide();
    ui->snapShoot_button->show();
    ui->addMark_button->show();
    ui->actionFlight_plan->setEnabled(true);
    ui->actionFlight_data->setEnabled(true);
    ui->actionVideo->setEnabled(false);

}

void video::close()
{
    exit(0);
}


//Load une map avec la format .osm
void video::openNewMap()

{
    path = QFileDialog::getOpenFileName(this, "Load a map","C:/Users/mboussai/Desktop/Mohamed/Qt Projects/FILES/map", "OSM (*.osm)");
    QFileInfo inputFile(path);

        ui->MarbleWidget_plan->model()->removeGeoData(lastMap);
        ui->MarbleWidget_plan->model()->addGeoDataFile( inputFile.absoluteFilePath() );
        ui->MarbleWidget_plan->reloadMap();
        ui->MarbleWidget_plan->repaint();
        ui->MarbleWidget_smallView->model()->addGeoDataFile( inputFile.absoluteFilePath() );
        ui->MarbleWidget_smallView->reloadMap();
        ui->MarbleWidget_smallView->repaint();
        lastMap = inputFile.absoluteFilePath();

}
//si on click sur la map ( small view ) l'application sera dériger à l'intreface Flight Data

void video::switchToMap()
{

    ui->MarbleWidget_plan->show();
    ui->MarbleWidget_smallView->hide();
    ui->tableWidget->hide();
    ui->snapShoot_button->hide();
    ui->addMark_button->show();
    ui->actionFlight_plan->setEnabled(false);
    ui->actionFlight_data->setEnabled(true);
    ui->actionVideo->setEnabled(true);
}
