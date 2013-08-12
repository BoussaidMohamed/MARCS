/******************************************************
*			         MARCS 2012		                  *
*******************************************************
* @file Waypoint.h
* @author Nicolas FERRRERO
*
* @date 2012/04/19 (creation_date)
* @date 2012/07/19 (latest_modification_date)
*
* @brief Waypoint model
*
* @bug
* - symptoms : none
* - causes : none
* - solutions : none
*
* @todo : none
*/

#ifndef __WAYPOINT
#define __WAYPOINT

#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include <QtXml/QDomNode>
#include <QtXml/QDomNodeList>
#include "Action.h"
#include "LatLongCoord.h"

class Waypoint
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
	LatLongCoord* m_pCoordinates;	//Waypoint coordinates in decimal degrees
	double m_dAltitude;				//Waypoint altitude in meters
	Action* m_pAction;				//Associated action
	int m_iNumber;					//Waypoint number

public:
	//============= Methods ==================

	/**
	* @brief Constructor
	* @param none
	* @exception none
	* @return Waypoint instance
	*/
	Waypoint();

	/**
	* @brief Constructor
	* @param p_iNumber waypoint number int
	* @exception none
	* @return Waypoint instance
	*/
	Waypoint(int p_iNumber);

	/**
	* @brief Constructor
	* @param p_pWaypoint waypoint model Waypoint*
	* @exception none
	* @return Waypoint instance
	*/
	Waypoint(Waypoint* p_pWaypoint);

	/**
	* @brief Constructor
	* @param p_pCoordinates waypoint coordinates LatLongCoord*
	* @param p_dAltitude waypoint altitude double
	* @exception none
	* @return Waypoint instance
	*/
	Waypoint(LatLongCoord* p_pCoordinates, double p_dAltitude = 0.);

	/**
	* @brief Destructor
	* @param none
	* @exception none
	* @return none
	*/
	~Waypoint();

	/**
	* @brief Coordinates setter
	* @param p_pCoordinates waypoint coordinates LatLongCoord*
	* @param p_dAltitude waypoint altitude double
	* @exception none
	* @return none
	*/
	void setCoordinates(LatLongCoord* p_pCoordinates, double p_dAltitude = 0.);

	/**
	* @brief Altitude setter
	* @param p_dAltitude waypoint altitude double
	* @exception none
	* @return none
	*/
	void setAltitude(double p_dAltitude);

	/**
	* @brief Action setter
	* @param p_pAction associated action Action*
	* @exception none
	* @return none
	*/
	void setAction(Action* p_pAction);

	/**
	* @brief set action by its string
	* @param p_pAction associated action string QString
	* @exception none
	* @return none
	*/
	void setAction(QString p_pAction);

	/**
	* @brief Waypoint number setter
	* @param p_iNumber waypoint number int
	* @exception none
	* @return none
	*/
	void setNumber(int p_iNumber);

	/**
	* @brief Waypoint coordinates getter
	* @param none
	* @exception none
	* @return none
	*/
	LatLongCoord* getCoordinates();

	/**
	* @brief Waypoint altitude getter
	* @param none
	* @exception none
	* @return none
	*/
	double getAltitude();

	/**
	* @brief Waypoint action getter
	* @param none
	* @exception none
	* @return none
	*/
	Action* getAction();

	/**
	* @brief Compute distance between 2 waypoints
	* @param p_pWaypoint second waypoint model Waypoint*
	* @exception none
	* @return none
	*/
	double getDistance(Waypoint* p_pWaypoint);

	/**
	* @brief Waypoint number getter
	* @param none
	* @exception none
	* @return none
	*/
	int getNumber();

	/**
	* @brief Describe a waypoint in XML structure
	* @param none
	* @exception none
	* @return XML representation of waypoint QDomElement
	*/
	QDomElement toXML(QDomDocument p_pDocument);

	//============= Operators ================

	/**
	* @brief Comparaison operator
	* @param p_pWaypoint second waypoint model Waypoint&
	* @exception none
	* @return Equality between the 2 models bool
	*/
	bool operator == (const Waypoint& p_pWaypoint);
};

#endif