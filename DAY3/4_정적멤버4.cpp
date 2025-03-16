
#include <iostream>


// static member function

class Car
{
	int color = 0;
	static int cnt;	// private 으로 해야 안전.

public:

	Car() { ++cnt; }
	~Car() { --cnt; }

	// 멤버 함수 : 객체가 있어야만 호출 가능.
//	int get_count() const { return cnt; }

	// static 멤버 함수: 객체가 없어도 호출 가능한 함수
	//					"클래스이름::함수이름()" 으로 호출
	//					"Car::get_count()"
	//					객체가 없이 호출하므로 상수 멤버함수 라는 개념적용이 안됨.
	static int get_count() { return cnt; }	//
};

int Car::cnt = 0;	// private 멤버라도 static은 외부 초기화 가능.


int main()
{

	std::cout << Car::get_count() << std::endl;	// 0

	Car c1;
	Car c2;

	std::cout << Car::get_count() << std::endl;	// 2 , 권장
	std::cout << c1.get_count() << std::endl;	// 2, 비권장
	std::cout << c2.get_count() << std::endl;	// 2, 비권장

}




