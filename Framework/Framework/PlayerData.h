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
	int tower[5] = { 0 };
	GameObject* remainlife1;
	GameObject* remainlife2;
	String m_ChoSungTbl = "ㄱㄲㄴㄷㄸㄹㅁㅂㅃㅅㅆㅇㅈㅉㅊㅋㅌㅍㅎ";
	String m_JungSungTbl = "ㅏㅐㅑㅒㅓㅔㅕㅖㅗㅘㅙㅚㅛㅜㅝㅞㅟㅠㅡㅢㅣ";
	String m_JongSungTbl = "  ㄱㄲㄳㄴㄵㄶㄷㄹㄺㄻㄼㄽㄾㄿㅀㅁㅂㅄㅅㅆㅇㅈㅊㅋㅌㅍㅎ";
	ushort m_UniCodeHangulBase = 0xAC00;
	ushort m_UniCodeHangulLast = 0xD79F;
	std::map<String, int> jaeum;//자음
	std::map<String, int> moeum;//모음
	std::map<String, int> eumjul;//음절
	std::map<String, int> word;//단어

	struct Info {
		const wchar_t* path;
		int attribute;
		int damage;
		int speed;//탄속
		int srange;
		float rate;//딜레이
	};
	Info towerTable[1000] = {
		{L"resources\\Tower.png", 1, 1, 1000, 3, 0.1f},

	};

	int addMoney(int add);
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

