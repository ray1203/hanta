#include "stdafx.h"
#include "Tower.h"
#include "Bullet.h"
#include "Enemy.h"
#include "TimeManager.h"
#include "GameScene.h"
#include "InputManager.h"
#include "ImageResize.h"
#include <vector>
Tower::Tower(const wchar_t* path, int attribute, int damage, int speed, int srange, float rate, int star)
	:o_damage(damage), speed(speed), o_srange(srange), o_rate(rate), GameObject(path), attribute(attribute), path(path), star(star) {
	GameScene& s = (GameScene&)Scene::GetCurrentScene();
	bm = s.GetBM();
	em = s.GetEM();
	o_range = srange * 40 + 20;
	col = new CircleCollider(*transform, o_range);
	col2 = new AABBCollider(*transform, renderer->GetWidth(), renderer->GetHeight());
	playerData = s.GetPlayerData();
	time = 0;

	this->damage = o_damage;
	this->rate = o_rate;
	this->srange = o_srange;
	this->range = o_range;
}

void Tower::Update() {
	GameScene& scene = (GameScene&)Scene::GetCurrentScene();
	if (attribute == 1) {//힘
		damage = o_damage * (1 + 0.2 * scene.GetPlayerData()->tower[0]);
		towerkinds = "힘";
	}
	if (attribute == 2) {//환상
		rate = o_rate * 3.0 / (1.0 + scene.GetPlayerData()->tower[1]);
		towerkinds = "환상";
	}
	if (attribute == 3) {//자연
		range = o_range * (1 + 0.1 * scene.GetPlayerData()->tower[2]);
		srange = o_srange * (1 + 0.1 * scene.GetPlayerData()->tower[2]);
		towerkinds = "자연";
	}
	if (attribute == 4) {//인공
		multi = 2 + (int)(0.5 * (scene.GetPlayerData()->tower[3]) - 1);
		towerkinds = "인공";
	}
	if (attribute == 5) {//개념
		damage = o_damage * (0.5 * scene.GetPlayerData()->tower[4]);
		towerkinds = "개념";
	}
	col = new CircleCollider(*transform, range);
	if (!(playerData->isPause)) {
		time += TimeManager::GetDeltaTime();
		if (time >= rate && activation) {
			Shoot();
			time = 0;
		}
		if (InputManager::GetMyKeyState(MK_LBUTTON) == 1 && flag == 1) {
			scene.Destroy(rangeI);
			scene.Destroy(TowerInfoframe);
			scene.Destroy(towerkind);
			scene.Destroy(TowerImage);
			scene.Destroy(stars);
			scene.Destroy(towerstat);
			flag = 0;
		}
		if (InputManager::GetMyKeyState(VK_LBUTTON) == 1 && col2->Intersected(InputManager::GetMouseVector2()) && activation) {
			ImageResize r;
			rangeI = (GameObject*)scene.PushBackGameObject(new GameObject(L"resources\\tower\\range.png"));
			TowerInfoframe = (GameObject*)scene.PushBackGameObject(new GameObject(L"resources\\tower\\towerInfo.png"));
			TowerImage = (GameObject*)scene.PushBackGameObject(new GameObject(path));

			words = "";
			for (int i = 0; i < star; i++) {
				words += "★";
			}

			rangeI->renderer->changeAlpha(0.5f); rangeI->transform->SetPosition(transform->position.x, transform->position.y);
			int px, py;
			if (transform->position.x + 250 > 1080) {
				px = transform->position.x - 250;
			}
			else {
				px = transform->position.x + 250;
			}
			if (transform->position.y + 180 > 800) {
				py = transform->position.y - 200;
			}
			else if (transform->position.y - 180 < 0) {
				py = transform->position.y + 180;
			}
			else {
				py = transform->position.y;
			}
			TowerInfoframe->transform->SetPosition(px, py-35);

			TowerImage->transform->SetPosition(px - 120, py - 65);
			towerkind = (FontObject*)scene.PushBackGameObject(new FontObject("유형:" + towerkinds, px - 180, py + 30));
			towerkind->font->colorBrush->SetColor(D2D1::ColorF(0, 0.6, 0.7, 1));

			String temp = "공격력:";
			temp += std::to_string(damage);
			temp += "\n공격속도:";
			temp += std::to_string(speed);
			temp += "\n사거리:";
			if(range<60000)
			temp += std::to_string(range);
			else
			temp += "∞";
			temp += "\n멀티샷:";
			temp += std::to_string(multi - (attribute != 4));
			temp += "\n같은 계열의 타워 수:";
			temp += std::to_string(scene.GetPlayerData()->tower[attribute - 1]);



			towerstat = (FontObject*)scene.PushBackGameObject(new FontObject(temp, px - 25, py - 100));
			towerstat->font->colorBrush->SetColor(D2D1::ColorF(0, 0.6, 0.7, 1));
			
			stars = (FontObject*)scene.PushBackGameObject(new FontObject(words, px - 150, py - 15));
			stars->font->colorBrush->SetColor(D2D1::ColorF(1, 1, 0, 1));
			r.resize(rangeI, (double)80 * srange + 40, 80 * srange + 40);
			r.resize(TowerImage, 100, 100);
			towerstat->font->fontSize = 6;
			flag = 1;
		}
	}
}

void Tower::Shoot()
{
	if (attribute <= 3 || attribute == 6) {
		std::vector<Enemy*> enemyList;
		int maxAge = -1;
		Enemy* frontE = NULL;
		int listSize = em->getList().size();
		for (int i = 0; i < listSize; i++) {
			if (em->getValue(i)->age < 0 || em->getValue(i) == nullptr)
				continue;
			if (col->Intersected(em->getValue(i)->transform->position)) {
				enemyList.push_back(em->getValue(i));
				if (maxAge < em->getValue(i)->age) {
					maxAge = em->getValue(i)->age;
					frontE = em->getValue(i);
				}
			}
		}
		if (listSize != 0 && enemyList.size() != 0) {
			Bullet* b = bm->PushBackTowerBullet(new Bullet(L"resources\\tower\\bullet.png", speed, damage, frontE));
			b->transform->SetPosition(transform->position.x, transform->position.y);
		}
	}
	else if (attribute == 4) {//멀티 공격
		std::vector<Enemy*> enemyList;
		int maxAge = -1;
		Enemy* frontE = NULL;
		int listSize = em->getList().size();
		for (int i = 0; i < listSize; i++) {
			if (em->getValue(i)->age < 0 || em->getValue(i) == nullptr)
				continue;
			if (col->Intersected(em->getValue(i)->transform->position)) {
				enemyList.push_back(em->getValue(i));
				if (maxAge < em->getValue(i)->age) {
					maxAge = em->getValue(i)->age;
					frontE = em->getValue(i);
				}
			}
		}
		while (maxAge >= 0) {
			for (int i = 0; i < enemyList.size(); i++) {
				if (enemyList[i]->age == maxAge) {
					Bullet* b = bm->PushBackTowerBullet(new Bullet(L"resources\\tower\\bullet.png", speed, damage, enemyList[i]));
					b->transform->SetPosition(transform->position.x, transform->position.y);
					multi--;
				}
				if (multi == 0)
					break;
			}
			if (multi == 0)
				break;
			maxAge--;
		}
	}
	else if (attribute == 5) {//전체 공격
		std::vector<Enemy*> enemyList;
		for (int i = em->getList().size(); i--;) {
			 em->getValue(i)->hp -= damage;
			GameScene& s = (GameScene&)Scene::GetCurrentScene();
			if (em->getValue(i)->hp <= 0) {
				s.GetPlayerData()->changeMoney(em->getValue(i)->money);
				em->getValue(i)->Destroy();
			}
		}
	}
}