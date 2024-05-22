#include <iostream>
#include <list>
#include <fstream>
#include "String.h"

// ������� ���� ������ ���� ��
void MergeList(void);

// ���ݱ��� ���Դ� ����
void Problem1(void);

int main(void)
{
	// ������� ���� ������ ���� ��
	//MergeList();

	// ���ݱ��� ���Դ� ����
	Problem1();
}

// ������� ���� ������ ���� ��
//---------------------------------------------------------------------------------------
void MergeList(void)
{
	std::list<String> cont1{ "1", "22", "333", "4444", "55555" };
	std::list<String> cont2{ "1", "22", "a", "bb", "333", "4444", "55555" };

	cont2.sort();

	// �� ����Ʈ�� �̹� ���ĵǾ� �ִٰ� �����ϰ� ��ħ
	// cont1�� cont2�� ��ħ
	cont1.merge(cont2);

	for (const String& s : cont1)
		std::cout << s << '\n';
}
//---------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------
// [����1] ���� "STL.cpp"�� �ܾ �о� �����϶�.
void Problem1(void)
{
	std::ifstream in{ "STL.cpp" };

	std::list<String> cont{ std::istream_iterator<String>{in}, {} };

	cont.sort();
	// �ߺ��� ���� ����
	cont.unique();

	for (const String& s : cont)
		std::cout << s << '\n';
}
//---------------------------------------------------------------------------------------