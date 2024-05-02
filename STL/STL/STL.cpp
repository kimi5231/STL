//-------------------------------------------------------------------
// 2024 1�б� STL ȭ56��56		5�� 2�� ȭ����		(9�� 2)
// 
// Iterator - �ݺ��ڴ� �����͸� �Ϲ�ȭ �� ���̴�.
// 
// Iterators are a generalization of pointers
// that allow a C++ program to work with different data structures
// in a uniform manner.
//-------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <list>
#include<forward_list>
#include <deque>
#include "save.h"
#include "String.h"

extern bool ����;

template <typename �ݺ���>
void f(�ݺ��� iter)
{
	std::cout << typeid(�ݺ���::iterator_category).name() << '\n';
}

//-------------
int main(void)
//-------------
{
	// Ŭ���� String�� contoguous �޸𸮸� �����Ѵ�.
	// ���� �ڵ尡 ����ǰ� �϶�.

	String s{ "0123456789" };

	for (char s : s)
		std::cout << s << ' ';
	std::cout << '\n';

	save("STL.cpp");
}