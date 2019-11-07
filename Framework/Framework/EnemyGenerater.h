#pragma once
#include "GameObject.h"
#include "GameScene.h"
class EnemyGenerater :
	public GameObject,public GameScene
{
	int i = 0;
	double pastTime = 0.0f;
	double currentTime;
public:
	void Update();
};

