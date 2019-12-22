#pragma once
#include "Button.h"
#include "PlayerData.h"
typedef std::string String;
class MakeTowerButton :
	public Button
{

public:
	bool flag = false;
	MakeTowerButton(const wchar_t* path, float colwidth, float colheight);
	PlayerData* playerData;
	String buffer;
	void OnClick();
	void setBuffer(String b);
};

