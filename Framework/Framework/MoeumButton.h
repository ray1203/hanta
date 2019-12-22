#pragma once
#include "Button.h"
#include "PlayerData.h"
class MoeumButton :
	public Button
{
	PlayerData* playerData;
public:
	MoeumButton(const wchar_t* path, float colwidth, float colheight, PlayerData* playerData);
	void OnClick();
};

