//-------------------------------------------------------------------
// 2024 1�б� STL ȭ56��56		3�� 12�� ȭ����		(2�� 1)
// 
// ���� ���� �����͸� ó���� �� �־��...
//-------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <algorithm>
#include "save.h"

// [����] "int����.txt"���� �� ������ �𸣴� int���� �ִ�.
// ���� ū ���� ã�� ȭ�鿡 ����϶�.

//-------------
int main(void)
//-------------
{
	std::ifstream in{ "int����.txt" };
	if (not in) 
		exit(0);
	
	std::cout << "�ִ밪: " << *std::max_element(std::istream_iterator<int>{in}, { }) << '\n';

	save("STL.cpp");
}