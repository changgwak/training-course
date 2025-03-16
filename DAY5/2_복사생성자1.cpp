// 2_복사생성자1.cpp
#include <iostream>

// 124 page ~ 

class Point
{
	int x, y;

public:
	Point()             : x(0), y(0) {} // 1
	Point(int a, int b) : x(a), y(b) {} // 2


	// 복사 생성자(copy constructor)
	// -> 자신과 동일한 타입의 객체를 1개 받는 생성자.
	// -> 사용자가 만들지 않으면 컴파일러가 제공한다.
	// -> 컴파일러 제공 버전은 아래와 동일
	Point(const Point& other): x(other.y), y(other.y) {}

};

int main()
{
	// 아래 4줄에 대해서 생각해 봅시다.
	Point p1;		// ok, 1번 생성자 호출
//	Point p2(1);    // error, 인자가 1개인 생성자는 없음
	Point p3(1,2);	// ok, 2번 생성자 호출
	Point p4(p3);   // 복사 생성자 호출
	Point p5 = p3;	// 복사 생성자 호출
}

