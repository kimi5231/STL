//-------------------------------------------------------------------
// 2024 1학기 STL 화56목56		4월 18일 화요일		(8주 1)
// 
// 4월 25일 (8주 2일) - 중간시험
// 
// list
//-------------------------------------------------------------------
#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <fstream>
#include <string>
#include <algorithm>
#include "save.h"
#include "String.h"

extern bool 관찰;

//-------------
int main(void)
//-------------
{
	std::list<String> cont;

	
	// [문제] 파일 "String.cpp"를 읽어 cont에 저장하라.
	std::ifstream in{ "String.cpp", std::ios::binary };
	if (not in)
		return 0;

	cont = { std::istream_iterator<String>{in}, {} };

	// cont를 길이오름차순으로 정렬하라.
	cont.sort([](const String& a, const String& b) {
		return a.getLen() < b.getLen();
		});

	// [문제] cont에서 길이가 5인 원소만 화면에 출력하라.
	copy_if(cont.begin(), cont.end(), std::ostream_iterator<String>{std::cout, "\n"},
		[](const String& s) {
			return s.getLen() == 5;
		});

	save("STL.cpp");
}