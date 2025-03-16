// 3_입출력2.cpp - 18 page
#include <iostream>

// io manipulator (입출력 조정자 함수)
// --> 입출력의 형태를 지정할 때 사용하는 함수들
// 
#include <iomanip>

int main()
{
	int n = 10;
	std::cout << n << std::endl; // 10 즉, 10 진수로 출력
	std::cout << std::hex << n << std::endl; // a, 16진수 출력 
	std::cout << std::dec << n << std::endl; // 10, 다시 10진수로
	std::cout << std::setw(10) << n << std::endl; // 10 자리에 맞추어 출력
	std::cout << std::setw(10) << std::setfill('#') << n << std::endl; // 10 자리에 맞추어 출력하는데 공백은 #으로 채움.

	double d = 12.123456789;
	std::cout << d << std::endl;	// 몇자리까지 출력되는지? --> 12.1234. 
									// 정수부+실수부 합쳐서 6자리까지 출력

	// 출력 정밀도를 높이려면 iomanipulator를 사용해야됨.
	// 1. cpprefernece.com
	// 2. std::setw 검색
	// 3. 상위 문서로 이동
	// 4. 모든 iomanipulator 를 볼 수 있음. 
	std::cout << std::setprecision(12) << d << std::endl;





								}


