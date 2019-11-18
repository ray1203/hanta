#include "stdafx.h"
#include "ImageResize.h"
#include "Renderer.h"
void ImageResize::resize(GameObject* g, int x, int y) {	
	g->transform->SetScale((float)x / g->renderer->GetWidth(), (float)y / g->renderer->GetHeight());
}