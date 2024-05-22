//-------------------------------------------------------------------
// 2024 1�б� STL ȭ56��56		5�� 21�� ȭ����		(12�� 1)
// 
// Associative Container - set / map
// 
// map<Key, value> - dictionary
// 
// 6�� 6�� ����� - �����ϰڽ��ϴ�.
// 6�� 13�� ����� (15�� 2��) - �⸻����
//-------------------------------------------------------------------
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <fstream>
#include "save.h"
#include "String.h"

extern bool ����;

//-------------
int main(void)
//-------------
{
	// [����] �Ҽ��� ���� �����ڿ� �� ���Ƚ���� Ƚ������ ������������ ����϶�.
	// �빮�ڴ� �ҹ��ڷ� ��ȯ�Ѵ�.
	std::map<char, int> cim;

	std::ifstream in{ "�̻��� ������ �ٸ���.txt" };

	char c;
	while (in >> c) {
		if (isalpha(c))
			cim[tolower(c)]++;
	}

	for (auto [�ҹ���, Ƚ��] : cim)
		std::cout << �ҹ��� << " - " << Ƚ�� << '\n';

	save("STL.cpp");
}