// 파일 분할, p120 - 121
#include <iostream>


// static member 7 도 추가 후 동일하게 복사


class Car
{
	int color = 0;
	static int cnt;	// private 으로 해야 안전.

public:

	Car();
	~Car();

	// 1. static 멤버 함수 만들 때 static 키워드는 선언에만 표기
	// -> 대부분 문법이 선언에만 표기하는데
	// -> 상수 멤버 함수의 const 만 선언과 구현에 모두 표기.
	static int get_count();	//
};

// 2. static 멤버 데이터의 외부 선언은 .cpp 에 있어야 함.
// p 121 완전한 코드 참고.
// Car.cpp
int Car::cnt = 0;	// 전역변수! 전역변수는 cpp에 기재.

Car::Car() { ++cnt; }
Car::~Car() { --cnt; }

int Car::get_count() 
{ 
	return cnt; 
}

int main()
{


}




