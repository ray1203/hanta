#pragma once
#include "stdafx.h"
#include <ctime>
typedef std::string String;
class PlayerData
{
public:
	PlayerData();
	int money;
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
};

