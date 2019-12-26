#include "stdafx.h"
#include "ConButton.h"
#include "GameScene.h"
ConButton::ConButton(const wchar_t* path, int colwidth, int colheight,int line):Button(path, colwidth, colheight)
{
	this->line = line;
	GameScene& s = (GameScene&)Scene::GetCurrentScene();
	playdata = s.GetPlayerData();
}
void ConButton::OnClick()
{
	playdata->nowdic = line;
}
