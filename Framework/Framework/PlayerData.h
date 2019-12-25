#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include <ctime>
#include <map>
typedef std::string String; 
typedef unsigned short ushort;

class PlayerData
{
public:
	PlayerData(int life, int money);

	String m_ChoSungTbl = "ㄱㄲㄴㄷㄸㄹㅁㅂㅃㅅㅆㅇㅈㅉㅊㅋㅌㅍㅎ";
	String m_JungSungTbl = "ㅏㅐㅑㅒㅓㅔㅕㅖㅗㅘㅙㅚㅛㅜㅝㅞㅟㅠㅡㅢㅣ";
	String m_JongSungTbl = "  ㄱㄲㄳㄴㄵㄶㄷㄹㄺㄻㄼㄽㄾㄿㅀㅁㅂㅄㅅㅆㅇㅈㅊㅋㅌㅍㅎ";

	std::map<String, int> jaeum;//자음
	std::map<String, int> moeum;//모음
	std::map<String, int> eumjul;//음절
	std::map<String, int> word;//단어
	std::map<String, int> vocab;//단어 목록 선언은 .cpp에서

	void createJaeum();
	void createMoeum();
	void createWord(String str);

	void printJaeum();
	void printMoeum();
	void printAll();

	int breakHan(wchar_t* str, wchar_t* buffer, int nSize);

	String mergeJaJa(String choSung1, String choSung2);
	String mergeJaMo(String choSung, String jungSung, String jongSung);
	String mergeMoMo(String mouem1, String mouem2);
	String merge(String str1, String str2);

	String sprintJaeum();
	String sprintMoeum();
	String sprintWord();

	String splitJaeum(String);
	String splitMoeum(String);

public:
	enum attribute
	{
		power=1,
		fantasy,
		nature,
		art,
		concept,
		none,
	};
	enum attribute_kr
	{
		힘 = 1,
		환상,
		자연,
		인공,
		개념,
		무계열,
	};
	wchar_t number[10][30] = {
		{L"resources\\ui\\dot_0.png"},
		{L"resources\\ui\\dot_1.png"},
		{L"resources\\ui\\dot_2.png"},
		{L"resources\\ui\\dot_3.png"},
		{L"resources\\ui\\dot_4.png"},
		{L"resources\\ui\\dot_5.png"},
		{L"resources\\ui\\dot_6.png"},
		{L"resources\\ui\\dot_7.png"},
		{L"resources\\ui\\dot_8.png"},
		{L"resources\\ui\\dot_9.png"}
	};
	struct Info {
		const wchar_t* path;
		int attribute;
		int damage;
		int speed;//탄속
		int srange;
		float rate;//딜레이
		int star;
	};
	Info towerTable[1000] = {
		{L"resources\\tower\\power_1.png",power,12,1000,3,0.5f,2},
		{L"resources\\tower\\power_2.png",power,15,1000,3,0.35f,3},
		{L"resources\\tower\\fantasy_1.png",fantasy,8,1000,3,0.4f,2},
		{L"resources\\tower\\fantasy_2.png",fantasy,11,1000,3,0.25f,3},
		{L"resources\\tower\\nature_1.png",nature,10,1000,4,0.5f,2},
		{L"resources\\tower\\nature_2.png",nature,13,1000,4,0.35f,3},
		{L"resources\\tower\\art_1.png",art,10,1000,3,0.5f,2},
		{L"resources\\tower\\art_2.png",art,13,1000,3,0.35f,3},
		{L"resources\\tower\\concept_1.png",concept,10,1000,1510,0.5f,2},
		{L"resources\\tower\\concept_2.png",concept,13,1000,1510,0.35f,3},
		{L"resources\\tower\\none_1.png",none,15,1000,3,0.3f,2},
		{L"resources\\tower\\none_2.png",none,17,1000,3,0.2f,3},
	};
	int tower[6] = { 0 };
	int myTower[13] = { 0 };

	bool isPause;
	int over = 0;
	int nowdic = 0;
	int showdic = 0;
	int money;
	int life;
	int ls, ms;//life_lan money_lan
	GameObject* remainlife[10];
	GameObject* remainmoney[10];
	
	void notifyChange();

	void pause();
	void resume();

	void changeLife(int changelife);
	void changeMoney(int changemoney);
};

