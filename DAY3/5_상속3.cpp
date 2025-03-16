// 상속과 생성자.   136page ~
#include <iostream>

class Base
{

	int data1 = 0;
public:
	Base()      { std::cout << "Base()"  << std::endl; }
	Base(int a) { std::cout << "Base(int)" << std::endl; }
	~Base()     { std::cout << "~Base()" << std::endl; }
};

class Derived : public Base
{
	int data2 = 0;
public:
	// 상속에서 생성자 호출의 정확한 원리
	Derived()       
	{ 
		// call Base::Base() <- 컴파일러가 추가한 코드
		std::cout << "Derived()" << std::endl; 
	} 

	Derived(int a)  
	{
		// call Base::Base() <- 컴파일러가 추가한 코드는 
		//						항상 default 생성자를 호출.
		std::cout << "Derived(int)" << std::endl; 
	}

	~Derived()      
	{
		std::cout << "~Derived()" << std::endl; 

		// 소멸자는 Derived 구현이 먼저 실행된 후, 기반 클래스 소멸자 호추
		//call Base::~Base()
	}
};

int main()
{
//	Derived d1;	// call Derived::Derived()
	Derived d2(5);	// call Derived::Derived(int)
}







