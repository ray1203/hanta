#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include "Enemy.h"
class EnemyManager :
	public GameObject
{
	int i = 0;
	double pastTime = 0.0f;
	double currentTime;
public:
	EnemyManager();
	void Update();
	std::vector<Enemy*> enemyList;
	std::vector<Enemy*> getList();
	Enemy* getValue(int i);
};

