#include <iostream>
// 28 page ~

int main()
{
	int x[3] = { 1,2,3 };

	// 1. auto : 우변의 표현식으로 좌변의 타입을 결정해 달라는 것.
	auto n = x[0];	// int n = x[0] 로 컴파일 시간에 결정. 성능 저하 없음.
	//std::cout << 10 << std::endl;

	// 2. decltype : () 안의 표현식의 타입을 결정.
	decltype(n) d; // int d;

	// auto : 일반 개발자도 아주 널리 사용.
	// decltype : 일반 개발자 보다는 라이브러리 설계자를 위한 것.

	//3. auto는 생각보다 어렵다.
	const int c = 10;
	auto a = c;	// 1. int a = c; --> ok
				// 2. const int a = c; --> no
	
	// auto가 타입을 추론하는 정확한 알고리즘은 꽤 복잡.
	// -> 많은 C++ 문법을 알아야 함.
	// -> 지금은 우변의 const, valatile, reference 를 제거하고 타입 결정.
}


