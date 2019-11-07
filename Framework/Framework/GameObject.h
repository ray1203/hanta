#pragma once
#include "stdafx.h"
#include "Renderer.h"

//게임오브젝트 객체입니다.
//게임에서 표현될 모든 객체는 반드시 GameObject를 상속받은 객체로 생성되어야 합니다.
//게임에서 표현될 모든 객체는 반드시 Scene에 PushBack되어야 정상적으로 관리됩니다.

class GameObject
{
public:
	//GameObject() 처럼 호출할 수 있는 생성자입니다. 이미지 로드가 필요없을경우 사용합니다.
	GameObject(Vector2 position = Vector2(), float angle = 0.0f, Vector2 scale = Vector2());

	//GameObject(L"image.png"); 처럼 호출할 수 있는 생성자입니다. 하나의 이미지를 로드할 경우 사용합니다.
	//TestObject.h, TestObject.cpp를 참고하세요.
	GameObject(const wchar_t* imagePath, Vector2 position = Vector2(), float angle = 0.0f, Vector2 scale = Vector2(1.0f,1.0f));
	
	//GameObject(new AnimationRenderer()); 처럼 호출할 수 있는 생성자입니다. 애니메이션을 이용할 경우 사용합니다.
	//Player.h, Player.cpp를 참고하세요.
	GameObject(Renderer* renderer, Vector2 position = Vector2(), float angle = 0.0f, Vector2 scale = Vector2(1.0f, 1.0f));
	virtual ~GameObject();
private:
	bool isActive;
public:
	std::string name;		//객체 고유의 이름값
	Transform* transform;	//위치, 회전값, 크기값 등을 가짐
	Renderer* renderer;		//Render를 관리할 객체입니다. 아마 직접 건드실 일은 많이 없을 것입니다.

public:
	virtual void Start() {}				//오브젝트가 처음 만들었을 때 호출
	virtual void Update() {}			//매 프레임마다 호출
	virtual void LateUpdate() {}		//Update가 호출된 이후 호출
	virtual void OnDestroy() {}			//오브젝트가 삭제될 때 호출

public:
	bool GetActive();
};

