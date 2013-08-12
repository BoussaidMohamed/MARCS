/********************************************************************************
** Form generated from reading UI file 'video.ui'
**
** Created: Wed 7. Aug 10:58:17 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEO_H
#define UI_VIDEO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
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

class Ui_video
{
public:
    QAction *actionLoad_map;
    QAction *actionSave_mission;
    QAction *actionLoad_mission;
    QAction *actionClose;
    QAction *actionConnect_RPA;
    QAction *actionController;
    QAction *actionFlight_plan;
    QAction *actionVideo;
    QAction *actionFlight_data;
    QAction *actionLogs;
    QAction *actionReplay_mission;
    QAction *actionClear_mission;
    QAction *actionStart_planning;
    QAction *actionEdit_waypoint;
    QWidget *centralwidget;
    QLCDNumber *valAltitude;
    QPushButton *excute_button;
    QLabel *battery_label;
    QFrame *line;
    QPushButton *addMark_button;
    QLabel *label_Altitude;
    QPushButton *status_button;
    QPushButton *start_button;
    QPushButton *goHome_button;
    QPushButton *led_button;
    QPushButton *snapShoot_button;
    Marble::MarbleWidget *MarbleWidget_smallView;
    Marble::MarbleWidget *MarbleWidget_plan;
    QTableWidget *tableWidget;
    QListWidget *listLog;
    QComboBox *comboBox_ListWaypoint;
    QLabel *label_Num_Waypoint;
    QFrame *line_2;
    QLineEdit *lineEdit_Alt;
    QLineEdit *lineEdit_HDG;
    QLabel *label_Alt;
    QLabel *label_HDG;
    QLabel *label_Time;
    QPushButton *SaveEdit_button;
    QTimeEdit *timeEdit_Mission;
    QPushButton *FinishEdit_button_2;
    QPushButton *Delete_button;
    QLabel *label;
    QLabel *Time_left;
    QMenuBar *menubar;
    QMenu *menuPlanning;
    QMenu *menuSettings;
    QMenu *menuDisplay;
    QMenu *menuPost_Flight;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *video)
    {
        if (video->objectName().isEmpty())
            video->setObjectName(QString::fromUtf8("video"));
        video->setWindowModality(Qt::WindowModal);
        video->resize(800, 632);
        video->setMinimumSize(QSize(800, 632));
        video->setMaximumSize(QSize(800, 635));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/drone.png"), QSize(), QIcon::Normal, QIcon::Off);
        video->setWindowIcon(icon);
        actionLoad_map = new QAction(video);
        actionLoad_map->setObjectName(QString::fromUtf8("actionLoad_map"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/icon/Open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad_map->setIcon(icon1);
        actionSave_mission = new QAction(video);
        actionSave_mission->setObjectName(QString::fromUtf8("actionSave_mission"));
        actionSave_mission->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/icon/Save-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_mission->setIcon(icon2);
        actionLoad_mission = new QAction(video);
        actionLoad_mission->setObjectName(QString::fromUtf8("actionLoad_mission"));
        actionLoad_mission->setIcon(icon1);
        actionClose = new QAction(video);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/icon/cute_ball_stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon3);
        actionConnect_RPA = new QAction(video);
        actionConnect_RPA->setObjectName(QString::fromUtf8("actionConnect_RPA"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/icon/Actions network connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect_RPA->setIcon(icon4);
        actionController = new QAction(video);
        actionController->setObjectName(QString::fromUtf8("actionController"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/icon/joystick_256.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionController->setIcon(icon5);
        actionFlight_plan = new QAction(video);
        actionFlight_plan->setObjectName(QString::fromUtf8("actionFlight_plan"));
        actionFlight_plan->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/icon/psd-world-map-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFlight_plan->setIcon(icon6);
        actionVideo = new QAction(video);
        actionVideo->setObjectName(QString::fromUtf8("actionVideo"));
        actionVideo->setEnabled(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/icon/camera.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionVideo->setIcon(icon7);
        actionFlight_data = new QAction(video);
        actionFlight_data->setObjectName(QString::fromUtf8("actionFlight_data"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/prefix1/icon/url1.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFlight_data->setIcon(icon8);
        actionLogs = new QAction(video);
        actionLogs->setObjectName(QString::fromUtf8("actionLogs"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/prefix1/icon/crystal-log.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLogs->setIcon(icon9);
        actionReplay_mission = new QAction(video);
        actionReplay_mission->setObjectName(QString::fromUtf8("actionReplay_mission"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/new/prefix1/icon/replay_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReplay_mission->setIcon(icon10);
        actionClear_mission = new QAction(video);
        actionClear_mission->setObjectName(QString::fromUtf8("actionClear_mission"));
        actionClear_mission->setEnabled(false);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/new/prefix1/icon/Gnome-edit-clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear_mission->setIcon(icon11);
        actionStart_planning = new QAction(video);
        actionStart_planning->setObjectName(QString::fromUtf8("actionStart_planning"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/new/prefix1/icon/Start.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStart_planning->setIcon(icon12);
        actionEdit_waypoint = new QAction(video);
        actionEdit_waypoint->setObjectName(QString::fromUtf8("actionEdit_waypoint"));
        actionEdit_waypoint->setEnabled(false);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/new/prefix1/icon/Edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEdit_waypoint->setIcon(icon13);
        centralwidget = new QWidget(video);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        valAltitude = new QLCDNumber(centralwidget);
        valAltitude->setObjectName(QString::fromUtf8("valAltitude"));
        valAltitude->setGeometry(QRect(670, 30, 81, 31));
        valAltitude->setSmallDecimalPoint(false);
        valAltitude->setSegmentStyle(QLCDNumber::Flat);
        excute_button = new QPushButton(centralwidget);
        excute_button->setObjectName(QString::fromUtf8("excute_button"));
        excute_button->setEnabled(false);
        excute_button->setGeometry(QRect(640, 450, 151, 61));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/new/prefix1/icon/takeoff.png"), QSize(), QIcon::Normal, QIcon::Off);
        excute_button->setIcon(icon14);
        excute_button->setIconSize(QSize(61, 151));
        excute_button->setAutoDefault(true);
        excute_button->setDefault(true);
        battery_label = new QLabel(centralwidget);
        battery_label->setObjectName(QString::fromUtf8("battery_label"));
        battery_label->setGeometry(QRect(640, 70, 161, 71));
        battery_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/icon/0.png")));
        battery_label->setScaledContents(true);
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(623, 0, 31, 641));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        addMark_button = new QPushButton(centralwidget);
        addMark_button->setObjectName(QString::fromUtf8("addMark_button"));
        addMark_button->setEnabled(false);
        addMark_button->setGeometry(QRect(0, 530, 151, 61));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/new/prefix1/icon/add_mark.png"), QSize(), QIcon::Normal, QIcon::Off);
        addMark_button->setIcon(icon15);
        addMark_button->setIconSize(QSize(61, 50));
        addMark_button->setAutoDefault(true);
        addMark_button->setDefault(true);
        label_Altitude = new QLabel(centralwidget);
        label_Altitude->setObjectName(QString::fromUtf8("label_Altitude"));
        label_Altitude->setGeometry(QRect(640, -20, 141, 61));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_Altitude->setFont(font);
        label_Altitude->setText(QString::fromUtf8("ALTITUDE:"));
        label_Altitude->setTextFormat(Qt::LogText);
        label_Altitude->setAlignment(Qt::AlignCenter);
        status_button = new QPushButton(centralwidget);
        status_button->setObjectName(QString::fromUtf8("status_button"));
        status_button->setGeometry(QRect(640, 170, 151, 61));
        status_button->setFont(font);
        status_button->setIconSize(QSize(60, 60));
        status_button->setAutoDefault(true);
        status_button->setDefault(true);
        status_button->setFlat(false);
        start_button = new QPushButton(centralwidget);
        start_button->setObjectName(QString::fromUtf8("start_button"));
        start_button->setEnabled(false);
        start_button->setGeometry(QRect(640, 370, 151, 61));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/new/prefix1/icon/engineOff.png"), QSize(), QIcon::Normal, QIcon::Off);
        start_button->setIcon(icon16);
        start_button->setIconSize(QSize(61, 151));
        start_button->setCheckable(false);
        start_button->setAutoDefault(true);
        start_button->setDefault(true);
        goHome_button = new QPushButton(centralwidget);
        goHome_button->setObjectName(QString::fromUtf8("goHome_button"));
        goHome_button->setEnabled(false);
        goHome_button->setGeometry(QRect(640, 530, 151, 61));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/new/prefix1/icon/HouseBlack.png"), QSize(), QIcon::Normal, QIcon::Off);
        goHome_button->setIcon(icon17);
        goHome_button->setIconSize(QSize(61, 151));
        goHome_button->setAutoDefault(true);
        goHome_button->setDefault(true);
        led_button = new QPushButton(centralwidget);
        led_button->setObjectName(QString::fromUtf8("led_button"));
        led_button->setGeometry(QRect(750, 190, 21, 21));
        led_button->setMinimumSize(QSize(21, 21));
        led_button->setMaximumSize(QSize(21, 21));
        led_button->setAutoDefault(true);
        led_button->setDefault(true);
        snapShoot_button = new QPushButton(centralwidget);
        snapShoot_button->setObjectName(QString::fromUtf8("snapShoot_button"));
        snapShoot_button->setEnabled(false);
        snapShoot_button->setGeometry(QRect(160, 530, 151, 61));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/new/prefix1/icon/11954231621344997843camera_pictogram_r5d_01.svg.hi.png"), QSize(), QIcon::Normal, QIcon::Off);
        snapShoot_button->setIcon(icon18);
        snapShoot_button->setIconSize(QSize(61, 50));
        snapShoot_button->setAutoDefault(true);
        snapShoot_button->setDefault(true);
        MarbleWidget_smallView = new Marble::MarbleWidget(centralwidget);
        MarbleWidget_smallView->setObjectName(QString::fromUtf8("MarbleWidget_smallView"));
        MarbleWidget_smallView->setGeometry(QRect(650, 240, 141, 121));
        MarbleWidget_smallView->setMinimumSize(QSize(25, 25));
        MarbleWidget_smallView->setMaximumSize(QSize(141, 121));
        MarbleWidget_smallView->setProperty("zoom", QVariant(2100));
        MarbleWidget_smallView->setProperty("longitude", QVariant(1.4));
        MarbleWidget_smallView->setProperty("latitude", QVariant(43.6));
        MarbleWidget_smallView->setProperty("showOverviewMap", QVariant(false));
        MarbleWidget_smallView->setProperty("showScaleBar", QVariant(false));
        MarbleWidget_smallView->setProperty("showCompass", QVariant(false));
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
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 631, 521));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setWeight(75);
        tableWidget->setFont(font1);
        tableWidget->horizontalHeader()->setDefaultSectionSize(90);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(90);
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setMinimumSectionSize(30);
        listLog = new QListWidget(centralwidget);
        listLog->setObjectName(QString::fromUtf8("listLog"));
        listLog->setGeometry(QRect(640, 230, 151, 201));
        comboBox_ListWaypoint = new QComboBox(centralwidget);
        comboBox_ListWaypoint->setObjectName(QString::fromUtf8("comboBox_ListWaypoint"));
        comboBox_ListWaypoint->setGeometry(QRect(240, 530, 41, 22));
        label_Num_Waypoint = new QLabel(centralwidget);
        label_Num_Waypoint->setObjectName(QString::fromUtf8("label_Num_Waypoint"));
        label_Num_Waypoint->setEnabled(true);
        label_Num_Waypoint->setGeometry(QRect(160, 530, 81, 21));
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(280, 520, 20, 71));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        lineEdit_Alt = new QLineEdit(centralwidget);
        lineEdit_Alt->setObjectName(QString::fromUtf8("lineEdit_Alt"));
        lineEdit_Alt->setGeometry(QRect(340, 528, 61, 21));
        lineEdit_HDG = new QLineEdit(centralwidget);
        lineEdit_HDG->setObjectName(QString::fromUtf8("lineEdit_HDG"));
        lineEdit_HDG->setGeometry(QRect(570, 528, 61, 21));
        label_Alt = new QLabel(centralwidget);
        label_Alt->setObjectName(QString::fromUtf8("label_Alt"));
        label_Alt->setGeometry(QRect(295, 530, 46, 13));
        label_HDG = new QLabel(centralwidget);
        label_HDG->setObjectName(QString::fromUtf8("label_HDG"));
        label_HDG->setGeometry(QRect(520, 530, 46, 13));
        label_Time = new QLabel(centralwidget);
        label_Time->setObjectName(QString::fromUtf8("label_Time"));
        label_Time->setGeometry(QRect(408, 530, 46, 13));
        SaveEdit_button = new QPushButton(centralwidget);
        SaveEdit_button->setObjectName(QString::fromUtf8("SaveEdit_button"));
        SaveEdit_button->setGeometry(QRect(330, 568, 75, 23));
        timeEdit_Mission = new QTimeEdit(centralwidget);
        timeEdit_Mission->setObjectName(QString::fromUtf8("timeEdit_Mission"));
        timeEdit_Mission->setGeometry(QRect(440, 528, 71, 21));
        FinishEdit_button_2 = new QPushButton(centralwidget);
        FinishEdit_button_2->setObjectName(QString::fromUtf8("FinishEdit_button_2"));
        FinishEdit_button_2->setGeometry(QRect(530, 568, 75, 23));
        Delete_button = new QPushButton(centralwidget);
        Delete_button->setObjectName(QString::fromUtf8("Delete_button"));
        Delete_button->setGeometry(QRect(430, 568, 75, 23));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(650, 140, 71, 21));
        Time_left = new QLabel(centralwidget);
        Time_left->setObjectName(QString::fromUtf8("Time_left"));
        Time_left->setGeometry(QRect(720, 140, 61, 21));
        video->setCentralWidget(centralwidget);
        menubar = new QMenuBar(video);
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
        video->setMenuBar(menubar);
        statusbar = new QStatusBar(video);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        video->setStatusBar(statusbar);

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
        menuPost_Flight->addAction(actionLogs);
        menuPost_Flight->addAction(actionReplay_mission);

        retranslateUi(video);

        QMetaObject::connectSlotsByName(video);
    } // setupUi

    void retranslateUi(QMainWindow *video)
    {
        video->setWindowTitle(QApplication::translate("video", "MARCS", 0, QApplication::UnicodeUTF8));
        actionLoad_map->setText(QApplication::translate("video", "Load map", 0, QApplication::UnicodeUTF8));
        actionSave_mission->setText(QApplication::translate("video", "Save mission", 0, QApplication::UnicodeUTF8));
        actionLoad_mission->setText(QApplication::translate("video", "Load mission", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("video", "Close", 0, QApplication::UnicodeUTF8));
        actionConnect_RPA->setText(QApplication::translate("video", "Connect RPA", 0, QApplication::UnicodeUTF8));
        actionController->setText(QApplication::translate("video", "Controller", 0, QApplication::UnicodeUTF8));
        actionFlight_plan->setText(QApplication::translate("video", "Flight plan", 0, QApplication::UnicodeUTF8));
        actionVideo->setText(QApplication::translate("video", "Video", 0, QApplication::UnicodeUTF8));
        actionFlight_data->setText(QApplication::translate("video", "Flight data", 0, QApplication::UnicodeUTF8));
        actionLogs->setText(QApplication::translate("video", "Log", 0, QApplication::UnicodeUTF8));
        actionReplay_mission->setText(QApplication::translate("video", "Replay mission", 0, QApplication::UnicodeUTF8));
        actionClear_mission->setText(QApplication::translate("video", "Clear mission ", 0, QApplication::UnicodeUTF8));
        actionStart_planning->setText(QApplication::translate("video", "Start planning", 0, QApplication::UnicodeUTF8));
        actionEdit_waypoint->setText(QApplication::translate("video", "Edit waypoint", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        excute_button->setToolTip(QApplication::translate("video", "EXECUTE", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        excute_button->setText(QString());
        battery_label->setText(QString());
#ifndef QT_NO_TOOLTIP
        addMark_button->setToolTip(QApplication::translate("video", "ADD MARK", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        addMark_button->setText(QString());
        status_button->setText(QApplication::translate("video", "STATUS", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        start_button->setToolTip(QApplication::translate("video", "START MOTOR", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        start_button->setText(QString());
#ifndef QT_NO_TOOLTIP
        goHome_button->setToolTip(QApplication::translate("video", "GO HOME", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        goHome_button->setText(QString());
        led_button->setText(QString());
#ifndef QT_NO_TOOLTIP
        snapShoot_button->setToolTip(QApplication::translate("video", "SNAPSHOOT", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        snapShoot_button->setText(QString());
#ifndef QT_NO_TOOLTIP
        MarbleWidget_smallView->setToolTip(QApplication::translate("video", "The Earth", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        MarbleWidget_smallView->setWhatsThis(QApplication::translate("video", "The Marble widget displays a virtual globe.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        MarbleWidget_smallView->setProperty("mapThemeId", QVariant(QApplication::translate("video", "earth/openstreetmap/openstreetmap.dgml", 0, QApplication::UnicodeUTF8)));
#ifndef QT_NO_TOOLTIP
        MarbleWidget_plan->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        MarbleWidget_plan->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        MarbleWidget_plan->setProperty("mapThemeId", QVariant(QApplication::translate("video", "earth/openstreetmap/openstreetmap.dgml", 0, QApplication::UnicodeUTF8)));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("video", "Waypoint                                ", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("video", "Longitude", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("video", "Latitude", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("video", "Altitude (m)\n"
"", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("video", "Heading (\302\260)\n"
"", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("video", "Distance (m)  \n"
"", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("video", "ETA (min)\n"
"", 0, QApplication::UnicodeUTF8));
        label_Num_Waypoint->setText(QApplication::translate("video", "Num waypoint", 0, QApplication::UnicodeUTF8));
        label_Alt->setText(QApplication::translate("video", "Alt  (m ):", 0, QApplication::UnicodeUTF8));
        label_HDG->setText(QApplication::translate("video", "HDG (\302\260) :", 0, QApplication::UnicodeUTF8));
        label_Time->setText(QApplication::translate("video", "Time :", 0, QApplication::UnicodeUTF8));
        SaveEdit_button->setText(QApplication::translate("video", "Save Edition", 0, QApplication::UnicodeUTF8));
        FinishEdit_button_2->setText(QApplication::translate("video", "Finish Edition", 0, QApplication::UnicodeUTF8));
        Delete_button->setText(QApplication::translate("video", "Delete", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("video", "Time Left : ", 0, QApplication::UnicodeUTF8));
        Time_left->setText(QApplication::translate("video", "0.0", 0, QApplication::UnicodeUTF8));
        menuPlanning->setTitle(QApplication::translate("video", "Planning", 0, QApplication::UnicodeUTF8));
        menuSettings->setTitle(QApplication::translate("video", "Settings", 0, QApplication::UnicodeUTF8));
        menuDisplay->setTitle(QApplication::translate("video", "Display", 0, QApplication::UnicodeUTF8));
        menuPost_Flight->setTitle(QApplication::translate("video", "Post-Flight", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class video: public Ui_video {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEO_H
