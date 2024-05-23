//-------------------------------------------------------------------
// 2024 1�б� STL ȭ56��56		5�� 23�� �����		(12�� 2)
// 
// Unordered Associative Container - unordered_set / unordered_map
// - ������ ����
// - �޸𸮸� ��� ����Ͽ� ���⵵�� O(1)�ΰ�
// - ���� ���� String�� �����Ϸ��� ���
// 
// 6�� 6�� ����� - �����ϰڽ��ϴ�.
// 6�� 13�� ����� (15�� 2��) - �⸻����
//-------------------------------------------------------------------
#include <iostream>
#include <unordered_set>
#include <print>
#include "save.h"
#include "String.h"

extern bool ����;

void print_us(const std::unordered_multiset<int>& us)
{
	std::cout << "������� ��Ƽ���� �޸� ����" << '\n';

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
		std::cout << "�߰��� ����? ";
		String str;
		std::cin >> str;
		us.insert(str);
		print_us(us);
		std::cout << '\n' << '\n';
	}
}