#include <iostream>


// 중요한 예제. 반드시 이해하세요.
class Counter
{
	int cnt = 0;
public:
//	Counter increment() // 참조 리턴이 아니므로 복사본 생성.
	Counter& increment()
	{
		++cnt;
		return *this;	// 디레퍼런스를 하여 "값" 이자 나 자신.
	}
	int get() const { return cnt; }

	Counter() {}

	Counter(const Counter& c) : cnt(c.cnt)
	{
		std::cout << "copy ctor\n";

	}

	~Counter()
	{
		std::cout << "~Counter\n";
	}

};

int main()
{
	Counter c;
	std::cout << "-------------------------------------\n";

	c.increment().increment().increment(); // 복사본 3개 생성.
	std::cout << "-------------------------------------\n";


	std::cout << c.get() << std::endl;
}

// p170 마지막 단락에 별표하고 "임시객체5.cpp" 예제 참고.
// *this 반환시

// 값 반환: 임시객체 생성됨.
// 참조 반환 : 임시객체 생성 안됨.


/*
int n = 0;
int* p = &n; // 포인터 변수는 주소로 초기화. 주소!
int& r = n;  // 참조는 이름으로 초기화. 레퍼런스!

int& r1 = p; // error. 참조 초기화를 포인터로 할수 없음
int& r2 = *p; // ok. p 가 포인터 이므로 *p 는 값!!!!

Point& r3 = this; // error
Point& r4 = *this; // ok


int& foo()
int foo()
{
	int n = 10;
	int* p = &n;

	return n;
	return *p;

}


*/
