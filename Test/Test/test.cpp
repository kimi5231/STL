#include <iostream>
#include <vector>
#include <string>

template <typename 반복자>
void f(반복자 iter)
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