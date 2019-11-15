#include "stdafx.h"
#include "JaeumButton.h"
#include "GameScene.h"

JaeumButton::JaeumButton(const wchar_t* path, int x, int y, float width, float height, PlayerData* playerData)
	:GameObject(path), playerData(playerData), col2(*transform, width, height), path(path)
{
	transform->SetPosition(x * 40 + 20, y * 40 + 20);
}

void JaeumButton::Update()
{
	if (col2.Intersected(InputManager::GetMouseVector2())) {
		HCURSOR hCursor = LoadCursor(0, IDC_HAND);
		hCursor = SetCursor(hCursor);
	}

	if (InputManager::GetMyKeyState(VK_LBUTTON) == -1 && col2.Intersected(InputManager::GetMouseVector2())) {
		playerData->createJaeum();
		playerData->printJaeum();
	}
}
