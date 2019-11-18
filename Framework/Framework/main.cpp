#include "stdafx.h"
#include "Framework.h"
#include "GameScene.h"
#include "Math.h"
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "korean");
	Framework& f = Framework::GetInstance();
	f.Run(new GameScene(), L"HanTa", 1280, 800, false);
	return 0;
}