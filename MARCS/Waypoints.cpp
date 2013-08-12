#include "Waypoint.h"

Waypoint::Waypoint()
{
	m_iNumber = 0;
	m_pCoordinates = new LatLongCoord();
	m_dAltitude = 0.;
	m_pAction = new Action();
}

Waypoint::Waypoint(int p_iNumber)
{
	m_iNumber = p_iNumber;
	m_pCoordinates = new LatLongCoord();
	m_dAltitude = 0.;
	m_pAction = new Action();
}

Waypoint::Waypoint(Waypoint* p_pWaypoint):m_dAltitude(p_pWaypoint->m_dAltitude), m_iNumber(p_pWaypoint->m_iNumber)
{
	m_pCoordinates = new LatLongCoord(p_pWaypoint->m_pCoordinates);
	m_pAction = new Action(p_pWaypoint->m_pAction);
}

Waypoint::Waypoint(LatLongCoord* p_pCoordinates, double p_dAltitude)
{
	m_iNumber = 0;
	m_pCoordinates = p_pCoordinates;
	m_dAltitude = p_dAltitude;
	m_pAction = new Action();
}

Waypoint::~Waypoint()
{
	delete m_pCoordinates;
	delete m_pAction;
}

void Waypoint::setCoordinates(LatLongCoord* p_pCoordinates, double p_dAltitude)
{
	m_pCoordinates = p_pCoordinates;
	m_dAltitude = p_dAltitude;
}

void Waypoint::setAltitude(double p_dAltitude)
{
	m_dAltitude = p_dAltitude;
}

void Waypoint::setAction(Action* p_pAction)
{
	m_pAction = p_pAction;
}

void Waypoint::setAction(QString p_pAction)
{
	m_pAction->setType(p_pAction);
}

void Waypoint::setNumber(int p_iNumber)
{
	m_iNumber = p_iNumber;
}

LatLongCoord* Waypoint::getCoordinates()
{
	return m_pCoordinates;
}

double Waypoint::getAltitude()
{
	return m_dAltitude;
}

Action* Waypoint::getAction()
{
	return m_pAction;
}

double Waypoint::getDistance(Waypoint* p_pWaypoint)
{
	return m_pCoordinates->getDistance(p_pWaypoint->m_pCoordinates);
}

int Waypoint::getNumber()
{
	return m_iNumber;
}

QDomElement Waypoint::toXML(QDomDocument p_pDocument)
{
	QDomElement pWaypoint = p_pDocument.createElement("waypoint");

	QDomElement pLocation = p_pDocument.createElement("location");
	pLocation.setAttribute("longitude", m_pCoordinates->getLongitude());
	pLocation.setAttribute("latitude", m_pCoordinates->getLatitude());
	pLocation.setAttribute("altitude", m_dAltitude);
	
	QDomElement pAction = p_pDocument.createElement("action");
	pAction.setAttribute("name", m_pAction->getTypeString());

	pWaypoint.appendChild(pLocation);
	pWaypoint.appendChild(pAction);

	return pWaypoint;
}

bool Waypoint::operator == (const Waypoint& p_pWaypoint)
{
	bool bCoordinates = *this->m_pCoordinates == *p_pWaypoint.m_pCoordinates;
	bool bAltitude = this->m_dAltitude == p_pWaypoint.m_dAltitude;
	bool bAction = *this->m_pAction == *p_pWaypoint.m_pAction;

	return bCoordinates && bAltitude && bAction;
}