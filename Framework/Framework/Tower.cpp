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
	if (attribute == 1) {//��
		damage = o_damage * (1 + 0.2 * scene.GetPlayerData()->tower[0]);
		towerkinds = "��";
	}
	if (attribute == 2) {//ȯ��
		rate = o_rate * 3.0 / (1.0 + scene.GetPlayerData()->tower[1]);
		towerkinds = "ȯ��";
	}
	if (attribute == 3) {//�ڿ�
		range = o_range * (1 + 0.1 * scene.GetPlayerData()->tower[2]);
		srange = o_srange * (1 + 0.1 * scene.GetPlayerData()->tower[2]);
		towerkinds = "�ڿ�";
	}
	if (attribute == 4) {//�ΰ�
		multi = 2 + (int)(0.5 * (scene.GetPlayerData()->tower[3]) - 1);
		towerkinds = "�ΰ�";
	}
	if (attribute == 5) {//����
		damage = o_damage * (0.5 * scene.GetPlayerData()->tower[4]);
		towerkinds = "����";
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
			rangeI = (GameObject*)scene.PushBackGameObject(new GameObject(L"resources\\Range.png"));
			TowerInfoframe = (GameObject*)scene.PushBackGameObject(new GameObject(L"resources\\TowerInfo.png"));
			TowerImage = (GameObject*)scene.PushBackGameObject(new GameObject(path));

			words = "";
			for (int i = 0; i < star; i++) {
				words += "��";
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
			TowerInfoframe->transform->SetPosition(px, py);

			TowerImage->transform->SetPosition(px - 120, py - 65);
			towerkind = (FontObject*)scene.PushBackGameObject(new FontObject("����:" + towerkinds, px - 160, py + 70));
			towerkind->font->colorBrush->SetColor(D2D1::ColorF(0, 0.6, 0.7, 1));

			String temp = "���ݷ�:";
			temp += std::to_string(damage);
			temp += "\n���ݼӵ�:";
			temp += std::to_string(speed);
			temp += "\n��Ÿ�:";
			temp += std::to_string(range);
			temp += "\n��Ƽ��:";
			temp += std::to_string(multi - (attribute != 4));
			temp += "\n���� �迭�� Ÿ�� ��:";
			temp += std::to_string(scene.GetPlayerData()->tower[attribute - 1]);



			towerstat = (FontObject*)scene.PushBackGameObject(new FontObject(temp, px, py));
			towerstat->font->colorBrush->SetColor(D2D1::ColorF(0, 0.6, 0.7, 1));
			towerstat->font->fontSize = 10;
			stars = (FontObject*)scene.PushBackGameObject(new FontObject(words, px - 150, py + 10));
			stars->font->colorBrush->SetColor(D2D1::ColorF(1, 1, 0, 1));
			r.resize(rangeI, (double)80 * srange + 40, 80 * srange + 40);
			r.resize(TowerImage, 100, 100);
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
			Bullet* b = bm->PushBackTowerBullet(new Bullet(L"resources\\Bullet.png", speed, damage, frontE));
			b->transform->SetPosition(transform->position.x, transform->position.y);
		}
	}
	else if (attribute == 4) {//��Ƽ ����
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
					Bullet* b = bm->PushBackTowerBullet(new Bullet(L"resources\\Bullet.png", speed, damage, enemyList[i]));
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
	else if (attribute == 5) {//��ü ����
		std::vector<Enemy*> enemyList;
		for (int i = em->getList().size(); i--;) {
			 em->getValue(i)->hp -= damage;
			GameScene& s = (GameScene&)Scene::GetCurrentScene();
			if (em->getValue(i)->hp <= 0) {
				s.GetPlayerData()->changeMoney(em->getValue(i)->money);
				s.GetPlayerData()->printMoney();
				em->getValue(i)->Destroy();
			}
		}
	}
}