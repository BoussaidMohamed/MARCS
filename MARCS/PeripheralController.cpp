#include "PeripheralController.h"

PeripheralController* PeripheralController::singleton = NULL;

PeripheralController::PeripheralController()
{
	m_pJoystick = new JoystickGrabber();

	m_bMouseMode = true;
	m_bWaitRelease = false;
	m_bWaitReleaseRight = false;
	m_bWaitReleaseMode = false;

	connect(&m_pTimer, SIGNAL(timeout()), m_pJoystick, SLOT(grab()));
	connect(m_pJoystick, SIGNAL(dataComputed()), this, SLOT(useController()));
	connect(m_pJoystick, SIGNAL(dataComputed()), this, SIGNAL(controllerConnected()));
	connect(m_pJoystick, SIGNAL(noJoystick()), this, SIGNAL(noJoystick()));
	connect(m_pJoystick, SIGNAL(directInputProblem()), this, SIGNAL(directInputProblem()));
	connect(m_pJoystick, SIGNAL(dataFormatProblem()), this, SIGNAL(dataFormatProblem()));
	connect(m_pJoystick, SIGNAL(joystickProblem()), this, SIGNAL(joystickProblem()));
	connect(m_pJoystick, SIGNAL(deviceEnumProblem()), this, SIGNAL(deviceEnumProblem()));
}

PeripheralController* PeripheralController::getInstance()
{
	if (singleton == NULL)
	{
		singleton = new PeripheralController();
	}

	return singleton;
}

void PeripheralController::kill()
{
	if (singleton != NULL)
	{
		delete singleton;
		singleton = NULL;
	}
}

PeripheralController::~PeripheralController()
{
}

void PeripheralController::startControllerGrab(int p_nTime)
{
	m_pTimer.start(p_nTime);
}

void PeripheralController::useController()
{
	if (m_pJoystick->buttons[5] == true && !m_bWaitReleaseMode)
	{
		m_bWaitReleaseMode = true;
		m_bMouseMode = !m_bMouseMode;

		if (m_bMouseMode)
		{
			emit controllerMouseMode();
		}
		else
		{
			emit controllerControlMode();
		}
	}
	else if (m_pJoystick->buttons[5] == false && m_bWaitReleaseMode)
	{
		m_bWaitReleaseMode = false;
	}

	if (m_bMouseMode)
	{
		mouseMode();
	}
	else
	{
		controlMode();
	}
}

void PeripheralController::mouseMode()
{
	bool modified = false;
	int x, y;
	QPoint position = QCursor::pos();

	x = position.x();
	y = position.y();

	if (m_pJoystick->leftStickX < -0.7 || m_pJoystick->leftStickX > 0.7)
	{
		modified = true;
		x = position.x() + (int)(m_pJoystick->leftStickX * 50);
	}
	else if (m_pJoystick->leftStickX < -0.4 || m_pJoystick->leftStickX > 0.4)
	{
		modified = true;
		x = position.x() + (int)(m_pJoystick->leftStickX * 20);
	}
	else if (m_pJoystick->leftStickX < -0.2 || m_pJoystick->leftStickX > 0.2)
	{
		modified = true;
		x = position.x() + (int)(m_pJoystick->leftStickX * 10);
	}

	if (m_pJoystick->leftStickY < -0.7 || m_pJoystick->leftStickY > 0.7)
	{
		modified = true;
		y = position.y() + (int)(m_pJoystick->leftStickY * 50);
	}
	else if (m_pJoystick->leftStickY < -0.4 || m_pJoystick->leftStickY > 0.4)
	{
		modified = true;
		y = position.y() + (int)(m_pJoystick->leftStickY * 20);
	}
	else if (m_pJoystick->leftStickY < -0.2 || m_pJoystick->leftStickY > 0.2)
	{
		modified = true;
		y = position.y() + (int)(m_pJoystick->leftStickY * 10);
	}

	if (m_pJoystick->buttons[0] == true && !m_bWaitRelease)
	{ 
		emit mouseEvent(Qt::LeftButton, m_bWaitRelease);
		m_bWaitRelease = true;
	}
	else if (m_pJoystick->buttons[0] == false && m_bWaitRelease == true)
	{
		emit mouseEvent(Qt::LeftButton, m_bWaitRelease);
		m_bWaitRelease = false;
	}

	if (m_pJoystick->buttons[1] == true && !m_bWaitReleaseRight)
	{ 
		emit mouseEvent(Qt::RightButton, m_bWaitReleaseRight);
		m_bWaitReleaseRight = true;
	}
	else if (m_pJoystick->buttons[1] == false && m_bWaitReleaseRight == true)
	{
		emit mouseEvent(Qt::RightButton, m_bWaitReleaseRight);
		m_bWaitReleaseRight = false;
	}

	if (modified)
	{
		QCursor::setPos(x, y);
	}
}

void PeripheralController::controlMode()
{
	double x = 0, y = 0, z = 0, yaw = 0, height = 0;
	bool bSend = false;

	if (m_pJoystick->leftStickY < -0.5)
	{
		x = 10;
		bSend = true;
	}
	else if (m_pJoystick->leftStickY > 0.5)
	{
		x = -10;
		bSend = true;
	}

	if (m_pJoystick->leftStickX < -0.5)
	{
		y = 10;
		bSend = true;
	}
	else if (m_pJoystick->leftStickX > 0.5)
	{
		y = -10;
		bSend = true;
	}

	if (m_pJoystick->rightStickX < -0.5)
	{
		yaw = UAV::getInstance()->getHeading() - 10;
		bSend = true;

		if (yaw < 0)
		{
			yaw = UAV::getInstance()->getHeading() - 10 + 360;
		}
	}
	else if (m_pJoystick->rightStickX > 0.5)
	{	
		yaw = UAV::getInstance()->getHeading() + 10;
		bSend = true;

		if (yaw > 360)
		{
			yaw = UAV::getInstance()->getHeading() + 10 - 360;
		}
	}

	if (m_pJoystick->topTrigger < -0.5)
	{
		height = UAV::getInstance()->getHeight() + 10;
		bSend = true;
	}
	else if (m_pJoystick->topTrigger > 0.5)
	{
		height = UAV::getInstance()->getHeight() - 10;
		bSend = true;
	}

	if (bSend)
	{
		emit move(x, y, height, yaw);
	}
}

bool PeripheralController::isMouseMode()
{
	return m_bMouseMode;
}