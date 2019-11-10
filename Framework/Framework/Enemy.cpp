#include "stdafx.h"
#include "Enemy.h"
#include "GameScene.h"
#include "InputManager.h"
Enemy::Enemy(const wchar_t* path, int bx, int by, int hp)
	:GameObject(path), bx(bx), by(by), hp(hp), col(*transform, renderer->GetWidth(), renderer->GetHeight())
{
	GameScene& s = (GameScene&)Scene::GetCurrentScene();
	bm = s.GetBM();
	age = 0;
	speed = 5.0f;
}

Enemy::~Enemy() {
}

void Enemy::Update() {
	
	/*ax ay:���� ��ġ 
	bx by: ��ǥ ��ġ 
	cx cy: ���� ��ġ�� 40�� 1 ġȯ�ؼ� ���������� �ٲ۰� 
	dx dy:�׳� �����¿� ���°�*/
	double cx = (this->transform->position.x - 20) / 40;
	double cy = (this->transform->position.y - 20) / 40;
	int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
	if (cx == bx && cy == by) {
		for (int i = 0; i < 4; i++) {
			if (cx + dx[i] >= 0 && cx + dx[i] < 32 && cy + dy[i] >= 0 && cy + dy[i] < 20) {
				GameScene g;
				if (g.GetMap(cx + dx[i], cy + dy[i]) == 1 && (cx + dx[i] != ax || cy + dy[i] != ay)) {
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
	else if (ax==30&&ay==1) {
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
}

void Enemy::Destroy()
{
	for (auto& i : bm->towerBullets) {
		if (i->e == this) {
			bm->Destroy(i);
		}
	}
	Scene::GetCurrentScene().Destroy(this);
	//bm->Remove();
}