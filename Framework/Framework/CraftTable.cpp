#include "stdafx.h"
#include "CraftTable.h"
#include "BackGround.h"
#include "GameScene.h"

CraftTable::CraftTable()
{
	GameScene& s = (GameScene&)Scene::GetCurrentScene();
	playerData = s.GetPlayerData();
}
void CraftTable::show() {
	FontObject* f = new FontObject("hihi",30,30);
	Scene::GetCurrentScene().PushBackGameObject(f);
	isActive = true;
	GameScene& s = (GameScene&)Scene::GetCurrentScene();
	background = (BackGround*)s.PushBackGameObject(new BackGround(L"resources\\background.png"));
	mButton = (MoeumButton*)s.PushBackGameObject(new MoeumButton(L"resources\\MoeumButton.png", 10, 10, 80, 80, playerData));
	jButton = (JaeumButton*)s.PushBackGameObject(new JaeumButton(L"resources\\JaeumButton.png", 20, 10, 80, 80, playerData));
	
}
void CraftTable::hide() {
	isActive = false;
	Scene::GetCurrentScene().Destroy(background);
	Scene::GetCurrentScene().Destroy(mButton);
	Scene::GetCurrentScene().Destroy(jButton);
}
void CraftTable::change() {
	GameScene& s = (GameScene&)Scene::GetCurrentScene();
	if (isActive) {
		hide();
		s.GetPlayerData()->resume();
	}
	else {
		show();
		s.GetPlayerData()->pause();
	}
}

void CraftTable::updateText()
{
	if(jaeumText!=nullptr)
	Scene::GetCurrentScene().Destroy(jaeumText);
	if(moeumText!=nullptr)
	Scene::GetCurrentScene().Destroy(moeumText);
	moeumText = new FontObject(playerData->sprintMoeum(), 1100, 600);
	jaeumText = new FontObject(playerData->sprintJaeum(), 100, 600);
	Scene::GetCurrentScene().PushBackGameObject(jaeumText);
	Scene::GetCurrentScene().PushBackGameObject(moeumText);
}
