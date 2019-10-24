#include "stdafx.h"
#include "Player.h"
#include "InputManager.h"
#include "GameScene.h"
#include "AnimationRenderer.h"
#include "ListAnimation.h"
#include "SheetAnimation.h"

Player::Player()
	:GameObject(animRenderer = new AnimationRenderer()),		//GameObject(animRenderer = new AnimationRenderer), 애니메이션렌더러를 사용합니다. 일반적인 이미지 렌더러를 사용하시는 것은 TestObject를 참고하세요.
	moveSpeed(10.0f),
	col(*transform, Vector2(42.0f, 128.0f))
{
	//애니메이션 적용 방법
	//ListAnimation(사진 여러장으로 애니메이션을 만듦)
	//SheetAnimation(사진 한장을 잘라서 애니메이션을 만듦, 애니메이션 시트 참조)
	//둘 중 하나를 동적할당을 통해 생성
	//~Animation 클래스는 한 애니메이션을 담당하는 클래스입니다.
	//처음 인수 state는 애니메이션 등록 번호를 의미합니다.(enum등으로 관리 가능)
	//state 값이 겹치지 않게 해주세요.
	ListAnimation* lanim = new ListAnimation(0, 1.0f);		//애니메이션 생성, 해당 애니메이션의 state는 0, 초당 1회 그림
	lanim->PushBackSprite(L"a.png");				//이미지 등록
	lanim->PushBackSprite(L"b.png");
	SheetAnimation* sanim = new SheetAnimation(1, 16.0f,L"sheet.png",128,128,16);	//애니메이션 생성, 해당 애니메이션의 state는 1, 초당 16회 그림
																					//pixelwidth, pixelheight는 애니메이션이 잘릴 가로, 세로를 의미합니다.
																					//SheetAnimation.h 참고

	//애니메이션을 AnimationRenderer에 등록해야 애니메이션 사용 가능
	//AnimationRenderer는 해당 객체에 등록된 모든 애니메이션을 관리합니다.
	animRenderer->PushBackAnimation(lanim);
	animRenderer->PushBackAnimation(sanim);

	//사운드 사용하기
	//SoundEvent클래스를 생성합니다.
	//SoundEvent객체 하나는 하나의 음악 파일을 담당합니다.
	se = new SoundEvent();		//se = new SoundEvent(L"test.wav"); 처럼 사용할 수도 있습니다.
	se->LoadFile(L"test.wav");		

	//객체의 위치, 각도, 크기조정은 transform에 등록되어있습니다. Transform.h, GameObject.h 참고
	transform->SetPosition(300.0f, 300.0f);	//Player의 초기 위치 설정
	
	//현재 Scene을 얻어오고 싶으시다면 아래와 같이 사용하시면 됩니다.
	GameScene& scene = (GameScene&)Scene::GetCurrentScene();
}

void Player::Update()
{
	//키 입력받기
	//InputManager::GetMyKeyState(키값), 0보다 클 경우: 눌림, 0: 눌리지 않음, -1: 키를 방금 막 떼었음
	if (InputManager::GetMyKeyState(VK_UP))
		transform->position.y -= moveSpeed;
	if (InputManager::GetMyKeyState(VK_DOWN))
		transform->position.y += moveSpeed;
	if (InputManager::GetMyKeyState(VK_RIGHT))
		transform->position.x += moveSpeed;
	if (InputManager::GetMyKeyState(VK_LEFT))
		transform->position.x -= moveSpeed; 

	//Scene 전환
	if (InputManager::GetMyKeyState(VK_SPACE))
		Scene::ChangeScene(new GameScene());

	

	//입력처리, Animation 변경
	if (InputManager::GetKeyDown('A'))		//GetKeyDown: 키를 막 눌렀을 때에만 true
	{
		if (animRenderer->currentState==1)
		{
			animRenderer->ChangeAnimation(0);	//ChangeAnim(state)를 통해 애니메이션 전환 가능
		}
		else
		{
			animRenderer->ChangeAnimation(1);
		}
	}

	if (InputManager::GetKeyDown('S'))		//S키가 막 눌렸을 경우 재생 시작
	{
		se->Play();
	}
	if (InputManager::GetKeyUp('S'))		//S키가 막 눌렸을 경우 재생 멈춤
	{
		se->Stop();							//se->Pause()함수 사용시 일시정지
	}
}

void Player::LateUpdate()
{
	static int count = 0;
	//충돌처리는 Update에서 이동이 다 끝난 후 LateUpdate에서 시행해주어야 안전합니다.
	//(GameObject의 Update 실행 순서에 따라 오류 발생 가능성O)

	//객체에 CircleCollider 혹은 AABBCollider를 등록한 후, 충돌처리를 해줍니다.
	//OBB, 캡슐 등 다른 형태의 충돌체를 사용하고 싶으신 경우 직접 구현해주셔야 합니다.
	//물체의 충돌만을 담당할 객체를 생성하여 충돌을 관리하는 것도 추천드립니다.
	//collider의 intersected함수를 호출하여 충돌 여부를 확인할 수 있습니다.
	if (col.Intersected(enemy->col2))
	{
		printf("아야야 충돌중임%d\n",count++);
	}
}
