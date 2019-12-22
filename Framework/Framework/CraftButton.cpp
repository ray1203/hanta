#include "stdafx.h"
#include "CraftButton.h"
#include "GameScene.h"

CraftButton::CraftButton(const wchar_t* path,  float colwidth, float colheight, CraftTable* ct)
	:Button(path, colwidth, colheight), craftTable(ct)
{
}

void CraftButton::OnClick()
{
	GameScene& s = (GameScene&)Scene::GetCurrentScene();
	if (isActive) {
		s.GetCraftTable()->hide();
		s.GetPlayerData()->resume();
	}
	else {
		s.GetCraftTable()->show();
		s.GetPlayerData()->pause();
	}
	isActive = !isActive;
}
