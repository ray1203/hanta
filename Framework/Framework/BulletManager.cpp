#include "stdafx.h"
#include "BulletManager.h"
#include "Scene.h"			//¾À ÀÎÅ¬·çµå
#include "TimeManager.h"
#include "GameScene.h"
BulletManager::BulletManager()
{
	GameScene& s = (GameScene&)Scene::GetCurrentScene();
	playerData = s.GetPlayerData();
}

BulletManager::~BulletManager()
{
}

Bullet* BulletManager::PushBackTowerBullet(Bullet* b)
{
	Scene::GetCurrentScene().PushBackGameObject(b);
	towerBullets.push_back(b);
	return b;
}

void BulletManager::Destroy(Bullet* b)
{
	destroyed.push_back(b);
}

void BulletManager::Remove()
{
	for (auto& i : destroyed)
	{
		towerBullets.remove(i);
		Scene::GetCurrentScene().Destroy(i);
	}
	destroyed.clear();
}

void BulletManager::Check() {
	for (auto& i : towerBullets) {
		if (i->CheckOutOfScreen()) {
			Destroy(i);
		}
	}
}

void BulletManager::LateUpdate()
{	
	time += TimeManager::GetDeltaTime();
	if (time >= checkRate) {
		time = 0.0f;
		Check();
	}
	Remove();
}