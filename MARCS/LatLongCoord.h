/******************************************************
*			         MARCS 2012		                  *
*******************************************************
* @file LatLongCoord.h
* @author Nicolas FERRRERO
*
* @date 2012/06/07 (creation_date)
* @date 2012/07/19 (latest_modification_date)
*
* @brief Latitude / longitude coordinates model
*
* @bug
* - symptoms : none
* - causes : none
* - solutions : none
*
* @todo : none
*/

#ifndef __LATLONGCOORD
#define __LATLONGCOORD

#include <QtCore/qmath.h>
#include <limits>

class LatLongCoord
{
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
	double m_dLatitude;		//Latitude in decimal degrees
	double m_dLongitude;	//Longitude in decimal degrees

public:
	//============= Methods ==================

	/**
	* @brief Constructor
	* @param none
	* @exception none
	* @return LatLongCoord instance
	*/
	LatLongCoord();

	/**
	* @brief Constructor
	* @param p_pCoordinates latitude / longitude coordinates LatLongCoord*
	* @exception none
	* @return LatLongCoord instance
	*/
	LatLongCoord(LatLongCoord* p_pCoordinates);

	/**
	* @brief Constructor
	* @param p_dLatitude latitude in decimal degrees double
	* @param p_dLongitude longitude in decimal degrees double
	* @exception none
	* @return LatLongCoord instance
	*/
	LatLongCoord(double p_dLatitude, double p_dLongitude);

	/**
	* @brief Coordinates setter
	* @param p_dLatitude latitude in decimal degrees double
	* @param p_dLongitude longitude in decimal degrees double
	* @exception none
	* @return none
	*/
	void setCoordinates(double p_dLatitude, double p_dLongitude);

	/**
	* @brief Latitude getter
	* @param none
	* @exception none
	* @return Latitude in decimal degrees double
	*/
	double getLatitude();

	/**
	* @brief Longitude getter
	* @param none
	* @exception none
	* @return Latitude in decimal degrees double
	*/
	double getLongitude();

	/**
	* @brief Compute distance between 2 latitude / longitude coordinates
	* @param p_pCoordinate second coordinates model LatLongCoord*
	* @exception none
	* @return none
	*/
	double getDistance(LatLongCoord* p_pCoordinate);
	
	//============= Operators ================

	/**
	* @brief Comparaison operator
	* @param p_pLatLong second coordinates model LatLongCoord&
	* @exception none
	* @return Equality between the 2 models bool
	*/
	bool operator == (const LatLongCoord& p_pLatLong);
};

#endif