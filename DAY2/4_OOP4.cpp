#include <iostream>

struct Rect
{
	int left;
	int top;
	int right;
	int bottom;

	int getArea() { return (right - left) * (bottom - top); }
	void draw() { std::cout << "draw rect" << std::endl; }
};
int main()
{
	// #1. 용어 
	int n = 10; // n은 언제라도 값을 변경 가능 -> "변" "수"
	n = 20;

	Rect r = { 1,1,10,10 };	// "변수" 가 아닌 "객체" 라고 함.
	// object : 세상에 존재하는 모든 것들..
	// int n의 n도 메모리에 존재하므로 객체 임.
	// 어떤 언어는 n도 변수가 아닌 객체라는 용어 사용.
	// C++ 관례상
	// primitive type을 메모리에 생성한것: 변수
	// user define type 을 메모리에 생성한 것: 객체 라고 부름

	// #2. 메모리 layout
	// -> 스텍에는 각각의 객체에 대해 멤버 데이터만 각각 생성됨.
	// -> 멤버 함수는 객체 개수 상관없이 코드 메모리에 한개씩만 존재.
	Rect r1 = { 1,1,10,10 }; 
	Rect r2 = { 1,1,10,10 };

	std::cout << sizeof(r1) << std::endl;	// 16


}


