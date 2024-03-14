//-------------------------------------------------------------------
// 2024 1학기 STL 화56목56		3월 14일 목요일		(2주 2)
// 
// FILE I/O text/binary - high/low level
//-------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <array>
#include <random>
#include "save.h"

// [문제] "개들"에는 class Dog 객체 100개가 기록되어 있다.
// 파일은 binary 모드이 write 함수로 sizeof(Dog)*100 바이트를 기록하였다.
// 파일을 읽어 가장 num값이 큰 Dog 정보를 화면에 출력하라.
// class Dog의 멤버는 다음과 같다.
 
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