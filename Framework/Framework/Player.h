#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
#include "TestObject.h"
#include "Scene.h"
#include "AnimationRenderer.h"
#include "SoundEvent.h"

//Player�� ���Ƿ� ������ ��ü�Դϴ�.
//���� ���� ������Ʈ�� GameObject��ü�� ��ӹ޾� �����Ͽ����մϴ�.
class Player :
	public GameObject
{
public:
	float moveSpeed;		

	AABBCollider col;		//�浹�� ������ ����
	TestObject* enemy;		//���� �� �ٸ� ��ü

	AnimationRenderer* animRenderer;		//�ִϸ��̼Ƿ�����. �ִϸ��̼��� ������ �� �ʿ�

	SoundEvent* se;		//�����̺�Ʈ
	
	Player();					//Player������
	virtual void Update();		//Update: �� ������ ȣ��˴ϴ�.
	virtual void LateUpdate();	//LateUpdate: �� ������ Update, Render�� ����� ���� ȣ��˴ϴ�.
};