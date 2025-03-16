#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};



Point pt(1, 2);

Point foo() 
{
	return pt; 
	// 리턴용 복사본 생성.
	// 리턴용 복사본이 임시객체이고
	// 함수 호출 문장의 끝에서 파괴됨.
}

int main()
{
	foo();
}









