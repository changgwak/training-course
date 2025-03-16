#include <string>

int main()
{
	// #1. 초기화 vs 대입
	// 초기화 : 변수 선언문에 동시에 값을 넣는 것
	// 대입 : 변수 선언 후 에 값을 넣는 것.
	int a = 3;	// 초기화, initilization
	int b;
	b = 3;		// 대입

	// 초기화와 대입은 다른 개념이지만 
	// primitive type의 경우는 알아서 컴파일러 최적화를 해서 
	// 기계어 코드 레벨에서 거의 동일한 코드 생성.



	// #2. user define 타입의 경우는 초기화와 대입은 완전히 다름. 
	// -> 성능 차이가 큼. 초기화 하는 경우가 성능 우수.

	std::string s1("hello");	// 초기화, 
								// 생성자 1회 호출로 값을 넣은 것.

	std::string s2;	// 1. defualt 생성자 호출.
	s2 = "hello";	// 2. s2.operator=("hello") 라는 함수 호출(5일차 배우는 함수)
					// -> 즉, 2번의 함수 호출로 값을 넣는 것.

	// s1, s2 모두 "hello"를 가지게 되지만, s1이 훨씬 효율적
	// 초기화가 대입 보다 성능 우수.
	
	// 3. const 와 reference 는 초기화는 되지만 대입은 안됨.
	const int c1 = 10; // ok, 초기화.

	const int c2; // error
	c2 = 10;	// error. 대입 안됨.

}

