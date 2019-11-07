#include "stdafx.h"
#include "AABBCollider.h"
#include "Collision.h"

AABBCollider::AABBCollider(Transform& transform, const Vector2& size)
	:Collider(transform), boundingBox(size)
{
}

AABBCollider::AABBCollider(Transform& transform, float width, float height)
	: Collider(transform), boundingBox(width, height)
{
}

AABBCollider::AABBCollider(Transform& transform, const Vector2& leftTop, const Vector2& rightBottom)
	: Collider(transform), boundingBox(leftTop,rightBottom)
{

}

AABBCollider::AABBCollider(Transform& transform, float left, float top, float right, float bottom)
	: Collider(transform), boundingBox(left,top,right,bottom)
{
}

bool AABBCollider::Intersected(Collider& col)
{
	return col.Intersected(GetTransformedBox());
}

bool AABBCollider::Intersected(const Collider::AABBBox& box)
{
	return Collision::Intersected(GetTransformedBox(), box);
}

bool AABBCollider::Intersected(const Circle& circle)
{
	return Collision::Intersected(GetTransformedBox(),circle);
}

bool AABBCollider::Intersected(const Vector2& vector)
{
	return Collision::Intersected(GetTransformedBox(),vector);
}

Collider::AABBBox AABBCollider::GetTransformedBox()
{
	return AABBBox(transform.position + boundingBox.leftTop, transform.position + boundingBox.rightBottom);
}

Vector2 AABBCollider::GetCenter()
{
	return (boundingBox.rightBottom + boundingBox.leftTop) * 0.5f;
}

Vector2 AABBCollider::GetCenterOnScreen()
{
	return GetCenter() + transform.position;
}

Vector2 AABBCollider::GetLeftTopOnScreen()
{
	return transform.position + boundingBox.leftTop;
}

Vector2 AABBCollider::GetRightBottomOnScreen()
{
	return transform.position + boundingBox.rightBottom;
}

float AABBCollider::GetLeftOnScreen()
{
	return transform.position.x + boundingBox.leftTop.x;
}

float AABBCollider::GetRightOnScreen()
{
	return transform.position.x + boundingBox.rightBottom.x;
}

float AABBCollider::GetTopOnScreen()
{
	return transform.position.y + boundingBox.leftTop.y;
}

float AABBCollider::GetBottomOnScreen()
{
	return transform.position.y + boundingBox.rightBottom.y;
}

float AABBCollider::GetWidth()
{
	return boundingBox.rightBottom.x - boundingBox.leftTop.x;
}

float AABBCollider::GetHeight()
{
	return boundingBox.rightBottom.y - boundingBox.leftTop.y;
}

float AABBCollider::GetSquareDiagonal()
{
	return (GetWidth() * GetWidth()) + (GetHeight() * GetHeight());
}
