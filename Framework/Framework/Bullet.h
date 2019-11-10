#pragma once
#include "GameObject.h"
#include "CircleCollider.h"			//���� �߰�
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

	CircleCollider bulletCol;			//���⵵
	Enemy* e;

	virtual void Update();
	void Move();
	void Damage();
};