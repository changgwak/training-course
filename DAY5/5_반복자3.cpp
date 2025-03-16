#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };
	
	// 1. past the end

	auto p1 = s.begin(); // 컨테이너 1번째 요소를 가리키는 반복자
	auto p2 = s.end();   // 컨테이너 마지막 "다음" 요소를 가리키는 반복자.

	*p1 = 10; // ok, 1번째 요소인 1을 10으로 변경.
	*p2 = 10; // runtime error, 
				// 항상 .end()로 얻은 반복자는 * 연산하면 안됨.

	// p2는 p1 을 이동해서 순회할 때
	// 마지막에 도착했는지 확인하는 용도로만 사용.
	while (p1 != p2)
	{
		std::cout << *p1 << std::endl;
		++p1;

	}

}



