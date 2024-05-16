//-------------------------------------------------------------------
// 2024 1학기 STL 화56목56		5월 16일 화요일		(11주 2)
// 
// Associative Container - set / map
// 
// - equivalence(동등성, < ) / equality(상등성, == )
// 
// - default 정렬기준은 operator<
// - 함수객체
// -less<String>를 specializtion
// 
// 6월 6일 목요일 - 강의하겠습니다.
// 6월 13일 목요일 (15주 2일) - 기말시험
//-------------------------------------------------------------------
#include <iostream>
#include <set>
#include <fstream>
#include <algorithm>
#include "save.h"
#include "String.h"

extern bool 관찰;

//-------------
int main(void)
//-------------
{
	save("STL.cpp");

	std::ifstream in{ "이상한 나라의 앨리스.txt" };
	if (not in)
		return 0;

	std::multiset<String> s{ std::istream_iterator<String>{in}, {} };

	std::cout << "앨리스에서 사용한 단어 개수 - " << s.size() << '\n';

	// [문제] 사용자가 입력한 문자를 포함한 모든 단어를 출력하라.

	while (true) {
		std::cout << "찾을 단어는? ";
		String word;
		std::cin >> word;

		auto cnt = s.contains(word);
		if (cnt)
			std::cout << word << "를 " << cnt << "번 사용했다." << '\n';
		else
			std::cout<< word <<"를 사용하지는 않았습니다."<<'\n';
	}
}