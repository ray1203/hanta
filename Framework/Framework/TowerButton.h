#pragma once
#include "Tower.h"
#include "FontObject.h"
class TowerButton :
	public Button
{
	int range = 0;
	int flag = 0;
	int t = 0;
	Tower* tower;
	GameObject* rangeI;
	FontObject* text;
public:
	TowerButton(const wchar_t* path, float colwidth, float colheight, int t);
	~TowerButton();
	void Update();
};