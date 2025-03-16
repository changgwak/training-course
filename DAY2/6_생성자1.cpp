// 5_생성자1.cpp - 80 page
#include <iostream>
#include <string>

class Person
{
/*
public:
	std::string name;
	int  age;
*/

private:
	std::string name;
	int  age;

/*
public:
	void init(const std::string& n, int a)
	{
		name = n;
		age = a;
	}
*/
public:
	// 생성자
	// -> 클래스 이름과 동일한 이름의 함수
	// -> return 타입 표기 안함
	// -> 객체 생성시 자동으로 호출됨.
	Person(const std::string& n, int a)	// string 사용 시 오버헤드가 있으니 const reference로 사용하자
	{
		name = n;
		age = a;
	}
	
};


int main()
{
	// 1. 모든 멤버 데이터가 public 에 있으면
	// -> 결국 C 언어의 구조체와 동일.
	// -> 따라서 아래처럼 구조체 초기화 구문으로 초기화 가능.
	// Person p = { "kim", 28 };	// struct 와 동일한 초기화 방법

	// 2. 멤버 데이터가 private 에 있다면 위처럼 초기화 안됨.
	// 멤버 함수로 초기화 해야됨.
//	Person p;	// 객체를 만들때 초기화가 안 되어있으므로 쓰레기 값이 데이터에 있음.
//	p.init("kim", 28);	// 초기화 함수 호출.

	// 3. 위 코드 보다는 객체를 생성하면서 초기화 하는 것이 좋음.
	Person p("kim", 28); // 생성자 라는 함수가 호출됨.


}





