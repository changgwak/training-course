#include <iostream>
#include <algorithm> // std::swap 함수용.

// Swap를 만들어 봅시다.
// 1. C 버전
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//2. C++ 버전
// #1. pointer 대신 reference 사용
// #2. 함수가 아닌 함수를 만드는 template 로 작성.
// #3. 성능향상을 위해 inline 함수로. 저정도는 inline 해서 속도 향상시키자.
// #4. 이름 충돌을 막기 위해 namespace 안에 제공.
// #5. 이미 표준에 std::swap 이 있음. 아래와 유사하게 구현.
//		<algorithm> 헤더
namespace Utils
{
	template<typename T>
	inline void Swap(T& a, T& b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}
}



int main()
{
	int x = 3, y = 2;
	Utils::Swap(x, y);
	std::swap(x, y);

	std::cout << x << std::endl;
	std::cout << y << std::endl;
}





