
//  연산자재정의 - 163 page
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int x, int y) : x(x), y(y) {}

	void print() const { std::cout << x << ", " << y << std::endl; }


	Point operator+(const Point& p) const
	{
		Point tmp(x + p.x, y + p.y);
		return tmp;
	}

	friend Point operator+(const Point& p1, const Point& p2);

};


Point operator+(const Point& p1, const Point& p2)
{
	Point temp(p1.x + p2.x, p1.y + p2.y);
	return temp;
}


int main()
{
	const Point p1(1, 1);
	Point p2(2, 2);

	Point p3 = p1 + p2;   // error. compile error.
	                     // 멤버 버전 또는 일반 함수 버전 중에서 1개만 제공해야 함.

	p3.print();	// 3, 3



	// 멤버 함수가 좋을까? non-memebr 함수가 좋을까?

// 멤버 파: private 데이터 접근하려면 멤버가 좋다(캡슐화)
// non-member 함수: 멤버로 안 될때가 있다.

	int n = 1;
	Point p4 = p1 + p2; // p1.operator+(Point) 호출

	Point p5 = p1 + n; //p1.operator+(int) 호출

	Point p6 = n + p1; // n.operator+(Point) 인데,,
	// n은 int 인데, int에 operator+() 함수가 없다.
	                  // int에 operator+() 함수를 만들수 없다.
	                  // 그래서, non-member 함수로 만들어야 한다.
	                  // operator+(int, Point) 함수를 만들어야 한다.


	// 권장
	// 교환법칙이 필요한 이항연산자
	// +, -, *, ... : non-member 권장

	// 교환 법칙 필요없고, 객체 상태가 변경되는 연산자.
	// +=, -=, *=, ... : member 권장

	// (), [], ->, =, ... : memeber 만 가능 (p167 - 168)

	// ?, ::, *, .* : member 불가능


}






