#pragma once
#include "GameObject.h"
#include "CircleCollider.h"
#include "BulletManager.h"	
#include "EnemyManager.h"
#include "PlayerData.h"
class Tower :
	public GameObject
{
	int damage;
	int speed;
	int range=20;
	
	float rate;
	float time;
	int flag = 0;
	GameObject* rangeI;
	CircleCollider* col;
	EnemyManager* em;
	PlayerData* playerData;
	BulletManager* bm;
public:
	Tower(const wchar_t* path, int damage,int speed,int range,float rate);
int srange = 0;
	int activation = 0;

	void Update();
	void Shoot();
};