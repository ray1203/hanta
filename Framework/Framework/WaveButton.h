#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
class WaveButton :
	public GameObject
{
public:
	WaveButton(const wchar_t* path, int x, int y);
	AABBCollider col2;
	void Update();
};

