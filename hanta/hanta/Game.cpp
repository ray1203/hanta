#include "pch.h"
#include "Game.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::run() {
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	w.createWindow(L"HanTa", 1280, 800);
	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}