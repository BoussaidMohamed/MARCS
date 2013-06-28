/******************************************************
*			         MARCS 2012		                  *
*******************************************************
* @file ResourceControl.h
* @author Nicolas FERRRERO
*
* @date 2012/07/16 (creation_date)
* @date 2012/07/19 (latest_modification_date)
*
* @brief Manage resources
*
* @bug
* - symptoms : none
* - causes : none
* - solutions : none
*
* @todo : none
*/

#ifndef __RESOURCECONTROL
#define __RESOURCECONTROL

#include <QtXml/QDomDocument>
#include <QtCore/QFile>

static QDomDocument m_pResources;

class ResourceControl : QObject
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

public:
	//============= Methods ==================

	/**
	* @brief Constructor
	* @param none
	* @exception none
	* @return none
	*/
	ResourceControl();

	/**
	* @brief Destructor
	* @param none
	* @exception none
	* @return none
	*/
	~ResourceControl();

	/**
	* @brief Load resource XML document
	* @param none
	* @exception none
	* @return none
	*/
	static void loadResource();

	/**
	* @brief Image path getter
	* @param p_pName image name QString
	* @exception none
	* @return image path QString
	*/
	static QString getImage(QString p_pName);

	/**
	* @brief Sound path getter
	* @param p_pName sound name QString
	* @exception none
	* @return sound path QString
	*/
	static QString getSound(QString p_pName);

	/**
	* @brief Text getter
	* @param p_pName text name QString
	* @exception none
	* @return text QString
	*/
	static QString getText(QString p_pName);
};

#endif