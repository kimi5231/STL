#include <iostream>
#include <vector>
#include <string>

template <typename �ݺ���>
void f(�ݺ��� iter)
{
	std::cout << typeid(iter).name() << '\n';
}

//-------------
int main(void)
//-------------
{
	std::vector<int> v;
	std::ostream_iterator<char> p{ std::cout };

	f(v.begin());
	f(p);
}