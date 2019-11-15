#pragma once
#include "GameObject.h"
#include "PlayerData.h"
#include "AABBCollider.h"
#include "InputManager.h"
class JaeumButton :
	public GameObject
{

public:
	const wchar_t* path;
	PlayerData* playerData;
	JaeumButton(const wchar_t* path, int x, int y, float width, float height, PlayerData* playerData);
	AABBCollider col2;
	void Update();
	int isclick = 0;
};

