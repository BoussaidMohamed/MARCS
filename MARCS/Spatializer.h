/******************************************************
*			         MARCS 2012		                  *
*******************************************************
* @file Spatializer.h
* @author Nicolas FERRRERO
*
* @date 2012/05/03 (creation_date)
* @date 2012/07/19 (latest_modification_date)
*
* @brief Sound player and spatializer, text-to-speecher
*
* @bug
* - symptoms : none
* - causes : none
* - solutions : none
*
* @todo : none
*/

#ifndef __SPATIALIZER
#define __SPATIALIZER

#include <al.h>
#include <alc.h>
#include <sndfile.h>
#include <vector>
#include <QtCore/QString>
#include <sapi.h>

class Spatializer
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
	ALuint m_pBuffer;		//Sound buffer
	ALuint m_pSource;		//Sound source
	ISpVoice* m_pVoice;		//Text-to-speech voice
	wchar_t* m_pTextArray;	//Text-to-speech text

public:
	//============= Methods ==================

	/**
	* @brief Constructor
	* @param none
	* @exception none
	* @return Spatializer instance
	*/
	Spatializer();

	/**
	* @brief Destructor
	* @param none
	* @exception none
	* @return none
	*/
	~Spatializer();

	/**
	* @brief Initialisation of OpenAL
	* @param none
	* @exception none
	* @return Success bool
	*/
	bool initOpenAL();
	
	/**
	* @brief Initialisation of SAPI
	* @param none
	* @exception none
	* @return Success bool
	*/
	bool initSapi();

	/**
	* @brief Shutdown of OpenAL
	* @param none
	* @exception none
	* @return none
	*/
	void shutDownOpenAL();

	/**
	* @brief Shutdown of SAPI
	* @param none
	* @exception none
	* @return none
	*/
	void shutDownSapi();

	/**
	* @brief Load sound
	* @param p_pFileName name of the sound file QString
	* @exception none
	* @return Sound buffer ALuint
	*/
	ALuint loadSound(QString p_pFileName);

	/**
	* @brief Play sound
	* @param p_pBuffer sound buffer ALuint
	* @exception none
	* @return none
	*/
	void playSound(ALuint p_pBuffer);

	/**
	* @brief Play sound
	* @param none
	* @exception none
	* @return none
	*/
	void playSound();

	/**
	* @brief Transform text to speech
	* @param p_pText speech text QString
	* @exception none
	* @return none
	*/
	void textToSpeech(QString p_pText);

	/**
	* @brief Define the sound position
	* @param x double
	* @param y double
	* @param z double
	* @exception none
	* @return none
	*/
	void definePosition(double x, double y, double z);

	/**
	* @brief Define if the a sound is played
	* @param none
	* @exception none
	* @return Sound play in progress bool
	*/
	bool isPlaying();

	/**
	* @brief Stop sound play and text-to-speech
	* @param none
	* @exception none
	* @return none
	*/
	void stopPlay();
};

#endif