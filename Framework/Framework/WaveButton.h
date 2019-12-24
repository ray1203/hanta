#pragma once
#include "Button.h"
class WaveButton :
	public Button
{
public:
	WaveButton(const wchar_t* path, float colwidth, float colheight);
	void OnClick();
};