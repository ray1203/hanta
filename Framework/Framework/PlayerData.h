#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include <ctime>
typedef std::string String;
class PlayerData
{
public:
	PlayerData();
	bool isPause;
	int money;
	void setlife(int life);
	void changeLife(int changelife);
	int life;
	GameObject* remainlife1;
	GameObject* remainlife2;
	std::vector<String> jaeum;//자음
	std::vector<String> moeum;//모음
	std::vector<String> eumjul;//음절
	std::vector<String> word;//단어
	int addMoney(int add);
	void createJaeum();
	void createMoeum();

	void printJaeum();
	void printMoeum();
	void printMoney();
	void printAll();

	String sprintJaeum();
	String sprintMoeum();
	void notifyChange();

	void pause();
	void resume();
};

