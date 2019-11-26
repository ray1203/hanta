#include "stdafx.h"
#include "OverButton.h"
#include "InputManager.h"
#include "GameScene.h"
OverButton::OverButton(const wchar_t* path, float width, float height)
	:GameObject(path), col(*transform, width, height)
{
}

void OverButton::Update()
{
	if (col.Intersected(InputManager::GetMouseVector2())) {
		HCURSOR hCursor = LoadCursor(0, IDC_HAND);
		hCursor = SetCursor(hCursor);
	}

	if (InputManager::GetMyKeyState(VK_LBUTTON) == -1 && col.Intersected(InputManager::GetMouseVector2())) {
		Scene::GetCurrentScene().ChangeScene(new GameScene());
	}
}