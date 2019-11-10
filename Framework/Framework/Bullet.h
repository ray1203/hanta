#pragma once
#include "GameObject.h"
#include "CircleCollider.h"			//여기 추가
#include "Enemy.h"
class Enemy;
class Bullet:
	public GameObject
{
public:
	Bullet(const wchar_t* path, float speed, float damage, Enemy* e);
	~Bullet();
	float speed;
	float angle;
	float damage;
	void setPos();
	bool CheckOutOfScreen();

	CircleCollider bulletCol;			//여기도
	Enemy* e;

	virtual void Update();
	void Move();
	void Damage();
};