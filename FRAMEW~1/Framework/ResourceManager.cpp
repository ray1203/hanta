#include "stdafx.h"
#include "ResourceManager.h"
#include "Framework.h"

ResourceManager::~ResourceManager()
{
	for (auto& i : spriteList)
	{
		SAFE_RELEASE(i->bitmap);
		SAFE_DELETE(i);
	}
	spriteList.clear();
}

Sprite* ResourceManager::LoadBitmapFromFile(PCWSTR uri, UINT destinationWidth, UINT destinationHeight)
{
	//성공시 Sprite를, 실패시 nullptr을 반환
	HRESULT hr = S_OK;

	D2DApp& d2dApp = Framework::GetInstance().GetD2DApp();

	IWICBitmapDecoder* pDecoder = NULL;
	IWICBitmapFrameDecode* pSource = NULL;
	IWICStream* pStream = NULL;
	IWICFormatConverter* pConverter = NULL;
	IWICBitmapScaler* pScaler = NULL;

	Sprite* sprite = nullptr;

	for (auto& i : spriteList)
	{
		if (wcscmp(i->uri, uri) == 0)
		{
			return i;
		}
	}

	hr = d2dApp.GetImagingFactory().CreateDecoderFromFilename(uri, NULL, GENERIC_READ, WICDecodeMetadataCacheOnLoad, &pDecoder);

	if (SUCCEEDED(hr))
	{
		// Create the initial frame.
		hr = pDecoder->GetFrame(0, &pSource);
	}

	if (SUCCEEDED(hr))
	{
		// Convert the image format to 32bppPBGRA
		// (DXGI_FORMAT_B8G8R8A8_UNORM + D2D1_ALPHA_MODE_PREMULTIPLIED).
		hr = d2dApp.GetImagingFactory().CreateFormatConverter(&pConverter);
	}

	if (SUCCEEDED(hr))
	{
		// If a new width or height was specified, create an
		// IWICBitmapScaler and use it to resize the image.
		if (destinationWidth != 0 || destinationHeight != 0)
		{
			UINT originalWidth, originalHeight;
			hr = pSource->GetSize(&originalWidth, &originalHeight);
			if (SUCCEEDED(hr))
			{
				if (destinationWidth == 0)
				{
					FLOAT scalar = (FLOAT)destinationHeight / (FLOAT)originalHeight;
					destinationWidth = (UINT)(scalar * (FLOAT)(originalWidth));
				}
				else if (destinationHeight == 0)
				{
					FLOAT scalar = (FLOAT)(destinationWidth) / (FLOAT)(originalWidth);
					destinationHeight = (UINT)(scalar * (FLOAT)(originalHeight));
				}

				hr = d2dApp.GetImagingFactory().CreateBitmapScaler(&pScaler);
				if (SUCCEEDED(hr))
				{
					hr = pScaler->Initialize(pSource, destinationWidth, destinationHeight, WICBitmapInterpolationModeCubic);
				}

				if (SUCCEEDED(hr))
				{
					hr = pConverter->Initialize(
						pScaler,
						GUID_WICPixelFormat32bppPBGRA,
						WICBitmapDitherTypeNone,
						NULL,
						0.f,
						WICBitmapPaletteTypeMedianCut
					);
				}
			}
		}
		else // Don't scale the image.
		{
			hr = pConverter->Initialize(
				pSource,
				GUID_WICPixelFormat32bppPBGRA,
				WICBitmapDitherTypeNone,
				NULL,
				0.f,
				WICBitmapPaletteTypeMedianCut
			);
		}
	}
	if (SUCCEEDED(hr))
	{
		sprite = new Sprite();
		// Create a Direct2D bitmap from the WIC bitmap.
		hr = d2dApp.GetRenderTarget().CreateBitmapFromWicBitmap(
			pConverter,
			NULL,
			&sprite->bitmap
		);

		sprite->uri = uri;

		spriteList.push_back(sprite);
	}
	else
	{
		printf("이미지 로드 실패.\n");
	}

	SAFE_RELEASE(pDecoder);
	SAFE_RELEASE(pSource);
	SAFE_RELEASE(pStream);
	SAFE_RELEASE(pConverter);
	SAFE_RELEASE(pScaler);

	return sprite;
}

Vector2 Sprite::GetSize()
{
	D2D1_SIZE_F s = bitmap->GetSize();
	return Vector2(s.width,s.height);
}
