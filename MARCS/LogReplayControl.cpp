#include "LogReplayControl.h"

LogReplayControl* LogReplayControl::singleton = NULL;

LogReplayControl::LogReplayControl()
{
	/*m_pStartPause = new ToggleButton();
	m_pIncSpeed = new QPushButton();
	m_pDecSpeed = new QPushButton();
	m_pStop = new QPushButton();*/
	m_iData = 0;
	m_bReverse = false;
	connect(&m_pReplayTimer, SIGNAL(timeout()), this, SLOT(replay()));
}

void LogReplayControl::kill()
{
	if (singleton != NULL)
	{
		delete singleton;
		singleton = NULL;
	}
}

LogReplayControl::~LogReplayControl()
{
}

LogReplayControl* LogReplayControl::getInstance()
{
	if (singleton == NULL)
	{
		singleton = new LogReplayControl();
	}

	return singleton;
}

void LogReplayControl::start()
{
	m_pReplayTimer.start(200);
	CommunicationControl::getInstance()->stop();
}

void LogReplayControl::pause()
{
	m_pReplayTimer.stop();
}

void LogReplayControl::stop()
{
	m_pReplayTimer.stop();

	m_iData = 0;
	m_bReverse = false;
}

void LogReplayControl::forward()
{
	if (m_bReverse == false)
	{
		m_pReplayTimer.setInterval(m_pReplayTimer.interval() + 50);
	}
	else
	{
		m_pReplayTimer.setInterval(m_pReplayTimer.interval() - 50);

		if (m_pReplayTimer.interval() <= 0)
		{
			m_pReplayTimer.setInterval(50);
			m_bReverse = false;
		}
	}
}

void LogReplayControl::backward()
{
	if (m_bReverse == true)
	{
		m_pReplayTimer.setInterval(m_pReplayTimer.interval() + 50);
	}
	else
	{
		m_pReplayTimer.setInterval(m_pReplayTimer.interval() - 50);

		if (m_pReplayTimer.interval() <= 0)
		{
			m_pReplayTimer.setInterval(50);
			m_bReverse = true;
		}
	}
}

void LogReplayControl::replay()
{
	if (m_bReverse == false)
	{
		if (m_iData > m_aLatitude.length())
		{
			stop();
		}
		else if (m_iData < m_aLatitude.length())
		{
			emit geolocation(m_aLatitude[m_iData], m_aLongitude[m_iData], m_aAltitude[m_iData], 0);
			emit updateHeading(m_aHeading[m_iData]);

			m_iData++;
		}
		else
		{
			stop();
		}
	}
	else
	{
		if (m_iData < 0)
		{
			stop();
		}
		else if (m_iData < m_aLatitude.length())
		{
			emit geolocation(m_aLatitude[m_iData], m_aLongitude[m_iData], m_aAltitude[m_iData], 0);
			emit updateHeading(m_aHeading[m_iData]);

			m_iData--;
		}
		else
		{
			stop();
		}
	}
}

void LogReplayControl::openLog()
{
        //QString name = QFileDialog::getOpenFileName(NULL, ResourceControl::getText("selectLogTitle"),
        //	"", "Data log files (*.csv)");
    QString name = "Hola";

	if (name != "")
	{
		QString line;
		QStringList lineSplit;

		QFile file(name);

		if (file.open(QIODevice::ReadOnly))
		{
			QTextStream textStream(&file);
			line = textStream.readLine();

			while (!textStream.atEnd())
			{
				line = textStream.readLine();
				lineSplit = line.split(";");

				m_aLatitude.push_back(lineSplit.at(1).toDouble());
				m_aLongitude.push_back(lineSplit.at(2).toDouble());
				m_aAltitude.push_back(lineSplit.at(3).toDouble());
				m_aHeading.push_back(lineSplit.at(4).toDouble());
			}
		}
	}
}
