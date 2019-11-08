#pragma once
#include "GameObject.h"
#include "CircleCollider.h"
#include "EnemyGenerater.h"
class Tower :
	public GameObject

{
public:
	CircleCollider* col;
	EnemyGenerater* enemyGenerater;
	Tower(const wchar_t* path, int damage,int speed,int range,float rate);
	int damage;
	int speed;
	int range;
	float rate;
	float time;
	void Update();
	void Shoot();
	
};