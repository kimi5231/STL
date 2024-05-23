//-------------------------------------------------------------------
// 2024 1학기 STL 화56목56		5월 23일 목요일		(12주 2)
// 
// Unordered Associative Container - unordered_set / unordered_map
// - 순서가 없다
// - 메모리를 어떻게 사용하여 복잡도가 O(1)인가
// - 내가 만든 String을 저장하려면 어떻게
// 
// 6월 6일 목요일 - 강의하겠습니다.
// 6월 13일 목요일 (15주 2일) - 기말시험
//-------------------------------------------------------------------
#include <iostream>
#include <unordered_set>
#include <print>
#include "save.h"
#include "String.h"

extern bool 관찰;

void print_us(const std::unordered_multiset<int>& us)
{
	std::cout << "언오더드 멀티셋의 메모리 구조" << '\n';

	for (int i = 0; i < us.bucket_count(); ++i) {
		std::print("[{:3}]", i);
		for (auto p = us.begin(i); p != us.end(i); ++p)
			std::cout << " - " << *p;
		std::cout << '\n';
	}
}

//-------------
int main(void)
//-------------
{
	save("STL.cpp");

	std::unordered_multiset<String> us{ "3", "1", "4", "2" };
	
	while (true) {
		std::cout << "추가할 값은? ";
		String str;
		std::cin >> str;
		us.insert(str);
		print_us(us);
		std::cout << '\n' << '\n';
	}
}