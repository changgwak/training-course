
#include <iostream>


// static member 7 도 추가 후 동일하게 복사


class Car
{
	int color = 0;
	
	// C++17 의 inline static 을 사용하면
	// static  멤버 변수의 외부 정의 필요 없음.
	// 초기화도 여기서 가능.
	inline static int cnt;	// private 으로 해야 안전.

public:

	Car() { ++cnt; }
	~Car() { --cnt; }


	static int get_count() { return cnt; }	//
};

int Car::cnt = 0;	// private 멤버라도 static은 외부 초기화 가능.


int main()
{


}




