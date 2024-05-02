//-------------------------------------------------------------------
// 2024 1학기 STL 화56목56		5월 2일 화요일		(9주 2)
// 
// Iterator - 반복자는 포인터를 일반화 한 것이다.
// 
// Iterators are a generalization of pointers
// that allow a C++ program to work with different data structures
// in a uniform manner.
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <list>
#include<forward_list>
#include <deque>
#include "save.h"
#include "String.h"

extern bool 관찰;

template <typename 반복자>
void f(반복자 iter)
{
	std::cout << typeid(반복자::iterator_category).name() << '\n';
}

//-------------
int main(void)
//-------------
{
	// 클래스 String은 contoguous 메모리를 관리한다.
	// 다음 코드가 실행되게 하라.

	String s{ "0123456789" };

	for (char s : s)
		std::cout << s << ' ';
	std::cout << '\n';

	save("STL.cpp");
}