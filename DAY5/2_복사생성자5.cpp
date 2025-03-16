#include <iostream>

// 자동 생성 규칙

class Point
{
	int x, y;
public:
	// 컴파일러가 자동생성하는 규칙
	// 1. 어떠한 생성자도 없을때 디폴트 생성자 제공
	// 2. 복사 생성자가 없으면 복사 생성자 제공.
//	Point() : x(0), y(0) {}
	Point(const Point& p) : x(p.x), y(p.y)  {}
};

int main()
{
	Point p1;
	Point p2(p1);
}

