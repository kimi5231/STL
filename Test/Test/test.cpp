#include <iostream>
#include <array>
#include <random>
#include <print>
#include <algorithm>
#include <string>

//-------------
int main(void)
//-------------
{
	std::array<std::string, 5> a{
		"2024��", "4��", "4��", "�����", "��ſ� STL"
	};

	for (std::string s : a)
		std::cout << s << '\n';

}