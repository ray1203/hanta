#include "stdafx.h"
#include "MoeumButton.h"

MoeumButton::MoeumButton(const wchar_t* path, float colwidth, float colheight, PlayerData* playerData)
	:Button(path, colwidth, colheight), playerData(playerData)
{
}

void MoeumButton::OnClick()
{
	playerData->createMoeum();
	playerData->printMoeum();
}