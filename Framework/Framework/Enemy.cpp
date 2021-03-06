#include "stdafx.h"
#include "Enemy.h"
#include "GameScene.h"
#include "InputManager.h"
#include "ImageResize.h"
Enemy::Enemy(const wchar_t* path, int bx, int by,int money, int hp, float speed)
	:GameObject(path), bx(bx), by(by), hp(hp),money(money), speed(speed), col(*transform, renderer->GetWidth(), renderer->GetHeight())
{
	GameScene& s = (GameScene&)Scene::GetCurrentScene();
	playerData = s.GetPlayerData();
	bm = s.GetBM();
	age = 0;
	maxhp = hp;
	speed = 20.0f;
	hpbar = (GameObject*)s.PushBackGameObject(new GameObject(L"resources\\enemy\\hpBar.png"));
	hpbar->transform->SetPosition(this->transform->position.x, this->transform->position.y - 18);
	ImageResize I;
	I.resize(hpbar, 24, 4);
}

Enemy::~Enemy() {
}

void Enemy::Update() {
	if (!playerData->isPause) {
		/*ax ay:이전 위치
		bx by: 목표 위치
		cx cy: 현재 위치를 40당 1 치환해서 정수값으로 바꾼거
		dx dy:그냥 상하좌우 보는거*/
		double cx = (this->transform->position.x - 20) / 40;
		double cy = (this->transform->position.y - 20) / 40;
		int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
		GameScene& s = (GameScene&)Scene::GetCurrentScene();
		if (cx == bx && cy == by) {
			for (int i = 0; i < 4; i++) {
				if (cx + dx[i] >= 0 && cx + dx[i] < 32 && cy + dy[i] >= 0 && cy + dy[i] < 20) {
					if (s.map[(int)cy + dy[i]][(int)cx + dx[i]] == 1 && (cx + dx[i] != ax || cy + dy[i] != ay)) {
						ax = bx;
						ay = by;
						bx += dx[i];
						by += dy[i];
						age++;
						break;
					}
				}
			}
		}
		else if (ax == 30 && ay == 1) {
			s.GetPlayerData()->changeLife(-1);
			Destroy();
		}
		else {
			if (bx - ax > 0) {
				this->transform->position.x += speed;
			}
			else if (ax - bx > 0) {
				this->transform->position.x -= speed;
			}
			else if (by - ay > 0) {
				this->transform->position.y += speed;
			}
			else {
				this->transform->position.y -= speed;
			}
		}
		ImageResize I;
		hpbar->transform->SetPosition(this->transform->position.x + 24 * (hp / maxhp - 1), this->transform->position.y - 18);
		I.resize(hpbar, 24 * hp / maxhp, 4);
	}
}

void Enemy::Destroy()
{
	for (auto& i : bm->towerBullets) {
		if (i->e == this) {
			bm->Destroy(i);
		}
	}

	GameScene& s = (GameScene&)Scene::GetCurrentScene();
	std::vector<Enemy*>::iterator iter = s.GetEM()->enemyList.begin();
	for (int i = 0; i < s.GetEM()->enemyList.size(); i++) {
		if (s.GetEM()->enemyList[i] == this) {
			s.GetEM()->enemyList.erase(iter + i);
		}
	}

	Scene::GetCurrentScene().Destroy(this);
	Scene::GetCurrentScene().Destroy(hpbar);
}