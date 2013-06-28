#include "flightdata.h"
#include "ui_flightdata.h"
#include "video.h"
#include "mainwindow.h"


MainWindow *myMainWindow;
video *myVideoWindow;

flightdata::flightdata(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::flightdata)

{
    ui->setupUi(this);
    connect(ui->actionVideo,SIGNAL(triggered()),this,SLOT(openNewWindowVideo()));
    connect(ui->actionFlight_plan,SIGNAL(triggered()),this,SLOT(openNewWindowMain()));
    connect(ui->actionClose,SIGNAL(triggered()),this,SLOT(close()));

}



flightdata::~flightdata()
{
    delete ui;
}

void flightdata::openNewWindowMain()
{
   myMainWindow = new MainWindow();
   myMainWindow->show();
  this->hide();

}

void flightdata::openNewWindowVideo()
{
   myVideoWindow = new video();
   myVideoWindow->show();
  this->hide();

}


void flightdata::close()
{
    exit(0);
}
