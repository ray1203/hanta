#pragma once
#include "GameObject.h"
#include "CraftTable.h"
#include "AABBCollider.h"
#include "InputManager.h"
class CraftButton :
	public GameObject
{

public:
	const wchar_t* path;
	CraftTable* craftTable;
	CraftButton(const wchar_t* path, int x, int y, float width, float height, CraftTable* ct);
	AABBCollider col2;
	void Update();
	int isclick = 0;
};

