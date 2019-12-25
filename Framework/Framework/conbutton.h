#pragma once
#include"Button.h"
#include "PlayerData.h"
class conbutton :
	public Button
{
public:

	int line;
	conbutton(const wchar_t* path, int colwidth, int colheight,int line);
	void OnClick();
	PlayerData* playdata;
};