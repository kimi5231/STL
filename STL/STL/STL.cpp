//-------------------------------------------------------------------
// 2024 1�б� STL ȭ56��56		3�� 14�� �����		(2�� 2)
// 
// FILE I/O text/binary - high/low level
//-------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <array>
#include <random>
#include "save.h"

// [����] "����"���� class Dog ��ü 100���� ��ϵǾ� �ִ�.
// ������ binary ����� write �Լ��� sizeof(Dog)*100 ����Ʈ�� ����Ͽ���.
// ������ �о� ���� num���� ū Dog ������ ȭ�鿡 ����϶�.
// class Dog�� ����� ������ ����.
 
class Dog
{
private:
	char c;
	int num;
};

//-------------
int main(void)
//-------------
{
	save("STL.cpp");
}