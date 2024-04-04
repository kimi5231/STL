//-----------------------------------------------------------------------
// String.h		STL�� ������ �����ϱ� ����
// 
// 2024. 4. 4
//-----------------------------------------------------------------------
#pragma once
#include <memory>
#include <iostream>

class String
{
private:	// private�� �ڿ� ���ܼ� ���� ���� ����.
	size_t len{};
	std::unique_ptr<char[]> p{};

	// 2024. 4. 4
	size_t id{};
public:
	// 2024. 4. 4 - �� �� �Լ��� ���� �ʿ䰡 ���������� ������ ���� ����. 
	String( );
	~String();

	String(const char* str);

	// 2024. 4. 4 ���������/�����Ҵ翬����
	String(const String& other);
	String& operator=(const String& rhs);

	// 2024. 4. 4 �̵�������.�̵��Ҵ翬����
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