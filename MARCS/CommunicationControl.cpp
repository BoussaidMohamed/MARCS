#include "CommunicationControl.h"

CommunicationControl* CommunicationControl::singleton = NULL;

CommunicationControl::CommunicationControl()
{
	comThread = new ComThread();

	connect(this, SIGNAL(sendLaunch()), comThread, SLOT(sendLaunch()));
	connect(this, SIGNAL(sendLand()), comThread, SLOT(sendLand()));
	connect(this, SIGNAL(sendHome()), comThread, SLOT(sendHome()));
	connect(this, SIGNAL(sendMotOn()), comThread, SLOT(sendMotOn()));
	connect(this, SIGNAL(sendMotOff()), comThread, SLOT(sendMotOff()));

	connect(this, SIGNAL(poll(unsigned short)), comThread, SLOT(poll(unsigned short)));
	connect(comThread, SIGNAL(dataReceived(char*, int)), this, SLOT(computePolledData(char*, int)));
	connect(comThread, SIGNAL(XBeeDisconnected()), this, SIGNAL(XBeeDisconnected()));
	connect(comThread, SIGNAL(XBeeReconnected()), this, SIGNAL(XBeeReconnected()));

	connect(&m_pPollTimer, SIGNAL(timeout()), this, SLOT(pollData()));
	connect(&m_pPollTimeout, SIGNAL(timeout()), this, SLOT(pollDataTimedOut()));
	
	connect(comThread, SIGNAL(XBeeDisconnected()), &m_pRetryTimer, SLOT(start()));
	connect(&m_pRetryTimer, SIGNAL(timeout()), this, SLOT(retryConnection()));
	connect(comThread, SIGNAL(XBeeReconnected()), &m_pRetryTimer, SLOT(stop()));

	connect(this, SIGNAL(sendMove(double, double, double, double)), 
		comThread, SLOT(sendMove(double, double, double, double)));
    connect(this, SIGNAL(sendWaypoint(double, double, double, double)),
        comThread, SLOT(sendWaypoint(double, double, double, double)));


   longitude = 0;
	latitude = 0;
	altitude = 0;
	m_nLinkTries = 0;

	createLog();
	comThread->start();
	m_pRetryTimer.setInterval(300);
}

void CommunicationControl::kill()
{
	if (singleton != NULL)
	{
		delete singleton;
		singleton = NULL;
	}
}

CommunicationControl::~CommunicationControl()
{
	delete log;
}

void CommunicationControl::start(QString p_sCom)
{
	m_sCom = p_sCom;
	comThread->createCom(p_sCom);
    m_pPollTimer.start(200);
}

void CommunicationControl::stop()
{
	comThread->releaseCom();
	m_pPollTimer.stop();
}

CommunicationControl* CommunicationControl::getInstance()
{
	if (singleton == NULL)
	{
		singleton = new CommunicationControl();
	}

	return singleton;
}

void CommunicationControl::controlWaypoint(double xDest, double yDest, double zDest)
{
	int raver = 6378137;

	qreal xRad = xDest * M_PI / 180.;
	qreal yRad = yDest * M_PI / 180.;
	qreal latRad = latitude * M_PI / 180.;
	qreal longRad = longitude * M_PI / 180.;

	qreal dist = raver * qAcos((qCos(yRad) * qCos(latRad) * qCos(xRad - longRad)) + (qSin(yRad) * qSin(latRad)));

	bool validDistance = dist <= DISTMAX;
	bool validAltitude = (zDest > altitude) && (zDest <= altitude + ALTMAX);

	emit validWaypoint(dist, validDistance, validAltitude);
}

unsigned short CommunicationControl::crc_update(unsigned short crc, unsigned char data)
{
	data ^= (crc & 0xff);
	data ^= data << 4;
	return ((((unsigned short) data << 8) | ((crc >> 8) & 0xff)) ^ (unsigned char) (data >> 4) ^ ((unsigned short) data << 3));
}

unsigned short CommunicationControl::crc16(void *data, unsigned short cnt)
{
	unsigned short crc = 0xff;
	unsigned char *ptr = (unsigned char *)data;
	int i;

	for (i = 0; i < cnt; i++)
	{
		crc = crc_update(crc, *ptr);
		ptr++;
	}
	return crc;
}

void CommunicationControl::computePolledData(char* data, int length)
{
	unsigned char descriptor = 0;
	unsigned short sendCrc = 0;
	unsigned short checksum = 0;
	int index = 0;
	char ack[6];

	m_pPollTimeout.stop();
	m_nLinkTries = 0;
	emit XBeeStatus(true);

	*(log->getSystemLoggerStream()) << endl << "Compute polled data" << endl;

	while (index < length)
	{
		*(log->getSystemLoggerStream()) << "    End of buffer not reached : number of resting char = " << length - index << endl;

		while (!(data[index] == '>'))
		{
			index++;
		}

		if ((data[index + 1] == 'a' && data[index + 3] == 'a' && data[index + 4] == '<') && index < length)
		{
			if (index <= 395)
			{
				*(log->getSystemLoggerStream()) << "Command acknowledge received" << endl;
				memcpy((void*)ack, (void*)&data[index], 5 * sizeof(char));
				ack[5] = '\0';
			}

			emit displayAck(ack);
		}
		else if ((data[index + 1] == '*' && data[index + 2] == '>') && index < length - sizeof(">*>") - 1 - sizeof(short))
		{
			*(log->getSystemLoggerStream()) << "    New polled data structure found at index " << index << endl;

			descriptor = data[index + sizeof(">*>") - 1 + sizeof(short)];
			index += sizeof(">*>") - 1 + sizeof(short) + sizeof(char);

			if (descriptor == STATUS_DESCRIPTOR)
			{
				*(log->getSystemLoggerStream()) << "        Status polled data found in buffer" << endl;

				if (index < (length - sizeof(LL_STATUS) - sizeof(short) + sizeof("<#<") - 1))
				{
					memcpy((void*)&st, &data[index], sizeof(LL_STATUS));

					index += sizeof(LL_STATUS);
					memcpy((void*)&sendCrc, &data[index], sizeof(short));

					checksum = crc16(&st, sizeof(LL_STATUS));

					emit batteryLevel(st.battery_voltage_1 / 1000.);
					emit updateStatus(st.flightMode);
					
					emit inFlight(st.flying);
				}
				else
				{
					*(log->getSystemLoggerStream()) << "        ERROR : Incomplete structure" << endl;
				}
			}
			else if (descriptor == IMU_CALCDATA_DESCRIPTOR)
			{
				*(log->getSystemLoggerStream()) << "        IMU polled data found in buffer" << endl;

				if (index < (length - sizeof(IMU_CALCDATA) - sizeof(short) + sizeof("<#<") - 1))
				{
					memcpy((void*)&imu, &data[index], sizeof(IMU_CALCDATA));

					index += sizeof(IMU_CALCDATA);
					memcpy((void*)&sendCrc, &data[index], sizeof(short));

					checksum = crc16(&imu, sizeof(IMU_CALCDATA));
					heading = imu.mag_heading / 1000.;
					height = imu.height / 1000.;

					emit updateHeading(heading);
					emit updateHeight(height);
				}
				else
				{
					*(log->getSystemLoggerStream()) << "        ERROR : Incomplete structure" << endl;
				}
			}
			else if (descriptor == CURRENT_WAY_DESCRIPTOR)
			{
				*(log->getSystemLoggerStream()) << "        Current way polled data found in buffer" << endl;

				if (index < (length - sizeof(CURRENT_WAY) - sizeof(short) + sizeof("<#<") - 1))
				{
					memcpy((void*)&cw, &data[index], sizeof(CURRENT_WAY));

					index += sizeof(CURRENT_WAY);
					memcpy((void*)&sendCrc, &data[index], sizeof(short));

					checksum = crc16(&cw, sizeof(CURRENT_WAY));

					emit waypointNAVInfo(cw.current_wp, cw.distance_to_wp / 10., cw.navigation_status);
				}
				else
				{
					*(log->getSystemLoggerStream()) << "        ERROR : Incomplete structure" << endl;
				}
			}
			else if (descriptor == GPS_DESCRIPTOR && index < (length - sizeof(GPS_DATA_ADVANCED) - sizeof(short) + sizeof("<#<") - 1))
			{
				*(log->getSystemLoggerStream()) << "        Geolocation polled data found in buffer" << endl;

				if (index < (length - sizeof(GPS_DATA_ADVANCED) - sizeof(short) + sizeof("<#<") - 1))
				{
					memcpy((void*)&gps, &data[index], sizeof(GPS_DATA_ADVANCED));

					index += sizeof(GPS_DATA_ADVANCED);
					memcpy((void*)&sendCrc, &data[index], sizeof(short));

					checksum = crc16(&gps, sizeof(GPS_DATA_ADVANCED));

					longitude = gps.longitude / 10000000.;
					latitude = gps.latitude / 10000000.;
					altitude = gps.height / 1000.;
					double speedX = qAbs(gps.speed_x * 0.0036);
					double speedY = qAbs(gps.speed_y * 0.0036);
					m_dSpeed = qSqrt(speedX * speedX + speedY * speedY);

					if (checksum == sendCrc)
					{
						emit geolocation(latitude, longitude, altitude, heading);
						emit updateSpeed(m_dSpeed);
						emit updateGPSQuality(gps.numSV);
					}
				}
				else
				{
					*(log->getSystemLoggerStream()) << "        ERROR : Incomplete structure" << endl;
				}

				writeLog(checksum == sendCrc);
			}
			else if (descriptor == RC_DATA_DESCRIPTOR && index < (length - sizeof(RC_DATA) - sizeof(short) + sizeof("<#<") - 1))
			{
				*(log->getSystemLoggerStream()) << "        RC polled data found in buffer" << endl;

				if (index < (length - sizeof(RC_DATA) - sizeof(short) + sizeof("<#<") - 1))
				{
					memcpy((void*)&rc, &data[index], sizeof(RC_DATA));

					index += sizeof(RC_DATA);
					memcpy((void*)&sendCrc, &data[index], sizeof(short));

					checksum = crc16(&rc, sizeof(RC_DATA));

					emit rcData(rc.channels_out[3], rc.channels_out[0], rc.channels_out[1], 
							rc.channels_out[2], rc.channels_out[4], rc.channels_out[5], rc.lock);
				}
				else
				{
					*(log->getSystemLoggerStream()) << "        ERROR : Incomplete structure" << endl;
				}
			}
			else
			{
				*(log->getSystemLoggerStream()) << "        Unknown polled data type found in buffer" << endl;
			}
		}
		index += sizeof(short) + sizeof("<#<") - 1;
	}

	*(log->getSystemLoggerStream()) << "Polled data sent" << endl;
}

void CommunicationControl::createLog()
{
	log = new UAVLogger();

	*(log->getDataLoggerStream()) << "Date" << "; " << "Latitude (°)" << "; " << "Longitude (°)" 
		<< "; " << "Altitude (from ground, in m)" << "; " << "Heading (°)" << "; " 
		<< "Speed (km/h)" << "; " << "Valid crc" << endl;
}

void CommunicationControl::writeLog(bool validCrc)
{
	*(log->getDataLoggerStream()) << QDateTime::currentDateTime().toString() << "; " <<
		latitude << "; " << longitude << "; " << altitude << "; " << heading << "; " << 
		m_dSpeed << "; " << validCrc << endl;
}


UAVLogger* CommunicationControl::getLogger()
{
	return log;
}


void CommunicationControl::pollData()
{
	emit poll(CURRENT_WAY_PACKET | GPS_PACKET | STATUS_PACKET | IMU_CALCDATA_PACKET | RC_DATA_PACKET);
	m_pPollTimeout.start(150);
}

void CommunicationControl::autonomousMode()
{
	connect(this, SIGNAL(sendWaypoint(double, double, double, double)), 
		comThread, SLOT(sendWaypoint(double, double, double, double)));

	connect(this, SIGNAL(sendGoTo()), comThread, SLOT(sendGoTo()));
}

void CommunicationControl::computerAidedControlMode()
{
	disconnect(this, SIGNAL(sendWaypoint(double, double, double, double)), 
		comThread, SLOT(sendWaypoint(double, double, double, double)));

	disconnect(this, SIGNAL(sendGoTo()), comThread, SLOT(sendGoTo()));
}

void CommunicationControl::pollDataTimedOut()
{
	m_nLinkTries ++;

	if (m_nLinkTries > NB_TRIES)
	{
		m_pPollTimeout.stop();
		comThread->clearCounters();
		emit XBeeStatus(false);
	}
}

void CommunicationControl::retryConnection()
{
	stop();
	start(m_sCom);
}
