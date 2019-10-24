#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
#include "TestObject.h"
#include "Scene.h"
#include "AnimationRenderer.h"
#include "SoundEvent.h"

//Player는 임의로 생성한 객체입니다.
//게임 내의 오브젝트는 GameObject객체를 상속받아 생성하여야합니다.
class Player :
	public GameObject
{
public:
	float moveSpeed;		

	AABBCollider col;		//충돌을 관리할 변수
	TestObject* enemy;		//게임 내 다른 객체

	AnimationRenderer* animRenderer;		//애니메이션렌더러. 애니메이션을 구현할 때 필요

	SoundEvent* se;		//사운드이벤트
	
	Player();					//Player생성자
	virtual void Update();		//Update: 매 프레임 호출됩니다.
	virtual void LateUpdate();	//LateUpdate: 매 프레임 Update, Render가 실행된 이후 호출됩니다.
};