#pragma once
#include "Button.h"
class ModeButton :
	public Button
{
public:
	ModeButton(const wchar_t* path, float colwidth, float colheight);
	void OnClick();
};

