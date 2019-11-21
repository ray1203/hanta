#include "stdafx.h"
#include "EnemyManager.h"
#include "GameObject.h"
#include "GameScene.h"
#include "Scene.h"
EnemyManager::EnemyManager() {
	GameScene& s = (GameScene&)Scene::GetCurrentScene();
	w = (WaveButton*)s.PushBackGameObject(new WaveButton(L"resources\\WaveButton.png", 0, 1));
	playerData = s.GetPlayerData();
}

void EnemyManager::Update() {
	if (!playerData->isPause) {
		GameScene& s = (GameScene&)Scene::GetCurrentScene();
		if (s.enemyWave[wave][0] != 0 && flag == 0) {
			if (s.enemyWave[wave][i] != 0) {
				currentTime = clock();
				if ((pastTime == 0 || currentTime - pastTime >= s.enemyWave[wave][i + 1]) && cnt < s.enemyWave[wave][i + 2]) {
					cnt++;
					int n = s.enemyWave[wave][i] - 1;
					Enemy* e = (Enemy*)s.PushBackGameObject(new Enemy(enemyTable[n].path, enemyTable[n].bx, enemyTable[n].by, enemyTable[n].money, enemyTable[n].hp, enemyTable[n].speed));
					e->transform->SetPosition(20, 60);
					enemyList.push_back(e);
					pastTime = currentTime;
					for (int i = 0; i < enemyList.size(); i++) {
						if (enemyList[i]->age < 0)
							enemyList.erase(enemyList.begin() + i);
					}
				}
				else if (cnt >= s.enemyWave[wave][i + 2]) {
					i += 3;
					cnt = 0;
				}
			}
			else {
				w = (WaveButton*)s.PushBackGameObject(new WaveButton(L"resources\\WaveButton.png", 0, 1));
				i = 0;
				flag = 1;
			}
		}
	}
}

std::vector<Enemy*> EnemyManager::getList() {
	return enemyList;
}

Enemy* EnemyManager::getValue(int i) {
	return enemyList[i];
}