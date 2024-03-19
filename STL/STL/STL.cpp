//-------------------------------------------------------------------
// 2024 1학기 STL 화56목56		3월 19일 화요일		(3주 1)
// 
// 실행파일의 메모리 구조 - STACK CODE DATA free-store
//-------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include "save.h"

// [문제] "개들"에는 class Dog 객체 100개가 기록되어 있다.
// 파일은 binary 모드이고 모든 객체를 한 번의 write()로 기록하였다.
// 파일을 읽어 가장 num값이 1'0000미만인 Dog 객체는 몇 개인지 정보를 화면에 출력하라.
// class Dog의 멤버는 다음과 같다.
 
class Dog
{
private:
	char c;
	int num;
public:
	int getNum() const {
		return num;
	}
	void show() const {
		std::cout << "Dog, c-" << c << ", num-" << num << '\n';
	}
	friend std::istream& operator>>(std::istream& is, Dog& dog) {
		return is.read((char*)&dog, sizeof(Dog));
	}
};

//-------------
int main(void)
//-------------
{
	// 꼭 바이너리 모드로 읽을 것
	std::ifstream in{ "개들", std::ios::binary };
	if (not in) {
		std::cout << "열 수 없다" << '\n';
		return 0;
	}
	// 100번 째 Dog, c-i, num--2288

	// in 파일의 크기를 filesystem을 이용하여 얻는다.
	// 파일사이즈/sizeof(Dog) -> 100개
	// new Dog[num];

	std::array<Dog, 100> dogs;
	in.read(reinterpret_cast<char*>(dogs.data()), sizeof(Dog) * 100);

	int num = std::count_if(dogs.begin(), dogs.end(), [](const Dog& dog) {
		if (1'0000 > dog.getNum())
			return true;
		return false;
		});
	std::cout << "개수 - " << num << '\n';

	save("STL.cpp");
}