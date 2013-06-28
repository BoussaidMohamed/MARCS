/********************************************************************************
** Form generated from reading UI file 'flightdata.ui'
**
** Created: Thu 20. Jun 17:30:47 2013
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLIGHTDATA_H
#define UI_FLIGHTDATA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_flightdata
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
    QAction *actionLog;
    QAction *actionReplay_mission;
    QWidget *centralwidget;
    QLCDNumber *valAltitude;
    QPushButton *start_button;
    QPushButton *led_button;
    QPushButton *goHome_button;
    QPushButton *excute_button;
    QFrame *line;
    QLabel *labelAltitude;
    QPushButton *status_button;
    QLabel *battery_label;
    QPushButton *led_button_2;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QMenu *menuPlanning;
    QMenu *menuSettings;
    QMenu *menuDisplay;
    QMenu *menuPost_Flight;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *flightdata)
    {
        if (flightdata->objectName().isEmpty())
            flightdata->setObjectName(QString::fromUtf8("flightdata"));
        flightdata->resize(800, 632);
        flightdata->setMinimumSize(QSize(800, 632));
        flightdata->setMaximumSize(QSize(800, 632));
        QFont font;
        font.setPointSize(8);
        font.setBold(false);
        font.setWeight(50);
        flightdata->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/drone.png"), QSize(), QIcon::Normal, QIcon::Off);
        flightdata->setWindowIcon(icon);
        actionLoad_map = new QAction(flightdata);
        actionLoad_map->setObjectName(QString::fromUtf8("actionLoad_map"));
        actionSave_mission = new QAction(flightdata);
        actionSave_mission->setObjectName(QString::fromUtf8("actionSave_mission"));
        actionLoad_mission = new QAction(flightdata);
        actionLoad_mission->setObjectName(QString::fromUtf8("actionLoad_mission"));
        actionClose = new QAction(flightdata);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionConnect_RPA = new QAction(flightdata);
        actionConnect_RPA->setObjectName(QString::fromUtf8("actionConnect_RPA"));
        actionController = new QAction(flightdata);
        actionController->setObjectName(QString::fromUtf8("actionController"));
        actionFlight_plan = new QAction(flightdata);
        actionFlight_plan->setObjectName(QString::fromUtf8("actionFlight_plan"));
        actionVideo = new QAction(flightdata);
        actionVideo->setObjectName(QString::fromUtf8("actionVideo"));
        actionVideo->setEnabled(true);
        actionFlight_data = new QAction(flightdata);
        actionFlight_data->setObjectName(QString::fromUtf8("actionFlight_data"));
        actionFlight_data->setEnabled(false);
        actionLog = new QAction(flightdata);
        actionLog->setObjectName(QString::fromUtf8("actionLog"));
        actionReplay_mission = new QAction(flightdata);
        actionReplay_mission->setObjectName(QString::fromUtf8("actionReplay_mission"));
        centralwidget = new QWidget(flightdata);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        valAltitude = new QLCDNumber(centralwidget);
        valAltitude->setObjectName(QString::fromUtf8("valAltitude"));
        valAltitude->setGeometry(QRect(670, 40, 81, 31));
        valAltitude->setSmallDecimalPoint(false);
        valAltitude->setSegmentStyle(QLCDNumber::Flat);
        start_button = new QPushButton(centralwidget);
        start_button->setObjectName(QString::fromUtf8("start_button"));
        start_button->setEnabled(false);
        start_button->setGeometry(QRect(640, 370, 151, 61));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/engineOn.png"), QSize(), QIcon::Normal, QIcon::Off);
        start_button->setIcon(icon1);
        start_button->setIconSize(QSize(61, 151));
        start_button->setCheckable(false);
        start_button->setAutoDefault(true);
        start_button->setDefault(true);
        led_button = new QPushButton(centralwidget);
        led_button->setObjectName(QString::fromUtf8("led_button"));
        led_button->setGeometry(QRect(750, 190, 21, 21));
        led_button->setMinimumSize(QSize(21, 21));
        led_button->setMaximumSize(QSize(21, 21));
        led_button->setAutoDefault(true);
        led_button->setDefault(true);
        goHome_button = new QPushButton(centralwidget);
        goHome_button->setObjectName(QString::fromUtf8("goHome_button"));
        goHome_button->setEnabled(false);
        goHome_button->setGeometry(QRect(640, 530, 151, 61));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/HouseBlack.png"), QSize(), QIcon::Normal, QIcon::Off);
        goHome_button->setIcon(icon2);
        goHome_button->setIconSize(QSize(61, 151));
        goHome_button->setAutoDefault(true);
        goHome_button->setDefault(true);
        excute_button = new QPushButton(centralwidget);
        excute_button->setObjectName(QString::fromUtf8("excute_button"));
        excute_button->setEnabled(false);
        excute_button->setGeometry(QRect(640, 450, 151, 61));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/takeoff.png"), QSize(), QIcon::Normal, QIcon::Off);
        excute_button->setIcon(icon3);
        excute_button->setIconSize(QSize(61, 151));
        excute_button->setAutoDefault(true);
        excute_button->setDefault(true);
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(623, 0, 31, 601));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        labelAltitude = new QLabel(centralwidget);
        labelAltitude->setObjectName(QString::fromUtf8("labelAltitude"));
        labelAltitude->setGeometry(QRect(640, -10, 141, 61));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        labelAltitude->setFont(font1);
        labelAltitude->setText(QString::fromUtf8("ALTITUDE:"));
        labelAltitude->setTextFormat(Qt::LogText);
        labelAltitude->setAlignment(Qt::AlignCenter);
        status_button = new QPushButton(centralwidget);
        status_button->setObjectName(QString::fromUtf8("status_button"));
        status_button->setGeometry(QRect(640, 170, 151, 61));
        status_button->setFont(font1);
        status_button->setIconSize(QSize(60, 60));
        status_button->setAutoDefault(true);
        status_button->setDefault(true);
        status_button->setFlat(false);
        battery_label = new QLabel(centralwidget);
        battery_label->setObjectName(QString::fromUtf8("battery_label"));
        battery_label->setGeometry(QRect(643, 80, 161, 71));
        battery_label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/0.png")));
        battery_label->setScaledContents(true);
        led_button_2 = new QPushButton(centralwidget);
        led_button_2->setObjectName(QString::fromUtf8("led_button_2"));
        led_button_2->setGeometry(QRect(750, 190, 21, 21));
        led_button_2->setMinimumSize(QSize(21, 21));
        led_button_2->setMaximumSize(QSize(21, 21));
        led_button_2->setAutoDefault(true);
        led_button_2->setDefault(true);
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
        tableWidget->setGeometry(QRect(0, 80, 636, 471));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setWeight(75);
        tableWidget->setFont(font2);
        tableWidget->horizontalHeader()->setDefaultSectionSize(90);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(90);
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setMinimumSectionSize(30);
        flightdata->setCentralWidget(centralwidget);
        menubar = new QMenuBar(flightdata);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 19));
        menuPlanning = new QMenu(menubar);
        menuPlanning->setObjectName(QString::fromUtf8("menuPlanning"));
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        menuDisplay = new QMenu(menubar);
        menuDisplay->setObjectName(QString::fromUtf8("menuDisplay"));
        menuPost_Flight = new QMenu(menubar);
        menuPost_Flight->setObjectName(QString::fromUtf8("menuPost_Flight"));
        flightdata->setMenuBar(menubar);
        statusbar = new QStatusBar(flightdata);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        flightdata->setStatusBar(statusbar);

        menubar->addAction(menuPlanning->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menubar->addAction(menuDisplay->menuAction());
        menubar->addAction(menuPost_Flight->menuAction());
        menuPlanning->addAction(actionLoad_map);
        menuPlanning->addSeparator();
        menuPlanning->addAction(actionSave_mission);
        menuPlanning->addAction(actionLoad_mission);
        menuPlanning->addSeparator();
        menuPlanning->addAction(actionClose);
        menuSettings->addAction(actionConnect_RPA);
        menuSettings->addAction(actionController);
        menuDisplay->addAction(actionFlight_plan);
        menuDisplay->addAction(actionVideo);
        menuDisplay->addAction(actionFlight_data);
        menuPost_Flight->addAction(actionLog);
        menuPost_Flight->addAction(actionReplay_mission);

        retranslateUi(flightdata);

        QMetaObject::connectSlotsByName(flightdata);
    } // setupUi

    void retranslateUi(QMainWindow *flightdata)
    {
        flightdata->setWindowTitle(QApplication::translate("flightdata", "MARCS", 0, QApplication::UnicodeUTF8));
        actionLoad_map->setText(QApplication::translate("flightdata", "Load map", 0, QApplication::UnicodeUTF8));
        actionSave_mission->setText(QApplication::translate("flightdata", "Save mission", 0, QApplication::UnicodeUTF8));
        actionLoad_mission->setText(QApplication::translate("flightdata", "Load mission", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("flightdata", "Close", 0, QApplication::UnicodeUTF8));
        actionConnect_RPA->setText(QApplication::translate("flightdata", "Connect RPA", 0, QApplication::UnicodeUTF8));
        actionController->setText(QApplication::translate("flightdata", "Controller", 0, QApplication::UnicodeUTF8));
        actionFlight_plan->setText(QApplication::translate("flightdata", "Flight plan", 0, QApplication::UnicodeUTF8));
        actionVideo->setText(QApplication::translate("flightdata", "Video", 0, QApplication::UnicodeUTF8));
        actionFlight_data->setText(QApplication::translate("flightdata", "Flight data", 0, QApplication::UnicodeUTF8));
        actionLog->setText(QApplication::translate("flightdata", "Log", 0, QApplication::UnicodeUTF8));
        actionReplay_mission->setText(QApplication::translate("flightdata", "Replay mission", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        start_button->setToolTip(QApplication::translate("flightdata", "START MOTOR", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        start_button->setText(QString());
        led_button->setText(QString());
#ifndef QT_NO_TOOLTIP
        goHome_button->setToolTip(QApplication::translate("flightdata", "GO HOME", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        goHome_button->setText(QString());
#ifndef QT_NO_TOOLTIP
        excute_button->setToolTip(QApplication::translate("flightdata", "EXECUTE", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        excute_button->setText(QString());
        status_button->setText(QApplication::translate("flightdata", "STATUS", 0, QApplication::UnicodeUTF8));
        battery_label->setText(QString());
        led_button_2->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("flightdata", "Waypoint                                ", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("flightdata", "Longitude", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("flightdata", "Latitude", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("flightdata", "Altitude (m)\n"
"", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("flightdata", "Heading (\302\260)\n"
"", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("flightdata", "Distance (m)  \n"
"", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("flightdata", "ETA (min)\n"
"", 0, QApplication::UnicodeUTF8));
        menuPlanning->setTitle(QApplication::translate("flightdata", "Planning ", 0, QApplication::UnicodeUTF8));
        menuSettings->setTitle(QApplication::translate("flightdata", "Settings", 0, QApplication::UnicodeUTF8));
        menuDisplay->setTitle(QApplication::translate("flightdata", "Display", 0, QApplication::UnicodeUTF8));
        menuPost_Flight->setTitle(QApplication::translate("flightdata", "Post-Flight", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class flightdata: public Ui_flightdata {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLIGHTDATA_H
