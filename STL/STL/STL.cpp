//-------------------------------------------------------------------
// 2024 1학기 STL 화56목56		5월 7일 화요일		(10주 1)
// 
// Iterator - 반복자는 포인터를 일반화 한 것이다.
// 
// Iterators are a generalization of pointers
// that allow a C++ program to work with different data structures
// in a uniform manner.
//-------------------------------------------------------------------
#include <iostream>
#include <string>
#include <algorithm>
#include <span>
#include "save.h"
#include "String.h"

extern bool 관찰;

template <typename 반복자>
void f(반복자 iter)
{
	// 반복자의 종류를 판단하는 표준 문장
	std::cout << typeid(반복자::iterator_concept).name() << '\n';
}

//-------------
int main(void)
//-------------
{
	String s{ "1357924680" };

	// s의 반복자가 - random_access_iterator_tag

	save("STL.cpp");
}