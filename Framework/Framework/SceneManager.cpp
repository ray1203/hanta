#include "stdafx.h"
#include "SceneManager.h"
#include "Scene.h"
SceneManager::SceneManager(){

}
void SceneManager::startScene(Scene* s)
{
	f.Run(s, L"HanTa", 1280, 800, false);
}
void SceneManager::changeScene(Scene* s) {
	Scene::ChangeScene(s);
}