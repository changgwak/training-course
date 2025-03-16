// 4_접근지정자1 - 76page
#include <iostream>
#include <string>

// 캡슐화(encapsulation)
// -> 객체의 상태(멤버데이터)를 private 에 놓고
// -> 외부에 잘못된 사용으로 부터 객체가 불안해 지는 것을 막는다.
// -> 객체의 상태는 잘 정의된 멤버함수를 사용해서만 변경할수 있다.

// 접근지정자: private, public
// -> 대부분의 객체지향 언어가 지원.


struct Person	//Person 이라는 타입을 만듬.
{
private:			// private 접근 지정자
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


