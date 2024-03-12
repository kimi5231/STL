//-------------------------------------------------------------------
// 2024 1�б� STL ȭ56��56		3�� 7�� �����		(1�� 2)
// 
// ���� ���� �����͸� ó���� �� �־��...
//-------------------------------------------------------------------
#include <iostream>
#include "save.h"

// [����] main()�� �մ��� ���� �ǵ���� ����ǵ��� change()�� �����ϰ� ����

class Dog
{
private:
	int num;
public:
	Dog(int n) : num(n) {}
	// operator int() { return num; }
	friend std::ostream& operator<<(std::ostream& os, const Dog& ref);
};

std::ostream& operator<<(std::ostream& os, const Dog& ref)
{
	os << ref.num;
	return os;
}

// ���ø� �Լ� ����
template <typename T>
void change(T&, T&);

//-------------
int main(void)
//-------------
{
	Dog a{ 1 }, b{ 2 };

	change(a, b);							// 1. change(Dog, Dog)
											// 2. chage(Dog&, Dog&)
											// 3. ���ø� �ڵ� Ȯ��

	std::cout << a << ", " << b << '\n';	// 2, 1

	save("STL.cpp");
}

template <typename T>
void change(T& a, T& b)
{
	T temp{ a };
	a = b;
	b = temp;
}