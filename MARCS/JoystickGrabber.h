/******************************************************
*			         MARCS 2012		                  *
*******************************************************
* @file JoystickGrabber.h
* @author Nicolas FERRRERO
*
* @date 2012/04/12 (creation_date)
* @date 2012/07/19 (latest_modification_date)
*
* @brief Game controller (XBox 360 typed) handler
*
* @bug
* - symptoms : none
* - causes : none
* - solutions : none
*
* @todo : none
*/

#ifndef __JOYSTICKGRABBER
#define __JOYSTICKGRABBER

#define _WINSOCKAPI_
#define DIRECTINPUT_VERSION 0x0800

#include <dinput.h>
#include <winsock2.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <QtCore/QObject>
#include <QtCore/QTimer>

#pragma comment(lib, "ws2_32.lib")

class JoystickGrabber : public QObject
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
	QTimer m_pTimer;			//Error send timer
	bool m_bDeviceNotCreated;	//Device not created error flag
	bool m_bNoJoystick;			//No joystick connected error flag
	bool m_bDirectInputProblem;	//Direct Input error flag
	bool m_bDataFormatProblem;	//Data format error flag
	bool m_bJoystickProblem;	//Joystick error flag
	bool m_bDeviceEnumProblem;	//Device enumeration error flag
	
	//============= Methods ==================

	/**
	* @brief Compute datat from game controller grab
	* @param none
	* @exception none
	* @return none
	*/
	void computeData(DIJOYSTATE state);

	/**
	* @brief Finalize the game controller handle
	* @param none
	* @exception none
	* @return none
	*/
	void Finalize();

public:
	//============= Attributes ===============
	double leftStickX;	//Left stick X axe value
	double leftStickY;	//Left stick Y axe value
	double topTrigger;	//Top triggers value
	double rightStickX;	//Right stick X axe value
	double rightStickY;	//Right stick Y axe value
	bool buttons[32];	//Button array
	bool pov[4];		//Point of View stick value

	//============= Methods ==================

	/**
	* @brief Constructor
	* @param none
	* @exception none
	* @return JoystickGrabber instance
	*/
	JoystickGrabber();

	/**
	* @brief Create the Direct X device
	* @param none
	* @exception none
	* @return none
	*/
	void createDevice();

signals:
	//============= Signals ==================

	/**
	* @brief No joystick or gamepad connected signal
	* @param none
	* @exception none
	* @return none
	*/
	void noJoystick();

	/**
	* @brief Direct Input problem signal
	* @param none
	* @exception none
	* @return none
	*/
	void directInputProblem();

	/**
	* @brief Data format for controller problem signal
	* @param none
	* @exception none
	* @return none
	*/
	void dataFormatProblem();

	/**
	* @brief Joystick access problem signal
	* @param none
	* @exception none
	* @return none
	*/
	void joystickProblem();

	/**
	* @brief Enumeration of devices problem signal
	* @param none
	* @exception none
	* @return none
	*/
	void deviceEnumProblem();

	/**
	* @brief Data computed signal
	* @param none
	* @exception none
	* @return none
	*/
	void dataComputed();

	public slots:
		//============= Slots ====================

		/**
		* @brief Grab information one time
		* @param none
		* @exception none
		* @return none
		*/
		void grab();

		/**
		* @brief Send errors each time interval of the timer
		* @param none
		* @exception none
		* @return none
		*/
		void sendAcknowledge();
};

#endif