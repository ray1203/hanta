#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
class WordButton:
	public GameObject
{
public:
	WordButton(const wchar_t* path, int x, int y);
	AABBCollider col2;

};

