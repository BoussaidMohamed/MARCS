#include "marcs.h"
#include "ui_marcs.h"

std::stringstream stream;

MARCS::MARCS(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MARCS)
{

    ui->setupUi(this);

    iconOn.addFile(QString::fromUtf8(":/new/prefix1/icon/engineOn.png"), QSize(), QIcon::Normal, QIcon::Off);
    iconOff.addFile(QString::fromUtf8(":/new/prefix1/icon/engineOff.png"), QSize(), QIcon::Normal, QIcon::Off);
    iconTakeOff.addFile(QString::fromUtf8(":/new/prefix1/icon/takeoff.png"), QSize(), QIcon::Normal, QIcon::Off);
    iconLand.addFile(QString::fromUtf8(":/new/prefix1/icon/land.png"), QSize(), QIcon::Normal, QIcon::Off);

    place =  new GeoDataPlacemark( "" );
    document = new GeoDataDocument();
    placemarkRPA = new GeoDataPlacemark( "" );
    placemarkHome = new GeoDataPlacemark( "" );
    placemarkMark = new GeoDataPlacemark( "" );
    styleArchRPA = new GeoDataStyle();
    styleArchHome = new GeoDataStyle();
    styleArchMark = new GeoDataStyle();

    documentRPA = new GeoDataDocument();
    documentHome = new GeoDataDocument();
    documentMark = new GeoDataDocument();
    myCom = new ComThread();
    numWpText = new char[32];

    ItemLon = new QTableWidgetItem;
    ItemLat = new QTableWidgetItem;
    ItemAlt = new QTableWidgetItem;
    ItemHdg = new QTableWidgetItem;
    ItemName = new QTableWidgetItem;

    ItemMarkAlt = new QTableWidgetItem;
    ItemMarkHdg = new QTableWidgetItem;
    ItemMarkLat = new QTableWidgetItem;
    ItemMarkLon = new QTableWidgetItem;
    ItemMarkNum = new QTableWidgetItem;

    m_pComWindow = new QMainWindow();
    layout = new QGridLayout();
    widget = new QWidget();
    m_pComList = new QComboBox();
    m_pValidCom = new QPushButton("Valid");
    m_pLabel = new QLabel("Serial port") ;

    layout->addWidget(m_pLabel , 0, 0);
    layout->addWidget(m_pComList, 0, 1);
    layout->addWidget(m_pValidCom, 1, 0, 1, 2);
    widget->setLayout(layout);
    widget->move(500,500);
    widget->setMaximumSize(180,100);
    widget->setMinimumSize(180,100);

    //config marble
    ui->MarbleWidget_smallView->setShowOverviewMap(false);
    ui->MarbleWidget_plan->setShowOverviewMap(false);
    ui->MarbleWidget_smallView->setShowScaleBar(false);
    ui->MarbleWidget_smallView->setShowCompass(false);
    ui->MarbleWidget_smallView->hide();
    ui->centralwidget->move(300,300);
    ui->led_button->setStyleSheet("* { background-color: rgb(0,100,0) }");

    //initialisation de l'intreface
    ui->tableWidget->hide();
    ui->snapShoot_button->hide();
    ui->actionFlight_plan->setEnabled(false);
    ui->actionFlight_data->setEnabled(true);
    ui->actionVideo->setEnabled(true);
    ui->listLog->hide();
    ui->actionEdit_waypoint->setEnabled(false);
    ui->tableMarkPoint->hide();
    ui->tableRPA->hide();
    ui->labelMark->hide();
    ui->labelMission->hide();
    ui->labelRPA->hide();
    ui->AddToMission_button->hide();
    ui->ListLogFinal->hide();
    ui->labelNext->setStyleSheet("* { color: rgb(0,100,0) }");
    ui->labelNow->setStyleSheet("* { color: rgb(255,0,255) }");
    ui->ListLogFinal->setStyleSheet("* { background-color: rgb(240,240,240) }");
    showEditWaypoint(false);

    //signal&&slot de l'application
    connect(ui->actionClose,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->led_button,SIGNAL(clicked()),this,SLOT(showList()));
    connect(ui->status_button,SIGNAL(clicked()),this,SLOT(showList()));
    connect(ui->actionLoad_map,SIGNAL(triggered()),this,SLOT(openNewMap()));
    connect(ui->actionSave_mission,SIGNAL(triggered()),this,SLOT(saveMission()));
    connect(ui->actionVideo,SIGNAL(triggered()),this,SLOT(openNewWindowVideo()));
    connect(ui->actionLoad_mission,SIGNAL(triggered()),this,SLOT(openMission()));
    connect(ui->actionClear_mission,SIGNAL(triggered()),this,SLOT(clearMission()));
    connect(ui->actionEdit_waypoint,SIGNAL(triggered()),this,SLOT(editWaypoint()));
    connect(ui->actionFlight_plan,SIGNAL(triggered()),this,SLOT(openNewWindowMain()));
    connect(ui->actionFlight_data,SIGNAL(triggered()),this,SLOT(openNewWindowData()));
    connect(ui->actionConnect_RPA,SIGNAL(triggered()),this,SLOT(showConnectDialog()));
    connect(ui->MarbleWidget_smallView,SIGNAL(rightClicked(qreal,qreal,GeoDataCoordinates::Unit)),this,SLOT(switchToMap()));
    connect(ui->MarbleWidget_plan,SIGNAL(rightClicked(qreal,qreal,GeoDataCoordinates::Unit)),this,SLOT(addPoint(qreal,qreal,GeoDataCoordinates::Unit)));
    connect(this,SIGNAL(clickOn()),CommunicationControl::getInstance(),SIGNAL(sendMotOn()));
    connect(this,SIGNAL(clickOff()),CommunicationControl::getInstance(),SIGNAL(sendMotOff()));
    connect(this,SIGNAL(clickOn()),this,SLOT(startMotors()));
    connect(this,SIGNAL(clickOff()),this,SLOT(stopMotors()));
    connect(this,SIGNAL(takeOff()),CommunicationControl::getInstance(),SIGNAL(sendLaunch()));
    connect(this,SIGNAL(landRPA()),CommunicationControl::getInstance(),SIGNAL(sendLand()));
    connect(this,SIGNAL(takeOff()),this,SLOT(fly()));
    connect(this,SIGNAL(landRPA()),this,SLOT(stopFly()));
    connect(ui->goHome_button,SIGNAL(clicked()),CommunicationControl::getInstance(),SIGNAL(sendHome()));
    connect(CommunicationControl::getInstance(), SIGNAL(updateHeight(double)), this, SLOT(setHeight(double)));
    connect(MissionControl::getInstance(), SIGNAL(batteryLevel(double)), this, SLOT(batteryLevel(double)));
    connect(MissionControl::getInstance(), SIGNAL(GPSLevel(int)), this, SLOT(GPSLevel(int)));
    connect(MissionControl::getInstance(), SIGNAL(GPSLevel(int)), this, SLOT(setTableRPA()));
    connect(this,SIGNAL(next(double,double,double,double)),CommunicationControl::getInstance(),SIGNAL(sendWaypoint(double,double,double,double)));
    connect(CommunicationControl::getInstance(),SIGNAL(sendWaypoint(double,double,double,double)),this,SLOT(goTo(double,double,double,double)));
    connect(ui->actionLog,SIGNAL(triggered()),this,SLOT(showLog()));
    connect(CommunicationControl::getInstance(),SIGNAL(XBeeDisconnected()),this,SLOT(XbeeDisconnect()));
    connect(CommunicationControl::getInstance(),SIGNAL(XBeeReconnected()),this,SLOT(XbeeConnect()));
    connect(CommunicationControl::getInstance(), SIGNAL(inFlight(char)), this, SLOT(updateMotors(char)));

    home = new waypoint(0,0,0,0,0,0,0,0);

    number = 0 ;
    num_add_waypoint = 0 ;
    num_waypoint = 0;
    m_map = 0;
    nbClickMotors=0;
    n = 0;
    rowAdd = 0;
    m_cMotorValue = 0 ;

    affichageList = false ;//etat d'affichage de la liste du log
    logShow40 = false ;
    logShow30 = false ;
    logShow20 = false ;
    logShow10 = false ;
    homeShow = false ;
    land = false ;
    open = false ;
    motorOn = false ;
    clear_mission = false ;
    nextIsShowing = false ;
    takeOffClicked = false ;
    gps0 = false ;
    gps1 = false;
    gps2 = false;
    gps3 = false;
    gps4 = false;
    gps5 = false;
    missionOpned = false ;
    motorTurn = false ;
}
MARCS::~MARCS()
{
    delete ui;
    delete place ;
    delete document ;
    delete documentRPA;
    delete documentHome;
    delete documentMark;
    delete tempo;
    delete manager ;
    delete request;
    delete manager_smallMap ;
    delete request_smallMap;
    delete[] numWpText;
    delete m_listView;
    delete ItemAlt;
    delete ItemHdg;
    delete ItemLat;
    delete ItemLon;
    delete ItemName;
    delete ItemMarkAlt;
    delete ItemMarkHdg;
    delete ItemMarkLat;
    delete ItemMarkLon;
    delete ItemMarkNum;
    delete placemarkRPA ;
    delete placemarkHome;
    delete placemarkMark ;
    delete styleArchRPA ;
    delete styleArchHome;
    delete styleArchMark ;
    myMission.~mission();
    wpListOpen.~QList();
    wpListSave.~QList();
    wpListAdd.~QList();
    m_mission.~QList();
    listPlaceMark.~QList();
}
//Delete a mission from the view
void MARCS::clearMission(){


    int reponse =  QMessageBox::question(this, "Clear Mission", "Do You Want To Clear This Mission?", QMessageBox::Yes | QMessageBox::No);

        if (reponse == QMessageBox::Yes)
        {
            ui->MarbleWidget_plan->model()->removeGeoData(lastMission);
            ui->MarbleWidget_smallView->model()->removeGeoData(lastMission);
            ui->actionClear_mission->setEnabled(false);
            ui->actionSave_mission->setEnabled(false);
            showEditWaypoint(false);
            ui->actionEdit_waypoint->setEnabled(false);
            ui->tableWidget->clear();
            clear_mission = true ;
            missionOpned = false ;
            ui->NextWaypoint_button->hide();
            ui->labelNext->hide();
            ui->labelNow->hide();
        }
        else if (reponse == QMessageBox::No)
        {
//rien
        }

}
//Show the list of logs
void MARCS::showList()
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
void MARCS::openMission(){

    path = QFileDialog::getOpenFileName(this, "Load a mission", "./mission/", "KML (*.kml)");

    if (path.length()>0){
        QFileInfo inputFile(path);
        string m ;
        string nameFileOpen;
        //get the path of the file
        m = path.toUtf8().constData();
        //get the file name selected by the user
        size_t pos = m.find_last_of("/");
        if(pos != std::string::npos){

            nameFileOpen.assign(m.begin() + pos + 1, m.end()-4);
        }
          else
        {
          nameFileOpen = m;
      }
        string fileNameTempOpen = "./MissionXML/" + nameFileOpen +".xml" ;
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
        ui->MarbleWidget_smallView->model()->addGeoDataFile( inputFile.absoluteFilePath() );
        ui->MarbleWidget_plan->model()->removeGeoData(lastMission);
        ui->MarbleWidget_smallView->model()->removeGeoData(lastMission);
        ui->MarbleWidget_plan->repaint();
        ui->MarbleWidget_smallView->repaint();
        ui->actionClear_mission->setEnabled(true);
        //Make a copy for the mission information on a QList
        lastMission = inputFile.absoluteFilePath();
        wpListOpen = myMission.loadMission(fileOpened);
        ui->actionEdit_waypoint->setEnabled(true);
        open = true ;
        num_waypoint=0;
        showEditWaypoint(false);
        wpListSave.clear();
        myMission.setWaypointList(wpListOpen);
        m_mission = myMission.getWaypointList();
        clear_mission = false ;
        if (takeOffClicked== true){
            ui->NextWaypoint_button->show();
            ui->labelNext->show();
            ui->labelNow->show();
        }
        else {
            //rien
        }
        missionOpned = true ;

    }
    else {
        //rien
    }

}
//Save a mission
void MARCS::saveMission(){

    QString  fileName = QFileDialog::getSaveFileName( this,  "Save a mission" , "./mission/",  "KML files (*.kml)"  );
    if(fileName.length()>0){

        QString hideFile ;
        string m ;
        string nameFile;

        m = fileName.toUtf8().constData();
        size_t pos = m.find_last_of("/");
        if(pos != std::string::npos){

            nameFile.assign(m.begin() + pos + 1, m.end()-4);
        }
          else
        {
          nameFile = m;
      }
        string fileNameTemp =  "./MissionXML/" + nameFile +".xml" ;
        hideFile =  QString::fromStdString(fileNameTemp);


        if (m_mission.length()==0){

            myMission.saveMissionKml(wpListSave,fileName);
            myMission.saveMission(wpListSave,hideFile);

        }
        else {

            myMission.saveMissionKml(myMission.getWaypointList(),fileName);
            myMission.saveMission(myMission.getWaypointList(),hideFile);

        }

        ui->actionSave_mission->setEnabled(false);
        num_waypoint = 0 ;

        QMessageBox::information(this, "Save Mission", "The Mission Was Saved");



    }
    else{
        //rien
    }

}
//add waypoint to the Flight Plan
void MARCS::addPoint(qreal lon, qreal lat, GeoDataCoordinates::Unit){
    clear_mission = false ;

  sprintf(numWpText,"%d",num_waypoint);
  temp = string(numWpText);
  textNumWaypoint = "" + temp ;
  qstr = QString::fromStdString(textNumWaypoint);

  // Access the shared route request (start, destination and parameters)
  manager = ui->MarbleWidget_plan->model()->routingManager();
  manager_smallMap = ui->MarbleWidget_smallView->model()->routingManager();
  request = manager->routeRequest();
  request_smallMap = manager_smallMap->routeRequest();
  tempo = new GeoDataCoordinates(lon,lat,0.0,GeoDataCoordinates::Radian);

 // add point to map
 request->append( GeoDataCoordinates(lon,lat, 0.0, GeoDataCoordinates::Degree ) );
 request->setName(num_waypoint,qstr);
 request_smallMap->append(GeoDataCoordinates( lon,lat, 0.0, GeoDataCoordinates::Degree ));
 request_smallMap->setName(num_waypoint,qstr);
 wpListSave.append(new waypoint(num_waypoint,tempo->longitude(GeoDataCoordinates::Radian),tempo->latitude(GeoDataCoordinates::Radian),100.0,90.0,60,1,1));
 num_waypoint++ ;

 ui->actionEdit_waypoint->setEnabled(true);
 ui->actionSave_mission->setEnabled(true);
 ui->MarbleWidget_plan->repaint();
 ui->MarbleWidget_smallView->repaint();
 open = false ;
 myMission.setWaypointList(wpListSave);
}
//Show the page "Flight Plan"
void MARCS::openNewWindowMain()
{
    ui->MarbleWidget_plan->show();
    ui->MarbleWidget_smallView->hide();
    ui->tableWidget->hide();
    ui->snapShoot_button->hide();
    ui->addMark_button->show();
    ui->actionFlight_plan->setEnabled(false);
    ui->actionFlight_data->setEnabled(true);
    ui->actionVideo->setEnabled(true);
    ui->tableMarkPoint->hide();
    ui->tableRPA->hide();
    ui->labelMark->hide();
    ui->labelMission->hide();
    ui->labelRPA->hide();
    ui->ListLogFinal->hide();
    ui->actionLog->setEnabled(true);
    ui->AddToMission_button->hide();
    if ( missionOpned == true && nextIsShowing == true){
        ui->NextWaypoint_button->show();
        ui->labelNext->show();
        ui->labelNow->show();
    }
    else{
        ui->NextWaypoint_button->hide();
        ui->labelNext->hide();
        ui->labelNow->hide();
    }

}
//Show the page "Flight DATA"
void MARCS::openNewWindowData()
{
    ui->MarbleWidget_plan->hide();
    ui->MarbleWidget_smallView->hide();
    ui->tableWidget->show();
    ui->tableMarkPoint->show();
    ui->tableRPA->show();
    ui->labelMark->show();
    ui->labelMission->show();
    ui->labelRPA->show();
    ui->snapShoot_button->hide();
    ui->addMark_button->hide();
    ui->actionFlight_plan->setEnabled(true);
    ui->actionFlight_data->setEnabled(false);
    ui->actionVideo->setEnabled(true);
    ui->AddToMission_button->show();
    ui->ListLogFinal->hide();
    ui->actionLog->setEnabled(true);
    if ( missionOpned == true && nextIsShowing == true){
        ui->NextWaypoint_button->show();
        ui->labelNext->show();
        ui->labelNow->show();
    }
    else {
        ui->NextWaypoint_button->hide();
        ui->labelNext->hide();
        ui->labelNow->hide();
    }
    showEditWaypoint(false);

}
//Show the page "VIDEO"
void MARCS::openNewWindowVideo()
{
    ui->MarbleWidget_plan->hide();
    ui->MarbleWidget_smallView->show();
    ui->tableWidget->hide();
    ui->snapShoot_button->show();
    ui->addMark_button->show();
    ui->actionFlight_plan->setEnabled(true);
    ui->actionFlight_data->setEnabled(true);
    ui->actionVideo->setEnabled(false);
    ui->tableMarkPoint->hide();
    ui->tableRPA->hide();
    ui->labelMark->hide();
    ui->labelMission->hide();
    ui->labelRPA->hide();
    ui->ListLogFinal->hide();
    ui->actionLog->setEnabled(true);
    showEditWaypoint(false);
    ui->AddToMission_button->hide();
    ui->actionEdit_waypoint->setEnabled(false);
    if ( missionOpned == true && nextIsShowing == true ){
        ui->NextWaypoint_button->show();
        ui->labelNext->show();
        ui->labelNow->show();
    }
    else {
        ui->NextWaypoint_button->hide();
        ui->labelNext->hide();
        ui->labelNow->hide();
    }

}

void MARCS::showLog(){
    ui->ListLogFinal->show();
    ui->MarbleWidget_plan->hide();
    ui->MarbleWidget_smallView->hide();
    ui->tableWidget->hide();
    ui->snapShoot_button->hide();
    ui->addMark_button->hide();
    ui->actionFlight_plan->setEnabled(true);
    ui->actionFlight_data->setEnabled(true);
    ui->actionVideo->setEnabled(true);
    ui->actionLog->setEnabled(false);
    ui->tableMarkPoint->hide();
    ui->tableRPA->hide();
    ui->labelMark->hide();
    ui->labelMission->hide();
    ui->labelRPA->hide();
    showEditWaypoint(false);

    ui->AddToMission_button->hide();
    ui->NextWaypoint_button->hide();
    ui->labelNext->hide();
    ui->labelNow->hide();
}

//Close the window
void MARCS::close()
{
    exit(0);
}
//Load a map with the format .osm
void MARCS::openNewMap()
{
    path = QFileDialog::getOpenFileName(this, "Load a map","./map/", "OSM (*.osm)");
    QFileInfo inputFile(path);

    if ( m_map == 0  ) {
        ui->MarbleWidget_plan->model()->addGeoDataFile( inputFile.absoluteFilePath() );
        ui->MarbleWidget_smallView->model()->addGeoDataFile(inputFile.absoluteFilePath());
        lastMap = inputFile.absoluteFilePath();
        m_map = 1 ;
   }

    else {
        ui->MarbleWidget_plan->model()->removeGeoData(lastMap);
        ui->MarbleWidget_smallView->model()->removeGeoData(lastMap);
        ui->MarbleWidget_plan->model()->addGeoDataFile( inputFile.absoluteFilePath() );
        ui->MarbleWidget_smallView->model()->addGeoDataFile(inputFile.absoluteFilePath());
        lastMap = inputFile.absoluteFilePath();
    }

}
//Switch Mode ( Flight Plan , Video )
void MARCS::switchToMap()
{
openNewWindowMain();
}
//Display the edit waypoint zone
void MARCS::editWaypoint(){
int i = 0;
int maxCB = ui->comboBox_ListWaypoint->count();

    if(ui->comboBox_ListWaypoint->count()>0 ){
        while (i < maxCB)
            {
                ui->comboBox_ListWaypoint->removeItem(0);
                i++;
            }
    }
    else {
        //rien
    }
    ui->comboBox_ListWaypoint->show();
    ui->label_Num_Waypoint->show();
    ui->actionEdit_waypoint->setEnabled(false);
    if ( open == false){

        for ( int i = 0 ; i < wpListSave.size(); i++){
            ui->comboBox_ListWaypoint->addItem(QString::number(i));
        }
    }

    else {
        for ( int i = 0 ; i < wpListOpen.size(); i++){
            ui->comboBox_ListWaypoint->addItem(QString::number(i));
        }
    }
    ui->NextWaypoint_button->hide();
    ui->labelNext->hide();
    ui->labelNow->hide();

}
//Get information of each waypoints and show it
void MARCS::loadData(){
    int h ;
    int m ;
    int s ;

   showEditWaypoint(true);

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
    ui->SaveEdit_button->setEnabled(true);
   }
//Save the modification on the XML file
void MARCS::saveEditData(){
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
//Close/hide the edit waypoint zone
void MARCS::finishEditData(){

showEditWaypoint(false);
ui->actionEdit_waypoint->setEnabled(true);
ui->actionSave_mission->setEnabled(true);
if (nextIsShowing == true){
    ui->NextWaypoint_button->show();
    ui->labelNext->show();
    ui->labelNow->show();
}
}
//Display the edit waypoint zone
void MARCS::showEditWaypoint(bool show){

    if ( show == true ){


        ui->label_Alt->show();
        ui->label_HDG->show();
        ui->label_Num_Waypoint->show();
        ui->label_Time->show();
        ui->lineEdit_HDG->show();
        ui->lineEdit_Alt->show();
        ui->timeEdit_Mission->show();
        ui->line_2->show();
        ui->SaveEdit_button->show();
        ui->Delete_button->show();
        ui->comboBox_ListWaypoint->show();
        ui->FinishEdit_button_2->show();

    }

    else {

        ui->label_Alt->hide();
        ui->label_HDG->hide();
        ui->label_Num_Waypoint->hide();
        ui->label_Time->hide();
        ui->lineEdit_HDG->hide();
        ui->lineEdit_Alt->hide();
        ui->timeEdit_Mission->hide();
        ui->line_2->hide();
        ui->SaveEdit_button->hide();
        ui->Delete_button->hide();
        ui->comboBox_ListWaypoint->hide();
        ui->FinishEdit_button_2->hide();

    }

}
//Load information of the waypoint that user chose
void MARCS::on_comboBox_ListWaypoint_currentIndexChanged(int index)
{
    int h ;
    int m ;
    int s ;

   showEditWaypoint(true);

    if ( open == false){
        h = wpListSave[index]->getTime() / 3600 ;
        m = (wpListSave[index]->getTime() % 3600)/60 ;
        s = (wpListSave[index]->getTime() % 3600)%60  ;
       ui->lineEdit_Alt->setText(QString::number(wpListSave[index]->getAlt()));
       ui->lineEdit_HDG->setText(QString::number(wpListSave[index]->getHdg()));
       ui->timeEdit_Mission->setTime(QTime(h,m,s,00));

    }

    else {
        h = wpListOpen[index]->getTime() / 3600 ;
        m = (wpListOpen[index]->getTime() % 3600)/60 ;
        s = (wpListOpen[index]->getTime() % 3600)%60  ;

       ui->lineEdit_Alt->setText(QString::number(wpListOpen[index]->getAlt()));
       ui->lineEdit_HDG->setText(QString::number(wpListOpen[index]->getHdg()));
       ui->timeEdit_Mission->setTime(QTime(h,m,s,00));

    }

    connect(ui->SaveEdit_button,SIGNAL(clicked()),this,SLOT(saveEditData()));
    connect(ui->FinishEdit_button_2,SIGNAL(clicked()),this,SLOT(finishEditData()));
    ui->SaveEdit_button->setEnabled(true);

}
//Delete a waypoint from the XML,KML and the Marble view
void MARCS::on_Delete_button_clicked()
{

    int index = ui->comboBox_ListWaypoint->currentIndex() ;

    int reponse =  QMessageBox::question(this, "Delete Waypoint", "Do You Want To Delete The Waypoint Number "+QString::number(index)+" ?", QMessageBox::Yes | QMessageBox::No);

        if (reponse == QMessageBox::Yes)
        {
            if ( open == false){

                 if (wpListSave.size() == 1 )
                 {
                     request->remove(index);
                     request_smallMap->remove(index);
                     ui->MarbleWidget_plan->repaint();
                     ui->MarbleWidget_smallView->repaint();
                     wpListSave.removeAt(index);
                     ui->comboBox_ListWaypoint->clear();

                     for ( int i = 0 ; i < wpListSave.size(); i++){
                         sprintf(numWpText,"%d",i);
                         temp = string(numWpText);
                         textNumWaypoint = "" + temp ;
                         qstr = QString::fromStdString(textNumWaypoint);
                         ui->comboBox_ListWaypoint->addItem(QString::number(i));
                         request->setName(i,qstr);

                 }
                     showEditWaypoint(false);
                 }
                 else {

                     request->remove(index);
                     request_smallMap->remove(index);
                     ui->MarbleWidget_plan->repaint();
                     ui->MarbleWidget_smallView->repaint();
                     wpListSave.removeAt(index);
                     ui->comboBox_ListWaypoint->clear();

                     for ( int i = 0 ; i < wpListSave.size(); i++)
                     {
                         sprintf(numWpText,"%d",i);
                         temp = string(numWpText);
                         textNumWaypoint = "" + temp ;
                         qstr = QString::fromStdString(textNumWaypoint);
                         ui->comboBox_ListWaypoint->addItem(QString::number(i));
                         request->setName(i,qstr);
                         wpListSave[i]->setNum(i);
                     }

                 }


             }

             else {
                     if (wpListOpen.size() == 1 ){

                         wpListOpen.removeAt(index);
                         ui->comboBox_ListWaypoint->clear();

                         for ( int i = 0 ; i < wpListOpen.size(); i++)
                         {
                             ui->comboBox_ListWaypoint->addItem(QString::number(i));
                             wpListOpen[i]->setNum(i);
                         }

                         showEditWaypoint(false);

                         myMission.saveMission(wpListOpen,fileOpened);
                         wpListOpen =  myMission.loadMission(fileOpened);
                         ui->MarbleWidget_plan->model()->removeGeoData(lastMission);
                         ui->MarbleWidget_smallView->model()->removeGeoData(lastMission);
                         myMission.saveMissionKml(wpListOpen,lastMission);
                         ui->MarbleWidget_plan->model()->addGeoDataFile( lastMission );
                         ui->MarbleWidget_smallView->model()->addGeoDataFile( lastMission );
                         ui->MarbleWidget_plan->repaint();
                         ui->actionClear_mission->setEnabled(true);

                     }
                     else {

                 showEditWaypoint(true);
                 wpListOpen.removeAt(index);
                 ui->comboBox_ListWaypoint->clear();

                 for ( int i = 0 ; i < wpListOpen.size(); i++){
                     ui->comboBox_ListWaypoint->addItem(QString::number(i));
                     wpListOpen[i]->setNum(i);
                 }

                 myMission.saveMission(wpListOpen,fileOpened);
                 wpListOpen =  myMission.loadMission(fileOpened);
                 ui->MarbleWidget_plan->model()->removeGeoData(lastMission);
                 ui->MarbleWidget_smallView->model()->removeGeoData(lastMission);
                 myMission.saveMissionKml(wpListOpen,lastMission);
                 ui->MarbleWidget_plan->model()->addGeoDataFile( lastMission );
                 ui->MarbleWidget_smallView->model()->addGeoDataFile( lastMission );
                 ui->MarbleWidget_plan->repaint();
                 ui->MarbleWidget_smallView->repaint();
                 ui->actionClear_mission->setEnabled(true);


         }

         }

        }
        else if (reponse == QMessageBox::No)
        {
//rien
        }



   }
//Altitude value control ( it must be < 151 )
void MARCS::on_lineEdit_Alt_textChanged(QString )
{
    bool ok = false ;
    if (ui->lineEdit_Alt->text().toInt(&ok,10)>150){
        ui->label_Alt->setText("<font color='red'>Alt  ( m ):</font>");
        ui->SaveEdit_button->setEnabled(false);
    }
    else {

        ui->label_Alt->setText("<font color='black'>Alt  ( m ):</font>");
        ui->SaveEdit_button->setEnabled(true);
    }
}
//Heading value control ( it must be < 360 )
void MARCS::on_lineEdit_HDG_textEdited(QString )
{
    bool ok = false ;
    if (ui->lineEdit_HDG->text().toInt(&ok,10)>359){
        ui->label_HDG->setText("<font color='red'>HDG (&deg;) :</font>");
        ui->SaveEdit_button->setEnabled(false);
    }
    else {
        ui->label_HDG->setText("<font color='black'>HDG (&deg;) :</font>");
        ui->SaveEdit_button->setEnabled(true);

    }
}
//Time value control ( it must be < 15 min )
void MARCS::on_timeEdit_Mission_timeChanged(const QTime &date)
{

    if (( date.hour()*3600+date.minute()*60+date.second() ) > 900 ) {
        ui->label_Time->setText("<font color='red'>Time :</font>");
         ui->SaveEdit_button->setEnabled(false);
    }
    else {
        ui->label_Time->setText("<font color='black'>Time :</font>");
         ui->SaveEdit_button->setEnabled(true);
    }

}
//Show Connect Dialog
void MARCS::showConnectDialog(){

    QList<QextPortInfo> ports = QextSerialEnumerator::getPorts();

    m_pComList->clear();

    foreach (QextPortInfo port, ports) {
        if (port.portName.at(0).toAscii()=='C'){

           m_pComList->addItem(port.portName);

       }
    }
    widget->show();
    connect(m_pValidCom,SIGNAL(clicked()),this,SLOT(validCom()));

    }
//Event listener of closing the window
void MARCS::closeEvent(QCloseEvent *event)
{
    close();
}
//emit 2 different signals from the some button
void MARCS::on_start_button_clicked()
{
    if ( motorOn == false ){
        emit clickOn();
        motorOn = true ;
        qDebug()<<"MotorOn";
    }
    else {
        emit clickOff();
        motorOn = false ;
        qDebug()<<"MotorOff";
    }
}
//Save the serial port
void MARCS::validCom(){
    ui->start_button->setEnabled(true);
    widget->hide();
    CommunicationControl::getInstance()->start(m_pComList->currentText());

}
//start motor of the RPA
void MARCS::startMotors(){
    if (nbClickMotors == 0){
            myCom->sendMotOn();
            ui->start_button->setIcon(iconOn);
            ui->start_button->setIconSize(QSize(61, 151));
            nbClickMotors++;
      }
    else {
            myCom->sendMotOn();
            ui->start_button->setIcon(iconOn);
            ui->start_button->setIconSize(QSize(61, 151));
            nbClickMotors++;
        }

    ui->excute_button->setEnabled(true);
    home->setNum(0);
    home->setLong(RPA::getInstance()->getCoordinates()->getLongitude());
    home->setLat(RPA::getInstance()->getCoordinates()->getLatitude());
    home->setAlt(RPA::getInstance()->getHeight());
    home->setHdg(RPA::getInstance()->getHeading());
    createHomeMark(RPA::getInstance()->getCoordinates()->getLongitude(),RPA::getInstance()->getCoordinates()->getLatitude(),GeoDataCoordinates::Degree);

   connect(this,SIGNAL(clickOff()),CommunicationControl::getInstance(),SIGNAL(sendMotOff()));
   qDebug()<<"StartMotors";

}
//stop the motor of the RPA
void MARCS::stopMotors(){
    connect(this,SIGNAL(clickOn()),CommunicationControl::getInstance(),SIGNAL(sendMotOn()));
        myCom->sendMotOff();
        ui->start_button->setIcon(iconOff);
        ui->start_button->setIconSize(QSize(61, 151));
        ui->excute_button->setEnabled(false);
        ui->goHome_button->setEnabled(false);
        ui->addMark_button->setEnabled(false);
        ui->snapShoot_button->setEnabled(false);
        ui->battery_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/0.png")));
        ui->label_Altitude_2->setText("0.0");
        ui->excute_button->setIcon(iconTakeOff);
        land= false ;
       // CommunicationControl::getInstance()->stop();
        ui->NextWaypoint_button->hide();
        ui->labelNext->hide();
        ui->labelNow->hide();


        qDebug()<<"StopMotors";
}
//get the batteryLevel
void MARCS::batteryLevel(double p_pValue){
    p_pValue = (int)(p_pValue * 10) / 10.;
    int dureeDeVie = (((15*60)*(((p_pValue - 9.5) / (12.5 - 9.5)) * 100))/100) ;
    int pourcentage =(((p_pValue - 9.5) / (12.5 - 9.5)) * 100);
    int dureeDeVie_Min = dureeDeVie/60 ;
    int dureeDeVie_Sec = (dureeDeVie%60)%60 ;
    double latRPA= RPA::getInstance()->getCoordinates()->getLatitude();
    double lonRPA = RPA::getInstance()->getCoordinates()->getLongitude();

    time_t now1 = time (0);
    struct tm * now2 = localtime( & now1);
    string temp ;
    char* time_mission = new char[32];
    QString timeShow ;

    sprintf(time_mission,"%d-%d-%d %d:%d:%d",(now2->tm_year + 1900 ) ,(now2->tm_mon+1), (now2->tm_mday),(now2->tm_hour), (now2->tm_min),now2->tm_sec);
    temp = string(time_mission);
    string time_mission_temp = "" + temp ;
    timeShow = QString::fromStdString(time_mission_temp);

          if (pourcentage == 100 )
         { ui->battery_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/100.png")));
              ui->label_Time_Left->setText("<font color='green'>Time Left : </font>");
              ui->Time_left_point->setText("<font color='green'>: </font>");
              ui->Time_left_Min->setStyleSheet("QLabel { color : green; }");
              ui->Time_left_Seconde->setStyleSheet("QLabel { color : green; }");
              if ((dureeDeVie_Min) >=  10 ) {
                  ui->Time_left_Min->setText("<font color='green'></font>"+QString::number(dureeDeVie_Min));
              }

              else {
                  ui->Time_left_Min->setText("<font color='green'>0</font>"+QString::number(dureeDeVie_Min));
              }

              if ((dureeDeVie_Sec)>=10) {
                  ui->Time_left_Seconde->setText("<font color='green'></font>"+(QString::number(dureeDeVie_Sec)));
              }
              else {
                  ui->Time_left_Seconde->setText("<font color='green'>0</font>"+(QString::number(dureeDeVie_Sec)));
              }
          }
          else if (pourcentage >= 90 && pourcentage < 100 )
          {   ui->battery_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/90.png")));
              ui->led_button->setStyleSheet("* { background-color: rgb(0,100,0) }");
              ui->label_Time_Left->setText("<font color='green'>Time Left : </font>");
              ui->Time_left_point->setText("<font color='green'>: </font>");
              ui->Time_left_Min->setStyleSheet("QLabel { color : green; }");
              ui->Time_left_Seconde->setStyleSheet("QLabel { color : green; }");

              if ((dureeDeVie_Min) >=  10 ) {
                  ui->Time_left_Min->setText("<font color='green'></font>"+QString::number(dureeDeVie_Min));
              }

              else {
                  ui->Time_left_Min->setText("<font color='green'>0</font>"+QString::number(dureeDeVie_Min));
              }

              if ((dureeDeVie_Sec)>=10) {
                  ui->Time_left_Seconde->setText("<font color='green'></font>"+(QString::number(dureeDeVie_Sec)));
              }
              else {
                  ui->Time_left_Seconde->setText("<font color='green'>0</font>"+(QString::number(dureeDeVie_Sec)));
              }
         }
          else if (pourcentage >= 80 && pourcentage < 90 )
          {
              ui->battery_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/80.png")));
              ui->label_Time_Left->setText("<font color='green'>Time Left : </font>");
              ui->Time_left_point->setText("<font color='green'>: </font>");
              ui->Time_left_Min->setStyleSheet("QLabel { color : green; }");
              ui->Time_left_Seconde->setStyleSheet("QLabel { color : green; }");
              if ((dureeDeVie_Min) >=  10 ) {
                  ui->Time_left_Min->setText("<font color='green'></font>"+QString::number(dureeDeVie_Min));
              }

              else {
                  ui->Time_left_Min->setText("<font color='green'>0</font>"+QString::number(dureeDeVie_Min));
              }

              if ((dureeDeVie_Sec)>=10) {
                  ui->Time_left_Seconde->setText("<font color='green'></font>"+(QString::number(dureeDeVie_Sec)));
              }
              else {
                  ui->Time_left_Seconde->setText("<font color='green'>0</font>"+(QString::number(dureeDeVie_Sec)));
              }
         }
          else if (pourcentage >= 70 && pourcentage < 80 )
          {   ui->battery_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/70.png")));
              ui->label_Time_Left->setText("<font color='#4AA440'>Time Left : </font>");
              ui->Time_left_point->setText("<font color='#4AA440'>: </font>");
              ui->Time_left_Min->setStyleSheet("QLabel { color : green; }");
              ui->Time_left_Seconde->setStyleSheet("QLabel { color : green; }");
              if ((dureeDeVie_Min) >=  10 ) {
                  ui->Time_left_Min->setText("<font color='green'></font>"+QString::number(dureeDeVie_Min));
              }

              else {
                  ui->Time_left_Min->setText("<font color='green'>0</font>"+QString::number(dureeDeVie_Min));
              }

              if ((dureeDeVie_Sec)>=10) {
                  ui->Time_left_Seconde->setText("<font color='green'></font>"+(QString::number(dureeDeVie_Sec)));
              }
              else {
                  ui->Time_left_Seconde->setText("<font color='green'>0</font>"+(QString::number(dureeDeVie_Sec)));
              }
         }
          else if (pourcentage >= 60 && pourcentage < 70 )
          {   ui->battery_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/60.png")));
              ui->label_Time_Left->setText("<font color='green'>Time Left : </font>");
              ui->Time_left_point->setText("<font color='green'>: </font>");
              ui->Time_left_Min->setStyleSheet("QLabel { color : green; }");
              ui->Time_left_Seconde->setStyleSheet("QLabel { color : green; }");
              if ((dureeDeVie_Min) >=  10 ) {
                  ui->Time_left_Min->setText("<font color='green'></font>"+QString::number(dureeDeVie_Min));
              }

              else {
                  ui->Time_left_Min->setText("<font color='green'>0</font>"+QString::number(dureeDeVie_Min));
              }

              if ((dureeDeVie_Sec)>=10) {
                  ui->Time_left_Seconde->setText("<font color='green'></font>"+(QString::number(dureeDeVie_Sec)));
              }
              else {
                  ui->Time_left_Seconde->setText("<font color='green'>0</font>"+(QString::number(dureeDeVie_Sec)));
              }
         }
          else if (pourcentage >= 50 && pourcentage < 60 )
          { ui->battery_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/50.png")));
              ui->label_Time_Left->setText("<font color='green'>Time Left : </font>");
              ui->Time_left_point->setText("<font color='green'>: </font>");
              ui->Time_left_Min->setStyleSheet("QLabel { color : green; }");
              ui->Time_left_Seconde->setStyleSheet("QLabel { color : green; }");

              if ((dureeDeVie_Min) >=  10 ) {
                  ui->Time_left_Min->setText("<font color='green'></font>"+QString::number(dureeDeVie_Min));
              }

              else {
                  ui->Time_left_Min->setText("<font color='green'>0</font>"+QString::number(dureeDeVie_Min));
              }

              if ((dureeDeVie_Sec)>=10) {
                  ui->Time_left_Seconde->setText("<font color='green'></font>"+(QString::number(dureeDeVie_Sec)));
              }
              else {
                  ui->Time_left_Seconde->setText("<font color='green'>0</font>"+(QString::number(dureeDeVie_Sec)));
              }
         }
          else if (pourcentage >= 40 && pourcentage < 50 )
          {   ui->battery_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/40.png")));
              ui->label_Time_Left->setText("<font color='green'>Time Left : </font>");
              ui->Time_left_point->setText("<font color='green'>: </font>");
              ui->Time_left_Min->setStyleSheet("QLabel { color : green; }");
              ui->Time_left_Seconde->setStyleSheet("QLabel { color : green; }");
              if ((dureeDeVie_Min) >=  10 ) {
                  ui->Time_left_Min->setText("<font color='green'></font>"+QString::number(dureeDeVie_Min));
              }

              else {
                  ui->Time_left_Min->setText("<font color='green'>0</font>"+QString::number(dureeDeVie_Min));
              }

              if ((dureeDeVie_Sec)>=10) {
                  ui->Time_left_Seconde->setText("<font color='green'></font>"+(QString::number(dureeDeVie_Sec)));
              }
              else {
                  ui->Time_left_Seconde->setText("<font color='green'>0</font>"+(QString::number(dureeDeVie_Sec)));
              }
         }
          else if (pourcentage >= 30 && pourcentage < 40 )
          {   ui->battery_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/30.png")));
              ui->led_button->setStyleSheet("* { background-color: rgb(255,127,36) }");
              ui->label_Time_Left->setText("<font color='orange'>Time Left : </font>");
              ui->Time_left_point->setText("<font color='orange'>: </font>");
              ui->Time_left_Min->setStyleSheet("QLabel { color : orange; }");
              ui->Time_left_Seconde->setStyleSheet("QLabel { color : orange; }");
                if (logShow40 == false){
                  QListWidgetItem* pItem =new QListWidgetItem("Low battery and time left is :"+ QString::number(dureeDeVie_Min)+ " min.");
                  pItem->setTextColor(QColor::fromRgb(255,127,36));
                  ui->listLog->addItem(pItem);

                  QListWidgetItem* pItemLog =new QListWidgetItem(timeShow+" : Low battery and time left is :"+ QString::number(dureeDeVie_Min)+ " min.");
                  pItemLog->setTextColor(QColor::fromRgb(255,127,36));
                  ui->ListLogFinal->addItem(pItemLog);

                  logShow40= true ;

              }
                if ((dureeDeVie_Min) >=  10 ) {
                    ui->Time_left_Min->setText("<font color='orange'></font>"+QString::number(dureeDeVie_Min));
                }

                else {
                    ui->Time_left_Min->setText("<font color='orange'>0</font>"+QString::number(dureeDeVie_Min));
                }

                if ((dureeDeVie_Sec)>=10) {
                    ui->Time_left_Seconde->setText("<font color='orange'></font>"+(QString::number(dureeDeVie_Sec)));
                }
                else {
                    ui->Time_left_Seconde->setText("<font color='orange'>0</font>"+(QString::number(dureeDeVie_Sec)));
                }
         }
          else if (pourcentage >= 20 && pourcentage < 30 )
          {   ui->battery_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/20.png")));
              ui->led_button->setStyleSheet("* { background-color: rgb(255,127,36) }");
              ui->label_Time_Left->setText("<font color='orange'>Time Left : </font>");
              ui->Time_left_point->setText("<font color='orange'>: </font>");
              ui->Time_left_Min->setStyleSheet("QLabel { color : orange; }");
              ui->Time_left_Seconde->setStyleSheet("QLabel { color : orange; }");
              if (logShow30 == false){

                  QListWidgetItem* pItem =new QListWidgetItem("Low battery and time left is :"+ QString::number(dureeDeVie_Min)+ " min.");
                  pItem->setTextColor(QColor::fromRgb(255,127,36));
                  ui->listLog->addItem(pItem);

                  QListWidgetItem* pItemLog =new QListWidgetItem(timeShow+" : Low battery and time left is :"+ QString::number(dureeDeVie_Min)+ " min.");
                  pItemLog->setTextColor(QColor::fromRgb(255,127,36));
                  ui->ListLogFinal->addItem(pItemLog);

                  logShow30= true ;
              }

              if ((dureeDeVie_Min) >=  10 ) {
                  ui->Time_left_Min->setText("<font color='orange'></font>"+QString::number(dureeDeVie_Min));
              }

              else {
                  ui->Time_left_Min->setText("<font color='orange'>0</font>"+QString::number(dureeDeVie_Min));
              }

              if ((dureeDeVie_Sec)>=10) {
                  ui->Time_left_Seconde->setText("<font color='orange'></font>"+(QString::number(dureeDeVie_Sec)));
              }
              else {
                  ui->Time_left_Seconde->setText("<font color='orange'>0</font>"+(QString::number(dureeDeVie_Sec)));
              }
         }
          else if (pourcentage >= 10 && pourcentage < 20 )
          {
              ui->battery_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/10.png")));
              ui->label_Time_Left->setText("<font color='red'>Time Left : </font>");
              ui->Time_left_point->setText("<font color='red'>: </font>");
              ui->led_button->setStyleSheet("* { background-color: rgb(255,0,0) }");
              ui->Time_left_Min->setStyleSheet("QLabel { color : red; }");
              ui->Time_left_Seconde->setStyleSheet("QLabel { color : red; }");
              if (logShow20 == false){

                  QListWidgetItem* pItem =new QListWidgetItem("Low battery and time left is :"+ QString::number(dureeDeVie_Min)+ " min.");
                  pItem->setTextColor(QColor::fromRgb(255,0,0));
                  ui->listLog->addItem(pItem);

                  QListWidgetItem* pItemLog =new QListWidgetItem(timeShow+" : Low battery and time left is :"+ QString::number(dureeDeVie_Min)+ " min.");
                  pItemLog->setTextColor(QColor::fromRgb(255,0,0));
                  ui->ListLogFinal->addItem(pItemLog);

                  logShow20= true ;
              }
              if ((dureeDeVie_Min) >=  10 ) {
                  ui->Time_left_Min->setText("<font color='red'></font>"+QString::number(dureeDeVie_Min));
              }

              else {
                  ui->Time_left_Min->setText("<font color='red'>0</font>"+QString::number(dureeDeVie_Min));
              }
              if ((dureeDeVie_Sec)>=10) {
                  ui->Time_left_Seconde->setText("<font color='red'></font>"+(QString::number(dureeDeVie_Sec)));
              }
              else {
                  ui->Time_left_Seconde->setText("<font color='red'>0</font>"+(QString::number(dureeDeVie_Sec)));
              }
         }
          else if (pourcentage >= 0 && pourcentage < 10 )
          {
              ui->battery_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/0.png")));
              ui->label_Time_Left->setText("<font color='red'>Time Left : </font>");
              ui->Time_left_point->setText("<font color='red'>: </font>");
              ui->led_button->setStyleSheet("* { background-color: rgb(255,0,0) }");
              ui->Time_left_Min->setStyleSheet("QLabel { color : red; }");
              ui->Time_left_Seconde->setStyleSheet("QLabel { color : red; }");
              if (logShow10 == false){

                  QListWidgetItem* pItem =new QListWidgetItem("Low battery and time left is :"+ QString::number(dureeDeVie_Min)+ " min.");
                  pItem->setTextColor(QColor::fromRgb(255,0,0));
                  ui->listLog->addItem(pItem);

                  QListWidgetItem* pItemLog =new QListWidgetItem(timeShow+" : Low battery and time left is :"+ QString::number(dureeDeVie_Min)+ " min.");
                  pItemLog->setTextColor(QColor::fromRgb(255,0,0));
                  ui->ListLogFinal->addItem(pItemLog);

                  logShow10= true ;
              }
              if ((dureeDeVie_Min) >=  10 ) {
                  ui->Time_left_Min->setText("<font color='red'></font>"+QString::number(dureeDeVie_Min));
              }

              else {
                  ui->Time_left_Min->setText("<font color='red'>0</font>"+QString::number(dureeDeVie_Min));
              }

              if ((dureeDeVie_Sec)>=10) {
                  ui->Time_left_Seconde->setText("<font color='red'></font>"+(QString::number(dureeDeVie_Sec)));
              }
              else {
                  ui->Time_left_Seconde->setText("<font color='red'>0</font>"+(QString::number(dureeDeVie_Sec)));
              }
         }
          if(lonRPA < 200 && latRPA < 200){

              createRpaMark(RPA::getInstance()->getHeading(),lonRPA,latRPA,GeoDataCoordinates::Degree);
          }
          else {
              //rien
          }


          delete[] time_mission ;

}
//get the altitude of the RPA
void MARCS::setHeight(double p_dHeight){
    if (p_dHeight > 0 ) {

        ui->label_Altitude_2->setText(QString::number(p_dHeight));
        item = new QTableWidgetItem(QString::number(RPA::getInstance()->getCoordinates()->getLongitude()),1);
        ui->tableRPA->setItem(1,3,item);

    }
    else {

        ui->label_Altitude_2->setText("0.0");
        item = new QTableWidgetItem(QString::number(0),1);
        ui->tableRPA->setItem(1,3,item);

    }
    ui->label_Altitude_2->setText(QString::number(p_dHeight));
    item = new QTableWidgetItem(QString::number(RPA::getInstance()->getCoordinates()->getLongitude()),1);
    ui->tableRPA->setItem(1,3,item);
}
//Create the icon of the RPA to be add later in the map
void MARCS::createStyleRPA (GeoDataStyle *style , double hdg ) {
    GeoDataIconStyle iconStyle;
    if ( hdg >= 0 && hdg < 20){
        iconStyle.setIconPath(QString::fromUtf8(":/new/prefix1/icon/Arrow/0.png"));
    }
    else  if ( hdg >= 20 && hdg < 40){
         iconStyle.setIconPath(QString::fromUtf8(":/new/prefix1/icon/Arrow/20.png"));
    }
    else  if ( hdg >= 40 && hdg < 60){
         iconStyle.setIconPath(QString::fromUtf8(":/new/prefix1/icon/Arrow/40.png"));
    }
    else  if ( hdg >= 60 && hdg < 80){
         iconStyle.setIconPath(QString::fromUtf8(":/new/prefix1/icon/Arrow/60.png"));
    }
    else  if ( hdg >= 80 && hdg < 100){
         iconStyle.setIconPath(QString::fromUtf8(":/new/prefix1/icon/Arrow/80.png"));
    }
    else  if ( hdg >= 100 && hdg < 120){
         iconStyle.setIconPath(QString::fromUtf8(":/new/prefix1/icon/Arrow/100.png"));
    }
    else  if ( hdg >= 120 && hdg < 140){
         iconStyle.setIconPath(QString::fromUtf8(":/new/prefix1/icon/Arrow/120.png"));
    }
    else  if ( hdg >= 140 && hdg < 160){
         iconStyle.setIconPath(QString::fromUtf8(":/new/prefix1/icon/Arrow/140.png"));
    }
    else  if ( hdg >= 160 && hdg < 180){
         iconStyle.setIconPath(QString::fromUtf8(":/new/prefix1/icon/Arrow/160.png"));
    }
    else  if ( hdg >= 180 && hdg < 200){
         iconStyle.setIconPath(QString::fromUtf8(":/new/prefix1/icon/Arrow/180.png"));
    }
    else  if ( hdg >= 200 && hdg < 220){
         iconStyle.setIconPath(QString::fromUtf8(":/new/prefix1/icon/Arrow/200.png"));
    }
    else  if ( hdg >= 220 && hdg < 240){
         iconStyle.setIconPath(QString::fromUtf8(":/new/prefix1/icon/Arrow/220.png"));
    }
    else  if ( hdg >= 240 && hdg < 260){
         iconStyle.setIconPath(QString::fromUtf8(":/new/prefix1/icon/Arrow/240.png"));
    }
    else  if ( hdg >= 260 && hdg < 280){
         iconStyle.setIconPath(QString::fromUtf8(":/new/prefix1/icon/Arrow/260.png"));
    }
    else  if ( hdg >= 280 && hdg < 300){
         iconStyle.setIconPath(QString::fromUtf8(":/new/prefix1/icon/Arrow/280.png"));
    }
    else  if ( hdg >= 300 && hdg < 320){
         iconStyle.setIconPath(QString::fromUtf8(":/new/prefix1/icon/Arrow/300.png"));
    }
    else  if ( hdg >= 320 && hdg < 340){
         iconStyle.setIconPath(QString::fromUtf8(":/new/prefix1/icon/Arrow/320.png"));
    }
    else  if ( hdg >= 340 && hdg < 360){
         iconStyle.setIconPath(QString::fromUtf8(":/new/prefix1/icon/Arrow/340.png"));
    }

    style->setIconStyle( iconStyle );
}
//add mark of the RPA in the map
void MARCS::createRpaMark(double hdg ,double lon, double lat, GeoDataCoordinates::Unit){

    //Create the placemark representing the Arch of Triumph
    placemarkRPA->setCoordinate( lon, lat, 0, GeoDataCoordinates::Degree );
    createStyleRPA (  styleArchRPA, hdg );
    placemarkRPA->setStyle( styleArchRPA ) ;

     //Create the document and add the two placemarks (the point representing the Arch of Triumph and the polygon with Bucharest's boundaries)
     if(number==0){
         documentRPA->append( placemarkRPA );
       ui->MarbleWidget_plan->model()->treeModel()->addDocument(documentRPA);
              }
     else {
         documentRPA->remove(0);
         documentRPA->append( placemarkRPA );
         ui->MarbleWidget_plan->model()->treeModel()->update();

     }
   number ++ ;
}//add mark of the RPA in the map

//Create the icon of Home to be add later in the map
void MARCS::createStyleHome (GeoDataStyle *style  ) {
    GeoDataIconStyle iconStyle;
    iconStyle.setIconPath(QString::fromUtf8(":/new/prefix1/icon/home.png"));
    style->setIconStyle( iconStyle );
}
//add mark of Home in the map
void MARCS::createHomeMark(double lon, double lat, GeoDataCoordinates::Unit){
    //Create the placemark representing the Arch of Triumph
    placemarkHome->setCoordinate( lon, lat, 0, GeoDataCoordinates::Degree );
     createStyleHome (  styleArchHome );
     placemarkHome->setStyle( styleArchHome ) ;
     //Create the document and add the two placemarks (the point representing the Arch of Triumph and the polygon with Bucharest's boundaries)
     if(homeShow == false){
         documentHome->append( placemarkHome );
         ui->MarbleWidget_plan->model()->treeModel()->addDocument(documentHome);
         homeShow = true ;
              }
     else {
         //
     }
}
//Create the icon of AddMark to be add later in the map
void MARCS::createStyleAddMark (GeoDataStyle *style  ) {
    GeoDataIconStyle iconStyle;
    iconStyle.setIconPath(QString::fromUtf8(":/new/prefix1/icon/addMark.png"));
    style->setIconStyle( iconStyle );
}
//add mark of AddMark in the map
void MARCS::createAddMark(double lon, double lat, GeoDataCoordinates::Unit){
    //Create the placemark representing the Arch of Triumph

    placemarkMark->setCoordinate(lon,lat,0,GeoDataCoordinates::Degree);
    createStyleAddMark (  styleArchMark );
    placemarkMark->setStyle( styleArchMark ) ;

  if ( num_add_waypoint == 0){
         //Create the document and add the two placemarks (the point representing the Arch of Triumph and the polygon with Bucharest's boundaries)
             documentMark->append( placemarkMark );
             ui->MarbleWidget_plan->model()->treeModel()->addDocument(documentMark);
      }
 else {
      for (int i = 0 ; i < num_add_waypoint ; i++)   {
          documentMark->append(placemarkMark);

      }


      }


  ui->MarbleWidget_plan->model()->treeModel()->update();
  num_add_waypoint++;
    }
//emit 2 signals from the execute button
void MARCS::on_excute_button_clicked()
{
    if ( land == false ){
        emit takeOff();
        land = true ;
    }
    else {
        emit landRPA();
        land = false ;
    }

}
//takeoff the RPA
void MARCS::fly(){
    ui->goHome_button->setEnabled(true);
    ui->addMark_button->setEnabled(true);
    ui->excute_button->setIcon(iconLand);
    if (m_mission.length()> 0){
        ui->NextWaypoint_button->show();
        ui->labelNext->show();
        ui->labelNow->show();
        nextIsShowing = true ;
    }
    else {
        //rien
    }

takeOffClicked = true ;
   }
//land the RPA
void MARCS::stopFly(){
    ui->goHome_button->setEnabled(false);
    ui->addMark_button->setEnabled(false);
    ui->excute_button->setIcon(iconTakeOff);
    myCom->sendLand();

    home->setLong(0);
    home->setLat(0);
    home->setAlt(0);
    home->setHdg(0);
    ui->NextWaypoint_button->hide();
    ui->labelNext->hide();
    ui->labelNow->hide();
    nextIsShowing = false ;
    takeOffClicked= false ;
}
void MARCS::on_addMark_button_clicked()
{
    double lon = RPA::getInstance()->getCoordinates()->getLongitude();
    double lat = RPA::getInstance()->getCoordinates()->getLatitude();
    double alt = RPA::getInstance()->getHeight();
    double hdg = RPA::getInstance()->getHeading();


          ui->tableMarkPoint->setItem(num_add_waypoint,0,new QTableWidgetItem(QString::number(num_add_waypoint)));
          ui->tableMarkPoint->setItem(num_add_waypoint,1,new QTableWidgetItem(QString::number(lon)));
          ui->tableMarkPoint->setItem(num_add_waypoint,2,new QTableWidgetItem(QString::number(lat)));
          ui->tableMarkPoint->setItem(num_add_waypoint,3,new QTableWidgetItem(QString::number(alt)));
          ui->tableMarkPoint->setItem(num_add_waypoint,4,new QTableWidgetItem(QString::number(hdg)));

          ui->tableMarkPoint->item(num_add_waypoint,0)->setBackgroundColor(Qt::green);
          wpListAdd.append(new waypoint(num_add_waypoint,lon,lat,alt,hdg,0,0,0));

          createAddMark(RPA::getInstance()->getCoordinates()->getLongitude(),RPA::getInstance()->getCoordinates()->getLatitude(),GeoDataCoordinates::Degree);

          ui->AddToMission_button->setEnabled(true);


}
//Check the GPS Level
void MARCS::GPSLevel(int p_value){

    time_t now1 = time (0);
    struct tm * now2 = localtime( & now1);
    string temp ;
    char* time_mission = new char[32];
    QString timeShow ;

    sprintf(time_mission,"%d-%d-%d %d:%d:%d",(now2->tm_year + 1900 ) ,(now2->tm_mon+1), (now2->tm_mday),(now2->tm_hour), (now2->tm_min),now2->tm_sec);
    temp = string(time_mission);
    string time_mission_temp = "" + temp ;
    timeShow = QString::fromStdString(time_mission_temp);


    if (p_value == 0 && gps0 == false){
        QListWidgetItem* pItem =new QListWidgetItem("Low GPS Signal :"+ QString::number(p_value)+ "/7");
        pItem->setTextColor(QColor::fromRgb(255,0,0));
        ui->listLog->addItem(pItem);

        QListWidgetItem* pItemLog =new QListWidgetItem(timeShow+" : Low GPS Signal :"+ QString::number(p_value)+ "/7");
        pItemLog->setTextColor(QColor::fromRgb(255,0,0));
        ui->ListLogFinal->addItem(pItemLog);

        ui->led_button->setStyleSheet("* { background-color: rgb(255,0,0) }");
        gps0 = true ;

    }
    else if (p_value == 1 && gps1 == false){
        QListWidgetItem* pItem =new QListWidgetItem("Low GPS Signal :"+ QString::number(p_value)+ "/7");
        pItem->setTextColor(QColor::fromRgb(255,0,0));
        ui->listLog->addItem(pItem);

        QListWidgetItem* pItemLog =new QListWidgetItem(timeShow+" : Low GPS Signal :"+ QString::number(p_value)+ "/7");
        pItemLog->setTextColor(QColor::fromRgb(255,0,0));
        ui->ListLogFinal->addItem(pItemLog);


        ui->led_button->setStyleSheet("* { background-color: rgb(255,0,0) }");
        gps1 = true ;
        gps2 = false ;
        gps3 = false ;
        gps4 = false ;
        gps5 = false ;

    }else if (p_value == 2 && gps2 == false){
        QListWidgetItem* pItem =new QListWidgetItem("Low GPS Signal :"+ QString::number(p_value)+ "/7");
        pItem->setTextColor(QColor::fromRgb(255,0,0));
        ui->listLog->addItem(pItem);

        QListWidgetItem* pItemLog =new QListWidgetItem(timeShow+" : Low GPS Signal :"+ QString::number(p_value)+ "/7");
        pItemLog->setTextColor(QColor::fromRgb(255,0,0));
        ui->ListLogFinal->addItem(pItemLog);

        ui->led_button->setStyleSheet("* { background-color: rgb(255,0,0) }");
        gps1 = false ;
        gps2 = true ;
        gps3 = false ;
        gps4 = false ;
        gps5 = false ;

    }else if (p_value == 3 && gps3 == false){
        QListWidgetItem* pItem =new QListWidgetItem("Low GPS Signal :"+ QString::number(p_value)+ "/7");
        pItem->setTextColor(QColor::fromRgb(255,0,0));
        ui->listLog->addItem(pItem);

        QListWidgetItem* pItemLog =new QListWidgetItem(timeShow+" : Low GPS Signal :"+ QString::number(p_value)+ "/7");
        pItemLog->setTextColor(QColor::fromRgb(255,0,0));
        ui->ListLogFinal->addItem(pItemLog);

        ui->led_button->setStyleSheet("* { background-color: rgb(255,0,0) }");
        gps1 = false ;
        gps2 = false ;
        gps3 = true ;
        gps4 = false ;
        gps5 = false ;

    }else if (p_value == 4 && gps4 == false){
        QListWidgetItem* pItem =new QListWidgetItem("Low GPS Signal :"+ QString::number(p_value)+ "/7");
        pItem->setTextColor(QColor::fromRgb(255,0,0));
        ui->listLog->addItem(pItem);

        QListWidgetItem* pItemLog =new QListWidgetItem(timeShow+" : Low GPS Signal :"+ QString::number(p_value)+ "/7");
        pItemLog->setTextColor(QColor::fromRgb(255,0,0));
        ui->ListLogFinal->addItem(pItemLog);

        ui->led_button->setStyleSheet("* { background-color: rgb(255,0,0) }");
        gps1 = false ;
        gps2 = false ;
        gps3 = false ;
        gps4 = true ;
        gps5 = false ;


    }
    else if (p_value > 4 && gps5 == false) {
        QListWidgetItem* pItem =new QListWidgetItem("GPS Signal :"+ QString::number(p_value)+ "/7");
        pItem->setTextColor(QColor::fromRgb(0,100,0));
        ui->listLog->addItem(pItem);

        QListWidgetItem* pItemLog =new QListWidgetItem(timeShow+" : GPS Signal :"+ QString::number(p_value)+ "/7");
        pItemLog->setTextColor(QColor::fromRgb(0,100,0));
        ui->ListLogFinal->addItem(pItemLog);

        ui->led_button->setStyleSheet("* { background-color: rgb(0,100,0) }");
        gps1 = false ;
        gps2 = false ;
        gps3 = false ;
        gps4 = false ;
        gps5 = true ;
    }

    delete[] time_mission;

   }
//add data info to RPA table
void MARCS::setTableRPA(){


    ui->tableRPA->setItem(0,0,  new QTableWidgetItem("RPA"));
    ui->tableRPA->setItem(0,1 , new QTableWidgetItem(QString::number(RPA::getInstance()->getCoordinates()->getLongitude())));
    ui->tableRPA->setItem(0,2 , new QTableWidgetItem(QString::number(RPA::getInstance()->getCoordinates()->getLatitude())));
    ui->tableRPA->setItem(0,3 , new QTableWidgetItem(QString::number(RPA::getInstance()->getHeight())));
    ui->tableRPA->setItem(0,4 , new QTableWidgetItem(QString::number(RPA::getInstance()->getHeading())));
    ui->tableRPA->item(0, 0)->setBackground(Qt::green);
    ui->tableRPA->item(0, 1)->setBackground(Qt::green);
    ui->tableRPA->item(0, 2)->setBackground(Qt::green);
    ui->tableRPA->item(0, 3)->setBackground(Qt::green);
    ui->tableRPA->item(0, 4)->setBackground(Qt::green);

    if ( clear_mission == false){
        m_mission = myMission.getWaypointList();

         for (int i = 0 ; i < m_mission.length() ;  i++) {

               ui->tableWidget->setItem(i+1,0,new QTableWidgetItem(QString::number(m_mission[i]->getNum())));
               ui->tableWidget->setItem(i+1,1,new QTableWidgetItem(QString::number(m_mission[i]->getLong())));
               ui->tableWidget->setItem(i+1,2,new QTableWidgetItem(QString::number(m_mission[i]->getLat())));
               ui->tableWidget->setItem(i+1,3,new QTableWidgetItem(QString::number(m_mission[i]->getAlt())));
               ui->tableWidget->setItem(i+1,4,new QTableWidgetItem(QString::number(m_mission[i]->getHdg())));
               ui->tableWidget->item(i+1,0)->setBackgroundColor(Qt::yellow);

         }
    }
    else {

        //rien
    }

    ui->tableWidget->setItem(0,0,new QTableWidgetItem("HOME"));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem(QString::number(home->getLong())));
    ui->tableWidget->setItem(0,2,new QTableWidgetItem(QString::number(home->getLat())));
    ui->tableWidget->setItem(0,3,new QTableWidgetItem(QString::number(home->getAlt())));
    ui->tableWidget->setItem(0,4,new QTableWidgetItem(QString::number(home->getHdg())));
    ui->tableWidget->item(0,0)->setBackgroundColor(Qt::green);
    ui->tableWidget->item(0,1)->setBackgroundColor(Qt::green);
    ui->tableWidget->item(0,2)->setBackgroundColor(Qt::green);
    ui->tableWidget->item(0,3)->setBackgroundColor(Qt::green);
    ui->tableWidget->item(0,4)->setBackgroundColor(Qt::green);




}
void MARCS::on_AddToMission_button_clicked()
{
    bool ok= false ;
    if ( rowAdd == 0){
        rowAdd = m_mission.length()+1;
    }
    else {
        //rien
    }
    ui->tableWidget->setItem(rowAdd,0,new QTableWidgetItem(QString::number(rowAdd-1)));
    ui->tableWidget->setItem(rowAdd,1,new QTableWidgetItem(QString::number(wpListAdd[ui->tableMarkPoint->currentItem()->text().toInt(&ok,10)]->getLong())));
    ui->tableWidget->setItem(rowAdd,2,new QTableWidgetItem(QString::number(wpListAdd[ui->tableMarkPoint->currentItem()->text().toInt(&ok,10)]->getLat())));
    ui->tableWidget->setItem(rowAdd,3,new QTableWidgetItem(QString::number(wpListAdd[ui->tableMarkPoint->currentItem()->text().toInt(&ok,10)]->getAlt())));
    ui->tableWidget->setItem(rowAdd,4,new QTableWidgetItem(QString::number(wpListAdd[ui->tableMarkPoint->currentItem()->text().toInt(&ok,10)]->getHdg())));
    ui->tableWidget->item(rowAdd,0)->setBackgroundColor(Qt::green);
    ui->tableWidget->item(rowAdd,1)->setBackgroundColor(Qt::green);
    ui->tableWidget->item(rowAdd,2)->setBackgroundColor(Qt::green);
    ui->tableWidget->item(rowAdd,3)->setBackgroundColor(Qt::green);
    ui->tableWidget->item(rowAdd,4)->setBackgroundColor(Qt::green);
    m_mission.append(new waypoint(rowAdd-1,
                     wpListAdd[ui->tableMarkPoint->currentItem()->text().toInt(&ok,10)]->getLong(),
                     wpListAdd[ui->tableMarkPoint->currentItem()->text().toInt(&ok,10)]->getLat(),
                     wpListAdd[ui->tableMarkPoint->currentItem()->text().toInt(&ok,10)]->getAlt(),
                     wpListAdd[ui->tableMarkPoint->currentItem()->text().toInt(&ok,10)]->getHdg(),60,1,0));
 rowAdd++;
 ui->actionSave_mission->setEnabled(true);
 myMission.setWaypointList(m_mission);

}
void MARCS::on_NextWaypoint_button_clicked()
{
    if ( n < m_mission.length()){

        emit next(m_mission[n]->getLong(),m_mission[n]->getLat(),m_mission[n]->getAlt(),n);
        if (n<m_mission.length()-1){

            ui->labelNext->setText(QString::number(n+1));
            ui->labelNow->setText(QString::number(n));
        }
        else {
            //rien
        }
        n++;
    }
    else {
        //
    }
}
void MARCS::XbeeConnect(){
    time_t now1 = time (0);
    struct tm * now2 = localtime( & now1);
    string temp ;
    char* time_mission = new char[32];
    QString timeShow ;

    sprintf(time_mission,"%d-%d-%d %d:%d:%d",(now2->tm_year + 1900 ) ,(now2->tm_mon+1), (now2->tm_mday),(now2->tm_hour), (now2->tm_min),now2->tm_sec);
    temp = string(time_mission);
    string time_mission_temp = "" + temp ;
    timeShow = QString::fromStdString(time_mission_temp);

    QListWidgetItem* pItem =new QListWidgetItem("Xbee Reconnected.");
    pItem->setTextColor(QColor::fromRgb(0,100,0));
    ui->listLog->addItem(pItem);

    QListWidgetItem* pItemLog =new QListWidgetItem(timeShow+" : Xbee Reconnected.");
    pItemLog->setTextColor(QColor::fromRgb(0,100,0));
    ui->ListLogFinal->addItem(pItemLog);

    ui->led_button->setStyleSheet("* { background-color: rgb(0,100,0) }");
    delete[] time_mission ;
}
void MARCS::XbeeDisconnect(){
    time_t now1 = time (0);
    struct tm * now2 = localtime( & now1);
    string temp ;
    char* time_mission = new char[32];
    QString timeShow ;

    sprintf(time_mission,"%d-%d-%d %d:%d:%d",(now2->tm_year + 1900 ) ,(now2->tm_mon+1), (now2->tm_mday),(now2->tm_hour), (now2->tm_min),now2->tm_sec);
    temp = string(time_mission);
    string time_mission_temp = "" + temp ;
    timeShow = QString::fromStdString(time_mission_temp);

    QListWidgetItem* pItem =new QListWidgetItem("Xbee Disconnected.");
    pItem->setTextColor(QColor::fromRgb(255,0,0));
    ui->listLog->addItem(pItem);

    QListWidgetItem* pItemLog =new QListWidgetItem(timeShow+" : Xbee Disconnected.");
    pItemLog->setTextColor(QColor::fromRgb(255,0,0));
    ui->ListLogFinal->addItem(pItemLog);

    ui->led_button->setStyleSheet("* { background-color: rgb(255,0,0) }");
    delete[] time_mission ;

}

void MARCS::updateMotors(char p_cValue){

    if (m_cMotorValue != p_cValue)
    {
        m_cMotorValue = p_cValue;

        if ( p_cValue == 1){

            ui->start_button->setIcon(iconOn);
            ui->start_button->setIconSize(QSize(61, 151));
            ui->excute_button->setEnabled(true);
            home->setNum(0);
            home->setLong(RPA::getInstance()->getCoordinates()->getLongitude());
            home->setLat(RPA::getInstance()->getCoordinates()->getLatitude());
            home->setAlt(RPA::getInstance()->getHeight());
            home->setHdg(RPA::getInstance()->getHeading());
            createHomeMark(RPA::getInstance()->getCoordinates()->getLongitude(),RPA::getInstance()->getCoordinates()->getLatitude(),GeoDataCoordinates::Degree);
            nbClickMotors = 1 ;
            motorOn = true ;


        }
        else {
            motorTurn = false ;
            stopMotors();
        }
    }
}

void MARCS::goTo(double lon, double lat, double alt, double n){
    myCom->sendGoTo();
}
