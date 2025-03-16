#include <iostream>

// 아래 코드에서 에러를 모두 찾아 보세요
class Base
{
public:
	Base(int a) { std::cout << "Base(int)" << std::endl; }
	~Base() { std::cout << "~Base()" << std::endl; }
};

// 핵심: Base 에는 디폴트 생성자가 없음.
class Derived : public Base
{
public:
	// 1. 아래 2줄이 에러인 이유를 정확히 알아야 함.
	//		주석처럼 컴파일러가 추가 했기 때문.

//	Derived(){}				// Derived() {call Base::Base();}
//	Derived(int a) {	}	// Derived(int a) {call Base::Base();}

	// 2. 해결책
	//		기반 클래스에 디폴트 생성자가 없다면
	//		아래처럼 사용자가 기반 클래스의 다른 생성자를 호출하게 해야 됨.
	Derived()	: Base(0) {}				
	Derived(int a) : Base(a) {}	


};

int main()
{
}







