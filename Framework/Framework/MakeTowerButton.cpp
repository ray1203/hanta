#include "stdafx.h"
#include "MakeTowerButton.h"
#include "GameScene.h"

MakeTowerButton::MakeTowerButton(const wchar_t* path)
	:GameObject(path), col2(*transform,640,600)
{
	GameScene& s = (GameScene&)Scene::GetCurrentScene();
	playerData = s.GetPlayerData();
	transform->position.x = 640;
	transform->position.y = 600;
}

void MakeTowerButton::Update()
{
	//std::cout << buffer;

	if (col2.Intersected(InputManager::GetMouseVector2())) {
		HCURSOR hCursor = LoadCursor(0, IDC_HAND);
		hCursor = SetCursor(hCursor);
	}

	if (InputManager::GetMyKeyState(VK_LBUTTON) == -1 && col2.Intersected(InputManager::GetMouseVector2())) {
		int attribute=0;
		for (int i = 0; i < buffer.size(); i++) {
			if (buffer[i] == ' ') {
				buffer.erase(i, 1);
			}
		}
		if (playerData->word[buffer]) {
			flag = true;
			playerData->word.erase(buffer);
			if (playerData->vocab[buffer]) {
				attribute = playerData->vocab[buffer];
				
			}
			else {
				attribute = 6;
			}
			playerData->myTower[(attribute - 1) * 2 + buffer.size()/2 - 2]++;
			for (int i = 0; i < 12; i++) {
				std::cout << playerData->myTower[i] << " ";
			}
		}
	}
}
void MakeTowerButton::destroy() {
	Scene::GetCurrentScene().Destroy(this);
}

void MakeTowerButton::getBuffer(String b)
{
	buffer = b;
}
