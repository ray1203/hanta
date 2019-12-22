#include "stdafx.h"
#include "MakeTowerButton.h"
#include "GameScene.h"

MakeTowerButton::MakeTowerButton(const wchar_t* path, float colwidth, float colheight)
	:Button(path, colwidth, colheight)
{
	GameScene& s = (GameScene&)Scene::GetCurrentScene();
	playerData = s.GetPlayerData();
}

void MakeTowerButton::OnClick()
{
	int attribute=0;
	for (int i = 0; i < buffer.size(); i++) {
		if (buffer[i] == ' ') {
			buffer.erase(i, 1);
		}
	}
	if (playerData->word[buffer] && buffer.size() > 3) {
		flag = true;
		playerData->word.erase(buffer);
		if (playerData->vocab[buffer]) {
			attribute = playerData->vocab[buffer];
		}
		else {
			attribute = 6;
		}
		playerData->myTower[(attribute - 1) * 2 + buffer.size() / 2 - 2]++;
		for (int i = 0; i < 12; i++) {
			std::cout << playerData->myTower[i] << " ";
		}

	}
	
}

void MakeTowerButton::setBuffer(String b)
{
	buffer = b;
}
