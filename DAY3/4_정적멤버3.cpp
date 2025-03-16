// 2번 복사
#include <iostream>

// 3_정적멤버1 - 111 page

// 방법 #3. static member data



class Car
{
	int color = 0;

public:

//	int cnt = 0;	// 객체당 한개씩 생성됨.

	static int cnt;	// static member data 선언만 하기. 원랜 private으로 해야되는듯?
					// -> 모든 객체가 공유하는 멤버 데이터
					// -> 전역 변수와 유사 (Car 전용 전역변수)

	Car() { ++cnt; }
	~Car() { --cnt; }
};

//static 멤버 데이터는 외부 정의 필요. 초기화도 외부에서 하기.
int Car::cnt = 0;

int main()
{
	Car c1;
	Car c2;

	std::cout << Car::cnt << std::endl;	// 2 출력
}




