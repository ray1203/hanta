#include "stdafx.h"
#include "Enemy.h"
#include "GameScene.h"

Enemy::Enemy(const wchar_t* path,int bx,int by)
	:GameObject(path),bx(bx),by(by)
{
	speed = 20.0f;
	Vector2 vec;
	col = new AABBCollider(*transform, renderer->GetWidth(),renderer->GetHeight());
}
Enemy::~Enemy() {
	printf("으앙뒤짐");
	SAFE_DELETE(col);
}
void Enemy::Update() {
	
	/*ax ay:이전 위치 
	bx by: 목표 위치 
	cx cy: 현재 위치를 40당 1 치환해서 정수값으로 바꾼거 
	dx dy:그냥 상하좌우 보는거*/
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

