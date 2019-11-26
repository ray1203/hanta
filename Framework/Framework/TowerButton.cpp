#include "stdafx.h"
#include "TowerButton.h"
#include "InputManager.h"
#include "GameScene.h"
#include "Button.h"
#include "GameScene.h"
TowerButton::TowerButton(const wchar_t* path, int x, int y)
	:GameObject(path), col2(*transform, 40.0f, 40.0f)
{
	transform->SetPosition(x * 40 + 20, y * 40 + 20);
}
void TowerButton::Update()
{
	if (col2.Intersected(InputManager::GetMouseVector2())) {
		HCURSOR hCursor = LoadCursor(0, IDC_HAND);
		hCursor = SetCursor(hCursor);
	}
	if (col2.Intersected(InputManager::GetMouseVector2())&&flag&&InputManager::GetMyKeyState(VK_LBUTTON) == -1) {
		for (int i = 0; i < 12; i++) {
		b[i] = (Button*)s.PushBackGameObject(new Button(s.GetPlayerData()->towerTable[i].path, i+1, 19, i));
		}
		flag = 0;
	}
	else if (col2.Intersected(InputManager::GetMouseVector2()) && !flag && InputManager::GetMyKeyState(VK_LBUTTON) == -1)
	{
		for (int i = 0; i < 12; i++) {
			s.Destroy(b[i]);
	}
		flag = 1;
		}


}
