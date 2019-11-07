#pragma once
#include "Transform.h"


class Collider :
	public Component
{
public:
	struct AABBBox //AABB 충돌처리
	{
		Vector2 leftTop;			//(0,0)을 기준으로 한 좌상단 꼭지점의 포지션값입니다. 상자의 중심을 0,0으로 두었을 경우 음수 값을 가지게 됩니다.
		Vector2 rightBottom;		//(0,0)을 기준으로 한 우하단 꼭지점의 포지션값입니다. 상자의 중심을 0,0으로 두었을 경우 양수 값을 가지게 됩니다.

		AABBBox();
		AABBBox(const AABBBox& box);
		AABBBox(const Vector2& size);
		AABBBox(float width, float height);
		AABBBox(const Vector2& leftTop, const Vector2& rightBottom);
		AABBBox(float left, float top, float right, float bottom);
	};
	struct Circle //center값은 transform.position을 원점으로한 거리입니다.
	{
		Vector2 center;			//기본적으로 0,0
		float radius;			//원의 반지름

		Circle();
		Circle(const Circle& circle);
		Circle(float radius);
		Circle(const Vector2& center, float radius);
		Circle(float x, float y, float radius);
	};
public:
	Collider(Transform& transform);		//콜라이더 객체는 Transform을 기준으로 충돌처리를 진행합니다.
public:
	Transform& transform;

public:
	//충돌체를 더 만드실 경우 순수 가상 함수를 추가해주셔야합니다.
	virtual bool Intersected(Collider& col) = 0;
	virtual bool Intersected(const AABBBox& box) = 0;
	virtual bool Intersected(const Circle& circle) = 0;
	virtual bool Intersected(const Vector2& vector) = 0;
};