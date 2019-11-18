#include "stdafx.h"
#include "Font.h"
#include "Framework.h"

Font::Font(const wchar_t* fontName, float fontSize, float red, float green, float blue, float alpha,  bool isBold)
	:fontWeight(DWRITE_FONT_WEIGHT_NORMAL), fontSize(fontSize),fontName(fontName),fontStretch(DWRITE_FONT_STRETCH_NORMAL),
	fontStyle(DWRITE_FONT_STYLE_NORMAL),textFormat(nullptr),colorBrush(nullptr)
{
	
	if (isBold)
		fontWeight = DWRITE_FONT_WEIGHT_BOLD;
	HRESULT hr = Framework::GetInstance().GetD2DApp().GetDwriteFactory().CreateTextFormat(
		fontName,
		NULL,
		fontWeight,
		fontStyle,
		fontStretch,
		fontSize,
		L"",
		&textFormat
	);
	if (!SUCCEEDED(hr))
		printf("폰트 생성 실패\n");
	D2D1::ColorF color(red, green, blue, alpha);
	hr = Framework::GetInstance().GetD2DApp().GetRenderTarget().CreateSolidColorBrush(
		color,
		&colorBrush
	);
	if (!SUCCEEDED(hr))
		printf("색상값 조정 실패\n");
}

Font::~Font()
{
	SAFE_RELEASE(textFormat);
	SAFE_RELEASE(colorBrush);
}
