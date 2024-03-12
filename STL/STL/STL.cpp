//-------------------------------------------------------------------
// 2024 1학기 STL 화56목56		3월 7일 목요일		(1주 2)
// 
// 많은 수의 데이터를 처리할 수 있어야...
//-------------------------------------------------------------------
#include <iostream>
#include "save.h"

// [문제] main()을 손대지 말고 의도대로 실행되도록 change()를 선언하고 정의

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

// 템플릿 함수 선언
template <typename T>
void change(T&, T&);

//-------------
int main(void)
//-------------
{
	Dog a{ 1 }, b{ 2 };

	change(a, b);							// 1. change(Dog, Dog)
											// 2. chage(Dog&, Dog&)
											// 3. 템플릿 코드 확장

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