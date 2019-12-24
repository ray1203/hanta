#include "stdafx.h"
#include "WaveButton.h"
#include "GameScene.h"
WaveButton::WaveButton(const wchar_t* path, float colwidth, float colheight)
:Button(path, colwidth, colheight)
{
}

void WaveButton::OnClick()
{
	GameScene& s = (GameScene&)Scene::GetCurrentScene();
	(s.GetEM())->wave++;
	(s.GetEM())->flag = 0;
	s.Destroy(this);
}