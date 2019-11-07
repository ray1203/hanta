#include "stdafx.h"
#include "Button.h"
#include "GameScene.h"
#include "InputManager.h"
#include "Tower.h"
Button::Button(const wchar_t* path, int x, int y)
	:GameObject(path)
	, col2(*transform, 80.0f, 80.0f)
{
	transform->SetPosition(x * 40 + 20, y * 40 + 20);
}

void Button::Update()
{
	if (col2.Intersected(InputManager::GetMouseVector2())) {
		HCURSOR hCursor = LoadCursor(0, IDC_HAND);
		hCursor = SetCursor(hCursor);

	}
	if (InputManager::GetMyKeyState(VK_LBUTTON) == 1 && col2.Intersected(InputManager::GetMouseVector2())) {
		GameScene& scene = (GameScene&)Scene::GetCurrentScene();
		tower = (Tower*)scene.PushBackGameObject(new Tower());
		tower->transform->SetPosition(InputManager::GetMouseX() / 40 * 40 + 20, InputManager::GetMouseY() / 40 * 40 + 20);
		flag = 1;
	}
	if (InputManager::GetMyKeyState(VK_LBUTTON) == 2 && flag) {
		tower->transform->SetPosition(InputManager::GetMouseX() / 40 * 40 + 20, InputManager::GetMouseY() / 40 * 40 + 20);
	}
	if (InputManager::GetMyKeyState(VK_LBUTTON) == -1 && flag) {
		GameScene& scene = (GameScene&)Scene::GetCurrentScene();
		flag = 0;

		if (scene.map[(int)(tower->transform->position.y - 20) / 40][(int)(tower->transform->position.x - 20) / 40]) {
			scene.Destroy(tower);
		}
	}
}