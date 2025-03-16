// 3_OOP1 - 72page
#include <iostream>


//	객체지향 프로그래밍의 핵심 2.
// -> 타입을 만들 때 상태를 나타내는 데이터와 상태를 가지고 
// 연산을 수행하는 함수를 묶어서 타입을 만들자
// 
// 함수를 구조체 안에 넣을 때 장점:
// 1. 데이터를 함수 인자로 전달할 필요 없음
// 2. 다양한 구조체(클래스) 관련 문법을 통해서 사용하기 쉽고,
//		안전한 타입을 설계 가능.(오후에 배울 내용)
// 
// 
// C 구조체: 구조체 안 에 함수를 못 넣음.
// C++ 구조체: 구조체 안에 함수 넣을 수 있음.

struct Rect
{
	// 멤버 데이터 (다른 언어는 필드 라는 용어 사용)
	int left;
	int top;
	int right;
	int bottom;

	// 멤버 함수 (다른 언어는 메서드 라는 용어 사용)
	// -> 특징: 함수 안에서 멤버 데이터에 직접 접근 가능.
	int getArea()
	{
		return (right - left) * (bottom - top);
	}

	void draw()
	{
		std::cout << "draw rect" << std::endl;
	}

};


int main()
{
	Rect rc = { 1,1,10,10 };

	int n1 = rc.getArea();	// 객체지향 스타일
							// rc 에게 면적좀 알려달라고 요청.
	rc.draw();		// 

//	int n1 = getRectArea(rc);	// C 스타일: 함수에 데이터 전달
//	drawRect(rc);

	//	int n1 = getRectArea(1, 1, 10, 10);
	//	drawRect(1, 1, 10, 10);
}

