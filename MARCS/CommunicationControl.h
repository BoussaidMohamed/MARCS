#ifndef __CONTROL
#define __CONTROL

#include <qmath.h>
#include <QtCore/QTimer>
#include <QtCore/QDateTime>
#include "ComThread.h"
#include "UAVLogger.h"

#define DISTMAX		150
#define ALTMAX		100
#define NB_TRIES	5

class CommunicationControl : public QObject
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
	static CommunicationControl* singleton;	//Lone instance
	ComThread* comThread;					//Communication thread
	UAVLogger* log;							//Logger
	QTimer m_pPollTimer;					//Poll timer
	QTimer m_pPollTimeout;					//Poll timeout
	GPS_DATA_ADVANCED gps;					//GPS data structure
	CURRENT_WAY cw;							//Current way data structure
	LL_STATUS st;							//Status data structure
	IMU_CALCDATA imu;						//Inertial Measurement Unit data structure
	RC_DATA rc;								//Remote control received data (by MUAV)
	double longitude;						//Longitude in decimal degrees
	double latitude;						//Latitude in decimal degrees
	double altitude;						//Altitude in meters
	double heading;							//Heading in degrees
	double m_dSpeed;						//Speed in km/h
	double height;							//Hieght from ground in meters
	int m_nLinkTries;						//Data connection tries counter
	QString m_sCom;							//COM port string
	QTimer m_pRetryTimer;					//Timer for connection retry

	//============= Methods ==================

	/**
	* @brief Constructor
	* @param none
	* @exception none
	* @return CommunicationControl instance
	*/
	CommunicationControl();

	/**
	* @brief Destructor
	* @param none
	* @exception none
	* @return none
	*/
	~CommunicationControl();

public:
	//============= Methods ==================

	/**
	* @brief Lone instance getter
	* @param none
	* @exception none
	* @return lone instance CommunicationControl*
	*/
	static CommunicationControl* getInstance();

	/**
	* @brief Instance killer
	* @param none
	* @exception none
	* @return none
	*/
	static void kill();

	/**
	* @brief Start communication
	* @param none
	* @exception none
	* @return none
	*/
	void start(QString p_sCom);

	/**
	* @brief Stop communication
	* @param none
	* @exception none
	* @return none
	*/
	void stop();

	/**
	* @brief Update crc
	* @param none
	* @exception none
	* @return none
	*/
	unsigned short crc_update(unsigned short crc, unsigned char data);

	/**
	* @brief Compute crc
	* @param none
	* @exception none
	* @return none
	*/
	unsigned short crc16(void *data, unsigned short cnt);

	/**
	* @brief Create logger
	* @param none
	* @exception none
	* @return none
	*/
	void createLog();

	/**
	* @brief Write logs
	* @param validCrc valid crc state bool
	* @exception none
	* @return none
	*/
	void writeLog(bool validCrc);

	/**
	* @brief Logger getter
	* @param none
	* @exception none
	* @return logger UAVLogger*
	*/
	UAVLogger* getLogger();

signals:
	//============= Signals ==================

	/**
	* @brief Waypoint to send
	* @param x longitude double
	* @param y latitude double
	* @param z altitude double
	* @param yaw heading double
	* @exception none
	* @return none
	*/
	void sendWaypoint(double x, double y, double z, double yaw);

	/**
	* @brief Relative move to send
	* @param x x axe move in meters double
	* @param y y axe move in meters double
	* @param z z axe move in meters double
	* @param yaw heading value in degrees double
	* @exception none
	* @return none
	*/
	void sendMove(double x, double y, double z, double yaw);

	/**
	* @brief Send go to order
	* @param none
	* @exception none
	* @return none
	*/
	void sendGoTo();

	/**
	* @brief Send launch (define home) order
	* @param none
	* @exception none
	* @return none
	*/
	void sendLaunch();

	/**
	* @brief Send land order
	* @param none
	* @exception none
	* @return none
	*/
	void sendLand();

	/**
	* @brief Send come home order
	* @param none
	* @exception none
	* @return none
	*/
	void sendHome();

	/**
	* @brief Send start engines order
	* @param none
	* @exception none
	* @return none
	*/
	void sendMotOn();

	/**
	* @brief Send stop engines order
	* @param none
	* @exception none
	* @return none
	*/
	void sendMotOff();

	/**
	* @brief Poll data
	* @param dataToPoll data to poll unsigned short
	* @exception none
	* @return none
	*/
	void poll(unsigned short dataToPoll);

	/**
	* @brief Define if the waypoint is valid
	* @param dist distance between the 2 waypoints double
	* @param validLatLong valid coordinates bool
	* @param validAltitude valid altitude bool
	* @exception none
	* @return none
	*/
	void validWaypoint(double dist, bool validLatLong, bool validAltitude);

	/**
	* @brief Waypoint navigation state
	* @param p_cWaypointNumber waypoint number char
	* @param p_nDistance between MUAV and waypoint short
	* @param p_cStatus navigation status (reached or not) short
	* @exception none
	* @return none
	*/
	void waypointNAVInfo(char p_cWaypointNumber, short p_nDistance, short p_cStatus);

	/**
	* @brief GPS qualtity
	* @param p_iSatellite number of get satellites int
	* @exception none
	* @return none
	*/
	void updateGPSQuality(int p_iSatellite);

	/**
	* @brief Battery level
	* @param p_dValue battery voltage double
	* @exception none
	* @return none
	*/
	void batteryLevel(double p_dValue);

	/**
	* @brief MUAV internal state
	* @param p_dValue MUAV status short
	* @exception none
	* @return none
	*/
	void updateStatus(short p_dValue);

	/**
	* @brief Update flight state
	* @param p_cValue flight in progress (engines started) char
	* @exception none
	* @return none
	*/
	void inFlight(char p_cValue);

	/**
	* @brief Update heading value
	* @param p_pValue heading value double
	* @exception none
	* @return none
	*/
	void updateHeading(double p_pValue);

	/**
	* @brief Update height value
	* @param p_pValue heading value double
	* @exception none
	* @return none
	*/
	void updateHeight(double p_pValue);

	/**
	* @brief Update acknowledge value
	* @param data received acknowledge char*
	* @exception none
	* @return none
	*/
	void displayAck(char* data);

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

	/**
	* @brief Update remote control data
	* @param yaw short
	* @param pitch short
	* @param roll short
	* @param thrust short
	* @param serial short
	* @param GPSHeightControl short
	* @param valid char
	* @exception none
	* @return none
	*/
	void rcData(short yaw, short pitch, short roll, short thrust, 
		short serial, short GPSHeightControl, char valid);

	/**
	* @brief Update XBee connection status
	* @param p_bValue status bool
	* @exception none
	* @return none
	*/
	void XBeeStatus(bool p_bValue);

	/**
	* @brief Update speed value
	* @param speed double
	* @exception none
	* @return none
	*/
	void updateSpeed(double p_dSpeed);

	/**
	* @brief XBee physically disconnected
	* @param none
	* @exception none
	* @return none
	*/
	void XBeeDisconnected();

	/**
	* @brief XBee physically reconnected
	* @param none
	* @exception none
	* @return none
	*/
	void XBeeReconnected();

	public slots:
		//============= Slots ====================

		/**
		* @brief Control the given waypoint validity
		* @param xDest longitude double
		* @param yDest latitude double
		* @param zDest altitude double
		* @exception none
		* @return none
		*/
		void controlWaypoint(double xDest, double yDest, double zDest);

		/**
		* @brief Polled data to be sent to other modules
		* @param data polled data char*
		* @param length length in char of the polled data int
		* @exception none
		* @return none
		*/
		void computePolledData(char* data, int length);

		/**
		* @brief Poll data (timed)
		* @param none
		* @exception none
		* @return none
		*/
		void pollData();

		/**
		* @brief Poll data (timed)
		* @param none
		* @exception none
		* @return none
		*/
		void autonomousMode();

		/**
		* @brief Poll data (timed)
		* @param none
		* @exception none
		* @return none
		*/
		void computerAidedControlMode();

		/**
		* @brief Data poll timedout
		* @param none
		* @exception none
		* @return none
		*/
		void pollDataTimedOut();

		/**
		* @brief Retry connection (timed)
		* @param none
		* @exception none
		* @return none
		*/
		void retryConnection();
};

#endif
