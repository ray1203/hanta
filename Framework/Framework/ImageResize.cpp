#include "stdafx.h"
#include "ImageResize.h"
#include "Renderer.h"
void ImageResize::resize(GameObject* g, double x, double y) {	
	g->transform->SetScale((float)(g->renderer->GetWidth()/x),g->renderer->GetHeight()/ y);
}