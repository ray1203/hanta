#include "stdafx.h"
#include "conbutton.h"
#include "GameScene.h"
conbutton::conbutton(const wchar_t* path, int colwidth, int colheight, int line)
	:Button(path, colwidth, colheight)
{
	this->line = line;
	GameScene& s = (GameScene&)Scene::GetCurrentScene();
	playdata = s.GetPlayerData();
}
void conbutton::OnClick()
{
	playdata->nowdic = line;
}
