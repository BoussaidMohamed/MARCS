/******************************************************
*			         MARCS 2012		                  *
*******************************************************
* @file UAV.h
* @author Nicolas FERRRERO
*
* @date 2012/07/04 (creation_date)
* @date 2012/07/19 (latest_modification_date)
*
* @brief UAV model
*
* @bug
* - symptoms : none
* - causes : none
* - solutions : none
*
* @todo : none
*/

#ifndef __UAV
#define __UAV

#include <QtCore/QObject>
#include "CommunicationControl.h"
#include "LogReplayControl.h"
#include "LatLongCoord.h"

class UAV : public QObject
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

private :
	//============= Attributes ===============
	static UAV* singleton;		//UAV lone instance
	LatLongCoord* m_pPosition;	//UAV latitude / longitude coordinates in decimal degrees
	double m_dAltitude;			//UAV altitude in meters
	double m_dHeading;			//UAV heading in degrees
	double m_dHeight;			//UAV height in degrees

	//============= Methods ==================

	/**
	* @brief Constructor
	* @param none
	* @exception none
	* @return UAV instance
	*/
	UAV();

	/**
	* @brief Destructor
	* @param none
	* @exception none
	* @return none
	*/
	~UAV();

public :
	//============= Methods ==================

	/**
	* @brief UAV instance getter
	* @param none
	* @exception none
	* @return UAV pointer UAV*
	*/
	static UAV* getInstance();

	/**
	* @brief UAV instance killer
	* @param none
	* @exception none
	* @return none
	*/
	static void kill();

	/**
	* @brief UAV coordinates setter
	* @param p_pPosition new GPS coordinates LatLongCoord*
	* @exception none
	* @return none
	*/
	void setCoordinates(LatLongCoord* p_pPosition);

	/**
	* @brief UAV altitude setter
	* @param p_dAltitude new altitude double
	* @exception none
	* @return none
	*/
	void setAltitude(double p_dAltitude);

	/**
	* @brief UAV heading setter
	* @param p_dHeading new heading double
	* @exception none
	* @return none
	*/
	void setHeading(double p_dHeading);

	/**
	* @brief UAV height setter
	* @param p_dHeading new heading double
	* @exception none
	* @return none
	*/
	void setHeight(double p_dHeight);

	/**
	* @brief UAV coordinates getter
	* @param none
	* @exception none
	* @return latitude / longitude coordinates in decimal degrees LatLongCoord*
	*/
	LatLongCoord* getCoordinates();

	/**
	* @brief UAV altitude getter
	* @param none
	* @exception none
	* @return altitude in meters double
	*/
	double getAltitude();

	/**
	* @brief UAV heading getter
	* @param none
	* @exception none
	* @return heading in degrees double
	*/
	double getHeading();
	
	/**
	* @brief UAV height getter
	* @param none
	* @exception none
	* @return heading in degrees double
	*/
	double getHeight();

signals:
	//============= Signals ==================

	/**
	* @brief Position changed event signal
	* @param none
	* @exception none
	* @return none
	*/
	void positionChanged();

	public slots:
		//============= Slots ====================

		/**
		* @brief geolocation update slot
		* @param p_fLatitude latitude double
		* @param p_fLongitude longitude double
		* @param p_fAltitude altitude double
		* @param p_fHeading "false" heading double
		* @exception none
		* @return none
		*/
		void geolocation(double p_fLatitude, double p_fLongitude, double p_fAltitude, double p_fHeading);

		/**
		* @brief "real" heading update slot
		* @param p_pValue "real" heading value double
		* @exception none
		* @return none
		*/
		void updateHeading(double p_pValue);
		
		/**
		* @brief Height (from ground) update slot
		* @param p_pValue "real" heading value double
		* @exception none
		* @return none
		*/
		void updateHeight(double p_pValue);
};

#endif