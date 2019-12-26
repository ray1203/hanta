#include "stdafx.h"
#include "DicButton.h"
#include "GameScene.h"
#include "AABBCollider.h"

DicButton::DicButton(const wchar_t* path, int colwidth, int colheight)
	:Button(path, colwidth, colheight)
{
	GameScene& s = (GameScene&)Scene::GetCurrentScene();
	playdata = s.GetPlayerData();
}
void DicButton::Update() {
	GameScene& s = (GameScene&)Scene::GetCurrentScene();
	std::map<String, int>::iterator iter;
	String returnvalue;
	if (col.Intersected(InputManager::GetMouseVector2())) {
		HCURSOR hCursor = LoadCursor(0, IDC_HAND);
		hCursor = SetCursor(hCursor);
	}

	if (InputManager::GetMyKeyState(VK_LBUTTON) == -1 && col.Intersected(InputManager::GetMouseVector2())) {
		OnClick();
	}
	if (playdata->nowdic != lastdic)
	{
		if (lastdic != 0) {
			s.Destroy(onselect);
			s.Destroy(dic);
			
		}
		if (lastdic == 1) {
			s.Destroy(con);
			con = (ConButton*)s.PushBackGameObject(new ConButton(L"resources\\개념.png", 200, 50, 1));
			con->transform->SetPosition(145, 140);
		}
		if (lastdic == 2) {
			s.Destroy(nat);
			nat = (ConButton*)s.PushBackGameObject(new ConButton(L"resources\\자연.png", 200, 50, 2));
			nat->transform->SetPosition(345, 140);
		}
		if (lastdic == 3) {
			s.Destroy(hum);
			hum = (ConButton*)s.PushBackGameObject(new ConButton(L"resources\\인공.png", 200, 50, 3));
			hum->transform->SetPosition(545, 140);
		}
		if (lastdic == 4) {
			s.Destroy(fan);
			fan = (ConButton*)s.PushBackGameObject(new ConButton(L"resources\\환상.png", 200, 50, 4));
			fan->transform->SetPosition(745, 140);
		}
		if (lastdic == 5) {
			s.Destroy(pow);
			pow = (ConButton*)s.PushBackGameObject(new ConButton(L"resources\\힘.png", 200, 50, 5));
			pow->transform->SetPosition(945, 140);
		}
		if (lastdic == 6) {
			s.Destroy(no);
			no = (ConButton*)s.PushBackGameObject(new ConButton(L"resources\\무계열.png", 200, 50, 6));
			no->transform->SetPosition(1130, 140);
		}
		lastdic = playdata->nowdic;
		if (lastdic == 1) {
			s.Destroy(con);
			con = (ConButton*)s.PushBackGameObject(new ConButton(L"resources\\개념s.png", 200, 50, 1));
			onselect = (GameObject*)s.PushBackGameObject(new GameObject(L"resources\\onselect.png"));
			con->transform->SetPosition(145, 140);
			onselect->transform->SetPosition(145, 165);

		}
		if (lastdic == 2) {
			s.Destroy(nat);
			nat = (ConButton*)s.PushBackGameObject(new ConButton(L"resources\\자연s.png", 200, 50, 2));
			onselect = (GameObject*)s.PushBackGameObject(new GameObject(L"resources\\onselect.png"));
			nat->transform->SetPosition(345, 140);
			onselect->transform->SetPosition(345, 165);
		}
		if (lastdic == 3) {
			s.Destroy(hum);
			hum = (ConButton*)s.PushBackGameObject(new ConButton(L"resources\\인공s.png", 200, 50, 3));
			onselect = (GameObject*)s.PushBackGameObject(new GameObject(L"resources\\onselect.png"));
			hum->transform->SetPosition(545, 140);
			onselect->transform->SetPosition(545, 165);
		}
		if (lastdic == 4) {
			s.Destroy(fan);
			fan = (ConButton*)s.PushBackGameObject(new ConButton(L"resources\\환상s.png", 200, 50, 4));
			onselect = (GameObject*)s.PushBackGameObject(new GameObject(L"resources\\onselect.png"));
			fan->transform->SetPosition(745, 140);
			onselect->transform->SetPosition(745, 165);
		}
		if (lastdic == 5) {
			s.Destroy(pow);
			pow = (ConButton*)s.PushBackGameObject(new ConButton(L"resources\\힘s.png", 200, 50, 5));
			onselect = (GameObject*)s.PushBackGameObject(new GameObject(L"resources\\onselect.png"));
			pow->transform->SetPosition(945, 140);
			onselect->transform->SetPosition(945, 165);
		}
		if (lastdic == 6) {
			s.Destroy(no);
			no = (ConButton*)s.PushBackGameObject(new ConButton(L"resources\\무계열s.png", 200, 50, 6));
			onselect = (GameObject*)s.PushBackGameObject(new GameObject(L"resources\\onselect.png"));
			no->transform->SetPosition(1130, 140);
			onselect->transform->SetPosition(1130, 165);
			returnvalue = "무계열은 사전에 등록되지 않은 \n다른 모든 단어가 이곳에 포함됩니다.";
		}
		int count = 0;
		for (iter = playdata->vocab.begin(); iter != playdata->vocab.end(); iter++)
		{
			if (iter->second == lastdic) {
				returnvalue += iter->first+" ";
				count++;
				if (count % 10 == 0)returnvalue += "\n";
			}
		}

		dic = (FontObject*)s.PushBackGameObject(new FontObject(returnvalue, 100, 200));
		dic->transform->SetScale(2, 2);
	}
}
void DicButton::OnClick()
{
	playdata->showdic = !playdata->showdic;	GameScene& s = (GameScene&)Scene::GetCurrentScene();
	if (playdata->showdic) {
	

		g = (GameObject*)s.PushBackGameObject(new GameObject(L"resources\\dictionary.png"));
		con = (ConButton*)s.PushBackGameObject(new ConButton(L"resources\\개념.png", 200, 50, 1));
		nat = (ConButton*)s.PushBackGameObject(new ConButton(L"resources\\자연.png", 200, 50, 2));
		hum = (ConButton*)s.PushBackGameObject(new ConButton(L"resources\\인공.png", 200, 50, 3));
		fan = (ConButton*)s.PushBackGameObject(new ConButton(L"resources\\환상.png", 200, 50, 4));
		pow = (ConButton*)s.PushBackGameObject(new ConButton(L"resources\\힘.png", 200, 50, 5));
		no = (ConButton*)s.PushBackGameObject(new ConButton(L"resources\\무계열.png", 200, 50, 6));

		g->transform->SetPosition(640, 420);
		con->transform->SetPosition(145, 140);
		nat->transform->SetPosition(345, 140);
		hum->transform->SetPosition(545, 140);
		fan->transform->SetPosition(745, 140);
		pow->transform->SetPosition(945, 140);
		no->transform->SetPosition(1130, 140);

	}
	else {
		s.Destroy(g);
		s.Destroy(con);
		s.Destroy(nat);
		s.Destroy(hum);
		s.Destroy(fan);
		s.Destroy(pow);
		s.Destroy(no);
		if (lastdic != 0) {
			s.Destroy(onselect); s.Destroy(dic);
		}	lastdic = 0;
		playdata->nowdic = 0;
	}
}
