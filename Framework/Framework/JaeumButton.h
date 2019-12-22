#pragma once
#include "Button.h"
#include "PlayerData.h"
class JaeumButton :
	public Button
{
	PlayerData* playerData;
public:
	JaeumButton(const wchar_t* path, float colwidth, float colheight, PlayerData* playerData);
	void OnClick();
};