//-------------------------------------------------------------------
// 2024 1�б� STL ȭ56��56		6�� 6�� �����		(14�� 2)
// 
// 6�� 6�� ����� - �����ϰڽ��ϴ�.
// 6�� 13�� ����� (15�� 2��) - �⸻����
// 
// C++20 Concept / Range
// 
// for/accumulate/reduce
//-------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <array>
#include <random>
#include <chrono>
#include <numeric>
#include <execution>
#include "save.h"
#include "String.h"

std::default_random_engine dre;
std::uniform_int_distribution uid;

std::array<int, 2'5000'0000> a;

// for - loop
// �ɸ� �ð� - 84ms
// �հ� - 268416090773281637

// �˰��� - accumulate
// �ɸ� �ð� - 80ms
// �հ� - 268416090773281637

// �˰��� - reduce(execution::par)
// �ɸ� �ð� - 35ms
// �հ� - 268416090773281637

//-------------
int main(void)
//-------------
{
	for (int& num : a)
		num = uid(dre);

	// �ջ�
	long long sum{};

	auto b = std::chrono::high_resolution_clock::now();
	sum = std::reduce(std::execution::par, a.begin(), a.end(), 0LL);
	auto d = std::chrono::high_resolution_clock::now() - b;
	std::cout << "�ɸ� �ð� - " << std::chrono::duration_cast<std::chrono::milliseconds>(d) << '\n';
	std::cout << "�հ� - " << sum << '\n';

	save("STL.cpp");
}