//-----------------------------------------------------------------------
// String.h		STL의 동작을 관찰하기 위함
// 
// 2024. 4. 4
// 2024. 4. 16 - 이동할 때 예외가 발생하지 않음을 보장 - noexcept
// 2024. 4. 30 - list의 merge에 필요한 operator<
// 2024. 5. 7 - begin, end
// 2024. 5. 7 - String_reverse_iterator
// 2024. 5. 7 - begin, end의 return 값을 String_iterator
// 2024. 5. 9 - sort가 문제없이 실행되도록 연산자를 오버로딩하였다
//-----------------------------------------------------------------------
#pragma once
#include <memory>
#include <iostream>

// String 반복자
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

	// 2024. 5. 9 sort에서 요구하는 연산들
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

// 역방향 반복자 - 반복자 어댑터
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