#include <iostream>
#include <set>
#include <fstream>
#include <algorithm>
#include <string>

extern bool ����;

//-------------
int main(void)
//-------------
{
	std::ifstream in{ "�̻��� ������ �ٸ���.txt" };
	if (not in)
		return 0;

	std::multiset<std::string> s{ std::istream_iterator<std::string>{in}, {} };

	std::cout << "�ٸ������� ����� �ܾ� ���� - " << s.size() << '\n';

	// [����] ����ڰ� �Է��� �ܾ �� �Ҽ��� �ִ� �ܾ����� �˷�����.

	while (true) {
		std::cout << "ã�� �ܾ��? ";
		std::string word;
		std::cin >> word;

		auto p = s.find(word);
		if (p != s.end())
			std::cout << word << "�� �ִ� �ܾ��Դϴ�." << '\n';
		else
			std::cout << word << "�� ��������� �ʾҽ��ϴ�." << '\n';
	}
}