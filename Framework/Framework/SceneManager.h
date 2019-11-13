#pragma once
#include "GameScene.h"
#include "Scene.h"
#include "CraftScene.h"
#include "Framework.h"
class SceneManager
{
public:
	SceneManager();
	GameScene* gs = new GameScene();
	CraftScene* gc = new CraftScene();
	Framework &f = Framework::GetInstance();
	void startScene(Scene* s);
	void changeScene(Scene* s);
};

