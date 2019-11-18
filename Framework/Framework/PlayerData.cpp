#include "stdafx.h"
#include "PlayerData.h"
#include "GameScene.h"
PlayerData::PlayerData():money(10),isPause(false)
{
	
	std::srand(static_cast<unsigned int>(std::time(0)));
}

int PlayerData::addMoney(int add=1)
{
	money += add;
	return money;
}

void PlayerData::createJaeum()
{
	if (money > 0) {
		String list[30] = { "ぁ","い","ぇ","ぉ","け","げ","さ","し","じ","ず","せ","ぜ","そ","ぞ" };
		int r = std::rand() % 14;
		jaeum.push_back(list[r]);
		money--;
		notifyChange();
	}
	else std::cout << "儀 採膳" << "\n";
	
}

void PlayerData::createMoeum()
{
	if (money > 0) {
		String list[30] = { "に","づ","ち","だ","つ","び","た","っ","で","ば","ぬ","ぱ"};
		int r = std::rand() % 12;
		moeum.push_back(list[r]);
		money--;
		notifyChange();
	}
	else std::cout << "儀 採膳" << "\n";
}

void PlayerData::printJaeum()
{
	std::cout << "jaeum : ";
	for (int i = 0; i < jaeum.size(); i++) {
		std::cout << jaeum[i] << ",";
	}
	std::cout << "\n";
}

void PlayerData::printMoeum()
{
	std::cout << "moeum : ";
	for (int i = 0; i < moeum.size(); i++) {
		std::cout << moeum[i] << ",";
	}
	std::cout << "\n";
}

void PlayerData::printMoney()
{
	std::cout << "money : "<<money<<"\n";
}

void PlayerData::printAll()
{
	std::cout << "----------------------" << "\n";
	printJaeum();
	printMoeum();
	printMoney();
	std::cout << "----------------------" << "\n";
}

String PlayerData::sprintJaeum()
{
	String str;
	for (int i = 0; i < jaeum.size(); i++) {
		str.append(jaeum[i]);
		if (i != jaeum.size() - 1) {
			str.append(",");
		}
	}
	return str;
}

String PlayerData::sprintMoeum()
{
	String str;
	for (int i = 0; i < moeum.size(); i++) {
		str.append(moeum[i]);
		if (i != moeum.size() - 1) {
			str.append(",");
		}
	}
	return str;
}

void PlayerData::notifyChange()
{
	printf("notify\n");
	GameScene& s = (GameScene&)Scene::GetCurrentScene();
	s.GetCraftTable()->updateText();
}

void PlayerData::pause()
{
	isPause = true;
}

void PlayerData::resume()
{
	isPause = false;
}
