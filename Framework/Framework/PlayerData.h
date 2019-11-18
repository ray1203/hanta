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
	std::vector<String> jaeum;//����
	std::vector<String> moeum;//����
	std::vector<String> eumjul;//����
	std::vector<String> word;//�ܾ�
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

