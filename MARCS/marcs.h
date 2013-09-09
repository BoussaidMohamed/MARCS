#ifndef MARCS_H
#define MARCS_H

#include <QString>
#include <MarbleWidget.h>
#include "GeoDataCoordinates.h"
#include <QLabel>
#include "mission.h"
#include "waypoint.h"
#include "MissionControl.h"
#include <QMainWindow>
#include <QtCore/QFileInfo>
#include <QtCore/QDataStream>
#include <QtCore/QFile>
#include <QtCore/QIODevice>
#include <QtGui/QTreeView>
#include <QtGui/QTreeView>
#include <QtGui/QApplication>
#include <QListWidget>
#include <QTableWidgetItem>
#include <QListWidgetItem>
#include <QPaintDevice>
#include <QString>
#include <QGridLayout>
#include <QtGlobal>
#include <QFileDialog>
#include <GeoDataIconStyle.h>
#include <GeoDataStyle.h>
#include <QListView>
#include <ctime>
#include <QComboBox>
#include <QDebug>
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
#include <AbstractFloatItem.h>
#include <global.h>
#include <string>
#include <iostream>
#include <fstream>
#include "QGridLayout"
#include "qextserialenumerator.h"
#include <QMessageBox>
using namespace Marble;
using namespace std ;

namespace Ui {
class MARCS;
}

class MARCS : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MARCS(QWidget *parent = 0);
    ~MARCS();

signals :
  void clickOn() ;
  void clickOff();
  void takeOff();
  void landRPA();
  void next(double lon , double lat , double alt , double num );

public slots:
  /**
  * @brief Show the main window Map
  * @param none
  * @exception none
  * @return none
  */
    void openNewWindowMain();
    /**
    * @brief Show the Data window
    * @param none
    * @exception none
    * @return none
    */
    void openNewWindowData();
    /**
    * @brief Show the video window
    * @param none
    * @exception none
    * @return none
    */
    void openNewWindowVideo();
    /**
    * @brief Load map
    * @param none
    * @exception none
    * @return none
    */
    void openNewMap();
    /**
    * @brief switch view between the map and the video by clicking on map
    * @param none
    * @exception none
    * @return none
    */
    void switchToMap();
    /**
    * @brief show log list
    * @param none
    * @exception none
    * @return none
    */
    void showList();
    /**
    * @brief Open new mission from Kml File
    * @param none
    * @exception none
    * @return none
    */
    void openMission();
    /**
    * @brief Save mission to Kml File
    * @param none
    * @exception none
    * @return none
    */
    void saveMission();
    /**
    * @brief add point to map
    * @param lon qreal , lat qreal, GeoDataCoordinates::Unit
    * @exception none
    * @return none
    */
    void addPoint( qreal lon, qreal lat, GeoDataCoordinates::Unit );
    /**
    * @brief clear mission from the map view
    * @param none
    * @exception none
    * @return none
    */
    void clearMission();
    /**
    * @brief open the list of the waypoints
    * @param none
    * @exception none
    * @return none
    */
    void editWaypoint();
    /**
    * @brief load waypoint data from the index
    * @param none
    * @exception none
    * @return none
    */
    void loadData();
    /**
    * @brief save edition to the XML file source of the mission
    * @param none
    * @exception none
    * @return none
    */
    void saveEditData();
    /**
    * @brief close the edit waypoints view
    * @param none
    * @exception none
    * @return none
    */
    void finishEditData();
    /**
    * @brief show the waypoint edition area
    * @param show bool
    * @exception none
    * @return none
    */
    void showEditWaypoint(bool show);
    /**
    * @brief show the COM connect dialog
    * @param none
    * @exception none
    * @return none
    */
    void showConnectDialog();
    /**
    * @brief send the Serial COM
    * @param none
    * @exception none
    * @return none
    */
    void validCom();
    /**
    * @brief Close the window
    * @param event QCloseEvent
    * @exception none
    * @return none
    */
    void closeEvent(QCloseEvent *event);
    /**
    * @brief start the RPA engine
    * @param none
    * @exception none
    * @return none
    */
    void startMotors();
    /**
    * @brief get the battery Level;
    * @param p_pValue double
    * @exception none
    * @return none
    */
    void batteryLevel(double p_pValue);
    /**
    * @brief stop the RPA engine
    * @param none
    * @exception none
    * @return none
    */
    void stopMotors();
    /**
    * @brief Create the Style of the RPA presentation on the map
    * @param style GeoDataStyle, hdg double
    * @exception none
    * @return none
    */
    void createStyleRPA( GeoDataStyle *style, double hdg ) ;
    /**
    * @brief Add the RPA presentation on the map with heading and position
    * @param hdg double , lon double , lat double , GeoDataCoordinates::Unit
    * @exception none
    * @return none
    */
    void createRpaMark(double hdg,double lon, double lat, GeoDataCoordinates::Unit );
    /**
    * @brief Create the Style of the HOME presentation on the map
    * @param style GeoDataStyle
    * @exception none
    * @return none
    */
    void createStyleHome( GeoDataStyle *style ) ;
    /**
    * @brief Add the HOME presentation on the map with position
    * @param lon double , lat double , GeoDataCoordinates::Unit
    * @exception none
    * @return none
    */
    void createHomeMark(double lon, double lat, GeoDataCoordinates::Unit );
    /**
    * @brief Create the Style of the Add Mark presentation on the map
    * @param style GeoDataStyle
    * @exception none
    * @return none
    */
    void createStyleAddMark( GeoDataStyle *style ) ;
    /**
    * @brief Add the Add Mark presentation on the map with position
    * @param lon double , lat double , GeoDataCoordinates::Unit
    * @exception none
    * @return none
    */
    void createAddMark(double lon, double lat, GeoDataCoordinates::Unit );
    /**
    * @brief set RPA height field
    * @param p_dHeight double
    * @exception none
    * @return none
    */
    void setHeight(double p_dHeight);
    /**
    * @brief take off the RPA
    * @param none
    * @exception none
    * @return none
    */
    void fly();
    /**
    * @brief Xbee disconnected
    * @param none
    * @exception none
    * @return none
    */
    void XbeeDisconnect();
    /**
    * @brief Xbee reconnected
    * @param none
    * @exception none
    * @return none
    */
    void XbeeConnect();
    /**
    * @brief land the RPA
    * @param none
    * @exception none
    * @return none
    */
    void stopFly();
    /**
    * @brief get The GPS Level
    * @param p_value int
    * @exception none
    * @return none
    */
    void GPSLevel(int p_value);
    void updateMotors(char p_cValue);
    void goTo(double lon,double lat,double alt,double n);
    /**
    * @brief add information to RPA table
    * @param none
    * @exception none
    * @return none
    */
    void setTableRPA();
    /**
    * @brief show Log page
    * @param none
    * @exception none
    * @return none
    */
    void showLog();
    /**
    * @brief close the application
    * @param none
    * @exception none
    * @return none
    */
    void close();


private:
    Ui::MARCS *ui;
    QString path ;
    mission myMission ;
    QListView *m_listView;
    QList <waypoint* > wpListSave ;
    QList <waypoint* > wpListOpen ;
    QList <waypoint* > wpListAdd ;
    QList <waypoint* > m_mission ;
    QList <GeoDataPlacemark*> listPlaceMark;
    QString lastMission;
    QString lastMap;
    QString fileOpened ;
    QString qstr ;
    int num_waypoint;
    int number ;
    int m_map  ;
    int nbClickMotors;
    int num_add_waypoint;
    int rowAdd;
    int n;
    int m_cMotorValue;
    waypoint* home;
    bool clear_mission;
    bool logShow40;
    bool logShow30;
    bool logShow20;
    bool logShow10;
    bool homeShow;
    bool affichageList;
    bool open  ;
    bool motorOn;
    bool motorTurn;
    bool land ;
    bool nextIsShowing;
    bool takeOffClicked;
    bool gps0;
    bool gps1;
    bool gps2;
    bool gps3;
    bool gps4;
    bool gps5;
    bool missionOpned;
    char* numWpText;
    QTableWidgetItem *ItemLon ;
    QTableWidgetItem *ItemLat ;
    QTableWidgetItem *ItemAlt;
    QTableWidgetItem *ItemHdg ;
    QTableWidgetItem *ItemName ;
    QTableWidgetItem *ItemMarkLon ;
    QTableWidgetItem *ItemMarkLat ;
    QTableWidgetItem *ItemMarkAlt;
    QTableWidgetItem *ItemMarkHdg ;
    QTableWidgetItem *ItemMarkNum ;
    string textNumWaypoint ;
    string temp;
    GeoDataPlacemark *place ;
    GeoDataPlacemark* placemarkRPA ;
    GeoDataPlacemark* placemarkHome;
    GeoDataPlacemark* placemarkMark ;
    GeoDataStyle* styleArchRPA;
    GeoDataStyle* styleArchHome ;
    GeoDataStyle* styleArchMark;
    GeoDataDocument *document ;
    GeoDataDocument *documentRPA ;
    GeoDataDocument *documentHome ;
    GeoDataDocument *documentMark ;
    GeoDataCoordinates *tempo;
    RoutingManager* manager ;
    RouteRequest* request;
    RoutingManager* manager_smallMap ;
    RouteRequest* request_smallMap;
    QComboBox* m_pComList;		    //Available COM port list
    QMainWindow* m_pComWindow;		//COM port selection window
    QPushButton* m_pValidCom;		//COM port validation button
    QGridLayout* layout ;
    QWidget* widget;
    QLabel* m_pLabel;
    ComThread* myCom;
    QIcon iconOff;
    QIcon iconOn;
    QIcon iconTakeOff;
    QIcon iconLand;
    QTableWidgetItem* item;

private slots:
    void on_start_button_clicked();
    void on_lineEdit_HDG_textEdited(QString );
    void on_lineEdit_Alt_textChanged(QString );
    void on_comboBox_ListWaypoint_currentIndexChanged(int index);
    void on_Delete_button_clicked();
    void on_timeEdit_Mission_timeChanged(const QTime &date);
    void on_excute_button_clicked();
    void on_addMark_button_clicked();
    void on_AddToMission_button_clicked();
    void on_NextWaypoint_button_clicked();
};

#endif // MARCS_H
