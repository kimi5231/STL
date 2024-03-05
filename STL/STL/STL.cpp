//-------------------------------------------------------------------
// 2024 1학기 STL 화56목56		3월 5일 화요일		(1주 1)
// 
// VisualStudio 17.9 이상, Release/x64
// 프로젝트 설정 - 언어 /std:c++latest
// 
// 한학기 강의를 저장할 save 함수 작성하고 파일 분리
//-------------------------------------------------------------------
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

void save(std::string_view);

int main(void)
{
	std::cout << "2024 STL" << '\n';
	save("STL.cpp");
}

void save(std::string_view fileName)
{
	// fileName을 읽기
	std::ifstream in{ fileName.data() };	//RAII
	if (not in) {
		std::cout << fileName << " 열기 실패" << "\n";
		exit(0);
	}

	// 저장할 파일을 덧붙여 쓰기모드로 연다.
	std::ofstream out{ "2024 1학기 STL 화56목56 강의저장.txt", std::ios::app };
	
	// 읽을 파일의 내용을 읽어 쓸 파일에 덧붙인다.
	// STL 자료구조와 알고리즘을 이용하여 기록한다. (좋은건 아니다)
	std::vector<char> v{ std::istreambuf_iterator<char>{in}, {} };

	out << "\n" << "\n";
	std::copy(v.begin(), v.end(), std::ostreambuf_iterator<char>{ out });
}