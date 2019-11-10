#pragma once
#include "Component.h"
#include "ResourceManager.h"
#include "Transform.h"

//�������� ���õ� ���� �� ��ü
class Renderer :
	public Component
{
	int width, height;
public:
	Renderer();
	Renderer(Sprite* startSprite, float alpha = 1.0f);
protected:
	Sprite* currentSprite;	//���� ǥ���� ��������Ʈ�� ����
	float alpha;
	bool initialized;		//��������Ʈ�� �ִ���

public:
	bool GetInitialized();
	int GetWidth();
	int GetHeight();
	Sprite& GetSprite();
	virtual void Update() {}
	virtual void Render(ID2D1HwndRenderTarget& renderTarget, Transform& transform);
	void changeAlpha(float ap);
};

