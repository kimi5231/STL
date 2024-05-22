//-------------------------------------------------------------------
// 2024 1학기 STL 화56목56		5월 21일 화요일		(12주 1)
// 
// Associative Container - set / map
// 
// map<Key, value> - dictionary
// 
// 6월 6일 목요일 - 강의하겠습니다.
// 6월 13일 목요일 (15주 2일) - 기말시험
//-------------------------------------------------------------------
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <fstream>
#include "save.h"
#include "String.h"

extern bool 관찰;

//-------------
int main(void)
//-------------
{
	// [문제] 소설에 사용된 영문자와 그 사용횟수를 횟수기준 내림차순으로 출력하라.
	// 대문자는 소문자로 변환한다.
	std::map<char, int> cim;

	std::ifstream in{ "이상한 나라의 앨리스.txt" };

	char c;
	while (in >> c) {
		if (isalpha(c))
			cim[tolower(c)]++;
	}

	for (auto [소문자, 횟수] : cim)
		std::cout << 소문자 << " - " << 횟수 << '\n';

	save("STL.cpp");
}