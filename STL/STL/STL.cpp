//-------------------------------------------------------------------
// 2024 1�б� STL ȭ56��56		4�� 18�� �����		(7�� 2)
// 
// 4�� 25�� (8�� 2��) - �߰�����
// 
// STL container - Sequence - deque(��)
// �� - 
// 
// push_back, push_front -> O(1)
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "save.h"
#include "String.h"

extern bool ����;

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
			std::cout << "�ִ� ���� - " << v.size() << '\n';
			return 0;
		}
		if (cnt % 10'0000 == 0)
			std::cout << cnt << '\n';
	}

	save("STL.cpp");
}