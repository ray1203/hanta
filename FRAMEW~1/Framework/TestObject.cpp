#include "stdafx.h"
#include "TestObject.h"
#include "InputManager.h"

TestObject::TestObject()
	:GameObject(L"circle.png"),		//���ӿ�����Ʈ�� �����մϴ�.
	col2(*transform,64.0f)
{
}

void TestObject::Update()
{
	//InputManager::GetMouseVector2(), InputManager::GetMouseX()�� ���� ���콺 ��ġ�� ��ȯ���� �� �ֽ��ϴ�.
	if (col2.Intersected(InputManager::GetMouseVector2()))	//�浹ó��, Player�� �����ϼ���.
		printf("����\n");
}
