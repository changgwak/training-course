// 10_캐스팅1.cpp    49 page
#include <iostream>


// 핵심 1. C언어 캐스팅은 한가지 방법만 있음.'
// 핵심 2. 그래서 어떤 위험한 캐스팅 코드가
// 개발자의 의도인지 실수인지 알수 없음.

// 핵심 3. 캐스팅 방법을 한가지가 아닌, 여러 개를 제공해서 
// -> 용도에 맞게 사용하면 어떨까?

int main()
{
	int n = 3;


	// #1. int 변수 주소를 double* 에 담기.
//	double* p = &n; // error

	double* p = (double*)&n; // ok. 위험한 캐스팅. 비권장.

	*p = 3.4;	// 이 순간의 메모리를 생각해 보세요.
				// 잘못된 메모리를 접근하게 됨.

	// 2. 상수성 제거
	const int c = 10;

	int* p1 = (int*)&c;	// 위험한 캐스팅.

	*p1 = 20;

	std::cout << c << std::endl;	// 10
	std::cout << *p << std::endl;	// 20
					// -> 컴파일러마다 다를 수 있음
					// -> undefined behavior


}


