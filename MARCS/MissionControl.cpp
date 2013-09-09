#include "MissionControl.h"

MissionControl* MissionControl::singleton = NULL;

MissionControl::MissionControl()
{
        //m_pPlan = new FlightPlan();
        //m_pMap = new Map();
        //m_pMap->setFlightPlan(m_pPlan);

	m_pLaunchTimer.setInterval(1000);

	connect(CommunicationControl::getInstance(), SIGNAL(XBeeStatus(bool)), this, SLOT(updateXBee(bool)));
	connect(PeripheralController::getInstance(), SIGNAL(directInputProblem()), this, SIGNAL(directXProblem()));
	connect(PeripheralController::getInstance(), SIGNAL(dataFormatProblem()), this, SIGNAL(directXProblem()));
	connect(PeripheralController::getInstance(), SIGNAL(deviceEnumProblem()), this, SIGNAL(directXProblem()));
	connect(PeripheralController::getInstance(), SIGNAL(joystickProblem()), this, SIGNAL(controllerProblem()));
	connect(PeripheralController::getInstance(), SIGNAL(noJoystick()), this, SIGNAL(controllerProblem()));
	connect(PeripheralController::getInstance(), SIGNAL(controllerConnected()), this, SIGNAL(controllerConnected()));

	connect(CommunicationControl::getInstance(), SIGNAL(geolocation(double, double, double, double)), 
        RPA::getInstance(), SLOT(geolocation(double, double, double, double)));
    connect(CommunicationControl::getInstance(), SIGNAL(updateHeading(double)), RPA::getInstance(), SLOT(updateHeading(double)));
    connect(CommunicationControl::getInstance(), SIGNAL(updateHeight(double)), RPA::getInstance(), SLOT(updateHeight(double)));
	connect(CommunicationControl::getInstance(), SIGNAL(updateGPSQuality(int)), this, SLOT(updateGPS(int)));
	connect(CommunicationControl::getInstance(), SIGNAL(batteryLevel(double)), this, SLOT(updateBattery(double)));
	connect(CommunicationControl::getInstance(), SIGNAL(updateStatus(short)), this, SLOT(updateRadiocommand(short)));
	connect(CommunicationControl::getInstance(), SIGNAL(inFlight(char)), this, SLOT(inFlight(char)));
	connect(CommunicationControl::getInstance(), SIGNAL(waypointNAVInfo(char, short, short)), 
		this, SLOT(updateNAV(char, short, short)));
	connect(CommunicationControl::getInstance(), SIGNAL(rcData(short, short, short, short, short, short, char)), 
		this, SLOT(rcData(short, short, short, short, short, short, char)));

    connect(RPA::getInstance(), SIGNAL(positionChanged()), this, SLOT(updateDigression()));
	connect(&m_pWaypointTimer, SIGNAL(timeout()), this, SLOT(sendWaypoint()));
	connect(&m_pLaunchTimer, SIGNAL(timeout()), this, SIGNAL(sendLaunch()));

	connect(CommunicationControl::getInstance(), SIGNAL(displayAck(char*)), this, SLOT(acknowledge(char*)));
	connect(this, SIGNAL(sendLaunch()), CommunicationControl::getInstance(), SIGNAL(sendLaunch()));
	connect(this, SIGNAL(move(double, double, double, double)), CommunicationControl::getInstance(), 
		SIGNAL(sendMove(double, double, double, double)));

	m_bFirstWaypoint = true;
	m_bNextSent = false;
	m_bFPLaunched = false;
	m_bFirstRC = true;
}

void MissionControl::kill()
{
	if (singleton != NULL)
	{
		delete singleton;
		singleton = NULL;
	}
}

MissionControl::~MissionControl()
{
}

MissionControl* MissionControl::getInstance()
{
	if (singleton == NULL)
	{
		singleton = new MissionControl();
	}

	return singleton;
}





void MissionControl::updateBattery(double p_pValue)
{
	emit batteryLevel(p_pValue);
	m_dBattery = p_pValue;
}

void MissionControl::updateGPS(int p_pValue)
{
	emit GPSLevel(p_pValue);
	m_nGPS = p_pValue;
}

void MissionControl::updateDigression()
{
    LatLongCoord* p_pPosition = RPA::getInstance()->getCoordinates();

        //if (m_pPlan->getNextWaypointIndex() < m_pPlan->getWaypointList().size() && m_pPlan->getNextWaypointIndex() > 0)
	{
                //Waypoint* pFirstWaypoint = m_pPlan->getWaypointList()[m_pPlan->getNextWaypointIndex() - 1];
                //Waypoint* pSecondWaypoint = m_pPlan->getWaypointList()[m_pPlan->getNextWaypointIndex()];

                //if (pFirstWaypoint != NULL && pSecondWaypoint != NULL)
                    if (true)
		{
                        //LatLongCoord* p_pFirstWaypointPosition = pFirstWaypoint->getCoordinates();
                        //LatLongCoord* p_pSecondWaypointPosition = pSecondWaypoint->getCoordinates();
                        //emit digression(m_pMap->distanceFromLeg(p_pPosition, p_pFirstWaypointPosition, p_pSecondWaypointPosition));
		}
	}
}

void MissionControl::updateXBee(bool p_pValue)
{
	emit XBeeConnection(p_pValue);
	m_bXBee = p_pValue;
}

void MissionControl::updateRadiocommand(short p_pValue)
{
	emit radiocommandConnection(!(p_pValue & EMERGENCY));
	m_nStatus = p_pValue;
}

void MissionControl::sendWaypoint()
{
        //if (m_pPlan->getWaypointList().size() > 0)
	{
                //Waypoint* pWaypoint = m_pPlan->getWaypointList()[m_pPlan->getNextWaypointIndex()];
                //LatLongCoord pCoordinates = pWaypoint->getCoordinates();

                //emit waypoint(pCoordinates.getLongitude(), pCoordinates.getLatitude(), pWaypoint->getAltitude(), pWaypoint->getNumber());

    }
m_pWaypointTimer.start(1000);
}

bool MissionControl::nextWaypoint()
{
	bool ret = false;
        //int index = m_pPlan->getNextWaypointIndex();

        //if (index < m_pPlan->getWaypointList().size())
        if(true)
	{
        //	m_pPlan->setNextWaypointIndex(index + 1);
		ret = true;
	}
	else
	{
		ret = false;
	}

        //m_pMap->displayWaypoints();
	emit resetWaypointNotification();

	return ret;
}

void MissionControl::updateNAV(char p_cWaypointNumber, short p_nDistance, short p_cStatus)
{
	if (m_bFPLaunched)
	{
		if (m_bFirstWaypoint == true)
		{
			sendLaunch();
			sendWaypoint();
			m_bFirstWaypoint = false;
			m_pLaunchTimer.start();
		}
		else if (p_cStatus == WP_NAVSTAT_REACHED_POS && m_bNextSent == false)
		{
			if (nextWaypoint())
			{
				sendWaypoint();
				m_bNextSent = true;
			}
			else
			{
				emit endFlightPlan();
			}
		}
		else
		{
			m_bNextSent = false;
		}
	}
}

void MissionControl::acknowledge(char* m_pAck)
{
	QString ack(m_pAck);

	if (ack == WAYPOINT_ACK)
	{
		m_pWaypointTimer.stop();
	}
	else if (ack == DEFINE_HOME_ACK)
	{
		m_pLaunchTimer.stop();
	}
}

void MissionControl::launchFlightPlan()
{
        //bool bFlightPlanDefined = m_pPlan->getWaypointList().size() != 0;

        //if (m_dBattery > batteryVeryLow && /*m_nGPS > GPSVeryLow &&*/ m_bXBee
        //	&& (m_nStatus & GPS) && bFlightPlanDefined && m_cEngine == 1)
    if (true)
    {
		m_bFPLaunched = true;
		emit flightPlanLaunched();
	}
	else
	{
                //emit cannotLaunchFP(m_dBattery > batteryVeryLow, m_nGPS > GPSVeryLow, m_bXBee,
                //	m_nStatus & GPS, bFlightPlanDefined, m_cEngine == 1);
	}
}

void MissionControl::stopFlightPlan()
{
	m_bFPLaunched = false;
        //m_pPlan->setNextWaypointIndex(0);
	m_bFirstWaypoint = true;
}

void MissionControl::pauseFlightPlan()
{
	m_bFPLaunched = false;
}

void MissionControl::updateWayStatus(char p_cWaypointNumber, short p_nDistance, short p_nNavStatus)
{
	if (p_nNavStatus == (WP_NAVSTAT_REACHED_POS_TIME | WP_NAVSTAT_REACHED_POS | WP_NAVSTAT_20M))
	{
        //	if (m_pPlan->getNextWaypointIndex() < m_pPlan->getWaypointList().size() - 1)
		{
			emit waypointReached();
		}
	}
}

void MissionControl::rcData(short p_nYaw, short p_nPitch, short p_nRoll, short p_nThrust, 
	short p_nSerial, short p_nGPSHeightControl, char p_cValid)
{
	if (p_cValid)
	{
		if (!m_bFirstRC && PeripheralController::getInstance()->isMouseMode())
		{
			if (m_pPreviousYawRC != p_nYaw || m_pPreviousPitchRC != p_nPitch
				|| m_pPreviousRollRC != p_nRoll || m_pPreviousThrustRC != p_nThrust
				|| m_pPreviousSerialRC != p_nSerial || m_pPreviousGPSHeightControlRC != p_nGPSHeightControl)
			{
				emit RCDataChanged();

				m_pPreviousYawRC = p_nYaw;
				m_pPreviousPitchRC = p_nPitch;
				m_pPreviousRollRC = p_nRoll;
				m_pPreviousThrustRC = p_nThrust;
				m_pPreviousSerialRC = p_nSerial;
				m_pPreviousGPSHeightControlRC = p_nGPSHeightControl;
			}
		}
		else
		{
			m_bFirstRC = false;
		}
	}
}

void MissionControl::inFlight(char p_cValue)
{
	m_cEngine = p_cValue;
}

void MissionControl::moveForward()
{
    emit move(10, 0, RPA::getInstance()->getAltitude(), RPA::getInstance()->getHeading());
}

void MissionControl::moveBackward()
{
    emit move(-10, 0, RPA::getInstance()->getAltitude(), RPA::getInstance()->getHeading());
}

void MissionControl::moveLeft()
{
    emit move(0, 10, RPA::getInstance()->getAltitude(), RPA::getInstance()->getHeading());
}

void MissionControl::moveRight()
{
    emit move(0, -10, RPA::getInstance()->getAltitude(), RPA::getInstance()->getHeading());
}

void MissionControl::turnLeft()
{
    emit move(0, 0, RPA::getInstance()->getAltitude(), RPA::getInstance()->getHeading() - 10);
}

void MissionControl::turnRight()
{
    emit move(0, 0, RPA::getInstance()->getAltitude(), RPA::getInstance()->getHeading() + 10);
}

void MissionControl::up()
{
    emit move(0, 0, RPA::getInstance()->getAltitude() + 10, RPA::getInstance()->getHeading());
}

void MissionControl::down()
{
    emit move(0, 0, RPA::getInstance()->getAltitude() - 10, RPA::getInstance()->getHeading());
}

void MissionControl::addMark()
{
        //Waypoint* pWaypoint = new Waypoint(RPA::getInstance()->getCoordinates(), RPA::getInstance()->getHeight());
        //pWaypoint->setNumber(MissionControl::getInstance()->getPlan()->getWaypointList().size() +
        //	MissionControl::getInstance()->getPlan()->getMarkList().size() + 1);
        //pWaypoint->setAction(new Action(GOTO));

        //MissionControl::getInstance()->getPlan()->addMark(pWaypoint);
}
