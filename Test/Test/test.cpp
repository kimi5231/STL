#include <iostream>
#include <string>
#include <algorithm>
#include "String.h"

extern bool ����;

template <typename �ݺ���>
void f(�ݺ��� iter)
{
	// �ݺ����� ������ �Ǵ��ϴ� ǥ�� ����
	std::cout << typeid(�ݺ���::iterator_concept).name() << '\n';
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