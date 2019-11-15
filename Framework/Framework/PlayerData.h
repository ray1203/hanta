#pragma once
#include "stdafx.h"
#include <ctime>
typedef std::string String;
class PlayerData
{
public:
	PlayerData();
	int money;
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
};

