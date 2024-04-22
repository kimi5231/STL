#include <iostream>
#include <fstream>
#include <array>
#include <random>

// [문제] int 1000개를 "int값들"에 저장하였다.
// 파일은 binary 모드로 열었고
// 값은 메모리 크기 그대로 4'000 바이트를 기록하였다.
// int값 중 제일 큰 값을 찾아 화면에 출력하라.

std::default_random_engine dre;
std::uniform_int_distribution<int> uidC{ 'a', 'z' };
std::uniform_int_distribution uidNum{ -9999, 9999 };

class Dog
{
	char c{ static_cast<char>(uidC(dre)) };
	int num{ uidNum(dre) };
public:
	friend std::ostream& operator<<(std::ostream& os, const Dog& dog)
	{
		return os << "글자: " << dog.c << ", 숫자: " << dog.num;
	}
};

//-------------
int main(void)
//-------------
{
	std::array<Dog, 100> dogs;

	for (Dog dog : dogs)
		std::cout << dog << '\n';

	std::ofstream out{ "개들", std::ios::binary };
	out.write((char*)dogs.data(), sizeof(Dog) * dogs.size());
}