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

// ������� ���� ������ ���� ��
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

// ���ݱ��� ���Դ� ����
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
	// ������� ���� ������ ���� ��
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

	// ���ݱ��� ���Դ� ����
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

// ������� ���� ������ ���� ��
//---------------------------------------------------------------------------------------
void MergeList(void)
{
	std::list<String> cont1{ "1", "22", "333", "4444", "55555" };
	std::list<String> cont2{ "1", "22", "a", "bb", "333", "4444", "55555" };

	cont2.sort();

	// �� ����Ʈ�� �̹� ���ĵǾ� �ִٰ� �����ϰ� ��ħ
	// cont1�� cont2�� ��ħ
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
	std::cout << "��½�Ʈ�� �ݺ����� ũ�� - " << sizeof(p) << '\n';
	std::cout << "�ݺ����� Ÿ�� - " << typeid(p).name() << '\n';
}
//---------------------------------------------------------------------------------------
template <class �ݺ���>
void f1(�ݺ��� iter)
{
	// �ݺ��ڴ� 6���� ����(category)�� ����
	std::cout << typeid(�ݺ���::iterator_category).name() << '\n';
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
template <class �ݺ���>
void f2(�ݺ��� iter)
{
	// �ݺ����� ������ �Ǵ��ϴ� ǥ�� ����
	std::cout << typeid(std::iterator_traits<�ݺ���>::iterator_category).name() << '\n';
}

void TemplateIteratorTraits(void)
{
	int* p;
	f2(p);
}
//---------------------------------------------------------------------------------------
template <class �ݺ���>
void f3(�ݺ��� iter)
{
	// �ݺ����� ������ �Ǵ��ϴ� ǥ�� ����
	std::cout << typeid(�ݺ���::iterator_concept).name() << '\n';
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
	String s{ "STL aldorithm 2024�� 5�� 14��" };

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
class ���̿�������
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
	std::set<String, ���̿�������> s{ std::istream_iterator<String>{in1}, {} };

	std::ifstream in2{ "STL.cpp" };
	std::multiset<String, ���̿�������> ms{ std::istream_iterator<String>{in2}, {} };

	for (const String& s : s)
		std::cout << s << '\n';

	for (const String& s : ms)
		std::cout << s << '\n';
}
//---------------------------------------------------------------------------------------
template <>
struct std::less<String> {
	// ���ܾ ���� ���� �� �ѱ� �ܾ ���´�.
public:
	bool operator()(const String& a, const String& b) const {
		// a/b --> ��/��, ��/��, ��/��, ��/��
		// ��/�� �� ��츸 �ٲ۴�.
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
	std::map<String, std::list<String>> m{ {"�޾��", {"���� �縷", "���� �縷"}} };
	m.insert(std::pair<String, std::list<String>>{"�ؽ�", { "������", "�ٶ��� ����", "������������" }});
	m.insert(std::make_pair("��������Ʈ", std::list<String>{"������", "������M"}));
	// ���� �����迭�� ����� �� ����
	m["�����ϰ���Ʈ"] = { "�ν�Ʈ��ũ" };

	for (auto [ȸ��, ���ӵ�] : m) {
		std::cout << ȸ�� << " - ";
		for (const String& ���� : ���ӵ�)
			std::cout << ���� << " ";
		std::cout << '\n';
	}
	std::cout << '\n';
}
//---------------------------------------------------------------------------------------
template <class �ݺ���, class ����>
bool my_all_of(�ݺ��� b, �ݺ��� e, ���� lamda) {
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
		std::cout << "��� Ȧ��" << '\n';
	else
		std::cout << "�� Ȧ���� ���� �ƴϴ�" << '\n';

	b = my_all_of(v.begin(), v.end(), [](int n) {return n & 1; });

	if (b)
		std::cout << "��� Ȧ��" << '\n';
	else
		std::cout << "�� Ȧ���� ���� �ƴϴ�" << '\n';
}
//---------------------------------------------------------------------------------------



//---------------------------------------------------------------------------------------
// [����1] ���� "STL.cpp"�� �ܾ �о� �����϶�.
void Problem1(void)
{
	std::ifstream in{ "STL.cpp" };

	std::list<String> cont{ std::istream_iterator<String>{in}, {} };

	cont.sort();
	// �ߺ��� ���� ����
	cont.unique();

	for (const String& s : cont)
		std::cout << s << '\n';
}
//---------------------------------------------------------------------------------------
// [����2] s�� ����ڰ� ã�� ���ڰ� �ִ��� �˷�����.
// ã�� ���ڰ� �ִٸ� �� ��° �������� �˷�����.
// ���ٸ� ���ٰ� �������.
template <class �ݺ���, class ��>
�ݺ��� my_find(�ݺ��� b, �ݺ��� e, �� val)
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
		std::cout << "ã�� ����? ";
		char c;
		std::cin >> c;

		auto p = my_find(s.begin(), s.end(), c);
		if (p != s.end())
			std::cout << c << "�� s�� " << std::distance(s.begin(), p) + 1 << "��° �����Դϴ�." << '\n';
		else
			std::cout << c << "�� s�� �����ϴ�." << '\n';
	}
}
//---------------------------------------------------------------------------------------
// [����3] s���� ����ڰ� ã�� ����(¦��)�� �´� ���ڸ�
// ��� ����϶�.
// ã�� ���ڰ� �ִٸ� ���° �������� �˷�����.
// ���ٸ� ���ٰ� �������.
template <class �ݺ���, class Pred>
�ݺ��� my_find_if(�ݺ��� b, �ݺ��� e, Pred f)
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
			std::cout << *p << "�� s�� " << std::distance(s.begin(), p) + 1 << "��° �����Դϴ�" << '\n';
		else {
			std::cout << "���ǿ� �´� ���ڴ� s�� �����ϴ�" << '\n';
			break;
		}

		b = p + 1;
	}
}
//---------------------------------------------------------------------------------------
// [����4] ����ڰ� �Է��� ��� �ܾ ������������ ������ ��
// ����϶�.

void Problem4(void)
{
	std::set<String> s{ std::istream_iterator<String>{std::cin}, {} };

	for (const String& s : s)
		std::cout << s << '\n';
}
//---------------------------------------------------------------------------------------
// [����5] ����ڰ� �Է��� �ܾ �� �Ҽ��� �ִ� �ܾ����� �˷�����.

int Problem5(void)
{
	std::ifstream in{ "�̻��� ������ �ٸ���.txt" };
	if (not in)
		return 0;

	std::multiset<std::string> s{ std::istream_iterator<std::string>{in}, {} };

	std::cout << "�ٸ������� ����� �ܾ� ���� - " << s.size() << '\n';

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
//---------------------------------------------------------------------------------------
// [����6] ã�� �ܾ �ֳ�? �ִٸ� �� ���� �ֳ�?

int Problem6(void)
{
	std::ifstream in{ "�̻��� ������ �ٸ���.txt" };
	if (not in)
		return 0;

	std::multiset<std::string> s{ std::istream_iterator<std::string>{in}, {} };

	std::cout << "�ٸ������� ����� �ܾ� ���� - " << s.size() << '\n';

	while (true) {
		std::cout << "ã�� �ܾ��? ";
		std::string word;
		std::cin >> word;

		auto [����, ����] = s.equal_range(word);

		if (���� == ����)
			std::cout << word << "�� �ٸ����� ���� �ܾ��Դϴ�." << '\n';
		else
			std::cout << word << "�� " << std::distance(����, ����) << "�� ���Ǿ���" << '\n';
	}
}
//---------------------------------------------------------------------------------------
// [����7] ã�� �ܾ ������ ��� �ܾ ����϶�.
// ��) �Է� - "ion" ��� - sensation, imagination, nation

int Problem7(void)
{
	std::ifstream in{ "�̻��� ������ �ٸ���.txt" };
	if (not in)
		return 0;

	std::multiset<std::string> s{ std::istream_iterator<std::string>{in}, {} };

	std::cout << "�ٸ������� ����� �ܾ� ���� - " << s.size() << '\n';

	while (true) {
		std::cout << "ã�� �ܾ��? ";
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
// [����8] �Ҽ��� ���� �����ڿ� �� ���Ƚ���� Ƚ������ ������������ ����϶�.
// �빮�ڴ� �ҹ��ڷ� ��ȯ�Ѵ�.

void Problem8(void)
{
	std::map<char, int> cim;

	std::ifstream in{ "�̻��� ������ �ٸ���.txt" };

	char c;
	while (in >> c) {
		if (isalpha(c))
			cim[tolower(c)]++;
	}

	// ���1
	/*std::map<int, char> icm;	// == std::map<int, char, std::greater<int>> icm;

	for (auto [�ҹ���, Ƚ��] : cim)
		icm[Ƚ��] = �ҹ���;*/

	// ���2
	std::multimap<int, char> icm;

	for (auto [�ҹ���, Ƚ��] : cim)
		icm.insert(std::make_pair(Ƚ��, �ҹ���));

	for (auto [Ƚ��, �ҹ���] : icm )
		std::cout << �ҹ��� << " - " << Ƚ�� << '\n';

	// �ݴ�� ���
	/*for (auto [Ƚ��, �ҹ���] : icm | std::views::reverse)
		std::cout << �ҹ��� << " - " << Ƚ�� << '\n';*/
}
//---------------------------------------------------------------------------------------
// [����9] �Ҽ��� ���� �ܾ�� ���Ƚ���� Ƚ������ ������������ ����ض�.

void Problem9(void)
{
	std::ifstream in{ "�̻��� ������ �ٸ���.txt" };

	std::map<std::string, int> strim;

	std::string word;
	while (in >> word)
		strim[word]++;

	std::multimap<int, std::string> istrm;

	for (const auto& [�ܾ�, Ƚ��] : strim)
		istrm.insert(std::make_pair(Ƚ��, �ܾ�));

	for (auto [Ƚ��, �ܾ�] : istrm | std::views::reverse)
		std::cout << �ܾ� << " - " << Ƚ�� << '\n';
}
//---------------------------------------------------------------------------------------