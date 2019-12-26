#pragma once
#include"Button.h"
#include "PlayerData.h"
class ConButton :
	public Button
{
public:

	int line;
	ConButton(const wchar_t* path, int colwidth, int colheight,int line);
	void OnClick();
	PlayerData* playdata;
};