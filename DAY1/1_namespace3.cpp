// 1_namespace3.cpp - 9page 내용
// 
#include <algorithm>
using namespace std;	// 이름 충돌 날수 있기에 사용 말것.

// #1. C++표준의 모든 요소는 std 라는 namespace 안에 있습니다.
// #2. using namespace std의 위험성 (이름 충돌) -> 즉, std:: 항상 사용하기
// #3. std::min 같은 표준함수는 대부분 <algorithm> 헤더에 있음.

int count =10;

int main()
{
	// int n = min(3, 2); // C++ 표준 함수. algorithm 헤더 필요
							// error. std:: 필요

	int n = std::min(3,4); // ok

	count = 20;	// why error? 내가 만든 전역변수에 접근하는데..!
				// C++ 표준에 이미 std::count() 함수가 있음.
				// using namespace stf 때문에 std:: 이름없이도 접근 가능.
				// 전역변수 이름과 c++ 표준 함수가 이름 충돌 발생.
				// 되도록 "using namespace std" 사용하지 말기.
}


