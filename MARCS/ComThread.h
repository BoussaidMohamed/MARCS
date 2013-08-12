/******************************************************
*			         MARCS 2012		                  *
*******************************************************
* @file ComThread.h
* @author Nicolas FERRRERO
*
* @date 2012/04/19 (creation_date)
* @date 2012/07/19 (latest_modification_date)
*
* @brief GCS / MUAV communication thread
*
* @bug
* - symptoms : none
* - causes : none
* - solutions : none
*
* @todo : none
*/

#ifndef __COMTHREAD
#define __COMTHREAD

#include <QtCore/QThread>
#include <QtCore/QMutex>
#include <QtCore/QTimer>
#include <windows.h>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include "qextserialport.h"

//Waypoint properties
#define WPPROP_ABSCOORDS		0x01
#define WPPROP_HEIGHTENABLED	0x02
#define WPPROP_YAWENABLED		0x04
#define WPPROP_AUTOMATICGOTO	0x10

//Packet descriptor (polled data)
#define GPS_PACKET				0x0200
#define CURRENT_WAY_PACKET		0x0100
#define STATUS_PACKET			0x0001
#define IMU_CALCDATA_PACKET		0x0004
#define RC_DATA_PACKET			0x0008

//Packet descriptor for data polling
#define IMU_CALCDATA_DESCRIPTOR 0x03
#define GPS_DESCRIPTOR			0x29
#define CURRENT_WAY_DESCRIPTOR	0x21
#define STATUS_DESCRIPTOR		0x02
#define RC_DATA_DESCRIPTOR		0x15

//Communication parameters
#define RX_SIZE         600
#define TX_SIZE         200
#define MAX_WAIT_READ   100
#define READ_INTERVAL	1
#define READ_MULTIPLIER 10
#define MAX_WAIT_WRITE  100

//MUAV state
#define EMERGENCY		0x80
#define HEIGHT_CONTROL	0x02
#define GPS				0x04
#define SERIAL			0x20

//Waypoint status
#define WP_NAVSTAT_REACHED_POS		0x01
#define WP_NAVSTAT_REACHED_POS_TIME 0x02
#define WP_NAVSTAT_20M				0x04

//Acknowwledges
#define DEFINE_HOME_ACK ">a&a<"
#define COME_HOME_ACK	">a(a<"
#define WAYPOINT_ACK	">a$a<"
#define LAND_ACK		">a'a<"
#define GOTO_ACK		">a%a<"

//Waypoint structure
struct WAYPOINT
{
	//always set to 1
	unsigned char wp_number;
	//don't care
	unsigned char dummy_1;
	unsigned short dummy_2;
	//see WPPROP defines below
	unsigned char properties;
	//max. speed to travel to waypoint in % (default 100)
	unsigned char max_speed;
	//time to stay at a waypoint (XYZ) in 1/100th s
	unsigned short time;
	//position accuracy to consider a waypoint reached in mm (default: 2500 (= 2.5 m))
	unsigned short pos_acc;
	//chksum = 0xAAAA + wp.yaw + wp.height + wp.time + wp.X + wp.Y + wp.max_speed + wp.pos_acc + wp.properties + wp.wp_number;
	short chksum;
	//waypoint coordinates in mm // longitude in abs coords
	int X;
	//waypoint coordinates in mm // latitude in abs coords
	int Y;
	//Desired heading at waypoint
	int yaw;
	//height over 0 reference in mm
	int height;
};

//Current way structure
struct CURRENT_WAY
{
	unsigned char dummy1;
	unsigned char properties;
	unsigned short nr_of_wp; //don't care

	unsigned char current_wp; //don't care
	unsigned char current_wp_memlocation; //don't care

	unsigned char status;  //don't care
	unsigned char dummy2;

	unsigned short navigation_status;          //see WP_NAVSTAT_... defines
	unsigned short distance_to_wp;             //distance to WP in dm
}; 

//GPS data structure
struct GPS_DATA_ADVANCED
{
	//latitude/longitude in deg * 10ˆ7
	int latitude;
	int longitude;
	//GPS height in mm
	int height;
	//speed in x (E/W) and y(N/S) in mm/s
	int speed_x;
	int speed_y;
	//GPS heading in deg * 1000
	int heading;
	//accuracy estimates in mm and mm/s
	unsigned int horizontal_accuracy;
	unsigned int vertical_accuracy;
	unsigned int speed_accuracy;
	//number of satellite vehicles used in NAV solution
	unsigned int numSV;
	//GPS status information; 0x03 = valid GPS fix
	int status;
	//coordinates of current origin in deg * 10ˆ7
	int latitude_best_estimate;
	int longitude_best_estimate;
	//velocities in X (E/W) and Y (N/S) after data fusion
	int speed_x_best_estimate;
	int speed_y_best_estimate;
};

//Inertial Measurement Unit structure
struct IMU_CALCDATA
{
	//angles derived by integration of gyro_outputs, drift compensated by data 
	int angle_nick;
	int angle_roll;
	int angle_yaw;
	//angular velocities, raw values [16 bit] but bias free
	int angvel_nick;
	int angvel_roll;
	int angvel_yaw;
	//acc-sensor outputs, calibrated: -10000..+10000 = -1g..+1g
	short acc_x_calib;
	short acc_y_calib;
	short acc_z_calib;
	//horizontal / vertical accelerations: -10000..+10000 = -1g..+1g
	short acc_x;
	short acc_y;
	short acc_z;
	//reference angles derived by accelerations only: -90000..+90000; 1000 = 1 degree
	int acc_angle_nick;
	int acc_angle_roll;
	//total acceleration measured (10000 = 1g)
	int acc_absolute_value;
	//magnetic field sensors output, offset free and scaled
	int Hx;
	int Hy;
	int Hz;
	//compass reading: angle reference for angle_yaw: 0..360000; 1000 = 1 degree
	int mag_heading;
	int speed_x;
	int speed_y;
	int speed_z;
	//height in mm (after data fusion)
	int height;
	//diff. height in mm/s (after data fusion)
	int dheight;
	//diff. height measured by the pressure sensor [mm/s]
	int dheight_reference;
	//height measured by the pressure sensor [mm]
	int height_reference;
};

//MUAV Status structure
struct LL_STATUS
{
	//battery voltages in mV
	short battery_voltage_1;
	short battery_voltage_2;
	//don’t care
	short status;
	//Controller cycles per second (should be ˜1000)
	short cpu_load;
	//don’t care
	char compass_enabled;
	char chksum_error;
	char flying;
	char motors_on;
	short flightMode;
	//Time motors are turning
	short up_time;
};

//Remote control received data structure
struct RC_DATA
{
	//channels as read from R/C receiver
	unsigned short channels_in[8];
	//channels bias free, remapped and scaled to 0..4095
	unsigned short channels_out[8];
	//Indicator for valid R/C receiption
	unsigned char lock;
};

class ComThread : public QThread
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
	HANDLE handle;			//WinAPI handle for virtual COM (XBee)
	DCB dcb;				//WinAPI dcb for handle settings
	WAYPOINT wp;			//Waypoint structure
	bool mustWrite;			//Write flag
	bool mustRead;			//Read flag
	bool mustPoll;			//Poll flag
	char command[TX_SIZE];	//Command to be sent array
	char dataToPoll[10];	//Data poll descriptor array
	char buffer[RX_SIZE];	//Reception buffer
	int sizeWrite;			//Number of char to send
    unsigned long sizeRead;			//Number of char to read
	int sizePoll;			//Number of char to send for data polling
	QTimer timerFail;		//Communication retry timer
	bool failed;			//Transmission failed (not timed out)
	bool failNoticed;		//Transmission fail noticed to the controller

public:
	//============= Methods ==================

	/**
	* @brief Constructor
	* @param none
	* @exception none
	* @return ComThread instance
	*/
	ComThread();

	/**
	* @brief Destructor
	* @param none
	* @exception none
	* @return none
	*/
	~ComThread();

	/**
	* @brief QThread run override
	* @param none
	* @exception none
	* @return none
	*/
	void run();

	/**
	* @brief Create the COM port handler
	* @param p_sCom COM port name QString
	* @exception none
	* @return none
	*/
	void createCom(QString p_sCom);

	/**
	* @brief Destruct the COM port handler
	* @param none
	* @exception none
	* @return none
	*/
	void releaseCom();

	/**
	* @brief Reset all counters
	* @param none
	* @exception none
	* @return none
	*/
	void clearCounters();

signals:
	//============= Signals ==================

	/**
	* @brief Data received event signal
	* @param buffer reception buffer char*
	* @param length number of received char int
	* @exception none
	* @return none
	*/
	void dataReceived(char* buffer, int length);

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

	public slots :
		//============= Slots ====================

		/**
		* @brief Send waypoint slot
		* @param x longitude reference double
		* @param y latitude reference double
		* @param z altitude reference double
		* @param number waypoint number double
		* @exception none
		* @return none
		*/
		void sendWaypoint(double x, double y, double z, double number);

		/**
		* @brief Send relative waypoint slot
		* @param x x axe move reference double
		* @param y y axe move reference double
		* @param z z axe move reference double
		* @param yaw heading reference double
		* @exception none
		* @return none
		*/
		void sendMove(double x, double y, double z, double yaw);

		/**
		* @brief Send go to order slot
		* @param none
		* @exception none
		* @return none
		*/
		void sendGoTo();

		/**
		* @brief Send launch (define home) order slot
		* @param none
		* @exception none
		* @return none
		*/
		void sendLaunch();

		/**
		* @brief Send land order slot
		* @param none
		* @exception none
		* @return none
		*/
		void sendLand();

		/**
		* @brief Send come home order slot
		* @param none
		* @exception none
		* @return none
		*/
		void sendHome();

		/**
		* @brief Send start engines order slot
		* @param none
		* @exception none
		* @return none
		*/
		void sendMotOn();

		/**
		* @brief Send stop engines order slot
		* @param none
		* @exception none
		* @return none
		*/
		void sendMotOff();

		/**
		* @brief Poll data slot
		* @param pDataToPoll data packet to poll descriptor unsigned short
		* @exception none
		* @return none
		*/
		void poll(unsigned short pDataToPoll);
};

#endif
