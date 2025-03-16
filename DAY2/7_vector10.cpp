#include <iostream>
#include <vector> // 이 안에 C++ 표준 vector 가 있습니다.
// 원리는 우리가 만든것과 유사합니다.

// STL
// => Standard Template Library
// => C++ 표준 라이브러리가 대부분 template 이라서 이렇게 부릅니다.

int main()
{
	std::vector<int> v1(4, 0);

	v1[0] = 10;			// v1.operator(0)[] = 10 입니다. 
						// 5일차 배우는 "연산자 재정의" 문법
	v1.at(0) = 10;	 // 위와 동일. 우리가 만든것과 동일

	v1.resize(8);

	v1.push_back(0); // 끝에 한개 추가. 이순간 size 는 9개
					// 하지만 메모리 자체의 크기는 g++ 2배
					// vc : 1.5배

	//std::cout << v1[9] << std::endl;
	std::cout << v1.size() << std::endl; // 배열 사이즈: 9개
	std::cout << v1.capacity() << std::endl; // 실제 메모리 크기: 12개
											// g++ 은 16

	v1.push_back(0);	// 현재 상태는 size(9) < capacity(12) 이므로
						// 새로운 메모리 할당 필요 없음.
						// 아주 빠르게 동작.
}

