#include "stdafx.h"
#include "CraftTable.h"
#include "BackGround.h"
#include "GameScene.h"
#include "ImageResize.h"
#pragma warning(disable:4996)
CraftTable::CraftTable()
{
	GameScene& s = (GameScene&)Scene::GetCurrentScene();
	playerData = s.GetPlayerData();
	buffer = "";
}
void CraftTable::Update()
{
	if (isActive) {
		if (makeTowerBtn->flag) {
			buffer = "";
			makeTowerBtn->flag = false;

		}
		input();
		makeTowerBtn->setBuffer(buffer);
	}
}
void CraftTable::show() {
	isActive = true;
	GameScene& s = (GameScene&)Scene::GetCurrentScene();

	ImageResize I;

	background = (BackGround*)s.PushBackGameObject(new BackGround(L"resources\\backGround.png"));
	I.resize(background, 1280, 800);
	background->transform->SetPosition(640, 400);

	s.Destroy(s.GetPlayerData()->coin);
	s.GetPlayerData()->coin = Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\ui\\coin.png"));
	I.resize(s.GetPlayerData()->coin, 45, 45);
	s.GetPlayerData()->coin->transform->SetPosition(940, 80);

	s.GetPlayerData()->changeMoney(0);

	jaeumButton = (JaeumButton*)s.PushBackGameObject(new JaeumButton(L"resources\\button\\jaeumButton.png", 80, 80, playerData));
	I.resize(jaeumButton, 160, 100);
	jaeumButton->transform->SetPosition(220, 620);

	moeumButton = (MoeumButton*)s.PushBackGameObject(new MoeumButton(L"resources\\button\\moeumButton.png", 80, 80, playerData));
	I.resize(moeumButton, 160, 100);
	moeumButton->transform->SetPosition(1020, 620);

	modeButton = (ModeButton*)s.PushBackGameObject(new ModeButton(L"resources\\button\\modeButton_1.png", 80, 80));
	I.resize(modeButton, 80, 80);
	modeButton->transform->SetPosition(620, 220);

	makeTowerBtn = (MakeTowerButton*)s.PushBackGameObject(new MakeTowerButton(L"resources\\button\\makeTower.png", 160, 160));
	I.resize(makeTowerBtn, 160, 160);
	makeTowerBtn->transform->SetPosition(640,600);

	gameButton = (GameObject*)s.PushBackGameObject(new GameObject(L"resources\\button\\gameButton.png"));
	I.resize(gameButton, 80, 80);
	gameButton->transform->SetPosition(640, 40);

	if (!craftmode) {
		modeButton2 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\button\\modeButton_2.png"));
		I.resize(modeButton2, 80, 80);
		modeButton2->transform->SetPosition(620, 220);
	}

	updateText();
}
void CraftTable::hide() {
	buffer = "";
	isActive = false;
	Scene::GetCurrentScene().Destroy(background);
	Scene::GetCurrentScene().Destroy(jaeumButton);
	Scene::GetCurrentScene().Destroy(moeumButton);
	Scene::GetCurrentScene().Destroy(modeButton);
	Scene::GetCurrentScene().Destroy(makeTowerBtn);
	Scene::GetCurrentScene().Destroy(gameButton);
	if(!craftmode)
		Scene::GetCurrentScene().Destroy(modeButton2);
	deleteText();
}

void CraftTable::deleteText()
{
	if (jaeumText != nullptr)
		Scene::GetCurrentScene().Destroy(jaeumText);
	if (moeumText != nullptr)
		Scene::GetCurrentScene().Destroy(moeumText);
	if (wordText != nullptr)
		Scene::GetCurrentScene().Destroy(wordText);
	if (insertText != nullptr)
		Scene::GetCurrentScene().Destroy(insertText);

	moeumText = new FontObject("", 800, 700);
	jaeumText = new FontObject("", 100, 700);
	wordText = new FontObject("", 300, 750);
	insertText = new FontObject("", 450, 350);

	Scene::GetCurrentScene().PushBackGameObject(jaeumText);
	Scene::GetCurrentScene().PushBackGameObject(moeumText);
	Scene::GetCurrentScene().PushBackGameObject(wordText);
	Scene::GetCurrentScene().PushBackGameObject(insertText);
}

void CraftTable::modeChange() {
	craftmode = !craftmode;
	ImageResize I;
	if (craftmode) {
		Scene::GetCurrentScene().Destroy(modeButton2);
	}
	else {
		modeButton2 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\button\\modeButton_2.png"));
		I.resize(modeButton2, 80, 80);
		modeButton2->transform->SetPosition(620, 220);
	}
}

void CraftTable::input()
{
	int keyselect = 0;
	if (buffer.size() >= 4&&craftmode) {

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
	else if (!craftmode && InputManager::GetKeyDown(VK_SPACE)) {
	buffer.append(" "); keyselect = 1;
}
	else if (InputManager::GetKeyDown(VK_RETURN)&&craftmode) {
		playerData->createWord(buffer);
		buffer.clear();
	}
	else if (InputManager::GetKeyDown(VK_RETURN) && !craftmode) {
		if (buffer.back() == ' ')buffer.erase(buffer.size() - 1);
		String words[3];
		char* writable = new char[buffer.size() + 1];
		std::copy(buffer.begin(), buffer.end(), writable);
		int size = buffer.size();
		writable[buffer.size()] = '\0';
		words[0] = strtok(writable, " ");
		if (std::count(buffer.begin(), buffer.end(), ' ') >= 1)
			words[1] = strtok(NULL, " ");
		if (std::count(buffer.begin(), buffer.end(), ' ') == 2)
			words[2] = strtok(NULL, " ");

		String addtext;
		addtext = words[0];
		if (std::count(buffer.begin(), buffer.end(), ' ') >= 1)
			addtext += words[1];
		if (std::count(buffer.begin(), buffer.end(), ' ') == 2)
			addtext += words[2];

		if (playerData->word[words[0]])
		{
			std::map<String, int> usingword;
			usingword[words[0]] += 1;
			if (playerData->word[words[1]] && std::count(buffer.begin(), buffer.end(), ' ') >= 1 && playerData->word[words[1]] >= 1 + usingword[words[1]]) {
				usingword[words[1]] += 1;
				if (std::count(buffer.begin(), buffer.end(), ' ') >= 2 && playerData->word[words[2]] >= 1 + usingword[words[2]])
				{
					playerData->word[words[0]] -= 1;
					playerData->word[words[1]] -= 1;
					playerData->word[words[2]] -= 1;
					playerData->word[addtext] += 1;
					updateText();
					buffer.clear();
					
				}
				else if (playerData->word[words[1]]>=0+usingword[words[1]] && std::count(buffer.begin(), buffer.end(), ' ') ==1 ) {
					playerData->word[words[0]] -= 1;
					playerData->word[words[1]] -= 1;
					playerData->word[addtext] += 1;
					updateText();
					buffer.clear();
				}


			}

		}

	}
	if (InputManager::GetKeyDown(VK_BACK)) {
		if (buffer.size() > 0) {
			if (buffer.at(buffer.size() - 1) == ' ') {
				buffer.erase(buffer.size() - 1);
			}
			else {
				buffer.erase(buffer.size() - 1);
				buffer.erase(buffer.size() - 1);
			}
		}

	}
	if (keyselect) {
			keyselect = 0;
			int C_STR_BUFFER_SIZE = buffer.size() + 1;
			wchar_t* result = new wchar_t[buffer.size() + 1];
			const char* s = buffer.c_str();
			MultiByteToWideChar(CP_ACP, NULL, s + buffer.size() - 4, -1, result, buffer.size() + 1);
			


			wchar_t a1[15];
			swprintf(a1, sizeof(a1) / sizeof(wchar_t), L"%c", result[0]);
			char b1[15];
			sprintf_s(b1, 15, "%ls", a1);
			String result1(b1);

			wchar_t a2[15];
			swprintf(a2, sizeof(a2) / sizeof(wchar_t), L"%c", result[1]);
			char b2[15];
			sprintf_s(b2, 15, "%ls", a2);
		
			String result2(b2);
			//std::cout << "rs1:"<<result1 << " rs2:" << result2 <<result1.size()<<" "<<result2.size()<< std::endl;
			String str;
			str = playerData->merge(result1, result2);
		//	std::cout << "str:" << buffer << std::endl;
			if (str != "null") {
				//std::cout << buffer.find_last_of(result1) << " " << buffer.find(result1) << std::endl;
				buffer.erase(buffer.find(result1), buffer.size());
				buffer.append(str);
				updateText();
			}

		
	}



	int C_STR_BUFFER_SIZE = buffer.size() + 1;
	wchar_t* result = new wchar_t[buffer.size() + 1];
	MultiByteToWideChar(CP_ACP, NULL, buffer.c_str(), -1, result, buffer.size());
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
	moeumText = new FontObject(playerData->sprintMoeum(), 800, 700);
	jaeumText = new FontObject(playerData->sprintJaeum(), 100, 700);
	wordText = new FontObject(playerData->sprintWord(), 300, 750);
	insertText = new FontObject(buffer, 450, 350);
	insertText->transform->SetScale(4, 4);
	
	Scene::GetCurrentScene().PushBackGameObject(jaeumText);
	Scene::GetCurrentScene().PushBackGameObject(moeumText);
	Scene::GetCurrentScene().PushBackGameObject(insertText);
	Scene::GetCurrentScene().PushBackGameObject(wordText);
}
