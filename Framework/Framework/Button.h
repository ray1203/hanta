#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
#include "Tower.h"
#include "FontObject.h"
class Button :
	public GameObject
{
public:
	int range = 0;
	int flag = 0;
	int t = 0;
	Button(const wchar_t* path, int x, int y,int t);
	AABBCollider col2;
	void Update();
	Tower* tower;
	GameObject* rangeI;
	FontObject* text;
};