#include "RPA.h"

RPA* RPA::singleton = NULL;

RPA::RPA()
{
	m_pPosition = new LatLongCoord();
	m_dAltitude = 0;
	m_dHeading = 0;

	connect(LogReplayControl::getInstance(), SIGNAL(geolocation(double, double, double, double)), 
		this, SLOT(geolocation(double, double, double, double)));
	connect(LogReplayControl::getInstance(), SIGNAL(updateHeading(double)), this, SLOT(updateHeading(double)));
}

void RPA::kill()
{
	if (singleton != NULL)
	{
		delete singleton;
		singleton = NULL;
	}
}

RPA::~RPA()
{
	delete m_pPosition;
}

RPA* RPA::getInstance()
{
	if (singleton == NULL)
	{
        singleton = new RPA();
	}

	return singleton;
}

void RPA::setCoordinates(LatLongCoord* p_pPosition)
{
	m_pPosition->setCoordinates(p_pPosition->getLatitude(), p_pPosition->getLongitude());
	emit positionChanged();
}

void RPA::setAltitude(double p_dAltitude)
{
	m_dAltitude = p_dAltitude;
}

void RPA::setHeading(double p_dHeading)
{
	if(p_dHeading > 360)
	{
		m_dHeading = p_dHeading - 360;
	}
	else if (p_dHeading < 0)
	{
		m_dHeading = 360 + p_dHeading;
	}
	else
	{
		m_dHeading = p_dHeading;
	}
}

void RPA::setHeight(double p_dHeight)
{
	m_dHeight = p_dHeight;
}

LatLongCoord* RPA::getCoordinates()
{
	return m_pPosition;
}

double RPA::getAltitude()
{
	return m_dAltitude;
}

double RPA::getHeading()
{
	return m_dHeading;
}

double RPA::getHeight()
{
	return m_dHeight;
}

void RPA::geolocation(double p_fLatitude, double p_fLongitude, double p_fAltitude, double p_fHeading)
{
	setAltitude(p_fAltitude);
	setCoordinates(new LatLongCoord(p_fLatitude, p_fLongitude));

	emit positionChanged();
}

void RPA::updateHeading(double p_pValue)
{
	setHeading(p_pValue);
}

void RPA::updateHeight(double p_pValue)
{
	setHeight(p_pValue);
}

