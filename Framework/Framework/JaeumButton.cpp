#include "stdafx.h"
#include "JaeumButton.h"

JaeumButton::JaeumButton(const wchar_t* path, float colwidth, float colheight, PlayerData* playerData)
	:Button(path, colwidth, colheight), playerData(playerData)
{
}

void JaeumButton::OnClick()
{
	playerData->createJaeum();
	playerData->printJaeum();
}
