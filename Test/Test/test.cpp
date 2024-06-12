#include <iostream>
#include <set>
#include <fstream>
#include <algorithm>
#include <string>

extern bool 관찰;

//-------------
int main(void)
//-------------
{
	std::ifstream in{ "이상한 나라의 앨리스.txt" };
	if (not in)
		return 0;

	std::multiset<std::string> s{ std::istream_iterator<std::string>{in}, {} };

	std::cout << "앨리스에서 사용한 단어 개수 - " << s.size() << '\n';

	// [문제] 사용자가 입력한 단어가 이 소설에 있는 단어인지 알려주자.

	while (true) {
		std::cout << "찾을 단어는? ";
		std::string word;
		std::cin >> word;

		auto p = s.find(word);
		if (p != s.end())
			std::cout << word << "는 있는 단어입니다." << '\n';
		else
			std::cout << word << "를 사용하지는 않았습니다." << '\n';
	}
}