#pragma once
#include "GameObject.h"
#include "BackGround.h"
#include "TimeManager.h"
#include "PlayerData.h"
#include "MoeumButton.h"
#include "JaeumButton.h"
#include "InputManager.h"
#include "FontObject.h"
#include<conio.h>
//#include "Scene.h"
typedef std::string String;
class CraftTable :
	public GameObject
{
public:
	CraftTable();
	virtual void Update();
	FontObject* jaeumText;
	FontObject* moeumText;
	FontObject* eumjulText;
	FontObject* insertText;

	PlayerData* playerData;
	BackGround* background;
	MoeumButton* mButton;
	JaeumButton* jButton;
	bool isActive;
	void show();
	void hide();
	void change();
	String buffer;
	void input();
	void updateText();

};

