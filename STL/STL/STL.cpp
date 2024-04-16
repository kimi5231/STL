//-------------------------------------------------------------------
// 2024 1�б� STL ȭ56��56		4�� 16�� ȭ����		(7�� 1)
// 
// 4�� 25�� (8�� 2��) - �߰�����
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

extern bool ����;

//-------------
int main(void)
//-------------
{
	std::vector<int> v(100);
	std::iota(v.begin(), v.end(), 1);

	// [����] v���� Ȧ���� �����϶�
	/*remove_if(v.begin(), v.end(), [](int num) {
		return num % 2;
		});*/
	erase_if(v, [](int num) {
		return num&1;	// ���� ������ ��Ʈ�� 1�̸� Ȧ��
		});

	for (int num : v)
		std::print("{:8}", num);

	save("STL.cpp");
}