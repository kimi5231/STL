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
		"2024년", "4월", "4일", "목요일", "즐거운 STL"
	};

	for (std::string s : a)
		std::cout << s << '\n';

}