#pragma once
#include "GameObject.h"
#include "BackGround.h"
#include "TimeManager.h"
#include "PlayerData.h"
#include "MoeumButton.h"
#include "JaeumButton.h"
//#include "Scene.h"
class CraftTable :
	public GameObject
{
public:
	CraftTable();
	PlayerData* playerData;
	BackGround* background;
	MoeumButton* mButton;
	JaeumButton* jButton;
	bool isActive;
	void show();
	void hide();
	void change();

};

