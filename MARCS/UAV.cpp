#include "UAV.h"

UAV* UAV::singleton = NULL;

UAV::UAV()
{
	m_pPosition = new LatLongCoord();
	m_dAltitude = 0;
	m_dHeading = 0;

	connect(LogReplayControl::getInstance(), SIGNAL(geolocation(double, double, double, double)), 
		this, SLOT(geolocation(double, double, double, double)));
	connect(LogReplayControl::getInstance(), SIGNAL(updateHeading(double)), this, SLOT(updateHeading(double)));
}

void UAV::kill()
{
	if (singleton != NULL)
	{
		delete singleton;
		singleton = NULL;
	}
}

UAV::~UAV()
{
	delete m_pPosition;
}

UAV* UAV::getInstance()
{
	if (singleton == NULL)
	{
		singleton = new UAV();
	}

	return singleton;
}

void UAV::setCoordinates(LatLongCoord* p_pPosition)
{
	m_pPosition->setCoordinates(p_pPosition->getLatitude(), p_pPosition->getLongitude());
	emit positionChanged();
}

void UAV::setAltitude(double p_dAltitude)
{
	m_dAltitude = p_dAltitude;
}

void UAV::setHeading(double p_dHeading)
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

void UAV::setHeight(double p_dHeight)
{
	m_dHeight = p_dHeight;
}

LatLongCoord* UAV::getCoordinates()
{
	return m_pPosition;
}

double UAV::getAltitude()
{
	return m_dAltitude;
}

double UAV::getHeading()
{
	return m_dHeading;
}

double UAV::getHeight()
{
	return m_dHeight;
}

void UAV::geolocation(double p_fLatitude, double p_fLongitude, double p_fAltitude, double p_fHeading)
{
	setAltitude(p_fAltitude);
	setCoordinates(new LatLongCoord(p_fLatitude, p_fLongitude));

	emit positionChanged();
}

void UAV::updateHeading(double p_pValue)
{
	setHeading(p_pValue);
}

void UAV::updateHeight(double p_pValue)
{
	setHeight(p_pValue);
}

