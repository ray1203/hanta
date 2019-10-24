#include "stdafx.h"
#include "CircleCollider.h"
#include "Collision.h"

CircleCollider::CircleCollider(Transform& transform, const Circle& circle)
	:Collider(transform),boundingCircle(circle)
{
}

CircleCollider::CircleCollider(Transform& transform, const Vector2& center, float radius)
	: Collider(transform), boundingCircle(center, radius)
{
}

CircleCollider::CircleCollider(Transform& transform, float x, float y, float radius)
	:Collider(transform), boundingCircle(x,y,radius)
{
}

Collider::Circle CircleCollider::GetTransformedCircle()
{
	return Circle(boundingCircle.center,boundingCircle.radius);
}

Vector2 CircleCollider::GetCenterOnScreen()
{
	return transform.position+ boundingCircle.center;
}

float CircleCollider::GetXOnScreen()
{
	return transform.position.x+boundingCircle.center.x;
}

float CircleCollider::GetYOnScreen()
{
	return transform.position.y+boundingCircle.center.y;
}

bool CircleCollider::Intersected(Collider& col)
{
	return col.Intersected(boundingCircle);
}

bool CircleCollider::Intersected(const AABBBox& box)
{
	return Collision::Intersected(box,GetTransformedCircle());
}

bool CircleCollider::Intersected(const Circle& circle)
{
	return Collision::Intersected(GetTransformedCircle(),circle);
}

bool CircleCollider::Intersected(const Vector2& vector)
{
	return Collision::Intersected(GetTransformedCircle(),vector);
}
