#include "stdafx.h"
#include "TestScene2.h"

void TestScene2::Initialize()
{
	GameObject* g = PushBackGameObject(new GameObject(L"c.png"));
	g->transform->SetPosition(300.0f, 400.0f);

}
