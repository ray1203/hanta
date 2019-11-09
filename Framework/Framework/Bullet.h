#pragma once
#include "GameObject.h"
#include "CircleCollider.h"			//여기 추가
#include "AABBCollider.h"
class Bullet :
	public GameObject
{
public:
	Bullet(const wchar_t* path, float speed, float damage);
	Bullet(const wchar_t* path, float speed, float angle, float damage);
	~Bullet();
	float speed;
	float angle;
	float damage;
	void setPos(float towerX, float towerY, float enemyX, float enemyY);
	bool CheckOutOfScreen();

	CircleCollider bulletCol;			//여기도


	virtual void Update();
	virtual void Move();
	virtual void Destroy();
};

