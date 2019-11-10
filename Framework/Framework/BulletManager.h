#pragma once
#include "GameObject.h"
#include "Bullet.h"
class BulletManager :
	public GameObject
{
	std::list<Bullet*> destroyed;

public:
	BulletManager();
	~BulletManager();

	std::list<Bullet*> towerBullets;
	Bullet* PushBackTowerBullet(Bullet* b);

	void Check();
	void Destroy(Bullet* b);
	void Remove();
	virtual void LateUpdate();
	
	float checkRate=5.0f;
	float time = 0.0f;
};

