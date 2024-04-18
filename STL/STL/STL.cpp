//-------------------------------------------------------------------
// 2024 1학기 STL 화56목56		4월 18일 목요일		(7주 2)
// 
// 4월 25일 (8주 2일) - 중간시험
// 
// STL container - Sequence - deque(덱)
// 덱 - 
// 
// push_back, push_front -> O(1)
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "save.h"
#include "String.h"

extern bool 관찰;

class Test
{
	char x[4'095];
};

//-------------
int main(void)
//-------------
{
	// std::vector<Test> v;			// 1574803, 2362204
	std::deque<Test> v;			// 4194303

	size_t cnt{};

	while (true) {
		try {
			v.emplace_back();
			++cnt;
		}
		catch(...) {
			std::cout << "최대 개수 - " << v.size() << '\n';
			return 0;
		}
		if (cnt % 10'0000 == 0)
			std::cout << cnt << '\n';
	}

	save("STL.cpp");
}