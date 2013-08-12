#include "LatLongCoord.h"

LatLongCoord::LatLongCoord()
{
	m_dLatitude = std::numeric_limits<double>::infinity();
	m_dLongitude = std::numeric_limits<double>::infinity();
}

LatLongCoord::LatLongCoord(LatLongCoord* p_pCoordinates)
{
	m_dLatitude = p_pCoordinates->m_dLatitude;
	m_dLongitude = p_pCoordinates->m_dLongitude;
}

LatLongCoord::LatLongCoord(double p_dLatitude, double p_dLongitude)
{
	m_dLatitude = p_dLatitude;
	m_dLongitude = p_dLongitude;
}

void LatLongCoord::setCoordinates(double p_dLatitude, double p_dLongitude)
{
	m_dLatitude = p_dLatitude;
	m_dLongitude = p_dLongitude;
}

double LatLongCoord::getLatitude()
{
	return m_dLatitude;
}

double LatLongCoord::getLongitude()
{
	return m_dLongitude;
}

double LatLongCoord::getDistance(LatLongCoord* p_pCoordinates)
{
	int raver = 6378137;

	double longRad = p_pCoordinates->getLongitude() * M_PI / 180.;
	double latRad = p_pCoordinates->getLatitude() * M_PI / 180.;
	double destLatRad = m_dLatitude * M_PI / 180.;
	double destLongRad = m_dLongitude * M_PI / 180.;

	return raver * qAcos((qCos(latRad) * qCos(destLatRad) * qCos(longRad - destLongRad)) + (qSin(latRad) * qSin(destLatRad)));
}

bool LatLongCoord::operator == (const LatLongCoord& p_pLatLong)
{
	bool bLatitude = this->m_dLatitude == p_pLatLong.m_dLatitude;
	bool bLongitude = this->m_dLongitude == p_pLatLong.m_dLongitude;

	return bLatitude && bLongitude;
}