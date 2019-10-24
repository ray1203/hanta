#include "stdafx.h"
#include "Framework.h"
#include "TimeManager.h"
#include "Audio.h"

Framework::Framework()
{
}

void Framework::Run(Scene* startScene, const wchar_t* title, int width, int height, bool isFullScreen)
{
	if (SUCCEEDED(CoInitialize(NULL)))
	{
		
		if (winApp.Initialize(title, width, height, isFullScreen))
		{
			if (d2dApp.Initialize())
			{
				bool audioInitialized=Audio::GetInstance()->Initialize();
				Scene::currentScene = startScene;
				Scene::currentScene->Initialize();
				StartGameLoop();
				SAFE_DELETE(Scene::currentScene);
				SAFE_DELETE(Scene::nextScene);
				if (audioInitialized)
					Audio::GetInstance()->Uninitialize();
				d2dApp.Uninitialize();
			}
		}
		CoUninitialize();
	}
}

void Framework::StartGameLoop()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	d2dApp.LoadBitmapFromFile(L"a.png", 400, 0, &d2dApp.example);

	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		//Check Input
		InputManager:: UpdateKeyState();
		TimeManager::UpdateTime();
		//Update World
		Scene::currentScene->Update();
		Scene::currentScene->Render();

		//Change Scene
		Scene::SwapScene();
	}
}

Framework& Framework::GetInstance()
{
	static Framework f;
	return f;
}

WinApp& Framework::GetWinApp()
{
	return winApp;
}

D2DApp& Framework::GetD2DApp()
{
	return d2dApp;
}

InputManager& Framework::GetInputManager()
{
	return inputManager;
}
