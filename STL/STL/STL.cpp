//-------------------------------------------------------------------
// 2024 1�б� STL ȭ56��56		5�� 28�� ȭ����		(13�� 1)
// 
// 6�� 6�� ����� - �����ϰڽ��ϴ�.
// 6�� 13�� ����� (15�� 2��) - �⸻����
// 
// ���İ��� Algorithm - ���⵵ ������
// partition		- ���ǿ� ���� �и�
// nth_element		- n������� �������� �и�
// partial_sort		- n������� ���ĵ� ���·� �������� ����
// sort				- ��ü ����
// stable_sort
//-------------------------------------------------------------------
#include <iostream>
#include <array>
#include <random>
#include "save.h"
#include "String.h"

extern bool ����;

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

	for (auto [����, ����] : dogs)
		std::cout << ���� << " - " << ���� << '\n';

	save("STL.cpp");
}