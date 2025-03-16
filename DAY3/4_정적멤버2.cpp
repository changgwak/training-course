#include <iostream>

// 3_정적멤버1 - 111 page

// 방법 2. 전역변수
// -> 전역 변수는 모든 객체가 공유
// -> 객체 갯수 파악 성공.

// 단점
// 1. 전역변수는 누구나 접근 가능. 안전하지 않음.
//		-> private 으로 보호 할 수 없을까?
// 2. 이름 충돌
//		Car 뿐만 아니라, Bike, Boat 등의 객체도 갯수 파악하고 싶다.
//		cnt 말고 다른 이름의 전역변수가 필요.
//		이름을 Car::cnt, Bike::cnt, Boat::cnt 처럼 사용하면 어떨까?

int cnt = 0;

class Car
{
	int color = 0;

public:

	Car() { ++cnt; }
	~Car() { --cnt; }
};

int main()
{
	Car c1;
	Car c2;

	std::cout << cnt << std::endl;
}




