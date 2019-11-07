#include "stdafx.h"
#include "AnimationRenderer.h"
#include "TimeManager.h"

AnimationRenderer::AnimationRenderer()
	:currentState(0), currentAnimation(nullptr)
{
	initialized = true;
}

AnimationRenderer::~AnimationRenderer()
{
	for (auto& i : animations)
		SAFE_DELETE(i);
	animations.clear();
}

void AnimationRenderer::Render(ID2D1HwndRenderTarget& renderTarget, Transform& transform)
{
	if (!currentAnimation)
		return;
	currentSprite = currentAnimation->UpdateAnim();
	if (!currentSprite || !currentSprite->bitmap)
	{
		return;
	}

	Vector2 size;
	size = currentAnimation->GetAnimationSize();

	Point positioningCenter;
	positioningCenter.x = transform.position.x - transform.positioningCenter.x;
	positioningCenter.y = transform.position.y - transform.positioningCenter.y;

	D2D1_RECT_F rect;
	rect.left = positioningCenter.x - size.x * 0.5f;
	rect.top = positioningCenter.y - size.y * 0.5f;
	rect.right = positioningCenter.x + size.x * 0.5f;
	rect.bottom = positioningCenter.y + size.y * 0.5f;


	D2D1_RECT_F sourceRect;
	sourceRect.left = 0.0f;
	sourceRect.right = size.x;
	sourceRect.top = 0.0f;
	sourceRect.bottom = size.y;
	currentAnimation->SetSourceRect(sourceRect);
	//printf("%.2f, %.2f, %.2f, %.2f\n", sourceRect.left, sourceRect.right, sourceRect.top, sourceRect.bottom);

	Point scalingCenter;
	scalingCenter.x = positioningCenter.x + transform.scalingCenter.x;
	scalingCenter.y = positioningCenter.y + transform.scalingCenter.y;

	Point rotatingCenter;
	rotatingCenter.x = positioningCenter.x + transform.rotatingCenter.x;
	rotatingCenter.y = positioningCenter.y + transform.rotatingCenter.y;

	renderTarget.SetTransform(
		D2D1::Matrix3x2F::Scale(
			transform.scale.x,
			transform.scale.y,
			scalingCenter)
		* D2D1::Matrix3x2F::Rotation(
			transform.rotatingAngle,
			rotatingCenter
		));
	renderTarget.DrawBitmap(currentSprite->bitmap, &rect, alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, &sourceRect);
}

void AnimationRenderer::ChangeAnimation(int state)
{
	Animation* temp = FindAnimationByState(state);
	if (temp)
	{
		currentState = state;
		currentAnimation = temp;
		currentAnimation->Reset();
	}
	else
	{
		printf("존재하지 않는 Animation state입니다.\n");
	}
}

void AnimationRenderer::PushBackAnimation(Animation* anim)
{
	animations.push_back(anim);
	if (!currentSprite)
	{
		ChangeAnimation(anim->state);
	}
}

Animation* AnimationRenderer::FindAnimationByState(int state)
{
	for (auto& i : animations)
	{
		if (i->state == state)
			return i;				//찾았을 경우 해당 애니메이션 반환
	}
	return nullptr;		//없을 경우 nullptr 반환
		
}
