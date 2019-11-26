#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
class OverButton :
	public GameObject
{
	AABBCollider col;
public:
	OverButton(const wchar_t* path, float width, float height);
	void Update();
};

