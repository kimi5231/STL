//-------------------------------------------------------------------
// 2024 1학기 STL 화56목56		4월 9일 화요일		(6주 1)
// 
// 4월 25일 (8주 1일) - 중간시험
// 
// STL Container - Containers are objects that store other objects.
// 실습할 시간을 줘야 한다.
//-------------------------------------------------------------------
#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include "save.h"
#include "String.h"

extern bool 관찰;

//-------------
int main(void)
//-------------
{
	std::array<std::string, 50> a;

	// [문제] "STL.cpp"의 단어를 a에 저장하라.
	// 길이오름차순으로 a를 정렬하라.
	// 화면에 출력하라.

	std::ifstream in{ "STL.cpp" };
	
	for (int i = 0; i < 50; ++i)
		in >> a[i];					// std::string을 이용해서 하자.

	save("STL.cpp");
}