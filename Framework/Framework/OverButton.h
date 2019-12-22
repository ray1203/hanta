#pragma once
#include "Button.h"
class OverButton :
	public Button
{
public:
	OverButton(const wchar_t* path, float colwidth, float colheight);
	void OnClick();
};

