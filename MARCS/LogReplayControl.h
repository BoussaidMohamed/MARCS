#ifndef __LOGREPLAYCONTROL
#define __LOGREPLAYCONTROL

#include <QtGui/QFileDialog>
//#include "ResourceControl.h"
#include "CommunicationControl.h"

class LogReplayControl : public QObject
{
	Q_OBJECT

		/*
		Prefix 	Meaning			Variable Type

		a 		Array 			Table
		b 		Boolean 		Logic
		d 		Double 			Double precision float
		dw 		Double Word 	Unsigned 32 bits word
		i 		Integer 		Integer used as index
		n 		Integer 		Integer used as value
		p 		Pointer 		Pointer
		s 		String 			String
		ss 		String stream	Stringstream
		*/

private:
	//============= Attributes ===============
	static LogReplayControl* singleton;		//Lone instance
	QTimer m_pReplayTimer;					//Waypoint sent timer
	int m_iData;
	bool m_bReverse;
	QList<double> m_aLatitude;
	QList<double> m_aLongitude;
	QList<double> m_aAltitude;
	QList<double> m_aHeading;
	/*ToggleButton* m_pStartPause;
	QPushButton* m_pIncSpeed;
	QPushButton* m_pDecSpeed;
	QPushButton* m_pStop;*/

	//============= Methods ==================

	/**
	* @brief Constructor
	* @param none
	* @exception none
	* @return LogReplayControl instance
	*/
	LogReplayControl();

	/**
	* @brief Destructor
	* @param none
	* @exception none
	* @return none
	*/
	~LogReplayControl();

public:
	//============= Methods ==================

	/**
	* @brief LogReplayControl lone instance getter
	* @param none
	* @exception none
	* @return lone instance MissionControl*
	*/
	static LogReplayControl* getInstance();

	/**
	* @brief Instance killer
	* @param none
	* @exception none
	* @return none
	*/
	static void kill();

signals:
	//============= Signals ==================

	/**
	* @brief Update heading value
	* @param p_pValue heading value double
	* @exception none
	* @return none
	*/
	void updateHeading(double p_pValue);

	/**
	* @brief Update MUAV geolocation
	* @param x longitude double
	* @param y latitude double
	* @param z altitude double
	* @param yaw heading double
	* @exception none
	* @return none
	*/
	void geolocation(double latitude, double longitude, double altitude, double heading);

	public slots:
		//============= Slots ====================

		void start();

		void pause();

		void stop();

		void backward();

		void forward();

		void replay();

		void openLog();
};

#endif
