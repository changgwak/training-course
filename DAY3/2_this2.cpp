#include <iostream>

class Point
{
	int x, y;
public:
//	this 활용 1. 이름 충돌이 있거나 또는 멤버 데이터 임을 명확히 하기 위함.
	void set(int x, int y)
	{
		this->x = x;	
		this->y = y;
	}

	// this 활용 2. this 또는 *this 를 반환하는 멤버 함수
	// -> 멤버 함수 호출을 연속적으로 할 수 있음.
	Point* foo() { return this; }	// 주소로 return
	Point& goo() { return *this; }	// 주소가 아니라 값으로 return. 보통 이렇게 쓰는 듯.

};
int main()
{
	Point p1;
	p1.set(10, 20);

	p1.foo()->foo()->foo();
	p1.goo().goo().goo();

	// std::cout의 원리는 *this 반환 임. - 내일 오후.
	std::cout << "A" << "B" << "C";

	// cout.operator<<("A").operator<<("B").operator<<("C")

// java 의 빌더 라는 기술
//	Person p;
//	p.set_name("kim").set_age(20).set_weight(60);

	// C++
//	p.set("kim", 20, 60);
//	p.set("kim");
}



