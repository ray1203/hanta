#pragma once
#include "stdafx.h"
//싱글턴으로 활용될 Audio 객체입니다.
//프레임워크 내부 객체입니다.
class Audio
{
public:
	Audio();
	~Audio();

	IXAudio2* xaudio2;	//XAudio2 엔진 인스턴스
	IXAudio2MasteringVoice* masterVoice;	//마스터 보이스
	IMFAttributes* sourceReaderConfiguration;

	bool Initialize();
	void Uninitialize();
	void LoadFile(const wchar_t* path, std::vector<BYTE>& audioData, WAVEFORMATEX** waveFormatEx, unsigned int& waveLength);

	static Audio* GetInstance();


};

