
#include <iostream>
#include <string>

// struct : 접근지정 생략 시 deffualt 가 public
// class :  접근 지정자 생략 시 디폴트가 private. struct보다 더 안전함.

// C++: class 와 struct 의 차이점은 오직 한가지.
//		접근 지정자 생략시 defualt 의 차이
// 
// C#, Java : class 와 struct 는 완전히 다름.
// Rust : class 키워드 없음. struct 만으로 모든 것을 만듬.

// struct Person
class Person	//Person 이라는 타입을 만듬.
{
// private:			// private 접근 지정자
	// 멤버 데이터
	std::string name;	// 이 영역에 멤버는 멤버 함수에서만 접근 가능.
	int  age;

public:				// 이 영역의 멤버는 어디에서도 접근 가능.
	void set_age(int a)
	{
		// 인자 값이 유효한 경우에만 객체의 상태 변경.
		if (a > 0 && a < 150)
			age = a;
	}
};

int main()
{
	Person p;

	//	p.age = -10; // error. private 멤버는 
					// 멤버가 아닌 함수에서는 접근 안됨.

	p.set_age(-10);	// ok. 하지만 유효하지 않은 값이므로 객체의 상태 변경이 안됨.

}


