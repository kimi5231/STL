//-------------------------------------------------------------------
// 2024 1�б� STL ȭ56��56		4�� 9�� ȭ����		(6�� 1)
// 
// 4�� 25�� (8�� 1��) - �߰�����
// 
// STL Container - Containers are objects that store other objects.
// �ǽ��� �ð��� ��� �Ѵ�.
//-------------------------------------------------------------------
#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include "save.h"
#include "String.h"

extern bool ����;

//-------------
int main(void)
//-------------
{
	std::array<std::string, 50> a;

	// [����] "STL.cpp"�� �ܾ a�� �����϶�.
	// ���̿����������� a�� �����϶�.
	// ȭ�鿡 ����϶�.

	std::ifstream in{ "STL.cpp" };
	
	for (int i = 0; i < 50; ++i)
		in >> a[i];					// std::string�� �̿��ؼ� ����.

	save("STL.cpp");
}