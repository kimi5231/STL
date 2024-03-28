//-------------------------------------------------------------------
// 2024 1학기 STL 화56목56		3월 28일 목요일		(4주 2)
// 
// callable type -> 정렬 예제에서 시작
//-------------------------------------------------------------------
#include <iostream>
#include <array>
#include <random>
#include <print>
#include "save.h"

// [문제] int 100개를 저장할 공간을 확보하라.
// int 100개의 값을 [1, 10000] 랜덤값으로 설정하라.
// int값 100개를 C의 qsort를 사용하여 오름차순으로 정렬하라.
// 정렬결과를 한 줄에 10개씩 화면에 출력하라.

std::array<int, 100> a;
std::uniform_int_distribution uid{1, 10000};
std::default_random_engine dre;

int 정렬방법(const void*, const void*);

//-------------
int main(void)
//-------------
{
	for (int& num : a)
		num = uid(dre);

	// 여기서 qsort로 정렬한다 - qsort는 C함수이지만 generic 함수이다.
	// qsort( 어디를, 몇개야, 한개의 크기는, 너 만의 정렬방법을 알려줘 );

	int (*함수)(const void*, const void*)  = 정렬방법;

	qsort(a.data(), a.size(), sizeof(int), 함수);

	for (int num : a)
		std::print("{:8}", num);

	save("STL.cpp");
}

int 정렬방법(const void* a, const void* b)
{
	return *(int*)b - *(int*)a;
}