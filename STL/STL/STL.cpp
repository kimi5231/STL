//-------------------------------------------------------------------
// 2024 1�б� STL ȭ56��56		4�� 11�� �����		(6�� 2)
// 
// 4�� 25�� (8�� 1��) - �߰�����
// 
// STL container - Sequence - vector(dynamic array - [] operator)
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <ranges>
#include "save.h"
#include "String.h"

extern bool ����;

//-------------
int main(void)
//-------------
{
	���� = true;

	// [����] Ű���忡�� �Է��� int ���� �հ�� ��հ��� ����϶�.
	std::vector<int>v{ std::istream_iterator<int>{std::cin}, { } };

	for (int num : v)
		std::cout << num << ' ';
	std::cout << '\n';

	save("STL.cpp");
}