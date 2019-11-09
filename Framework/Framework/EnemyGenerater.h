#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include "GameScene.h"
#include "Enemy.h"
class EnemyGenerater :
	public GameObject,public GameScene
{
	int i = 0;
	double pastTime = 0.0f;
	double currentTime;
public:
	EnemyGenerater(BulletManager* bm);
	void Update();
	BulletManager* bm;
	std::vector<Enemy*> enemyList;
	std::vector<Enemy*> getList();
	Enemy* getValue(int i);
	void delFirst();
};