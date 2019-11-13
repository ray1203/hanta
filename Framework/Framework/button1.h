#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
class button1:
	public GameObject
{
public:
	button1(const wchar_t* path, int x, int y);
	AABBCollider col2;
	void Update();
	int isclick = 0;
};

