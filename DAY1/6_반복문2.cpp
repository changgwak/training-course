// 8_반복문 44 page
#include <iostream>
#include <ranges> // C++20부터 지원하는 헤더

// C++ 버전 : C++latest 로 하세요.
// C++ 표준 위원회 : 성능을 고려한 최선의 설계

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };	// 배열

//	for (auto e : x)
//	for (auto e : std::views::reverse(x))	// 뒤집어서
//	for (auto e : std::views::take(x, 5))	// 5개만
	for (auto e : std::views::stride(x, 2))	// 2칸 씩, C++23
	{
		std::cout << e << std::endl;

	}



}


