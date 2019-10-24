#include "stdafx.h"
#include "InputManager.h"
#include "Framework.h"

POINT InputManager::mousePosition;

bool InputManager::lkey[256];
bool InputManager::rkey[256];

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}


int InputManager::GetMouseX()
{
	return mousePosition.x;
}

int InputManager::GetMouseY()
{
	return mousePosition.y;
}

Vector2 InputManager::GetMouseVector2()
{
	return Vector2((float)mousePosition.x,(float)mousePosition.y);
}

void InputManager::UpdateKeyState()
{
	static HWND hWnd = Framework::GetInstance().GetWinApp().GetHWND();

	//마우스 위치 갱신
	GetCursorPos(&mousePosition);
	ScreenToClient(hWnd,&mousePosition);

	//폴링, 키 상태 갱신
	for (int i = 0; i < 256; ++i)
	{
		lkey[i] = rkey[i];
		rkey[i] = GetAsyncKeyState(i) & 0x8000;
	}
}

int InputManager::GetMyKeyState(int vk)
{
	if (lkey[vk] && rkey[vk]) return 2; //아까도 눌렀었고 지금도 눌러져있을 때
	if (!lkey[vk] && rkey[vk]) return 1; //아까는 아니지만 지금은 눌려있을때
	if (lkey[vk] && !rkey[vk]) return -1; //누르다 땠을때
	return 0;	//눌리지 않았을 경우
}

bool InputManager::GetKeyDown(int vk)
{
	return (!lkey[vk] && rkey[vk])?true:false;
}

bool InputManager::GetKeyPressed(int vk)
{
	return (lkey[vk] && rkey[vk])?true:false;
}

bool InputManager::GetKeyUp(int vk)
{
	return (lkey[vk] && !rkey[vk])?true:false;
}
