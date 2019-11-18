#include "stdafx.h"
#include "FontObject.h"
FontObject::FontObject()
	:GameObject(fontRenderer = new FontRenderer()), str("Hello")
{
	std::wstring ws;
	for (int i = 0; i < str.length(); i++) {
		ws += wchar_t(str[i]);
	}
	const wchar_t* wchar = ws.c_str();
	wchar_t* result = const_cast<wchar_t*>(wchar);
	font = new Font(L"Arial");						//폰트, 색상 등을 지니는 Font 클래스 생성(Font.h 참고), 기본 크기 20pt
	fontRenderer->font = this->font;				//텍스트의 속성을 지정해줍니다.
	fontRenderer->text = result;						//텍스트의 내용을 지정해줍니다.
	transform->SetPosition(300.0f, 300.0f);			//위치 지정
	transform->SetRotation(0.0f);					//각도 지정
	transform->SetScale(3.0f, 1.0f);				//크기 지정 모두 가능합니다.
}

FontObject::FontObject(String str, float posX, float posY):GameObject(fontRenderer=new FontRenderer()), str(str)
{
	setlocale(LC_ALL, "korean");
	int C_STR_BUFFER_SIZE = str.size() + 1;
	wchar_t *result = new wchar_t[str.size()+1];
	MultiByteToWideChar(CP_ACP, NULL, str.c_str(), -1, result, str.size()+1);
	//std::cout << "giving:" << str<<"||";
	//wprintf(L"%s\n", result);

	font = new Font(L"Arial");				
	font->fontSize = 10.0f;
	fontRenderer->font = this->font;			
	fontRenderer->text = result;				
	transform->SetPosition(posX, posY);			
	transform->SetRotation(0.0f);				
	transform->SetScale(3.0f, 1.0f);			
}

FontObject::FontObject(String str, float posX, float posY , float scaleX, float scaleY) :GameObject(fontRenderer = new FontRenderer()), str(str)
{
	/*
	std::wstring ws;
	for (int i = 0; i < str.length(); i++) {
		ws += wchar_t(str[i]);
	}
	const wchar_t* wchar = ws.c_str();
	wchar_t* result = const_cast<wchar_t*>(wchar);
	font = new Font(L"Arial");							
	fontRenderer->font = this->font;					
	fontRenderer->text = result;						
	transform->SetPosition(posX, posY);					
	transform->SetRotation(0.0f);						
	transform->SetScale(scaleX, scaleY);	*/			
}

FontObject::~FontObject()
{
	SAFE_DELETE(font);
}
