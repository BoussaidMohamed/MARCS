#include "marcs.h"
#include "ui_marcs.h"
#include "QGridLayout"
#include "qextserialenumerator.h"

MARCS::MARCS(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MARCS)
{
    ui->setupUi(this);

    iconOn.addFile(QString::fromUtf8(":/new/prefix1/icon/engineOn.png"), QSize(), QIcon::Normal, QIcon::Off);
    iconOff.addFile(QString::fromUtf8(":/new/prefix1/icon/engineOff.png"), QSize(), QIcon::Normal, QIcon::Off);
    nbClickMotors=0;

    affichageList = false ;//etat d'affichage de la liste du log

    place =  new GeoDataPlacemark( "" );
    document = new GeoDataDocument();
    documentRPA = new GeoDataDocument();
    myMissionControl= MissionControl::getInstance();

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

    myCom = new ComThread();
    myComControl=CommunicationControl::getInstance();
    QList<QextPortInfo> ports = QextSerialEnumerator::getPorts();

    foreach (QextPortInfo port, ports) {
        if (port.portName.at(0).toAscii()=='C'){

           m_pComList->addItem(port.portName);

       }
    }

    num_waypoint = 0;
    m_map = 0;
    numWpText = new char[32];
    open = false ;
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
    ui->actionEdit_waypoint->setEnabled(false);
    //ui->stop_button->hide();
    showEditWaypoint(false);

    //signal&&slot de l'application
    connect(ui->actionClose,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->led_button,SIGNAL(clicked()),this,SLOT(afficheList()));
    connect(ui->status_button,SIGNAL(clicked()),this,SLOT(afficheList()));
    connect(ui->actionLoad_map,SIGNAL(triggered()),this,SLOT(openNewMap()));
    connect(ui->actionSave_mission,SIGNAL(triggered()),this,SLOT(saveMission()));
    connect(ui->actionVideo,SIGNAL(triggered()),this,SLOT(openNewWindowVideo()));
    connect(ui->actionLoad_mission,SIGNAL(triggered()),this,SLOT(openMission()));
    connect(ui->actionClear_mission,SIGNAL(triggered()),this,SLOT(clearMission()));
    connect(ui->actionEdit_waypoint,SIGNAL(triggered()),this,SLOT(editWaypoint()));
    connect(ui->actionFlight_plan,SIGNAL(triggered()),this,SLOT(openNewWindowMain()));
    connect(ui->actionFlight_data,SIGNAL(triggered()),this,SLOT(openNewWindowData()));
    connect(ui->actionConnect_RPA,SIGNAL(triggered()),this,SLOT(showConnectDialog()));
    connect(ui->MarbleWidget_smallView,SIGNAL(mouseClickGeoPosition(qreal,qreal,GeoDataCoordinates::Unit)),this,SLOT(switchToMap()));
    connect(ui->MarbleWidget_plan,SIGNAL(rightClicked(qreal,qreal,GeoDataCoordinates::Unit)),this,SLOT(addPoint(qreal,qreal,GeoDataCoordinates::Unit)));
    connect(this,SIGNAL(clickOn()),CommunicationControl::getInstance(),SIGNAL(sendMotOn()));
    connect(this,SIGNAL(clickOff()),CommunicationControl::getInstance(),SIGNAL(sendMotOff()));
    connect(this,SIGNAL(clickOn()),this,SLOT(startMotors()));
    connect(this,SIGNAL(clickOff()),this,SLOT(stopMotors()));
    connect(CommunicationControl::getInstance(), SIGNAL(updateHeight(double)), this, SLOT(setHeight(double)));

    connect(MissionControl::getInstance(), SIGNAL(batteryLevel(double)), this, SLOT(batteryLevel(double)));



    paintDevice = this;


        // If the globe covers fully the screen then we can use the faster
        // RGB32 as there are no translucent areas involved.
        QImage::Format imageFormat = ( ui->MarbleWidget_plan->viewport()->mapCoversViewport() )
                                     ? QImage::Format_RGB32
                                     : QImage::Format_ARGB32_Premultiplied;
        // Paint to an intermediate image
        image = QImage( ui->MarbleWidget_plan->width(),ui->MarbleWidget_plan->height(), imageFormat );

        image.fill( Qt::transparent );
        paintDevice = &image;

    gp = new GeoPainter ( paintDevice, ui->MarbleWidget_plan->viewport(), ui->MarbleWidget_plan->mapQuality() );
    drawMission(gp);

    motorOn = false ;
    ui->centralwidget->move(300,300);
    number = 0 ;

}

MARCS::~MARCS()
{
    delete ui;
    delete gp;
    delete paintDevice ;
    delete place ;
    delete document ;
    delete documentRPA;
    delete tempo;
    delete manager ;
    delete request;
    delete manager_smallMap ;
    delete request_smallMap;
    delete[] numWpText;
    delete m_listView;
    myMission.~mission();
    image.~QImage();
    wpListOpen.~QList();
    wpListSave.~QList();
}




//Delete a mission from the view
void MARCS::clearMission(){

    ui->MarbleWidget_plan->model()->removeGeoData(lastMission);
    ui->MarbleWidget_smallView->model()->removeGeoData(lastMission);
    ui->actionClear_mission->setEnabled(false);
    ui->actionSave_mission->setEnabled(false);
    showEditWaypoint(false);
    ui->actionEdit_waypoint->setEnabled(false);

}


//Show the list of logs
void MARCS::afficheList()
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

    path = QFileDialog::getOpenFileName(this, "Load a mission", "./FILES/mission/", "KML (*.kml)");
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
    string fileNameTempOpen = "./FILES/MissionXML/" + nameFileOpen +".xml" ;
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
    ui->actionClear_mission->setEnabled(true);
    //Make a copy for the mission information on a QList
    lastMission = inputFile.absoluteFilePath();
    wpListOpen = myMission.loadMission(fileOpened);
    ui->actionEdit_waypoint->setEnabled(true);
    open = true ;
    num_waypoint=0;
    showEditWaypoint(false);
    wpListSave.clear();
}

//Save a mission
void MARCS::saveMission(){

    QString  fileName = QFileDialog::getSaveFileName( this,  "Save a mission" , "./FILES/mission/",  "KML files (*.kml)"  );
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
    string fileNameTemp =  "./FILES/MissionXML/" + nameFile +".xml" ;
    hideFile =  QString::fromStdString(fileNameTemp);


    myMission.saveMissionKml(wpListSave,fileName);
    myMission.saveMission(wpListSave,hideFile);
    ui->actionSave_mission->setEnabled(false);
    num_waypoint = 0 ;


}

//add waypoint to the Flight Plan
void MARCS::addPoint(qreal lon, qreal lat, GeoDataCoordinates::Unit){

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
 ui->MarbleWidget_plan->repaint();
 open = false ;
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

}

//Show the page "Flight DATA"
void MARCS::openNewWindowData()
{
    ui->MarbleWidget_plan->hide();
    ui->MarbleWidget_smallView->hide();
    ui->tableWidget->show();
    ui->snapShoot_button->hide();
    ui->addMark_button->hide();
    ui->actionFlight_plan->setEnabled(true);
    ui->actionFlight_data->setEnabled(false);
    ui->actionVideo->setEnabled(true);
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
    showEditWaypoint(false);

}

//Close the window
void MARCS::close()
{
    exit(0);
}

//Load a map with the format .osm
void MARCS::openNewMap()

{
    path = QFileDialog::getOpenFileName(this, "Load a map","./FILES/map/", "OSM (*.osm)");
    QFileInfo inputFile(path);

    if ( m_map == 0  ) {
        ui->MarbleWidget_plan->model()->addGeoDataFile( inputFile.absoluteFilePath() );
        lastMap = inputFile.absoluteFilePath();
        m_map = 1 ;
   }

    else {
        ui->MarbleWidget_plan->model()->removeGeoData(lastMap);
        ui->MarbleWidget_plan->model()->addGeoDataFile( inputFile.absoluteFilePath() );
        lastMap = inputFile.absoluteFilePath();
    }
}
//Switch Mode ( Flight Plan , Video )

void MARCS::switchToMap()
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

void MARCS::drawMission(GeoPainter *painter){

    GeoDataCoordinates France( 2.2, 48.52, 0.0, GeoDataCoordinates::Degree );
        painter->setPen( QColor( 0, 0, 0 ) );
        painter->drawText( France, "France" );

        GeoDataCoordinates Canada( -77.02, 48.52, 0.0, GeoDataCoordinates::Degree );
        painter->setPen( QColor( 0, 0, 0 ) );
        painter->drawText( Canada, "Canada" );

        //A line from France to Canada without tessellation

        GeoDataLineString shapeNoTessellation( NoTessellation );
        shapeNoTessellation << France << Canada;

        painter->setPen( oxygenSkyBlue4 );
        painter->drawPolyline( shapeNoTessellation );

        //The same line, but with tessellation

        GeoDataLineString shapeTessellate( Tessellate );
        shapeTessellate << France << Canada;

        painter->setPen( oxygenBrickRed4 );
        painter->drawPolyline( shapeTessellate );

        //Now following the latitude circles

        GeoDataLineString shapeLatitudeCircle( RespectLatitudeCircle | Tessellate );
        shapeLatitudeCircle << France << Canada;

        painter->setPen( oxygenForestGreen4 );
        painter->drawPolyline( shapeLatitudeCircle );
}

void MARCS::editWaypoint(){

    ui->comboBox_ListWaypoint->show();

    ui->label_Num_Waypoint->show();
    ui->actionEdit_waypoint->setEnabled(false);
    ui->comboBox_ListWaypoint->clear();

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
}

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

void MARCS::finishEditData(){


showEditWaypoint(false);

ui->actionEdit_waypoint->setEnabled(true);
ui->actionSave_mission->setEnabled(true);

}

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

void MARCS::on_Delete_button_clicked()
{
     int index = ui->comboBox_ListWaypoint->currentIndex() ;




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
                 qDebug() << wpListSave[0]->getNum();

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
             ui->actionClear_mission->setEnabled(true);


     }

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

void MARCS::showConnectDialog(){
  //  uiConnect->show();
    widget->show();
    connect(m_pValidCom,SIGNAL(clicked()),this,SLOT(validCom()));

}

void MARCS::closeEvent(QCloseEvent *event)
{
    close();
}

void MARCS::on_start_button_clicked()
{
    if ( motorOn == false ){
        emit clickOn();
        motorOn = true ;
    }
    else {
        emit clickOff();
        motorOn = false ;
    }
}

void MARCS::validCom(){
    ui->start_button->setEnabled(true);
    widget->hide();

}

void MARCS::startMotors(){

    connect(this,SIGNAL(clickOff()),CommunicationControl::getInstance(),SIGNAL(sendMotOff()));
    if (nbClickMotors == 0){

        CommunicationControl::getInstance()->start(m_pComList->currentText());
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


}

void MARCS::stopMotors(){


    connect(this,SIGNAL(clickOn()),CommunicationControl::getInstance(),SIGNAL(sendMotOn()));
    CommunicationControl::getInstance()->stop();
    myCom->sendMotOff();
    ui->start_button->setIcon(iconOff);
    ui->start_button->setIconSize(QSize(61, 151));
    ui->excute_button->setEnabled(false);
    ui->goHome_button->setEnabled(false);
    ui->addMark_button->setEnabled(false);
    ui->snapShoot_button->setEnabled(false);
    ui->battery_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/0.png")));
    ui->label_Altitude_2->setText("0.0");


}

void MARCS::batteryLevel(double p_pValue){

    p_pValue = (int)(p_pValue * 10) / 10.;

    int dureeDeVie = (((15*60)*(((p_pValue - 9.5) / (12.5 - 9.5)) * 100))/100) ;
    int pourcentage =(((p_pValue - 9.5) / (12.5 - 9.5)) * 100);

    double latUAV= UAV::getInstance()->getCoordinates()->getLatitude();
    double lonUAV = UAV::getInstance()->getCoordinates()->getLongitude();


          if (pourcentage == 100 )
    { ui->battery_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/100.png")));
              ui->led_button->setStyleSheet("* { background-color: rgb(0,100,0) }");
              if ((dureeDeVie/60) >=  10 ) {
                  ui->Time_left_Min->setText(QString::number(dureeDeVie/60));
              }
              else {
                  ui->Time_left_Min->setText("0"+QString::number(dureeDeVie/60));
              }
              if (((dureeDeVie%60)%60)>=10) {
                  ui->Time_left_Seconde->setText((QString::number((dureeDeVie%60)%60)));
              }
              else {
                  ui->Time_left_Seconde->setText("0"+(QString::number((dureeDeVie%60)%60)));
              }
          }
          else if (pourcentage >= 90 && pourcentage < 100 )
          {   ui->battery_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/90.png")));
              ui->led_button->setStyleSheet("* { background-color: rgb(0,100,0) }");
              if ((dureeDeVie/60) >=  10 ) {
                 ui->Time_left_Min->setText(QString::number(dureeDeVie/60));
              }
              else {
                  ui->Time_left_Min->setText("0"+QString::number(dureeDeVie/60));
              }
              if (((dureeDeVie%60)%60)>=10) {
                  ui->Time_left_Seconde->setText((QString::number((dureeDeVie%60)%60)));
              }
              else {
                  ui->Time_left_Seconde->setText("0"+(QString::number((dureeDeVie%60)%60)));
              }
         }
          else if (pourcentage >= 80 && pourcentage < 90 )
          {
              ui->battery_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/80.png")));
              ui->led_button->setStyleSheet("* { background-color: rgb(0,100,0) }");
              if ((dureeDeVie/60) >=  10 ) {
                  ui->Time_left_Min->setText(QString::number(dureeDeVie/60));
              }
              else {
                  ui->Time_left_Min->setText("0"+QString::number(dureeDeVie/60));
              }
              if (((dureeDeVie%60)%60)>=10) {
                  ui->Time_left_Seconde->setText((QString::number((dureeDeVie%60)%60)));
              }
              else {
                  ui->Time_left_Seconde->setText("0"+(QString::number((dureeDeVie%60)%60)));
              }
         }
          else if (pourcentage >= 70 && pourcentage < 80 )
          {   ui->battery_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/70.png")));
              ui->led_button->setStyleSheet("* { background-color: rgb(0,100,0) }");
              if ((dureeDeVie/60) >=  10 ) {
                  ui->Time_left_Min->setText(QString::number(dureeDeVie/60));
              }
             else {
                  ui->Time_left_Min->setText("0"+QString::number(dureeDeVie/60));
              }
              if (((dureeDeVie%60)%60)>=10) {
                  ui->Time_left_Seconde->setText((QString::number((dureeDeVie%60)%60)));
             }
              else {
                  ui->Time_left_Seconde->setText("0"+(QString::number((dureeDeVie%60)%60)));
              }
         }
          else if (pourcentage >= 60 && pourcentage < 70 )
          {   ui->battery_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/60.png")));
              ui->led_button->setStyleSheet("* { background-color: rgb(0,100,0) }");
              if ((dureeDeVie/60) >=  10 ) {

                  ui->Time_left_Min->setText(QString::number(dureeDeVie/60));
              }
              else {
                  ui->Time_left_Min->setText("0"+QString::number(dureeDeVie/60));
              }
              if (((dureeDeVie%60)%60)>=10) {
                  ui->Time_left_Seconde->setText((QString::number((dureeDeVie%60)%60)));
              }
              else {
                  ui->Time_left_Seconde->setText("0"+(QString::number((dureeDeVie%60)%60)));
              }
         }
          else if (pourcentage >= 50 && pourcentage < 60 )
          { ui->battery_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/50.png")));
              ui->led_button->setStyleSheet("* { background-color: rgb(0,100,0) }");
              if ((dureeDeVie/60) >=  10 ) {
                  ui->Time_left_Min->setText(QString::number(dureeDeVie/60));
              }

             else {
                  ui->Time_left_Min->setText("0"+QString::number(dureeDeVie/60));
              }
              if (((dureeDeVie%60)%60)>=10) {
               ui->Time_left_Seconde->setText((QString::number((dureeDeVie%60)%60)));
              }
              else {
                  ui->Time_left_Seconde->setText("0"+(QString::number((dureeDeVie%60)%60)));
              }
         }
          else if (pourcentage >= 40 && pourcentage < 50 )
          {   ui->battery_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/40.png")));
              ui->led_button->setStyleSheet("* { background-color: rgb(0,100,0) }");
              if ((dureeDeVie/60) >=  10 ) {
                  ui->Time_left_Min->setText(QString::number(dureeDeVie/60));
              }
              else {
                  ui->Time_left_Min->setText("0"+QString::number(dureeDeVie/60));
              }

              if (((dureeDeVie%60)%60)>=10) {
                  ui->Time_left_Seconde->setText((QString::number((dureeDeVie%60)%60)));
              }
              else {
                  ui->Time_left_Seconde->setText("0"+(QString::number((dureeDeVie%60)%60)));
              }
         }
          else if (pourcentage >= 30 && pourcentage < 40 )
          {   ui->battery_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/30.png")));
              ui->led_button->setStyleSheet("* { background-color: rgb(255,127,36) }");
              if ((dureeDeVie/60) >=  10 ) {
                  ui->Time_left_Min->setText(QString::number(dureeDeVie/60));
              }

              else {
                  ui->Time_left_Min->setText("0"+QString::number(dureeDeVie/60));
              }

              if (((dureeDeVie%60)%60)>=10) {
                  ui->Time_left_Seconde->setText((QString::number((dureeDeVie%60)%60)));
              }
              else {
                  ui->Time_left_Seconde->setText("0"+(QString::number((dureeDeVie%60)%60)));
              }
         }
          else if (pourcentage >= 20 && pourcentage < 30 )
          {   ui->battery_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/20.png")));
              ui->led_button->setStyleSheet("* { background-color: rgb(255,127,36) }");
              ui->label_Time_Left->setText("<font color='#E27101'>Time Left : </font>");
              ui->Time_left_point->setText("<font color='#E27101'>: </font>");
              if ((dureeDeVie/60) >=  10 ) {
                  ui->Time_left_Min->setText("<font color='#E27101'></font>"+QString::number(dureeDeVie/60));
              }

              else {
                  ui->Time_left_Min->setText("<font color='#E27101'>0</font>"+QString::number(dureeDeVie/60));
              }

              if (((dureeDeVie%60)%60)>=10) {
                  ui->Time_left_Seconde->setText("<font color='#E27101'></font>"+(QString::number((dureeDeVie%60)%60)));
              }
              else {
                  ui->Time_left_Seconde->setText("<font color='#E27101'>0</font>"+(QString::number((dureeDeVie%60)%60)));
              }
         }
          else if (pourcentage >= 10 && pourcentage < 20 )
          {
              ui->battery_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/10.png")));
              ui->label_Time_Left->setText("<font color='red'>Time Left : </font>");
              ui->Time_left_point->setText("<font color='red'>: </font>");
              ui->led_button->setStyleSheet("* { background-color: rgb(255,0,0) }");
              if ((dureeDeVie/60) >=  10 ) {
                  ui->Time_left_Min->setText("<font color='red'></font>"+QString::number(dureeDeVie/60));
              }

              else {
                  ui->Time_left_Min->setText("<font color='red'>0</font>"+QString::number(dureeDeVie/60));
              }
              if (((dureeDeVie%60)%60)>=10) {
                  ui->Time_left_Seconde->setText("<font color='red'></font>"+(QString::number((dureeDeVie%60)%60)));
              }
              else {
                  ui->Time_left_Seconde->setText("<font color='red'>0</font>"+(QString::number((dureeDeVie%60)%60)));
              }
         }
          else if (pourcentage >= 0 && pourcentage < 10 )
          {
              ui->battery_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/0.png")));
              ui->label_Time_Left->setText("<font color='red'>Time Left : </font>");
              ui->Time_left_point->setText("<font color='red'>: </font>");
              ui->led_button->setStyleSheet("* { background-color: rgb(255,0,0) }");
              if ((dureeDeVie/60) >=  10 ) {
                  ui->Time_left_Min->setText("<font color='red'></font>"+QString::number(dureeDeVie/60));
              }

              else {
                  ui->Time_left_Min->setText("<font color='red'>0</font>"+QString::number(dureeDeVie/60));
              }

              if (((dureeDeVie%60)%60)>=10) {
                  ui->Time_left_Seconde->setText("<font color='red'></font>"+(QString::number((dureeDeVie%60)%60)));
              }
              else {
                  ui->Time_left_Seconde->setText("<font color='red'>0</font>"+(QString::number((dureeDeVie%60)%60)));
              }
         }

          if(lonUAV < 200 && latUAV < 200){

              createRpaMark(UAV::getInstance()->getHeading(),lonUAV,latUAV,GeoDataCoordinates::Degree);
          }
          else {
              //rien

          }
}
void MARCS::setHeight(double p_dHeight){
    ui->label_Altitude_2->setText(QString::number(p_dHeight));
}

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


void MARCS::createRpaMark(double hdg ,double lon, double lat, GeoDataCoordinates::Unit){

    //Create the placemark representing the Arch of Triumph
     GeoDataPlacemark* placemarkArch = new GeoDataPlacemark( "" );
     placemarkArch->setCoordinate( lon, lat, 0, GeoDataCoordinates::Degree );

     GeoDataStyle* styleArch = new GeoDataStyle();
     createStyleRPA (  styleArch, hdg );
     placemarkArch->setStyle( styleArch ) ;

     //Create the document and add the two placemarks (the point representing the Arch of Triumph and the polygon with Bucharest's boundaries)
     if(number==0){
         documentRPA->append( placemarkArch );

         ui->MarbleWidget_plan->model()->treeModel()->addDocument(documentRPA);
              }
     else {
         documentRPA->remove(0);
         documentRPA->append( placemarkArch );
         ui->MarbleWidget_plan->model()->treeModel()->update();
     }
   number ++ ;
}

