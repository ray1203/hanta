#include "stdafx.h"
#include "PlayerData.h"
#include "GameScene.h"
#include "ImageResize.h"
#include <string>
#include <math.h>
PlayerData::PlayerData():isPause(false)
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	vocab.insert(std::pair<String,int>("물",nature));
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
//	printf("mergeJaJa\n");
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
	std::map<String, int> usingword;
	if (splitJaeum(str) != "null") {

		String j = splitJaeum(str);
		String jauem1[2];
		char* writable = new char[j.size() + 1];
		std::copy(j.begin(), j.end(), writable);
		writable[5] = '\0';
		jauem1[0] = strtok(writable, ",");
		jauem1[1] = strtok(NULL, ",");
		int flag = 0;
		if (jauem1[0] == jauem1[1])
		{
			if (jaeum[jauem1[0]] < 2) {
				std::cout << jauem1[0] << "이 모잘랍니다!" << std::endl;
				flag = 1;
			}
		}
		if (jaeum[jauem1[0]] < 1 && !flag)
		{

			std::cout << jauem1[0] << "이 모잘랍니다!" << std::endl;
			flag = 1;
		}
		if (jaeum[jauem1[1]] < 1) {
			std::cout << jauem1[1] << "이 모잘랍니다!!" << std::endl; flag = 1;
		}
		if (flag)return;
		jaeum[jauem1[0]] -= 1;
		jaeum[jauem1[1]] -= 1;

		std::cout << MergeJaJa(jauem1[0], jauem1[1]) << std::endl;
		jaeum[MergeJaJa(jauem1[0], jauem1[1])] += 1;
	}
	else {
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

		if (jaeum[Cho] < 1)
		{
			std::cout << Cho << "이 모잘랍니다!" << std::endl;
			flag = 1;
		}
		else {
			usingword[Cho] += 1;
		}
		if (moeum[Jung] < 1) {
			std::cout << Jung << "이 모잘랍니다!" << std::endl; flag = 1;
		}
		if (jaeum[Jong] < 1 + usingword[Jong] && Jong.size() >= 2)
		{
			std::cout << Jong << "이 모잘랍니다!" << std::endl; flag = 1;
		}
		if (flag)return;
		jaeum[Cho] -= 1;
		moeum[Jung] -= 1;
		if (Jong.size() >= 2)
			jaeum[Jong] -= 1;
		std::cout << str << "이 생성되었습니다!" << std::endl;
		word[str] += 1;
	}
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
				mouem = MergeSoSo(result2, str2);
				if (mouem != "null")
					flag = 1;
			}
		}
		i = 0;
		while (cList[i] != " ") {
			if (cList[i++] == str2) {
				if (result3 == " ")
					return MergeJaso(result1, result2, str2);
				if (MergeJaJa(result3, str2) != "null")
					return MergeJaso(result1, result2, MergeJaJa(result3, str2));
			}
		}
		if (flag)
			return MergeJaso(result1, mouem, "");
	}

	return "null";
}

void PlayerData::createJaeum()
{
	if (money > 0) {
		String list[30] = { "ㄱ","ㄴ","ㄷ","ㄹ","ㅁ","ㅂ","ㅅ","ㅇ","ㅈ","ㅊ","ㅋ","ㅌ","ㅍ","ㅎ" };
		int r = std::rand() % 14;
		jaeum[list[r]] += 1;
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
		std::cout << i->first << ",";
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
	std::cout << "money : " << money << "\n";
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
//	printf("notify\n");
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

void PlayerData::setdata(int life,int money)
{
	ImageResize I;

	GameObject* heart = new GameObject(L"resources\\heart.png");
	Scene::GetCurrentScene().PushBackGameObject(heart);
	I.resize(heart, 45, 45);
	this->life = life;
	heart->transform->position.x = 940;
	heart->transform->position.y = 30;

	GameObject* coin = new GameObject(L"resources\\coin.png");
	Scene::GetCurrentScene().PushBackGameObject(coin);
	I.resize(coin, 45, 45);
	this->money = money;
	coin->transform->position.x = 940;
	coin->transform->position.y = 80;

	int k = pow(10, (int)log10(life));
	for (ls = 0; k > 0; ls++) {
		remainlife[ls] = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(number[life / k]));
		remainlife[ls]->transform->position.x = 1000 + 31 * ls;
		remainlife[ls]->transform->position.y = 30;
		life %= k;
		k /= 10;
	}

	k = pow(10, (int)log10(money));
	for (ms = 0; k > 0; ms++) {
		remainmoney[ms] = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(number[money / k]));
		remainmoney[ms]->transform->position.x = 1000 + 31 * ms;
		remainmoney[ms]->transform->position.y = 75;
		money %= k;
		k /= 10;
	}
}

void PlayerData::changeLife(int changelife)
{
	life += changelife;
	int k = pow(10, ls - 1);
	for (int i = 0, dlife = life; i < ls; i++) {
		Scene::GetCurrentScene().Destroy(remainlife[i]);
		remainlife[i] = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(number[dlife / k]));
		remainlife[i]->transform->position.x = 1000 + 31 * i;
		remainlife[i]->transform->position.y = 30;
		dlife %= k;
		k /= 10;
	}
}

void PlayerData::changeMoney(int changemoney)
{
	money += changemoney;
	int k = pow(10, ms - 1);
	for (int i = 0, dmoney = money; i < ms; i++) {
		Scene::GetCurrentScene().Destroy(remainmoney[i]);
		remainmoney[i] = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(number[dmoney / k]));
		remainmoney[i]->transform->position.x = 1000 + 31 * i;
		remainmoney[i]->transform->position.y = 75;
		dmoney %= k;
		k /= 10;
	}
}