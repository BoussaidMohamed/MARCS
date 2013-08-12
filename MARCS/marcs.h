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
#include <QListWidgetItem>
#include <QPaintDevice>
#include <QString>
#include <QGridLayout>
#include <QtGlobal>
#include <QFileDialog>
#include <GeoDataIconStyle.h>
#include <GeoDataStyle.h>
#include <QListView>
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

public slots:
    void openNewWindowMain();
    void openNewWindowData();
    void openNewWindowVideo();
    void openNewMap();
    void switchToMap();
    void afficheList();
    void openMission();
    void saveMission();
    void addPoint( qreal lon, qreal lat, GeoDataCoordinates::Unit );
    void clearMission();
    void editWaypoint();
    void loadData();
    void saveEditData();
    void finishEditData();
    void drawMission(GeoPainter* painter);
    void showEditWaypoint(bool show);
    void showConnectDialog();
    void validCom();
    void closeEvent(QCloseEvent *event);
    void startMotors();
    void batteryLevel(double p_pValue);
    void stopMotors();
    void createStyleRPA( GeoDataStyle *style, double hdg ) ;
    void createRpaMark(double hdg,double lon, double lat, GeoDataCoordinates::Unit );
    /**
    * @brief set RPA height field
    * @param p_dSpeed double
    * @exception none
    * @return none
    */
    void setHeight(double p_dHeight);
    void close();


private:
    Ui::MARCS *ui;
    QString path ;
    mission myMission ;
    QListView *m_listView;
    QList <waypoint* > wpListSave ;
    QList <waypoint* > wpListOpen ;
    QString lastMission;
    QString lastMap;
    QString fileOpened ;
    QString qstr ;
    int num_waypoint;
    int number ;

    bool affichageList;
    bool open  ;
    bool motorOn;
    int m_map  ;
    int nbClickMotors;
    char* numWpText;
    string textNumWaypoint ;
    string temp;
    GeoDataPlacemark *place ;
    GeoDataDocument *document ;
    GeoDataDocument *documentRPA ;
    GeoDataCoordinates *tempo;
    RoutingManager* manager ;
    RouteRequest* request;
    RoutingManager* manager_smallMap ;
    RouteRequest* request_smallMap;
    GeoPainter* gp ;
    QPaintDevice* paintDevice ;
    QImage image;
    QComboBox* m_pComList;		//Available COM port list
    QMainWindow* m_pComWindow;		//COM port selection window
    QPushButton* m_pValidCom;		//COM port validation button
    QGridLayout* layout ;
    QWidget* widget;
    QLabel* m_pLabel;
    CommunicationControl* myComControl ;
    ComThread* myCom;
    QIcon iconOff;
    QIcon iconOn;
    MissionControl* myMissionControl;

private slots:
    void on_start_button_clicked();
    void on_lineEdit_HDG_textEdited(QString );
    void on_lineEdit_Alt_textChanged(QString );
    void on_comboBox_ListWaypoint_currentIndexChanged(int index);
    void on_Delete_button_clicked();
    void on_timeEdit_Mission_timeChanged(const QTime &date);

};

#endif // MARCS_H
