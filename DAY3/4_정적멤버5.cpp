#include <iostream>
// 시험, exam, 다음 중 틀린것/ 맞는 것을 찾으세요. 그대로 시험 나옴.
class Car
{
	int color;
	static int cnt;
public:
	// 다음중 에러를 모두 골라 보세요
	// 1. static 멤버 데이터는 객체가 없어도 메모리에 존재
	// 2. static 멤버 함수는 객체가 없어도 호출 가능.
	
	// 아래 foo 를 호출한 것은 객체를 생성했다는 의미
	void foo()
	{
		color = 0;	// 1. ok. 
		cnt = 0;	// 2. ok. 
		goo();		// 3. ok. 객체 유무와 상관없이 이미 메모리에 있으므로 호출가능.
		std::cout << this; // 4. ok. 
	}
	static void goo()
	{
		color = 0;	// 5. error. 객체가 있어야만 메모리에 존재. this->color 이 안 됨.
		cnt = 0;	// 6. ok, cnt는 객체가 없어도 메모리에 이미 존재.
		foo();		// 7. error. 객체가 있어야 호출 가능한 함수.
		std::cout << this; // 8. error. 객체 주소. 객체가 있어야 됨.
	}
};
int Car::cnt;	// 전역변수는 초기값 생략 시 자동으로 0 으로 초기화.

int main()
{
	Car::goo();	// 객체 없이 호출 가능.


}

// 핵심 - p118, 119
// static member function 에서는
// static member(data, function) 만 사용 가능.

