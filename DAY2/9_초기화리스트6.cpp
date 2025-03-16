#include <iostream>

// member field initialization
class Point
{
	// C++11 부터는 아래 코드도 가능.
	// 원리는 아래 코드 참고
	int x = 0;	// 좋은 코드
	int y{ 0 };	// 좋은 코드
public:
	Point() {}
	Point(int a) : y{ a } {}
};


int main()
{

}




class Point
{

	int x;	
	int y;	
public:
	// 위 초기값을 보고 모든 생성자를 아래 처럼 변경.
	Point() : x(0), y(0) {}
	Point(int a) : x(0), y(a) {}
};


int main()
{

}










