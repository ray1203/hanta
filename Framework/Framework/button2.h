#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
class button2 :
	public GameObject
{
public:
	button2(const wchar_t* path, int x, int y);
	AABBCollider col2;
	void Update();
	int isclick = 0;
};

