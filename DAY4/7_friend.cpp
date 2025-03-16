#include <iostream>

// friend 79page ~

class Bike
{
	int gear = 0;

public:
	void setGear(int n) { gear = n; }

	// friend 함수는 클래스의 멤버가 아니지만, private 멤버에 접근 가능.
	friend void fixBike();

	// 1. Set(), Get() 함수를 사용하면 되는데 왜 friend 함수를 만드나요?
	// -> Set/Get 을 제공하는 것은 모든 곳에서 접근 가능하게 하는것
	//   friend 함수는 특정 함수만 접근 가능하게 하는 것.

	// 2. 멤버 함수를 사용하면 되는데 왜 일반함수인 friend 함수를 만드나요?
	// -> 멤버 함수로 할 수 없을 때가 있음(연산자 재정의)
	// 
	// 3. private 으로 막았는데 다시 open 하는 것은 안 좋지 않나요?
	// -> 그래서 비판이 많은 문법
	// -> C++ 에만 있는 문법. 다른 언어에는 없음.
	// 
	// friend 함수는 클래스의 멤버가 아니므로 this 포인터가 없다.
};

void fixBike()
{

	Bike b;
	b.gear = 10;
}

int main()
{
	
	fixBike();
}

