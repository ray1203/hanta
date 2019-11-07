#include "stdafx.h"
#include "GameScene.h"
#include "Player.h"
#include "GameObject.h"
#include "EnemyGenerater.h"
void GameScene::Initialize()
{
	for (int x = 0; x < 32; x++) {
		for (int y = 0; y < 20; y++) {
			if (map[y][x])
			{
				GameObject* g = (GameObject*)PushBackGameObject(new GameObject(L"Road.png"));
				g->transform->SetPosition(x * 40 + 20, y * 40 + 20);
			}
			else {
				GameObject* g = (GameObject*)PushBackGameObject(new GameObject(L"Ground.png"));
				g->transform->SetPosition(x * 40 + 20, y * 40 + 20);
			}
		}
	}
	EnemyGenerater* e = (EnemyGenerater*)PushBackGameObject(new EnemyGenerater());
	//TestObject* t = (TestObject*)PushBackGameObject(new TestObject());		//테스트용 오브젝트입니다.
	//t->transform->SetPosition(200.0f,100.0f);

	//player = (Player*)PushBackGameObject(new Player());			//오브젝트를 생성하고 싶다면, PushBackGameObject함수를 호출하여 생성합니다.
	//player->enemy = t;
}

int GameScene::GetMap(int x, int y) {
	return map[y][x];
}