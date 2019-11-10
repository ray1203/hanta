#include "stdafx.h"
#include "Tower.h"
#include "Bullet.h"
#include "Enemy.h"
#include "TimeManager.h"
#include "GameScene.h"
#include <vector>
Tower::Tower(const wchar_t* path, int damage, int speed, int range, float rate)
	:damage(damage), speed(speed), range(range), rate(rate), GameObject(path) {
	GameScene& s = (GameScene&)Scene::GetCurrentScene();
	bm = s.GetBM();
	em = s.GetEM();
	col = new CircleCollider(*transform, range);
	time = 0;
}

void Tower::Update() {
	time += TimeManager::GetDeltaTime();
	if (time >= rate && activation) {
		Shoot();
		time = 0;
	}
}

void Tower::Shoot()
{
	std::vector<Enemy*> enemyList;
	int maxAge = -1;
	Enemy* frontE = NULL;
	int listSize = em->getList().size();
	for (int i = 0; i < listSize; i++) {
		if (em->getValue(i)->age < 0)
			continue;
		if ((this->transform->position.x - em->getValue(i)->transform->position.x) * (this->transform->position.x - em->getValue(i)->transform->position.x) + (this->transform->position.y - em->getValue(i)->transform->position.y) * (this->transform->position.y - em->getValue(i)->transform->position.y) <= range * range) {
			enemyList.push_back(em->getValue(i));
			if (maxAge < em->getValue(i)->age) {
				maxAge = em->getValue(i)->age;
				frontE = em->getValue(i);
			}
		}
	}
	if (listSize != 0&&enemyList.size()!=0) {	
		Bullet* b = bm->PushBackTowerBullet(new Bullet(L"bullet.png", speed, damage, frontE));
		b->transform->SetPosition(transform->position.x, transform->position.y);
	}
}