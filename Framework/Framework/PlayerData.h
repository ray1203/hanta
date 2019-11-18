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
	GameObject* remainlife1;
	GameObject* remainlife2;
	String m_ChoSungTbl = "��������������������������������������";
	String m_JungSungTbl = "�������¤äĤŤƤǤȤɤʤˤ̤ͤΤϤФѤҤ�";
	String m_JongSungTbl = "  ������������������������������������������������������";
	ushort m_UniCodeHangulBase = 0xAC00;
	ushort m_UniCodeHangulLast = 0xD79F;
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

	String MergeJaso(String choSung, String jungSung, String jongSung);
	String sprintJaeum();
	String sprintMoeum();
	void notifyChange();

	void pause();
	void resume();

};

