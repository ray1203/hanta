#include "stdafx.h"
#include "Bullet.h"
#include "TimeManager.h"
#include "Framework.h"
#define PI 3.141592f

Bullet::Bullet(const wchar_t* path, float speed, float damage)
	:GameObject(path), speed(speed), damage(damage),angle(0.0f),bulletCol(*transform, renderer->GetWidth() * 0.5f)
{
	this->speed = speed;
	//bulletCol = new CircleCollider(*transform, renderer->GetWidth() * 0.5f);
}
Bullet::Bullet(const wchar_t* path,float speed,float angle,float damage)
	:GameObject(path),speed(speed),angle(angle),damage(damage), bulletCol(*transform, renderer->GetWidth() * 0.5f)
{
	this->speed = speed;
	//bulletCol = new CircleCollider(*transform, renderer->GetWidth() * 0.5f);
}


Bullet::~Bullet()
{
}

void Bullet::Update()
{
	//std::cout << angle;
	Move();
	CheckOutOfScreen();
}
void Bullet::setPos(float towerX, float towerY, float enemyX, float enemyY) {
	angle = (enemyY - towerY) / (enemyX - towerX);
	angle = atan2((enemyY - towerY), (enemyX - towerX))*57.295f;
	angle = angle / 360.0f;
	angle = angle;
	
	
}
void Bullet::Move()
{
	//움직일 때 사용할 함수
	float rad = PI * angle * 2.0f;
	//rad = angle;
	transform->position.x
		+= (speed * cosf(rad)
			* TimeManager::GetDeltaTime());
	transform->position.y
		+= (speed * sinf(rad)
			* TimeManager::GetDeltaTime());
}

void Bullet::Destroy()
{
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