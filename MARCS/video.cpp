#include "video.h"
#include "ui_video.h"
#include "mission.h"
#include "waypoint.h"
#include <global.h>
#include <AbstractFloatItem.h>
#include <QPaintDevice>
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
#include <MarbleMap.h>
#include <GeoPainter.h>
#include <RouteRequest.h>
#include <RoutingManager.h>
#include <GeoDataDocument.h>
#include <GeoDataPlacemark.h>
#include <GeoDataLineString.h>
#include <GeoDataTreeModel.h>
#include <RoutingWidget.h>
#include <GeoPainter.h>
#include <ViewportParams.h>
#include <cstdio>
#include <sstream>

using namespace std;
using namespace Marble;

QListView *m_listView;
bool affichageList;
GeoDataPlacemark *place ;
GeoDataDocument *document ;
GeoDataCoordinates *tempo;
RoutingManager* manager ;
RouteRequest* request;
RoutingManager* manager_smallMap ;
RouteRequest* request_smallMap;
QList < waypoint* > wpListSave ;
QList <waypoint* > wpListOpen ;
QString lastMission;
QString lastMap;
int num_waypoint = 0;
string textNumWaypoint ;
string temp;
QString qstr ;
bool open = false ;
char* numWpText = new char[32];
GeoPainter* gp ;
QString fileOpened ;


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
    ui->label_Alt->hide();
    ui->label_HDG->hide();
    ui->label_Num_Waypoint->hide();
    ui->label_Time->hide();
    ui->lineEdit_HDG->hide();
    ui->lineEdit_Alt->hide();
    ui->timeEdit_Mission->hide();
    ui->line_2->hide();
    ui->SaveEdit_button->hide();
    ui->LoadData_button->hide();
    ui->comboBox_ListWaypoint->hide();
    ui->FinishEdit_button_2->hide();



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
    connect(ui->actionEdit_waypoint,SIGNAL(triggered()),this,SLOT(editWaypoint()));

    QPaintDevice *paintDevice = this;
   // QPaintEvent *evt ;
    QImage image;
    if (!isEnabled())
    {
        // If the globe covers fully the screen then we can use the faster
        // RGB32 as there are no translucent areas involved.
        QImage::Format imageFormat = ( ui->MarbleWidget_plan->viewport()->mapCoversViewport() )
                                     ? QImage::Format_RGB32
                                     : QImage::Format_ARGB32_Premultiplied;
        // Paint to an intermediate image
        image = QImage( rect().size(), imageFormat );

        image.fill( Qt::transparent );
        paintDevice = &image;

    }


gp = new GeoPainter ( paintDevice, ui->MarbleWidget_plan->viewport(), ui->MarbleWidget_plan->mapQuality() );
//ui->MarbleWidget_plan->paint( gp, evt->rect() );
drawMission();

}

video::~video()
{
    delete ui;
}


//Delete a mission from the view
void video::clearMission(){

    ui->MarbleWidget_plan->model()->removeGeoData(lastMission);
    ui->actionClear_mission->setEnabled(false);
    ui->actionSave_mission->setEnabled(false);

}

//Activate the adding points on the map
void video::activateAddingPoint(){
    ui->actionSave_mission->setEnabled(true);
    connect(ui->MarbleWidget_plan,SIGNAL(mouseClickGeoPosition(qreal,qreal,GeoDataCoordinates::Unit)),this,SLOT(addPoint(qreal,qreal,GeoDataCoordinates::Unit)));
    ui->actionStart_planning->setEnabled(false);
}

//Show the list of logs
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
    QString file ;
    file = "C:/Users/mboussai/Desktop/Mohamed/Qt Projects/MARCS/MissionXML/testParse.xml";

    string m ;
    string nameFileOpen;


    m = path.toUtf8().constData();
    size_t pos = m.find_last_of("/");
    if(pos != std::string::npos){

        nameFileOpen.assign(m.begin() + pos + 1, m.end()-4);
    }
      else
    {
      nameFileOpen = m;
  }
    string fileNameTempOpen = "C:/Users/mboussai/Desktop/Mohamed/Qt Projects/MARCS/MissionXML/" + nameFileOpen +".xml" ;
    fileOpened =  QString::fromStdString(fileNameTempOpen);

    // Access the shared route request (start, destination and parameters)
    manager = ui->MarbleWidget_plan->model()->routingManager();
    manager_smallMap = ui->MarbleWidget_smallView->model()->routingManager();
    request = manager->routeRequest();
    request_smallMap = manager_smallMap->routeRequest();
    request->append( GeoDataCoordinates( 0.0, 1.0, 0.0, GeoDataCoordinates::Radian ) );
    request_smallMap->append(GeoDataCoordinates( 0.0, 4.0, 0.0, GeoDataCoordinates::Radian ));

    request->clear();
    request_smallMap->clear();
    ui->MarbleWidget_plan->model()->addGeoDataFile( inputFile.absoluteFilePath() );
    ui->MarbleWidget_plan->repaint();
    ui->MarbleWidget_smallView->model()->addGeoDataFile( inputFile.absoluteFilePath() );
    lastMission = inputFile.absoluteFilePath();
    ui->actionClear_mission->setEnabled(true);
    lastMission = inputFile.absoluteFilePath();
    ui->actionStart_planning->setEnabled(true);

     wpListOpen = myMission.loadMission(wpListOpen,fileOpened);
    ui->actionEdit_waypoint->setEnabled(true);
    open = true ;


}
//Save a mission

void video::saveMission(){
    QString  fileName = QFileDialog::getSaveFileName( this,  "Save a mission" , "C:/Users/mboussai/Desktop/Mohamed/Qt Projects/FILES/mission",  "KML files (*.kml)"  );
    string m ;
    string nameFile;
    QString hideFile ;


    m = fileName.toUtf8().constData();
    size_t pos = m.find_last_of("/");
    if(pos != std::string::npos){

        nameFile.assign(m.begin() + pos + 1, m.end()-4);
    }
      else
    {
      nameFile = m;
  }
    string fileNameTemp = "C:/Users/mboussai/Desktop/Mohamed/Qt Projects/MARCS/MissionXML/" + nameFile +".xml" ;
    hideFile =  QString::fromStdString(fileNameTemp);

      if ( !fileName.isEmpty() ) {
          manager->saveRoute(fileName);

       }

    myMission.saveMission(wpListSave,hideFile);

    ui->actionSave_mission->setEnabled(false);

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

  tempo = new GeoDataCoordinates(lon,lat,0.0,GeoDataCoordinates::Radian);

 // add point to map
 request->append( GeoDataCoordinates( lon, lat, 0.0, GeoDataCoordinates::Radian ) );
 request->setName(num_waypoint,qstr);
 request_smallMap->append(GeoDataCoordinates( lon, lat, 0.0, GeoDataCoordinates::Radian ));
 request_smallMap->setName(num_waypoint,qstr);
 wpListSave.append(new waypoint(num_waypoint,tempo->longitude(GeoDataCoordinates::Degree),tempo->latitude(GeoDataCoordinates::Degree),100.0,90.0,60,1,1));
 num_waypoint++ ;

 ui->actionEdit_waypoint->setEnabled(true);
 open = false ;
}

//Show the page "Flight Plan"
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

//Show the page "Flight DATA"
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

//Show the page "VIDEO"
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

//Close the window
void video::close()
{
    exit(0);
}

//Load a map with the format .osm
void video::openNewMap()

{
    path = QFileDialog::getOpenFileName(this, "Load a map","C:/Users/mboussai/Desktop/Mohamed/Qt Projects/FILES/map", "OSM (*.osm)");
    QFileInfo inputFile(path);

        ui->MarbleWidget_plan->model()->removeGeoData(lastMap);
        ui->MarbleWidget_plan->model()->addGeoDataFile( inputFile.absoluteFilePath() );
        ui->MarbleWidget_smallView->model()->addGeoDataFile( inputFile.absoluteFilePath() );
        lastMap = inputFile.absoluteFilePath();

}
//Switch Mode ( Flight Plan , Video )

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

void video::drawMission(){

    GeoDataCoordinates France( 2.2, 48.52, 0.0, GeoDataCoordinates::Degree );
    gp->setPen( QColor( 0, 0, 0 ) );
    gp->drawText( France, "France" );

    GeoDataCoordinates Canada( -77.02, 48.52, 0.0, GeoDataCoordinates::Degree );
    gp->setPen( QColor( 0, 0, 0 ) );
    gp->drawText( Canada, "Canada" );

    //A line from France to Canada without tessellation

    GeoDataLineString shapeNoTessellation( NoTessellation );
    shapeNoTessellation << France << Canada;

    gp->setPen( oxygenSkyBlue4 );
    gp->drawPolyline( shapeNoTessellation );

    //The same line, but with tessellation

    GeoDataLineString shapeTessellate( Tessellate );
    shapeTessellate << France << Canada;

    gp->setPen( oxygenBrickRed4 );
    gp->drawPolyline( shapeTessellate );

    //Now following the latitude circles

    GeoDataLineString shapeLatitudeCircle( RespectLatitudeCircle | Tessellate );
    shapeLatitudeCircle << France << Canada;

    gp->setPen( oxygenForestGreen4 );
    gp->drawPolyline( shapeLatitudeCircle );
}

void video::editWaypoint(){
    ui->comboBox_ListWaypoint->show();
    ui->LoadData_button->show();
    ui->label_Num_Waypoint->show();

    ui->actionEdit_waypoint->setEnabled(false);
    ui->comboBox_ListWaypoint->clear();

    if ( open == false){

        for ( int i = 0 ; i < wpListSave.size(); i++){
            ui->comboBox_ListWaypoint->addItem(QString::number(i+1));
        }
    }
    else {
        for ( int i = 0 ; i < wpListOpen.size(); i++){
            ui->comboBox_ListWaypoint->addItem(QString::number(i+1));
        }

    }

    connect(ui->LoadData_button,SIGNAL(clicked()),this,SLOT(loadData()));


}

void video::loadData(){
    int h ;
    int m ;
    int s ;

    ui->label_Alt->show();
    ui->label_HDG->show();
    ui->label_Time->show();
    ui->lineEdit_Alt->show();
    ui->lineEdit_HDG->show();
    ui->timeEdit_Mission->show();
    ui->line_2->show();
    ui->SaveEdit_button->show();
    ui->FinishEdit_button_2->show();
    ui->SaveEdit_button->setEnabled(true);

    if ( open == false){
        h = wpListSave[ui->comboBox_ListWaypoint->currentIndex()]->getTime() / 3600 ;
        m = (wpListSave[ui->comboBox_ListWaypoint->currentIndex()]->getTime() % 3600)/60 ;
        s = (wpListSave[ui->comboBox_ListWaypoint->currentIndex()]->getTime() % 3600)%60  ;

       ui->lineEdit_Alt->setText(QString::number(wpListSave[ui->comboBox_ListWaypoint->currentIndex()]->getAlt()));
       ui->lineEdit_HDG->setText(QString::number(wpListSave[ui->comboBox_ListWaypoint->currentIndex()]->getHdg()));
       ui->timeEdit_Mission->setTime(QTime(h,m,s,00));

    }

    else {
        h = wpListOpen[ui->comboBox_ListWaypoint->currentIndex()]->getTime() / 3600 ;
        m = (wpListOpen[ui->comboBox_ListWaypoint->currentIndex()]->getTime() % 3600)/60 ;
        s = (wpListOpen[ui->comboBox_ListWaypoint->currentIndex()]->getTime() % 3600)%60  ;

       ui->lineEdit_Alt->setText(QString::number(wpListOpen[ui->comboBox_ListWaypoint->currentIndex()]->getAlt()));
       ui->lineEdit_HDG->setText(QString::number(wpListOpen[ui->comboBox_ListWaypoint->currentIndex()]->getHdg()));
       ui->timeEdit_Mission->setTime(QTime(h,m,s,00));

    }

    connect(ui->SaveEdit_button,SIGNAL(clicked()),this,SLOT(saveEditData()));
    connect(ui->FinishEdit_button_2,SIGNAL(clicked()),this,SLOT(finishEditData()));

   }

void video::saveEditData(){
    bool ok = false ;
    QTime tempo = ui->timeEdit_Mission->time();
    int time = tempo.hour() * 3600 + tempo.minute() * 60 + tempo.second() ;

    if ( open == false){

        wpListSave[ui->comboBox_ListWaypoint->currentIndex()]->setAlt(ui->lineEdit_Alt->text().toDouble(&ok));
        wpListSave[ui->comboBox_ListWaypoint->currentIndex()]->setHdg(ui->lineEdit_HDG->text().toDouble(&ok));
        wpListSave[ui->comboBox_ListWaypoint->currentIndex()]->setTime(time);

    }

    else {


        wpListOpen[ui->comboBox_ListWaypoint->currentIndex()]->setAlt(ui->lineEdit_Alt->text().toDouble(&ok));
        wpListOpen[ui->comboBox_ListWaypoint->currentIndex()]->setHdg(ui->lineEdit_HDG->text().toDouble(&ok));
        wpListOpen[ui->comboBox_ListWaypoint->currentIndex()]->setTime(time);
        myMission.saveMission(wpListOpen,fileOpened);

    }


    ui->SaveEdit_button->setEnabled(false);

}

void video::finishEditData(){


    ui->label_Alt->hide();
    ui->label_HDG->hide();
    ui->label_Num_Waypoint->hide();
    ui->label_Time->hide();
    ui->lineEdit_HDG->hide();
    ui->lineEdit_Alt->hide();
    ui->timeEdit_Mission->hide();
    ui->line_2->hide();
    ui->SaveEdit_button->hide();
    ui->LoadData_button->hide();
    ui->comboBox_ListWaypoint->hide();
    ui->FinishEdit_button_2->hide();
    ui->actionEdit_waypoint->setEnabled(true);


}


