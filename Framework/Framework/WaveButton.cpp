#include "stdafx.h"
#include "WaveButton.h"
#include "InputManager.h"
#include "GameScene.h"
WaveButton::WaveButton(const wchar_t* path, int x, int y)
:GameObject(path), col2(*transform, 40.0f,40.0f)
{
	transform->SetPosition(x * 40 + 20, y * 40 + 20);
}

void WaveButton::Update()
{
	if (col2.Intersected(InputManager::GetMouseVector2())) {
		HCURSOR hCursor = LoadCursor(0, IDC_HAND);
		hCursor = SetCursor(hCursor);
	}

	if (InputManager::GetMyKeyState(VK_LBUTTON) == -1 && col2.Intersected(InputManager::GetMouseVector2())) {
		HCURSOR hCursor = LoadCursor(0, IDC_ARROW);
		hCursor = SetCursor(hCursor);
		GameScene& s = (GameScene&)Scene::GetCurrentScene();
		(s.GetEM())->wave++;
		(s.GetEM())->flag = 0;
		s.Destroy(this);
	}
}