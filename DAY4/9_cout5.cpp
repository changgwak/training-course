// p171
#include <iostream>


// std::cout 으로 사용자 정의 타입을 출력
class Point : public std::ostream
{
	int x;
	int y;
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}

	friend std::ostream& operator<<(std::ostream& os, const Point& p);

};

// 연산자 재정의는 멤버가 아닌 일반 함수도 가능.
std::ostream& operator<<(std::ostream& os, const Point& p)
{
	// 여기서 os 는 std::cout의 alias 임.
	os << p.x << ", " << p.y;
	return os;
}


int main()
{
	Point p(1, 2);

	std::cout << p ; // std::cout.operator<<(Point); 가 있으면 됨.
					// but, C++ 표준인 std::ostream 에 멤버함수 추가 불가.
	                // 해결책: 연산자 재정의는 멤버가 아닌 일반 함수도 가능.
	                // operator<<(std::cout, p)
	                 // operator<<(std::ostream, Point) 가 있으면 됨.
					
					
				
	// cout의 별명을 만들때는 non-const 참조로 만들어야 한다.
	std::ostream& o1 = std::cout; // ok o1은 << 사용 가능.
	const std::ostream& o2 = std::cout; // o2 는 << 사용못함

	o1 << "hello"; // ok
	o2 << "hello"; // error.   o2.operator<<() 인데, 
	                 // operator<<() 가 상수 함수 아님.
}




