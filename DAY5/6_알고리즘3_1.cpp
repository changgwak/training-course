// 6_알고리즘1
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

// 단항 함수: 인자가 1개인 함수
// 이항 함수: 인자가 2개인 함수

// 조건자(Predicate) : bool 을 반환하는 함수

// find_if 의 3번째 인자는 단항 조건자(unary prediate) 입니다

bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 1,2,9,4,3,6,7,3,9,10 };

	auto ret1 = std::find_if(v.begin(), v.end(), foo);

	// 람다 표현식(lambda expression)
	// C++11
	// -> 익명의 함수를 만드는 문법
	// -> 함수 이름을 전달하는 위치에 함수 구현 자체를 전달하는 기술.

	// [] : 람다표현식이 시작됨을 알리는 기호
	//		lammbda introducer
	auto ret2 = std::find_if(v.begin(), v.end(), 
		[](int n){ return n % 3 == 0; });
//		[](int n) -> bool { return n % 3 == 0; }); // 반환 타입 생략 가능.
					


}

