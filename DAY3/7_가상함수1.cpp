// 7_가상함수1  144 page ~
//			   150 page
#include <iostream>

class Animal
{
public:
	void Cry1() { std::cout << "Animal Cry1" << std::endl; } // 1
};

class Dog : public Animal
{
public:
	//function override : 기반 클래스의 함수를 파생클래스가 다시 만든 것.
	// overloading : 인자가 다르면 동일이름 함수 2개 만들수 있음.
			//		ex, square(int), square(double) : 이름 동일, 인자 다름
	void Cry1() { std::cout << "Dog Cry" << std::endl; }  // 2
};

int main()
{
	Animal a; a.Cry1(); // 1 Animal Cry1
	Dog    d; d.Cry1(); // 2 Dog	Cry1

	Animal* p = &d;		

	// 객체는 Dog, 포인터 타입은 Animal*
	p->Cry1();	// Animal Cry1
}


// p150 내용.

// p->Cry1() 을 어떤 함수와 연결할 것인가?
// -> 함수 바인딩(function binding) 이라고 함.

// 1. static binding : static 이란 단어는 컴파일 시간 의미
					// 컴파일 시간에 컴파일러가 함수 호출을 결정함.
					// **컴파일러는 p가 가리키는 객체의 타입을 알 수 없음.
					// p->Cry1(); 에서 p는 변수이므로 컴파일 시간에서 누구를 가르키는 지 모름.
					// 컴파일러는 p자체의 타입이 "Animal*" 이라는 것만 알 수 있음.
					// 따라서, 컴파일러가 결정하면 "Animal Cry1" 호출.
// 속도 : static > dynamic , 직관적으로 비논리적.
// C++/C# 언어의 기본 바인딩 정책

// 2. dynamic binding : dynamic 이란 단어는 실행 시간을 믜이
					// 컴파일 시간에는 p가 가리키는 메모리를 조사하는 기계어코드 생성.
					// 실행시에 p가 가리키는 메모리를 조사해서 어떤 타입인지 조사해서 호출을 결정.
					// p 가 가리키는 곳에 Dog 가 있었다면 "Dog Cry1" 호출
// 직관적으로 논리적.
// Java, Python, Swift, 등 대부분의 객체지향 언어가 사용하는 방식.
// C++/C# 언어의 가상함수 (virtual function) 를 사용하면 dynamic binding 가능.
