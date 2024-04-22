#include <iostream>
#include <fstream>
#include <array>
#include <random>

// [����] int 1000���� "int����"�� �����Ͽ���.
// ������ binary ���� ������
// ���� �޸� ũ�� �״�� 4'000 ����Ʈ�� ����Ͽ���.
// int�� �� ���� ū ���� ã�� ȭ�鿡 ����϶�.

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
		return os << "����: " << dog.c << ", ����: " << dog.num;
	}
};

//-------------
int main(void)
//-------------
{
	std::array<Dog, 100> dogs;

	for (Dog dog : dogs)
		std::cout << dog << '\n';

	std::ofstream out{ "����", std::ios::binary };
	out.write((char*)dogs.data(), sizeof(Dog) * dogs.size());
}