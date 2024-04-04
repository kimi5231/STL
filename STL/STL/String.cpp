//-----------------------------------------------------------------------
// String.cpp 	STL의 동작을 관찰하기 위함
// 
// 2024. 4. 4 시작
// 2024. 4. 4 관찰메시지
//-----------------------------------------------------------------------
#include "String.h"
#include <memory>

bool 관찰{ false };

size_t String::uid{};

// 2024. 4. 4 - 디폴트 생성자와 소멸자는 만들 필요가 전혀없지만 관찰을 위해 만듦. 
String::String()
	: id{ ++uid }
{
	if(관찰)
		std::cout << "[" << id << "] - 디폴트, 개수:" << len << ", 주소:"
			<< static_cast<void*>(p.get()) << '\n';
}

String::~String()
{
	if (관찰)
		std::cout << "[" << id << "] - 소멸, 개수:" << len << ", 주소:"
			<< static_cast<void*>(p.get()) << '\n';
}

String::String(const char* str)
	: len(strlen(str)), id{++uid}
{
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), str, len);

	if (관찰)
		std::cout << "[" << id << "] - 생성(char*), 개수:" << len << ", 주소:"
			<< static_cast<void*>(p.get()) << '\n';
}

// 2024. 4. 4 복사생성자/복사할당연산자
String::String(const String& other)
	: len(other.len), id{ ++uid }
{
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);

	if (관찰)
		std::cout << "[" << id << "] - 복사생성, 개수:" << len << ", 주소:"
			<< static_cast<void*>(p.get()) << '\n';
}

String& String::operator=(const String& rhs)
{
	if (this == &rhs)
		return *this;

	len = rhs.len;
	p.release();
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), rhs.p.get(), len);

	if (관찰)
		std::cout << "[" << id << "] - 복사할당, 개수:" << len << ", 주소:"
			<< static_cast<void*>(p.get()) << '\n';
}

// 2024. 4. 4 이동생성자.이동할당연산자
String::String(String&& other)
	: len{other.len}, id{++uid}
{
	p.reset(other.p.get());

	other.p.release();
	other.len = 0;

	if (관찰)
		std::cout << "[" << id << "] - 이동생성, 개수:" << len << ", 주소:"
		<< static_cast<void*>(p.get()) << '\n';
}

String& String::operator=(String&& rhs)
{
	if (this == &rhs)
		return *this;

	len = rhs.len;
	p.reset(rhs.p.get());
	
	rhs.len = 0;
	rhs.p.release();

	if (관찰)
		std::cout << "[" << id << "] - 이동할당연산자, 개수:" << len << ", 주소:"
		<< static_cast<void*>(p.get()) << '\n';

	return *this;
}

// 2024. 4. 4 get/set
size_t String::getLen() const
{
	return len;
}

char* String::getData() const
{
	return p.get();
}