#include <iostream>


// C 언어
// -> vector 라는 타입이 없음.
// -> 동적 배열 필요하면 "vector3.cpp" 처럼 매번 만들어야 됨.

// C++, java, C# : 모두 vector 있음 (객체 지향 언어)
// python : list 있음
// 

#include <vector>



int main()
{

	std::vector<int> v;		// 크기가 0인 vector

	int n = 0;

	while (1)
	{
		std::cin >> n;

		if (n == -1)
			break;

		v.push_back(n);
	}

	std::cout << "입력된 갯수        : " << v.size() << std::endl;
	std::cout << "할당된 메모리 크기 : " << v.capacity() << std::endl;

}

// 위 코드가 vector3.cpp 와 동일한 기능 수행.
// std::vector 라는 타입이 있으므로 vector3.cpp 보다 훨씬 간결.

// 1,2,3,4,,,,,9 입력 후 -1 입력
// 1..

