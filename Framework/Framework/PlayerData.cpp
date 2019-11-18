#include "stdafx.h"
#include "PlayerData.h"
#include "ImageResize.h"
#include "Scene.h"
PlayerData::PlayerData():money(0)
{
	std::srand(static_cast<unsigned int>(std::time(0)));
}

int PlayerData::addMoney(int add=1)
{
	money += add;
	return money;
}

void PlayerData::createJaeum()
{
	if (money > 0) {
		String list[30] = { "ぁ","い","ぇ","ぉ","け","げ","さ","し","じ","ず","せ","ぜ","そ","ぞ" };
		int r = std::rand() % 14;
		jaeum.push_back(list[r]);
		money--;
	}
	else std::cout << "捣 何练" << "\n";
}

void PlayerData::createMoeum()
{
	if (money > 0) {
		String list[30] = { "に","づ","ち","だ","つ","び","た","っ","で","ば","ぬ","ぱ"};
		int r = std::rand() % 12;
		moeum.push_back(list[r]);
		money--;
	}
	else std::cout << "捣 何练" << "\n";
}

void PlayerData::printJaeum()
{
	std::cout << "jaeum : ";
	for (int i = 0; i < jaeum.size(); i++) {
		std::cout << jaeum[i] << ",";
	}
	std::cout << "\n";
}

void PlayerData::printMoeum()
{
	std::cout << "moeum : ";
	for (int i = 0; i < moeum.size(); i++) {
		std::cout << moeum[i] << ",";
	}
	std::cout << "\n";
}

void PlayerData::printMoney()
{
	std::cout << "money : "<<money<<"\n";
}

void PlayerData::printAll()
{
	std::cout << "----------------------" << "\n";
	printJaeum();
	printMoeum();
	printMoney();
	std::cout << "----------------------" << "\n";
}
void PlayerData::setlife(int life)
{
	GameObject* heart = new GameObject(L"resources\\heart (2).png");
	Scene::GetCurrentScene().PushBackGameObject(heart);
	ImageResize l;	l.resize(heart, 60, 60);
	printf("\n积疙林涝");
	this->life = life;
	heart->transform->position.x = 940;
	heart->transform->position.y = 30;
	switch (life / 10) {
	case 0:
		remainlife1 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot0.png")); break;
	case 1:
		remainlife1 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot1.png")); break;
	case 2:
		remainlife1 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot2.png")); break;
	case 3:
		remainlife1 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot3.png")); break;
	case 4:
		remainlife1 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot4.png")); break;
	case 5:
		remainlife1 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot5.png")); break;
	case 6:
		remainlife1 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot6.png")); break;
	case 7:
		remainlife1 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot7.png")); break;
	case 8:
		remainlife1 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot8.png")); break;
	case 9:
		remainlife1 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot9.png")); break;

	}
	switch (life % 10) {
	case 0:
		remainlife2 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot0.png"));
		
		break;
	case 1:
		remainlife2 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot1.png")); break;
	case 2:
		remainlife2 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot2.png")); break;
	case 3:
		remainlife2 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot3.png")); break;
	case 4:
		remainlife2 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot4.png")); break;
	case 5:
		remainlife2 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot5.png")); break;
	case 6:
		remainlife2 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot6.png")); break;
	case 7:
		remainlife2 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot7.png")); break;
	case 8:
		remainlife2 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot8.png")); break;
	case 9:
		remainlife2 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot9.png")); break;
	}
	remainlife1->transform->position.x = 1010;
	remainlife1->transform->position.y = 30;
	remainlife2->transform->position.x = 1050;
	remainlife2->transform->position.y = 30;

}
void PlayerData::changeLife(int changelife)
{
	life += changelife;
	switch (life / 10) {
		Scene::GetCurrentScene().Destroy(remainlife1);
	case 0:
		remainlife1 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot0.png"));break;
	case 1:
		remainlife1 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot1.png")); break;
	case 2:
		remainlife1 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot2.png")); break;
	case 3:
		remainlife1 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot3.png")); break;
	case 4:
		remainlife1 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot4.png")); break;
	case 5:
		remainlife1 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot5.png")); break;
	case 6:
		remainlife1 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot6.png")); break;
	case 7:
		remainlife1 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot7.png")); break;
	case 8:
		remainlife1 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot8.png")); break;
	case 9:
		remainlife1 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot9.png")); break;

	}
	switch (life % 10) {
		Scene::GetCurrentScene().Destroy(remainlife2);
	case 0:
		remainlife2 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot0.png"));
		break;
	case 1:
		remainlife2 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot1.png")); break;
	case 2:
		remainlife2 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot2.png")); break;
	case 3:
		remainlife2 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot3.png")); break;
	case 4:
		remainlife2 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot4.png")); break;
	case 5:
		remainlife2 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot5.png")); break;
	case 6:
		remainlife2 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot6.png")); break;
	case 7:
		remainlife2 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot7.png")); break;
	case 8:
		remainlife2 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot8.png")); break;
	case 9:
		remainlife2 = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\number\\dot9.png")); break;
	}
	remainlife1->transform->position.x = 1010;
	remainlife1->transform->position.y = 30;
	remainlife2->transform->position.x = 1050;
	remainlife2->transform->position.y = 30;
}