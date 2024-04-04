//-----------------------------------------------------------------------
// String.h		STL의 동작을 관찰하기 위함
// 
// 2024. 4. 4
//-----------------------------------------------------------------------
#pragma once
#include <memory>
#include <iostream>

class String
{
private:	// private는 뒤에 숨겨서 쓰는 것이 좋음.
	size_t len{};
	std::unique_ptr<char[]> p{};

	// 2024. 4. 4
	size_t id{};
public:
	// 2024. 4. 4 - 이 두 함수는 만들 필요가 전혀없지만 관찰을 위해 만듦. 
	String( );
	~String();

	String(const char* str);

	// 2024. 4. 4 복사생성자/복사할당연산자
	String(const String& other);
	String& operator=(const String& rhs);

	// 2024. 4. 4 이동생성자.이동할당연산자
	String(String&&);
	String& operator=(String&&);

	// 2024. 4. 4 get/set
	size_t getLen() const;
	char* getData() const;

	friend std::ostream& operator<<(std::ostream& os, const String& s) {
		for (size_t i = 0; i < s.len; i++)
			os << s.p.get()[i];
		return os;
	}
private:
	static size_t uid;
};