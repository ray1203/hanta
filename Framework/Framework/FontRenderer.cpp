#include "stdafx.h"
#include "FontRenderer.h"
#include "Framework.h"

FontRenderer::FontRenderer(wchar_t text[], Font* font )
	: font(font), text(text)
{
	initialized = true;
}

void FontRenderer::Render(ID2D1HwndRenderTarget& renderTarget, Transform& transform)
{
	if (!text||!font||!font->textFormat||!font->colorBrush)
	{
		return;
	}

	WinApp& winApp = Framework::GetInstance().GetWinApp();
	int screenWidth = winApp.GetScreenWidth();
	int screenHeight = winApp.GetScreenHeight();

	Point positioningCenter;
	positioningCenter.x = transform.position.x - transform.positioningCenter.x;
	positioningCenter.y = transform.position.y - transform.positioningCenter.y;

	D2D1_RECT_F rect;
	rect.left = positioningCenter.x - screenWidth * 0.5f;
	rect.top = positioningCenter.y - screenHeight * 0.5f;
	rect.right = positioningCenter.x + screenWidth * 0.5f;
	rect.bottom = positioningCenter.y + screenHeight * 0.5f;

	Point scalingCenter;
	scalingCenter.x = positioningCenter.x + transform.scalingCenter.x;
	scalingCenter.y = positioningCenter.y + transform.scalingCenter.y;

	Point rotatingCenter;
	rotatingCenter.x = positioningCenter.x + transform.rotatingCenter.x;
	rotatingCenter.y = positioningCenter.y + transform.rotatingCenter.y;

	renderTarget.SetTransform(
		D2D1::Matrix3x2F::Scale(
			transform.scale.x,
			transform.scale.y,
			scalingCenter)
		* D2D1::Matrix3x2F::Rotation(
			transform.rotatingAngle,
			rotatingCenter
		));
	UINT32 len = wcslen(text);
	renderTarget.DrawTextW(text, len, font->textFormat,
		D2D1::RectF(positioningCenter.x, positioningCenter.y, positioningCenter.x+640.0f, positioningCenter.y+415.0f),
		font->colorBrush);
}
