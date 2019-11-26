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
	PlayerData();
	bool isPause;
	int money;
	void setdata(int life, int money);
	void changeLife(int changelife);
	void changeMoney(int changemoney);
	int life;
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
	int tower[6] = { 0 };
	int over = 0;
	GameObject* remainlife[10];
	GameObject* remainmoney[10];
	int ls, ms;
	String m_ChoSungTbl = "ㄱㄲㄴㄷㄸㄹㅁㅂㅃㅅㅆㅇㅈㅉㅊㅋㅌㅍㅎ";
	String m_JungSungTbl = "ㅏㅐㅑㅒㅓㅔㅕㅖㅗㅘㅙㅚㅛㅜㅝㅞㅟㅠㅡㅢㅣ";
	String m_JongSungTbl = "  ㄱㄲㄳㄴㄵㄶㄷㄹㄺㄻㄼㄽㄾㄿㅀㅁㅂㅄㅅㅆㅇㅈㅊㅋㅌㅍㅎ";
	ushort m_UniCodeHangulBase = 0xAC00;
	ushort m_UniCodeHangulLast = 0xD79F;
	std::map<String, int> jaeum;//자음
	std::map<String, int> moeum;//모음
	std::map<String, int> eumjul;//음절
	std::map<String, int> word;//단어
	std::map<String, int> vocab;//단어 목록 선언은 .cpp에서
	struct Info {
		const wchar_t* path;
		int attribute;
		int damage;
		int speed;//탄속
		int srange;
		float rate;//딜레이
	};
	
	Info towerTable[1000] = {
		{L"resources\\tower\\power_1.png",power,12,1000,3,0.5f},
		{L"resources\\tower\\power_2.png",power,15,1000,3,0.35f},
		{L"resources\\tower\\fantasy_1.png",fantasy,8,1000,3,0.4f},
		{L"resources\\tower\\fantasy_2.png",fantasy,11,1000,3,0.25f},
		{L"resources\\tower\\nature_1.png",nature,10,1000,4,0.5f},
		{L"resources\\tower\\nature_2.png",nature,13,1000,4,0.35f},
		{L"resources\\tower\\art_1.png",art,10,1000,3,0.5f},
		{L"resources\\tower\\art_2.png",art,13,1000,3,0.35f},
		{L"resources\\tower\\concept_1.png",concept,10,1000,1510,0.5f},
		{L"resources\\tower\\concept_2.png",concept,13,1000,1510,0.35f},
		{L"resources\\tower\\none_1.png",none,15,1000,3,0.3f},
		{L"resources\\tower\\none_2.png",none,17,1000,3,0.2f},
	};

	void createJaeum();
	void createMoeum();

	void CreateWord(String str);
	void printJaeum();
	void printMoeum();
	void printMoney();
	void printAll();

	int BreakHan(wchar_t* str, wchar_t* buffer, int nSize);

	String MergeJaso(String choSung, String jungSung, String jongSung);
	String MergeJaJa(String choSung1, String choSung2);
	String MergeSoSo(String mouem1, String mouem2);
	String Merge(String str1, String str2);
	String sprintJaeum();
	String sprintMoeum();
	String splitJaeum(String);
	String splitmoeum(String);//?
	String sprintword();
	void notifyChange();

	void pause();
	void resume();

};

