#pragma once
#include "WinApp.h"
#include "D2DApp.h"
#include "Scene.h"
#include "InputManager.h"

class Framework
{
public:
	Framework();
private:
	WinApp winApp;
	D2DApp d2dApp;
	InputManager inputManager;

public:
	void Run(Scene* startScene,const wchar_t* title, int width, int height, bool isFullScreen);

private:
	void StartGameLoop();

public:
	static Framework& GetInstance();
	WinApp& GetWinApp();
	D2DApp& GetD2DApp();
	InputManager& GetInputManager();
};
