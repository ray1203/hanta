#pragma once
#include "GameObject.h"
class Enemy :
	public GameObject
{
	int ax = -1, ay = -1;
	int bx, by;
	float speed = 5.0;
public:
	Enemy(const wchar_t* path, int bx, int by);

	void Update();
};

