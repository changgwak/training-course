// 148 page ~
#include <iostream>

// 핵심: 상속 문법을 사용한다면
//       기반 클래스의 소멸자는 반드시 virtual로 만들어야 한다.
//       -> 가상 소멸자 라고 불리는 문법.

// 기반 클래스 소멸자가 virtual 이 아니어도
// -> Derived 소멸자가 하는 일이 없는 경우는 문제가 없다.
// -> 그런데, 안전한 코드를 작성하기 위해서  
// -> 기반 클래스 소멸자는 반드시 virtual로 만들어야 한다.

class Base
{
public:
	Base()  {  }
	virtual	~Base() {  }	// 좋은 코드
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived()" << std::endl; }
	~Derived() { std::cout << "~Derived()" << std::endl; }
};

int main()
{
//	Derived d;	// ok. 문제 없음.

//	Derived* p = new Derived;	
//	delete p; // ok. 문제 없음.

	// 아래	코드는 error
	Base* p = new Derived;	// 1. sizeof(Derived) 크기만큼 메모리 할당
							// 2. 생성자 호출
	delete p;				// 1. 소멸자 호출  (p->소멸자())
							// 2. 메모리 해지
	//-------------------------------------------
	// 소멸자 호출도 결국 함수의 호출
	// p->소멸자() 가 호출되는데, p는 Base* 타입이므로 Base의 소멸자 호출

	// 1. 함수 호출시, static binding 할지 dynamic binding 할지 결정
	// 2. 컴파일러는 p 자체의 타입만 알기 때문에, 
	//		p의 타입인 Base 클래스의 소멸자가 가상인지 아닌지 조사.

	// Base 클래스의 소멸자는 가상함수가 아니면     : static binding
	//												포인터 타입으로 호출됨
	//												-> ~Base() 만 호출
	//							-> Derived 클래스의 소멸자는 호출되지 않음.
	// Base 소멸자가 가상 이면						: dynamic binding
	//							    p가 가리키는 곳을 조사해서 호출 결정
	//								p가 Derived 객체를 가리키면
	//								~Derived() 호출
}

