#include "stdafx.h"
#include "GameScene.h"
#include "Bullet.h"
#include "TimeManager.h"
#include "Framework.h"
#define PI 3.141592f

Bullet::Bullet(const wchar_t* path, float speed, float damage, Enemy* e)
	:GameObject(path), speed(speed), damage(damage), bulletCol(*transform, renderer->GetWidth() * 0.5f),e(e)
{
	this->speed = speed;
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	setPos();
	Move();
	CheckOutOfScreen();
	Damage();
}

void Bullet::setPos() {
	if (e != nullptr) {
		float X = transform->position.x;
		float Y = transform->position.y;
		float enemyX = e->transform->position.x;
		float enemyY = e->transform->position.y;

		angle = atan2((enemyY - Y), (enemyX - X)) * 57.295f;
		angle /= 360.0f;
	}
}

void Bullet::Move()
{
	//움직일 때 사용할 함수
	float rad = PI * angle * 2.0f;
	transform->position.x += (speed * cosf(rad) * TimeManager::GetDeltaTime());
	transform->position.y += (speed * sinf(rad) * TimeManager::GetDeltaTime());
}

void Bullet::Damage() {
	if (bulletCol.Intersected(e->col)) {
		e->hp -= damage;
		GameScene& s = (GameScene&)Scene::GetCurrentScene();
		if (e->hp <= 0) {
			s.GetPlayerData()->addMoney(e->money);
			s.GetPlayerData()->printMoney();
			e->Destroy();
		}
		else {
			s.GetBM()->Destroy(this);
		}
	}
}

bool Bullet::CheckOutOfScreen()
{
	int sw = Framework::GetInstance().GetWinApp().GetScreenWidth();
	int sh = Framework::GetInstance().GetWinApp().GetScreenHeight();
	int bw = renderer->GetWidth();
	int bh = renderer->GetHeight();
	Vector2 pos = transform->position;
	Vector2 scale = transform->scale;
	return pos.x<scale.x * bw * (-1.0f) ||
		pos.x>scale.x * bw + sw ||
		pos.y<scale.y * bh * (-1.0f) ||
		pos.y>scale.y * bh + sh;
}