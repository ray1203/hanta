#include "stdafx.h"
#include "CraftScene.h"
#include "button2.h"
void CraftScene::Initialize()
{

	button2* b2 = (button2*)PushBackGameObject(new button2(L"500 (1).jpg", 9, 23));
	b2->transform->SetPosition(300.0f, 400.0f);
	printf("¾À»ý¼º2");

}
