#include <cstdio>
#include <iostream> // std::cout, std::cin

// 13page

int main()
{
	int n = 10;

	// C style 입출력
	printf("n = %d\n", n); // C style
	scanf("%d", &n);	   // 입력

	// C++ style
	// 특징
	// #1. %d, %f 등 포맷 지시어 사용 안함.
	// #2. 개행은 '\n' 권장. 더 빠름.
	// std::cout : 객체
	std::cout << "n = " << n << std::endl;

	// 표준 입력
	// 연산자 방향 주의 >>
	// 
	std::cin >> n;

}


