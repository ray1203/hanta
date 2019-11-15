#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
#include "BulletManager.h"
class BulletManager;
class Enemy :
	public GameObject
{
	int ax = -1, ay = -1;
	int bx, by;
	float speed = 5.0;
public:
	int age;
	float hp;
	int money = 1;
	Enemy(const wchar_t* path, int bx, int by,int money,int hp = 1);
	~Enemy();
	AABBCollider col;
	BulletManager* bm;
	virtual void Update();
	void Destroy();
};