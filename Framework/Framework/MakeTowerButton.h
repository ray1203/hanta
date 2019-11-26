#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
#include "InputManager.h"
#include "PlayerData.h"
typedef std::string String;
class MakeTowerButton :
	public GameObject
{

public:/*
	enum attribute_kr
	{
		힘 = 1,
		환상,
		자연,
		인공,
		개념,
		무계열,
	};*/
	bool flag = false;
	MakeTowerButton(const wchar_t* path);
	AABBCollider col2;
	PlayerData* playerData;
	String buffer;
	void Update();
	void destroy();
	void getBuffer(String b);
};

