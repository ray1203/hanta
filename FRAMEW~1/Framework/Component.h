#pragma once
#include "stdafx.h"

class Component
{
	//상속을 위한 객체.
	//궁금한 사람은 '가상 함수', '순수 가상 함수(인터페이스)'에 대해 찾아보자.
public:
	Component();
	virtual ~Component();

public:

	virtual void Initialize() {};
	virtual void Update() = 0;
	virtual void Uninitialze() {};

public:
	bool isActive;
};

