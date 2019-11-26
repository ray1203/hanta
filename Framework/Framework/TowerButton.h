#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
#include "Scene.h"
#include "Button.h"
#include "GameScene.h"
class GameScene;
class TowerButton :
	public GameObject
{
public:
	Button* b[13];
	int flag = 1;
	TowerButton(const wchar_t* path, int x, int y);
	AABBCollider col2;
	void Update();
	GameScene& s = (GameScene&)Scene::GetCurrentScene();
};

