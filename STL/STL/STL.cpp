//-------------------------------------------------------------------
// 2024 1학기 STL 화56목56		4월 30일 화요일		(9주 1)
// 
// list
//-------------------------------------------------------------------
#include <iostream>
#include <list>
#include <fstream>
#include "save.h"
#include "String.h"

extern bool 관찰;

//-------------
int main(void)
//-------------
{
	// [문제] 파일 "STL.cpp"의 단어를 읽어 정렬하라.

	std::ifstream in{ "STL.cpp" };

	std::list<String> cont{ std::istream_iterator<String>{in}, {} };

	cont.sort();
	cont.unique();		// 중복된 원소를 삭제한다.

	for (const String& s : cont)
		std::cout << s << '\n';

	save("STL.cpp");
}