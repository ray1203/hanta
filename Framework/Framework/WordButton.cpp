#include "stdafx.h"
#include "WordButton.h"

WordButton::WordButton(const wchar_t* path, int x, int y)
	:GameObject(path), col2(*transform, 40.0f, 40.0f)
{
	transform->SetPosition(x * 40 + 20, y * 40 + 20);
}
