﻿#include <iostream>

// 26page - 중요한 변화.!

struct Point
{
	int x, y;
};
int main()
{
	// C언어, C++98 시절 초기화의 문제점
	// => 변수의 종류에 따라 초기화 방법이 다르다!!
	int n1 = 10;
	int x1[3] = { 1,2,3 };
	Point p1 = { 1,2 };

	// Uniform Initialization(일관된 초기화) 문법
	// => C++11 에서 도입
	// => 모든 변수는 {}로 초기화 할수 있다.
	// => 흔히 "중괄호 초기화" 라는 별명으로 불리는 기술

	int n2 = {10};
	int x2[3] = { 1,2,3 };
	Point p2 = { 1,2 };

	int n3 {10};
	int x3[3] { 1,2,3 };
	Point p3 { 1,2 };

	// = 이 있어도 되고, 없어도 됩니다.
	// direct(직접) initialization : =이 없는 경우
	// copy(복사)   initialization : =이 있는 경우
	
	// => 클래스로 만들어진 타입은 위 2개가 차이점이 있습니다.
	// => int 같은 표준 타입(primitive)은 차이점 없습니다.
}





