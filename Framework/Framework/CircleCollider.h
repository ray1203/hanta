#pragma once
#include "Collider.h"

class CircleCollider :
	public Collider
{
public:
	CircleCollider(Transform& transform, const Circle& circle);
	CircleCollider(Transform& transform, const Vector2& center, float radius);
	CircleCollider(Transform& transform, float x, float y, float radius);

public:
	Circle boundingCircle;

public:
	Circle GetTransformedCircle();
	Vector2 GetCenterOnScreen();
	float GetXOnScreen();
	float GetYOnScreen();
	

	virtual void Update() {}
	virtual bool Intersected(Collider& col);
	virtual bool Intersected(const AABBBox& box);
	virtual bool Intersected(const Circle& circle); 
	virtual bool Intersected(const Vector2& vector);
};

