//-------------------------------------------------------------------
// 2024 1�б� STL ȭ56��56		5�� 16�� ȭ����		(11�� 2)
// 
// Associative Container - set / map
// 
// - equivalence(���, < ) / equality(��, == )
// 
// - default ���ı����� operator<
// - �Լ���ü
// -less<String>�� specializtion
// 
// 6�� 6�� ����� - �����ϰڽ��ϴ�.
// 6�� 13�� ����� (15�� 2��) - �⸻����
//-------------------------------------------------------------------
#include <iostream>
#include <set>
#include <fstream>
#include <algorithm>
#include "save.h"
#include "String.h"

extern bool ����;

//-------------
int main(void)
//-------------
{
	save("STL.cpp");

	std::ifstream in{ "�̻��� ������ �ٸ���.txt" };
	if (not in)
		return 0;

	std::multiset<String> s{ std::istream_iterator<String>{in}, {} };

	std::cout << "�ٸ������� ����� �ܾ� ���� - " << s.size() << '\n';

	// [����] ����ڰ� �Է��� ���ڸ� ������ ��� �ܾ ����϶�.

	while (true) {
		std::cout << "ã�� �ܾ��? ";
		String word;
		std::cin >> word;

		auto cnt = s.contains(word);
		if (cnt)
			std::cout << word << "�� " << cnt << "�� ����ߴ�." << '\n';
		else
			std::cout<< word <<"�� ��������� �ʾҽ��ϴ�."<<'\n';
	}
}