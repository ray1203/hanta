#include "stdafx.h"
#include "Player.h"
#include "InputManager.h"
#include "GameScene.h"
#include "AnimationRenderer.h"
#include "ListAnimation.h"
#include "SheetAnimation.h"

Player::Player()
	:GameObject(animRenderer = new AnimationRenderer()),		//GameObject(animRenderer = new AnimationRenderer), �ִϸ��̼Ƿ������� ����մϴ�. �Ϲ����� �̹��� �������� ����Ͻô� ���� TestObject�� �����ϼ���.
	moveSpeed(10.0f),
	col(*transform, Vector2(42.0f, 128.0f))
{
	//�ִϸ��̼� ���� ���
	//ListAnimation(���� ���������� �ִϸ��̼��� ����)
	//SheetAnimation(���� ������ �߶� �ִϸ��̼��� ����, �ִϸ��̼� ��Ʈ ����)
	//�� �� �ϳ��� �����Ҵ��� ���� ����
	//~Animation Ŭ������ �� �ִϸ��̼��� ����ϴ� Ŭ�����Դϴ�.
	//ó�� �μ� state�� �ִϸ��̼� ��� ��ȣ�� �ǹ��մϴ�.(enum������ ���� ����)
	//state ���� ��ġ�� �ʰ� ���ּ���.
	ListAnimation* lanim = new ListAnimation(0, 1.0f);		//�ִϸ��̼� ����, �ش� �ִϸ��̼��� state�� 0, �ʴ� 1ȸ �׸�
	lanim->PushBackSprite(L"a.png");				//�̹��� ���
	lanim->PushBackSprite(L"b.png");
	SheetAnimation* sanim = new SheetAnimation(1, 16.0f,L"sheet.png",128,128,16);	//�ִϸ��̼� ����, �ش� �ִϸ��̼��� state�� 1, �ʴ� 16ȸ �׸�
																					//pixelwidth, pixelheight�� �ִϸ��̼��� �߸� ����, ���θ� �ǹ��մϴ�.
																					//SheetAnimation.h ����

	//�ִϸ��̼��� AnimationRenderer�� ����ؾ� �ִϸ��̼� ��� ����
	//AnimationRenderer�� �ش� ��ü�� ��ϵ� ��� �ִϸ��̼��� �����մϴ�.
	animRenderer->PushBackAnimation(lanim);
	animRenderer->PushBackAnimation(sanim);

	//���� ����ϱ�
	//SoundEventŬ������ �����մϴ�.
	//SoundEvent��ü �ϳ��� �ϳ��� ���� ������ ����մϴ�.
	se = new SoundEvent();		//se = new SoundEvent(L"test.wav"); ó�� ����� ���� �ֽ��ϴ�.
	se->LoadFile(L"test.wav");		

	//��ü�� ��ġ, ����, ũ�������� transform�� ��ϵǾ��ֽ��ϴ�. Transform.h, GameObject.h ����
	transform->SetPosition(300.0f, 300.0f);	//Player�� �ʱ� ��ġ ����
	
	//���� Scene�� ������ �����ôٸ� �Ʒ��� ���� ����Ͻø� �˴ϴ�.
	GameScene& scene = (GameScene&)Scene::GetCurrentScene();
}

void Player::Update()
{
	//Ű �Է¹ޱ�
	//InputManager::GetMyKeyState(Ű��), 0���� Ŭ ���: ����, 0: ������ ����, -1: Ű�� ��� �� ������
	if (InputManager::GetMyKeyState(VK_UP))
		transform->position.y -= moveSpeed;
	if (InputManager::GetMyKeyState(VK_DOWN))
		transform->position.y += moveSpeed;
	if (InputManager::GetMyKeyState(VK_RIGHT))
		transform->position.x += moveSpeed;
	if (InputManager::GetMyKeyState(VK_LEFT))
		transform->position.x -= moveSpeed; 

	//Scene ��ȯ
	if (InputManager::GetMyKeyState(VK_SPACE))
		Scene::ChangeScene(new GameScene());

	

	//�Է�ó��, Animation ����
	if (InputManager::GetKeyDown('A'))		//GetKeyDown: Ű�� �� ������ ������ true
	{
		if (animRenderer->currentState==1)
		{
			animRenderer->ChangeAnimation(0);	//ChangeAnim(state)�� ���� �ִϸ��̼� ��ȯ ����
		}
		else
		{
			animRenderer->ChangeAnimation(1);
		}
	}

	if (InputManager::GetKeyDown('S'))		//SŰ�� �� ������ ��� ��� ����
	{
		se->Play();
	}
	if (InputManager::GetKeyUp('S'))		//SŰ�� �� ������ ��� ��� ����
	{
		se->Stop();							//se->Pause()�Լ� ���� �Ͻ�����
	}
}

void Player::LateUpdate()
{
	static int count = 0;
	//�浹ó���� Update���� �̵��� �� ���� �� LateUpdate���� �������־�� �����մϴ�.
	//(GameObject�� Update ���� ������ ���� ���� �߻� ���ɼ�O)

	//��ü�� CircleCollider Ȥ�� AABBCollider�� ����� ��, �浹ó���� ���ݴϴ�.
	//OBB, ĸ�� �� �ٸ� ������ �浹ü�� ����ϰ� ������ ��� ���� �������ּž� �մϴ�.
	//��ü�� �浹���� ����� ��ü�� �����Ͽ� �浹�� �����ϴ� �͵� ��õ�帳�ϴ�.
	//collider�� intersected�Լ��� ȣ���Ͽ� �浹 ���θ� Ȯ���� �� �ֽ��ϴ�.
	if (col.Intersected(enemy->col2))
	{
		printf("�ƾ߾� �浹����%d\n",count++);
	}
}
