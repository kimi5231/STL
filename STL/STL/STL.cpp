//-------------------------------------------------------------------
// 2024 1학기 STL 화56목56		4월 2일 화요일		(5주 1)
// 
// 4월 25일 (8주 1일) - 중간시험
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
	String s{ "STL 공부를 위한 클래스" };
	String t = s;

	std::cout << s << '\n';
	std::cout << t << '\n';

	save("STL.cpp");
}