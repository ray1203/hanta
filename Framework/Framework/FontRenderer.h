#pragma once
#include "Renderer.h"
#include "Font.h"

//Renderer를 상속받는 FontRendrer함수입니다.
class FontRenderer :
	public Renderer
{
public:
	FontRenderer(wchar_t text[] = nullptr, Font* font = nullptr);
	Font* font;
	wchar_t* text;
	virtual void Render(ID2D1HwndRenderTarget& renderTarget, Transform& transform);
};

