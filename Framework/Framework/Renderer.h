#pragma once
#include "Component.h"
#include "ResourceManager.h"
#include "Transform.h"

//렌더링과 관련된 일을 할 객체
class Renderer :
	public Component
{
public:
	Renderer();
	Renderer(Sprite* startSprite, float alpha = 1.0f);
protected:
	Sprite* currentSprite;	//현재 표시할 스프라이트를 저장
	float alpha;
	bool initialized;		//스프라이트가 있는지

public:
	bool GetInitialized();
	Sprite& GetSprite();
	virtual void Update() {}
	virtual void Render(ID2D1HwndRenderTarget& renderTarget, Transform& transform);
};

