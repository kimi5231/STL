//-----------------------------------------------------------------------
// String.h		STL의 동작을 관찰하기 위함
// 
// 2024. 4. 4
// 2024. 4. 16 - 이동할 때 예외가 발생하지 않음을 보장 - noexcept
// 2024. 4. 30 - list의 merge에 필요한 operator<
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
	// 2024. 4. 16 noexcept
	String(String&&) noexcept;
	String& operator=(String&&) noexcept;

	// 2024. 4. 18
	bool operator==(const String& rhs) const;

	// 2024. 4. 30
	bool operator<(const String& rhs) const;

	// 2024. 4. 4 get/set
	size_t getLen() const;
	char* getData() const;

	friend std::ostream& operator<<(std::ostream& os, const String& s);

	// 2024. 4. 11
	friend std::istream& operator>>(std::istream& is, String& s);
private:
	static size_t uid;
};