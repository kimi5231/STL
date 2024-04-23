#include <iostream>
#include <vector>
#include <string>

//-------------
int main(void)
//-------------
{
	std::vector<std::string> v;
	std::cout << "v의 용량 - " << v.capacity() << '\n';

	v.push_back("2024년");
}