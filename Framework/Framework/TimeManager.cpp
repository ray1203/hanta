#include "stdafx.h"
#include "TimeManager.h"

float TimeManager::deltaTime;

void TimeManager::UpdateTime()
{
	static DWORD oldTime = timeGetTime();		//static 변수 초기화는 1회만 실행됨

	DWORD curTime = timeGetTime();				//현재 시간 받아옴
	deltaTime = (curTime - oldTime) * 0.001f;	//ms(밀리세컨드), 현재 시간-이전 시간 = 델타시간
	oldTime = curTime;							//이전 시간에 현재 시간 대입
}

float TimeManager::GetDeltaTime()
{
	return deltaTime;
}
