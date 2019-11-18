#include "stdafx.h"
#include "ImageResize.h"
#include "Renderer.h"
void ImageResize::resize(GameObject* g, int x, int y) {	
	//printf("\n%f %f\n", (float)(x / g->renderer->GetWidth()), y / g->renderer->GetHeight());
	g->transform->SetScale(((float)x/g->renderer->GetWidth()), (float)y/g->renderer->GetHeight());
}