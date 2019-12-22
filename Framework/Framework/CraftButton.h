#pragma once
#include "Button.h"
#include "CraftTable.h"
#include "AABBCollider.h"
#include "InputManager.h"
class CraftButton :
	public Button
{
	CraftTable* craftTable;
	bool isActive = false;
public:
	CraftButton(const wchar_t* path, float colwidth, float colheight, CraftTable* ct);
	void OnClick();
};