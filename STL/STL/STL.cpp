//-------------------------------------------------------------------
// 2024 1학기 STL 화56목56		3월 26일 화요일		(4주 1)
// 
// free-store - RAII
// 
// C++언어에서 사용하지 않도록 권고
// - char*		-->	string
// - T[N]		-->	array<T, N>
// - T*(raw *)	-->	unique_ptr, shared_ptr(스마트 포인터)
// 
// RAII - 메모리, FILE, jthread, mutex 등
//-------------------------------------------------------------------
#include <iostream>
#include "save.h"

class Dog
{
public:
	Dog() { std::cout << "생성" << '\n'; }
	~Dog() { std::cout << "소멸" << '\n'; }
};

class 스마트포인터 {
private:
	Dog* p;
public:
	스마트포인터(Dog* p) : p(p) {}
	~스마트포인터() { delete p; }
};

void f()
{
	std::cout << "f 시작" << '\n';
	스마트포인터 p(new Dog);
	throw 1234;
	std::cout << "f 끝" << '\n';
}

//-------------
int main(void)
//-------------
{
	std::cout << "main() 시작" << '\n';
	try {
		f();
	}
	catch (...) {		// ... elipses
		std::cout << "예외를 받았어요" << '\n';
	}
	std::cout << "main() 끝" << '\n';
}