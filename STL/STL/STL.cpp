//-------------------------------------------------------------------
// 2024 1�б� STL ȭ56��56		4�� 18�� ȭ����		(8�� 1)
// 
// 4�� 25�� (8�� 2��) - �߰�����
// 
// list
//-------------------------------------------------------------------
#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <fstream>
#include <string>
#include <algorithm>
#include "save.h"
#include "String.h"

extern bool ����;

//-------------
int main(void)
//-------------
{
	std::list<String> cont;

	
	// [����] ���� "String.cpp"�� �о� cont�� �����϶�.
	std::ifstream in{ "String.cpp", std::ios::binary };
	if (not in)
		return 0;

	cont = { std::istream_iterator<String>{in}, {} };

	// cont�� ���̿����������� �����϶�.
	cont.sort([](const String& a, const String& b) {
		return a.getLen() < b.getLen();
		});

	// [����] cont���� ���̰� 5�� ���Ҹ� ȭ�鿡 ����϶�.
	copy_if(cont.begin(), cont.end(), std::ostream_iterator<String>{std::cout, "\n"},
		[](const String& s) {
			return s.getLen() == 5;
		});

	save("STL.cpp");
}