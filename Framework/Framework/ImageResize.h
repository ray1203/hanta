#pragma once
#include "GameObject.h"
class ImageResize
{
public:
	double width, height;
	void resize(GameObject* g, double x, double y);
};

