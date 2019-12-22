#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
class Button
	:public GameObject
{
public:
	AABBCollider col;

	Button(const wchar_t* path, float colwidth, float colheight);
	~Button();

	void Update();
	virtual void OnClick();
};