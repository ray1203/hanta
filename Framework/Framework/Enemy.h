#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
#include <vector>
#include "Bullet.h"
#include "BulletManager.h"
class Enemy :
	public GameObject
{
	int ax = -1, ay = -1;
	int bx, by;
	float speed = 5.0;
	
public:
	Bullet* bullet;
	int age;
	int hp;
	Enemy(const wchar_t* path, int bx, int by, BulletManager* bm);
	Enemy(const wchar_t* path, int bx, int by,int hp, BulletManager* bm);
	~Enemy();
	AABBCollider col;
	BulletManager* bm;
	virtual void Update();
	virtual void LateUpdate();
};

