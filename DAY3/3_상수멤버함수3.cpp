#include <iostream>

class Test
{
public:
	// 동일이름의 멤버 함수를
// "상수멤버 함수", "비상수 멤버함수"로 동시에 만들수 있습니다
	void foo()       { std::cout << "foo" << std::endl; }
	void foo() const { std::cout << "foo const" << std::endl; }
};

int main()
{
	// 1. 상수 객체는 상수 멤버 함수만 호출 가능.
	const Test ct;
	ct.foo();		// foo() const 만 호출

	// 2. 비상수객체는 모두 호출 가능한데, 우선순위가 있음.
	Test t; 
	t.foo();  // 1. foo() 호출, 없다면 foo() const 호출 (호출 우선순위가 있음)


}




