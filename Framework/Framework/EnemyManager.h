#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include "Enemy.h"
#include "WaveButton.h"
#include "Scene.h"
class EnemyManager :
	public GameObject
{
	struct Info {
		const wchar_t* path;
		int bx;
		int by;
		int money;
		int hp;
	};
	Info enemyTable[2] = {
		{L"resources\\R.png", 0, 1, 1, 30}
	};
	int i = 0;
	int cnt = 0;
	double pastTime = 0.0f;
	double currentTime = 0.0f;
	WaveButton* w;
public:
	int wave = -1;
	int flag = 0;
	EnemyManager();
	void Update();
	std::vector<Enemy*> enemyList;
	std::vector<Enemy*> getList();
	Enemy* getValue(int i);
};

