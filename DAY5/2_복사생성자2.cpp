// 2_복사생성자1.cpp
#include <iostream>

class Point
{
	int x, y;
public:
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}

	// 언제 호출되는지 확인을 위해서 복사 생성자에서 로그...
	Point(const Point& p) : x(p.x), y(p.y)
	{
		std::cout << "copy ctor" << std::endl;
	}
};

void f1(Point  p) {} // call by value : 복사본 생성
void f2(Point& p) {} // call by reference : 복사본 생성 안됨

Point pt(1, 1);

Point  f3()		// return by value
{
	return pt;	// pt 를 리턴하는 것이 아닙니다.
	// 복사본이 만들어져서 리턴 됩니다.
}

Point& f4() // return by reference
{
	return pt; // 복사본을 만들지 말고
	// 별명으로 반환해 달라.
}

int main()
{
	Point p1(1, 2);

	// 복사 생성자가 사용되는 경우 3가지
	// #1. 자신과 동일한 타입의 객체로 초기화 될때
//	Point p2(p1); 
//	Point p3 = p1;


	// #2. 함수 인자로 call by value 를 사용할때(복사본 생성)
//	f1(p1); // call by value. "Point p = p1" 의 의미!!
			// 즉, 복사본 만들때 복사 생성자 호출

//	f2(p1); // call by reference 이므로 복사본 생성 안됨


	// #3. 함수가 객체를 값으로 반환 할때
	// f3();	// 복사본 반환. 복사본 만들때 복사 생성자 호출

	f4();	// 참조 반환이므로 복사 생성자 호출안됨.
}
//------------------------

Point f5()
{
	Point p1(1, 1);

	return p1;	// 1. p1 을 사용해서 리턴용 복사본 만들고
	// 2. p1 은 파괴(소멸자 호출됨)
	// 3. 복사본 반환
}
//f5(); // 리턴된 복사본은 이 문장의 끝에서 파괴됨.

// 아래 코드를 평가해 보세요
// -> 잘못된 코드임.
// -> 지역변수는 절대 참조 변환하면 안됨.
// -> 파괴되지 않은 것(전역 변수, static 지역 변수, 멤버데이터)만
//  참조 반환 가능함 (임시 객체에서 좀더 자세히..)
Point& f6()
{
	Point p1(1, 1);
	return p1;
}
