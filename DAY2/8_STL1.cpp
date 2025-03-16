#include <iostream>
#include <string>	// std::string 타입을 위한 헤더

int main()
{
	// #1. C 언어의 문자열
	// C 언어는 문자타입(char) 만 있고, 문자열 타입이 없음.
	// -> 그래서 문자열을 위해서는 문자타입의 배열 또는 문자 타입의 포인터 사용.
	char cs1[] = "hello";
	char cs2[] = "hello";


	// 단점: 문자열 관련 코드가 직관적이지 않음.
	if (cs1 == cs2) {}	// 문자열 비교가 아닌, 배열의 주소 비교, 항상 false.
	if (strcmp(cs1, cs2) == 0) {}	// 이 코드가 문자열 비교.(C언어)

	// #2. C++ 언어의 문자열 타입 -> std::string
	std::string s1 = "hello";
	std::string s2 = "hello";

	// s1, s2는 int 형 변수와 사용법이 동일. 아래 모두 가능.
	auto s3 = s1 + s2;

	if (s1 == s2) {}

	if (s1 > s2) {}

	auto n = s1.size();	// 5

}

