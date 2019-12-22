#include "stdafx.h"
#include "Button.h"
#include "InputManager.h"

Button::Button(const wchar_t* path, float colwidth, float colheight)
	:GameObject(path), col(*transform, colwidth, colheight)
{
}

Button::~Button()
{
}

void Button::Update() {
	if (col.Intersected(InputManager::GetMouseVector2())) {
		HCURSOR hCursor = LoadCursor(0, IDC_HAND);
		hCursor = SetCursor(hCursor);
	}

	if (InputManager::GetMyKeyState(VK_LBUTTON) == -1 && col.Intersected(InputManager::GetMouseVector2())) {
		OnClick();
	}
}

void Button::OnClick() {

}