#include "stdafx.h"
#include "CraftButton.h"
#include "GameScene.h"

CraftButton::CraftButton(const wchar_t* path, int x, int y, float width, float height, CraftTable* ct)
	:GameObject(path), craftTable(ct), col2(*transform, width, height), path(path)
{
	transform->SetPosition(x * 40 + 20, y * 40 + 20);
}

void CraftButton::Update()
{
	if (col2.Intersected(InputManager::GetMouseVector2())) {
		HCURSOR hCursor = LoadCursor(0, IDC_HAND);
		hCursor = SetCursor(hCursor);
	}

	if (InputManager::GetMyKeyState(VK_LBUTTON) == -1 && col2.Intersected(InputManager::GetMouseVector2())) {
		craftTable->change();
		GameScene& s = (GameScene&)Scene::GetCurrentScene();
	}
}
