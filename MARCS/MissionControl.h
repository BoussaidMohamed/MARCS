#ifndef __MISSIONCONTROL
#define __MISSIONCONTROL

#include "PeripheralController.h"
#include "CommunicationControl.h"
#include <qmath.h>

#define batteryLow 11.0
#define batteryVeryLow 10.0
#define GPSHigh 9
#define GPSLow 7
#define GPSVeryLow 5
#define lowDigression 8.0
#define highDigression 15.0

class MissionControl : public QObject
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
	static MissionControl* singleton;		//Lone instance
	bool m_bNextSent;						//Next waypoint sent flag
	bool m_bFirstWaypoint;					//First waypoint sent flag
	bool m_bFPLaunched;						//Flight plan launched flag
	QTimer m_pWaypointTimer;				//Waypoint sent timer
	QTimer m_pLaunchTimer;					//Launch sent timer
	short m_pPreviousYawRC;					//
	short m_pPreviousPitchRC;				//
	short m_pPreviousRollRC;				//
	short m_pPreviousThrustRC;				//
	short m_pPreviousSerialRC;				//
	short m_pPreviousGPSHeightControlRC;	//
	bool m_bFirstRC;						//
	double m_dBattery;						//
	int m_nGPS;								//
	bool m_bXBee;							//
	short m_nStatus;						//
	char m_cEngine;							//

	//============= Methods ==================

	/**
	* @brief Constructor
	* @param none
	* @exception none
	* @return MissionControl instance
	*/
	MissionControl();

	/**
	* @brief Destructor
	* @param none
	* @exception none
	* @return none
	*/
	~MissionControl();

public:
	//============= Methods ==================

	/**
	* @brief MissionControl lone instance getter
	* @param none
	* @exception none
	* @return lone instance MissionControl*
	*/
	static MissionControl* getInstance();

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
	* @brief Battery level
	* @param none
	* @exception none
	* @return none
	*/
	void batteryLevel(double p_pValue);

	/**
	* @brief GPS reception level
	* @param none
	* @exception none
	* @return none
	*/
	void GPSLevel(int p_pValue);

	/**
	* @brief Digression value
	* @param none
	* @exception none
	* @return none
	*/
	void digression(double p_pValue);

	/**
	* @brief XBee connection state
	* @param none
	* @exception none
	* @return none
	*/
	void XBeeConnection(bool p_pValue);

	/**
	* @brief Radiocommand connection state
	* @param none
	* @exception none
	* @return none
	*/
	void radiocommandConnection(bool p_pValue);

	/**
	* @brief Direct X problem
	* @param none
	* @exception none
	* @return none
	*/
	void directXProblem();

	/**
	* @brief Problem with the game controller
	* @param none
	* @exception none
	* @return none
	*/
	void controllerProblem();

	/**
	* @brief Controller connected
	* @param none
	* @exception none
	* @return none
	*/
	void controllerConnected();

	/**
	* @brief Change next waypoint
	* @param none
	* @exception none
	* @return none
	*/
	void resetWaypointNotification();

	/**
	* @brief Waypoint to send
	* @param x longitude double
	* @param y latitude double
	* @param z altitude double
	* @param number waypoint number double
	* @exception none
	* @return none
	*/
	void waypoint(double x, double y, double z, double number);

	/**
	* @brief Waypoint to send
	* @param x in meters double
	* @param y in meters double
	* @param z altitude double
	* @param yaw heading double
	* @exception none
	* @return none
	*/
	void move(double x, double y, double z, double yaw);

	/**
	* @brief Send launch order
	* @param none
	* @exception none
	* @return none
	*/
	void sendLaunch();

	/**
	* @brief End of flight plan event
	* @param none
	* @exception none
	* @return none
	*/
	void endFlightPlan();

	/**
	* @brief Waypoint reached event
	* @param none
	* @exception none
	* @return none
	*/
	void waypointReached();

	/**
	* @brief Remote control values changed
	* @param none
	* @exception none
	* @return none
	*/
	void RCDataChanged();

	/**
	* @brief Flight plan launched acknowledge
	* @param none
	* @exception none
	* @return none
	*/
	void flightPlanLaunched();

	/**
	* @brief Cannot launch flight plan event
	* @param p_bBattery battery level above low bool
	* @param p_bGPS enough satellites bool
	* @param p_bXBee link through XBee bool
	* @param p_bStatus MUAV in GPS mode bool
	* @param p_bFlightPlan flight plan loaded bool
	* @param p_bEngine engines started bool
	* @exception none
	* @return none
	*/
	void cannotLaunchFP(bool p_bBattery, bool p_bGPS, bool p_bXBee, bool p_bStatus, 
		bool p_bFlightPlan, bool p_bEngine);

	public slots:
		//============= Slots ====================

		/**
		* @brief Battery level update
		* @param p_pValue battery level double
		* @exception none
		* @return none
		*/
		void updateBattery(double p_pValue);

		/**
		* @brief GPS satellite number update
		* @param p_pValue number of satellite double
		* @exception none
		* @return none
		*/
		void updateGPS(int p_pValue);

		/**
		* @brief Compute the digression value
		* @param none
		* @exception none
		* @return none
		*/
		void updateDigression();

		/**
		* @brief XBee connection state update
		* @param p_pValue connection state bool
		* @exception none
		* @return none
		*/
		void updateXBee(bool p_pValue);

		/**
		* @brief Remote control connection update
		* @param p_pValue remote control link state short
		* @exception none
		* @return none
		*/
		void updateRadiocommand(short p_pValue);

		//temporary
		/**
		* @brief Send waypoint order
		* @param none
		* @exception none
		* @return none
		*/
		void sendWaypoint();

		/**
		* @brief Next waypoint index increment
		* @param none
		* @exception none
		* @return end of flight plan reached
		*/
		bool nextWaypoint();

		/**
		* @brief Update the mission state
		* @param p_cWaypointNumber waypoint number char
		* @param p_nDistance waypoint / MUAV distance short
		* @param p_cStatus navigation status short
		* @exception none
		* @return none
		*/
		void updateNAV(char p_cWaypointNumber, short p_nDistance, short p_cStatus);

		/**
		* @brief Receive MUAV acknowledge
		* @param m_pAck acknowledge string char*
		* @exception none
		* @return none
		*/
		void acknowledge(char* m_pAck);

		/**
		* @brief Launch the flight plan
		* @param none
		* @exception indicate if cannot launch (bad parameters)
		* @return none
		*/
		void launchFlightPlan();

		/**
		* @brief Stop flight plan (reset of next waypoint index)
		* @param none
		* @exception none
		* @return none
		*/
		void stopFlightPlan();

		/**
		* @brief Pause flight plan (no reset of next waypoint index)
		* @param none
		* @exception none
		* @return none
		*/
		void pauseFlightPlan();

		/**
		* @brief Define if waypoint reached
		* @param p_cWaypointNumber don't care char
		* @param p_nDistance don't care short
		* @param p_nNavStatus don't care short
		* @exception none
		* @return none
		*/
		void updateWayStatus(char p_cWaypointNumber, short p_nDistance, short p_nNavStatus);

		/**
		* @brief Define if remote control values changed and update them
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
		void rcData(short p_nYaw, short p_nPitch, short p_nRoll, short p_nThrust, 
			short p_nSerial, short p_nGPSHeightControl, char p_cValid);

		/**
		* @brief Define if the MUAV has its engines started
		* @param none
		* @exception none
		* @return none
		*/
		void inFlight(char p_cValue);

		/**
		* @brief Move forward command
		* @param none
		* @exception none
		* @return none
		*/
		void moveForward();

		/**
		* @brief Move backward command
		* @param none
		* @exception none
		* @return none
		*/
		void moveBackward();

		/**
		* @brief Move left command
		* @param none
		* @exception none
		* @return none
		*/
		void moveLeft();

		/**
		* @brief Move right command
		* @param none
		* @exception none
		* @return none
		*/
		void moveRight();

		/**
		* @brief Turn left command
		* @param none
		* @exception none
		* @return none
		*/
		void turnLeft();

		/**
		* @brief Turn right command
		* @param none
		* @exception none
		* @return none
		*/
		void turnRight();

		/**
		* @brief Increase altitude command
		* @param none
		* @exception none
		* @return none
		*/
		void up();

		/**
		* @brief Decrease altitude command
		* @param none
		* @exception none
		* @return none
		*/
		void down();

		void addMark();
};

#endif
