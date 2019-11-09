#include "stdafx.h"
#include "GameScene.h"
#include "Player.h"
#include "GameObject.h"
#include "EnemyGenerater.h"
#include "Button.h"
void GameScene::Initialize()
{
	printf("gamesceneInitializing");
	BulletManager* bm
		= (BulletManager*)PushBackGameObject(
			new BulletManager()
		);
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
	EnemyGenerater* e = (EnemyGenerater*)PushBackGameObject(new EnemyGenerater(bm));

	Button* b = (Button*)PushBackGameObject(new Button(L"Button.png", 9, 17,bm));
	b->enemyGenerater = e;
	//TestObject* t = (TestObject*)PushBackGameObject(new TestObject());		//�׽�Ʈ�� ������Ʈ�Դϴ�.
	//t->transform->SetPosition(200.0f,100.0f);

	//player = (Player*)PushBackGameObject(new Player());			//������Ʈ�� �����ϰ� �ʹٸ�, PushBackGameObject�Լ��� ȣ���Ͽ� �����մϴ�.
	//player->enemy = t;
	printf("gamesceneInitialized");

}

int GameScene::GetMap(int x, int y) {
	return map[y][x];
}