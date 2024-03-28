//-------------------------------------------------------------------
// 2024 1�б� STL ȭ56��56		3�� 28�� �����		(4�� 2)
// 
// callable type -> ���� �������� ����
//-------------------------------------------------------------------
#include <iostream>
#include <array>
#include <random>
#include <print>
#include "save.h"

// [����] int 100���� ������ ������ Ȯ���϶�.
// int 100���� ���� [1, 10000] ���������� �����϶�.
// int�� 100���� C�� qsort�� ����Ͽ� ������������ �����϶�.
// ���İ���� �� �ٿ� 10���� ȭ�鿡 ����϶�.

std::array<int, 100> a;
std::uniform_int_distribution uid{1, 10000};
std::default_random_engine dre;

int ���Ĺ��(const void*, const void*);

//-------------
int main(void)
//-------------
{
	for (int& num : a)
		num = uid(dre);

	// ���⼭ qsort�� �����Ѵ� - qsort�� C�Լ������� generic �Լ��̴�.
	// qsort( ���, ���, �Ѱ��� ũ���, �� ���� ���Ĺ���� �˷��� );

	int (*�Լ�)(const void*, const void*)  = ���Ĺ��;

	qsort(a.data(), a.size(), sizeof(int), �Լ�);

	for (int num : a)
		std::print("{:8}", num);

	save("STL.cpp");
}

int ���Ĺ��(const void* a, const void* b)
{
	return *(int*)b - *(int*)a;
}