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

	// 컨테이너에서 3을 찾고 싶다.
	// 방법 1. 멤버함수 find를 제공하자.
	// 장점: 사용하기 쉽다.
	// 단점: 모든 컨테이너레 finc 멤머 함수를 만들어야 함.
//	s.find(3); // 없는 거.error.
	
	
	// 방법 2. finc 를 일반 함수 템플릿으로 만들자.
	// 장점: 1개의 non-member function(template) 으로 모든 컨테이너에서 
	//			선형 검색 가능.
	// 단점: 코드가 복잡해 보인다.
	auto ret1 = std::find(s.begin(), s.end(), 3);
	auto ret2 = std::find(v.begin(), v.end(), 3);


}

//std::find 같은 일반 함수(템플릿)을 알고리즘이라고 부름.
// STL의 3대 요소: Container, Iterator, Algorithm

// STL
// 1998 년 C++ 1차 표준화에서 채택된 표준 라이브러리
// -> 객체지향 스타일이 아닌
// -> template 기반의 설계

// "알고리즘 산책" -> STL 을 만든 저자가 지은 서적.

