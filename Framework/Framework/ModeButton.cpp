#include "stdafx.h"
#include "ModeButton.h"
#include "GameScene.h"

ModeButton::ModeButton(const wchar_t* path, float colwidth, float colheight)
	:Button(path, colwidth, colheight)
{
}

void ModeButton::OnClick() {
	GameScene& s = (GameScene&)Scene::GetCurrentScene();
	s.GetCraftTable()->modeChange();
}