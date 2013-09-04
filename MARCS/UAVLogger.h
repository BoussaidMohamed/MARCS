#ifndef __LOGGER
#define __LOGGER

#include <QFile>
#include <QTextStream>
#include <QMutex>

class UAVLogger : public QObject
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
	QTextStream* sysLog;	//System logger
	QTextStream* pollLog;	//Data logger
	QFile* dataFile;		//System log file
	QFile* sysFile;			//Data log file

public :
	//============= Methods ==================

	/**
	* @brief Constructor
	* @param none
	* @exception none
	* @return UAVLogger instance
	*/
	UAVLogger();

	/**
	* @brief Destructor
	* @param none
	* @exception none
	* @return none
	*/
	~UAVLogger();

	/**
	* @brief System logger getter
	* @param none
	* @exception none
	* @return System logger pointer QTextStream*
	*/
	QTextStream* getSystemLoggerStream();

	/**
	* @brief Data logger getter
	* @param none
	* @exception none
	* @return CCardDetection QTextStream*
	*/
	QTextStream* getDataLoggerStream();
};

#endif;
