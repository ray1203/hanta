#include "stdafx.h"
#include "EnemyManager.h"
#include "GameObject.h"
#include "Scene.h"
EnemyManager::EnemyManager()
{
}

void EnemyManager::Update() {
	currentTime = clock();
	if ((pastTime == 0 || currentTime - pastTime >= 1000) && i < 30) {
		i++;
		Scene& s = Scene::GetCurrentScene();
		Enemy* e = (Enemy*)s.PushBackGameObject(new Enemy(L"resources\\R.png", 0, 1, 30));
		e->transform->SetPosition(20, 60);
		enemyList.push_back(e);
		pastTime = currentTime;
		for (int i = 0; i < enemyList.size(); i++) {
			if (enemyList[i]->age < 0)
				enemyList.erase(enemyList.begin() + i);
		}
	}
}

std::vector<Enemy*> EnemyManager::getList() {
	return enemyList;
}

Enemy* EnemyManager::getValue(int i) {
	return enemyList[i];
}