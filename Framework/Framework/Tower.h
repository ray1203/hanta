#pragma once
#include "GameObject.h"
#include "CircleCollider.h"
#include "BulletManager.h"	
#include "EnemyManager.h"
class Tower :
	public GameObject
{
	int damage;
	int speed;
	int range;
	float rate;
	float time;

	CircleCollider* col;
	EnemyManager* em;
	BulletManager* bm;
public:
	Tower(const wchar_t* path, int damage,int speed,int range,float rate);

	int activation = 0;

	void Update();
	void Shoot();
};