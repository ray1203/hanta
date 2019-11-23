#include "stdafx.h"
#include "PlayerData.h"
#include "GameScene.h"
#include "ImageResize.h"
#include<string>
PlayerData::PlayerData():money(100),isPause(false)
{
	
	std::srand(static_cast<unsigned int>(std::time(0)));
}

int PlayerData::BreakHan(wchar_t* str, wchar_t* buffer, int nSize)
{
	static const wchar_t wcHead[] = { L'ㄱ', L'ㄲ', L'ㄴ', L'ㄷ',
		   L'ㄸ', L'ㄹ', L'ㅁ', L'ㅂ',
		   L'ㅃ', L'ㅅ', L'ㅆ', L'ㅇ',
		   L'ㅈ', L'ㅉ', L'ㅊ', L'ㅋ',
		   L'ㅌ', L'ㅍ', L'ㅎ' };

	static const wchar_t wcMid[] = { L'ㅏ', L'ㅐ', L'ㅑ', L'ㅒ',
		  L'ㅓ', L'ㅔ', L'ㅕ', L'ㅖ',
		  L'ㅗ', L'ㅘ', L'ㅙ', L'ㅚ',
		  L'ㅛ', L'ㅜ', L'ㅝ', L'ㅞ',
		  L'ㅟ', L'ㅠ', L'ㅡ', L'ㅢ', L'ㅣ' };
	static const wchar_t wcTail[] = { L' ', L'ㄱ', L'ㄲ', L'ㄳ',
		   L'ㄴ', L'ㄵ', L'ㄶ', L'ㄷ',
		   L'ㄹ', L'ㄺ', L'ㄻ', L'ㄼ',
		   L'ㄽ', L'ㄾ', L'ㄿ', L'ㅀ',
		   L'ㅁ', L'ㅂ', L'ㅄ', L'ㅅ',
		   L'ㅆ', L'ㅇ', L'ㅈ', L'ㅊ',
		   L'ㅋ', L'ㅌ', L'ㅍ', L'ㅎ' };
	int pos = 0;
	while (*str != '\0')
	{
		if (*str < 256)
		{
			if (pos + 2 >= nSize - 1)
				break;

			buffer[pos] = *str;
			++pos;
		}
		else
		{
			if (pos + 4 >= nSize - 1)
				break;
			buffer[pos] = wcHead[(*str - 0xAC00) / (21 * 28)];
			buffer[pos + 1] = wcMid[(*str - 0xAC00) % (21 * 28) / 28];
			buffer[pos + 2] = wcTail[(*str - 0xAC00) % 28];
			pos += 3;
		}
		++str;
	}
	buffer[pos] = '\0';
	return pos;
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
String PlayerData::splitJaeum(String str) {
	String returnvalue;
	if (str == "ㄲ") {
			return "ㄱ,ㄱ";
		}
	else if (str == "ㄳ") {
			return "ㄱ,ㅅ";
	}
	else if (str == "ㄵ") {
			return "ㄴ,ㅈ";
		}
	else if (str == "ㄶ") {
			return "ㄴ,ㅎ";
		}
	else if (str == "ㄸ") {
			return "ㄷ,ㄷ";
	}
	else if (str == "ㄺ") {
			return "ㄹ,ㄱ";
		}
		else if (str == "ㄻ") {
			return "ㄹ,ㅁ";
		}
		else if (str == "ㄼ") {
			return "ㄹ,ㅂ";
		}
		else if (str == "ㄽ") {
			return "ㄹ,ㅅ";
		}
		else if (str == "ㄾ") {
			return "ㄹ,ㅌ";
		}
		else if (str == "ㄿ") {
			return "ㄹ,ㅍ";
		}
		else if (str == "ㅀ") {
			return "ㄹ,ㅎ";
		}
	else if (str == "ㅄ") {
			return "ㅂ,ㅅ";
		}
		else if (str == "ㅃ") {
			return "ㅂ,ㅂ";
		}
	else if (str == "ㅆ") {
			return "ㅅ,ㅅ";
		}
	else if (str == "ㅉ") {
			return "ㅈ,ㅈ";
		}
	return "null";
}
String PlayerData::MergeJaJa(String choSung1, String choSung2)
{
	printf("mergeJaJa\n");
	if (choSung1 == "ㄱ") {
		if (choSung2 == "ㄱ") {
			return "ㄲ";
		}
		else if (choSung2 == "ㅅ") {
			return "ㄳ";
		}
	}
	else if (choSung1 == "ㄴ") {
		if (choSung2 == "ㅈ") {
			return "ㄵ";
		}
		else if (choSung2 == "ㅎ") {
			return "ㄶ";
		}
	}
	else if (choSung1 == "ㄷ") {
		if (choSung2 == "ㄷ") {
			return "ㄸ";
		}
	}
	else if (choSung1 == "ㄹ") {
		if (choSung2 == "ㄱ") {
			return "ㄺ";
		}
		else if (choSung2 == "ㅁ") {
			return "ㄻ";
		}
		else if (choSung2 == "ㅂ") {
			return "ㄼ";
		}
		else if (choSung2 == "ㅅ") {
			return "ㄽ";
		}
		else if (choSung2 == "ㅌ") {
			return "ㄾ";
		}
		else if (choSung2 == "ㅍ") {
			return "ㄿ";
		}
		else if (choSung2 == "ㅎ") {
			return "ㅀ";
		}
	}
	else if (choSung1 == "ㅂ") {
		if (choSung2 == "ㅅ") {
			return "ㅄ";
		}else if (choSung2 == "ㅂ") {
			return "ㅃ";
		}
	}
	else if (choSung1 == "ㅅ") {
		if (choSung2 == "ㅅ") {
			return "ㅆ";
		}
	}
	else if (choSung1 == "ㅈ") {
		if (choSung2 == "ㅈ") {
			return "ㅉ";
		}
	}
	return "null";
}

String PlayerData::MergeSoSo(String mouem1, String mouem2)
{
	if (mouem1 == "ㅗ") {
		if (mouem2 == "ㅏ")
			return "ㅘ";
		if (mouem2 == "ㅐ")
			return "ㅙ";
		if (mouem2 == "ㅣ")
				return "ㅚ";

	}
	if (mouem1 == "ㅡ") {
		if (mouem2 == "ㅣ")
			return "ㅢ";
	}
	if (mouem1 == "ㅜ") {
		if (mouem2 == "ㅓ")
			return "ㅝ";
		if (mouem2 == "ㅔ")
			return "ㅞ";
		if (mouem2 == "ㅣ")
			return "ㅟ";

	}
	return "null";

}
void PlayerData::CreateWord(String str) {
	if (splitJaeum(str) != "null") {
		String j = splitJaeum(str);
		String jauem1[2];
		char* writable = new char[j.size() + 1];
		std::copy(j.begin(), j.end(), writable);
		writable[str.size()] = '\0';
		jauem1[0] = strtok(writable, ",");
		jauem1[1] = strtok(writable, ",");
		int flag = 0;
		if (jauem1[0] == jauem1[1])
		{
			if (jaeum.count(jauem1[0]) >= 2) {
				std::cout << jauem1[0] << "이 모잘랍니다!" << std::endl;
				flag = 1;
			}
		}
		if (!jaeum.count(jauem1[0]))
		{

			std::cout << jauem1[0] << "이 모잘랍니다!" << std::endl;
			flag = 1;
		}
		if (!jaeum.count(jauem1[1])) {
			std::cout << jauem1[1] << "이 모잘랍니다!!" << std::endl; flag = 1;
		}
		if (flag)return;
		jaeum[jauem1[0]] -= 1;
		jaeum[jauem1[1]] -= 1;
			std::cout << MergeJaJa(jauem1[0], jauem1[1]) << std::endl;
		jaeum[MergeJaJa(jauem1[0], jauem1[1])]+=1;
	}
	int C_STR_BUFFER_SIZE = str.size() + 1;
	wchar_t* result = new wchar_t[str.size() + 1];
	const char* s = str.c_str();
	MultiByteToWideChar(CP_ACP, NULL, s, -1, result, str.size() + 1);
	wchar_t buffer[10];
	BreakHan(result, buffer, sizeof(buffer));
	int flag = 0;
	wchar_t a1[15];
	swprintf(a1, sizeof(a1) / sizeof(wchar_t), L"%c", buffer[0]);
	char b1[15];
	sprintf_s(b1, 15, "%ls", a1);
	String Cho(b1);

	wchar_t a2[15];
	swprintf(a2, sizeof(a2) / sizeof(wchar_t), L"%c", buffer[1]);
	char b2[15];
	sprintf_s(b2, 15, "%ls", a2);
	String Jung(b2);

	wchar_t a3[15];
	swprintf(a3, sizeof(a3) / sizeof(wchar_t), L"%c", buffer[2]);
	char b3[15];
	sprintf_s(b3, 15, "%ls", a3);
	String Jong(b3);

	if (!jaeum.count(Cho))
	{
		std::cout << Cho << "이 모잘랍니다!" << std::endl;
		flag = 1;
	}
	if (!moeum.count(Jung)) {
		std::cout << Jung << "이 모잘랍니다!" << std::endl; flag = 1;
	}
	if (!jaeum.count(Jong)&&Jong.size()>=2)
	{
		std::cout << Jong << "이 모잘랍니다!" << std::endl; flag = 1;
	}
	if (flag)return;
	jaeum[Cho] -= 1;
	moeum[Jung] -= 1;
	if(Jong.size()>=2)
	jaeum[Jong] -= 1;
	std::cout << str << "이 생성되었습니다!" << std::endl;
	word[str] += 1;

}
String PlayerData::Merge(String str1, String str2)
{
	int C_STR_BUFFER_SIZE = str1.size() + 1;
	wchar_t* result = new wchar_t[str1.size() + 1];
	const char* s = str1.c_str();
	MultiByteToWideChar(CP_ACP, NULL, s, -1, result, str1.size() + 1);
	String cList[30] = { "ㄱ","ㄴ","ㄷ","ㄹ","ㅁ","ㅂ","ㅅ","ㅇ","ㅈ","ㅊ","ㅋ","ㅌ","ㅍ","ㅎ"," " };
	String c2List[30] = { "ㄱ","ㄴ","ㄷ","ㄹ","ㅁ","ㅂ","ㅅ","ㅇ","ㅈ","ㅊ","ㅋ","ㅌ","ㅍ","ㅎ","ㄲ","ㄸ","ㅃ","ㅆ","ㅉ", " " };
	String c3List[35] = { "ㄱ","ㄴ","ㄷ","ㄹ","ㅁ","ㅂ","ㅅ","ㅇ","ㅈ","ㅊ","ㅋ","ㅌ","ㅍ","ㅎ","ㄲ","ㄸ","ㅃ","ㅆ","ㅉ","ㄳ","ㄵ","ㄶ","ㄺ","ㄻ","ㄼ","ㄽ","ㄾ","ㄿ","ㅀ","ㅄ"," " };
	String mList[30] = { "ㅏ","ㅐ","ㅑ","ㅒ","ㅓ","ㅔ","ㅕ","ㅖ","ㅗ","ㅘ","ㅙ","ㅚ","ㅛ","ㅜ","ㅝ","ㅞ","ㅟ","ㅠ","ㅡ","ㅢ","ㅣ"," " };
	int i = 0;

	wchar_t buffer[10];

	BreakHan(result, buffer, sizeof(buffer));
	
	if ((int)buffer[0] == 0) {
		while (cList[i] != " ") {
			if (cList[i++] == str1) {
				int j = 0;
				while (cList[j] != " ") {
					if (cList[j++] == str2) {
						return MergeJaJa(str1, str2);

					}
				}
			}

		}
		i = 0;
		while (c2List[i] != " ") {
			if (c2List[i++] == str1) {
				int j = 0;
				while (mList[j] != " ") {
					if (mList[j++] == str2) {
						return MergeJaso(str1, str2, "");
					}
				}
			}

		}
	}
	else {

		i = 0;
		String mouem;
		wchar_t a1[15];
		swprintf(a1, sizeof(a1) / sizeof(wchar_t), L"%c", buffer[0]);
		char b1[15];
		sprintf_s(b1, 15, "%ls", a1);
		String result1(b1);

		wchar_t a2[15];
		swprintf(a2, sizeof(a2) / sizeof(wchar_t), L"%c", buffer[1]);
		char b2[15];
		sprintf_s(b2, 15, "%ls", a2);
		String result2(b2);

		wchar_t a3[15];
		swprintf(a3, sizeof(a3) / sizeof(wchar_t), L"%c", buffer[2]);
		char b3[15];
		sprintf_s(b3, 15, "%ls", a3);
		String result3(b3);

		int flag = 0;
		while (mList[i] != " ") {
			if (mList[i++] == str2) {
				mouem=MergeSoSo(result2, str2);
				if(mouem!="null")
				flag = 1;
			}
		}
		i = 0;
		while (cList[i] != " ") {
			if (cList[i++] == str2) {
				if(result3==" ")
				return MergeJaso(result1, result2, str2);
				if (MergeJaJa(result3, str2) != "null")
					return MergeJaso(result1, result2, MergeJaJa(result3, str2));
			}
		}
		if(flag)
		return MergeJaso(result1,mouem,"");
	}
	
	return "null";
}

void PlayerData::createJaeum()
{
	if (money > 0) {
		String list[30] = { "ㄱ","ㄴ","ㄷ","ㄹ","ㅁ","ㅂ","ㅅ","ㅇ","ㅈ","ㅊ","ㅋ","ㅌ","ㅍ","ㅎ" };
		int r = std::rand() % 14;
		jaeum[list[r]]+=1;
		money--;
		notifyChange();
	}
	else std::cout << "돈 부족" << "\n";
	
}

void PlayerData::createMoeum()
{
	if (money > 0) {
		String list[30] = { "ㅏ","ㅐ","ㅑ","ㅒ","ㅓ","ㅔ","ㅕ","ㅖ","ㅗ","ㅘ","ㅙ","ㅚ","ㅛ","ㅜ","ㅝ","ㅞ","ㅟ","ㅠ","ㅡ","ㅢ","ㅣ" };
		int r = std::rand() % 12;
		moeum[list[r]] += 1;
		money--;
		notifyChange();
	}
	else std::cout << "돈 부족" << "\n";
}

void PlayerData::printJaeum()
{
	std::map<String, int>::iterator i;
	std::cout << "jaeum : ";
	for (i = jaeum.begin(); i != jaeum.end(); i++) {
		std::cout << i->first<< ",";
	}

	std::cout << "\n";
}

void PlayerData::printMoeum()
{
	std::map<String, int>::iterator i;
	std::cout << "moeum : ";
	for (i = moeum.begin(); i != moeum.end(); i++) {
		std::cout << i->first << ",";
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
	std::map<String, int>::iterator i;
	String str;
	for (i = jaeum.begin(); i != jaeum.end(); i++) {
		if (i->second) {
			str.append(i->first);
			str.append("x");
			char a[10];
			sprintf_s(a, "%d", i->second);
			str.append(a);
			str.append(",");
		}
	}

	return str;
}
String PlayerData::sprintword() {
	std::map<String, int>::iterator i;
	String str;
	for (i = word.begin(); i != word.end(); i++) {
		if (i->second) {
			str.append(i->first);
			str.append("x");
			char a[10];
			sprintf_s(a, "%d", i->second);
			str.append(a);
			str.append(",");
		}
	}

	return str;
}
String PlayerData::sprintMoeum()
{
	
	std::map<String, int>::iterator i;
	String str;
	for (i = moeum.begin(); i != moeum.end(); i++) {
		if (i->second) {
			str.append(i->first);
			str.append("x");
			char a[10];
			sprintf_s(a, "%d", i->second);
			str.append(a);
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