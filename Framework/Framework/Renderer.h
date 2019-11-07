#pragma once
#include "Component.h"
#include "ResourceManager.h"
#include "Transform.h"

//�������� ���õ� ���� �� ��ü
class Renderer :
	public Component
{
public:
	Renderer();
	Renderer(Sprite* startSprite, float alpha = 1.0f);
protected:
	Sprite* currentSprite;	//���� ǥ���� ��������Ʈ�� ����
	float alpha;
	bool initialized;		//��������Ʈ�� �ִ���

public:
	bool GetInitialized();
	Sprite& GetSprite();
	virtual void Update() {}
	virtual void Render(ID2D1HwndRenderTarget& renderTarget, Transform& transform);
};

