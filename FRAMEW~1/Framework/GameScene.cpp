#include "stdafx.h"
#include "GameScene.h"
#include "Player.h"

void GameScene::Initialize()
{
	TestObject* t = (TestObject*)PushBackGameObject(new TestObject());		//�׽�Ʈ�� ������Ʈ�Դϴ�.

	player = (Player*)PushBackGameObject(new Player());			//������Ʈ�� �����ϰ� �ʹٸ�, PushBackGameObject�Լ��� ȣ���Ͽ� �����մϴ�.
	player->enemy = t;
}
