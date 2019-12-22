#pragma once
#include "Button.h"
#include "Scene.h"
#include "TowerButton.h"
class TmenuButton :
	public Button
{
public:
	TowerButton* b[13];
	int flag = 1;
	TmenuButton(const wchar_t* path, int colwidth, int colheight);
	void Update();
};