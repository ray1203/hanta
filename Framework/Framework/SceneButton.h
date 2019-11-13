#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
#include "Scene.h"
class SceneButton:
	public GameObject
{
	Scene* s;
public:
	SceneButton(const wchar_t* path, int x, int y, float width, float height, Scene* s);
	AABBCollider col2;
	void Update();
	int isclick = 0;
};

