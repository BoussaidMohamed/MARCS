#include "ComThread.h"
#include "QDebug"
#include "qdebug.h"

using namespace std;

ComThread::ComThread()
{
	handle = NULL;

	dcb.DCBlength = sizeof(DCB);
	dcb.BaudRate = CBR_57600;   /*  vitesse */
        dcb.fBinary = true;
	dcb.fParity = false;
	dcb.fOutxCtsFlow = false;
	dcb.fOutxDsrFlow = false;
	dcb.fDtrControl = DTR_CONTROL_ENABLE;
	dcb.fDsrSensitivity = false;
	dcb.fTXContinueOnXoff = false;
	dcb.fOutX = false;
	dcb.fInX = false;
	dcb.fErrorChar = false;
	dcb.fNull = false;
	dcb.fRtsControl = RTS_CONTROL_ENABLE;
	dcb.fAbortOnError = false;
	dcb.fDummy2 = 0;
	dcb.wReserved = 0;
	dcb.XonLim = 0x100;
	dcb.XoffLim = 0x100;
	dcb.ByteSize = 8 ; /* nombre de bits */
	dcb.Parity = NOPARITY;
	dcb.StopBits = ONESTOPBIT;
	dcb.XonChar = 0x11;
	dcb.XoffChar = 0x13;
	dcb.ErrorChar = '?';
	dcb.EofChar = 0x1a;
	dcb.EvtChar = 0x10;

	failed = false;
	failNoticed = false;
}

ComThread::~ComThread()
{
}

void ComThread::createCom(QString p_sCom)
{


    handle = CreateFile((LPCWSTR)p_sCom.constData(), GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_SYSTEM, NULL);

	if (handle == INVALID_HANDLE_VALUE)
	{
		handle = NULL;
	}
	else if (failed)
	{
		emit XBeeReconnected();
		failNoticed = false;
		failed = false;
	}

	COMMTIMEOUTS g_cto =
	{
		READ_INTERVAL,		/* ReadIntervalTimeOut          */
		READ_MULTIPLIER,	/* ReadTotalTimeOutMultiplier   */
		MAX_WAIT_READ,		/* ReadTotalTimeOutConstant     */
		0,					/* WriteTotalTimeOutMultiplier  */
		0					/* WriteTotalTimeOutConstant    */
	};

	SetupComm(handle, RX_SIZE, TX_SIZE);

	if(!SetCommTimeouts(handle, &g_cto) || !SetCommState(handle, &dcb))
	{
		CloseHandle(handle);
		handle = NULL;
	}

	PurgeComm(handle, PURGE_TXCLEAR|PURGE_RXCLEAR|PURGE_TXABORT|PURGE_RXABORT);
	EscapeCommFunction(handle, SETDTR);

}

void ComThread::releaseCom()
{
	CloseHandle(handle);
	handle = NULL;
}

void ComThread::run()
{
	DWORD nbReceived = 0;
	DWORD nbWritten = 0;
	sizeWrite = 0;
	sizeRead = 0;

	while (1)
	{
		if (handle != NULL)
		{
			if (mustWrite == true)
			{
				if (WriteFile(handle, command, sizeWrite, &nbWritten, NULL) == true)
				{
                                        mustWrite = false;
				}
				else
				{
                                        failed = true;
				}
			}

			if (mustPoll == true)
			{
				if (WriteFile(handle, dataToPoll, sizePoll, &nbWritten, NULL) == true)
				{
                                        mustPoll = false;
				}
				else
				{
                                        failed = true;
				}
			}

			if (mustRead == true)
			{
				if (ReadFile(handle, buffer, sizeRead, &nbReceived, NULL) == true)
				{
					PurgeComm(handle, PURGE_RXCLEAR);
					sizeRead = 0;
                                        mustRead = false;
				}
				else
				{
                                        failed = true;
				}
			}

			if (nbReceived >= sizeRead && nbReceived != 0)
			{
				emit dataReceived(buffer, nbReceived);
                                nbReceived = 0;
			}

			if (failed && !failNoticed)
			{
				emit XBeeDisconnected();
                                failNoticed = true;
			}
		}
        QThread::msleep(10);
	}
}

void ComThread::sendHome()
{
	memcpy((void*)command, ">*>wh", sizeof(">*>wh") - 1);
	sizeWrite = sizeof(">*>wh") - 1;
	mustWrite = true;

	mustRead = true;
    sizeRead += 5;
}

void ComThread::sendLand()
{
	memcpy((void*)command, ">*>we", sizeof(">*>we") - 1);
	sizeWrite = sizeof(">*>we") - 1;
	mustWrite = true;

	mustRead = true;
	sizeRead += 5;
}

void ComThread::sendLaunch()
{
	memcpy((void*)command, ">*>wl", sizeof(">*>wl") - 1);
	sizeWrite = sizeof(">*>wl") - 1;
	mustWrite = true;

	mustRead = true;
    sizeRead += 5;
}

void ComThread::sendGoTo()
{
	memcpy((void*)command, ">*>wg", sizeof(">*>wg") - 1);
	sizeWrite = sizeof(">*>wg") - 1;
	mustWrite = true;

	mustRead = true;
    sizeRead += 5;
}

void ComThread::sendWaypoint(double x, double y, double z, double number)
{
	wp.wp_number = number;
	wp.pos_acc = 10000;
	wp.time = 0;
	wp.max_speed = 100;
	wp.properties = WPPROP_ABSCOORDS | WPPROP_HEIGHTENABLED | WPPROP_YAWENABLED;
	wp.X = x * 10000000;
	wp.Y = y * 10000000;
	wp.height = z * 1000;
	wp.yaw = 0;
	wp.chksum = 0xAAAA + wp.yaw + wp.height + wp.time + wp.X + wp.Y + wp.max_speed + wp.pos_acc + wp.properties + wp.wp_number;

	memcpy((void*)command, ">*>ws", sizeof(">*>ws") - 1);
	memcpy((void*)&command[sizeWrite], &wp, sizeof(WAYPOINT));
	sizeWrite = sizeof(">*>ws") - 1;
	sizeWrite += sizeof(WAYPOINT);
	mustWrite = true;

	mustRead = true;
	sizeRead += 5;
    qDebug()<<"send it ";
}

void ComThread::sendMove(double x, double y, double z, double yaw)
{
	wp.wp_number = 1;
	wp.pos_acc = 10000;
	wp.time = 0;
	wp.max_speed = 100;
	wp.properties = WPPROP_HEIGHTENABLED | WPPROP_YAWENABLED | WPPROP_AUTOMATICGOTO;
	wp.X = x * 1000;
	wp.Y = y * 1000;
	wp.height = z * 1000;
	wp.yaw = yaw * 1000;
	wp.chksum = 0xAAAA + wp.yaw + wp.height + wp.time + wp.X + wp.Y + wp.max_speed + wp.pos_acc + wp.properties + wp.wp_number;

	memcpy((void*)command, ">*>ws", sizeof(">*>ws") - 1);
	memcpy((void*)&command[sizeWrite], &wp, sizeof(WAYPOINT));
	sizeWrite = sizeof(">*>ws") - 1;
	sizeWrite += sizeof(WAYPOINT);
	mustWrite = true;

	mustRead = true;
	sizeRead += 5;
}

void ComThread::sendMotOn()
{
	unsigned char value = 1;
	memcpy((void*)command, ">*>m", 4);
	memcpy((void*)&command[4], &value, 1);
	sizeWrite = 5;
        mustWrite = true;
   }

void ComThread::sendMotOff()
{
	unsigned char value = 0;

	memcpy((void*)command, ">*>m", 4);
	memcpy((void*)&command[4], &value, 1);
	sizeWrite = 5;
        mustWrite = true;

}

void ComThread::poll(unsigned short pDataToPoll)
{
	memcpy((void*)dataToPoll, ">*>p", 4);
	memcpy((void*)&dataToPoll[4], &pDataToPoll, sizeof(short));
	sizePoll = 4 + sizeof(short);
	sizeRead = 0;
	mustPoll = true;

	mustRead = true;

	if (pDataToPoll & STATUS_PACKET)
	{
		sizeRead += sizeof(">*>") - 1 +  sizeof(short) + sizeof(char) + sizeof(LL_STATUS) + sizeof(short) + sizeof("<#<") - 1;
	}

	if (pDataToPoll & GPS_PACKET)
	{
		sizeRead += sizeof(">*>") - 1 +  sizeof(short) + sizeof(char) + sizeof(GPS_DATA_ADVANCED) + sizeof(short) + sizeof("<#<") - 1;
	}

	if (pDataToPoll & CURRENT_WAY_PACKET)
	{
		sizeRead += sizeof(">*>") - 1 +  sizeof(short) + sizeof(char) + sizeof(CURRENT_WAY) + sizeof(short) + sizeof("<#<") - 1;
	}

	if (pDataToPoll & IMU_CALCDATA_PACKET)
	{
		sizeRead += sizeof(">*>") - 1 +  sizeof(short) + sizeof(char) + sizeof(IMU_CALCDATA) + sizeof(short) + sizeof("<#<") - 1;
	}

	if (pDataToPoll & RC_DATA_PACKET)
	{
		sizeRead += sizeof(">*>") - 1 +  sizeof(short) + sizeof(char) + sizeof(RC_DATA) + sizeof(short) + sizeof("<#<") - 1;
	}
}

void ComThread::clearCounters()
{
	sizeWrite = 0;
	sizeRead = 0;
	sizePoll = 0;
}
