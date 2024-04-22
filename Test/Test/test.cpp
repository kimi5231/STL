#include <iostream>
#include <fstream>
#include <algorithm>


// [문제] "STL.cpp"를 읽어 모든 소문자를 대문자로 변환하여
// "STL대문자.txt"에 저장하라.

//-------------
int main(void)
//-------------
{
	std::ifstream in{ "STL.cpp", std::ios::binary };
	if (not in)
		return 1234567890;

	std::ofstream out{ "STL대문자.txt", std::ios::binary };

	char c;
	while (in.read(&c, sizeof(char)))
		out << (c = toupper(c));

	std::transform(std::istream_iterator<char>{in}, { },
		std::ostreambuf_iterator<char>{std::cout}, [](char c) {
			return toupper(c);
		});

}