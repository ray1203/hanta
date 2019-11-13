#include "stdafx.h"
#include "Tower.h"
#include "Bullet.h"
#include "Enemy.h"
#include "TimeManager.h"
#include "GameScene.h"
#include "InputManager.h"
#include <vector>
Tower::Tower(const wchar_t* path, int damage, int speed, int srange, float rate)
	:damage(damage), speed(speed), srange(srange), rate(rate), GameObject(path) {
	GameScene& s = (GameScene&)Scene::GetCurrentScene();
	bm = s.GetBM();
	em = s.GetEM();
	col = new CircleCollider(*transform, range);
	range += srange * 40;
	time = 0;
}

void Tower::Update() {
	time += TimeManager::GetDeltaTime();
	if (time >= rate && activation) {
		Shoot();
		time = 0;
	}	if (InputManager::GetMyKeyState(MK_LBUTTON) == 1 && flag == 1) {
		
		GameScene& scene = (GameScene&)Scene::GetCurrentScene();
		scene.Destroy(rangeI);
		flag = 0;
	}
	if (InputManager::GetMyKeyState(VK_LBUTTON) == 1 && col->Intersected(InputManager::GetMouseVector2())&&activation) {
		GameScene& scene = (GameScene&)Scene::GetCurrentScene();
		rangeI = (GameObject*)scene.PushBackGameObject(new GameObject(L"resources\\Range.png"));
		rangeI->renderer->changeAlpha(0.5f);
		rangeI->transform->SetPosition(transform->position.x,transform->position.y);
		printf("%d", srange);
		rangeI->transform->SetScale(srange*2.0f+1, srange*2.0f+1);
		flag = 1;
	}


}

void Tower::Shoot()
{
	std::vector<Enemy*> enemyList;
	int maxAge = -1;
	Enemy* frontE = NULL;
	int listSize = em->getList().size();
	for (int i = 0; i < listSize; i++) {
		if (em->getValue(i)->age < 0 || em->getValue(i) == nullptr)
			continue;
		float X = transform->position.x;
		float Y = transform->position.y;
		float enemyX = em->getValue(i)->transform->position.x;
		float enemyY = em->getValue(i)->transform->position.y;
		if ((X - enemyX)* (X - enemyX) + (Y - enemyY) * (Y - enemyY) <= range * range) {
			enemyList.push_back(em->getValue(i));
			if (maxAge < em->getValue(i)->age) {
				maxAge = em->getValue(i)->age;
				frontE = em->getValue(i);
			}
		}
	}
	if (listSize != 0&&enemyList.size()!=0) {	
		Bullet* b = bm->PushBackTowerBullet(new Bullet(L"resources\\Bullet.png", speed, damage, frontE));
		b->transform->SetPosition(transform->position.x, transform->position.y);
	}

}