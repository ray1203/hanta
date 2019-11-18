#include "stdafx.h"
#include "CraftTable.h"
#include "BackGround.h"
#include "GameScene.h"
CraftTable::CraftTable()
{
	GameScene& s = (GameScene&)Scene::GetCurrentScene();
	playerData = s.GetPlayerData();
}
void CraftTable::Update()
{
	if (isActive)
		input();
}
void CraftTable::show() {
	//FontObject* f = new FontObject("hihi",30,30);
	//Scene::GetCurrentScene().PushBackGameObject(f);
	isActive = true;
	GameScene& s = (GameScene&)Scene::GetCurrentScene();
	background = (BackGround*)s.PushBackGameObject(new BackGround(L"resources\\background.png"));
	mButton = (MoeumButton*)s.PushBackGameObject(new MoeumButton(L"resources\\MoeumButton.png", 10, 10, 80, 80, playerData));
	jButton = (JaeumButton*)s.PushBackGameObject(new JaeumButton(L"resources\\JaeumButton.png", 20, 10, 80, 80, playerData));
}
void CraftTable::hide() {
	buffer = "";
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

void CraftTable::input()
{

	if (InputManager::GetKeyDown(0x41)) {
		buffer.append("け");
	}
	else if (InputManager::GetKeyDown(0x42)) {
		buffer.append("ば");
	}
	else if (InputManager::GetKeyDown(0x43)) {
		buffer.append("ず");
	}
	else if (InputManager::GetKeyDown(0x44)) {
		buffer.append("し");
	}
	else if (InputManager::GetKeyDown(0x45)) {
		buffer.append("ぇ");
	}
	else if (InputManager::GetKeyDown(0x46)) {
		buffer.append("ぉ");
	}
	else if (InputManager::GetKeyDown(0x47)) {
		buffer.append("ぞ");
	}
	else if (InputManager::GetKeyDown(0x48)) {
		buffer.append("で");
	}
	else if (InputManager::GetKeyDown(0x49)) {
		buffer.append("ち");
	}
	else if (InputManager::GetKeyDown(0x4A)) {
		buffer.append("っ");
	}
	else if (InputManager::GetKeyDown(0x4B)) {
		buffer.append("た");
	}
	else if (InputManager::GetKeyDown(0x4C)) {
		buffer.append("び");
	}
	else if (InputManager::GetKeyDown(0x4D)) {
		buffer.append("ぱ");
	}
	else if (InputManager::GetKeyDown(0x4E)) {
		buffer.append("ぬ");
	}
	else if (InputManager::GetKeyDown(0x4F)) {
		buffer.append("だ");
	}
	else if (InputManager::GetKeyDown(0x50)) {
		buffer.append("つ");
	}
	else if (InputManager::GetKeyDown(0x51)) {
		buffer.append("げ");
	}
	else if (InputManager::GetKeyDown(0x52)) {
		buffer.append("ぁ");
	}
	else if (InputManager::GetKeyDown(0x53)) {
		buffer.append("い");
	}
	else if (InputManager::GetKeyDown(0x54)) {
		buffer.append("さ");
	}
	else if (InputManager::GetKeyDown(0x55)) {
		buffer.append("づ");
	}
	else if (InputManager::GetKeyDown(0x56)) {
		buffer.append("そ");
	}
	else if (InputManager::GetKeyDown(0x57)) {
		buffer.append("じ");
	}
	else if (InputManager::GetKeyDown(0x58)) {
		buffer.append("ぜ");
	}
	else if (InputManager::GetKeyDown(0x59)) {
		buffer.append("に");
	}
	else if (InputManager::GetKeyDown(0x5A)) {
		buffer.append("せ");
	}
	else if (InputManager::GetKeyDown(VK_OEM_PLUS)) {
		buffer.append("+");
	}
	else if (InputManager::GetKeyDown(VK_BACK)) {
		if (buffer.size() > 0) {
			if (buffer.at(buffer.size() - 1) == '+') {
				buffer.erase(buffer.size() - 1);
			}
			else {
				buffer.erase(buffer.size() - 1);
				buffer.erase(buffer.size() - 1);
			}
		}

	}

	int C_STR_BUFFER_SIZE = buffer.size() + 1;
	wchar_t* result = new wchar_t[buffer.size() + 1];
	MultiByteToWideChar(CP_ACP, NULL, buffer.c_str(), -1, result, buffer.size() + 1);
	//std::cout << buffer.size() << std::endl;
	if (buffer.size() > 6) {
		if (buffer.at(buffer.size() - 1) == '+') {
			buffer.erase(buffer.size() - 1);
		}
		else {
			buffer.erase(buffer.size() - 1);
			buffer.erase(buffer.size() - 1);
		}
	}
	updateText();
}

void CraftTable::updateText()
{
	if (jaeumText != nullptr)
		Scene::GetCurrentScene().Destroy(jaeumText);
	if (moeumText != nullptr)
		Scene::GetCurrentScene().Destroy(moeumText);
	if (insertText != nullptr)
		Scene::GetCurrentScene().Destroy(insertText);
	moeumText = new FontObject(playerData->sprintMoeum(), 1100, 600);
	jaeumText = new FontObject(playerData->sprintJaeum(), 100, 600);
	insertText = new FontObject(buffer, 600, 400);
	Scene::GetCurrentScene().PushBackGameObject(jaeumText);
	Scene::GetCurrentScene().PushBackGameObject(moeumText);
	Scene::GetCurrentScene().PushBackGameObject(insertText);
}
