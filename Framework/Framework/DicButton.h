#pragma once
#include "Button.h"
#include "PlayerData.h"
#include"conbutton.h"
#include"FontObject.h"
class DicButton :
	public Button
{
public:

	int lastdic = 0;
	DicButton(const wchar_t* path, int colwidth, int colheight);
	void Update();
	void OnClick();

	PlayerData* playdata;
	GameObject* onselect;
	conbutton* con;
	conbutton* nat;
	GameObject* g;
	conbutton* hum;
	conbutton* fan;
	conbutton* pow;
	conbutton* no;
	FontObject* dic;
};