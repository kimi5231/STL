//-----------------------------------------------------------------------
// String.cpp 	STL�� ������ �����ϱ� ����
// 
// 2024. 4. 4 ����
// 2024. 4. 4 �����޽���
// 2024. 4. 16 noexcept
//-----------------------------------------------------------------------
#include "String.h"
#include <memory>
#include <algorithm>

bool ����{ false };

size_t String::uid{};

// 2024. 4. 4 - ����Ʈ �����ڿ� �Ҹ��ڴ� ���� �ʿ䰡 ���������� ������ ���� ����. 
String::String()
	: id{ ++uid }
{
	if(����)
		std::cout << "[" << id << "] - ����Ʈ, ����:" << len << ", �ּ�:"
			<< static_cast<void*>(p.get()) << '\n';
}

String::~String()
{
	if (����)
		std::cout << "[" << id << "] - �Ҹ�, ����:" << len << ", �ּ�:"
			<< static_cast<void*>(p.get()) << '\n';
}

String::String(const char* str)
	: len(strlen(str)), id{++uid}
{
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), str, len);

	if (����)
		std::cout << "[" << id << "] - ����(char*), ����:" << len << ", �ּ�:"
			<< static_cast<void*>(p.get()) << '\n';
}

// 2024. 4. 4 ���������/�����Ҵ翬����
String::String(const String& other)
	: len(other.len), id{ ++uid }
{
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);

	if (����)
		std::cout << "[" << id << "] - �������, ����:" << len << ", �ּ�:"
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

	if (����)
		std::cout << "[" << id << "] - �����Ҵ�, ����:" << len << ", �ּ�:"
			<< static_cast<void*>(p.get()) << '\n';
}

// 2024. 4. 4 �̵�������.�̵��Ҵ翬����
// 2024. 4. 16 noexcept
String::String(String&& other) noexcept
	: len{other.len}, id{++uid}
{
	p.reset(other.p.get());

	other.p.release();
	other.len = 0;

	if (����)
		std::cout << "[" << id << "] - �̵�����, ����:" << len << ", �ּ�:"
		<< static_cast<void*>(p.get()) << '\n';
}

String& String::operator=(String&& rhs) noexcept
{
	if (this == &rhs)
		return *this;

	len = rhs.len;
	p.reset(rhs.p.get());
	
	rhs.len = 0;
	rhs.p.release();

	if (����)
		std::cout << "[" << id << "] - �̵��Ҵ翬����, ����:" << len << ", �ּ�:"
		<< static_cast<void*>(p.get()) << '\n';

	return *this;
}

// 2024. 4. 18
bool String::operator==(const String& rhs) const
{
	// "1" == "11"
	if (len != rhs.len)
		return false;

	return std::equal(p.get(), p.get() + len, rhs.p.get());
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

// ������ϱ� ���� �����Լ�
std::ostream& operator<<(std::ostream& os, const String& s) {
	for (size_t i = 0; i < s.len; i++)
		os << s.p.get()[i];
	return os;
}

// 2024. 4. 11
std::istream& operator>>(std::istream& is, String& s) {
	std::string ts;
	is >> ts;

	s.len = ts.size();
	s.p = std::make_unique<char[]>(s.len);
	memcpy(s.p.get(), ts.data(), s.len);

	return is;
}