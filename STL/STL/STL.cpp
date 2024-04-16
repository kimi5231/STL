//-------------------------------------------------------------------
// 2024 1학기 STL 화56목56		4월 16일 화요일		(7주 1)
// 
// 4월 25일 (8주 2일) - 중간시험
// 
// STL container - Sequence - vector(dynamic array - [] operator)
// 
// push_back(T) - amortized O(1)
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <array>
#include <print>
#include <numeric>
#include "save.h"
#include "String.h"

extern bool 관찰;

//-------------
int main(void)
//-------------
{
	std::vector<int> v(100);
	std::iota(v.begin(), v.end(), 1);

	// [문제] v에서 홀수를 제거하라
	/*remove_if(v.begin(), v.end(), [](int num) {
		return num % 2;
		});*/
	erase_if(v, [](int num) {
		return num&1;	// 제일 오른쪽 비트가 1이면 홀수
		});

	for (int num : v)
		std::print("{:8}", num);

	save("STL.cpp");
}