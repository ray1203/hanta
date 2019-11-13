#include "stdafx.h"
#include "SceneButton.h"
#include "InputManager.h"
SceneButton::SceneButton(const wchar_t* path, int x, int y, float width, float height, Scene* s)
	:GameObject(path), col2(*transform, width, height), s(s)
{
	transform->SetPosition(x * 40 + 20, y * 40 + 20);
}

void SceneButton::Update() {
	if (col2.Intersected(InputManager::GetMouseVector2())) {
		HCURSOR hCursor = LoadCursor(0, IDC_HAND);
		hCursor = SetCursor(hCursor);
	}

	if (InputManager::GetMyKeyState(VK_LBUTTON) == -1 && col2.Intersected(InputManager::GetMouseVector2())) {
		Scene::ChangeScene(s);
	}
}