#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include <ctime>
typedef std::string String; 
typedef unsigned short ushort;
class PlayerData
{
public:
	PlayerData();
	bool isPause;
	int money;
	void setlife(int life);
	void changeLife(int changelife);
	int life;
	wchar_t number[10][30] = {
		{L"resources\\number\\dot0.png"},
		{L"resources\\number\\dot1.png"},
		{L"resources\\number\\dot2.png"},
		{L"resources\\number\\dot3.png"},
		{L"resources\\number\\dot4.png"},
		{L"resources\\number\\dot5.png"},
		{L"resources\\number\\dot6.png"},
		{L"resources\\number\\dot7.png"},
		{L"resources\\number\\dot8.png"},
		{L"resources\\number\\dot9.png"}
	};
	GameObject* remainlife1;
	GameObject* remainlife2;
	String m_ChoSungTbl = "ぁあいぇえぉけげこさざしじすずせぜそぞ";
	String m_JungSungTbl = "ただちぢっつづてでとどなにぬねのはばぱひび";
	String m_JongSungTbl = "  ぁあぃいぅうぇぉおかがきぎくぐけげごさざしじずせぜそぞ";
	ushort m_UniCodeHangulBase = 0xAC00;
	ushort m_UniCodeHangulLast = 0xD79F;
	std::vector<String> jaeum;//切製
	std::vector<String> moeum;//乞製
	std::vector<String> eumjul;//製箭
	std::vector<String> word;//舘嬢
	int addMoney(int add);
	void createJaeum();
	void createMoeum();

	void printJaeum();
	void printMoeum();
	void printMoney();
	void printAll();

	String MergeJaso(String choSung, String jungSung, String jongSung);
	String MergeJaJa(String choSung1, String choSung2);
	String Merge(String str1, String str2);
	String sprintJaeum();
	String sprintMoeum();
	void notifyChange();

	void pause();
	void resume();

};

