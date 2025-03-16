// 5_this1.cpp      97 page ~
#include <iostream>

class Point
{
	int x, y;
public:
	// 사용자 코드				// 컴파일러가 변경한 코드
	void set(int a, int b)		// void set(Point* this, int a, int b)
	{							// {
		x = a;					//		this->x = a;
		y = b;					//		this->y = b;

		// 멤버 함수 안에서 this : 현재 멤버함수를 호출한 객체의 주소
		std::cout << this << std::endl;
	}
};
int main()
{
	Point p1;
	Point p2;
	std::cout << "p1 : " << &p1 << std::endl;
	std::cout << "p2 : " << &p2 << std::endl;
	
	
	p1.set(10, 20);	// 컴파일러가 set(&p1, 10, 20) 라는 형태로 변경됨.
	p2.set(10, 20); // set(&p2, 10, 20)
}

// 파이썬
// c = Car()
// c.Go()  => Go(c) 로 변경된 것.

// 위 원리는 모든 객체지향 프로그래밍에서 동일.

// 파이썬, Rust : 개발자가 객체의 참조(주소)를 받는 코드를 명시적으로 작성, def Go(self)

// C++, C#, Java : 컴파일러가 객체의 참조(주소)를 받는 코드를 자동으로 추가




