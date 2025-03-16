// 5_생성자1.cpp - 80 page
#include <iostream>
#include <string>

class Person
{

private:
	std::string name;
	int  age;


public:
	// 생성자 여러개 만들기 가능
	Person(const std::string& n, int a)	// string 사용 시 오버헤드가 있으니 const reference로 사용하자
	{
		name = n;
		age = a;
		std::cout << "생성자1\n";
	}

	Person()
	{
		name = "이름 없음";
		age = 0;
		std::cout << "생성자2\n";
	}

	// 소멸자
	// => "~클래스이름" 의 함수
	// => 객체가 파괴 될때 호출
	// => 반환값없고, 인자도 가질수 없다.
	// => 오직 한개만 만들수 있다.
	~Person() { std::cout << "소멸자\n"; }
};


int main()
{

	Person p1("kim", 28); // 생성자 1번 호출
	Person p2;		// 생성자 2번 호출

}	// <= p1, p2 파괴, 소멸자 호출됨.

// 생성자는 "객체(멤버 데이터) 초기화" 라는 목표가 있는데
// 소멸자는 언제 사용하나?
// -> 필요한 경우만 만들면 됨. vector 예제 참고
// #C, Java, Swift 등에는 없는 C++ 만의 문법






