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

	Font* font;						//�ڼ��� ������ Font.h ����
	FontRenderer* fontRenderer;		//�ڼ��� ������ FontRenderer.h ����
	String str;
};

