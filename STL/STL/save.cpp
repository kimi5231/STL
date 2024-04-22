//-------------------------------------------------------------------
// save.cpp		���б� ���Ǹ� �����Ѵ�.
// 
// 2024. 3. 7
//-------------------------------------------------------------------
#include <string_view>
#include <fstream>
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include "save.h"

//-----------------------------------
void save(std::string_view fileName)
//-----------------------------------
{
	// fileName�� �б������ ����.
	std::ifstream in{ fileName.data() };	//RAII
	if (not in) {
		std::cout << fileName << " ���� ����" << '\n';
		exit(0);
	}

	// ������ ������ ���ٿ� ������� ����.
	std::ofstream out{ "2024 1�б� STL ȭ56��56 ��������.txt", std::ios::app };

	// ���� ������ ������ �о� �� ���Ͽ� �����δ�.
	// STL �ڷᱸ���� �˰����� �̿��Ͽ� ����Ѵ�. (������ �ƴϴ�)
	std::vector<char> v{ std::istreambuf_iterator<char>{in}, {} };

	// ���� time_point�� ��´�.
	auto now = std::chrono::system_clock::now();	// epoch���κ��� �帥 tick
	// UTC �ð��������� ��ȯ
	auto utc = std::chrono::system_clock::to_time_t(now);
	// ���� �ð����� ��ȯ
	auto It = localtime(&utc);	//c �Լ�

	// �ѱ��������� ����Ѵ�. (��½�Ʈ���� ������ ��ȯ)
	auto old = out.imbue(std::locale("ko_KR"));

	// �ð��� ����Ѵ�.
	out << '\n' << '\n';
	out << "=========================================================" << '\n';
	out << fileName << std::put_time(It, ": %x %A %X") << '\n';
	out << "=========================================================" << '\n';
	out << '\n';

	out.imbue(old); // �̿��ϰ� ���������.

	std::copy(v.begin(), v.end(), std::ostreambuf_iterator<char>{ out });
}