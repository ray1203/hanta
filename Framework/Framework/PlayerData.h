#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include <ctime>
#include <map>
typedef std::string String; 
typedef unsigned short ushort;
struct words{
	String word;
	int value;
};
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
	String m_ChoSungTbl = "ぁあいぇえぉけげこさざしじすずせぜそぞ";
	String m_JungSungTbl = "ただちぢっつづてでとどなにぬねのはばぱひび";
	String m_JongSungTbl = "  ぁあぃいぅうぇぉおかがきぎくぐけげごさざしじずせぜそぞ";
	ushort m_UniCodeHangulBase = 0xAC00;
	ushort m_UniCodeHangulLast = 0xD79F;
	std::map<String,int> jaeum;//切製
	std::map<String, int> moeum;//乞製
	std::vector<words> eumjul;//製箭
	std::vector<words> word;//舘嬢
	int addMoney(int add);
	void createJaeum();
	void createMoeum();

	void printJaeum();
	void printMoeum();
	void printMoney();
	void printAll();

	String MergeJaso(String choSung, String jungSung, String jongSung);
	String MergeJaJa(String choSung1, String choSung2);
	String MergeSoSo(String mouem1, String mouem2);
	String Merge(String str1, String str2);
	String sprintJaeum();
	String sprintMoeum();
	void notifyChange();

	void pause();
	void resume();

};

