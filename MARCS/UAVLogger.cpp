#include "UAVLogger.h"
#include "QDir"

UAVLogger::UAVLogger()
{
    sysFile = new QFile(QDir::currentPath()+"/Logs/system.log");
    dataFile = new QFile(QDir::currentPath()+"/Logs/data_RPA.csv");

	sysFile->open(QIODevice::WriteOnly | QIODevice::Text);
	dataFile->open(QIODevice::WriteOnly | QIODevice::Text);

	sysLog = new QTextStream(sysFile);
	pollLog = new QTextStream(dataFile);


}

UAVLogger::~UAVLogger()
{
	sysFile->close();
	dataFile->close();

	delete sysLog;
	delete pollLog;
	delete dataFile;
	delete sysFile;
}

QTextStream* UAVLogger::getSystemLoggerStream()
{
	return sysLog;
}

QTextStream* UAVLogger::getDataLoggerStream()
{
	return pollLog;
}
