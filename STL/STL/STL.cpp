//-------------------------------------------------------------------
// 2024 1�б� STL ȭ56��56		5�� 7�� ȭ����		(10�� 1)
// 
// Iterator - �ݺ��ڴ� �����͸� �Ϲ�ȭ �� ���̴�.
// 
// Iterators are a generalization of pointers
// that allow a C++ program to work with different data structures
// in a uniform manner.
//-------------------------------------------------------------------
#include <iostream>
#include <string>
#include <algorithm>
#include <span>
#include "save.h"
#include "String.h"

extern bool ����;

template <typename �ݺ���>
void f(�ݺ��� iter)
{
	// �ݺ����� ������ �Ǵ��ϴ� ǥ�� ����
	std::cout << typeid(�ݺ���::iterator_concept).name() << '\n';
}

//-------------
int main(void)
//-------------
{
	String s{ "1357924680" };

	// s�� �ݺ��ڰ� - random_access_iterator_tag

	save("STL.cpp");
}