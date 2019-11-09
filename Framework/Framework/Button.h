#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
#include "Tower.h"
#include "BulletManager.h"
#include "EnemyGenerater.h"
class Button :
	public GameObject
{
public:
	EnemyGenerater* enemyGenerater;
	int flag = 0;
	Button(const wchar_t* path, int x, int y,BulletManager *bm);
	BulletManager* bm;
	AABBCollider col2;
	void Update();
	Tower* tower;
};