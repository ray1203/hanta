#include "stdafx.h"
#include "GameScene.h"
#include "Player.h"
#include "GameObject.h"
#include "Button.h"
//#include "SceneButton.h"
//#include "CraftScene.h"
void GameScene::Initialize()
{
	for (int x = 0; x < 32; x++) {
		for (int y = 0; y < 20; y++) {
			if (map[y][x])
			{
				GameObject* g = (GameObject*)PushBackGameObject(new GameObject(L"resources\\Road.png"));
				g->transform->SetPosition(x * 40 + 20, y * 40 + 20);
			}
			else {
				GameObject* g = (GameObject*)PushBackGameObject(new GameObject(L"resources\\Ground.png"));
				g->transform->SetPosition(x * 40 + 20, y * 40 + 20);
			}
		}
	}
	playerData = new PlayerData();
	playerData->setlife(20);
	craftTable = (CraftTable*)PushBackGameObject(new CraftTable());
	craftButton = (CraftButton*)PushBackGameObject(new CraftButton(L"resources\\SceneButton.png", 31, 0, 80, 80, craftTable));
	bm = (BulletManager*)PushBackGameObject(new BulletManager());
	em = (EnemyManager*)PushBackGameObject(new EnemyManager());
	for (int i = 0; i < 12; i++) {
		Button* b = (Button*)PushBackGameObject(new Button(playerData->towerTable[i].path, i, 19,i));

	}
	//SceneButton* sb = (SceneButton*)PushBackGameObject(new SceneButton(L"resources\\SceneButton.png", 11, 17, 80, 80, new CraftScene()));
	//TestObject* t = (TestObject*)PushBackGameObject(new TestObject());		//테스트용 오브젝트입니다.
	//t->transform->SetPosition(200.0f,100.0f);

	//player = (Player*)PushBackGameObject(new Player());			//오브젝트를 생성하고 싶다면, PushBackGameObject함수를 호출하여 생성합니다.
	//player->enemy = t;
}

PlayerData* GameScene::GetPlayerData()
{
	return playerData;
}

BulletManager* GameScene::GetBM() {
	return bm;
}

EnemyManager* GameScene::GetEM() {
	return em;
}

CraftTable* GameScene::GetCraftTable()
{
	return craftTable;
}
