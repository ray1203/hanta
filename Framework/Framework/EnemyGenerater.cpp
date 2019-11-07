#include "stdafx.h"
#include "EnemyGenerater.h"
#include "Enemy.h"
#include "GameObject.h"
void EnemyGenerater::Update() {
	currentTime = clock();
	if ((pastTime == 0 || currentTime - pastTime >= 1000) && i < 30) {
		i++;
		Scene& s = Scene::GetCurrentScene();
		Enemy* e = (Enemy*)s.PushBackGameObject(new Enemy(L"R.png", 0, 1));
		e->transform->SetPosition(20, 60);
		pastTime = currentTime;
	}
}