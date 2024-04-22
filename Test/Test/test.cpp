#include <iostream>
#include <fstream>
#include <algorithm>


// [����] "STL.cpp"�� �о� ��� �ҹ��ڸ� �빮�ڷ� ��ȯ�Ͽ�
// "STL�빮��.txt"�� �����϶�.

//-------------
int main(void)
//-------------
{
	std::ifstream in{ "STL.cpp", std::ios::binary };
	if (not in)
		return 1234567890;

	std::ofstream out{ "STL�빮��.txt", std::ios::binary };

	char c;
	while (in.read(&c, sizeof(char)))
		out << (c = toupper(c));

	std::transform(std::istream_iterator<char>{in}, { },
		std::ostreambuf_iterator<char>{std::cout}, [](char c) {
			return toupper(c);
		});

}