// 4_정적멤버4-1.cpp

class Car
{
	int color;
	int speed;

public:
	void set(int c, int s)	// void set(Car* this, int c, int s)
	{
		color = c;	// this->color = c;
		speed = c;	// this->speed = s;
	}
// 	핵심: static member function 은 this 가 추가되지 않은 멤버 함수.
	static void foo(int c, int s)	// void foo(int c, int s)
	{
		color = c;	// error. this-> color = c 가 되어야 되는데 this 가 없음.
		speed = c;	//error
	}
};
int main()
{
	// const Car c;
	Car c;
						// 컴파일러의 원리
	c.set(10, 20);		// set(&c, 10, 20)

	Car::foo(10, 20);	// foo(10, 20);
	c.foo(10, 20);		// foo(10, 20);
						// 즉, c 가 함수 인자로 전달되지 않으므로
						// c 가 상수 객체인지 아닌지는 상관 없음.
}

