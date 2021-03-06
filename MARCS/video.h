#ifndef VIDEO_H
#define VIDEO_H
#include <QString>
#include <MarbleWidget.h>
#include "GeoDataCoordinates.h"

#include <QMainWindow>
using namespace Marble;
namespace Ui {
    class video;
}

class video : public QMainWindow
{
    Q_OBJECT

public:
    explicit video(QWidget *parent = 0);
    ~video();

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
    void close();

private:
    Ui::video *ui;
    QString path ;
};

#endif // VIDEO_H
