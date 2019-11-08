#include "stdafx.h"
#include "Tower.h"
#include "Scene.h"
#include "Bullet.h"
#include "EnemyGenerater.h"
#include "Enemy.h"
#include "TimeManager.h"
#include <vector>
Tower::Tower(const wchar_t* path, int damage, int speed,int range,float rate):damage(damage),speed(speed),range(range),rate(rate),GameObject(path) {

	col = new CircleCollider(*transform, range);
	time = 0;
}
void Tower::Update() {
	time += TimeManager::GetDeltaTime();
	if (time >= rate) {
		Shoot();
		time = 0;
	}
	//std::cout << col->GetXOnScreen() << " ";
}

void Tower::Shoot()
{
	std::vector<Enemy*> enemyList;
	int maxAge = -1;
	float frontX = 0.0f; 
	float frontY = 0.0f;
	int listSize = enemyGenerater->getList().size();
	//std::cout << "listsize:"<<listSize<<" ";
	for (int i = 0; i < listSize; i++) {
		if (enemyGenerater->getValue(i)->age < 0)continue;
		//if (col-> Intersected(enemyGenerater->getValue(i)->col->boundingBox)) {
		//std::cout << "\n" << (this->transform->position.x - enemyGenerater->getValue(i)->transform->position.x) * (this->transform->position.x - enemyGenerater->getValue(i)->transform->position.x) + (this->transform->position.y - enemyGenerater->getValue(i)->transform->position.y) * (this->transform->position.y - enemyGenerater->getValue(i)->transform->position.y) << "\n";
		if ((this->transform->position.x - enemyGenerater->getValue(i)->transform->position.x) * (this->transform->position.x - enemyGenerater->getValue(i)->transform->position.x) + (this->transform->position.y - enemyGenerater->getValue(i)->transform->position.y) * (this->transform->position.y - enemyGenerater->getValue(i)->transform->position.y) <= range * range) {
			//std::cout << "ÀÀ±âÀÕ " << enemyGenerater->getValue(i)->transform->position.x << " " << enemyGenerater->getValue(i)->transform->position.y<<" "<<enemyList.size()<< std::endl;
			enemyList.push_back(enemyGenerater->getValue(i));
			if (maxAge < enemyGenerater->getValue(i)->age) {
				maxAge = enemyGenerater->getValue(i)->age;
				frontX = enemyGenerater->getValue(i)->transform->position.x;
				frontY = enemyGenerater->getValue(i)->transform->position.y;
			}

			//}


		}
	}
		if (listSize != 0&&enemyList.size()!=0) {
	Bullet* b = new Bullet(L"bullet.png", speed, damage);
	//std::cout << frontX << ' ' << frontY <<' '<<transform->position.x<<' '<<transform->position.y<< std::endl;
	Scene::GetCurrentScene().PushBackGameObject(b);
	b->setPos(transform->position.x, transform->position.y, frontX,frontY);
	b->transform->SetPosition(transform->position.x, transform->position.y);

	}
}

