#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 }; // 연속된 메모리, 삽입삭제 느리다. 
										// 요소 열거가 빠르고, 캐쉬 적중률이 높다.

	std::list<int>   s = { 1,2,3,4,5 }; // 모든 요소가 떨어진 메모리(린크드리스트), 삽입삭제 빠르다.
										// 요소 열거가 느리고, 캐쉬 적중률이 낮다.
	
	std::deque<int>  d = { 1,2,3,4,5 }; // 연속된 메모리와 유사, 
										// 대부분의 작업에서 list 와 vector의 중간 성능
										// "덱" 또는 "디큐" 라고 발음합니다.
	// 핵심 1. 대부분의 멤버 함수는 이름이 동일합니다.
	// -> 기능은 동일
	// -> 성능은 다름
	
	v.push_back(0);
	s.push_back(0);
	d.push_back(0);


	// 
	// 핵심 2. 사용법이 다르지만 의도적인 설계 
	// -> vector 만 앞에 삽입 할 수 없음.
	// -> push_front() 가 없음.
	// 
	s.push_front(10);
	d.push_front(10);
	v.push_front(10); // error.
	//				-> 연속된 메모리를 쓰므로 앞에 삽입하려면 성능이 많이 느릴수 
	//              -> 있으므로 사용 불가.
	//               -> 앞에 삽입하고 싶은 경우 애초에 list 또는 deque 를 사용해야됨.

	// 핵심 3. [] 연산자는 vector와 deque만 가능합니다.(연속된 메모리와 유사한것만)
	// -> list 는 안됩니다.
	v[0] = 0;
	d[0] = 0;
	s[0] = 0; 

	// 만일 list 가 [] 된다면 아래 코드처럼 사용할텐데,, 성능을 생각해 보세요
	for (int i = 0; i < s.size(); i++)
	{
		s[i] = 0; // error지만 된다고 가정해 보세요
	}

	// 선택 기준
	// 1. [] 를 사용하고 싶은데, 전방삽입을 할일은 없다. : vector
	// 2. [] 를 사용하고 싶은데, 전방삽입도 필요하다.    : deque
	// 3. [] 필요 없고, 삽입/삭제 작업을 많이 한다.      : list

	// 권장 : 대부분의 경우의 캐쉬가 있는 환경(cpu)이라면 vector 권장
	// 잘 모르겠으면 그냥 vector 쓰자.

//	std::vector<int> c = { 1,2,3 };
	std::list<int> c = { 1,2,3 };

	// 대부분의 멤버 함수이름이 유사하므로 컨테이너를 변경해가면서 성능 테스트 할수 있습니다.
	c.push_back(10);
	int n = c.back();
}


// 컨테이너(Container ) : 여러개의 요소를 보관하는 클래스
//						list, vector, deque 등
//						다른 언어에서는 collection 이라고도 합니다.



