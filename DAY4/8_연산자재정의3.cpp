
//  연산자재정의 - 163 page
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int x, int y) : x(x), y(y) {}

	void print() const { std::cout << x << ", " << y << std::endl; }

	friend Point operator+(const Point& p1, const Point& p2);
};


// 멤버 함수가 아닌 함수로 만드는 operator+() 함수
Point operator+(const Point& p1, const Point& p2)
{
	Point temp(p1.x + p2.x, p1.y + p2.y);
	return temp;
}


int main()
{
	Point p1(1, 1);
	Point p2(2, 2);


	Point p3 = p1 + p2;   // operator+(p1, p2) 호출
	// operator+(Point, Point) 호출

	p3.print();	// 3, 3
}



