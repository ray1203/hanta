#include "stdafx.h"
#include "button2.h"
#include "InputManager.h"
#include "SceneManager.h"
button2::button2(const wchar_t* path, int x, int y)
	:GameObject(path), col2(*transform, 80.0f, 80.0f)
{
	transform->SetPosition(x * 40 + 20, y * 40 + 20);
}

void button2::Update()
{
	if (col2.Intersected(InputManager::GetMouseVector2())) {
		HCURSOR hCursor = LoadCursor(0, IDC_HAND);
		hCursor = SetCursor(hCursor);
	}

	if (InputManager::GetMyKeyState(VK_LBUTTON) == -1&& col2.Intersected(InputManager::GetMouseVector2())) {
		SceneManager s;
		s.changeScene(s.gs);
	}
}
