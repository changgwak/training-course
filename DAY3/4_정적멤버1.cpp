// 3_정적멤버1 - 111 page
#include <iostream>

// 자동차 객체가 몇대나 생성되었는지 알고 싶다.

// 방법 1. 멤버 데이터 cnt 사용.
// -> 멤버 데이터는 객체당 1개씩 생성됨.
// -> 객체 갯수 파악 실패.

class Car
{
	int color = 0;

public:

	int cnt = 0;

	Car() { ++cnt; }
	~Car() { --cnt; }
};

int main()
{
	Car c1;
	Car c2;

	std::cout << c1.cnt << std::endl;
}




