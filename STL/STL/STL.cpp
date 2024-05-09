//-------------------------------------------------------------------
// 2024 1학기 STL 화56목56		5월 9일 목요일		(10주 2)
// 
// Iterator - 반복자는 포인터를 일반화 한 것이다.
// 
// 6월 6일 목요일 - 강의하겠습니다.
//-------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <string>
#include "save.h"
#include "String.h"

extern bool 관찰;

template <class 반복자, class 호출가능타입>
반복자 my_find(반복자 b, 반복자 e, 호출가능타입 f)
{

}

// [실습] 연산자 오버로딩
//-------------
int main(void)
//-------------
{
	String s{ "1357924580" };

	// [문제] 다음 코드가 문제없이 실행되도록 하자.
	// 이 코드는 [begin(), end()]에서 주어진 조건에 맞는 원소의 위치를 리턴한다.
	my_find(s.begin(), s.end(), [](char c) {
		if (std::stoi(c) % 2 == 0)
			return true;
		return false;
		});
	std::cout < "처음 찾은 짝수의 위치는 " << '\n';
	std::cout < "처음 찾은 짝수의 값은 " << '\n';

	save("STL.cpp");
}