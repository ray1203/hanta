#pragma once
#include "GameObject.h"
#include "CircleCollider.h"
#include "BulletManager.h"	
#include "EnemyManager.h"
#include "PlayerData.h"
class Tower :
	public GameObject
{
	int attribute;

	int damage;
	int o_damage;
	int speed;
	int range;
	int o_range;
	int multi = 2;
	
	float rate;
	float o_rate;
	float time;
	int flag = 0;
	GameObject* rangeI;
	CircleCollider* col;
	EnemyManager* em;
	PlayerData* playerData;
	BulletManager* bm;
public:
	Tower(const wchar_t* path, int attribute, int damage, int speed, int range, float rate);
	int srange;
	int o_srange;

	int activation = 0;

	void Update();
	void Shoot();
};