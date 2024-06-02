//-------------------------------------------------------------------
// 2024 1학기 STL 화56목56		5월 28일 화요일		(13주 1)
// 
// 6월 6일 목요일 - 강의하겠습니다.
// 6월 13일 목요일 (15주 2일) - 기말시험
// 
// 정렬관련 Algorithm - 복잡도 순으로
// partition		- 조건에 따라 분리
// nth_element		- n등까지와 나머지로 분리
// partial_sort		- n등까지는 정렬된 상태로 나머지는 무관
// sort				- 전체 정렬
// stable_sort
//-------------------------------------------------------------------
#include <iostream>
#include <array>
#include <random>
#include "save.h"
#include "String.h"

extern bool 관찰;

std::random_device rd;
std::default_random_engine dre{ rd() };
std::uniform_int_distribution uid{ 1, 50 };
std::uniform_int_distribution<int> uidC{ 'A', 'Z' };

struct Dog {
	char c;
	int n;

	Dog() {
		c = uidC(dre);
		n = uid(dre);
	}
};

//-------------
int main(void)
//-------------
{
	// stable_sort
	std::array<Dog, 100> dogs;

	sort(dogs.begin(), dogs.end(), [](const Dog& a, const Dog& b) {
		return a.c < b.c;
		});

	for (auto [글자, 숫자] : dogs)
		std::cout << 글자 << " - " << 숫자 << '\n';

	save("STL.cpp");
}