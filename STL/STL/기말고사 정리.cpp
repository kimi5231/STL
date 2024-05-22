#include <iostream>
#include <list>
#include <fstream>
#include "String.h"

// 배웠으나 관련 문제가 없는 것
void MergeList(void);

// 지금까지 나왔던 문제
void Problem1(void);

int main(void)
{
	// 배웠으나 관련 문제가 없는 것
	//MergeList();

	// 지금까지 나왔던 문제
	Problem1();
}

// 배웠으나 관련 문제가 없는 것
//---------------------------------------------------------------------------------------
void MergeList(void)
{
	std::list<String> cont1{ "1", "22", "333", "4444", "55555" };
	std::list<String> cont2{ "1", "22", "a", "bb", "333", "4444", "55555" };

	cont2.sort();

	// 두 리스트가 이미 정렬되어 있다고 가정하고 합침
	// cont1에 cont2를 합침
	cont1.merge(cont2);

	for (const String& s : cont1)
		std::cout << s << '\n';
}
//---------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------
// [문제1] 파일 "STL.cpp"의 단어를 읽어 정렬하라.
void Problem1(void)
{
	std::ifstream in{ "STL.cpp" };

	std::list<String> cont{ std::istream_iterator<String>{in}, {} };

	cont.sort();
	// 중복된 원소 삭제
	cont.unique();

	for (const String& s : cont)
		std::cout << s << '\n';
}
//---------------------------------------------------------------------------------------