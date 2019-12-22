#pragma once
#include "Button.h"
class WaveButton :
	public Button
{
public:
	WaveButton(const wchar_t* path, int colwidth, int colheight);
	void OnClick();
};