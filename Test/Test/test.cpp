#include <iostream>
#include <string>
#include <algorithm>
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
	std::string s{ "1357924680" };

	std::sort(s.rbegin(), s.rend());
	for (auto i = s.rbegin(); i != s.rend(); ++i)
		std::cout << *i << ' ';
	std::cout << '\n';
}