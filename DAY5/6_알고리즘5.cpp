// 6_알고리즘1
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>


int foo(int a, int b) { return a + b; }


int main()
{
	std::vector<int> v1 = { 1,2,3,4,5 };
	std::vector<int> v2 = { 6,7,8,9,10 };
	std::vector<int> v3 = { 0,0,0,0,0 };

	std::transform(v1.begin(), v1.end(),	// 1. 이 구간의 요소를
		v2.begin(),							// 2. 이 구간의 요소와 함께
		v3.begin(),							// 4. 이곳에 넣어라
		//		foo);								// 3. 이 함수에 보내서 반환값을
		[](int a, int b) {return a + b; });

	for (auto e : v3)
		std::cout << e << ", ";
	// 7,9,11,13,15 나에게 위 코드 완성하세요
}

