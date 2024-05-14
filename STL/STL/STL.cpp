//-------------------------------------------------------------------
// 2024 1학기 STL 화56목56		5월 14일 화요일		(11주 1)
// 
// 알고리즘 함수 - 반복자를 인자로 받는다
// 
// 6월 6일 목요일 - 강의하겠습니다.
// 6월 13일 목요일 (15주 2일) - 기말시험
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include "save.h"
#include "String.h"

extern bool 관찰;

template <class InIter, class OutIter>
void my_copy(InIter b, InIter e, OutIter d)
{
	while (b != e) {
		*d = *b;
		++b;
		++d;
	}
}

// [실습] 연산자 오버로딩
//-------------
int main(void)
//-------------
{
	save("STL.cpp");

	String s{ "STL aldorithm 2024년 5월 14일" };
	std::vector<char> v{s.getLen()};
	
	my_copy(s.begin(), s.end(), back_inserter(v));

	for (char c : v)
		std::cout << v[i];
	std::cout << '\n';
}