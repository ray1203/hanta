#pragma once
#include "GameObject.h"
#include "CircleCollider.h"
#include "BulletManager.h"	
#include "EnemyManager.h"
#include "PlayerData.h"
#include "FontObject.h"
class Tower :
	public GameObject
{
	int attribute;
	int star;
	int damage;
	int o_damage;
	int speed;
	int range;
	int o_range;
	int multi = 2;
	
	float rate;
	float o_rate;
	float time;
	int flag = 0;
	const wchar_t* path;
	GameObject* rangeI;
	GameObject* TowerInfoframe;
	GameObject* TowerImage;
	String towerkinds = "¹«°è¿­";
	String words;
	CircleCollider* col;
	AABBCollider* col2;
	EnemyManager* em;
	PlayerData* playerData;
	BulletManager* bm;
	FontObject* towerkind;
	FontObject* stars;
	FontObject* towerstat;
public:
	Tower(const wchar_t* path, int attribute, int damage, int speed, int range, float rate, int star);
	int srange;
	int o_srange;

	int activation = 0;

	void Update();
	void Shoot();
};