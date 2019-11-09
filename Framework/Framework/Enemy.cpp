#include "stdafx.h"
#include "Enemy.h"
#include "GameScene.h"
#include "EnemyGenerater.h"
#include <vector>
#include "InputManager.h"
Enemy::Enemy(const wchar_t* path, int bx, int by, BulletManager* bm)
	:GameObject(path), bx(bx), by(by), hp(1), col(*transform, renderer->GetWidth(), renderer->GetHeight()),bm(bm)
{
	//std::cout << "A"<<bullet->angle;
	age = 0;
	speed = 5.0f;
	Vector2 vec;
	//col = new AABBCollider(*transform, renderer->GetWidth(),renderer->GetHeight());
}
Enemy::Enemy(const wchar_t* path, int bx, int by,int hp, BulletManager* bm)
	:GameObject(path), bx(bx), by(by),hp(hp),col(*transform, renderer->GetWidth(), renderer->GetHeight()),bm(bm)
{
	age = 0;
	speed = 5.0f;
	Vector2 vec;
	//col = new AABBCollider(*transform, renderer->GetWidth(), renderer->GetHeight());
	
}
Enemy::~Enemy() {
	printf("���ӵ���");
	
	//SAFE_DELETE(col);
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
		Scene::GetCurrentScene().Destroy(this);
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

void Enemy::LateUpdate()
{
	//std::cout << "bulletcount:" << bm->towerBullets.size() << " ";
	for (auto& i : bm->towerBullets) {
		if (col.Intersected(i->bulletCol)) {
			bm->Destroy(i);
			
			hp -= i->damage;
			if (hp <= 0) {
				std::cout << "���� �¾Ҵ�";
				Scene::GetCurrentScene().Destroy(this);
				break;
			}
			
		}
	}
}