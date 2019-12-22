#include "stdafx.h"
#include "OverButton.h"
#include "InputManager.h"
#include "GameScene.h"
OverButton::OverButton(const wchar_t* path, float colwidth, float colheight)
	:Button(path, colwidth, colheight)
{
}

void OverButton::OnClick()
{
	Scene::GetCurrentScene().ChangeScene(new GameScene());
}