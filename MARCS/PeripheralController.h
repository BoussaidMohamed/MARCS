/******************************************************
*			         MARCS 2012		                  *
*******************************************************
* @file ProgramControl.h
* @author Nicolas FERRRERO
*
* @date 2012/06/26 (creation_date)
* @date 2012/07/20 (latest_modification_date)
*
* @brief Program controller (execution management)
*
* @bug
* - symptoms : none
* - causes : none
* - solutions : none
*
* @todo : none
*/


#ifndef __PERIPHERALCONTROLLER
#define __PERIPHERALCONTROLLER

#include <QtCore/QTimer>
#include <QtGui/QCursor>
#include <QtGui/QApplication>
#include <QtGui/QMouseEvent>
#include "JoystickGrabber.h"
#include "RPA.h"

class PeripheralController : public QObject
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
	bool problemDetected;					//Problem detected with the controller
	bool m_bMouseMode;						//Controller in mouse mode
	bool m_bWaitRelease;					//Button (left click) already pressed
	bool m_bWaitReleaseRight;				//Button (right click) already pressed
	bool m_bWaitReleaseMode;				//Button (change mode) already pressed
	QTimer m_pTimer;						//Grab timer
	JoystickGrabber* m_pJoystick;			//Joystick manager
	static PeripheralController* singleton;	//Lone instance

	//============= Methods ==================

	/**
	* @brief Constructor
	* @param none
	* @exception none
	* @return PeripheralController instance
	*/
	PeripheralController();

	/**
	* @brief Destructor
	* @param none
	* @exception none
	* @return none
	*/
	~PeripheralController();

	/**
	* @brief Mouse mode management
	* @param none
	* @exception none
	* @return none
	*/
	void mouseMode();

	/**
	* @brief MUAV control management
	* @param none
	* @exception none
	* @return none
	*/
	void controlMode();

public:
	//============= Methods ==================

	/**
	* @brief Get the lone instance
	* @param none
	* @exception none
	* @return PeripheralController instance PeripheralController*
	*/
    static PeripheralController* getInstance();

	/**
	* @brief Lone instance killer
	* @param none
	* @exception none
	* @return none
	*/
	static void kill();

	/**
	* @brief Start grab timer
	* @param p_nTime interval time in ms for grab int
	* @exception none
	* @return none
	*/
	void startControllerGrab(int p_nTime);

	/**
	* @brief Mouse mode activated indicator
	* @param none
	* @exception none
	* @return In mouse mode bool
	*/
	bool isMouseMode();

signals:
	//============= Signals ==================

	/**
	* @brief Mouse event reagrding actions on gamepad
	* @param button emulated pressed button Qt::MouseButton
	* @param waitRelease button already pressed bool
	* @exception none
	* @return none
	*/
	void mouseEvent(Qt::MouseButton button, bool waitRelease);

	/**
	* @brief Controller connected event
	* @param none
	* @exception none
	* @return none
	*/
	void controllerConnected();

	/**
	* @brief No joystick event
	* @param none
	* @exception none
	* @return none
	*/
	void noJoystick();

	/**
	* @brief Direct Input problem
	* @param none
	* @exception none
	* @return none
	*/
	void directInputProblem();

	/**
	* @brief Direct X data format problem
	* @param none
	* @exception none
	* @return none
	*/
	void dataFormatProblem();

	/**
	* @brief Game controller device state get problem
	* @param none
	* @exception none
	* @return none
	*/
	void joystickProblem();

	/**
	* @brief Device emumeration problem
	* @param none
	* @exception none
	* @return none
	*/
	void deviceEnumProblem();

	/**
	* @brief Controller mouse mode event
	* @param none
	* @exception none
	* @return none
	*/
	void controllerMouseMode();

	/**
	* @brief Controller control mode event
	* @param none
	* @exception none
	* @return none
	*/
	void controllerControlMode();

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

	public slots:
		//============= Slots ====================

		/**
		* @brief Controller handle slot (timed by another software controller)
		* @param none
		* @exception none
		* @return none
		*/
		void useController();
};

#endif
