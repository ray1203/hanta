#pragma once
#include "Collider.h"

class AABBCollider :
	public Collider
{
public:
	AABBCollider(Transform& transform, const Vector2& size);
	AABBCollider(Transform& transform, const Vector2& leftTop, const Vector2& rightBottom);
	AABBCollider(Transform& transform, float width, float height); //직사각형
	AABBCollider(Transform& transform, float left, float top, float right, float bottom);

public:
	AABBBox boundingBox;

public:
	virtual bool Intersected(Collider& col);
	virtual bool Intersected(const AABBBox& box);
	virtual bool Intersected(const Circle& circle);
	virtual bool Intersected(const Vector2& vector);

public:
	AABBBox GetTransformedBox();
	Vector2 GetCenter();
	Vector2 GetCenterOnScreen();
	Vector2 GetLeftTopOnScreen();
	Vector2 GetRightBottomOnScreen();
	float GetLeftOnScreen();
	float GetRightOnScreen();
	float GetTopOnScreen();
	float GetBottomOnScreen();
	float GetWidth();
	float GetHeight();
	float GetSquareDiagonal();

	virtual void Update() {}
};

