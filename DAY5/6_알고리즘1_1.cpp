// 6_알고리즘1
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

// 200 page ~
int main()
{
	std::list<int>   s = { 1,2,3,4,5,6,7,8,9,10 };	// 린크드 리스트.
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };  // 

	// std::find
	// 검색 구간 : [first, last)
	//				last 는 검색 대상이 아님. 반 개행구간(half-open range)
	// 반환 값 : 찾은 곳을 가리키는 반복자
		//			실패 시 last 반환
	auto ret1 = std::find(s.begin(), s.end(), 3);

	if (ret1 == s.end())
	{
		std::cout << "검색 실패\n";
	}
	else
	{
		// 검색 성공. ret1은 3을 가리키는 반복자(포인터 라고 생각)
		std::cout << *ret1 << std::endl;
	}

}

