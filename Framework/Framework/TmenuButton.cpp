#include "stdafx.h"
#include "TmenuButton.h"
#include "GameScene.h"
TmenuButton::TmenuButton(const wchar_t* path, int colwidth, int colheight)
	:Button(path, colwidth, colheight)
{
}

void TmenuButton::Update()
{
	GameScene& s = (GameScene&)Scene::GetCurrentScene();
	if (col.Intersected(InputManager::GetMouseVector2())) {
		HCURSOR hCursor = LoadCursor(0, IDC_HAND);
		hCursor = SetCursor(hCursor);
	}
	if (col.Intersected(InputManager::GetMouseVector2())&&flag&&InputManager::GetMyKeyState(VK_LBUTTON) == -1) {
		for (int i = 0; i < 12; i++) {
			b[i] = (TowerButton*)s.PushBackGameObject(new TowerButton(s.GetPlayerData()->towerTable[i].path, 40, 40, i));
			b[i]->transform->SetPosition((i+1) * 40 + 20, 780);
		}
		flag = 0;
	}
	else if (col.Intersected(InputManager::GetMouseVector2()) && !flag && InputManager::GetMyKeyState(VK_LBUTTON) == -1)
	{
		for (int i = 0; i < 12; i++) {
			s.Destroy(b[i]);
		}
		flag = 1;
	}
}
