#pragma once
#include "GameObject.h"
#include "Renderer.h"
#include "stdafx.h"
#include "GameObject.h"
#include "ResourceManager.h"

//장면의 객체를 관리할 Scene객체입니다.
//Scene을 상속받은 객체를 통해 자신만의 Scene을 생성할 수 있습니다.

class Scene
{
	friend class Framework;
public:
	//모든 오브젝트의 생성 혹은 리소스의 로드는 Initialize에서 이루어져아합니다.
	//생성자에서의 오브젝트의 생성 혹은 로드를 추천드리지 않습니다. (오류가 발생할 수 있습니다.)
	Scene();
	virtual ~Scene();
	
private:
	static Scene* currentScene;
	static Scene* nextScene;
	static void SwapScene();

public:
	static void ChangeScene(Scene* nextScene);		//ChangeScene을 호출하여 Scene을 호출할 수 있습니다.
	static Scene& GetCurrentScene();				//GetCurrentScene을 호출하여 현재의 Scene을 호출할 수 있습니다.

private:
	std::list<GameObject*> gameObjectList;			//모든 게임오브젝트 리스트
	std::list<GameObject*> renderableList;			//그림이 그려질(렌더) 오브젝트의 리스트
	std::list<GameObject*> destroyedObjectList;		//삭제처리된 오브젝트 리스트
	ResourceManager* resourceManager;				//이미지 파일을 관리할 객체

public:
	//모든 오브젝트의 생성 혹은 리소스의 로드는 Initialize에서 이루어져아합니다.
	//생성자에서의 오브젝트의 생성 혹은 로드를 추천드리지 않습니다. (오류가 발생할 수 있습니다.)
	virtual void Initialize() = 0;	//초기화	(순수 가상 함수),
	void Update();					//업데이트
	void Render();					//렌더

public:
	GameObject* PushBackGameObject(GameObject* gameObject);	//게임오브젝트 푸쉬백
	void Destroy(GameObject* o);							//삭제처리

public:
	ResourceManager& GetResourceManager();					//Getter
};

