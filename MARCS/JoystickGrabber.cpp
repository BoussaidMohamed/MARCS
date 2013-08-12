#include "JoystickGrabber.h"

//DirectInput pointer
LPDIRECTINPUTDEVICE8  joypad = NULL; 

//Windows application instance
HINSTANCE instance = NULL;

//REturn value interpretation
HRESULT result; 

//DirectInput on device pointer 
LPDIRECTINPUT8 direct_input_object = NULL;

//Joypad state
DIJOYSTATE state;

//Enumeration callback
BOOL CALLBACK CreateDeviceCallback(LPCDIDEVICEINSTANCE instance, LPVOID reference)
{
   /*
	//Peripheral creation
	result = direct_input_object->CreateDevice(instance->guidInstance, &joypad, NULL);

	//Error management
	if(FAILED( result )) 
	{
		//Fail
		return DIENUM_CONTINUE; 
	}

	//Success
	return DIENUM_STOP;
        */
}

JoystickGrabber::JoystickGrabber()
{
    /*
	instance = GetModuleHandle(NULL);
	m_bDeviceNotCreated = true;
	createDevice();

	m_bNoJoystick = false;
	m_bDirectInputProblem = false;
	m_bDataFormatProblem = false;
	m_bJoystickProblem = false;
	m_bDeviceEnumProblem = false;

	connect(&m_pTimer, SIGNAL(timeout()), SLOT(sendAcknowledge()));
        */
}

void JoystickGrabber::createDevice()
{
    /*
	//DirectInput object creation
	result = DirectInput8Create(instance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&direct_input_object, NULL); 

	//Error management
	if(FAILED(result))
	{
		//Cannot create instance
		//Possible errors : DIERR_BETADIRECTINPUTVERSION, DIERR_INVALIDPARAM, DIERR_OLDDIRECTINPUTVERSION, DIERR_OUTOFMEMORY
		m_bDirectInputProblem = true;
		return;
	}

	m_bDirectInputProblem = false;

	//Enumerate peripherals
	result  = direct_input_object->EnumDevices(DI8DEVCLASS_GAMECTRL, &CreateDeviceCallback, NULL, DIEDFL_ATTACHEDONLY);

	//Error management
	if(FAILED(result))
	{
		//Cannot create joypad
		//possible errors : DIERR_INVALIDPARAM, DIERR_NOTINITIALIZED
		m_bDeviceEnumProblem = true;
		return;
	}
	m_bDeviceEnumProblem = false;

	if (joypad)
	{
		//Data format used definition
		result = joypad->SetDataFormat(&c_dfDIJoystick); 

		//Error management
		if(FAILED(result))
		{ 
			//Cannot initialize data format
			//Possible errors : DIERR_ACQUIRED, DIERR_INVALIDPARAM, DIERR_NOTINITIALIZED
			m_bDataFormatProblem = true;
			return;
		}

		m_bDataFormatProblem = false;
		m_bNoJoystick = false;
		m_bDeviceNotCreated = false;

		joypad->Acquire();
	}
	else
	{
		m_bNoJoystick = true;
	}
        */
}

void JoystickGrabber::computeData(DIJOYSTATE state)
{
    /*
	leftStickX = (state.lX - 32767) / 32767.;
	leftStickY = (state.lY - 32767) / 32767.;
	topTrigger = (state.lZ - 32767) / 32767.;
	rightStickX = (state.lRx - 32767) / 32767.;
	rightStickY = (state.lRy - 32767) / 32767.;

	for (int i = 0; i < 32; i++)
	{
		buttons[i] = (state.rgbButtons[i] != 0);
	}

	for (int i = 0; i < 4; i++)
	{
		pov[i] = (state.rgdwPOV[i] != -1);
	}

	emit dataComputed();
        */
}

void JoystickGrabber::Finalize(void)
{
    /*
	if (direct_input_object) 
	{ 
		//Finalize peripheral
		if (joypad) 
		{ 
			joypad->Unacquire(); 
			joypad->Release();
			joypad = NULL; 
		} 

		//Finalize DirectInput
		direct_input_object->Release();
		direct_input_object = NULL; 
	}
        */
}

void JoystickGrabber::grab()
{
    /*
	if (m_pTimer.isActive() == false)
	{
		m_pTimer.start(300);
	}

	if (m_bDeviceNotCreated)
	{
		createDevice();
	}

	if (m_bDeviceNotCreated == false)
	{
		result = joypad->Poll(); 

		//Error management
		if(FAILED(result))
		{ 
			m_bDeviceNotCreated = true;
			m_bJoystickProblem = true;
			return;
		}

		result = joypad->GetDeviceState(sizeof(state), (LPVOID)&state); 

		//Error management
		if(FAILED(result))
		{ 
			//Cannot get device state
			//Possible errors : DIERR_INPUTLOST, DIERR_INVALIDPARAM, DIERR_NOTACQUIRED, DIERR_NOTINITIALIZED, E_PENDING
			m_bJoystickProblem = true;
			return;
		}
		
		m_bJoystickProblem = false;
		computeData(state);
	}
        */
}

void JoystickGrabber::sendAcknowledge()
{
    /*
	if (m_bNoJoystick)
	{
		emit noJoystick();
	}

	if (m_bDirectInputProblem)
	{
		emit directInputProblem();
	}

	if (m_bDataFormatProblem)
	{
		emit dataFormatProblem();
	}

	if (m_bJoystickProblem)
	{
		emit joystickProblem();
	}

	if (m_bDeviceEnumProblem)
	{
		emit deviceEnumProblem();
	}

        */
}
