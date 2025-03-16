// 5_STL_컨테이너4
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	std::list<int>   s = { 1,2,3,4,5 };

	// 1. 제거와 반환을 동시에 하는 멤버 함수는 없습니다.
	// -> 가장 안전한 컨테이너를 설계하려면 이렇게 해야 한다는 이론.
	// -> "exception safety의 강력 보장" 이라는 이론.

	int n = v.back(); // 끝에서 하나 얻기.. 제거는 안됨.
	v.pop_back();     // 제거만, 반환값은 void

	std::cout << n << std::endl;

	// 2. 컨테이너가 컨테이너를 보관하면 아주 좋은 "자료구조"를 만들수 있습니다.
	// "자료구조(data structure)" : 데이타를 어떻게 보관할 것인가 ? 를 다루는 분야

	std::vector<int> v1(10);

	v1[0] = 10 ;	// v1은 int 보관

	std::vector< std::list<int> > v2(10);	// 해시테이블과 유사.

	v2[0].push_back(1);
	v2[0].push_back(2);
	v2[0].push_back(3);

	v2[1].push_back(10);
	v2[1].push_back(20);


	std::vector<std::vector<int>> v3(10);
	v3[0].push_back(0);

	// vector 안에 vector는 처음에는 0개의 버퍼가 있어서 
	// 실제 사용하려면 아래처럼 해서 사용해야함.
	v3[0].resize(10);
	v3[1].resize(5);
	v3[2].push_back(1);
}


