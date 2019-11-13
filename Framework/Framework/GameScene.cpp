#include "stdafx.h"
#include "GameScene.h"
#include "Player.h"
#include "GameObject.h"
#include "Button.h"
#include "button1.h"
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
	bm = (BulletManager*)PushBackGameObject(new BulletManager());
	em = (EnemyManager*)PushBackGameObject(new EnemyManager());
	Button* b = (Button*)PushBackGameObject(new Button(L"Button.png", 9, 17));
	button1* b1 = (button1*)PushBackGameObject(new button1(L"button1 (1).jpg", 11,17));
	//TestObject* t = (TestObject*)PushBackGameObject(new TestObject());		//테스트용 오브젝트입니다.
	//t->transform->SetPosition(200.0f,100.0f);

	//player = (Player*)PushBackGameObject(new Player());			//오브젝트를 생성하고 싶다면, PushBackGameObject함수를 호출하여 생성합니다.
	//player->enemy = t;
}

int GameScene::GetMap(int x, int y) {
	return map[y][x];
}

BulletManager* GameScene::GetBM() {
	return bm;
}

EnemyManager* GameScene::GetEM() {
	return em;
}