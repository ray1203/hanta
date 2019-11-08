#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
#include <vector>
class Enemy :
	public GameObject
{
	int ax = -1, ay = -1;
	int bx, by;
	float speed = 5.0;
	
public:
	int age;
	Enemy(const wchar_t* path, int bx, int by);
	~Enemy();
	AABBCollider* col;
	void Update();
};

