#include "stdafx.h"
#include "Enemy.h"
#include "GameScene.h"

Enemy::Enemy(const wchar_t* path,int bx,int by)
	:GameObject(path),bx(bx),by(by)
{
}

void Enemy::Update() {
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

