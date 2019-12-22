#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
#include "BulletManager.h"
#include "PlayerData.h"
class BulletManager;
class Enemy :
	public GameObject
{
	int ax = -1, ay = -1;
	int bx, by;
	float speed = 5.0;
	GameObject* hpbar;
public:
	int age;
	float maxhp;
	float hp;
	int money = 1;
	Enemy(const wchar_t* path, int bx, int by, int money, int hp, float speed);
	~Enemy();
	AABBCollider col;
	BulletManager* bm;
	PlayerData* playerData;
	virtual void Update();
	void Destroy();
};