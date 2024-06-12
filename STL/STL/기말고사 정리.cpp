#include <iostream>
#include <list>
#include <fstream>
#include <span>
#include <algorithm>
#include <vector>
#include <deque>
#include <forward_list>
#include <string>
#include <set>
#include <map>
#include <ranges>
#include "String.h"

// 배웠으나 관련 문제가 없는 것
void MergeList(void);
void Span(void);
void OstreamIterator(void);
void TemplateIteratorCategory(void);
void TemplateIteratorTraits(void);
void TemplateIteratorConcept(void);
void rIterator(void);
void Copy(void);
void OrderOfLen(void);
void Less(void);
void Map(void);
void AllOf(void);

// 지금까지 나왔던 문제
void Problem1(void);
void Problem2(void);
void Problem3(void);
void Problem4(void);
int Problem5(void);
int Problem6(void);
int Problem7(void);
void Problem8(void);
void Problem9(void);

int main(void)
{
	// 배웠으나 관련 문제가 없는 것
	//MergeList();
	//Span();
	//OstreamIterator();
	//TemplateIteratorCategory();
	//TemplateIteratorTraits();
	//TemplateIteratorConcept();
	//rIterator();
	//Copy();
	//OrderOfLen();
	//Less();
	//Map();
	AllOf();

	// 지금까지 나왔던 문제
	//Problem1();
	//Problem2();
	//Problem3();
	//Problem4();
	//Problem5();
	//Problem6();
	//Problem7();
	//Problem8();
	//Problem9();
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
void Span(void)
{
	int a[10]{ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

	std::span<int> s{ a };

	std::sort(s.begin(), s.end());

	for (int num : s)
		std::cout << num << '\n';
	std::cout << '\n';
}
//---------------------------------------------------------------------------------------
void OstreamIterator(void)
{
	std::ostream_iterator<char> p{ std::cout };
	std::cout << "출력스트림 반복자의 크기 - " << sizeof(p) << '\n';
	std::cout << "반복자의 타입 - " << typeid(p).name() << '\n';
}
//---------------------------------------------------------------------------------------
template <class 반복자>
void f1(반복자 iter)
{
	// 반복자는 6가지 종류(category)로 구분
	std::cout << typeid(반복자::iterator_category).name() << '\n';
}

void TemplateIteratorCategory(void)
{
	f1(std::istream_iterator<char>{ std::cin });
	f1(std::ostream_iterator<char>{ std::cout });
	f1(std::forward_list<int>{}.begin());
	f1(std::list<int>{}.cbegin());
	f1(std::deque<int>{}.rbegin());
	f1(std::vector<int>{}.begin());
}
//---------------------------------------------------------------------------------------
template <class 반복자>
void f2(반복자 iter)
{
	// 반복자의 종류를 판단하는 표준 문장
	std::cout << typeid(std::iterator_traits<반복자>::iterator_category).name() << '\n';
}

void TemplateIteratorTraits(void)
{
	int* p;
	f2(p);
}
//---------------------------------------------------------------------------------------
template <class 반복자>
void f3(반복자 iter)
{
	// 반복자의 종류를 판단하는 표준 문장
	std::cout << typeid(반복자::iterator_concept).name() << '\n';
}

void TemplateIteratorConcept(void)
{
	f3(std::vector<int>::iterator{});
	f3(std::string::iterator{});
}
//---------------------------------------------------------------------------------------
void rIterator(void)
{
	std::string s{ "1357924680" };

	for (auto i = s.begin(); i != s.end(); ++i)
		std::cout << *i << " ";
	std::cout << '\n';

	for (auto i = s.rbegin(); i != s.rend(); ++i)
		std::cout << *i << " ";
	std::cout << '\n';

	std::sort(s.rbegin(), s.rend());

	for (auto i = s.begin(); i != s.end(); ++i)
		std::cout << *i << " ";
	std::cout << '\n';

	for (auto i = s.rbegin(); i != s.rend(); ++i)
		std::cout << *i << " ";
	std::cout << '\n';
}
//---------------------------------------------------------------------------------------
template <class InIter, class OuIter>
void my_copy(InIter b, InIter e, OuIter d)
{
	while (b != e) {
		*d = *b;
		++b;
		++d;
	}
}

void Copy(void)
{
	String s{ "STL aldorithm 2024년 5월 14일" };

	std::copy(s.begin(), s.end(), std::ostream_iterator<char>{std::cout});
	std::cout << '\n';

	my_copy(s.begin(), s.end(), std::ostream_iterator<char>{std::cout});
	std::cout << '\n';

	std::vector<char> v1(s.getLen());

	my_copy(s.begin(), s.end(), v1.begin());

	for (char c : v1)
		std::cout << c;
	std::cout << '\n';

	std::vector<char> v2;

	my_copy(s.begin(), s.end(), std::back_inserter(v2));

	for (char c : v2)
		std::cout << c;
	std::cout << '\n';
}
//---------------------------------------------------------------------------------------
class 길이오름차순
{
public:
	bool operator()(const String& a, const String& b) const
	{
		return a.getLen() < b.getLen();
	}
};

void OrderOfLen(void)
{
	std::ifstream in1{ "STL.cpp" };
	std::set<String, 길이오름차순> s{ std::istream_iterator<String>{in1}, {} };

	std::ifstream in2{ "STL.cpp" };
	std::multiset<String, 길이오름차순> ms{ std::istream_iterator<String>{in2}, {} };

	for (const String& s : s)
		std::cout << s << '\n';

	for (const String& s : ms)
		std::cout << s << '\n';
}
//---------------------------------------------------------------------------------------
template <>
struct std::less<String> {
	// 영단어가 먼저 나온 후 한글 단어가 나온다.
public:
	bool operator()(const String& a, const String& b) const {
		// a/b --> 영/영, 영/한, 한/영, 한/한
		// 한/영 인 경우만 바꾼다.
		if (!isalpha(*a.begin()) && isalpha(*b.begin()))
			return false;
		return true;
	}
};

void Less(void)
{
	std::ifstream in{ "STL.cpp" };

	std::multiset<String> s{ std::istream_iterator<String>{in}, {} };

	for (const String& s : s)
		std::cout << s << '\n';
}
//---------------------------------------------------------------------------------------
void Map(void)
{
	std::map<String, std::list<String>> m{ {"펄어비스", {"검은 사막", "붉은 사막"}} };
	m.insert(std::pair<String, std::list<String>>{"넥슨", { "메이플", "바람의 나라", "던전앤파이터" }});
	m.insert(std::make_pair("엔씨소프트", std::list<String>{"리니지", "리니지M"}));
	// 맵은 연관배열로 사용할 수 있음
	m["스마일게이트"] = { "로스트아크" };

	for (auto [회사, 게임들] : m) {
		std::cout << 회사 << " - ";
		for (const String& 게임 : 게임들)
			std::cout << 게임 << " ";
		std::cout << '\n';
	}
	std::cout << '\n';
}
//---------------------------------------------------------------------------------------
template <class 반복자, class 조건>
bool my_all_of(반복자 b, 반복자 e, 조건 lamda) {
	while (b != e)
		if (lamda(*b))
			b++;
		else
			return false;
	return true;
}

void AllOf(void)
{
	std::vector<int> v{ 1, 3, 5, 7, 9, -2 };

	bool b = std::all_of(v.begin(), v.end(), [](int n) {return n & 1; });

	if (b)
		std::cout << "모두 홀수" << '\n';
	else
		std::cout << "다 홀수인 것은 아니다" << '\n';

	b = my_all_of(v.begin(), v.end(), [](int n) {return n & 1; });

	if (b)
		std::cout << "모두 홀수" << '\n';
	else
		std::cout << "다 홀수인 것은 아니다" << '\n';
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
// [문제2] s에 사용자가 찾는 문자가 있는지 알려주자.
// 찾는 문자가 있다면 몇 번째 문자인지 알려주자.
// 없다면 없다고 출력하자.
template <class 반복자, class 값>
반복자 my_find(반복자 b, 반복자 e, 값 val)
{
	while (b != e) {
		if (*b == val)
			return b;
		++b;
	}
	return e;
}

void Problem2(void)
{
	String s{ "1357924680" };

	while (true) {
		std::cout << "찾을 문자? ";
		char c;
		std::cin >> c;

		auto p = my_find(s.begin(), s.end(), c);
		if (p != s.end())
			std::cout << c << "는 s의 " << std::distance(s.begin(), p) + 1 << "번째 문자입니다." << '\n';
		else
			std::cout << c << "는 s에 없습니다." << '\n';
	}
}
//---------------------------------------------------------------------------------------
// [문제3] s에서 사용자가 찾는 조건(짝수)에 맞는 문자를
// 모두 출력하라.
// 찾는 문자가 있다면 몇번째 문자인지 알려주자.
// 없다면 없다고 출력하자.
template <class 반복자, class Pred>
반복자 my_find_if(반복자 b, 반복자 e, Pred f)
{
	while (b != e) {
		if (f(*b))
			return b;
		++b;
	}
	return e;
}

void Problem3(void)
{
	String s{ "stl aldorithm 222 sdjilljslf 46 0 a 12" };

	auto b = s.begin();

	while (true) {
		auto p = my_find_if(b, s.end(), [](char c) {
			if (isdigit(c))
				if ((c & 1) == 0)
					return true;
			return false;
			});

		if (p != s.end())
			std::cout << *p << "는 s의 " << std::distance(s.begin(), p) + 1 << "번째 문자입니다" << '\n';
		else {
			std::cout << "조건에 맞는 문자는 s에 없습니다" << '\n';
			break;
		}

		b = p + 1;
	}
}
//---------------------------------------------------------------------------------------
// [문제4] 사용자가 입력한 모든 단어를 오름차순으로 정렬한 후
// 출력하라.

void Problem4(void)
{
	std::set<String> s{ std::istream_iterator<String>{std::cin}, {} };

	for (const String& s : s)
		std::cout << s << '\n';
}
//---------------------------------------------------------------------------------------
// [문제5] 사용자가 입력한 단어가 이 소설에 있는 단어인지 알려주자.

int Problem5(void)
{
	std::ifstream in{ "이상한 나라의 앨리스.txt" };
	if (not in)
		return 0;

	std::multiset<std::string> s{ std::istream_iterator<std::string>{in}, {} };

	std::cout << "앨리스에서 사용한 단어 개수 - " << s.size() << '\n';

	while (true) {
		std::cout << "찾을 단어는? ";
	std::string word;
		std::cin >> word;

		auto p = s.find(word);
		if (p != s.end())
			std::cout << word << "는 있는 단어입니다." << '\n';
		else
			std::cout << word << "를 사용하지는 않았습니다." << '\n';
	}
}
//---------------------------------------------------------------------------------------
// [문제6] 찾는 단어가 있나? 있다면 몇 개가 있나?

int Problem6(void)
{
	std::ifstream in{ "이상한 나라의 앨리스.txt" };
	if (not in)
		return 0;

	std::multiset<std::string> s{ std::istream_iterator<std::string>{in}, {} };

	std::cout << "앨리스에서 사용한 단어 개수 - " << s.size() << '\n';

	while (true) {
		std::cout << "찾을 단어는? ";
		std::string word;
		std::cin >> word;

		auto [하한, 상한] = s.equal_range(word);

		if (하한 == 상한)
			std::cout << word << "는 앨리스에 없는 단어입니다." << '\n';
		else
			std::cout << word << "는 " << std::distance(하한, 상한) << "번 사용되었다" << '\n';
	}
}
//---------------------------------------------------------------------------------------
// [문제7] 찾는 단어를 포함한 모든 단어를 출력하라.
// 예) 입력 - "ion" 출력 - sensation, imagination, nation

int Problem7(void)
{
	std::ifstream in{ "이상한 나라의 앨리스.txt" };
	if (not in)
		return 0;

	std::multiset<std::string> s{ std::istream_iterator<std::string>{in}, {} };

	std::cout << "앨리스에서 사용한 단어 개수 - " << s.size() << '\n';

	while (true) {
		std::cout << "찾을 단어는? ";
		std::string word;
		std::cin >> word;

		std::set<std::string> ans;
		for (const std::string& s : s) {
			auto p = std::search(s.begin(), s.end(), word.begin(), word.end());
			if (p != s.end())
				ans.insert(s);
		}

		for (const std::string& s : ans)
			std::cout << s << ' ';
		std::cout << '\n' << '\n';
	}
}
//---------------------------------------------------------------------------------------
// [문제8] 소설에 사용된 영문자와 그 사용횟수를 횟수기준 내림차순으로 출력하라.
// 대문자는 소문자로 변환한다.

void Problem8(void)
{
	std::map<char, int> cim;

	std::ifstream in{ "이상한 나라의 앨리스.txt" };

	char c;
	while (in >> c) {
		if (isalpha(c))
			cim[tolower(c)]++;
	}

	// 방법1
	/*std::map<int, char> icm;	// == std::map<int, char, std::greater<int>> icm;

	for (auto [소문자, 횟수] : cim)
		icm[횟수] = 소문자;*/

	// 방법2
	std::multimap<int, char> icm;

	for (auto [소문자, 횟수] : cim)
		icm.insert(std::make_pair(횟수, 소문자));

	for (auto [횟수, 소문자] : icm )
		std::cout << 소문자 << " - " << 횟수 << '\n';

	// 반대로 출력
	/*for (auto [횟수, 소문자] : icm | std::views::reverse)
		std::cout << 소문자 << " - " << 횟수 << '\n';*/
}
//---------------------------------------------------------------------------------------
// [문제9] 소설에 사용된 단어와 사용횟수를 횟수기준 내림차순으로 출력해라.

void Problem9(void)
{
	std::ifstream in{ "이상한 나라의 앨리스.txt" };

	std::map<std::string, int> strim;

	std::string word;
	while (in >> word)
		strim[word]++;

	std::multimap<int, std::string> istrm;

	for (const auto& [단어, 횟수] : strim)
		istrm.insert(std::make_pair(횟수, 단어));

	for (auto [횟수, 단어] : istrm | std::views::reverse)
		std::cout << 단어 << " - " << 횟수 << '\n';
}
//---------------------------------------------------------------------------------------