/********************************************************************************
** Form generated from reading UI file 'marcs.ui'
**
** Created: Fri 6. Sep 15:53:46 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MARCS_H
#define UI_MARCS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QTimeEdit>
#include <QtGui/QWidget>
#include "MarbleWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MARCS
{
public:
    QAction *actionLoad_map;
    QAction *actionLoad_mission;
    QAction *actionSave_mission;
    QAction *actionClear_mission;
    QAction *actionEdit_waypoint;
    QAction *actionClose;
    QAction *actionConnect_RPA;
    QAction *actionController;
    QAction *actionFlight_plan;
    QAction *actionVideo;
    QAction *actionFlight_data;
    QAction *actionLog;
    QAction *actionRaplay_Mission;
    QAction *actionFollow_RAP;
    QWidget *centralwidget;
    QListWidget *ListLogFinal;
    QFrame *line_5;
    QComboBox *comboBox_ListWaypoint;
    QLabel *label_HDG;
    QLabel *label_Alt;
    QPushButton *Delete_button;
    QPushButton *status_button;
    QLabel *labelRPA;
    QLabel *Time_left_Min;
    QPushButton *snapShoot_button;
    QLabel *label_Time;
    QPushButton *led_button;
    QLabel *Time_left_point;
    QPushButton *FinishEdit_button_2;
    QFrame *line_3;
    Marble::MarbleWidget *MarbleWidget_plan;
    QFrame *line_6;
    QLabel *battery_label;
    QFrame *line;
    QPushButton *start_button;
    QLabel *label_Altitude_2;
    QLabel *labelMission;
    QPushButton *excute_button;
    QFrame *line_4;
    QPushButton *SaveEdit_button;
    QTableWidget *tableWidget;
    QPushButton *NextWaypoint_button;
    QLineEdit *lineEdit_Alt;
    QPushButton *goHome_button;
    QTableWidget *tableMarkPoint;
    QLabel *label_Num_Waypoint;
    QLabel *label_Altitude;
    QLabel *Time_left_Seconde;
    QLabel *labelMark;
    QTableWidget *tableRPA;
    QLineEdit *lineEdit_HDG;
    QPushButton *addMark_button;
    QLabel *label_Time_Left;
    QTimeEdit *timeEdit_Mission;
    QPushButton *AddToMission_button;
    Marble::MarbleWidget *MarbleWidget_smallView;
    QFrame *line_2;
    QLabel *label;
    QListWidget *listLog;
    QLabel *labelNow;
    QLabel *labelNext;
    QMenuBar *menubar;
    QMenu *menuPlanning;
    QMenu *menuSettings;
    QMenu *menuDisplay;
    QMenu *menuPost_Flight;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MARCS)
    {
        if (MARCS->objectName().isEmpty())
            MARCS->setObjectName(QString::fromUtf8("MARCS"));
        MARCS->resize(800, 645);
        MARCS->setMinimumSize(QSize(800, 645));
        MARCS->setMaximumSize(QSize(800, 645));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/icon/drone.png"), QSize(), QIcon::Normal, QIcon::Off);
        MARCS->setWindowIcon(icon);
        MARCS->setWindowOpacity(1);
        MARCS->setIconSize(QSize(40, 40));
        actionLoad_map = new QAction(MARCS);
        actionLoad_map->setObjectName(QString::fromUtf8("actionLoad_map"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icon/Open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad_map->setIcon(icon1);
        actionLoad_mission = new QAction(MARCS);
        actionLoad_mission->setObjectName(QString::fromUtf8("actionLoad_mission"));
        actionLoad_mission->setIcon(icon1);
        actionSave_mission = new QAction(MARCS);
        actionSave_mission->setObjectName(QString::fromUtf8("actionSave_mission"));
        actionSave_mission->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/icon/Save-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_mission->setIcon(icon2);
        actionClear_mission = new QAction(MARCS);
        actionClear_mission->setObjectName(QString::fromUtf8("actionClear_mission"));
        actionClear_mission->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/icon/Gnome-edit-clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear_mission->setIcon(icon3);
        actionEdit_waypoint = new QAction(MARCS);
        actionEdit_waypoint->setObjectName(QString::fromUtf8("actionEdit_waypoint"));
        actionEdit_waypoint->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/icon/Edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEdit_waypoint->setIcon(icon4);
        actionClose = new QAction(MARCS);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/icon/cute_ball_stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon5);
        actionConnect_RPA = new QAction(MARCS);
        actionConnect_RPA->setObjectName(QString::fromUtf8("actionConnect_RPA"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/icon/Actions network connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect_RPA->setIcon(icon6);
        actionController = new QAction(MARCS);
        actionController->setObjectName(QString::fromUtf8("actionController"));
        actionController->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/icon/joystick_256.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionController->setIcon(icon7);
        actionFlight_plan = new QAction(MARCS);
        actionFlight_plan->setObjectName(QString::fromUtf8("actionFlight_plan"));
        actionFlight_plan->setEnabled(false);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/prefix1/icon/psd-world-map-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFlight_plan->setIcon(icon8);
        actionVideo = new QAction(MARCS);
        actionVideo->setObjectName(QString::fromUtf8("actionVideo"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/prefix1/icon/camera.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionVideo->setIcon(icon9);
        actionFlight_data = new QAction(MARCS);
        actionFlight_data->setObjectName(QString::fromUtf8("actionFlight_data"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/new/prefix1/icon/url1.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFlight_data->setIcon(icon10);
        actionLog = new QAction(MARCS);
        actionLog->setObjectName(QString::fromUtf8("actionLog"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/new/prefix1/icon/crystal-log.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLog->setIcon(icon11);
        actionRaplay_Mission = new QAction(MARCS);
        actionRaplay_Mission->setObjectName(QString::fromUtf8("actionRaplay_Mission"));
        actionRaplay_Mission->setEnabled(false);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/new/prefix1/icon/replay_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRaplay_Mission->setIcon(icon12);
        actionFollow_RAP = new QAction(MARCS);
        actionFollow_RAP->setObjectName(QString::fromUtf8("actionFollow_RAP"));
        centralwidget = new QWidget(MARCS);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ListLogFinal = new QListWidget(centralwidget);
        ListLogFinal->setObjectName(QString::fromUtf8("ListLogFinal"));
        ListLogFinal->setGeometry(QRect(0, 0, 638, 591));
        ListLogFinal->setAutoFillBackground(false);
        line_5 = new QFrame(centralwidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(650, 20, 20, 41));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);
        comboBox_ListWaypoint = new QComboBox(centralwidget);
        comboBox_ListWaypoint->setObjectName(QString::fromUtf8("comboBox_ListWaypoint"));
        comboBox_ListWaypoint->setGeometry(QRect(240, 530, 41, 22));
        label_HDG = new QLabel(centralwidget);
        label_HDG->setObjectName(QString::fromUtf8("label_HDG"));
        label_HDG->setGeometry(QRect(520, 530, 46, 13));
        label_Alt = new QLabel(centralwidget);
        label_Alt->setObjectName(QString::fromUtf8("label_Alt"));
        label_Alt->setGeometry(QRect(295, 530, 46, 13));
        Delete_button = new QPushButton(centralwidget);
        Delete_button->setObjectName(QString::fromUtf8("Delete_button"));
        Delete_button->setGeometry(QRect(430, 568, 75, 23));
        status_button = new QPushButton(centralwidget);
        status_button->setObjectName(QString::fromUtf8("status_button"));
        status_button->setGeometry(QRect(640, 170, 151, 61));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        status_button->setFont(font);
        status_button->setIconSize(QSize(60, 60));
        status_button->setAutoDefault(false);
        status_button->setDefault(false);
        status_button->setFlat(false);
        labelRPA = new QLabel(centralwidget);
        labelRPA->setObjectName(QString::fromUtf8("labelRPA"));
        labelRPA->setGeometry(QRect(290, 10, 46, 20));
        labelRPA->setFont(font);
        Time_left_Min = new QLabel(centralwidget);
        Time_left_Min->setObjectName(QString::fromUtf8("Time_left_Min"));
        Time_left_Min->setGeometry(QRect(728, 140, 21, 21));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        Time_left_Min->setFont(font1);
        snapShoot_button = new QPushButton(centralwidget);
        snapShoot_button->setObjectName(QString::fromUtf8("snapShoot_button"));
        snapShoot_button->setEnabled(false);
        snapShoot_button->setGeometry(QRect(160, 530, 151, 61));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/new/prefix1/icon/11954231621344997843camera_pictogram_r5d_01.svg.hi.png"), QSize(), QIcon::Normal, QIcon::Off);
        snapShoot_button->setIcon(icon13);
        snapShoot_button->setIconSize(QSize(61, 50));
        snapShoot_button->setAutoDefault(false);
        snapShoot_button->setDefault(false);
        label_Time = new QLabel(centralwidget);
        label_Time->setObjectName(QString::fromUtf8("label_Time"));
        label_Time->setGeometry(QRect(408, 530, 46, 13));
        led_button = new QPushButton(centralwidget);
        led_button->setObjectName(QString::fromUtf8("led_button"));
        led_button->setGeometry(QRect(750, 190, 21, 21));
        led_button->setMinimumSize(QSize(21, 21));
        led_button->setMaximumSize(QSize(21, 21));
        led_button->setAutoDefault(false);
        led_button->setDefault(false);
        Time_left_point = new QLabel(centralwidget);
        Time_left_point->setObjectName(QString::fromUtf8("Time_left_point"));
        Time_left_point->setGeometry(QRect(745, 140, 21, 21));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        Time_left_point->setFont(font2);
        FinishEdit_button_2 = new QPushButton(centralwidget);
        FinishEdit_button_2->setObjectName(QString::fromUtf8("FinishEdit_button_2"));
        FinishEdit_button_2->setGeometry(QRect(530, 568, 75, 23));
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(660, 60, 118, 3));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        MarbleWidget_plan = new Marble::MarbleWidget(centralwidget);
        MarbleWidget_plan->setObjectName(QString::fromUtf8("MarbleWidget_plan"));
        MarbleWidget_plan->setGeometry(QRect(0, 0, 631, 521));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MarbleWidget_plan->sizePolicy().hasHeightForWidth());
        MarbleWidget_plan->setSizePolicy(sizePolicy);
        MarbleWidget_plan->setCursor(QCursor(Qt::CrossCursor));
        MarbleWidget_plan->setMouseTracking(false);
        MarbleWidget_plan->setProperty("zoom", QVariant(2100));
        MarbleWidget_plan->setProperty("projection", QVariant(0));
        MarbleWidget_plan->setProperty("longitude", QVariant(1.4));
        MarbleWidget_plan->setProperty("latitude", QVariant(43.6));
        MarbleWidget_plan->setProperty("showOverviewMap", QVariant(false));
        MarbleWidget_plan->setProperty("showScaleBar", QVariant(false));
        MarbleWidget_plan->setProperty("showCompass", QVariant(false));
        MarbleWidget_plan->setProperty("showGrid", QVariant(false));
        MarbleWidget_plan->setProperty("showClouds", QVariant(false));
        MarbleWidget_plan->setProperty("showAtmosphere", QVariant(false));
        MarbleWidget_plan->setProperty("showPlaces", QVariant(false));
        MarbleWidget_plan->setProperty("showCities", QVariant(false));
        MarbleWidget_plan->setProperty("showTerrain", QVariant(false));
        MarbleWidget_plan->setProperty("showOtherPlaces", QVariant(false));
        MarbleWidget_plan->setProperty("showRelief", QVariant(false));
        MarbleWidget_plan->setProperty("showBorders", QVariant(false));
        MarbleWidget_plan->setProperty("showRivers", QVariant(false));
        MarbleWidget_plan->setProperty("showLakes", QVariant(false));
        MarbleWidget_plan->setProperty("volatileTileCacheLimit", QVariant(Q_UINT64_C(200000)));
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(770, 20, 20, 41));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);
        battery_label = new QLabel(centralwidget);
        battery_label->setObjectName(QString::fromUtf8("battery_label"));
        battery_label->setGeometry(QRect(640, 70, 161, 71));
        battery_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/0.png")));
        battery_label->setScaledContents(true);
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(620, 0, 31, 591));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        start_button = new QPushButton(centralwidget);
        start_button->setObjectName(QString::fromUtf8("start_button"));
        start_button->setEnabled(false);
        start_button->setGeometry(QRect(640, 370, 151, 61));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/new/prefix1/icon/engineOff.png"), QSize(), QIcon::Normal, QIcon::Off);
        start_button->setIcon(icon14);
        start_button->setIconSize(QSize(61, 151));
        start_button->setCheckable(false);
        start_button->setAutoDefault(false);
        start_button->setDefault(false);
        label_Altitude_2 = new QLabel(centralwidget);
        label_Altitude_2->setObjectName(QString::fromUtf8("label_Altitude_2"));
        label_Altitude_2->setGeometry(QRect(690, 20, 71, 41));
        QFont font3;
        font3.setPointSize(17);
        label_Altitude_2->setFont(font3);
        labelMission = new QLabel(centralwidget);
        labelMission->setObjectName(QString::fromUtf8("labelMission"));
        labelMission->setGeometry(QRect(280, 140, 61, 20));
        labelMission->setFont(font);
        excute_button = new QPushButton(centralwidget);
        excute_button->setObjectName(QString::fromUtf8("excute_button"));
        excute_button->setEnabled(false);
        excute_button->setGeometry(QRect(640, 450, 151, 61));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/new/prefix1/icon/takeoff.png"), QSize(), QIcon::Normal, QIcon::Off);
        excute_button->setIcon(icon15);
        excute_button->setIconSize(QSize(61, 151));
        excute_button->setAutoDefault(false);
        excute_button->setDefault(false);
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(660, 20, 118, 3));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        SaveEdit_button = new QPushButton(centralwidget);
        SaveEdit_button->setObjectName(QString::fromUtf8("SaveEdit_button"));
        SaveEdit_button->setGeometry(QRect(330, 568, 75, 23));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignLeft|Qt::AlignTop);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignLeft|Qt::AlignTop);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignLeft|Qt::AlignTop);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignLeft|Qt::AlignTop);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignLeft|Qt::AlignTop);
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignLeft|Qt::AlignTop);
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignLeft|Qt::AlignTop);
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (tableWidget->rowCount() < 50)
            tableWidget->setRowCount(50);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 170, 631, 191));
        QFont font4;
        font4.setPointSize(8);
        font4.setBold(true);
        font4.setWeight(75);
        tableWidget->setFont(font4);
        tableWidget->setRowCount(50);
        tableWidget->horizontalHeader()->setDefaultSectionSize(90);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(90);
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setMinimumSectionSize(30);
        NextWaypoint_button = new QPushButton(centralwidget);
        NextWaypoint_button->setObjectName(QString::fromUtf8("NextWaypoint_button"));
        NextWaypoint_button->setEnabled(true);
        NextWaypoint_button->setGeometry(QRect(483, 530, 151, 61));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/new/prefix1/icon/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        NextWaypoint_button->setIcon(icon16);
        NextWaypoint_button->setIconSize(QSize(61, 50));
        NextWaypoint_button->setAutoDefault(false);
        NextWaypoint_button->setDefault(false);
        lineEdit_Alt = new QLineEdit(centralwidget);
        lineEdit_Alt->setObjectName(QString::fromUtf8("lineEdit_Alt"));
        lineEdit_Alt->setGeometry(QRect(340, 528, 61, 21));
        goHome_button = new QPushButton(centralwidget);
        goHome_button->setObjectName(QString::fromUtf8("goHome_button"));
        goHome_button->setEnabled(false);
        goHome_button->setGeometry(QRect(640, 530, 151, 61));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/new/prefix1/icon/HouseBlack.png"), QSize(), QIcon::Normal, QIcon::Off);
        goHome_button->setIcon(icon17);
        goHome_button->setIconSize(QSize(61, 151));
        goHome_button->setAutoDefault(false);
        goHome_button->setDefault(false);
        tableMarkPoint = new QTableWidget(centralwidget);
        if (tableMarkPoint->columnCount() < 7)
            tableMarkPoint->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignLeft|Qt::AlignTop);
        tableMarkPoint->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignLeft|Qt::AlignTop);
        tableMarkPoint->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignLeft|Qt::AlignTop);
        tableMarkPoint->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignLeft|Qt::AlignTop);
        tableMarkPoint->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignLeft|Qt::AlignTop);
        tableMarkPoint->setHorizontalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignLeft|Qt::AlignTop);
        tableMarkPoint->setHorizontalHeaderItem(5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignLeft|Qt::AlignTop);
        tableMarkPoint->setHorizontalHeaderItem(6, __qtablewidgetitem13);
        if (tableMarkPoint->rowCount() < 50)
            tableMarkPoint->setRowCount(50);
        tableMarkPoint->setObjectName(QString::fromUtf8("tableMarkPoint"));
        tableMarkPoint->setGeometry(QRect(0, 390, 631, 131));
        tableMarkPoint->setFont(font4);
        tableMarkPoint->setRowCount(50);
        tableMarkPoint->horizontalHeader()->setDefaultSectionSize(90);
        tableMarkPoint->horizontalHeader()->setHighlightSections(false);
        tableMarkPoint->horizontalHeader()->setMinimumSectionSize(90);
        tableMarkPoint->horizontalHeader()->setStretchLastSection(false);
        tableMarkPoint->verticalHeader()->setMinimumSectionSize(30);
        label_Num_Waypoint = new QLabel(centralwidget);
        label_Num_Waypoint->setObjectName(QString::fromUtf8("label_Num_Waypoint"));
        label_Num_Waypoint->setEnabled(true);
        label_Num_Waypoint->setGeometry(QRect(160, 530, 81, 21));
        label_Altitude = new QLabel(centralwidget);
        label_Altitude->setObjectName(QString::fromUtf8("label_Altitude"));
        label_Altitude->setGeometry(QRect(640, -20, 141, 61));
        label_Altitude->setFont(font);
        label_Altitude->setText(QString::fromUtf8("ALTITUDE:"));
        label_Altitude->setTextFormat(Qt::LogText);
        label_Altitude->setAlignment(Qt::AlignCenter);
        Time_left_Seconde = new QLabel(centralwidget);
        Time_left_Seconde->setObjectName(QString::fromUtf8("Time_left_Seconde"));
        Time_left_Seconde->setGeometry(QRect(750, 140, 20, 21));
        Time_left_Seconde->setFont(font1);
        labelMark = new QLabel(centralwidget);
        labelMark->setObjectName(QString::fromUtf8("labelMark"));
        labelMark->setGeometry(QRect(265, 360, 91, 20));
        labelMark->setFont(font);
        tableRPA = new QTableWidget(centralwidget);
        if (tableRPA->columnCount() < 7)
            tableRPA->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setTextAlignment(Qt::AlignLeft|Qt::AlignTop);
        tableRPA->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setTextAlignment(Qt::AlignLeft|Qt::AlignTop);
        tableRPA->setHorizontalHeaderItem(1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setTextAlignment(Qt::AlignLeft|Qt::AlignTop);
        tableRPA->setHorizontalHeaderItem(2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setTextAlignment(Qt::AlignLeft|Qt::AlignTop);
        tableRPA->setHorizontalHeaderItem(3, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setTextAlignment(Qt::AlignLeft|Qt::AlignTop);
        tableRPA->setHorizontalHeaderItem(4, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setTextAlignment(Qt::AlignLeft|Qt::AlignTop);
        tableRPA->setHorizontalHeaderItem(5, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setTextAlignment(Qt::AlignLeft|Qt::AlignTop);
        tableRPA->setHorizontalHeaderItem(6, __qtablewidgetitem20);
        if (tableRPA->rowCount() < 1)
            tableRPA->setRowCount(1);
        tableRPA->setObjectName(QString::fromUtf8("tableRPA"));
        tableRPA->setGeometry(QRect(0, 30, 631, 101));
        tableRPA->setFont(font4);
        tableRPA->setRowCount(1);
        tableRPA->horizontalHeader()->setDefaultSectionSize(90);
        tableRPA->horizontalHeader()->setHighlightSections(false);
        tableRPA->horizontalHeader()->setMinimumSectionSize(90);
        tableRPA->horizontalHeader()->setStretchLastSection(false);
        tableRPA->verticalHeader()->setMinimumSectionSize(30);
        lineEdit_HDG = new QLineEdit(centralwidget);
        lineEdit_HDG->setObjectName(QString::fromUtf8("lineEdit_HDG"));
        lineEdit_HDG->setGeometry(QRect(570, 528, 61, 21));
        addMark_button = new QPushButton(centralwidget);
        addMark_button->setObjectName(QString::fromUtf8("addMark_button"));
        addMark_button->setEnabled(false);
        addMark_button->setGeometry(QRect(0, 530, 151, 61));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/new/prefix1/icon/add_mark.png"), QSize(), QIcon::Normal, QIcon::Off);
        addMark_button->setIcon(icon18);
        addMark_button->setIconSize(QSize(61, 50));
        addMark_button->setAutoDefault(true);
        addMark_button->setDefault(true);
        label_Time_Left = new QLabel(centralwidget);
        label_Time_Left->setObjectName(QString::fromUtf8("label_Time_Left"));
        label_Time_Left->setGeometry(QRect(660, 140, 61, 21));
        QFont font5;
        font5.setBold(true);
        font5.setWeight(75);
        label_Time_Left->setFont(font5);
        timeEdit_Mission = new QTimeEdit(centralwidget);
        timeEdit_Mission->setObjectName(QString::fromUtf8("timeEdit_Mission"));
        timeEdit_Mission->setGeometry(QRect(440, 528, 71, 21));
        AddToMission_button = new QPushButton(centralwidget);
        AddToMission_button->setObjectName(QString::fromUtf8("AddToMission_button"));
        AddToMission_button->setEnabled(false);
        AddToMission_button->setGeometry(QRect(0, 530, 151, 61));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/new/prefix1/icon/edit_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddToMission_button->setIcon(icon19);
        AddToMission_button->setIconSize(QSize(61, 50));
        AddToMission_button->setAutoDefault(false);
        AddToMission_button->setDefault(false);
        MarbleWidget_smallView = new Marble::MarbleWidget(centralwidget);
        MarbleWidget_smallView->setObjectName(QString::fromUtf8("MarbleWidget_smallView"));
        MarbleWidget_smallView->setGeometry(QRect(640, 230, 155, 125));
        MarbleWidget_smallView->setMinimumSize(QSize(25, 25));
        MarbleWidget_smallView->setMaximumSize(QSize(155, 125));
        MarbleWidget_smallView->setProperty("zoom", QVariant(2100));
        MarbleWidget_smallView->setProperty("longitude", QVariant(1.4));
        MarbleWidget_smallView->setProperty("latitude", QVariant(43.6));
        MarbleWidget_smallView->setProperty("showOverviewMap", QVariant(false));
        MarbleWidget_smallView->setProperty("showScaleBar", QVariant(false));
        MarbleWidget_smallView->setProperty("showCompass", QVariant(false));
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(280, 520, 20, 71));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(540, 590, 311, 16));
        QFont font6;
        font6.setPointSize(7);
        font6.setBold(false);
        font6.setItalic(false);
        font6.setWeight(50);
        label->setFont(font6);
        listLog = new QListWidget(centralwidget);
        listLog->setObjectName(QString::fromUtf8("listLog"));
        listLog->setGeometry(QRect(640, 230, 151, 201));
        labelNow = new QLabel(centralwidget);
        labelNow->setObjectName(QString::fromUtf8("labelNow"));
        labelNow->setGeometry(QRect(511, 553, 21, 16));
        QFont font7;
        font7.setPointSize(12);
        font7.setBold(true);
        font7.setWeight(75);
        labelNow->setFont(font7);
        labelNow->setAlignment(Qt::AlignCenter);
        labelNext = new QLabel(centralwidget);
        labelNext->setObjectName(QString::fromUtf8("labelNext"));
        labelNext->setGeometry(QRect(590, 553, 21, 16));
        labelNext->setFont(font7);
        labelNext->setAlignment(Qt::AlignCenter);
        MARCS->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MARCS);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuPlanning = new QMenu(menubar);
        menuPlanning->setObjectName(QString::fromUtf8("menuPlanning"));
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        menuDisplay = new QMenu(menubar);
        menuDisplay->setObjectName(QString::fromUtf8("menuDisplay"));
        menuPost_Flight = new QMenu(menubar);
        menuPost_Flight->setObjectName(QString::fromUtf8("menuPost_Flight"));
        MARCS->setMenuBar(menubar);
        statusbar = new QStatusBar(MARCS);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MARCS->setStatusBar(statusbar);

        menubar->addAction(menuPlanning->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menubar->addAction(menuDisplay->menuAction());
        menubar->addAction(menuPost_Flight->menuAction());
        menuPlanning->addAction(actionLoad_map);
        menuPlanning->addSeparator();
        menuPlanning->addAction(actionLoad_mission);
        menuPlanning->addAction(actionSave_mission);
        menuPlanning->addAction(actionClear_mission);
        menuPlanning->addSeparator();
        menuPlanning->addAction(actionEdit_waypoint);
        menuPlanning->addSeparator();
        menuPlanning->addAction(actionClose);
        menuSettings->addAction(actionConnect_RPA);
        menuSettings->addAction(actionController);
        menuDisplay->addAction(actionFlight_plan);
        menuDisplay->addAction(actionVideo);
        menuDisplay->addAction(actionFlight_data);
        menuDisplay->addSeparator();
        menuPost_Flight->addAction(actionLog);
        menuPost_Flight->addAction(actionRaplay_Mission);

        retranslateUi(MARCS);

        QMetaObject::connectSlotsByName(MARCS);
    } // setupUi

    void retranslateUi(QMainWindow *MARCS)
    {
        MARCS->setWindowTitle(QApplication::translate("MARCS", "MARCS 2.0", 0, QApplication::UnicodeUTF8));
        actionLoad_map->setText(QApplication::translate("MARCS", "Load Map", 0, QApplication::UnicodeUTF8));
        actionLoad_mission->setText(QApplication::translate("MARCS", "Load Mission", 0, QApplication::UnicodeUTF8));
        actionSave_mission->setText(QApplication::translate("MARCS", "Save Mission", 0, QApplication::UnicodeUTF8));
        actionClear_mission->setText(QApplication::translate("MARCS", "Clear Mission", 0, QApplication::UnicodeUTF8));
        actionEdit_waypoint->setText(QApplication::translate("MARCS", "Edit Waypoint", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("MARCS", "Close", 0, QApplication::UnicodeUTF8));
        actionConnect_RPA->setText(QApplication::translate("MARCS", "Connect RPA", 0, QApplication::UnicodeUTF8));
        actionController->setText(QApplication::translate("MARCS", "Controller", 0, QApplication::UnicodeUTF8));
        actionFlight_plan->setText(QApplication::translate("MARCS", "Flight Plan ", 0, QApplication::UnicodeUTF8));
        actionVideo->setText(QApplication::translate("MARCS", "Video", 0, QApplication::UnicodeUTF8));
        actionFlight_data->setText(QApplication::translate("MARCS", "Flight Data", 0, QApplication::UnicodeUTF8));
        actionLog->setText(QApplication::translate("MARCS", "Log", 0, QApplication::UnicodeUTF8));
        actionRaplay_Mission->setText(QApplication::translate("MARCS", "Replay Mission", 0, QApplication::UnicodeUTF8));
        actionFollow_RAP->setText(QApplication::translate("MARCS", "Follow RPA", 0, QApplication::UnicodeUTF8));
        label_HDG->setText(QApplication::translate("MARCS", "HDG (\302\260) :", 0, QApplication::UnicodeUTF8));
        label_Alt->setText(QApplication::translate("MARCS", "Alt  (m ):", 0, QApplication::UnicodeUTF8));
        Delete_button->setText(QApplication::translate("MARCS", "Delete", 0, QApplication::UnicodeUTF8));
        status_button->setText(QApplication::translate("MARCS", "STATUS", 0, QApplication::UnicodeUTF8));
        labelRPA->setText(QApplication::translate("MARCS", "RPA", 0, QApplication::UnicodeUTF8));
        Time_left_Min->setText(QApplication::translate("MARCS", "00", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        snapShoot_button->setToolTip(QApplication::translate("MARCS", "SNAPSHOOT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        snapShoot_button->setText(QString());
        label_Time->setText(QApplication::translate("MARCS", "Time :", 0, QApplication::UnicodeUTF8));
        led_button->setText(QString());
        Time_left_point->setText(QApplication::translate("MARCS", ":", 0, QApplication::UnicodeUTF8));
        FinishEdit_button_2->setText(QApplication::translate("MARCS", "Finish Edition", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        MarbleWidget_plan->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        MarbleWidget_plan->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        MarbleWidget_plan->setProperty("mapThemeId", QVariant(QApplication::translate("MARCS", "earth/openstreetmap/openstreetmap.dgml", 0, QApplication::UnicodeUTF8)));
        battery_label->setText(QString());
#ifndef QT_NO_TOOLTIP
        start_button->setToolTip(QApplication::translate("MARCS", "START MOTOR", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        start_button->setText(QString());
        label_Altitude_2->setText(QApplication::translate("MARCS", "0.0", 0, QApplication::UnicodeUTF8));
        labelMission->setText(QApplication::translate("MARCS", "Mission", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        excute_button->setToolTip(QApplication::translate("MARCS", "EXECUTE", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        excute_button->setText(QString());
        SaveEdit_button->setText(QApplication::translate("MARCS", "Save Edition", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MARCS", "Waypoint                                ", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MARCS", "Longitude", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MARCS", "Latitude", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MARCS", "Altitude (m)\n"
"", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MARCS", "Heading (\302\260)\n"
"", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MARCS", "Distance (m)  \n"
"", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MARCS", "ETA (min)\n"
"", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        NextWaypoint_button->setToolTip(QApplication::translate("MARCS", "NEXT WAYPOINT ", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        NextWaypoint_button->setText(QString());
#ifndef QT_NO_TOOLTIP
        goHome_button->setToolTip(QApplication::translate("MARCS", "GO HOME", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        goHome_button->setText(QString());
        QTableWidgetItem *___qtablewidgetitem7 = tableMarkPoint->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("MARCS", "Waypoint                                ", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableMarkPoint->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("MARCS", "Longitude", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableMarkPoint->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QApplication::translate("MARCS", "Latitude", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableMarkPoint->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QApplication::translate("MARCS", "Altitude (m)\n"
"", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableMarkPoint->horizontalHeaderItem(4);
        ___qtablewidgetitem11->setText(QApplication::translate("MARCS", "Heading (\302\260)\n"
"", 0, QApplication::UnicodeUTF8));
        label_Num_Waypoint->setText(QApplication::translate("MARCS", "Num waypoint", 0, QApplication::UnicodeUTF8));
        Time_left_Seconde->setText(QApplication::translate("MARCS", "00", 0, QApplication::UnicodeUTF8));
        labelMark->setText(QApplication::translate("MARCS", "Mark Points", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = tableRPA->horizontalHeaderItem(1);
        ___qtablewidgetitem12->setText(QApplication::translate("MARCS", "Longitude", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = tableRPA->horizontalHeaderItem(2);
        ___qtablewidgetitem13->setText(QApplication::translate("MARCS", "Latitude", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = tableRPA->horizontalHeaderItem(3);
        ___qtablewidgetitem14->setText(QApplication::translate("MARCS", "Altitude (m)\n"
"", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = tableRPA->horizontalHeaderItem(4);
        ___qtablewidgetitem15->setText(QApplication::translate("MARCS", "Heading (\302\260)\n"
"", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        addMark_button->setToolTip(QApplication::translate("MARCS", "ADD MARK", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        addMark_button->setText(QString());
        label_Time_Left->setText(QApplication::translate("MARCS", "Time Left : ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        AddToMission_button->setToolTip(QApplication::translate("MARCS", "ADD TO MISSION", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        AddToMission_button->setText(QString());
#ifndef QT_NO_TOOLTIP
        MarbleWidget_smallView->setToolTip(QApplication::translate("MARCS", "The Flight Plan", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        MarbleWidget_smallView->setWhatsThis(QApplication::translate("MARCS", "The Flight Plan", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        MarbleWidget_smallView->setProperty("mapThemeId", QVariant(QApplication::translate("MARCS", "earth/openstreetmap/openstreetmap.dgml", 0, QApplication::UnicodeUTF8)));
        label->setText(QApplication::translate("MARCS", "(c) Copyright 2013 Rockwell Collins, Inc. All Rights Reserved.", 0, QApplication::UnicodeUTF8));
        labelNow->setText(QApplication::translate("MARCS", "H", 0, QApplication::UnicodeUTF8));
        labelNext->setText(QApplication::translate("MARCS", "0", 0, QApplication::UnicodeUTF8));
        menuPlanning->setTitle(QApplication::translate("MARCS", "Planning", 0, QApplication::UnicodeUTF8));
        menuSettings->setTitle(QApplication::translate("MARCS", "Settings", 0, QApplication::UnicodeUTF8));
        menuDisplay->setTitle(QApplication::translate("MARCS", "Display", 0, QApplication::UnicodeUTF8));
        menuPost_Flight->setTitle(QApplication::translate("MARCS", "Post-Flight", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MARCS: public Ui_MARCS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARCS_H
