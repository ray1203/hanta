#include "stdafx.h"
#include "CraftScene.h"
#include "SceneButton.h"
#include "GameScene.h"
void CraftScene::Initialize()
{
	SceneButton* sb = (SceneButton*)PushBackGameObject(new SceneButton(L"resources\\SceneButton.png", 11, 17, 80, 80, new GameScene()));
}
