#include "stdafx.h"
#include "TowerButton.h"
#include "GameScene.h"
#include "InputManager.h"
#include "Tower.h"
#include "ImageResize.h"
ImageResize r;
TowerButton::TowerButton(const wchar_t* path, float colwidth, float colheight, int t)
	:Button(path, colwidth, colheight), t(t)
{
}
TowerButton::~TowerButton(){
	Scene::GetCurrentScene().Destroy(text);
}

void TowerButton::Update()
{
	GameScene& scene = (GameScene&)Scene::GetCurrentScene();
	if (!scene.GetPlayerData()->isPause) {
		if (text != nullptr)
			Scene::GetCurrentScene().Destroy(text);
		text = new FontObject(std::to_string(scene.GetPlayerData()->myTower[t]), transform->position.x - 5, transform->position.y - 37);
		Scene::GetCurrentScene().PushBackGameObject(text);
	}
	if (col.Intersected(InputManager::GetMouseVector2())) {
		HCURSOR hCursor = LoadCursor(0, IDC_HAND);
		hCursor = SetCursor(hCursor);
	}
	if (InputManager::GetMyKeyState(VK_LBUTTON) == 1 && col.Intersected(InputManager::GetMouseVector2())) {
		range = 600;
		if (scene.GetPlayerData()->myTower[t] > 0) {
			tower = (Tower*)scene.PushBackGameObject(
				new Tower(
				scene.GetPlayerData()->towerTable[t].path,
				scene.GetPlayerData()->towerTable[t].attribute,
				scene.GetPlayerData()->towerTable[t].damage,
				scene.GetPlayerData()->towerTable[t].speed,
				scene.GetPlayerData()->towerTable[t].srange,
				scene.GetPlayerData()->towerTable[t].rate,
				scene.GetPlayerData()->towerTable[t].star));
			
			tower->transform->SetPosition(InputManager::GetMouseX() / 40 * 40 + 20, InputManager::GetMouseY() / 40 * 40 + 20);
			tower->renderer->changeAlpha(0.5f);
			flag = 1;

			rangeI = (GameObject*)scene.PushBackGameObject(new GameObject(L"resources\\tower\\range.png"));
			rangeI->renderer->changeAlpha(0.5f);
			rangeI->transform->SetPosition(InputManager::GetMouseX() / 40 * 40 + 20, InputManager::GetMouseY() / 40 * 40 + 20);
		}
	}
	if (InputManager::GetMyKeyState(VK_LBUTTON) == 2 && flag) {
		tower->transform->SetPosition(InputManager::GetMouseX() / 40 * 40 + 20, InputManager::GetMouseY() / 40 * 40 + 20);
		rangeI->transform->SetPosition(InputManager::GetMouseX() / 40 * 40 + 20, InputManager::GetMouseY() / 40 * 40 + 20);

		r.resize(rangeI, (double)80 * tower->srange + 40, 80 * tower->srange + 40);
	}
	if (InputManager::GetMyKeyState(VK_LBUTTON) == -1 && flag) {
		GameScene& scene = (GameScene&)Scene::GetCurrentScene();
		flag = 0;
		scene.Destroy(rangeI);
		if (scene.map[(int)(tower->transform->position.y - 20) / 40][(int)(tower->transform->position.x - 20) / 40]!=0) {
			scene.Destroy(tower);
		}
		else {
			scene.GetPlayerData()->myTower[t]--;
			scene.map[(int)(tower->transform->position.y - 20) / 40][(int)(tower->transform->position.x - 20) / 40] = 2;
			tower->activation = 1;
			tower->renderer->changeAlpha(1.0f);
			scene.GetPlayerData()->tower[scene.GetPlayerData()->towerTable[t].attribute - 1]++;//////
		}
	}
}