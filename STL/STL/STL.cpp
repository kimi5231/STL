//-------------------------------------------------------------------
// 2024 1�б� STL ȭ56��56		5�� 14�� ȭ����		(11�� 1)
// 
// �˰��� �Լ� - �ݺ��ڸ� ���ڷ� �޴´�
// 
// 6�� 6�� ����� - �����ϰڽ��ϴ�.
// 6�� 13�� ����� (15�� 2��) - �⸻����
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include "save.h"
#include "String.h"

extern bool ����;

template <class InIter, class OutIter>
void my_copy(InIter b, InIter e, OutIter d)
{
	while (b != e) {
		*d = *b;
		++b;
		++d;
	}
}

// [�ǽ�] ������ �����ε�
//-------------
int main(void)
//-------------
{
	save("STL.cpp");

	String s{ "STL aldorithm 2024�� 5�� 14��" };
	std::vector<char> v{s.getLen()};
	
	my_copy(s.begin(), s.end(), back_inserter(v));

	for (char c : v)
		std::cout << v[i];
	std::cout << '\n';
}