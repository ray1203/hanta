#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
#include "CircleCollider.h"
class TestObject :
	public GameObject
{
public:
	TestObject();
public:
	CircleCollider col2;
	GameObject* player;

	void Update();
};

