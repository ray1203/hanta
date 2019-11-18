#pragma once
#include "GameObject.h"
#include "FontRenderer.h"
typedef std::string String;
class FontObject :
	public GameObject
{
public:
	FontObject();
	FontObject(String str, float posX, float posY);
	FontObject(String str, float posX, float posY, float scaleX, float scaleY);
	~FontObject();

	Font* font;						//자세한 설명은 Font.h 참고
	FontRenderer* fontRenderer;		//자세한 설명은 FontRenderer.h 참고
	String str;
};

