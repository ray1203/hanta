#pragma once
#include "Button.h"
#include "PlayerData.h"
#include "ConButton.h"
#include "FontObject.h"
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
	ConButton* con;
	ConButton* nat;
	GameObject* g;
	ConButton* hum;
	ConButton* fan;
	ConButton* pow;
	ConButton* no;
	FontObject* dic;
};