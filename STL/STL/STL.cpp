//-------------------------------------------------------------------
// 2024 1�б� STL ȭ56��56		4�� 2�� ȭ����		(5�� 1)
// 
// 4�� 25�� (8�� 1��) - �߰�����
//-------------------------------------------------------------------
#include <iostream>
#include <cstring>
#include "save.h"

class String
{
private:
	size_t len{};
	std::unique_ptr<char[]> p{};
public:
	String(const char* str) : len(strlen(str)) {
		p = std::make_unique<char[]>(len);
		memcpy(p.get(), str, len);
	}
	friend std::ostream& operator<<(std::ostream& os, const String& s) {
		for (size_t i = 0; i < s.len; i++)
			os << s.p.get()[i];
		return os;
	}
};

//-------------
int main(void)
//-------------
{
	String s{ "STL ���θ� ���� Ŭ����" };
	String t = s;

	std::cout << s << '\n';
	std::cout << t << '\n';

	save("STL.cpp");
}