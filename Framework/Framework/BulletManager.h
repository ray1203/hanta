#pragma once
#include "GameObject.h"
#include "Bullet.h"
class BulletManager :
	public GameObject
{
public:
	BulletManager();
	~BulletManager();

	std::list<Bullet*> towerBullets;
	Bullet* PushBackTowerBullet(Bullet* b);
	void Destroy(Bullet* b);
	virtual void LateUpdate();
	void Check();
	float checkRate=5.0f;
	float time = 0.0f;
private:
	std::list<Bullet*> destroyed;
	void Remove();
};

