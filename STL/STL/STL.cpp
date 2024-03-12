//-------------------------------------------------------------------
// 2024 1학기 STL 화56목56		3월 12일 화요일		(2주 1)
// 
// 많은 수의 데이터를 처리할 수 있어야...
//-------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <algorithm>
#include "save.h"

// [문제] "int값들.txt"에는 몇 개인지 모르는 int값이 있다.
// 제일 큰 값을 찾아 화면에 출력하라.

//-------------
int main(void)
//-------------
{
	std::ifstream in{ "int값들.txt" };
	if (not in) 
		exit(0);
	
	std::cout << "최대값: " << *std::max_element(std::istream_iterator<int>{in}, { }) << '\n';

	save("STL.cpp");
}