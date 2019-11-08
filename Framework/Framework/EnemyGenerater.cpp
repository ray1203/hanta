#include "stdafx.h"
#include "EnemyGenerater.h"
#include "GameObject.h"
void EnemyGenerater::Update() {
	currentTime = clock();
	if ((pastTime == 0 || currentTime - pastTime >= 1000) && i < 30) {
		i++;
		Scene& s = Scene::GetCurrentScene();
		Enemy* e = (Enemy*)s.PushBackGameObject(new Enemy(L"R.png", 0, 1));
		e->transform->SetPosition(20, 60);
		//e->generater = this;
		enemyList.push_back(e);
		pastTime = currentTime;
		for (int i = 0; i < enemyList.size(); i++) {
			if (enemyList[i]->age <0)enemyList.erase(enemyList.begin() + i);
			std::cout << enemyList[i]->age<<" ";
		}
		std::cout << std::endl;
	}
}
std::vector<Enemy*> EnemyGenerater::getList() {
	return enemyList;
}
Enemy* EnemyGenerater::getValue(int i) {
	return enemyList[i];
}

void EnemyGenerater::delFirst()
{
	enemyList.erase(enemyList.begin());
}
