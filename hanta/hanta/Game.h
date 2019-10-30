#pragma once
#include "Window.h"
#include "pch.h"
class Game
{
	Window w;
public:
	Game();
	~Game();

	void run();
};