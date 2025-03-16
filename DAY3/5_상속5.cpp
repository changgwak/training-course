#include <iostream>
#include <vector>

class People
{
	std::string name;
	int age;
public:
	// 1. 생성자가 1개도 없으면 컴파일러가 디폴트 생성자 제공.

	People(std::string name_, int age_) : name{name_}, age{age_} {}


};

int main()
{
	People p;	// 초기값(name, age) 되지 않은 객체의 생성 - 나쁜 코드 
				// -> 생성자 만들어서 멤버 초기화 하자.

	People p("kim", 20); // 좋은 코드. 초기화가 잘 되어있음.
}






