#include "stdafx.h"
#include "GameScene.h"
#include "GameObject.h"
#include "Button.h"
#include "ImageResize.h"
#include "TmenuButton.h"
void GameScene::Initialize()
{
	for (int x = 0; x < 32; x++) {
		for (int y = 0; y < 20; y++) {
			if (map[y][x])
			{
				GameObject* g = (GameObject*)PushBackGameObject(new GameObject(L"resources\\road.png"));
				g->transform->SetPosition(x * 40 + 20, y * 40 + 20);
			}
			else {
				GameObject* g = (GameObject*)PushBackGameObject(new GameObject(L"resources\\ground.png"));
				g->transform->SetPosition(x * 40 + 20, y * 40 + 20);
			}
		}
	}
	ImageResize I;

	playerData = new PlayerData(20, 20);
	craftTable = (CraftTable*)PushBackGameObject(new CraftTable());
	bm = (BulletManager*)PushBackGameObject(new BulletManager());
	em = (EnemyManager*)PushBackGameObject(new EnemyManager());

	craftButton = (CraftButton*)PushBackGameObject(new CraftButton(L"resources\\button\\craftButton.png", 80, 80, craftTable));
	I.resize(craftButton, 80, 80);
	craftButton->transform->SetPosition(640, 40);

	b = (TmenuButton*)PushBackGameObject(new TmenuButton(L"resources\\button\\towerButton.png", 40, 40));
	I.resize(b, 40, 40);
	b->transform->SetPosition(20, 780);
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
