// 1_레퍼런스.cpp    57 page

#include <iostream>

// referenece(레퍼런스, 참조) : 기존 변수의 별명을 만트는 문법
// -> 일반적으로 "레퍼런스 변수"가 아닌 "레퍼런스" 라고 표현.

int main()
{
	int n1 = 10;

	int& r1 = n1;	// n1을 가르키는 또 다른 r1도 만듬. r1은 n1의 또 다른 이름.

	r1 = 30;

	std::cout << n1  << std::endl; // n1도 30으로 나옴.
	
	std::cout << &r1 << std::endl;	
	std::cout << &n1 << std::endl;	// &r1 주소와 &n1 주소 동일하게 나옴.

	// & 연산자의 3가지 용도
	int n = 3 & 4; // 비트연산자
	int* p = &n;	// 주소 연산자
	int& r = n;		// 레퍼런스 연산자

	// 포인터 변수 초기화 vs 레퍼런스 초기화
	int* p = &n;	// 포인터 변수는 주소(&n)로 초기화
	int& r = n;		// 레퍼런스는 변수 이름(n)으로 초기화.
}





