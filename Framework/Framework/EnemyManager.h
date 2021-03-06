#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include "Enemy.h"
#include "WaveButton.h"
#include "PlayerData.h"
class EnemyManager :
	public GameObject
{
	struct Info {
		const wchar_t* path;
		int bx;
		int by;
		int money;
		int hp;
		float speed;
	};
	Info enemyTable[1000] = {
		{L"resources\\enemy\\enemy_1.png", 0, 1, 1, 100, 5.0},
		{L"resources\\enemy\\enemy_2.png", 0, 1, 2, 200, 4.0},
		{L"resources\\enemy\\enemy_3.png", 0, 1, 1, 75, 8.0},
		{L"resources\\enemy\\enemy_4.png", 0, 1, 3, 1000, 5.0},
	};
	int i = 0;
	int cnt = 0;
	double pastTime = 0.0f;
	double currentTime = 0.0f;
	WaveButton* w;
public:
	PlayerData* playerData;
	int wave = -1;
	int flag = 0;
	EnemyManager();
	void Update();
	std::vector<Enemy*> enemyList;
	std::vector<Enemy*> getList();
	Enemy* getValue(int i);
};

