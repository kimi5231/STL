//-------------------------------------------------------------------
// 2024 1�б� STL ȭ56��56		3�� 26�� ȭ����		(4�� 1)
// 
// free-store - RAII
// 
// C++���� ������� �ʵ��� �ǰ�
// - char*		-->	string
// - T[N]		-->	array<T, N>
// - T*(raw *)	-->	unique_ptr, shared_ptr(����Ʈ ������)
// 
// RAII - �޸�, FILE, jthread, mutex ��
//-------------------------------------------------------------------
#include <iostream>
#include "save.h"

class Dog
{
public:
	Dog() { std::cout << "����" << '\n'; }
	~Dog() { std::cout << "�Ҹ�" << '\n'; }
};

class ����Ʈ������ {
private:
	Dog* p;
public:
	����Ʈ������(Dog* p) : p(p) {}
	~����Ʈ������() { delete p; }
};

void f()
{
	std::cout << "f ����" << '\n';
	����Ʈ������ p(new Dog);
	throw 1234;
	std::cout << "f ��" << '\n';
}

//-------------
int main(void)
//-------------
{
	std::cout << "main() ����" << '\n';
	try {
		f();
	}
	catch (...) {		// ... elipses
		std::cout << "���ܸ� �޾Ҿ��" << '\n';
	}
	std::cout << "main() ��" << '\n';
}