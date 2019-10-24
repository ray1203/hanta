#pragma once
#include "AABBCollider.h"
#include "CircleCollider.h"

//충돌을 처리할 함수의 모음입니다.
//Collider가 없어도 임의로 충돌 계산이 가능합니다.

namespace Collision 
{
	bool Intersected(const Collider::AABBBox& a, const Collider::AABBBox& b);
	bool Intersected(const Collider::AABBBox& a, const Collider::Circle& b);
	bool Intersected(const Collider::Circle& a, const Collider::Circle& b);
	bool Intersected(const Collider::AABBBox& a, const Vector2& b);
	bool Intersected(const Collider::Circle& a, const Vector2& b);
}

