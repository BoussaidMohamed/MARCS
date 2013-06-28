#include "Spatializer.h"

Spatializer::Spatializer()
{
	initOpenAL();
	initSapi();
}

Spatializer::~Spatializer()
{
	shutDownOpenAL();
	shutDownSapi();
}

bool Spatializer::initOpenAL()
{
	// Ouverture du device
	ALCdevice* pDevice = alcOpenDevice(NULL);

	if (!pDevice)
	{
		return false;
	}

	// Création du contexte
	ALCcontext* pContext = alcCreateContext(pDevice, NULL);

	if (!pContext)
	{
		return false;
	}

	// Activation du contexte
	if (!alcMakeContextCurrent(pContext))
	{
		return false;
	}

	return true;
}

bool Spatializer::initSapi()
{
	if (FAILED(CoInitialize(NULL)))
	{
		return false;
	}

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&m_pVoice);

	if(SUCCEEDED(hr))
	{
		return true;
	}

	return false;
}

void Spatializer::shutDownOpenAL()
{
	//Buffer destruction
	alDeleteBuffers(1, &m_pBuffer);

	//Device and context get
	ALCcontext* pContext = alcGetCurrentContext();
	ALCdevice*  pDevice  = alcGetContextsDevice(pContext);

	//Context deactivation
	alcMakeContextCurrent(NULL);

	//Context destruction
	alcDestroyContext(pContext);

	//Device closing
	alcCloseDevice(pDevice);
}

void Spatializer::shutDownSapi()
{
	m_pVoice->Release();
	::CoUninitialize();
}

ALuint Spatializer::loadSound(QString p_pFileName)
{
	//Audio file read with libsndfile
	SF_INFO pFileInfos;
	SNDFILE* pFile = sf_open(p_pFileName.toStdString().c_str(), SFM_READ, &pFileInfos);

	if (!pFile)
	{
		return 0;
	}

	//Number of sample and rate get
	ALsizei nNbSamples  = static_cast<ALsizei>(pFileInfos.channels * pFileInfos.frames);
	ALsizei nSampleRate = static_cast<ALsizei>(pFileInfos.samplerate);

	//Read of sample in 16 signed bits format
	std::vector<ALshort> aSamples(nNbSamples);
	if (sf_read_short(pFile, &aSamples[0], nNbSamples) < nNbSamples)
	{
		return 0;
	}

	//File closing
	sf_close(pFile);

	//Format determination
	ALenum Format;
	switch (pFileInfos.channels)
	{
	case 1 :  Format = AL_FORMAT_MONO16;   break;
	case 2 :  Format = AL_FORMAT_STEREO16; break;
	default : return 0;
	}

	//OpenAL buffer creation
	alGenBuffers(1, &m_pBuffer);

	//Copy int he buffer
	alBufferData(m_pBuffer, Format, &aSamples[0], nNbSamples * sizeof(ALushort), nSampleRate);

	//Error verification
	if (alGetError() != AL_NO_ERROR)
	{
		return 0;
	}

	return m_pBuffer;
}

void Spatializer::playSound(ALuint p_pBuffer)
{
	if (isPlaying())
	{
		alSourceStop(m_pSource);
		alSourcei(m_pSource, AL_BUFFER, 0);
		alDeleteSources(1, &m_pSource);
	}

	//Source creation
	alGenSources(1, &m_pSource);

	//Source / buffer attachment
	alSourcei(m_pSource, AL_BUFFER, p_pBuffer);

	//Play
	alSourcePlay(m_pSource);
}

void Spatializer::playSound()
{
	if (isPlaying())
	{
		alSourceStop(m_pSource);
		alSourcei(m_pSource, AL_BUFFER, 0);
		alDeleteSources(1, &m_pSource);
	}

	//Source creation
	alGenSources(1, &m_pSource);

	//Source / buffer attachment
	alSourcei(m_pSource, AL_BUFFER, m_pBuffer);

	//Play
	alSourcePlay(m_pSource);
}

void Spatializer::textToSpeech(QString p_pText)
{
	CoInitialize(NULL);
	m_pVoice->SetVolume(100);

	m_pTextArray = (wchar_t*)malloc(p_pText.length() * sizeof(wchar_t));
	p_pText.toWCharArray(m_pTextArray);

	HRESULT res = m_pVoice->Speak(m_pTextArray, 0, NULL);
}

void Spatializer::definePosition(double x, double y, double z)
{
	//Source creation
	alGenSources(1, &m_pSource);

	//Listener position definition
	alListener3f(AL_POSITION, 0., 0., 0.);
	alListener3f(AL_VELOCITY, 0.0, 0.0, 0.0);

	//Source position definition
	alSource3f(m_pSource, AL_POSITION, x, y, z);	
	alSource3f(m_pSource, AL_VELOCITY, 0.0, 0.0, 0.0);
}

bool Spatializer::isPlaying()
{
	ALint nStatus;
	alGetSourcei(m_pSource, AL_SOURCE_STATE, &nStatus);

	return nStatus == AL_PLAYING;
}

void Spatializer::stopPlay()
{
	CoInitialize(NULL);
	alSourceStop(m_pSource);
	m_pVoice->SetVolume(0);
}
