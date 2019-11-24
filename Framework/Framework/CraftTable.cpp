#include "stdafx.h"
#include "CraftTable.h"
#include "BackGround.h"
#include "GameScene.h"
#include "ImageResize.h"
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
	updateText();
}
void CraftTable::hide() {
	buffer = "";
	isActive = false;
	Scene::GetCurrentScene().Destroy(background);
	Scene::GetCurrentScene().Destroy(mButton);
	Scene::GetCurrentScene().Destroy(jButton);
	deleteText();
}

void CraftTable::deleteText()
{
	if (jaeumText != nullptr)
		Scene::GetCurrentScene().Destroy(jaeumText);
	if (moeumText != nullptr)
		Scene::GetCurrentScene().Destroy(moeumText);
	if (insertText != nullptr)
		Scene::GetCurrentScene().Destroy(insertText);

	moeumText = new FontObject("", 1100, 600);
	jaeumText = new FontObject("", 100, 600);
	insertText = new FontObject("", 600, 400);

	Scene::GetCurrentScene().PushBackGameObject(jaeumText);
	Scene::GetCurrentScene().PushBackGameObject(moeumText);
	Scene::GetCurrentScene().PushBackGameObject(insertText);
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
	int keyselect = 0;
	if (buffer.size() >= 4) {

	}
	else if (InputManager::GetKeyDown(0x52) && InputManager::GetMyKeyState(VK_SHIFT)) {
		buffer.append("あ"); keyselect = 1;

	}
	else if (InputManager::GetKeyDown(0x52)) {
		buffer.append("ぁ"); keyselect = 1;

	}
	else if (InputManager::GetKeyDown(0x53)) {
		buffer.append("い"); keyselect = 1;

	}
	else if (InputManager::GetKeyDown(0x45) && InputManager::GetMyKeyState(VK_SHIFT)) {
		buffer.append("え"); keyselect = 1;

	}
	else if (InputManager::GetKeyDown(0x45)) {
		buffer.append("ぇ"); keyselect = 1;

	}
	else if (InputManager::GetKeyDown(0x46)) {
		buffer.append("ぉ"); keyselect = 1;

	}
	else if (InputManager::GetKeyDown(0x41)) {
		buffer.append("け"); keyselect = 1;
	}
	else if (InputManager::GetKeyDown(0x51) && InputManager::GetMyKeyState(VK_SHIFT)) {
		buffer.append("こ"); keyselect = 1;
	}
	else if (InputManager::GetKeyDown(0x51)) {
		buffer.append("げ"); keyselect = 1;
	}
	else if (InputManager::GetKeyDown(0x54) && InputManager::GetMyKeyState(VK_SHIFT)) {
		buffer.append("ざ"); keyselect = 1;
	}
	else if (InputManager::GetKeyDown(0x54)) {
		buffer.append("さ"); keyselect = 1;
	}
	else if (InputManager::GetKeyDown(0x44)) {
		buffer.append("し"); keyselect = 1;
	}
	else if (InputManager::GetKeyDown(0x57) && InputManager::GetMyKeyState(VK_SHIFT)) {
		buffer.append("す"); keyselect = 1;
	}
	else if (InputManager::GetKeyDown(0x57)) {
		buffer.append("じ"); keyselect = 1;
	}
	else if (InputManager::GetKeyDown(0x43)) {
		buffer.append("ず"); keyselect = 1;
	}
	else if (InputManager::GetKeyDown(0x5A)) {
		buffer.append("せ"); keyselect = 1;
	}
	else if (InputManager::GetKeyDown(0x58)) {
		buffer.append("ぜ"); keyselect = 1;
	}
	else if (InputManager::GetKeyDown(0x56)) {
		buffer.append("そ"); keyselect = 1;
	}
	else if (InputManager::GetKeyDown(0x47)) {
		buffer.append("ぞ"); keyselect = 1;
	}

	else if (InputManager::GetKeyDown(0x4B)) {
		buffer.append("た"); keyselect = 1;
	}

	else if (InputManager::GetKeyDown(0x49)) {
		buffer.append("ち"); keyselect = 1;
	}


	else if (InputManager::GetKeyDown(0x4A)) {
		buffer.append("っ"); keyselect = 1;
	}
	else if (InputManager::GetKeyDown(0x55)) {
		buffer.append("づ"); keyselect = 1;
	}
	else if (InputManager::GetKeyDown(0x48)) {
		buffer.append("で"); keyselect = 1;
	}
	else if (InputManager::GetKeyDown(0x59)) {
		buffer.append("に"); keyselect = 1;
	}

	else if (InputManager::GetKeyDown(0x4E)) {
		buffer.append("ぬ"); keyselect = 1;
	}
	else if (InputManager::GetKeyDown(0x42)) {
		buffer.append("ば"); keyselect = 1;
	}
	else if (InputManager::GetKeyDown(0x4D)) {
		buffer.append("ぱ"); keyselect = 1;
	}
	else if (InputManager::GetKeyDown(0x4C)) {
		buffer.append("び"); keyselect = 1;
	}

	else if (InputManager::GetKeyDown(0x4F) && InputManager::GetMyKeyState(VK_SHIFT)) {
		buffer.append("ぢ"); keyselect = 1;
	}
	else if (InputManager::GetKeyDown(0x4F)) {
		buffer.append("だ"); keyselect = 1;
	}
	else if (InputManager::GetKeyDown(0x50) && InputManager::GetMyKeyState(VK_SHIFT)) {
		buffer.append("て"); keyselect = 1;
	}
	else if (InputManager::GetKeyDown(0x50)) {
		buffer.append("つ"); keyselect = 1;
	}
	else if (InputManager::GetKeyDown(VK_RETURN)) {
		playerData->CreateWord(buffer);
		buffer.clear();
	}
	if (InputManager::GetKeyDown(VK_BACK)) {
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
	if (buffer.size() <= 4 && keyselect) {
		std::cout << buffer.size() << std::endl;
		keyselect = 0;
		int C_STR_BUFFER_SIZE = buffer.size() + 1;
		printf("d: %d\n", C_STR_BUFFER_SIZE);
		wchar_t* result = new wchar_t[buffer.size() + 1];
		const char* s = buffer.c_str();
		MultiByteToWideChar(CP_ACP, NULL, s + buffer.size() - 4, -1, result, buffer.size() + 1);
		wprintf(L"%c\n", result[2]);


		wchar_t a1[15];
		swprintf(a1, sizeof(a1) / sizeof(wchar_t), L"%c", result[0]);
		char b1[15];
		sprintf_s(b1, 15, "%ls", a1);
		String result1(b1);
		std::cout << "r1:" << result1 << "\n";

		wchar_t a2[15];
		swprintf(a2, sizeof(a2) / sizeof(wchar_t), L"%c", result[1]);
		char b2[15];
		sprintf_s(b2, 15, "%ls", a2);
		String result2(b2);
		std::cout << "r2:" << result2 << "\n"; String str;
		str = playerData->Merge(result1, result2);
		std::cout << "str:" << str << "\n";
		if (str != "null") {
			buffer.erase(buffer.find(result1), buffer.size());
			buffer.append(str);
			updateText();
		}
	}



	int C_STR_BUFFER_SIZE = buffer.size() + 1;
	wchar_t* result = new wchar_t[buffer.size() + 1];
	MultiByteToWideChar(CP_ACP, NULL, buffer.c_str(), -1, result, buffer.size());
	//std::cout << buffer.size() << std::endl;
	/*if (buffer.size() > 6) {

			buffer.erase(buffer.size() - 1);
			buffer.erase(buffer.size() - 1);

	}*/
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
	if (wordText != nullptr)
		Scene::GetCurrentScene().Destroy(wordText);
	moeumText = new FontObject(playerData->sprintMoeum(), 800, 600);
	jaeumText = new FontObject(playerData->sprintJaeum(), 100, 600);
	wordText = new FontObject(playerData->sprintword(), 300, 700);
	insertText = new FontObject(buffer, 550, 350);
	insertText->transform->SetScale(4, 4);
	insertText->font->fontWeight = DWRITE_FONT_WEIGHT_HEAVY;
	Scene::GetCurrentScene().PushBackGameObject(jaeumText);
	Scene::GetCurrentScene().PushBackGameObject(moeumText);
	Scene::GetCurrentScene().PushBackGameObject(insertText);
	Scene::GetCurrentScene().PushBackGameObject(wordText);
}
