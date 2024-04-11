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

	friend std::ostream& operator<<(std::ostream& os, const String& s);

	// 2024. 4. 11
	friend std::istream& operator>>(std::istream& is, String& s);
private:
	static size_t uid;
};