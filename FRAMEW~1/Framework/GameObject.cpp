#include "stdafx.h"
#include "GameObject.h"
#include "Framework.h"
GameObject::GameObject(Vector2 position, float angle, Vector2 scale)
	: transform(new Transform(position, angle, scale)),
	renderer(new Renderer()),
	isActive(true)

{
}

GameObject::GameObject(const wchar_t* imagePath, Vector2 position, float angle, Vector2 scale)
	:transform(new Transform(position, angle, scale)), renderer(new Renderer(
		Scene::GetCurrentScene().GetResourceManager().LoadBitmapFromFile(imagePath, 0, 0))),
	isActive(true)
{
}

GameObject::GameObject(Renderer* renderer, Vector2 position, float angle, Vector2 scale)
	:transform(new Transform(position, angle, scale)),
	renderer(renderer),
	isActive(true)
{
}

GameObject::~GameObject()
{
	SAFE_DELETE(renderer);
	SAFE_DELETE(transform);
}

bool GameObject::GetActive()
{
	return isActive;
}
