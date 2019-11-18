#include "stdafx.h"
#include "PlayerData.h"
#include "GameScene.h"
#include "ImageResize.h"
PlayerData::PlayerData():money(10),isPause(false)
{
	
	std::srand(static_cast<unsigned int>(std::time(0)));
}

int PlayerData::addMoney(int add=1)
{
	money += add;
	return money;
}
String PlayerData::MergeJaso(String choSung, String jungSung, String jongSung) {
	int ChoSungPos, JungSungPos, JongSungPos;
	int nUniCode;
	ChoSungPos = m_ChoSungTbl.find(choSung) / 2;
	JungSungPos = m_JungSungTbl.find(jungSung) / 2;
	JongSungPos = m_JongSungTbl.find(jongSung) / 2;
	nUniCode = m_UniCodeHangulBase + (ChoSungPos * 21 + JungSungPos) * 28 + JongSungPos;
	wchar_t a[15];
	swprintf(a, sizeof(a) / sizeof(wchar_t), L"%c", nUniCode);
	char b[15];
	sprintf_s(b, 15, "%ls", a);
	String result(b);
	return result;
}
void PlayerData::createJaeum()
{
	if (money > 0) {
		String list[30] = { "ㄱ","ㄴ","ㄷ","ㄹ","ㅁ","ㅂ","ㅅ","ㅇ","ㅈ","ㅊ","ㅋ","ㅌ","ㅍ","ㅎ" };
		int r = std::rand() % 14;
		jaeum.push_back(list[r]);
		money--;
		notifyChange();
	}
	else std::cout << "돈 부족" << "\n";
	
}

void PlayerData::createMoeum()
{
	if (money > 0) {
		String list[30] = { "ㅛ","ㅕ","ㅑ","ㅐ","ㅔ","ㅣ","ㅏ","ㅓ","ㅗ","ㅠ","ㅜ","ㅡ"};
		int r = std::rand() % 12;
		moeum.push_back(list[r]);
		money--;
		notifyChange();
	}
	else std::cout << "돈 부족" << "\n";
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

String PlayerData::sprintJaeum()
{
	String str;
	for (int i = 0; i < jaeum.size(); i++) {
		str.append(jaeum[i]);
		if (i != jaeum.size() - 1) {
			str.append(",");
		}
	}
	return str;
}

String PlayerData::sprintMoeum()
{
	String str;
	for (int i = 0; i < moeum.size(); i++) {
		str.append(moeum[i]);
		if (i != moeum.size() - 1) {
			str.append(",");
		}
	}
	return str;
}

void PlayerData::notifyChange()
{
	printf("notify\n");
	GameScene& s = (GameScene&)Scene::GetCurrentScene();
	s.GetCraftTable()->updateText();
}

void PlayerData::pause()
{
	isPause = true;
}

void PlayerData::resume()
{
	isPause = false;
}

void PlayerData::setlife(int life)
{
	GameObject* heart = new GameObject(L"resources\\heart (2).png");
	Scene::GetCurrentScene().PushBackGameObject(heart);
	ImageResize l;    l.resize(heart, 60, 60);
	printf("\n생명주입");
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