// explicit_object_parameter.cpp - 102 page

// 상수멤버함수1 복사


#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) : x(a), y(b) {}


	void set1(int a, int b)
	{
		x = a;
		y = b;
	}

	// C++23 부터 this 가 암시적으로 추가되는 것 말고
	// 아래 처럼 명시적으로 받을수도 있습니다.
	// "explicit object parameter" 라는 문법
	void set2(this Point& self, int a, int b)
	{
		self.x = a;
		self.y = b;
	}
	void print1() const
	{
		std::cout << x << ", " << y << std::endl;
	}
	// 상수 멤버함수의 explicit object parameter는 아래 처럼
	void print2(this const Point& self)
	{
		std::cout << self.x << ", " << self.y << std::endl;
	}
};
int main()
{
	Point p(1, 2);
	p.set1(10, 20);
	p.set2(10, 20);
	p.print1();
	p.print2();
}

