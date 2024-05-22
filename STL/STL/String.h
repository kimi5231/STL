//-----------------------------------------------------------------------
// String.h		STL�� ������ �����ϱ� ����
// 
// 2024. 4. 4
// 2024. 4. 16 - �̵��� �� ���ܰ� �߻����� ������ ���� - noexcept
// 2024. 4. 30 - list�� merge�� �ʿ��� operator<
// 2024. 5. 7 - begin, end
// 2024. 5. 7 - String_reverse_iterator
// 2024. 5. 7 - begin, end�� return ���� String_iterator
// 2024. 5. 9 - sort�� �������� ����ǵ��� �����ڸ� �����ε��Ͽ���
//-----------------------------------------------------------------------
#pragma once
#include <memory>
#include <iostream>

// String �ݺ���
class String_iterator
{
public:
	using difference_type = std::ptrdiff_t;
	using value_type = char;
	using pointer = char*;
	using reference = char&;
	using iterator_category = std::random_access_iterator_tag;

	// C++17
	using iterator_cencpt = std::contiguous_iterator_tag;
private:
	char* p;
public:
	String_iterator(char* p) : p{ p } { };

	reference operator*() const {			// 2024. 5. 9
		return *p;
	};

	char* operator++() {
		return ++p;
	};

	bool operator==(const String_iterator& rhs) const {
		return p == rhs.p;
	}

	// 2024. 5. 9 sort���� �䱸�ϴ� �����
	difference_type operator-(const String_iterator & rhs) const {
		return p - rhs.p;
	}

	//const char operator*() {
	//	return *p;
	//};

	String_iterator& operator--() {
		--p;
		return *this;
	};

	String_iterator operator+(const difference_type diff) const {
		return String_iterator{ p + diff };
	}

	bool operator<(const String_iterator& rhs) const {
		return p < rhs.p;
	}

	String_iterator operator-(const difference_type diff) const {
		return String_iterator{ p - diff };
	}
};

// ������ �ݺ��� - �ݺ��� �����
class String_reverse_iterator
{
public:
	using difference_type = std::ptrdiff_t;
	using value_type = char;
	using pointer = char*;
	using reference = char&;
	using iterator_category = std::random_access_iterator_tag;

	// C++17
	using iterator_cencpt = std::contiguous_iterator_tag;
private:
	char* p;
public:
	String_reverse_iterator(char* p) : p{p} { };

	char operator*() {
		return *(p - 1);
	};

	char* operator++() {
		return --p;
	};

	bool operator==(const String_reverse_iterator& rhs) const {
		return p == rhs.p;
	}
};

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

	// interface
	// 2024. 5. 7
	String_iterator begin() const {
		return String_iterator{ p.get() };
	}

	String_iterator end() const {
		return String_iterator{p.get() + len};
	}

	String_reverse_iterator rbegin() const {
		return String_reverse_iterator{ p.get() + len };
	}

	String_reverse_iterator rend() const {
		return String_reverse_iterator{ p.get() };
	}

	bool contains(const String& s) {

	}

	friend std::ostream& operator<<(std::ostream& os, const String& s);

	// 2024. 4. 11
	friend std::istream& operator>>(std::istream& is, String& s);
private:
	static size_t uid;
};