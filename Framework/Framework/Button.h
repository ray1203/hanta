#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
#include "Tower.h"
#include "EnemyGenerater.h"
class Button :
	public GameObject
{
public:
	EnemyGenerater* enemyGenerater;
	int flag = 0;
	Button(const wchar_t* path, int x, int y);
	AABBCollider col2;
	void Update();
	Tower* tower;
};