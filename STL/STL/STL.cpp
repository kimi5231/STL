//-------------------------------------------------------------------
// 2024 1�б� STL ȭ56��56		3�� 19�� ȭ����		(3�� 1)
// 
// ���������� �޸� ���� - STACK CODE DATA free-store
//-------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include "save.h"

// [����] "����"���� class Dog ��ü 100���� ��ϵǾ� �ִ�.
// ������ binary ����̰� ��� ��ü�� �� ���� write()�� ����Ͽ���.
// ������ �о� ���� num���� 1'0000�̸��� Dog ��ü�� �� ������ ������ ȭ�鿡 ����϶�.
// class Dog�� ����� ������ ����.
 
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
	// �� ���̳ʸ� ���� ���� ��
	std::ifstream in{ "����", std::ios::binary };
	if (not in) {
		std::cout << "�� �� ����" << '\n';
		return 0;
	}
	// 100�� ° Dog, c-i, num--2288

	// in ������ ũ�⸦ filesystem�� �̿��Ͽ� ��´�.
	// ���ϻ�����/sizeof(Dog) -> 100��
	// new Dog[num];

	std::array<Dog, 100> dogs;
	in.read(reinterpret_cast<char*>(dogs.data()), sizeof(Dog) * 100);

	int num = std::count_if(dogs.begin(), dogs.end(), [](const Dog& dog) {
		if (1'0000 > dog.getNum())
			return true;
		return false;
		});
	std::cout << "���� - " << num << '\n';

	save("STL.cpp");
}