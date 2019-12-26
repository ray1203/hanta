#include "stdafx.h"
#include "PlayerData.h"
#include "GameScene.h"
#include "ImageResize.h"
#include "OverButton.h"
#pragma warning(disable:4996)
PlayerData::PlayerData(int life, int money)
	:isPause(false)
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	std::pair<String, int> v[1000] = {
	   {"파괴",힘},{"지식",힘}, {"근력",힘}, {"인력",힘},{"척력",힘},{"자기력",힘},{"전기력",힘},{"중력",힘},{"약력",힘},{"강력",힘},{"마찰력",힘},{"원심력",힘},{"구심력",힘},{"탄력",힘},{"탄성력",인공},
	   {"요정",환상},{"노을",환상},{"몽환",환상},{"악마",환상},{"천사",환상},{"드래곤",환상},{"여친",환상},{"고블린",환상},{"분신",환상},{"미믹",환상},{"정령",환상},{"마법",환상},{"유령",환상},
	   {"강물",자연},{"강아지",자연},{"고양이",자연},{"사자",자연},{"동물",자연},{"폭포",자연},{"바위",자연},{"태양",자연},{"산맥",자연},{"노루",자연},{"무지개",자연},{"나무",자연},{"개미",자연},{"곤충",자연},{"사과",인공},
	   {"기계",인공},{"포탑",인공},{"컴퓨터",인공},{"원자로",인공},{"폭탄",인공},{"공업",인공},{"인터넷",인공},{"설비",인공},{"시설",인공},{"미사일",인공},{"대검",인공}, {"도끼",인공},{"단검",인공},{"게임",인공},
	   {"사랑",개념},{"저주",개념},{"축복",개념},{"혼돈",개념},{"슬픔",개념},{"기쁨",개념},{"행운",개념},{"행복",개념},{"분노",개념},{"애정",개념},{"즐거움",개념},{"혐오",개념},{"공포",개념},{"증오",개념},{"욕망",개념},{"두려움",개념},{"노여움",개념},
	   {"시공의폭풍은정말최고야",무계열},
	};
	int i = 0;
	while (1) {
		if (v[i].first == "시공의폭풍은정말최고야")
			break;
		vocab.insert(v[i++]);
	}

	ImageResize I;

	heart = Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\ui\\heart.png"));
	I.resize(heart, 45, 45);
	this->life = life;
	heart->transform->SetPosition(940, 30);

	coin = Scene::GetCurrentScene().PushBackGameObject(new GameObject(L"resources\\ui\\coin.png"));
	I.resize(coin, 45, 45);
	this->money = money;
	coin->transform->SetPosition(940, 80);

	int k = pow(10, (int)log10(life));
	for (int i = 0; k > 0; i++) {
		remainlife[i] = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(number[(life / k) % 10]));
		remainlife[i]->transform->position.x = 1000 + 31 * i;
		remainlife[i]->transform->position.y = 30;
		k /= 10;
	}

	k = pow(10, (int)log10(money));
	for (int i = 0; k > 0; i++) {
		remainmoney[i] = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(number[(money / k) % 10]));
		remainmoney[i]->transform->position.x = 1000 + 31 * i;
		remainmoney[i]->transform->position.y = 75;
		k /= 10;
	}
}

void PlayerData::createJaeum()
{
	if (money > 0) {
		String list[14] = { "ㄱ","ㄴ","ㄷ","ㄹ","ㅁ","ㅂ","ㅅ","ㅇ","ㅈ","ㅊ","ㅋ","ㅌ","ㅍ","ㅎ" };
		int r = std::rand() % 14;
		jaeum[list[r]] += 1;
		changeMoney(-1);
		notifyChange();
	}
	else {
		std::cout << "돈 부족" << "\n";
	}
}

void PlayerData::createMoeum()
{
	if (money > 0) {
		String list[21] = { "ㅏ","ㅐ","ㅑ","ㅒ","ㅓ","ㅔ","ㅕ","ㅖ","ㅗ","ㅘ","ㅙ","ㅚ","ㅛ","ㅜ","ㅝ","ㅞ","ㅟ","ㅠ","ㅡ","ㅢ","ㅣ" };
		int r = std::rand() % 21;
		moeum[list[r]] += 1;
		changeMoney(-1);
		notifyChange();
	}
	else std::cout << "돈 부족" << "\n";
}

void PlayerData::createWord(String str) {
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
				std::cout << jauem1[0] << "이 더 필요합니다!" << std::endl;
				flag = 1;
			}
		}
		if (jaeum[jauem1[0]] < 1 && !flag)
		{

			std::cout << jauem1[0] << "이 더 필요합니다!" << std::endl;
			flag = 1;
		}
		if (jaeum[jauem1[1]] < 1) {
			std::cout << jauem1[1] << "이 더 필요합니다!!" << std::endl; flag = 1;
		}
		if (flag)return;
		jaeum[jauem1[0]] -= 1;
		jaeum[jauem1[1]] -= 1;

		std::cout << mergeJaJa(jauem1[0], jauem1[1]) << std::endl;
		jaeum[mergeJaJa(jauem1[0], jauem1[1])] += 1;
	}
	else if (splitMoeum(str) != "null") {
		String j = splitMoeum(str);

		String mouem1[2];
		char* writable = new char[j.size() + 1];
		std::copy(j.begin(), j.end(), writable);
		writable[5] = '\0';
		mouem1[0] = strtok(writable, ",");
		mouem1[1] = strtok(NULL, ",");
		int flag = 0;
		if (moeum[mouem1[0]] < 1) {
			flag = 1;
			std::cout << mouem1[0] << "이 더 필요합니다!" << std::endl;
		}
		if (moeum[mouem1[1]] < 1){
			flag = 1;
			std::cout << mouem1[1] << "이 더 필요합니다!!" << std::endl;
			}
		if (flag)return;
		moeum[mouem1[0]] -= 1;
		moeum[mouem1[1]] -= 1;
		std::cout << mergeMoMo(mouem1[0], mouem1[1]) << std::endl;
		moeum[mergeMoMo(mouem1[0], mouem1[1])] += 1;
	}
	else {
		int C_STR_BUFFER_SIZE = str.size() + 1;
		wchar_t* result = new wchar_t[str.size() + 1];
		const char* s = str.c_str();
		MultiByteToWideChar(CP_ACP, NULL, s, -1, result, str.size() + 1);
		wchar_t buffer[10];
		breakHan(result, buffer, sizeof(buffer));
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
			std::cout << Cho << "이 더 필요합니다!" << std::endl;
			flag = 1;
		}
		else {
			usingword[Cho] += 1;
		}
		if (moeum[Jung] < 1) {
			std::cout << Jung << "이 더 필요합니다!" << std::endl; flag = 1;
		}
		if (jaeum[Jong] < 1 + usingword[Jong] && Jong.size() >= 2)
		{
			std::cout << Jong << "이 더 필요합니다!" << std::endl; flag = 1;
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

void PlayerData::printAll()
{
	std::cout << "----------------------" << "\n";
	printJaeum();
	printMoeum();
	std::cout << "----------------------" << "\n";
}

int PlayerData::breakHan(wchar_t* str, wchar_t* buffer, int nSize)
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

String PlayerData::mergeJaJa(String choSung1, String choSung2)
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
		}
		else if (choSung2 == "ㅂ") {
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

String PlayerData::mergeJaMo(String choSung, String jungSung, String jongSung) {
	int ChoSungPos, JungSungPos, JongSungPos;
	int nUniCode;
	ChoSungPos = m_ChoSungTbl.find(choSung) / 2;
	JungSungPos = m_JungSungTbl.find(jungSung) / 2;
	JongSungPos = m_JongSungTbl.find(jongSung) / 2;
	nUniCode = 0xAC00 + (ChoSungPos * 21 + JungSungPos) * 28 + JongSungPos;
	wchar_t a[15];
	swprintf(a, sizeof(a) / sizeof(wchar_t), L"%c", nUniCode);
	char b[15];
	sprintf_s(b, 15, "%ls", a);
	String result(b);
	return result;
}

String PlayerData::mergeMoMo(String mouem1, String mouem2)
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

String PlayerData::merge(String str1, String str2)
{
	//std::cout << "str1:"<<str1 << " str2:" << str2 << std::endl;

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

	breakHan(result, buffer, sizeof(buffer));

	if ((int)buffer[0] == 0) {
		while (cList[i] != " ") {
			if (cList[i++] == str1) {
				int j = 0;
				while (cList[j] != " ") {
					if (cList[j++] == str2) {
						return mergeJaJa(str1, str2);
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
						return mergeJaMo(str1, str2, "");
					}
				}
			}

		}
		i = 0;
		while (mList[i] != " ") {
			if (mList[i++] == str1) {
				int j = 0;
				while (mList[j] != " ") {
					if (mList[j++] == str2) {
						return mergeMoMo(str1, str2);
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
				mouem = mergeMoMo(result2, str2);
				if (mouem != "null")
					flag = 1;
			}
		}
		i = 0;
		while (cList[i] != " ") {
			if (cList[i++] == str2) {
				if (result3 == " ")
					return mergeJaMo(result1, result2, str2);
				if (mergeJaJa(result3, str2) != "null")
					return mergeJaMo(result1, result2, mergeJaJa(result3, str2));
			}
		}
		if (flag)
			return mergeJaMo(result1, mouem, "");
		if (result3 != "0")
		{
			i = 0;
			while (mList[i] != " ") {
				if (mList[i++] == str2) {
					String a = mergeJaMo(result1, result2, "");
					String b = mergeJaMo(result3, str2, "");
					if (b == "")
					{
						String j = splitJaeum(result3);

						String jauem1[2];
						char* writable = new char[j.size() + 1];
						std::copy(j.begin(), j.end(), writable);
						writable[5] = '\0';
						jauem1[0] = strtok(writable, ",");
						jauem1[1] = strtok(NULL, ",");


						a = mergeJaMo(result1, result2, jauem1[0]);
						b = mergeJaMo(jauem1[1], str2, "");
					}
					return a + b;

				}
			}
		}
	}
	return "null";
}

String PlayerData::sprintJaeum()
{
	std::map<String, int>::iterator i;
	String str;
	int index = 0;
	for (i = jaeum.begin(); i != jaeum.end(); i++) {
		index++;
		if (i->second) {
			str.append(i->first);
			str.append("x");
			char a[10];
			sprintf_s(a, "%d", i->second);
			str.append(a);
			str.append(",");
		}
		if (index == 10)str.append("\n");
	}

	return str;
}

String PlayerData::sprintMoeum()
{

	std::map<String, int>::iterator i;
	String str;
	int index = 0;
	for (i = moeum.begin(); i != moeum.end(); i++) {
		index++;
		if (i->second) {
			str.append(i->first);
			str.append("x");
			char a[10];
			sprintf_s(a, "%d", i->second);
			str.append(a);
			str.append(",");
		}
		if (index == 10)str.append("\n");
	}

	return str;

}

String PlayerData::sprintWord() {
	std::map<String, int>::iterator i;
	String str;
	int index=0;
	for (i = word.begin(); i != word.end(); i++) {
		index++;
		if (i->second) {
			str.append(i->first);
			str.append("x");
			char a[10];
			sprintf_s(a, "%d", i->second);
			str.append(a);
			str.append(",");
		}
		if (index == 10)str.append("\n");
	}

	return str;
}
String PlayerData::splitMoeum(String str) {
	if (str == "ㅚ")return "ㅗ,ㅣ";
	if (str == "ㅙ")return "ㅗ,ㅐ";
	if (str == "ㅘ")return "ㅗ,ㅏ";
	if (str == "ㅝ")return "ㅜ,ㅓ";
	if (str == "ㅟ")return "ㅜ,ㅣ";
	if (str == "ㅞ")return "ㅜ,ㅔ";
	if (str == "ㅢ")return "ㅡ,ㅣ";
	return "null";
}
String PlayerData::splitJaeum(String str) {
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
	if (over == 0)
		isPause = false;
}

void PlayerData::changeLife(int changelife)
{
	life += changelife;
	int k = pow(10, (int)log10(life));
	int i = 0;
	for (; k > 0; i++) {
		Scene::GetCurrentScene().Destroy(remainlife[i]);
		remainlife[i] = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(number[(life / k) % 10]));
		remainlife[i]->transform->position.x = 1000 + 31 * i;
		remainlife[i]->transform->position.y = 30;
		k /= 10;
	}
	if (life == 0) {
		pause();
		over = 1;
		OverButton* b = (OverButton*)Scene::GetCurrentScene().PushBackGameObject(new OverButton(L"resources\\button\\overButton.png", 1280, 800));
		b->transform->SetPosition(640, 400);
	}
	else if ((int)log10(life) != (int)log10(life - changelife)) {
		Scene::GetCurrentScene().Destroy(remainlife[i]);
	}
}

void PlayerData::changeMoney(int changemoney)
{
	money += changemoney;
	int k = money == 0 ? 1 : pow(10, (int)log10(money));
	int i = 0;
	for (; k > 0; i++) {
		Scene::GetCurrentScene().Destroy(remainmoney[i]);
		remainmoney[i] = (GameObject*)Scene::GetCurrentScene().PushBackGameObject(new GameObject(number[(money / k) % 10]));
		remainmoney[i]->transform->position.x = 1000 + 31 * i;
		remainmoney[i]->transform->position.y = 75;
		k /= 10;
	}
	if ((int)log10(money) != (int)log10(money - changemoney) && money != 0) {
		Scene::GetCurrentScene().Destroy(remainmoney[i]);
	}
}